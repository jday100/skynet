#include "T100BackEnd.h"



namespace T100LIBRARY{

T100BackEnd::T100BackEnd() :
    T100Class()
{
    //ctor
}

T100BackEnd::~T100BackEnd()
{
    //dtor
}

T100VOID T100BackEnd::SetBuilder(T100Builder* builder)
{
    m_builder       = builder;
}

T100Builder* T100BackEnd::GetBuilder()
{
    return m_builder;
}

T100BOOL T100BackEnd::Build(const T100BackInfo& info)
{
    m_builder->Build(info);
}

}
