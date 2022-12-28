#ifndef T100MDIVIEWBASE_H
#define T100MDIVIEWBASE_H

#include <wx/docmdi.h>
#include "T100Common.h"

namespace T100IDE{
class T100IDEView;

class T100MDIViewBase : public wxView
{
    public:
        T100MDIViewBase();
        virtual ~T100MDIViewBase();

    protected:
        T100IDEView*            m_view          = T100NULL;


    private:
};

}

#endif // T100MDIVIEWBASE_H
