#ifndef T100STRINGSCANNER_H
#define T100STRINGSCANNER_H

#include "T100CharScanner.h"
#include "T100StringToken.h"


class T100StringScanner : public T100Scanner
{
    public:
        T100StringScanner();
        virtual ~T100StringScanner();

        T100VOID                setSource(T100Scanner*);
        T100Scanner*            getSource();

        T100BOOL                next(T100Token&);

    protected:
        T100StringToken*        m_token         = T100NULL;
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
        T100CharScanner*        m_scanner       = T100NULL;
        T100TOKEN_TYPE          m_type          = T100TOKEN_NONE;

};

#endif // T100STRINGSCANNER_H
