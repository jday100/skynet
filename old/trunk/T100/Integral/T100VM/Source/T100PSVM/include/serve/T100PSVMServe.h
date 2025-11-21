#ifndef T100PSVMSERVE_H
#define T100PSVMSERVE_H

#include <atomic>
#include "T100PSVMInfo.h"
#include "T100VMServe.h"

class T100PSVMServe
{
    public:
        T100PSVMServe();
        virtual ~T100PSVMServe();

        T100VOID                    SetDirty(T100BOOL);

        T100BOOL                    IsOpened();
        T100BOOL                    IsDirty();

        T100PSVMInfo*               GetPSVMInfo();
        T100VMServe&                GetVMServe();

        T100BOOL                    Create(T100PSVMInfo*&);
        T100BOOL                    Open(T100PSVMInfo*);
        T100BOOL                    Close();

    protected:
        std::atomic_bool            m_opened;
        std::atomic_bool            m_dirty;

        T100VMServe                 m_vm;

        T100PSVMInfo*               m_info      = T100NULL;

    private:
};

#endif // T100PSVMSERVE_H
