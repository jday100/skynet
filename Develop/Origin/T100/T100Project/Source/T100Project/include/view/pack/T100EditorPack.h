#ifndef T100EDITORPACK_H
#define T100EDITORPACK_H

#include <wx/sizer.h>
#include "T100Pack.h"
#include "T100Editor.h"

class T100EditorPack : public T100Pack
{
    public:
        T100EditorPack(wxWindow*);
        virtual ~T100EditorPack();

        T100VOID                SetEditor(T100Editor*);
        T100Editor*             GetEditor();

    protected:
        T100Editor*             m_editor        = T100NULL;

    private:
        T100VOID                init();
        T100VOID                uninit();
};

#endif // T100EDITORPACK_H
