#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "console.h"

#define UP_ARROW    0x4800
#define DOWN_ARROW  0x5000
#define ENTER       0x0D
#define ESC         0x1B

int menu_drv(const wchar_t **options, int n, int sell_attr, int unsell_attr)
{
    int i, x = 10, y = 10, cur_sell = 0, code;
    CursorVisible(FALSE);

    for(i = 0; i < n; ++i)
        RTextXY(x, y + i, options[cur_sell], sell_attr);

    do
    {
        code = getch();
        if(code == 0 || code == 0xE0)
            code = getch()<<8;

        RTextXY(x, y + cur_sell, options[cur_sell], unsell_attr);

        switch(code)
        {
            case UP_ARROW : if(--cur_sell < 0) cur_sell = n - 1;;
                            break;
            case DOWN_ARROW : if(++cur_sell >= n) cur_sell = 0;
                            break;
        }
        RTextXY(x, y + cur_sell, options[cur_sell], sell_attr);
    }
    while(code != ENTER && code != ESC);

    gotoxy(0, y + n + 1);
    CursorVisible(TRUE);

    return code = ENTER ? cur_sell : -1;
}

int main()
{
    wchar_t *options[] = {L" File ",
                          L" Edit ",
                          L" View ",
                          L" Insert ",
                          L" Help "};
    int r;

    r = menu_drv(options, sizeof options/sizeof *options,
                 BACKGROUND(CYAN)|WHITE, BACKGROUND(WHITE)|BLACK);
    textattr(0x07);
    printf("return value %d\n", r);
    return 0;
}
