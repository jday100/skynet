#ifndef T100VDISKVIEW_H
#define T100VDISKVIEW_H

#include "IView.h"
#include "T100VDiskFrame.h"


class T100VDiskView : public IView
{
    public:
        T100VDiskView();
        virtual ~T100VDiskView();

        T100VOID            create();

        T100VOID            setFrame(T100VDiskFrame*);
        T100VDiskFrame*     getFrame();

        T100BOOL            show();

        T100BOOL            start();

    protected:
        T100VOID            destroy();

    private:
        T100VDiskFrame*     m_frame         = T100NULL;
};

#endif // T100VDISKVIEW_H
