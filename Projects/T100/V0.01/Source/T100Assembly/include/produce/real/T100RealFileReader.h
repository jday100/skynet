#ifndef T100REALFILEREADER_H
#define T100REALFILEREADER_H

#include "T100Common.h"
#include "T100FileReader.h"
#include "T100RealInfo.h"


class T100RealFileReader : public T100FileReader
{
    public:
        T100RealFileReader(T100STRING);
        virtual ~T100RealFileReader();

        T100BOOL            load(T100RealInfo&);

    protected:
        T100BOOL            read_head();
        T100BOOL            read_data();
        T100BOOL            read_code();

    private:
        T100RealInfo*       m_info          = T100NULL;

};

#endif // T100REALFILEREADER_H
