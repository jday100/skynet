#ifndef T100WPAINTERCANVASTRANSVERTER_H
#define T100WPAINTERCANVASTRANSVERTER_H

#include <mutex>
#include "T100WPainterCanvasState.h"
#include "T100WPainterCanvasStateNone.h"
#include "T100WPainterCanvasStateEdit.h"
#include "T100WPainterCanvasStatePaint.h"
#include "T100WPainterCanvasStateSizing.h"
#include "T100WPainterCanvasStateSelected.h"

class T100WPainterCanvasTransverter
{
    public:
        T100WPainterCanvasTransverter();
        virtual ~T100WPainterCanvasTransverter();

        T100WPainterCanvasState*                GetCurrent();
        T100VOID                                Change(T100WORD);

    protected:
        T100WPainterCanvasState*                m_state         = T100NULL;

    private:
        std::mutex                              m_mutex;
        T100WPainterCanvasStateNone*            m_none          = T100NULL;
        T100WPainterCanvasStateEdit*            m_edit          = T100NULL;
        T100WPainterCanvasStatePaint*           m_paint         = T100NULL;
        T100WPainterCanvasStateSizing*          m_sizing        = T100NULL;
        T100WPainterCanvasStateSelected*        m_selected      = T100NULL;
};

#endif // T100WPAINTERCANVASTRANSVERTER_H
