#ifndef T100PROJECTVIEW_H
#define T100PROJECTVIEW_H

#include "T100Common.h"
#include "gui/T100Frame.h"
#include "view/platen/T100ProjectPlatenManager.h"

using namespace T100LIBRARY;
using namespace T100WINDOWS;

class T100ProjectView
{
    public:
        T100ProjectView();
        virtual ~T100ProjectView();

        T100VOID                        SetFrame(T100Frame*);
        T100Frame*                      GetFrame();

        T100ProjectPlatenManager&       GetPlatenManager();

        T100VOID                        Default();

    protected:
        T100Frame*                      m_frame         = T100NULL;
        T100ProjectPlatenManager        m_platenManager;

    private:
};

#endif // T100PROJECTVIEW_H
