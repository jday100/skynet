#include "T100Edit.h"

#include "T100File.h"

T100Edit::T100Edit() :
    m_view()
{
    //ctor
}

T100Edit::~T100Edit()
{
    //dtor
}

int T100Edit::Run()
{
    //m_view.Show();

    T100File            document;

    T100FILE_VECTOR     data;


    document.Read(data);

    return 0;
}
