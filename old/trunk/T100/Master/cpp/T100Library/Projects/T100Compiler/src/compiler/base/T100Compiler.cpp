#include "T100Compiler.h"

#include "T100FrontEnd.h"
#include "T100MiddleEnd.h"
#include "T100BackEnd.h"

namespace T100LIBRARY{

T100Compiler::T100Compiler() :
    T100Class()
{
    //ctor
}

T100Compiler::~T100Compiler()
{
    //dtor
}

T100VOID T100Compiler::SetFrontEnd(T100FrontEnd* frontEnd)
{
    m_frontEnd      = frontEnd;
}

T100FrontEnd* T100Compiler::GetFrontEnd()
{
    return m_frontEnd;
}

T100VOID T100Compiler::SetMiddleEnd(T100MiddleEnd* middleEnd)
{
    m_middleEnd     = middleEnd;
}

T100MiddleEnd* T100Compiler::GetMiddleEnd()
{
    return m_middleEnd;
}

T100VOID T100Compiler::SetBackEnd(T100BackEnd* backEnd)
{
    m_backEnd       = backEnd;
}

T100BackEnd* T100Compiler::GetBackEnd()
{
    return m_backEnd;
}

T100INT T100Compiler::Run(const T100WSTRING& file)
{
    T100BOOL                result;
    T100FrontInfo           frontInfo;
    T100MiddleInfo          middleInfo;
    T100BackInfo            backInfo;

    result  = m_frontEnd->Parse(file, frontInfo);
    if(!result){
        return -1;
    }

    result  = m_middleEnd->Execute(frontInfo, backInfo);
    if(!result){
        return -1;
    }

    result  = m_backEnd->Build(backInfo);
    if(!result){
        return -1;
    }
    return 0;
}

}
