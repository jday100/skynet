#include "T100Material.h"

T100Material::T100Material()
{
    //ctor
}

T100Material::~T100Material()
{
    //dtor
}

T100VOID T100Material::ToJSON(JSON& json)
{
    json["name"]        = Name;
}

T100VOID T100Material::FromJSON(JSON& json)
{
    Name                = json["name"].get<std::wstring>();
}

T100VOID T100Material::SetDiffuse(T100FLOAT red, T100FLOAT green, T100FLOAT blue, T100FLOAT alpha)
{
    T100Vector4     value(red, green, blue, alpha);
    SetDiffuse(value);
}

T100VOID T100Material::SetDiffuse(T100Vector4& value)
{
    m_diffuse   = value;
}

T100Vector4& T100Material::GetDiffuse()
{
    return m_diffuse;
}

T100VOID T100Material::SetSpecular(T100FLOAT red, T100FLOAT green, T100FLOAT blue, T100FLOAT alpha)
{
    T100Vector4     value(red, green, blue, alpha);
    SetSpecular(value);
}

T100VOID T100Material::SetSpecular(T100Vector4& value)
{
    m_diffuse   = value;
}

T100Vector4& T100Material::GetSpecular()
{
    return m_specular;
}

T100VOID T100Material::SetAmbient(T100FLOAT red, T100FLOAT green, T100FLOAT blue, T100FLOAT alpha)
{
    T100Vector4     value(red, green, blue, alpha);
    SetAmbient(value);
}

T100VOID T100Material::SetAmbient(T100Vector4& value)
{
    m_ambient   = value;
}

T100Vector4& T100Material::GetAmbient()
{
    return m_ambient;
}

T100VOID T100Material::SetEmissive(T100FLOAT red, T100FLOAT green, T100FLOAT blue, T100FLOAT alpha)
{
    T100Vector4     value(red, green, blue, alpha);
    SetEmissive(value);
}

T100VOID T100Material::SetEmissive(T100Vector4& value)
{
    m_emissive  = value;
}

T100Vector4& T100Material::GetEmissive()
{
    return m_emissive;
}

T100VOID T100Material::SetTransparent(T100FLOAT red, T100FLOAT green, T100FLOAT blue, T100FLOAT alpha)
{
    T100Vector4     value(red, green, blue, alpha);
    SetTransparent(value);
}

T100VOID T100Material::SetTransparent(T100Vector4& value)
{
    m_transparent   = value;
}

T100Vector4& T100Material::GetTransparent()
{
    return m_transparent;
}
