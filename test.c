#include <fcio.h>
#include <conio.h>

void main() {
   byte i;
   long t;
   fc_init(1,1,0,60,0);
   bordercolor(6);
   fc_clrscr();
   for (i=0;i<60;++i) {
      fc_textcolor(1+(i%14));
      fc_gotoxy(i+3,i);
      fc_printf("Hello world #%d",i);
   }
   fc_displayFCIFile("candor.fci",25,16);
   while(1);
}