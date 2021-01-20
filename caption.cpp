#include <list>
#include <Magick++.h>
#include <fstream>

#include <iostream>

using namespace std; 
using namespace Magick;

int main(int argc, char *argv[]) 
{ 

InitializeMagick(*argv);

std::ofstream file { argv[3] }; //create file that will be wrote to

   //input image
   list<Image> input; 
   readImages( &input, argv[1] );

   //intermediary image
   list <Image> coalesced;

   //captioned, but unoptimized image
   list <Image> captioned;

   //result is output
   list <Image> result;

    size_t width = input.front().baseColumns(); //get Base image width (before transformations)
    string query(to_string(width - ((width / 25) * 2)) + "x"); //get the size of the caption itself
    Image caption_image(Geometry(query), Color("white")); //make a white caption canvas
    caption_image.fillColor("black"); //make whats about to be appended black
    //caption_image.alpha(true); //it is transparent
    caption_image.font("Futura"); //Futura font
    caption_image.fontPointsize(width/13); //width divided by 13 is fontside so it can align with the caption
    caption_image.textGravity(Magick::CenterGravity); //center the text
    string text_input = argv[2]; //make var text_input accept the second arg as its datum
    text_input.insert(0, "pango:"); //tell text input to use the pango engine
    cout << text_input << "\n"; //break line in text input
    caption_image.read(text_input); //read the caption and input
    caption_image.extent(Geometry(width, caption_image.rows() + (width / 13)), Magick::CenterGravity); //extend the image itself to fit with the text

    coalesceImages(&coalesced, input.begin(), input.end()); //turns the input image into a coalesced image of all the frames; this makes it akin to a playable gif

for (Image &image : coalesced) { //iterates over every existing gif frame and add the caption to them
      Image appended; //create image appended
      list <Image> images; //create list of images called images
      image.backgroundColor("white");//adds white background to image
      images.push_back(caption_image); //adding caption to the top
      images.push_back(image); //adding the image itself
      appendImages(&appended, images.begin(), images.end(), true); //apends images to the memory location of appended
      appended.repage(); 
      appended.magick("gif"); //type inhereted from https://github.com/esmBot/esmBot/blob/master/commands/caption.js. Just assuming a gif
      captioned.push_back(appended);
}
int delay = 1;
    optimizeImageLayers(&result, captioned.begin(), captioned.end());
    for_each(result.begin(), result.end(), animationDelayImage(1));
    writeImages(result.begin(), result.end(), argv[3]); //writes image to third argument's location
}
