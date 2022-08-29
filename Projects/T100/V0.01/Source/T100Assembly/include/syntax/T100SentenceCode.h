#ifndef T100SENTENCECODE_H
#define T100SENTENCECODE_H

#include "T100Sentence.h"


class T100SentenceCode : public T100Sentence
{
    public:
        T100SentenceCode(T100SentenceScanner*);
        virtual ~T100SentenceCode();

        T100String          name;
        T100BOOL            isVirtual       = T100FALSE;
        T100BOOL            isDefault       = T100FALSE;
        T100BOOL            isShare         = T100FALSE;
        T100WORD            location        = 0;
        T100WORD            length          = 0;

        T100BOOL            parse();

        T100BOOL            build(T100BuildInfo*);

    protected:
        T100BOOL            parseConfig();

    private:
};

#endif // T100SENTENCECODE_H
