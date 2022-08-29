#ifndef T100CMDLINEPARAMETERSCANNER_H
#define T100CMDLINEPARAMETERSCANNER_H

#include "T100Scanner.h"
#include "T100CmdLineParameterToken.h"
#include "T100CmdLineCharScanner.h"
#include "T100CmdLineInfo.h"


class T100CmdLineParameterScanner : public T100Scanner
{
    friend class T100CmdLineInfo;
    friend class T100CmdLineParam;
    public:
        T100CmdLineParameterScanner();
        virtual ~T100CmdLineParameterScanner();

        T100VOID                        setSource(T100Scanner*);
        T100Scanner*                    getSource();

        T100VOID                        setInfo(T100CmdLineInfo*);

        T100BOOL                        next(T100Token&);

    protected:
        T100CmdLineParameterToken*      m_token         = T100NULL;
        T100CmdLineCharToken            m_item;

        T100BOOL                        run();

        T100CmdLineInfo*                parse();

        T100BOOL                        read();
        T100BOOL                        append();
        T100BOOL                        classify();

    private:
        T100CmdLineCharScanner*         m_scanner       = T100NULL;
        T100CmdLineInfo*                m_info          = T100NULL;

};

#endif // T100CMDLINEPARAMETERSCANNER_H
