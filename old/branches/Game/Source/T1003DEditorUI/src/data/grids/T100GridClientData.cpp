#include "T100GridClientData.h"

T100GridClientData::T100GridClientData(wxPropertyGrid* grid) :
    wxClientData(),
    m_gridPtr(grid)
{
    //ctor
}

T100GridClientData::~T100GridClientData()
{
    //dtor
}
