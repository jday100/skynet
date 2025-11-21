#ifndef T100CVMVIEW_H
#define T100CVMVIEW_H

#include "gui/T100Frame.h"
#include "T100CVMViewMainMenu.h"

using namespace T100WINDOWS;

class T100CVMView
{
    public:
        T100CVMView();
        virtual ~T100CVMView();

        virtual T100VOID            Create(T100Frame*);
        virtual T100VOID            Destroy();

    protected:
        T100Frame*                  m_frame         = T100NULL;
        T100CVMViewMainMenu*        m_mainMenu      = T100NULL;

    private:
};

#endif // T100CVMVIEW_H
