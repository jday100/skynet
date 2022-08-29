#ifndef T100REALFILEWRITER_H
#define T100REALFILEWRITER_H

#include "T100Common.h"
#include "T100FileWriter.h"
#include "T100RealInfo.h"


class T100RealFileWriter : public T100FileWriter
{
    public:
        T100RealFileWriter(T100STRING);
        virtual ~T100RealFileWriter();

        T100BOOL            save(T100RealInfo&);

    protected:
        T100BOOL            write_head();
        T100BOOL            write_data();
        T100BOOL            write_code();

    private:
        T100RealInfo*       m_info          = T100NULL;

};

#endif // T100REALFILEWRITER_H
