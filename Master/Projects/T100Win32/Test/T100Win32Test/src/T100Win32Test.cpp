#include "T100Win32Test.h"

T100Win32Test::T100Win32Test(HINSTANCE hThisInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, T100INT nCmdShow) :
    T100TestNode(L"Win32", T100NULL),
    m_hThisInstance(hThisInstance),
    m_hPrevInstance(hPrevInstance),
    m_lpCmdLine(lpCmdLine),
    m_nCmdShow(nCmdShow),
    test_app(this)
{
    //ctor
    init();
}

T100Win32Test::~T100Win32Test()
{
    //dtor
    uninit();
}

T100VOID T100Win32Test::init()
{

}

T100VOID T100Win32Test::uninit()
{

}
