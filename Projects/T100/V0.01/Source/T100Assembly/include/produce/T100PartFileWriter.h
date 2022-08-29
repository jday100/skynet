#ifndef T100PARTFILEWRITER_H
#define T100PARTFILEWRITER_H

#include "T100Common.h"
#include "T100FileWriter.h"
#include "T100PartInfo.h"


class T100PartFileWriter : public T100FileWriter
{
    public:
        T100PartFileWriter(T100STRING);
        virtual ~T100PartFileWriter();

        T100BOOL            save(T100PartInfo*);

    protected:

    private:
        T100PartInfo*       m_info          = T100NULL;

};

#endif // T100PARTFILEWRITER_H
