#ifndef T100FONTFILE1_H
#define T100FONTFILE1_H

#include "T100UnicodeCommon.h"
#include "T100File.h"
#include "T100String.h"
#include "T100FontFileReader.h"
#include "T100FontFileWriter.h"
class T100Font;



class T100FontFile : public T100File
{
    public:
        T100FontFile(T100String);
        virtual ~T100FontFile();

        T100FontFileReader*         getReader(T100Font*);

        T100FontFileWriter*         getWriter(T100Font*);

    public:
        T100VOID                    setFontName(T100String);
        T100String                  getFontName();

        T100VOID                    setFontWidth(T100WORD);
        T100WORD                    getFontWidth();

        T100VOID                    setFontHeight(T100WORD);
        T100WORD                    getFontHeight();

        T100VOID                    setRowSize(T100WORD);
        T100WORD                    getRowSize();

    protected:
        T100String                  m_font_name;
        T100WORD                    m_font_width;
        T100WORD                    m_font_height;
        T100WORD                    m_row_size          = 0;

    private:
};

#endif // T100FONTFILE1_H


