Eject version 1.0 beta.
Author: Fabrizio Pani
License: GPL


Eject is a simple utility to eject CD or DVD, or to disconnect removable device like USB keys.
It's a command line program that works beginning from Windows 95 and which ejects only the first CD-ROM unit found (for example master on the second IDE channel), if launched without parameters 

The available options are.

'eject -all': ejects all units, of CD-ROM and removable types
'eject -cdrom': ejects all CD-ROM units
'eject -nocdrom': ejects only removable units
'eject x' o 'eject x:': ejects the specified unit
'eject -info': show only version and copyright information
'eject -help o eject -h': show available options

***************************************************************************

Compiled with Open Watcom 1.5 version (http://www.openwatcom.org)

To compile the sources open the file 'eject.wpj' from the ide (ide.exe in 'binnt' or 'binw' directory) and click the button 'make the current target'. If you receive the error 'unable to open file ide.cfg' proceed as explained here below.

1) create the file 'setvars.bat' with the following content
SET  PATH=
SET  INCLUDE=
SET  WATCOM=x:\<install_dir>\WATCOM1.5
SET  PATH=%WATCOM%\binnt;%WATCOM%\binp;%WATCOM%\binw;
SET  HELP=%WATCOM%\binp\help;
SET  BOOKSHELF=%WATCOM%\binp\help;
SET  INCLUDE=%WATCOM%\h;%WATCOM%\lh;%WATCOM%\H\WIN;%WATCOM%\H\NT;%WATCOM%\H\OS2
SET  LIBPATH=%WATCOM%\binp\dll;%WATCOM%\lib286;%WATCOM%\lib386
SET  EDPATH=%WATCOM%\eddat; 

Where 'x': is the drive where the Watcom environment is installed and 'install_dir' the setup folder.

3) Open cmd.exe or command.exe/.com if you are in Windows 9x/ME, and go to the folder where you save the previous batch file so type the command 'setvars'.
5) go to the 'binnt' or 'binw' Watcom folder and type 'ide'. 
6) open the file 'eject.wpj' from the IDE.  

