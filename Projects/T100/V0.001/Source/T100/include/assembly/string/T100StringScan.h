#ifndef T100STRINGSCAN_H
#define T100STRINGSCAN_H

#include "T100CharScan.h"
#include "T100StringToken.h"


class T100StringScan : public T100Scan
{
    public:
        T100StringScan();
        virtual ~T100StringScan();

        T100BOOL                next(IToken&);
        T100BOOL                open(T100String&);
        T100BOOL                close();

    protected:
        T100StringToken*        m_token             = T100NULL;
        T100CharToken           m_item;

        T100StringToken*        getToken();
        T100CharToken*          getItem();

        T100BOOL                run();
        T100VOID                clear();
        T100BOOL                append();
        T100BOOL                read();

        T100BOOL                classify();
        T100BOOL                isOperator();

    private:
        T100CharScan*           m_scan              = T100NULL;
        T100TOKEN_TYPE          m_type              = T100TOKEN_NONE;

};

#endif // T100STRINGSCAN_H
