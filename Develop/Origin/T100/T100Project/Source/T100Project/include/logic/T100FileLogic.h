#ifndef T100FILELOGIC_H
#define T100FILELOGIC_H

#include "T100FileInfo.h"

class T100FileLogic
{
    public:
        T100FileLogic();
        virtual ~T100FileLogic();

        T100BOOL            IsExists(const T100WSTRING&);

        T100VOID            Create(T100FileInfo*);
        T100VOID            Remove(T100FileInfo*);
        T100VOID            Rename(T100FileInfo*);

        T100BOOL            Open(const T100WSTRING&, T100FileInfo*);
        T100VOID            Close(T100FileInfo*);



    protected:

    private:
};

#endif // T100FILELOGIC_H
