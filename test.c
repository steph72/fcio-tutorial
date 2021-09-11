#include <fcio.h>
#include <stdlib.h>
#include <string.h>

void main()
{
   textwin *bottomWindow;
   char *command;

   fc_init(0, 0, 0, 30, 0);
   fc_bordercolor(6);
   fc_clrscr();
   fc_displayFCIFile("candor.fci", 3, 0);

   bottomWindow = fc_makeWin(0, 24, 40, 6);
   fc_setwin(bottomWindow);
   fc_clrscr();
   fc_puts("As you turn the corner, suddenly a big\n"
           "shepherd dog stands in your way and\n"
           "demands treats.");
           
   do {
      fc_puts("\n>");
      fc_textcolor(COLOUR_ORANGE);
      command = fc_input(38);
      fc_textcolor(COLOUR_GREEN);
      fc_printf("\nI'm sorry, I don't understand '%s'",command);
      free(command);
   } while (strcmp(command,"give treats"));

   fc_clrscr();
   fc_puts("The dog moves away!");

   while (1);
}