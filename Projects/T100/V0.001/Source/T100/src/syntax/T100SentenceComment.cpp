#include "T100SentenceComment.h"

#include "T100SentenceScan.h"


T100SentenceComment::T100SentenceComment(T100SentenceScan* scan)
    :T100Sentence(scan)
{
    //ctor
}

T100SentenceComment::~T100SentenceComment()
{
    //dtor
}

T100BOOL T100SentenceComment::parse()
{
    return T100TRUE;
}
