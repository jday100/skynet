#ifndef T100BACKINFO_H
#define T100BACKINFO_H

#include "base/T100Class.h"
#include "vessel/T100Vessel.h"
#include "compiler/data/T100SourceInfo.h"

namespace T100LIBRARY{

#define     T100COMPILER_SOURCE_VESSEL          T100Vessel<T100WSTRING, T100SourceInfo*>

class T100BackInfo : public T100Class
{
    public:
        T100BackInfo();
        virtual ~T100BackInfo();

        const T100WSTRING&                      GetFileName();

    protected:
        T100COMPILER_SOURCE_VESSEL              m_sources;

    private:
        T100WSTRING                             m_filename;
};

}

#endif // T100BACKINFO_H
