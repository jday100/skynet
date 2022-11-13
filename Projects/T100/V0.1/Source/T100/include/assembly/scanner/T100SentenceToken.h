#ifndef T100SENTENCETOKEN_H
#define T100SENTENCETOKEN_H

#include "T100Token.h"


#define     T100SENTENCE_VECTOR         std::vector<T100SentenceToken*>


namespace T100Assembly{
class T100Sentence;

class T100SentenceToken : public T100Component::T100Token
{
    public:
        T100SentenceToken();
        virtual ~T100SentenceToken();

        T100Sentence*           value           = T100NULL;

        T100SentenceToken*      copy();
        T100VOID                clear();

    protected:

    private:
};

}

#endif // T100SENTENCETOKEN_H
