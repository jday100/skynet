#include "T100IDEEditorPlaten.h"

#include <wx/aui/aui.h>
#include "T100IDEView.h"
#include "T100IDEViewManager.h"


namespace T100IDE{

T100IDEEditorPlaten::T100IDEEditorPlaten(T100IDEView* view)
    :T100IDEPlatenBase(view)
{
    //ctor
}

T100IDEEditorPlaten::~T100IDEEditorPlaten()
{
    //dtor
}

T100BOOL T100IDEEditorPlaten::create()
{
    return T100TRUE;
}

T100VOID T100IDEEditorPlaten::destroy()
{

}

T100BOOL T100IDEEditorPlaten::show()
{
    return T100TRUE;
}

T100BOOL T100IDEEditorPlaten::hide()
{
    return T100TRUE;
}

}
