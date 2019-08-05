#include "eject.h"

void usage(){
       printf("Usage:\neject : eject first CD-ROM (ATAPI) drive\neject <drive letter> or eject <drive letter:> : eject the specified drive\neject -all : eject all CD-ROM (ATAPI) and removable drives\neject -nocdrom : eject all removable drives except CD-ROM (ATAPI) types\neject -cdrom : eject all CD-ROM (ATAPI) drives\neject -info : version and copyright info\neject -help : show this usage\n");
            }
     
     
void header(){
 
     printf("eject\nVersion: %s for windows\nAuthor: %s\ne-mail: ",VERSION,AUTHOR,EMAIL);
     printf("See readme.txt for more details\nDistribuited under GPLv2 license, see gpl.txt for details\n\n");
     
           }     
