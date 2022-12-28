#ifndef T100MDIDOCUMENTBASE_H
#define T100MDIDOCUMENTBASE_H

#include <wx/docmdi.h>
#include "T100Common.h"

namespace T100IDE{
class T100IDEServe;


class T100MDIDocumentBase : public wxDocument
{
    public:
        T100MDIDocumentBase();
        virtual ~T100MDIDocumentBase();

    protected:

    private:
};

}

#endif // T100MDIDOCUMENTBASE_H
