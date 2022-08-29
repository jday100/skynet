#include "T100IDECallbackEdit.h"

#include "T100IDEStore.h"
#include "T100IDEServe.h"
#include "T100IDEView.h"


T100IDECallbackEdit::T100IDECallbackEdit()
{
    //ctor
}

T100IDECallbackEdit::~T100IDECallbackEdit()
{
    //dtor
}

T100BOOL T100IDECallbackEdit::frame_menu_undo(void* d)
{
    return T100FALSE;
}

T100BOOL T100IDECallbackEdit::frame_menu_redo(void* d)
{
    return T100FALSE;
}

T100BOOL T100IDECallbackEdit::frame_menu_cut(void* d)
{
    return T100FALSE;
}

T100BOOL T100IDECallbackEdit::frame_menu_copy(void* d)
{
    return T100FALSE;
}

T100BOOL T100IDECallbackEdit::frame_menu_paste(void* d)
{
    return T100FALSE;
}
