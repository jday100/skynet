#include "T100EditorDocument.h"

T100EditorDocument::T100EditorDocument()
{
    //ctor
}

T100EditorDocument::~T100EditorDocument()
{
    //dtor
}

T100VOID T100EditorDocument::setFileName(T100WString& filename)
{
    m_filename  = filename;
}

T100WString& T100EditorDocument::getFileName()
{
    return m_filename;
}

T100VOID T100EditorDocument::setExtension(T100WString& extension)
{
    m_extension = extension;
}

T100WString& T100EditorDocument::getExtension()
{
    return m_extension;
}

T100VOID T100EditorDocument::setPath(T100WString& path)
{
    m_path      = path;
}

T100WString& T100EditorDocument::getPath()
{
    return m_path;
}
