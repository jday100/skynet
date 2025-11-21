#include "T100JSON.h"

#include "T100Unicode.h"

T100JSON::T100JSON()
{
    //ctor
}

T100JSON::T100JSON(T100WCHAR*)
{
    //ctor
}

T100JSON::T100JSON(T100WSTRING)
{
    //ctor
}

T100JSON::T100JSON(std::initializer_list<std::pair<std::string, std::string>> value)
{
    //ctor
    m_json = value;
}

T100JSON::~T100JSON()
{
    //dtor
}

JSON& T100JSON::GetJSON()
{
    return m_json;
}

T100BOOL T100JSON::IsObject()
{
    return m_json.is_object();
}

JSON::iterator T100JSON::Find(T100STRING value)
{
    return m_json.find(value);
}

JSON::iterator T100JSON::End()
{
    return m_json.end();
}

JSON& T100JSON::At(T100STRING value)
{
    return m_json.at(value);
}

T100WSTRING T100JSON::operator[](T100CHAR* value)
{
    return m_json[value];
}

/*
std::istream* operator>>(std::istream* is, const T100JSON& json)
{

}

std::ostream* operator<<(std::ostream* os, const T100JSON& json)
{

}
*/

std::ifstream& operator>>(std::ifstream& ifs, T100JSON& json)
{
    ifs >> json.m_json;
    return ifs;
}

std::ofstream& operator<<(std::ofstream& ofs, const T100JSON& json)
{
    /*
    if(!ofs.is_open()){
        T100WSTRING     file;
        T100STRING      filename;

        file        = json.m_filename;
        filename    = T100Unicode::to_string8(file);
        ofs.open(filename);

        ofs.close();
    }
    */

    ofs << json.m_json;
    ofs.flush();
    return ofs;
}
