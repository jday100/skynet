#include "T100CXCompiler.h"

#include "T100CXFrontEnd.h"
#include "T100CXMiddleEnd.h"
#include "T100CXBackEnd.h"

T100CXCompiler::T100CXCompiler() :
    T100Compiler()
{
    //ctor
    init();
}

T100CXCompiler::~T100CXCompiler()
{
    //dtor
    uninit();
}

T100VOID T100CXCompiler::init()
{
    m_frontEnd      = T100NEW T100CXFrontEnd();
    m_middleEnd     = T100NEW T100CXMiddleEnd();
    m_backEnd       = T100NEW T100CXBackEnd();
}

T100VOID T100CXCompiler::uninit()
{
    T100SAFE_DELETE(m_backEnd);
    T100SAFE_DELETE(m_middleEnd);
    T100SAFE_DELETE(m_frontEnd);
}
