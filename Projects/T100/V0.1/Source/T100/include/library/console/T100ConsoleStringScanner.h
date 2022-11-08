#ifndef T100CONSOLESTRINGSCANNER_H
#define T100CONSOLESTRINGSCANNER_H

#include "T100Scanner.h"
#include "T100ConsoleStringToken.h"

namespace T100Library{

class T100ConsoleStringScanner : public T100Component::T100Scanner
{
    public:
        T100ConsoleStringScanner();
        virtual ~T100ConsoleStringScanner();

        T100VOID                    setSource(T100WSTRING);

        T100BOOL                    next(T100Component::T100Token&);

    protected:
        T100ConsoleStringToken*     m_token         = T100NULL;

        T100BOOL                    run();

    private:
        T100WSTRING                 m_line;

};

}

#endif // T100CONSOLESTRINGSCANNER_H
