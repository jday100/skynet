#ifndef T100SENTENCEMODE_H
#define T100SENTENCEMODE_H

#include "T100Sentence.h"

typedef enum{
    T100MODE_NONE           = 0,
    T100MODE_REAL,
    T100MODE_VIRTUAL,
    T100MODE_MAX
}T100MODE;

typedef enum{
    T100TYPE_NONE           = 0,
    T100TYPE_TINY,
    T100TYPE_SMALL,
    T100TYPE_BIG,
    T100TYPE_MAX
}T100TYPE;


class T100SentenceMode : public T100Sentence
{
    public:
        T100SentenceMode(T100SentenceScan*);
        virtual ~T100SentenceMode();

        T100BOOL            istiny          = T100FALSE;
        T100MODE            mode            = T100MODE_VIRTUAL;
        T100TYPE            segment_type    = T100TYPE_NONE;

        T100BOOL            parse();
        T100BOOL            build(T100FileData*);

    protected:
        T100BOOL            parseSetup();

    private:
};

#endif // T100SENTENCEMODE_H
