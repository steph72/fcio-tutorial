#include <fcio.h>
#include <conio.h>

void main()
{
   fciInfo *imageInfo;

   fc_init(1, 1, 0, 60, 0);
   bordercolor(6);

   imageInfo = fc_loadFCI("candor.fci", 0, 0);

   fc_printf("image has %d rows, %d columns\n", imageInfo->rows, imageInfo->columns);
   fc_printf("image bitmap  at $%lx\n", imageInfo->baseAdr);
   fc_printf("image palette at $%lx\n", imageInfo->paletteAdr);
   fc_printf("image palette has %d entries\n", imageInfo->paletteSize);
   fc_puts("-- press any key to display images --\n");
   fc_getkey();

   fc_displayFCI(imageInfo, fc_wherex(), fc_wherey(), true);
   fc_displayFCI(imageInfo, fc_wherex()+imageInfo->columns, fc_wherey(), true);

   while (1);
}
