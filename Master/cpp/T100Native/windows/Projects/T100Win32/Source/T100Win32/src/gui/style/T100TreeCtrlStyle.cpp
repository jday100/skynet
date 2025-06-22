#include "T100TreeCtrlStyle.h"

#include "gui/common/T100WindowCommon.h"

namespace T100WINDOWS{

T100TreeCtrlStyle::T100TreeCtrlStyle() :
    T100WindowStyle()
{
    //ctor
    ClassType   = T100WINDOW_TYPE_TREECTRL;
    WindowLabel = T100WINDOW_TYPE_T100TREECTRL;
}

T100TreeCtrlStyle::~T100TreeCtrlStyle()
{
    //dtor
}

}
