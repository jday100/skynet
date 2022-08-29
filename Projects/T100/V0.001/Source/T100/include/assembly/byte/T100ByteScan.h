#ifndef T100BYTESCAN_H
#define T100BYTESCAN_H

#include <fstream>
#include "T100AsmCommon.h"
#include "T100Scan.h"
#include "T100ByteToken.h"


class T100ByteScan : protected T100Scan
{
    public:
        T100ByteScan();
        virtual ~T100ByteScan();

        virtual T100BOOL        next(IToken&);
        virtual T100BOOL        open(T100String&);
        virtual T100BOOL        close();

    protected:
        virtual T100BOOL        run();
        virtual T100BOOL        read();

        T100ByteToken*          getToken();
        T100TOKEN_TYPE          classify(T100BYTE);

    private:
        T100ByteToken*          m_token         = T100NULL;
        T100String              m_file;
        std::ifstream*          m_ifs           = T100NULL;

        T100STDCHAR             m_buffer[1024];
        T100WORD                m_length        = 0;
        T100WORD                m_offset        = 0;
};

#endif // T100BYTESCAN_H
