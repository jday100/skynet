#include "T100TestTools.h"

#include <iomanip>
#include <sstream>
#include <iostream>


namespace T100Library{

T100TestTools::T100TestTools()
{
    //ctor
}

T100TestTools::~T100TestTools()
{
    //dtor
}

T100BOOL T100TestTools::Exists(T100WSTRING path)
{
    T100File        file(path);

    return file.exists();
}

T100BOOL T100TestTools::Remove(T100WSTRING name)
{
    T100BOOL        result          = T100TRUE;
    T100BOOL        value;

    T100File        file(name);

    if(file.exists()){
        result = file.remove();
    }

    return result;
}

T100BOOL T100TestTools::CleanAndCreate(T100File& file)
{
    T100BOOL        result          = T100TRUE;
    T100BOOL        value;

    value = file.exists();
    if(value){
        value = file.remove();
        if(value){
            value = file.exists();
            if(value){
                return T100FALSE;
            }
        }else{
            return T100FALSE;
        }
    }
    value = file.create();
    result = value;

    return result;
}

T100BOOL T100TestTools::Print(T100WORD_VECTOR& data)
{
    for(T100WORD item : data){
        std::cout << Hex(item);
        std::cout << " ";
    }
    return T100TRUE;
}

T100STDSTRING T100TestTools::Hex(T100WORD& value)
{
    std::stringstream       str;
    std::string             result;

    str << std::uppercase << std::hex << std::setw(8) << std::setfill('0') << value;

    result = str.str();

    result.insert(2, " ");
    result.insert(5, " ");
    result.insert(8, " ");

    return result;
}

T100BOOL T100TestTools::Print(T100WSTRING msg)
{
    wprintf(L"%ls\n", msg.c_str());
    return T100TRUE;
}

T100BOOL T100TestTools::Print(void* value)
{
    wprintf(L"%10X\n", value);
    return T100TRUE;
}

}
