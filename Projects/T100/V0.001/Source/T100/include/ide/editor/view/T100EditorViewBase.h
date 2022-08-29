#ifndef T100EDITORVIEWBASE_H
#define T100EDITORVIEWBASE_H

#include "T100Common.h"
class T100EditorView;


class T100EditorViewBase
{
    public:
        T100EditorViewBase(T100EditorView*);
        virtual ~T100EditorViewBase();

    protected:
        T100EditorView*         m_view          = T100NULL;

    private:
};

#endif // T100EDITORVIEWBASE_H
