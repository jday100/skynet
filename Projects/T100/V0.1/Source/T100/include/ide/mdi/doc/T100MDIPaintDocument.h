#ifndef T100MDIPAINTDOCUMENT_H
#define T100MDIPAINTDOCUMENT_H

#include "T100MDIDocumentBase.h"
#include "T100Painter.h"

namespace T100IDE{

class T100MDIPaintDocument : public T100MDIDocumentBase
{
    public:
        T100MDIPaintDocument();
        virtual ~T100MDIPaintDocument();

        T100BOOL                    OnCreate(const wxString& path, long flags);

        T100BOOL                    IsModified() const;
        T100VOID                    Modify(T100BOOL mod);

    protected:
        T100VOID                    create();
        T100VOID                    destroy();

        T100Painter::T100Painter*       GetPainter() const;

        T100BOOL            DoSaveDocument(const wxString& filename);
        T100BOOL            DoOpenDocument(const wxString& filename);

    private:

        DECLARE_NO_COPY_CLASS(T100MDIPaintDocument);
        DECLARE_DYNAMIC_CLASS(T100MDIPaintDocument);
};

}

#endif // T100MDIPAINTDOCUMENT_H
