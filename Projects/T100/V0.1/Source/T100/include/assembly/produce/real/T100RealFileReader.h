#ifndef T100REALFILEREADER_H
#define T100REALFILEREADER_H

#include "T100Common.h"
#include "T100FileReader.h"
#include "T100RealInfo.h"

namespace T100Assembly{

class T100RealFileReader : public T100FileReader
{
    public:
        T100RealFileReader(T100STRING);
        virtual ~T100RealFileReader();

        T100BOOL            load(T100RealInfo&);

    protected:

    private:
        T100RealInfo*       m_info          = T100NULL;

};

}

#endif // T100REALFILEREADER_H
