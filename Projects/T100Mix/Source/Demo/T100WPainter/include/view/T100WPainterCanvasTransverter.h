#ifndef T100WPAINTERCANVASTRANSVERTER_H
#define T100WPAINTERCANVASTRANSVERTER_H

#include <mutex>
#include "T100WPainterCanvasState.h"

class T100WPainterCanvasTransverter
{
    public:
        T100WPainterCanvasTransverter();
        virtual ~T100WPainterCanvasTransverter();

        T100WPainterCanvasState*            GetCurrent();
        T100VOID                            Change(T100WORD);

    protected:
        T100WPainterCanvasState*            m_state         = T100NULL;

    private:
        std::mutex                          m_mutex;
};

#endif // T100WPAINTERCANVASTRANSVERTER_H
