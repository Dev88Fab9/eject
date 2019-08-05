#include "eject.h"

void IOCTLEject(LPCTSTR szDriveName,char* rgszDrive){
     

  HANDLE  hDrive;/*drive handle for Windows */  
  int nIsNT=0;  
    /*boolean variable, true when we are on a NT family OS*/ 
  int nLoop=0;  
   /*counter variable*/

  int nresult;
  


int nErrorCode;
  /*to contain the Dos error code */
  
DWORD dwError;
  /*error variable for GetLastError()*/
 
 typedef struct DIOC_REGISTERS{

 /* See
 http://msdn.microsoft.com/archive/default.asp?url=/archive/en-us/win9x/95str_9vxu.asp

*/
    
  DWORD   reg_EBX; 
  DWORD   reg_EDX; 
  DWORD   reg_ECX; 
  DWORD   reg_EAX; 
  DWORD   reg_EDI; 
  DWORD   reg_ESI; 
  DWORD   reg_Flags; 
}DIOC_REGS;    
    



 
  /*structure of type DIOC_REGISTERS*/
 DIOC_REGS  stRegs, *stpRegs;
  /*pointer to the structure Regs*/
 DWORD  dwReturnedBytes; 
     

    
   nIsNT=isWinNT();
    
    if(nIsNT){
         
         printf("\nEjecting drive ");
         
         while(rgszDrive[nLoop]){
             printf("%c",rgszDrive[nLoop]);
             nLoop++;
                      }    
         
        
       /* http://msdn.microsoft.com/library/default.asp?url=/library/en-us/fileio/fs/createfile.asp*/
       
         
         hDrive = CreateFile(szDriveName,(DWORD)GENERIC_READ | GENERIC_WRITE, 0, (LPSECURITY_ATTRIBUTES)NULL, (DWORD) OPEN_EXISTING, 0, (HANDLE)NULL);                                       
            
          if(hDrive == INVALID_HANDLE_VALUE){
               dwError = GetLastError();      
               errorString(dwError);
               return;           
               }
               
            /* no errors*/
          /*  http://msdn.microsoft.com/library/en-us/devio/base/deviceiocontrol.asp?frame=true*/
            nresult=DeviceIoControl(hDrive, (DWORD)IOCTL_EJECT_MEDIA, (LPVOID)NULL, 0,(LPVOID) NULL, 0, &dwReturnedBytes, (LPOVERLAPPED) NULL);
            
          if(!nresult){
                      dwError = GetLastError();      
                      errorString(dwError);
                      
                      if(hDrive != INVALID_HANDLE_VALUE)
                         CloseHandle(hDrive);
                      return;  
                      } 
                      
            printf("\nDrive ejected successfully!\n");  
                    
            if(hDrive != INVALID_HANDLE_VALUE)                        
                        CloseHandle(hDrive);
        }     
           
               
    else{
         printf("\nEjecting drive ");
         
         while(rgszDrive[nLoop]){
             printf("%c",rgszDrive[nLoop]);
             nLoop++;
                      }    
         printf("\n");    
       /*http://msdn.microsoft.com/library/default.asp?url=/library/en-us/fileio/fs/createfile.asp*/         
         hDrive = CreateFile("\\\\.\\VWIN32", 
         0, 0, 0, 0, 
         FILE_FLAG_DELETE_ON_CLOSE, NULL);
        
        if(hDrive == INVALID_HANDLE_VALUE){
               dwError = GetLastError();      
               errorString(dwError);
               return;            
               }
      
      /*DOS 3.2+ - IOCTL - GENERIC BLOCK DEVICE REQUEST
            http://www.ctyme.com/intr/rb-2896.htm
            */
      
       stRegs.reg_EAX=0x440D;
       stRegs.reg_EBX=rgszDrive[0]-64;
       stRegs.reg_ECX=0x49 | 0x800;
        /*minor code 49h=eject media in drive
          category code 08h=disk drive       */
       
        stpRegs=&stRegs; 
        /*pointer to the  struct*/    
            /*  http://msdn.microsoft.com/library/en-us/devio/base/deviceiocontrol.asp?frame=true*/ 
       DeviceIoControl(hDrive, 
        (DWORD)VWIN32_DIOC_DOS_IOCTL, 
        stpRegs, 
        sizeof(stRegs), 
        stpRegs, 
        sizeof(stRegs), 
        &dwReturnedBytes, 
        (HANDLE) NULL);    
        
         if(stRegs.reg_Flags & 0x1){
             
                      puts("IOCTL error!");                  
                      nErrorCode=stRegs.reg_EAX;
                      dosExtendedErrorInfo(nErrorCode);
                      
                      if(hDrive != INVALID_HANDLE_VALUE)
                        CloseHandle(hDrive);
                      
                      return;  
                      } 
            
            printf("\nDrive ejected successfully!\n");
                       
            if(hDrive != INVALID_HANDLE_VALUE)
                        CloseHandle(hDrive);
                     
        
        }         
    
 
} 
