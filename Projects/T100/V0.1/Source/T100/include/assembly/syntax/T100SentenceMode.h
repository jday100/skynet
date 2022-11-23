#ifndef T100SENTENCEMODE_H
#define T100SENTENCEMODE_H

#include "T100Sentence.h"

namespace T100Assembly{




class T100SentenceMode : public T100Sentence
{
    public:
        T100SentenceMode(T100SentenceScanner*);
        virtual ~T100SentenceMode();

        static T100VOID     init();

        T100MODE            mode            = T100MODE_VIRTUAL;

        T100BOOL            parse();

        T100BOOL            build(T100BuildInfo*);

    protected:
        T100BOOL            parseConfig();

    private:
};

}

#endif // T100SENTENCEMODE_H
