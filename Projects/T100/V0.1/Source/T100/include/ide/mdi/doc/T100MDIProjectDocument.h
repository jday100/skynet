#ifndef T100MDIPROJECTDOCUMENT_H
#define T100MDIPROJECTDOCUMENT_H

#include "T100MDIDocumentBase.h"
#include "T100Project.h"

namespace T100IDE{

class T100MDIProjectDocument : public T100MDIDocumentBase
{
    public:
        T100MDIProjectDocument();
        virtual ~T100MDIProjectDocument();

        T100BOOL                        OnCreate(const wxString& path, long flags);

        T100BOOL                        IsModified() const;
        T100VOID                        Modify(T100BOOL mod);

    protected:
        T100VOID                        create();
        T100VOID                        destroy();

        T100PROJECT::T100Project*       GetProject() const;

        T100BOOL                        DoSaveDocument(const wxString& filename);
        T100BOOL                        DoOpenDocument(const wxString& filename);

    private:

        DECLARE_NO_COPY_CLASS(T100MDIProjectDocument);
        DECLARE_DYNAMIC_CLASS(T100MDIProjectDocument);
};

}

#endif // T100MDIPROJECTDOCUMENT_H
