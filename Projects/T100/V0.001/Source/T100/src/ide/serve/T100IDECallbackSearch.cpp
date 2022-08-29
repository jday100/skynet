#include "T100IDECallbackSearch.h"

#include "T100IDEStore.h"
#include "T100IDEServe.h"
#include "T100IDEView.h"


T100IDECallbackSearch::T100IDECallbackSearch()
{
    //ctor
}

T100IDECallbackSearch::~T100IDECallbackSearch()
{
    //dtor
}

T100BOOL T100IDECallbackSearch::frame_menu_find(void* d)
{
    return T100FALSE;
}

T100BOOL T100IDECallbackSearch::frame_menu_replace(void* d)
{
    return T100FALSE;
}
