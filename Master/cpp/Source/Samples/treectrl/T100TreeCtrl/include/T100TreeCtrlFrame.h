#ifndef T100TREECTRLFRAME_H
#define T100TREECTRLFRAME_H

#include "gui/T100Frame.h"
#include "gui/T100TreeCtrl.h"

class T100TreeCtrlFrame : public T100Frame
{
    public:
        T100TreeCtrlFrame(T100Win32Application*);
        virtual ~T100TreeCtrlFrame();

        T100VOID            Create(T100WSTRING);

    protected:
        T100TreeCtrl        m_treeCtrl;

        T100VOID            OnWindowMessage(T100WindowEvent&);

    private:
        T100VOID            init();
        T100VOID            uninit();
};

#endif // T100TREECTRLFRAME_H
