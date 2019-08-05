/*
Using Watcom C Compiler
wcl386 /l=win386/bt=windows  eject.c
or from IDE that is easier

*/

#include "eject.h"


int main(int argc,char **argv)
{

char **pArg=NULL; 
    /*pointer to the command line arguments pointer*/   
  
int nLenArg=0; 
    /*to avoid calling strlen(); every time*/
int nLoop=0;
    /*counter variable */
UINT uDriveType=0;
    /*to check if a drive is of a particular type */
int nDrivesFound=0;


char rgszDrive[9]; 
    /*temporary command line argument holder*/
char rgszDriveName[7];
    /*it contains the drive name in the form of \\.\X:* or a temporary drive*/

   
   
   
  
    
    if(argc>2){
  /*error! We need zero or one parameter from command line*/
               usage();
               return 1;
              
              }
      
    if(argc==2){   
               
              pArg=&argv[1]; 
              nLenArg=strlen(*pArg);
               
               
                          
               
               if(nLenArg>8|nLenArg==3|nLenArg==7){
                                                                                     
               /*error! Length argument not valid, see usage() for options */    
                                   
                                    usage();
                                    return 1;
                                   } 
               
                             
              strcpy(rgszDrive,*pArg);  
                             
             
                  
                  
                   if(nLenArg==1) {
                                      
                        rgszDrive[1]='\0'; 
                   
                                      }                
                                                  
                   if(nLenArg==2) {
                                
                        rgszDrive[2]='\0';  
                            if(rgszDrive[1]!=':') {
                                   
                                    usage();
                                    return 1;
                                                                     
                                      }  
                                   }     
                           
                    if(nLenArg<3)     
                                           
                        if(!(isalpha(rgszDrive[0]))){
                                    usage();
                                    return 1;
                                       }
                                 
                                 
                                       
                
                    if(nLenArg>2){
                          
                         if(rgszDrive[0]!='-'){
                      /*if not drive letter, first argument char must be '-'*/                    
                                    usage();
                                    return 1;
                              }         
                        }
                  
                  
                  
                    if(nLenArg==4){
                       
                         if(rgszDrive[1]!='a'){usage();return 1;}
                         if(rgszDrive[2]!='l'){usage();return 1;}
                         if(rgszDrive[3]!='l'){usage();return 1;}

                         rgszDrive[4]='\0'; 
                               }
                               
                    if(nLenArg==5){
                       
                         if(rgszDrive[1]!='i' && rgszDrive[1]!='h'){usage();return 1;}
                         if(rgszDrive[2]!='n' && rgszDrive[2]!='e'){usage();return 1;}
                         if(rgszDrive[3]!='f' && rgszDrive[3]!='l'){usage();return 1;}
                         if(rgszDrive[4]!='o' && rgszDrive[4]!='p'){usage();return 1;}
                             rgszDrive[5]='\0';

                             
                         if(rgszDrive[1]=='i')
                            header();
                         else
                            usage();
                               
                         return 0;
                         
                                    
                                }
                                
                    if(nLenArg==6){
                      
                        if(rgszDrive[1]!='c'){usage();return 1;}
                        if(rgszDrive[2]!='d'){usage();return 1;}
                        if(rgszDrive[3]!='r'){usage();return 1;}
                        if(rgszDrive[4]!='o'){usage();return 1;}
                        if(rgszDrive[5]!='m'){usage();return 1;}

                        rgszDrive[6]='\0'; 
                                     }
                                     
                if(nLenArg==8){
                        
                        if(rgszDrive[1]!='n'){usage();return 1;}
                        if(rgszDrive[2]!='o'){usage();return 1;}
                        if(rgszDrive[3]!='c'){usage();return 1;}
                        if(rgszDrive[4]!='d'){usage();return 1;}
                        if(rgszDrive[5]!='r'){usage();return 1;}
                        if(rgszDrive[6]!='o'){usage();return 1;}
                        if(rgszDrive[7]!='m'){usage();return 1;}

                        rgszDrive[8]='\0'; 
                     
                                    } 
                    }           
                                                        
                 printf("OS: ");                                               
                 getWinVer();
               
                          
                                  
               switch(nLenArg){
                                
                                
                      case 1:
                      case 2:
                            //drive choosen by user
                            rgszDrive[0]=toupper(rgszDrive[0]);   
                            rgszDriveName[0]='\\';
                            rgszDriveName[1]='\\';
                            rgszDriveName[2]='.'; 
                            rgszDriveName[3]='\\'; 
                            rgszDriveName[4]=rgszDrive[0];
                            rgszDriveName[5]=':';
                            rgszDriveName[6]='\0';
                            
                            IOCTLEject(rgszDriveName,rgszDrive);    
                      break;
                      case 4:   
                            
                            /*all removable and cdrom drives*/
                                       
                            for(nLoop='A';nLoop<='Z';nLoop++){
                                                              
                              rgszDrive[0]=nLoop;
                              rgszDrive[1]=':';                                
                              rgszDrive[2]='\\';
                              rgszDrive[3]='\0';
                             
                              uDriveType=GetDriveType(rgszDrive);
                              
                              if (uDriveType==DRIVE_REMOVABLE || uDriveType==DRIVE_CDROM){
                              
                              
                              nDrivesFound++;
                              rgszDriveName[0]='\\';
                              rgszDriveName[1]='\\';
                              rgszDriveName[2]='.'; 
                              rgszDriveName[3]='\\'; 
                              rgszDriveName[4]=nLoop;
                              rgszDriveName[5]=':';
                              rgszDriveName[6]='\0';
                              
                              rgszDrive[0]=nLoop;
                              rgszDrive[1]=':';
                              rgszDrive[2]='\0';
                                                            
                              IOCTLEject(rgszDriveName,rgszDrive);                                
                                                           }
                              
                            }
                              if(!nDrivesFound)
                                    printf("\nNo Drives found!");
                                    //very, very unlikely
                      break;
                      
                      
                      case 5:
                             
                             //only CD-ROM type
                           
                             
                             
                              for(nLoop='A';nLoop<='Z';nLoop++){
                                                                
                                                                
                              rgszDrive[0]=nLoop;
                              rgszDrive[1]=':';                                
                              rgszDrive[2]='\\';
                              rgszDrive[3]='\0';
                             
                              uDriveType=GetDriveType(rgszDrive);                                  
                                                                
                              if (uDriveType==DRIVE_CDROM){                            

                              nDrivesFound++;                                
                              rgszDriveName[0]='\\';
                              rgszDriveName[1]='\\';
                              rgszDriveName[2]='.'; 
                              rgszDriveName[3]='\\'; 
                              rgszDriveName[4]=nLoop;
                              rgszDriveName[5]=':';
                              rgszDriveName[6]='\0';  
                              
                              rgszDrive[0]=nLoop;
                              rgszDrive[1]=':';
                              rgszDrive[2]='\0';
                              
                              IOCTLEject(rgszDriveName,rgszDrive);                               
                                                           }
                              
                                                         }
                              if(!nDrivesFound)
                                  printf("\nNo CD-ROM (Atapi) drives  found!");
                                  //very unlikely                            
                       break;                                  
                       case 8:
                             
                             //only removable type
                           
                              
                             
                              for(nLoop='A';nLoop<='Z';nLoop++){
                                                                
                                                                
                              rgszDrive[0]=nLoop;
                              rgszDrive[1]=':';                                
                              rgszDrive[2]='\\';
                              rgszDrive[3]='\0';
                             
                             
                              uDriveType=GetDriveType(rgszDrive);

                              /* today most PC doesn't have floppy but comes with smart card
                              reader for example. I don't check for the moment, if it's a classic floppy
                              instead. */


                                                                
                              if (uDriveType==DRIVE_REMOVABLE){                            

                              nDrivesFound++;                                
                              rgszDriveName[0]='\\';
                              rgszDriveName[1]='\\';
                              rgszDriveName[2]='.'; 
                              rgszDriveName[3]='\\'; 
                              rgszDriveName[4]=nLoop;
                              rgszDriveName[5]=':';
                              rgszDriveName[6]='\0';  
                              
                              rgszDrive[0]=nLoop;
                              rgszDrive[1]=':';
                              rgszDrive[2]='\0';
                              
                              IOCTLEject(rgszDriveName,rgszDrive);                               
                                                           }
                             
                                                         }
                               if(!nDrivesFound)
                                  printf("\nNo removable drives found!");                                                           
                      break;
                      default:
                              //no command line argument  
                              //we eject first CD-ROM unit
                             
                              for(nLoop='A';nLoop<='Z';nLoop++){
                                                                
                                                                
                              rgszDrive[0]=nLoop;
                              rgszDrive[1]=':';                                
                              rgszDrive[2]='\\';
                              rgszDrive[3]='\0';
                             
                              uDriveType=GetDriveType(rgszDrive);                                  
                                                                
                              if (uDriveType==DRIVE_CDROM){
                                                           
                                                                                                                     

                              nDrivesFound++; 
                              
                              if(nDrivesFound==2)                               
                                       break; 
                                                                              
                              rgszDriveName[0]='\\';
                              rgszDriveName[1]='\\';
                              rgszDriveName[2]='.'; 
                              rgszDriveName[3]='\\'; 
                              rgszDriveName[4]=nLoop;
                              rgszDriveName[5]=':';
                              rgszDriveName[6]='\0'; 
                              
                              rgszDrive[0]=nLoop;
                              rgszDrive[1]=':';
                              rgszDrive[2]='\0'; 
                              
                              IOCTLEject(rgszDriveName,rgszDrive);                               
                                                           }        
                                      
                                      }  
                              if(!nDrivesFound)
                                  printf("\nNo CD-ROM (Atapi) drives  found!");
                                  //very unlikely
                                      
                                  }
                                     
                  
                      return 0;
                  
           
       }    
   
    
