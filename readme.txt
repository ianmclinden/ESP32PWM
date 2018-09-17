Arduino Async Library - JavasScript-like callback task scheduling for Arduino.

Installation
--------------------------------------------------------------------------------

To install this library, just place this entire folder as a subfolder in your
Arduino/lib/targets/libraries folder.

When installed, this library should look like:

Arduino/lib/targets/libraries/Async              (this library's folder)
Arduino/lib/targets/libraries/Async/Async.cpp    (the library implementation file)
Arduino/lib/targets/libraries/Async/Async.h      (the library description file)
Arduino/lib/targets/libraries/Async/keywords.txt (the syntax coloring file)
Arduino/lib/targets/libraries/Async/examples     (the examples in the "open" menu)
Arduino/lib/targets/libraries/Async/readme.txt   (this file)

Building
--------------------------------------------------------------------------------

After this library is installed, you just have to start the Arduino application.
You may see a few warning messages as it's built.

To use this library in a sketch, go to the Sketch | Import Library menu and
select Async.  This will add a corresponding line to the top of your sketch:
#include <Async.h>

To stop using this library, delete that line from your sketch.

Geeky information:
After a successful build of this library, a new file named "Async.o" will appear
in "Arduino/lib/targets/libraries/Async". This file is the built/compiled library
code.

If you choose to modify the code for this library (i.e. "Async.cpp" or "Async.h"),
then you must first 'unbuild' this library by deleting the "Async.o" file. The
new "Async.o" with your code will appear after the next press of "verify"

