# funposting-cli
<p>A C++ implementation of <a href=https://github.com/esmBot/esmBot>esmbot's commands</a> on the cli</p>
<h2>How do I use this program?</h2>
<p>There are releases on the side that have the compiled binaries for each program. This program (As of currently) only has the caption command ported, but more are on the horizion.</p>
<p>to use the tool, run <code>caption input "text" output</code>. File extentions are required.</p>

<h3>Install</h3>
<ol>
<li>Download the binary or compile the code. If you wish to compile, make sure you have <code>libgraphicsmagick++1-dev</code> installed amd  make sure you run <code>c++ `Magick++-config --cxxflags --cppflags` -O2 -o caption caption.cpp `Magick++-config --ldflags --libs`</code> for it not to error.</li> 
<li>Make sure you have <a href=https://imagemagick.org/script/download.php>ImageMagick</a> installed on your computer. Make sure your version has <code>pangocairo</code> as a delegate (running <code>identify --version</code> will tell you), if it doesn't you will have to <a href=https://imagemagick.org/script/install-source.php>compile ImageMagick from source</a>.</li>
<li>Once this is complete, you will be free to use the program how you wish. To run it anywhere, put it in a folder in your <code>$PATH</code></li>
</ol>

