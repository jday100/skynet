#ifndef T100ASM64SENTENCESCANNER_H
#define T100ASM64SENTENCESCANNER_H

#include "T100Scanner.h"
#include "T100Asm64KeywordToken.h"
#include "T100Asm64KeywordScanner.h"
#include "T100Asm64SentenceToken.h"


class T100Asm64SentenceScanner : public T100Scanner
{
    public:
        T100Asm64SentenceScanner();
        virtual ~T100Asm64SentenceScanner();

        T100VOID            setSource(T100Scanner*);
        T100Scanner*        getSource();

        T100BOOL            next(T100Token&);

    protected:
        T100Asm64SentenceToken*     m_token         = T100NULL;
        T100Asm64KeywordToken       m_item;

        T100SentenceBase*           m_sentence      = T100NULL;

        T100BOOL            read();
        T100BOOL            append();

        T100Asm64SentenceToken*     getToken();
        T100Asm64KeywordToken*      getItem();

        T100BOOL            parse();

    private:
        T100Asm64KeywordScanner*    m_scanner       = T100NULL;
};

#endif // T100ASM64SENTENCESCANNER_H
