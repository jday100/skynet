#ifndef T100PARTFILEREADER_H
#define T100PARTFILEREADER_H

#include "T100Common.h"
#include "T100FileReader.h"
#include "T100PartInfo.h"

namespace T100Assembly{

class T100PartFileReader : public T100Library::T100FileReader
{
    public:
        T100PartFileReader(T100STRING);
        virtual ~T100PartFileReader();

        T100BOOL            load(T100PartInfo&);

    protected:

    private:
        T100PartInfo*       m_info          = T100NULL;

};

}

#endif // T100PARTFILEREADER_H
