#ifndef T100CHARSCANNER_H
#define T100CHARSCANNER_H

#include "T100AssemblyCommon.h"
#include "T100ByteScanner.h"
#include "T100CharToken.h"


class T100CharScanner : public T100Scanner
{
    public:
        T100CharScanner();
        virtual ~T100CharScanner();

        T100VOID                setSource(T100Scanner*);
        T100Scanner*            getSource();

        T100BOOL                next(T100Token&);

    protected:
        T100CharToken*          m_token         = T100NULL;
        T100ByteToken           m_item;

        T100CharToken*          getToken();
        T100ByteToken*          getItem();

        T100WORD                m_row           = 0;

        T100BOOL                run();
        T100BOOL                append();
        T100VOID                clear();
        T100BOOL                read();

        T100TOKEN_TYPE          classify();

    private:
        T100ByteScanner*        m_scanner       = T100NULL;

};

#endif // T100CHARSCANNER_H
