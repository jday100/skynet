#ifndef T100SENTENCEVARIABLE_H
#define T100SENTENCEVARIABLE_H

#include "T100Sentence.h"

namespace T100Assembly{

class T100SentenceVariable : public T100Sentence
{
    public:
        T100SentenceVariable(T100SentenceScanner*);
        virtual ~T100SentenceVariable();

        T100STRING          name;
        T100Component::T100OPERATOR        target;

        T100BOOL            parse();

        T100BOOL            build(T100BuildInfo*);

    protected:
        T100BOOL            parseType();
        T100BOOL            parseValue();

        T100BOOL            setDefine();

        T100BOOL            buildFloat(T100BuildInfo*);
        T100BOOL            buildInteger(T100BuildInfo*);
        T100BOOL            buildString(T100BuildInfo*);

    private:
};

}

#endif // T100SENTENCEVARIABLE_H
