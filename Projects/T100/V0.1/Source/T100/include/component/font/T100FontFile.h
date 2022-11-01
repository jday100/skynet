#ifndef T100FONTFILE_H
#define T100FONTFILE_H

#include "T100File.h"
#include "T100String.h"
#include "T100FontFileReader.h"
#include "T100FontFileWriter.h"


namespace T100Component{
class T100Font;


class T100FontFile : public T100Library::T100File
{
    public:
        T100FontFile(T100STRING);
        virtual ~T100FontFile();

        T100FontFileReader*         getReader(T100Font*);

        T100FontFileWriter*         getWriter(T100Font*);

    public:
        T100VOID                    setFontName(T100STRING);
        T100STRING                  getFontName();

        T100VOID                    setFontWidth(T100WORD);
        T100WORD                    getFontWidth();

        T100VOID                    setFontHeight(T100WORD);
        T100WORD                    getFontHeight();

        T100VOID                    setRowSize(T100WORD);
        T100WORD                    getRowSize();

    protected:
        T100STRING                  m_font_name;
        T100WORD                    m_font_width        = 0;
        T100WORD                    m_font_height       = 0;
        T100WORD                    m_row_size          = 0;

    private:
};

}

#endif // T100FONTFILE_H
