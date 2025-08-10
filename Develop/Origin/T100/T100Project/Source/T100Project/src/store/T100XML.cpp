#include "T100XML.h"

T100XML::T100XML(const T100WSTRING& filename) :
    m_filename(filename)
{
    //ctor
    init();
}

T100XML::~T100XML()
{
    //dtor
    uninit();
}

T100VOID T100XML::init()
{

}

T100VOID T100XML::uninit()
{

}
