#ifndef EJECT_H

#define EJECT_H



/**************************
*                         *  
*     include files       *
*                         *  
**************************/


#include<windows.h>
#include<string.h>
#include<stdio.h>
#include<ctype.h>
#include<stdlib.h>
#include "ioctl.h"




/**************************
*                         *  
*     defines             *
*                         *  
**************************/




    #ifndef VERSION
        #define VERSION "1.0 beta"
    #endif

    #ifndef AUTHOR
        #define AUTHOR  "Fabrizio Pani"
    #endif

    #ifndef EMAIL
        #define EMAIL   "fabph@hotmail.com"
    #endif

   

/***************************
*                          *  
*     functions prototypes *
*                          *  
****************************/


extern void header(void); //copyright and other information
extern void usage(void);  //usage message
extern void IOCTLEject(LPCTSTR,char*); //to open and eject drive
extern int  isWinNT(void);
extern void getWinVer(void); //getting windows family 
extern void errorString(DWORD); //displaying error
extern void dosExtendedErrorInfo(int);


#endif /* EJECT_H */  
  
