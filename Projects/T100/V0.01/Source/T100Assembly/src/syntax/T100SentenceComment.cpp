#include "T100SentenceComment.h"

T100SentenceComment::T100SentenceComment(T100SentenceScanner* scanner)
    :T100Sentence(scanner)
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

T100BOOL T100SentenceComment::build(T100BuildInfo* info)
{
    return T100TRUE;
}
