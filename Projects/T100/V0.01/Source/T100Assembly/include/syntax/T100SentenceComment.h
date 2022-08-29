#ifndef T100SENTENCECOMMENT_H
#define T100SENTENCECOMMENT_H

#include "T100Sentence.h"


class T100SentenceComment : public T100Sentence
{
    public:
        T100SentenceComment(T100SentenceScanner*);
        virtual ~T100SentenceComment();

        T100BOOL            parse();

        T100BOOL            build(T100BuildInfo*);

    protected:

    private:
};

#endif // T100SENTENCECOMMENT_H
