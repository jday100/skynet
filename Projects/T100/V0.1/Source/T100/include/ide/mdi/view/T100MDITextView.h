#ifndef T100MDITEXTVIEW_H
#define T100MDITEXTVIEW_H

#include "T100MDIViewBase.h"
#include "T100MDITextFrame.h"

namespace T100IDE{

class T100MDITextView : public T100MDIViewBase
{
    public:
        T100MDITextView();
        virtual ~T100MDITextView();

        T100VOID                    OnDraw(wxDC* dc);

    protected:

    private:
        DECLARE_EVENT_TABLE()
        DECLARE_DYNAMIC_CLASS(T100MDITextView)
};

}

#endif // T100MDITEXTVIEW_H
