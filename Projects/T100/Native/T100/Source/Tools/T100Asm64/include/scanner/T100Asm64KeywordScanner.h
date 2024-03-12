#ifndef T100ASM64KEYWORDSCANNER_H
#define T100ASM64KEYWORDSCANNER_H

#include "T100Scanner.h"
#include "T100Asm64KeywordToken.h"
#include "T100Asm64KeywordTable.h"
#include "T100Asm64StringToken.h"
#include "T100Asm64StringScanner.h"


class T100Asm64KeywordScanner : public T100Scanner
{
    public:
        T100Asm64KeywordScanner();
        virtual ~T100Asm64KeywordScanner();

        T100VOID                    setSource(T100Scanner*);
        T100Scanner*                getSource();

        T100BOOL                    next(T100Token&);

    protected:
        T100Asm64KeywordToken*      m_token         = T100NULL;
        T100Asm64StringToken        m_item;
        T100Asm64KeywordTable       m_table;

        T100BOOL                    append();
        T100BOOL                    classify();

    private:
        T100Asm64StringScanner*     m_scanner       = T100NULL;
};

#endif // T100ASM64KEYWORDSCANNER_H
