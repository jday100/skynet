#ifndef T100IDESERVEPROJECT_H
#define T100IDESERVEPROJECT_H

#include "T100IDEServeBase.h"


class T100IDEServeProject : public T100IDEServeBase
{
    public:
        T100IDEServeProject(T100IDEServe*);
        virtual ~T100IDEServeProject();

        T100BOOL                exist();

        T100BOOL                create();

        T100BOOL                open();

        T100BOOL                close();

        T100BOOL                opened();

    protected:

    private:

};

#endif // T100IDESERVEPROJECT_H
