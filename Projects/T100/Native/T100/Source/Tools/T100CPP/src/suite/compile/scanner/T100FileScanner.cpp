#include "T100FileScanner.h"

T100FileScanner::T100FileScanner()
    :T100GrammarScanner()
{
    //ctor
}

T100FileScanner::~T100FileScanner()
{
    //dtor
}

T100BOOL T100FileScanner::SetSource(T100File& file)
{
    m_file  = &file;
    return T100FALSE;
}

T100File& T100FileScanner::GetSource()
{
    return *m_file;
}

T100BOOL T100FileScanner::Next()
{
    return T100FALSE;
}
