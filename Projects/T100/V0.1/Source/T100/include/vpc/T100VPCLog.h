#ifndef T100VPCLOG_H
#define T100VPCLOG_H

#include "T100String.h"
#include "T100LogNew.h"

namespace T100VPC{

class T100VPCLog
{
    public:
        T100VPCLog();
        virtual ~T100VPCLog();

        static T100BOOL                     start();
        static T100BOOL                     stop();

        static T100BOOL                     running();

        static T100BOOL                     append(T100Library::T100LogBase*);
        static T100BOOL                     remove(T100Library::T100LogBase*);

        static T100VOID                     fatal(T100STRING);
        static T100VOID                     error(T100STRING);
        static T100VOID                     warn(T100STRING);
        static T100VOID                     debug(T100STRING);
        static T100VOID                     trace(T100STRING);
        static T100VOID                     info(T100STRING);

    protected:

    private:
        static T100Library::T100LogNew      m_log;

};

}

#endif // T100VPCLOG_H
