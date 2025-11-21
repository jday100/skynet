#ifndef T100DISKVIEW_H
#define T100DISKVIEW_H

#include "gui/T100Frame.h"
#include "T100DiskViewMainMenu.h"

using namespace T100WINDOWS;

class T100DiskView
{
    public:
        T100DiskView();
        virtual ~T100DiskView();

        virtual T100VOID            Create(T100Frame*);
        virtual T100VOID            Destroy();

    protected:
        T100Frame*                  m_frame         = T100NULL;
        T100DiskViewMainMenu*       m_mainMenu      = T100NULL;

    private:
};

#endif // T100DISKVIEW_H
