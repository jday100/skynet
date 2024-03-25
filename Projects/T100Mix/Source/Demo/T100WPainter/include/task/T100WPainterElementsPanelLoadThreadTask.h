#ifndef T100WPAINTERELEMENTSPANELLOADTHREADTASK_H
#define T100WPAINTERELEMENTSPANELLOADTHREADTASK_H

#include "T100WxThreadTask.h"
class T100WPainterElementsPanel;

class T100WPainterElementsPanelLoadThreadTask : public T100WxThreadTask
{
    public:
        T100WPainterElementsPanelLoadThreadTask();
        virtual ~T100WPainterElementsPanelLoadThreadTask();

        T100VOID            setPanel(T100WPainterElementsPanel*);

    protected:
        T100VOID                            run();

    private:
        T100WPainterElementsPanel*          m_panel         = T100NULL;
};

#endif // T100WPAINTERELEMENTSPANELLOADTHREADTASK_H
