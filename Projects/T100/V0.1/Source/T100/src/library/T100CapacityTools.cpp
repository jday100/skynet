#include "T100CapacityTools.h"

#include "T100CapacityParser.h"

namespace T100Library{

T100CapacityTools::T100CapacityTools()
{
    //ctor
}

T100CapacityTools::~T100CapacityTools()
{
    //dtor
}

T100BOOL T100CapacityTools::to_word(T100WSTRING str, T100WORD& value)
{
    T100BOOL        result          = T100FALSE;

    if(str.empty()){
        return T100FALSE;
    }

    T100CapacityParser          capacity;

    //result = capacity.parse(str, value);

    return result;
}

T100BOOL T100CapacityTools::to_dword(T100WSTRING str, T100DWORD& value)
{

}

T100WSTRING T100CapacityTools::to_wstring(T100WORD value)
{
    T100WSTRING         result;

    if(0 == value){
        result = L"0";
    }

    return result;
}

T100WSTRING T100CapacityTools::to_wstring(T100DWORD value)
{

}

}
