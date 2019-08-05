Eject versione 1.0 beta.
Autore: Fabrizio Pani
Licenza: GPL


Eject è una semplice utility per espellere CD o DVD, o disconnettere dispositivi removibili come chiavette USB.
E' un programma a linea di comando che funziona a partire da Windows 95 e che di default espelle solo la prima unità CD-ROM che trova (ad esempio master sul secondo canale IDE), se eseguito senza parametri. 

Le opzioni disponibili sono.

'eject -all': espelle tutte le unità, di tipo CD-ROM e removibili
'eject -cdrom': espelle tutte le unità CD-ROM
'eject -nocdrom': espelle solo le unità removibili
'eject x' o 'eject x:': espelle l'unità specificata
'eject -info': mostra solo la versione e le informazioni di copyright.
'eject -help o eject -h': mostra le opzioni disponibili

***************************************************************************

Compilato con Open Watcom versione 1.5 (http://www.openwatcom.org)

Per compilare i sorgenti apra il file 'eject.wpj' dall'ide e clicchi sul pulsante 'make the current target'. Se riceve l'errore 'unable to open file ide.cfg' proceda come spiegato qui sotto.

1) crei il file 'setvars.bat' con il seguente contenuto 
SET  PATH=
SET  INCLUDE=
SET  WATCOM=x:\<install_dir>\WATCOM1.5
SET  PATH=%WATCOM%\binnt;%WATCOM%\binp;%WATCOM%\binw;
SET  HELP=%WATCOM%\binp\help;
SET  BOOKSHELF=%WATCOM%\binp\help;
SET  INCLUDE=%WATCOM%\h;%WATCOM%\lh;%WATCOM%\H\WIN;%WATCOM%\H\NT;%WATCOM%\H\OS2
SET  LIBPATH=%WATCOM%\binp\dll;%WATCOM%\lib286;%WATCOM%\lib386
SET  EDPATH=%WATCOM%\eddat; 

Ove x: è il drive dove è installato l'ambiente Watcom e 'install_dir' la cartella d'installazione.

3) apra cmd.exe o command.exe/.com se è in Windows 9x/ME, e vada alla cartella dove ha salvato il precedente file batch quindi digiti il comando 'setvars'.
5) entri nella cartella 'binnt' o 'binw' di Watcom e digiti 'ide'. 
6) apra il file 'eject.wpj' dall'IDE.  


    

