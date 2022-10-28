#ifndef T100CMDLINESTRINGSCANNER_H
#define T100CMDLINESTRINGSCANNER_H

#include "T100Scanner.h"
#include "T100CmdLineStringToken.h"

namespace T100Library{

class T100CmdLineStringScanner : public T100Component::T100Scanner
{
    public:
        T100CmdLineStringScanner();
        virtual ~T100CmdLineStringScanner();

        T100VOID                        setSource(int, wchar_t**);

        T100BOOL                        next(T100Component::T100Token&);

    protected:
        T100CmdLineStringToken*         m_token         = T100NULL;

        T100BOOL                        run();

    private:
        T100INT                         m_index         = 0;
        int                             m_argc;
        wchar_t**                       m_argv          = T100NULL;

};

}

#endif // T100CMDLINESTRINGSCANNER_H
