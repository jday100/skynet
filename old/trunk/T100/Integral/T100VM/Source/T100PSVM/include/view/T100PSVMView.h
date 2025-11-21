#ifndef T100PSVMVIEW_H
#define T100PSVMVIEW_H

#include "T100MainMenu.h"
#include "T100PSVMInfo.h"
#include "T100WxFileInfo.h"
#include "T100VMFrame.h"
#include "T100DebugFrame.h"

class T100VM;
class T100PSVMFrame;

class T100PSVMView
{
    public:
        T100PSVMView();
        virtual ~T100PSVMView();

        virtual T100VOID            Create(T100PSVMFrame*);
        virtual T100VOID            Destroy();

        T100BOOL                    Create(T100PSVMInfo*);
        T100BOOL                    Open(T100PSVMInfo*);
        T100BOOL                    Save(T100PSVMInfo*);
        T100BOOL                    SaveAs();
        T100BOOL                    Close();

        T100BOOL                    Start();
        T100BOOL                    Stop();

        T100BOOL                    DebugStart(T100VM*);
        T100BOOL                    DebugStop();

        T100VOID                    Dirty();

        T100VOID                    Log(T100STRING&);

        T100BOOL                    ShowFileOpenDialog(T100WxFileInfo*);
        T100BOOL                    ShowFileSaveDialog(T100WxFileInfo*);

        T100BOOL                    ShowCreateDialog(T100PSVMInfo*);
        T100BOOL                    ShowDebugFrame();

        T100VOID                    ShowCreateFailureDialog();
        T100VOID                    ShowOpenFailureDialog();
        T100VOID                    ShowCloseFailureDialog();

        T100VOID                    ShowVMStartFailureDialog();

    protected:
        T100PSVMFrame*              m_frame     = T100NULL;
        T100MainMenu*               m_mainMenu  = T100NULL;
        T100VMFrame*                m_vm        = T100NULL;
        T100DebugFrame*             m_debug     = T100NULL;

    private:
};

#endif // T100PSVMVIEW_H
