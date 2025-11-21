#ifndef T100PSVMSKELETAL_H
#define T100PSVMSKELETAL_H

#include "T100PSVMSkeletalBase.h"

class T100PSVMSkeletal : public T100PSVMSkeletalBase
{
    public:
        T100PSVMSkeletal();
        virtual ~T100PSVMSkeletal();

        virtual T100VOID            Create(T100PSVMFrame*);
        virtual T100VOID            Destroy();

        T100VOID                    OnFileCreate();
        T100VOID                    OnFileOpen();
        T100VOID                    OnFileClose();
        T100VOID                    OnFileSave();
        T100VOID                    OnFileSaveAs();
        T100VOID                    OnFileQuit();

        T100VOID                    OnVMStart();
        T100VOID                    OnVMStop();

        T100VOID                    OnDebugStart();
        T100VOID                    OnDebugStop();

        T100VOID                    OnHelpAbout();

        T100VOID                    OnLog(T100STRING&);

    protected:

    private:
};

#endif // T100PSVMSKELETAL_H
