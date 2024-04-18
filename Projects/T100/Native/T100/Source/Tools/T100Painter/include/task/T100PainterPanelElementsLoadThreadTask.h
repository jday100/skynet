#ifndef T100PAINTERPANELELEMENTSLOADTHREADTASK_H
#define T100PAINTERPANELELEMENTSLOADTHREADTASK_H

#include "T100WxThreadTask.h"
class T100PainterElementsPanel;

class T100PainterPanelElementsLoadThreadTask : public T100WxThreadTask
{
    public:
        T100PainterPanelElementsLoadThreadTask();
        virtual ~T100PainterPanelElementsLoadThreadTask();

        T100VOID                        setPanel(T100PainterElementsPanel*);

    protected:
        T100VOID                        run();

        T100BOOL                        load(T100STRING);

    private:
        T100PainterElementsPanel*       m_panel         = T100NULL;

};

#endif // T100PAINTERPANELELEMENTSLOADTHREADTASK_H
