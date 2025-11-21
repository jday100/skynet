#ifndef T100FILE_H
#define T100FILE_H

#include "T100Common.h"

class T100File
{
    public:
        T100File(const T100STRING&);
        virtual ~T100File();

        T100VOID                SetPath(const T100STRING&);
        const T100STRING&       GetPath();

        T100BOOL                IsExists();

        T100BOOL                Load(T100BYTE_VECTOR&);

    protected:
        T100STRING              m_path;

    private:
};

#endif // T100FILE_H
