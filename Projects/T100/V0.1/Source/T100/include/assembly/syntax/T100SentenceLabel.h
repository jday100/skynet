#ifndef T100SENTENCELABEL_H
#define T100SENTENCELABEL_H

#include "T100Sentence.h"

namespace T100Assembly{

class T100SentenceLabel : public T100Sentence
{
    public:
        T100SentenceLabel(T100SentenceScanner*);
        virtual ~T100SentenceLabel();

        T100STRING          name;

        T100BOOL            parse();

        T100BOOL            build(T100BuildInfo*);

    protected:
        T100BOOL            setDefine(T100STRING&);

    private:
};

}

#endif // T100SENTENCELABEL_H
