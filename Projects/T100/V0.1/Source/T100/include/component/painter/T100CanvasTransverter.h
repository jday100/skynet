#ifndef T100CANVASTRANSVERTER_H
#define T100CANVASTRANSVERTER_H

#include <mutex>
#include "T100StateTransverter.h"
#include "T100CanvasStateNone.h"
#include "T100CanvasStateCommon.h"
#include "T100CanvasStatePaint.h"
#include "T100CanvasStateSelected.h"
#include "T100CanvasStateSizing.h"
#include "T100CanvasStateEdit.h"

namespace T100Component{

class T100CanvasTransverter : public T100StateTransverter
{
    public:
        T100CanvasTransverter();
        virtual ~T100CanvasTransverter();

        T100WORD                            GetState();

        T100Painter::T100CanvasState*       GetCurrent();
        T100VOID            Change(T100WORD);

    protected:
        T100Painter::T100CanvasState*               m_state         = T100NULL;

    private:
        std::mutex          m_mutex;

        T100Painter::T100CanvasStateNone*           m_none          = T100NULL;
        T100Painter::T100CanvasStateCommon*         m_common        = T100NULL;
        T100Painter::T100CanvasStatePaint*          m_paint         = T100NULL;
        T100Painter::T100CanvasStateSelected*       m_selected      = T100NULL;
        T100Painter::T100CanvasStateSizing*         m_sizing        = T100NULL;
        T100Painter::T100CanvasStateEdit*           m_edit          = T100NULL;

};

}

#endif // T100CANVASTRANSVERTER_H
