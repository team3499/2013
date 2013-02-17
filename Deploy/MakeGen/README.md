FRC-Makefile-Generator
======================
A custom tool to create the makefile instead of WindRiver. Also comes with a compile script.

Usage:
copy the executable, and the nessasary library files (unless they are added you your path)
along with the resource files to your project compilation folder (ie. C:/WindRiver/workspace/2013/PPC603gnu/)
run compile.bat

Files it depends on:
mkp1 : first part of the makefile, before any generated content.
mkp2 : middle section of the makefile, in between generated content.
mkp3 : last part of the makefile, after all generated content.
Found in the Resources directory


Nessasary library files:
Windows:
  mingwm10.dll
  QtCored4.dll
  libgcc_s_dw2-1.dll

Goals:
Make it more customizable,
and less dependant on users changing content in the file.

support for linux.
support for osx?

Other:
Developed in Qt-Creator, compiled with qmake/make/mingw
Developed by Ethan S