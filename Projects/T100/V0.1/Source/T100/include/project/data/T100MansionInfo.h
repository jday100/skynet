#ifndef T100MANSIONINFO_H
#define T100MANSIONINFO_H

#include "T100Common.h"
#include "T100String.h"


class T100MansionInfo
{
    public:
        T100MansionInfo();
        virtual ~T100MansionInfo();

        T100STRING          getName();

    protected:
        T100VOID            create();
        T100VOID            destroy();

    private:
        T100STRING          m_name;
        T100STRING          m_path;
};

#endif // T100MANSIONINFO_H
