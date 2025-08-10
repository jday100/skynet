#include "base/T100Size.h"

namespace T100LIBRARY{

T100Size::T100Size() :
    T100Class()
{
    //ctor
}

T100Size::T100Size(T100INT width, T100INT height) :
    T100Class(),
    Width(width),
    Height(height)
{
    //ctor
}

T100Size::~T100Size()
{
    //dtor
}

}
