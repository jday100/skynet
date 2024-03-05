#ifndef T100PROJECTSERVE_H
#define T100PROJECTSERVE_H

#include "T100String.h"


namespace T100PROJECT{

class T100ProjectServe
{
    public:
        T100ProjectServe();
        virtual ~T100ProjectServe();

    public:
        T100BOOL            SaveFile(T100STRING);
        T100BOOL            LoadFile(T100STRING);

        T100VOID            setModified(T100BOOL);
        T100BOOL            IsModified();
        T100VOID            DiscardEdits();

    protected:

    private:
        T100VOID            create();
        T100VOID            destroy();
};

}

#endif // T100PROJECTSERVE_H
