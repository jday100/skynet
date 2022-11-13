#ifndef T100SENTENCEMODE_H
#define T100SENTENCEMODE_H

#include "T100Sentence.h"

namespace T100Assembly{

typedef enum{
    T100MODE_NONE           = 0,
    T100MODE_REAL,
    T100MODE_VIRTUAL,
    T100MODE_MAX
}T100MODE;


class T100SentenceMode : public T100Sentence
{
    public:
        T100SentenceMode(T100SentenceScanner*);
        virtual ~T100SentenceMode();

        T100MODE            mode            =;

        T100BOOL            parse();

        T100BOOL            build(T100BuildInfo*);

    protected:
        T100BOOL            parseConfig();

    private:
};

}

#endif // T100SENTENCEMODE_H
