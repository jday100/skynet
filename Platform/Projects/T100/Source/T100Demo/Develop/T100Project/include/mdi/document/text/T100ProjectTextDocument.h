#ifndef T100PROJECTTEXTDOCUMENT_H
#define T100PROJECTTEXTDOCUMENT_H

#include "T100ProjectMDIDocument.h"

class T100ProjectTextDocument : public T100ProjectMDIDocument
{
    public:
        T100ProjectTextDocument();
        virtual ~T100ProjectTextDocument();

        T100BOOL                    OnCreate(const wxString& path, long flags);

        T100BOOL                    IsModifed() const;
        T100VOID                    Modify(T100BOOL mod);

    protected:
        T100VOID                    create();
        T100VOID                    destroy();

        T100BOOL                    DoSaveDocument(const wxString& filename);
        T100BOOL                    DoOpenDocument(const wxString& filename);

    private:
        DECLARE_NO_COPY_CLASS(T100ProjectTextDocument);
        DECLARE_DYNAMIC_CLASS(T100ProjectTextDocument);
};

#endif // T100PROJECTTEXTDOCUMENT_H
