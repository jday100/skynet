#ifndef T100MDITEXTDOCUMENT_H
#define T100MDITEXTDOCUMENT_H

#include "T100MDIDocumentBase.h"

namespace T100IDE{

class T100MDITextDocument : public T100MDIDocumentBase
{
    public:
        T100MDITextDocument();
        virtual ~T100MDITextDocument();

    protected:

    private:

        DECLARE_NO_COPY_CLASS(T100MDITextDocument);
        DECLARE_DYNAMIC_CLASS(T100MDITextDocument);
};

}

#endif // T100MDITEXTDOCUMENT_H
