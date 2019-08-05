#include "eject.h"
int isWinNT(){
    
    
   OSVERSIONINFO osvi;
  

   memset(&osvi, 0, sizeof(OSVERSIONINFO));
   osvi.dwOSVersionInfoSize = sizeof (OSVERSIONINFO);
   GetVersionEx (&osvi);

   if (osvi.dwPlatformId == VER_PLATFORM_WIN32s){
      puts("Win32s is not supported!");                   
      exit(1);
      }


   if (osvi.dwPlatformId == VER_PLATFORM_WIN32_WINDOWS)
      return 0;

      
        return 1;
}


void getWinVer(){
    
   OSVERSIONINFO osvi;
   char  szVersion [80];

   memset(&osvi, 0, sizeof(OSVERSIONINFO));
   osvi.dwOSVersionInfoSize = sizeof (OSVERSIONINFO);
   GetVersionEx (&osvi);

   if (osvi.dwPlatformId == VER_PLATFORM_WIN32s)

      wsprintf (szVersion, "Microsoft Win32s %d.%d (Build %d)",
                osvi.dwMajorVersion,
                osvi.dwMinorVersion,
                osvi.dwBuildNumber & 0xFFFF);

   else if (osvi.dwPlatformId == VER_PLATFORM_WIN32_WINDOWS)
      wsprintf (szVersion, "Microsoft Windows 95 %d.%d (Build %d)",
                osvi.dwMajorVersion,
                osvi.dwMinorVersion,
                osvi.dwBuildNumber & 0xFFFF);

   else if (osvi.dwPlatformId == VER_PLATFORM_WIN32_NT)

      wsprintf (szVersion, "Microsoft Windows NT %d.%d (Build %d)",
                osvi.dwMajorVersion,
                osvi.dwMinorVersion,
                osvi.dwBuildNumber & 0xFFFF);
                
                printf(szVersion);

}
