#ifndef T100SENTENCEHALT_H
#define T100SENTENCEHALT_H

#include "T100Sentence.h"

namespace T100Assembly{

class T100SentenceHalt : public T100Sentence
{
    public:
        T100SentenceHalt(T100SentenceScanner*);
        virtual ~T100SentenceHalt();

        static T100VOID     init();

        T100BOOL            parse();

        T100BOOL            build(T100BuildInfo*);

    protected:

    private:
};

}

#endif // T100SENTENCEHALT_H
