#ifndef T100DISPLAYINFO_H
#define T100DISPLAYINFO_H

#include "T100DeviceInfo.h"
#include "T100VPCDisplaySetupDialog.h"

namespace T100VPC{

class T100DisplayInfo : public T100DeviceInfo
{
    friend class T100VPCDisplay;
    friend class T100VPCDisplaySetupDialog;
    public:
        T100DisplayInfo();
        virtual ~T100DisplayInfo();

        T100WORD            count();
        T100BOOL            verify();

        T100BOOL            append(T100DisplayInfo*);
        T100BOOL            remove(T100DisplayInfo*);
        T100BOOL            getDeviceInfos(T100DEVICE_INFO_VECTOR&);

        T100BOOL            setup();

        T100BOOL            insert(wxListView*);

    protected:
        T100VOID            init();

        T100BOOL            append(T100DeviceInfo*);
        T100BOOL            remove(T100DeviceInfo*);

    protected:
        T100VOID            create();
        T100VOID            destroy();

        T100VPCDisplaySetupDialog*      m_setup         = T100NULL;

    private:
        T100STRING          m_font;

        T100WORD            m_width;
        T100WORD            m_height;

};

}

#endif // T100DISPLAYINFO_H
