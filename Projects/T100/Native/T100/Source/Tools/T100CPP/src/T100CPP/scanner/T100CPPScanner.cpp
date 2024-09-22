#include "T100CPPScanner.h"

T100CPPScanner::T100CPPScanner()
{
    //ctor
}

T100CPPScanner::~T100CPPScanner()
{
    //dtor
}

T100BOOL T100CPPScanner::create()
{
    m_keyword_scanner       = T100NEW T100CPPKeywordScanner();
    m_element_scanner       = T100NEW T100CPPElementScanner();
    m_sentence_scanner      = T100NEW T100CPPSentenceScanner();
    m_part_scanner          = T100NEW T100CPPPartScanner();
    m_project_scanner       = T100NEW T100CPPProjectScanner();

    return T100TRUE;
}

T100BOOL T100CPPScanner::destroy()
{
    return T100FALSE;
}

T100BOOL T100CPPScanner::done()
{
    T100BOOL        result          = T100FALSE;

    result  = create();

    if(result){
        result = execute();
    }

    return result;
}

T100BOOL T100CPPScanner::execute()
{
    return T100FALSE;
}

