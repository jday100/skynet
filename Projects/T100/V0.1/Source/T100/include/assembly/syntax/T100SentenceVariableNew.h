#ifndef T100SENTENCEVARIABLENEW_H
#define T100SENTENCEVARIABLENEW_H

#include "T100DataStructure.h"
#include "T100SentenceBase.h"

namespace T100Assembly{

class T100SentenceVariableNew : public T100SentenceBase::T100SentenceBase
{
    public:
        T100SentenceVariableNew(T100SentenceScanner*);
        virtual ~T100SentenceVariableNew();

        static T100VOID         init();

        ::T100SentenceBase::T100OPERATOR      target;

        T100BOOL                parse();

        T100BOOL                build(T100BuildInfo*);

    protected:
        T100BOOL                parseType();
        T100BOOL                parseValue();

        T100BOOL                parseDefault();
        T100BOOL                parseArray();

        T100BOOL                parseInteger();
        T100BOOL                parseFloat();
        T100BOOL                parseString();

        T100BOOL                buildInteger(T100BuildInfo*);
        T100BOOL                buildFloat(T100BuildInfo*);
        T100BOOL                buildString(T100BuildInfo*);

        T100BOOL                setDefine();

    private:
        T100FLOAT               FLOAT;
        T100STRING              STRING;

        T100WORD_VECTOR         m_integer;
        T100FLOAT_VECTOR        m_float;
        T100STRING_VECTOR       m_string;

};

}

#endif // T100SENTENCEVARIABLENEW_H
