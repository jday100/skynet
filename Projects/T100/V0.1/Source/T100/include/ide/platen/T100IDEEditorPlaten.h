#ifndef T100IDEEDITORPLATEN_H
#define T100IDEEDITORPLATEN_H

#include <wx/menu.h>
#include "T100IDEPlatenBase.h"

namespace T100IDE{

class T100IDEEditorPlaten : public T100IDEPlatenBase
{
    public:
        T100IDEEditorPlaten(T100IDEView*);
        virtual ~T100IDEEditorPlaten();

        T100BOOL            create();

        T100BOOL            show();

    protected:
        T100VOID            destroy();

    private:
};

}

#endif // T100IDEEDITORPLATEN_H
