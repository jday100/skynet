#include "T100Menu.h"

#include <stdlib.h>
#include <string.h>
#include <ncurses/ncurses.h>
#include <ncurses/menu.h>

#define     ARRAY_SIZE(x)           (sizeof(x) / sizeof(x[0]))
#define     CTRLD                   4

void print_in_middle(WINDOW* win, int y, int startx, int width, char* value, chtype color)
{
    int x;

    if(win == nullptr)win = stdscr;
    if(y == 0)getyx(win, y, x);

    x = startx + (width - strlen(value)) / 2;

    wattron(win, color);
    mvwprintw(win, y, x, "%s", value);
    wattroff(win, color);
    refresh();
}

T100Menu::T100Menu()
{
    //ctor
}

T100Menu::~T100Menu()
{
    //dtor
}

void T100Menu::PopupMenu()
{
    char* choices[] = {
        (char*)"File",
        (char*)"New",
        (char*)"Open",
        (char*)"Close",
        (char*)"Quit",
        nullptr
    };

    ITEM**      items;
    MENU*       menu;
    WINDOW*     win;
    int         count;

    //start_color();
    cbreak();
    noecho();

    keypad(stdscr, true);
    curs_set(0);
    init_pair(1, COLOR_RED, COLOR_BLACK);

    count   = ARRAY_SIZE(choices);
    items = (ITEM**)calloc(count, sizeof(ITEM*));

    for(int i=0;i<count;i++){
        items[i] = new_item(choices[i], choices[i]);
    }

    item_opts_off(items[3], O_SELECTABLE);
    menu = new_menu((ITEM**)items);

    win = newwin(10, 50, 4, 4);
    keypad(win, true);

    set_menu_win(menu, win);
    set_menu_sub(menu, derwin(win, 6, 48, 3, 1));
    set_menu_mark(menu, "*");
    menu_opts_off(menu, O_SHOWDESC);
    menu_opts_off(menu, O_ONEVALUE);
    set_menu_format(menu, 6, 2);

    box(win, 0, 0);

    print_in_middle(win, 1, 0, 50, (char*)"Menu", COLOR_PAIR(1));
    mvwhline(win, 2, 1, ACS_HLINE, 48);
    mvprintw(LINES - 2, 0, "F1 to exit");
    refresh();

    post_menu(menu);
    wrefresh(win);

    int    c;
    while((c = wgetch(win)) != KEY_F(1)){
        switch(c){
        case KEY_DOWN:
            menu_driver(menu, REQ_DOWN_ITEM);
            break;
        case KEY_UP:
            menu_driver(menu, REQ_UP_ITEM);
            break;
        case KEY_LEFT:
            menu_driver(menu, REQ_LEFT_ITEM);
            break;
        case KEY_RIGHT:
            menu_driver(menu, REQ_RIGHT_ITEM);
            break;
        }
    }

    unpost_menu(menu);
    free_menu(menu);

    for(int i=0;i<count;i++)
        free_item(items[i]);

    free(items);

}

void T100Menu::Show()
{
    //start_color();
    cbreak();
    noecho();

    bkgdset(COLOR_BLUE);
    refresh();
}
