#ifndef T100PROJECTINFO_H
#define T100PROJECTINFO_H

#include <vector>
#include "T100String.h"
#include "T100ProjectCommon.h"

namespace T100PROJECT{

#define     T100PROJECT_INFO_VECTOR         std::vector<T100PROJECT::T100ProjectInfo*>


class T100ProjectInfo
{
    public:
        T100ProjectInfo();
        virtual ~T100ProjectInfo();

        T100VOID                    setName(T100STRING);
        T100STRING                  getName();

        T100VOID                    setType(T100PROJECT_TYPE);
        T100PROJECT_TYPE            getType();

    protected:

    private:
        T100STRING                  m_name;
        T100PROJECT_TYPE            m_type          = T100PROJECT_TYPE_NONE;
};

}

#endif // T100PROJECTINFO_H
