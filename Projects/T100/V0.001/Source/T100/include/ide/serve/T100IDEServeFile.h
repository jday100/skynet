#ifndef T100IDESERVEFILE_H
#define T100IDESERVEFILE_H

#include "T100IDEServeBase.h"
#include "T100EditorData.h"


class T100IDEServeFile : public T100IDEServeBase
{
    public:
        T100IDEServeFile(T100IDEServe*);
        virtual ~T100IDEServeFile();

        T100BOOL                exist();

        T100BOOL                create();

        T100BOOL                open(T100STDSTRING, T100EditorData*);

        T100BOOL                close();

        T100BOOL                opened();

        T100BOOL                save(T100STDSTRING, T100EditorData*);

    protected:

    private:

};

#endif // T100IDESERVEFILE_H
