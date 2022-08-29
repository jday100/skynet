#ifndef T100FONT_H
#define T100FONT_H

#include "T100FontFile.h"

#define     T100FONT_VECTOR     std::vector<T100WORD>
#define     T100FONT_HASH       std::unordered_map<T100WORD, T100FONT_VECTOR*>


class T100Font
{
    public:
        T100Font();
        virtual ~T100Font();

        T100BOOL                load(T100String);

        T100WORD                getWidth();
        T100WORD                getHeight();

        T100BOOL                getFont(T100WORD, T100FONT_VECTOR*&);

    protected:
        T100WORD                m_width         = 0;
        T100WORD                m_height        = 0;

        T100VOID                clear(T100FONTFILE_ROW_VECTOR&);
        T100BOOL                unwind(T100WORD, T100WORD*, T100HWORD);
        T100BOOL                unwind(T100WORD, T100FONT_VECTOR*);

    private:
        T100FONT_HASH           m_fonts;
};

#endif // T100FONT_H
