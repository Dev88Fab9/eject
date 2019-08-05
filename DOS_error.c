#include "eject.h"

     
  void dosExtendedErrorInfo(int nErrorCode){
      
      
      printf("Error code %xh\n",nErrorCode);
      printf("Description: ");
          
          
      switch(nErrorCode){
          
          case 0x0:
              /*we should never come at this pint */                 
              printf("No error");
          break;
               
          case 0x1:     
             printf("Function number invalid");
          break;
          
          case 0x2:
                printf("File not found");
          break;        
          
          case 0x3:
              printf("Path not found");
          break;    
                    
          case 0x4: 
              printf("Too many open tiles (no file handles available)");
          break; 
          
          case 0x5:     
              printf("Access denied");
          break; 
          
          case 0x6:     
              printf("Invalid handle");
          break; 
          
          case  0x7:
              printf("Memory control block destroyed");
          break; 
          
          case  0x8: 
                printf("Insufficient memory");
          break; 
          
          case  0x9:               
                printf("Memory block address invalid");
          break; 
          
          case  0xA:  
                 printf("Environment invalid (usually >32k in length)"); 
          break; 
          
          case  0xB: 
                printf("Format invalid");
          break; 
          
          case  0xC:
                printf("Access code invalid"); 
          break; 
          
          case  0xD:
                printf("Data invalid"); 
          break; 
                
          case  0xE:
                printf("(reserved)"); 
          break; 
          
          case  0xF: 
                printf("Invalid drive"); 
          break; 
          
          case  0x10:
                printf("Attempted to remove current directory"); 
          break; 
          
          case  0x11:
                printf("Not same device"); 
          break; 
          
          case  0x12:
                printf("No more tiles"); 
          break;
                 
          case  0x13:
                printf("Disk write-protected"); 
          break; 
          
          case  0x14:
                printf("Unknown unit"); 
          break; 
          
          case  0x15:
                printf("Drive not ready"); 
          break; 
          
          case  0x16:
                printf("Unknown command");
          break; 
          
          case  0x17:
                printf("Data error (CRC)");
          break; 
          
          case  0x18: 
                printf("Bad request structure length");
          break; 
          
          case  0x19: 
                printf("Seek error"); 
          break; 
          
          case  0x1A:   
              printf("Unknown media type (non-DOS disk)");
          break; 
          
          case  0x1B:   
              printf("Sector not found"); 
          break; 
          
          case  0x1C: 
              printf("Printer out of paper");
          break; 
          
          case  0x1D:
              printf("Write fault");
          break; 
          
          case  0x1E:
              printf("Read fault"); 
          break; 
          
          case  0x1F: 
              printf("General failure"); 
          break; 
          
          case  0x20: 
              printf("Sharing violation"); 
          break; 
          
          case  0x21:   
              printf("Lock violation"); 
          break; 
          
          case  0x22:   
              printf("Disk change invalid"); 
          break; 
          
          case  0x23:   
              printf("FCB unavailable");
          break; 
          
          case  0x24:   
              printf("Sharing buffer invalid"); 
          break; 
          
          case  0x25:   
              printf("Code page mismatch");
          break; 
          
          case  0x26:   
              printf("Cannot complete file operation (out of input)");
          break; 
          
          case  0x27:   
              printf("Insufficient disk space");
          break; 
          
          case  0x28:   
              printf("(reserved)"); 
          break; 
          
          case  0x29:
          case  0x2A:   
          case  0x2B:   
          case  0x2C:   
          case  0x2D:   
          case  0x2E:   
          case  0x2F: 
          case  0x30:   
          case  0x31: 
              /*we should never come at this point*/
              printf("Reserved");
          break;
     
          case  0x32:   
              printf("Network request not supported");
          break; 
          
          case  0x33:   
              printf("Remote computer not listening");
          break; 
          
          case  0x34:   
              printf("Duplicate name on network"); 
          break; 
          
          case  0x35:   
              printf("Network name not found"); 
          break; 
          
          case  0x36:   
              printf("Network busy"); 
          break; 
          
          case  0x37:   
              printf("Network device no longer exists"); 
          break; 
          
          case  0x38:   
              printf("Network BIOS command limit exceeded"); 
          break; 
          
          case  0x39:   
              printf("Network adapter hardware error");
          break; 
          
          case  0x3A:   
              printf("Incorrect response from network"); 
          break; 
          
          case  0x3B:   
              printf("Unexpected network error");
          break; 
          
          case  0x3C:   
              printf("Incompatible remote adapter"); 
          break; 
          
          case  0x3D:   
              printf("Print queue full");
          break;
               
          case  0x3E:   
              printf("Queue not full");
          break; 
             
          case  0x3F:              
              printf("Not enough space to print file");
          break;   
           
          case  0x40:   
              printf("Network name was deleted");
          break;
               
          case  0x41:   
              printf("Network access denied");
          break; 
             
          case  0x42:   
              printf("Network device type incorrect");
           break;
               
          case  0x43:   
              printf("Network name not found");
          break; 
             
          case  0x44:   
              printf("Network name limit exceeded");
          break;  
            
          case  0x45:   
              printf("Network BIOS session limit exceeded");
          break;   
           
          case  0x46:   
              printf("Temporarily paused");
          break;
              
          case  0x47:
              printf("Network request not accepted");
          break;
              
          case  0x48:
              printf("Network print / disk redirection paused");
          break;
               
          case  0x49:
              printf("(LANtastic) invalid network version");
          break;   
           
          case  0x4A:
              printf("(LANtastic) account expired");
          break;
               
          case  0x4B:   
              printf("(LANtastic) password expired");
          break;       
          
          case  0x4C:   
              printf("(LANtastic) login attempted invalid at this time");
          break;      
          
          case 0x4D:    
              printf("(LANtastic) disk limit exceed on network node");
          break;
               
          case 0x4E:    
              printf("(LANtastic) not logged in to network node");
          break;
               
          case  0x4F:   
              printf("(reserved)"); 
          break; 
          
          case 0x50:    
              printf("File exists"); 
          break; 
          
          case  0x51:   
              printf("(reserved)"); 
          break; 
          
          case  0x52:   
              printf("Cannot make directory"); 
          break; 
          
          case  0x53: 
              printf("Fail on INT 24h"); 
          break; 
          
          case  0x54:   
              printf("Too many redirections"); 
          break; 
          
          case  0x55:   
                printf("Duplicate redirection"); 
          break; 
          
          case  0x56:   
              printf("Invalid password"); 
          break; 
          
          case  0x57:   
              printf("Invalid parameter"); 
          break; 
              
          case  0x58:   
              printf("Network write fault"); 
          break; 
              
          case  0x59:   
              printf("Function not supported on network"); 
          break; 
          
          case  0x5A:   
              printf("Required system component not installed"); 
          break; 
      
         default:
              /*we should never come at this point */
             printf("Error not specified!");
         break;
      
        }

        printf("\n");
 }     
     
     
