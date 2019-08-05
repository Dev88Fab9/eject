#include "eject.h"

void errorString(DWORD dwError){
         
    LPTSTR szMessageBuffer;

 
    
    FormatMessage(
        FORMAT_MESSAGE_ALLOCATE_BUFFER | 
        FORMAT_MESSAGE_FROM_SYSTEM,
        NULL,
        dwError,
        LANG_USER_DEFAULT,
        //MAKELANGID(LANG_NEUTRAL, SUBLANG_SYS_DEFAULT),
        (LPTSTR)&szMessageBuffer,
        0, 
        NULL );

    printf("\n%s",szMessageBuffer);
    LocalFree(szMessageBuffer);
    
    
    
 }
