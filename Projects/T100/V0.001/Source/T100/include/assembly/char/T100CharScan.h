#ifndef T100CHARSCAN_H
#define T100CHARSCAN_H

#include "T100AsmCommon.h"
#include "T100ByteScan.h"
#include "T100CharToken.h"


class T100CharScan : public T100Scan
{
    public:
        T100CharScan();
        virtual ~T100CharScan();

        T100BOOL                next(IToken&);
        T100BOOL                open(T100String&);
        T100BOOL                close();

    protected:
        T100String              m_file;
        T100CharToken*          m_token             = T100NULL;
        T100ByteToken           m_item;

        T100CharToken*          getToken();
        T100ByteToken*          getItem();

        T100WORD                m_row               = 1;

        T100BOOL                run();
        T100BOOL                append();
        T100VOID                clear();
        T100BOOL                read();

        T100TOKEN_TYPE          classify();

    private:
        T100ByteScan*           m_scan              = T100NULL;

};

#endif // T100CHARSCAN_H
