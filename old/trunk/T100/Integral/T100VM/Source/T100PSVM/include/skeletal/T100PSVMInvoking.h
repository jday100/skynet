#ifndef T100PSVMINVOKING_H
#define T100PSVMINVOKING_H

#include "T100PSVMSkeletal.h"

class T100PSVMInvoking
{
    public:
        T100PSVMInvoking();
        virtual ~T100PSVMInvoking();

        static T100VOID                     Init(T100PSVMFrame*);
        static T100VOID                     Uninit();

        static T100VOID                     OnFileCreate();
        static T100VOID                     OnFileOpen();
        static T100VOID                     OnFileClose();
        static T100VOID                     OnFileSave();
        static T100VOID                     OnFileSaveAs();
        static T100VOID                     OnFileQuit();

        static T100VOID                     OnVMStart();
        static T100VOID                     OnVMStop();

        static T100VOID                     OnDebugStart();
        static T100VOID                     OnDebugStop();

        static T100VOID                     OnHelpAbout();

        static T100VOID                     OnLog(T100STRING);

    protected:

    private:
        static T100PSVMSkeletal*            m_skeletal;
};

#endif // T100PSVMINVOKING_H
