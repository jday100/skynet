#ifndef T100EDITORSERVE_H
#define T100EDITORSERVE_H

#include "T100Common.h"


class T100EditorServe
{
    public:
        T100EditorServe();
        virtual ~T100EditorServe();

        T100BOOL            renew();
        T100BOOL            open();
        T100BOOL            close();

        T100BOOL            save();
        T100BOOL            save_as();

        T100BOOL            quit();

    protected:

    private:
};

#endif // T100EDITORSERVE_H
