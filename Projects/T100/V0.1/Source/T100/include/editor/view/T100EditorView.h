#ifndef T100EDITORVIEW_H
#define T100EDITORVIEW_H

#include "T100Common.h"

namespace T100Editor{
class T100EditorFrame;


class T100EditorView
{
    public:
        T100EditorView();
        virtual ~T100EditorView();

        T100VOID                show();

    protected:
        T100VOID                create();
        T100VOID                destroy();

    private:
        T100EditorFrame*        m_frame             = T100NULL;

};

}

#endif // T100EDITORVIEW_H
