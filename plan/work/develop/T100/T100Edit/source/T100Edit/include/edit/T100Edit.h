#ifndef T100EDIT_H
#define T100EDIT_H

#include "T100View.h"

class T100Edit
{
    public:
        T100Edit();
        virtual ~T100Edit();

        int             Run();

    protected:
        T100View        m_view;

    private:
};

#endif // T100EDIT_H
