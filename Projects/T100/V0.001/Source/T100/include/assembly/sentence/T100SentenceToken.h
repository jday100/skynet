#ifndef T100SENTENCETOKEN_H
#define T100SENTENCETOKEN_H

#include "T100Token.h"
class T100Sentence;


#define     T100SENTENCE_VECTOR     std::vector<T100SentenceToken*>



class T100SentenceToken : public T100Token
{
    public:
        T100SentenceToken();
        virtual ~T100SentenceToken();

        T100Sentence*           data                = T100NULL;
        T100BYTE_VECTOR         bytes;

        T100SentenceToken*      copy();
        T100VOID                clear();
        T100STDSTRING           tostring();

    protected:

    private:
};

#endif // T100SENTENCETOKEN_H
