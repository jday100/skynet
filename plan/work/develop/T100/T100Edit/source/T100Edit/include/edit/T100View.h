#ifndef T100VIEW_H
#define T100VIEW_H

#include "T100Menu.h"

class T100View
{
    public:
        T100View();
        virtual ~T100View();

        void            Show();

    protected:
        T100Menu        m_menu;

    private:
};

#endif // T100VIEW_H
