#ifndef T100PSVMSKELETALBASE_H
#define T100PSVMSKELETALBASE_H

#include "T100PSVMView.h"
#include "T100PSVMServe.h"
#include "T100PSVMStore.h"

class T100PSVMSkeletalBase
{
    public:
        T100PSVMSkeletalBase();
        virtual ~T100PSVMSkeletalBase();

        T100BOOL                FileClose();
        T100BOOL                FileSave();
        T100BOOL                FileSaveAs();


    protected:
        T100PSVMView*           m_view      = T100NULL;
        T100PSVMServe*          m_serve     = T100NULL;
        T100PSVMStore*          m_store     = T100NULL;

    private:
};

#endif // T100PSVMSKELETALBASE_H
