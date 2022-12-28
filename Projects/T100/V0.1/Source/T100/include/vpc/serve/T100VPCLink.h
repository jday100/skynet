#ifndef T100VPCLINK_H
#define T100VPCLINK_H

#include "T100QU32Interface.h"

namespace T100VPC{
class T100VPCServe;
class T100VPCView;


class T100VPCLink : public T100QU32::T100QU32Interface
{
    public:
        T100VPCLink();
        virtual ~T100VPCLink();

        static T100BOOL             init(T100VPCServe*, T100VPCView*);

        T100BOOL                    notify_start();
        T100BOOL                    notify_stop();


        T100BOOL                    notify_cmt_update(T100WORD);

        T100BOOL                    notify_register_update(T100WORD, T100WORD);

        T100BOOL                    notify_memory_update(T100WORD, T100WORD);
        T100BOOL                    notify_port_update(T100WORD, T100WORD);

        T100BOOL                    notify_debug_pause();

    protected:

    private:
        static T100VPCServe*        m_serve;
        static T100VPCView*         m_view;

};

}

#endif // T100VPCLINK_H
