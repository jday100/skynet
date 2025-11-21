#include "T100View.h"

#include <ncurses/ncurses.h>

T100View::T100View() :
    m_menu()
{
    //ctor
}

T100View::~T100View()
{
    //dtor
}

void T100View::Show()
{
    WINDOW* win = initscr();

    start_color();

    /*
    if(has_color()){

    }
    */

    wattron(win, COLOR_BLUE);

    clear();

    refresh();

    wbkgd(win, COLOR_BLUE);

    //refresh();

    //m_menu.Show();

    endwin();
}
