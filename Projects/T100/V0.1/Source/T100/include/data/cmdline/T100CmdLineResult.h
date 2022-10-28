#ifndef T100CMDLINERESULT_H
#define T100CMDLINERESULT_H

#include "T100Common.h"
#include "T100Class.h"

namespace T100Library{

class T100CmdLineResult : public T100Class
{
    public:
        T100CmdLineResult();
        virtual ~T100CmdLineResult();

        T100WSTRING         exec;

    protected:

    private:
};

}

#endif // T100CMDLINERESULT_H
