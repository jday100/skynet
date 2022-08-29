#ifndef T100SENTENCEHALT_H
#define T100SENTENCEHALT_H

#include "T100Sentence.h"


class T100SentenceHalt : public T100Sentence
{
    public:
        T100SentenceHalt(T100SentenceScan*);
        virtual ~T100SentenceHalt();

        T100BOOL            parse();
        T100BOOL            build(T100FileData*);

    protected:

    private:
};

#endif // T100SENTENCEHALT_H
