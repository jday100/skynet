#ifndef T100SENTENCEDATA_H
#define T100SENTENCEDATA_H

#include "T100Sentence.h"

namespace T100Assembly{

class T100SentenceData : public T100Sentence
{
    public:
        T100SentenceData(T100SentenceScanner*);
        virtual ~T100SentenceData();

        static T100VOID     init();

        T100STRING          name;
        T100BOOL            isVirtual           = T100FALSE;
        T100BOOL            isDefault           = T100FALSE;
        T100BOOL            isShare             = T100FALSE;
        T100WORD            location            = 0;
        T100WORD            length              = 0;

        T100BOOL            parse();

        T100BOOL            build(T100BuildInfo*);

    protected:
        T100BOOL            parseConfig();

    private:
};

}

#endif // T100SENTENCEDATA_H
