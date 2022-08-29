#ifndef T100IDEVIEWBASE_H
#define T100IDEVIEWBASE_H

#include "T100Common.h"
class T100IDEView;


class T100IDEViewBase
{
    public:
        T100IDEViewBase(T100IDEView*);
        virtual ~T100IDEViewBase();

        virtual T100BOOL        create_menu()=0;

    protected:
        T100IDEView*            m_view          = T100NULL;

    private:
};

#endif // T100IDEVIEWBASE_H
