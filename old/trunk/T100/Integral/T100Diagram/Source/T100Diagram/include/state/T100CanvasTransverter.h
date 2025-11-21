#ifndef T100CANVASTRANSVERTER_H
#define T100CANVASTRANSVERTER_H

#include "T100StateTransverter.h"
#include "T100CanvasStateNone.h"
#include "T100CanvasStateShow.h"
#include "T100CanvasStateEdit.h"
#include "T100CanvasStatePaint.h"
#include "T100CanvasStateCreate.h"
#include "T100CanvasStateMoving.h"
#include "T100CanvasStateSelected.h"
#include "T100CanvasStateTieStart.h"
#include "T100CanvasStateTieEnd.h"

class T100CanvasTransverter : public T100StateTransverter
{
    public:
        T100CanvasTransverter();
        virtual ~T100CanvasTransverter();

        T100UINT                GetState();

        T100CanvasState*        GetCurrent();

        T100VOID                Change(T100UINT);

    protected:
        T100CanvasState*                m_state     = T100NULL;

    private:

        T100CanvasStateNone*            m_none      = T100NULL;
        T100CanvasStateShow*            m_show      = T100NULL;
        T100CanvasStateEdit*            m_edit      = T100NULL;
        T100CanvasStatePaint*           m_paint     = T100NULL;
        T100CanvasStateCreate*          m_create    = T100NULL;
        T100CanvasStateMoving*          m_moving    = T100NULL;
        T100CanvasStateSelected*        m_selected  = T100NULL;
        T100CanvasStateTieStart*        m_tieStart  = T100NULL;
        T100CanvasStateTieEnd*          m_tieEnd    = T100NULL;
};

#endif // T100CANVASTRANSVERTER_H
