#ifndef T100DISKAPP_H
#define T100DISKAPP_H

#include "gui/T100Win32Application.h"
#include "T100DiskSkeletal.h"

using namespace T100WINDOWS;

class T100DiskApp : public T100Win32Application
{
    public:
        T100DiskApp();
        virtual ~T100DiskApp();

        virtual T100VOID            Create();
        virtual T100VOID            Destroy();

    protected:
        T100DiskSkeletal            m_skeletal;

    private:
        T100VOID            OnQuit(T100MenuEvent&);
};

#endif // T100DISKAPP_H
