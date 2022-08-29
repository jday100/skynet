#ifndef T100SENTENCECOMMENT_H
#define T100SENTENCECOMMENT_H

#include "T100Sentence.h"


class T100SentenceComment : public T100Sentence
{
    public:
        T100SentenceComment(T100SentenceScan*);
        virtual ~T100SentenceComment();

        T100BOOL                parse();

    protected:

    private:
};

#endif // T100SENTENCECOMMENT_H
