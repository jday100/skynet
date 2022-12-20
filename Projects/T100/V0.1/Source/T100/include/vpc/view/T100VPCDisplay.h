#ifndef T100VPCDISPLAY_H
#define T100VPCDISPLAY_H

#include "T100QU32.h"
#include "T100DisplayInfo.h"
#include "T100Display.h"

namespace T100VPC{
class T100VPCHost;
class T100VPCPanel;


class T100VPCDisplay : public T100Display
{
    public:
        T100VPCDisplay(T100QU32::T100QU32*, T100VPCHost*, T100DisplayInfo*);
        virtual ~T100VPCDisplay();

        T100BOOL                create();

    protected:
        T100BOOL                load();

        T100BOOL                OnCreate(void* = T100NULL);

    private:
        T100QU32::T100QU32*     m_host          = T100NULL;
        T100VPCHost*            m_frame         = T100NULL;
        T100VPCPanel*           m_panel         = T100NULL;
        T100DisplayInfo*        m_info          = T100NULL;
        T100Display*            m_display       = T100NULL;

};

}

#endif // T100VPCDISPLAY_H
