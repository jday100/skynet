#ifndef T100PARTINFO_H
#define T100PARTINFO_H

#include "T100AssemblyCommon.h"

#include "T100ParseInfo.h"
#include "T100BuildInfo.h"

namespace T100Assembly{

class T100PartInfo
{
    friend class T100RealBuilder;
    public:
        T100PartInfo();
        virtual ~T100PartInfo();

        T100VOID            setName(T100STRING);
        T100STRING          getName();

        T100ParseInfo&      getParseInfo();
        T100BuildInfo&      getBuildInfo();

    protected:
        T100ParseInfo       m_parse_info;
        T100BuildInfo       m_build_info;

    private:
        T100STRING          m_name;
        T100BOOL            m_master            = T100FALSE;

};

}

#endif // T100PARTINFO_H
