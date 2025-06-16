#include "log/T100LoggerNormal.h"

namespace T100LIBRARY{

T100LoggerNormal::T100LoggerNormal() :
    T100LoggerBase()
{
    //ctor
    init();
}

T100LoggerNormal::~T100LoggerNormal()
{
    //dtor
    uninit();
}

T100VOID T100LoggerNormal::init()
{

}

T100VOID T100LoggerNormal::uninit()
{

}

T100VOID T100LoggerNormal::Out(const T100WSTRING& value)
{

}

}
