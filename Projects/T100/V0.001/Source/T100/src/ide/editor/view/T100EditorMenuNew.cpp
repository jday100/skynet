#include "T100EditorMenuNew.h"

#include "T100IDEServe.h"
#include "T100IDEView.h"


T100EditorMenuNew::T100EditorMenuNew()
{
    //ctor
}

T100EditorMenuNew::~T100EditorMenuNew()
{
    //dtor
}

T100BOOL T100EditorMenuNew::run(T100IDEServe* serve, T100IDEView* view)
{
    T100BOOL    result      = T100FALSE;

    /*
    if(view->getFile()->opened()){
        result = view->getFile()->close();
    }else{
        result = T100TRUE;
    }

    if(result){
        result = view->getFile()->create();
    }else{

    }

    if(result){
        result = view->getFile()->open();
    }
    */

    return T100FALSE;
}
