#include "T100ProjectTransverter.h"

namespace T100Component{

T100ProjectTransverter::T100ProjectTransverter()
    :T100StateTransverter()
{
    //ctor
}

T100ProjectTransverter::~T100ProjectTransverter()
{
    //dtor
}

T100BOOL T100ProjectTransverter::Change(T100WORD state)
{
    switch(state){

    }
}

T100PROJECT::T100ProjectState* T100ProjectTransverter::GetCurrent()
{
    return m_state;
}

}
