#ifndef T100WXVIEW_H
#define T100WXVIEW_H

#include "T100ViewBase.h"
#include "T100RenderBase.h"
#include "wx/dc.h"

class T100WxView : public T100ViewBase
{
    public:
        T100WxView();
        virtual ~T100WxView();

        T100VOID                SetRender(T100RenderBase*);
        T100RenderBase*         GetRender();

        T100VOID                Draw(T100VOID* = T100NULL);

        T100VOID                DrawPoint(wxDC*, T100INT, T100INT, T100WORD);

    protected:
        T100RenderBase*         m_render            = T100NULL;

    private:
};

#endif // T100WXVIEW_H
