#ifndef T100EDITORFRAME_H
#define T100EDITORFRAME_H

#include "gui/T100Frame.h"
#include "gui/textctrl/T100TextCtrl.h"

class T100EditorFrame : public T100Frame
{
    public:
        T100EditorFrame();
        virtual ~T100EditorFrame();

        virtual T100VOID            Create(T100Win32Application*);

    protected:

    private:
};

#endif // T100EDITORFRAME_H
