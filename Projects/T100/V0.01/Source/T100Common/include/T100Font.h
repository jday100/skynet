#ifndef T100FONT_H
#define T100FONT_H

#include "T100FontFile.h"


class T100Font
{
    public:
        T100Font();
        virtual ~T100Font();

        T100BOOL                    load(T100String);

        T100VOID                    setName(T100String);
        T100String                  getName();

        T100VOID                    setWidth(T100WORD);
        T100WORD                    getWidth();

        T100VOID                    setHeight(T100WORD);
        T100WORD                    getHeight();

        T100BOOL                    setRowSize(T100WORD);
        T100WORD                    getRowSize();

        T100BOOL                    setFont(T100WORD, T100FONT_DATA_VECTOR*);
        T100BOOL                    getFont(T100WORD, T100FONT_DATA_VECTOR*&);

        T100BOOL                    appendRow(T100FONTFILE_ROW*);
        T100BOOL                    removeRow(T100FONTFILE_ROW*);

        T100FONT_ROW_VECTOR&        getFonts();

    protected:
        T100STRING                  m_name;
        T100WORD                    m_width         = 0;
        T100WORD                    m_height        = 0;
        T100WORD                    m_row_size      = 0;

    private:
        T100FONT_HASH               m_fonts;
        T100FONT_ROW_VECTOR         m_rows;

};

#endif // T100FONT_H
