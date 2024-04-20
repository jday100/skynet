#ifndef T100CANVASTRANSVERTER_H
#define T100CANVASTRANSVERTER_H

#include <mutex>
#include "T100CanvasStateNone.h"
#include "T100CanvasStateEdit.h"
#include "T100CanvasStatePaint.h"
#include "T100CanvasStateSizing.h"
#include "T100CanvasStateSelected.h"

class T100CanvasTransverter
{
    public:
        T100CanvasTransverter();
        virtual ~T100CanvasTransverter();

        T100CanvasState*                Current();
        T100VOID                        Change(T100WORD);

    protected:
        T100CanvasState*                m_state             = T100NULL;

    private:
        std::mutex                      m_mutex;
        T100CanvasStateNone*            m_none              = T100NULL;
        T100CanvasStateEdit*            m_edit              = T100NULL;
        T100CanvasStatePaint*           m_paint             = T100NULL;
        T100CanvasStateSizing*          m_sizing            = T100NULL;
        T100CanvasStateSelected*        m_selected          = T100NULL;
};

#endif // T100CANVASTRANSVERTER_H
