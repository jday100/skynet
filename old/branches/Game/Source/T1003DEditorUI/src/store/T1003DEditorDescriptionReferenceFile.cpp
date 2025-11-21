#include "T1003DEditorDescriptionReferenceFile.h"

T1003DEditorDescriptionReferenceFile::T1003DEditorDescriptionReferenceFile(T1003DEDITOR_DESCRIPTION_REFERENCE_DATA_VECTOR& value) :
    m_descriptionReferences(value)
{
    //ctor
}

T1003DEditorDescriptionReferenceFile::~T1003DEditorDescriptionReferenceFile()
{
    //dtor
}

T1003DEDITOR_DESCRIPTION_REFERENCE_DATA_VECTOR& T1003DEditorDescriptionReferenceFile::GetDescriptionReferences()
{
    return m_descriptionReferences;
}

T100VOID T1003DEditorDescriptionReferenceFile::encode()
{

}

T100VOID T1003DEditorDescriptionReferenceFile::decode()
{

}

std::ifstream& operator>>(std::ifstream& ifs, T1003DEditorDescriptionReferenceFile& desc)
{
    ifs >> desc.m_json;
    desc.decode();
    return ifs;
}

std::ofstream& operator<<(std::ofstream& ofs, T1003DEditorDescriptionReferenceFile& desc)
{
    desc.encode();
    ofs << desc.m_json;
    return ofs;
}
