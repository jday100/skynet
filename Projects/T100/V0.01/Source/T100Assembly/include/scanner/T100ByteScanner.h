#ifndef T100BYTESCANNER_H
#define T100BYTESCANNER_H

#include <fstream>
#include "T100AssemblyCommon.h"
#include "T100Scanner.h"
#include "T100ByteToken.h"


class T100ByteScanner : public T100Scanner
{
    public:
        T100ByteScanner();
        virtual ~T100ByteScanner();

        virtual T100BOOL            open(T100WSTRING);
        virtual T100BOOL            close();

        virtual T100BOOL            next(T100Token&);

    protected:
        virtual T100BOOL            run();
        virtual T100BOOL            read();

        T100ByteToken*              getToken();
        T100TOKEN_TYPE              classify(T100BYTE);

    private:
        T100ByteToken*              m_token             = T100NULL;
        T100WSTRING                 m_file;

        std::ifstream*              m_ifs               = T100NULL;

        T100STDCHAR                 m_buffer[1024];
        T100WORD                    m_length            = 0;
        T100WORD                    m_index             = 0;

};

#endif // T100BYTESCANNER_H
