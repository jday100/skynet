#ifndef T100ASM64LETTERSCANNER_H
#define T100ASM64LETTERSCANNER_H

#include "T100Scanner.h"
#include "T100Asm64LetterToken.h"


class T100Asm64LetterScanner : public T100Scanner
{
    public:
        T100Asm64LetterScanner();
        virtual ~T100Asm64LetterScanner();

        T100BOOL            open();
        T100BOOL            close();

        T100VOID            setSource(T100STRING);
        T100STRING          getSource();

        T100BOOL            next(T100Token&);

    protected:
        T100Asm64LetterToken*       m_token         = T100NULL;
        T100WCHAR                   m_item;

        T100BOOL            read();
        T100BOOL            append();
        T100VOID            clear();
        T100BOOL            classify();

    private:
        T100STRING                  m_filename;
        T100File*                   m_file          = T100NULL;
        T100Buffer*                 m_buffer        = T100NULL;
};

#endif // T100ASM64LETTERSCANNER_H
