#ifndef T100MDITEXTDOCUMENT_H
#define T100MDITEXTDOCUMENT_H

#include "T100MDIDocumentBase.h"
#include "T100Editor.h"


namespace T100IDE{

class T100MDITextDocument : public T100MDIDocumentBase
{
    public:
        T100MDITextDocument();
        virtual ~T100MDITextDocument();

        T100BOOL                    OnCreate(const wxString& path, long flags);

        T100BOOL                    IsModified() const;
        T100VOID                    Modify(T100BOOL mod);

    protected:
        T100VOID                    create();
        T100VOID                    destroy();

        T100Editor::T100Editor*     GetEditor() const;

        T100BOOL                    DoSaveDocument(const wxString& filename);
        T100BOOL                    DoOpenDocument(const wxString& filename);

    private:

        DECLARE_NO_COPY_CLASS(T100MDITextDocument);
        DECLARE_DYNAMIC_CLASS(T100MDITextDocument);
};

}

#endif // T100MDITEXTDOCUMENT_H
