#ifndef T100FONTFILE1_H
#define T100FONTFILE1_H

#include "T100UnicodeCommon.h"
#include "T100File.h"


#define     T100FONTFILE_DEFAULT_SIZE           16


typedef struct{
    T100FILE_HEAD       FILE_SIGN;
    T100WORD            FONT_NAME[130];
    T100WORD            FONT_WIDTH;
    T100WORD            FONT_HEIGHT;
    T100WORD            ROW_SIZE;
}T100FONTFILE_HEAD;

typedef struct{
    T100UNICODE32       UNICODE32;
    T100WORD            BEGIN;
    T100WORD            END;
    T100WORD            SEEK;
    T100WORD            LENGTH;
}T100FONTFILE_ROW;

#define     T100FONTFILE_VECTOR             std::vector<T100FONTFILE*>
#define     T100FONTFILE_HASH               std::unordered_map<T100FILE_HANDLE, T100FontFile*>
#define     T100FONTFILE_ROW_VECTOR         std::vector<T100FONTFILE_ROW*>


class T100FontFile : protected T100File
{
    public:
        T100FontFile(T100String);
        virtual ~T100FontFile();

        T100BOOL            load();
        T100BOOL            save();

        T100BOOL            exists();

        T100BOOL            create();
        T100BOOL            remove();

        T100BOOL            open(T100FILE_MODE);
        T100BOOL            close();
        T100BOOL            opened();

        T100BOOL            seek(T100DWORD);
        T100DWORD           length();

        T100BOOL            read_head();
        T100BOOL            write_head();

        T100BOOL            read_row(T100FONTFILE_ROW*);
        T100BOOL            write_row(T100FONTFILE_ROW*);

        T100BOOL            read_item(T100WORD*, T100WORD);
        T100BOOL            write_item(T100WORD*, T100WORD);

        T100BOOL            allot(T100WORD*&, T100HWORD&);

        T100VOID            setFontName(T100String);
        T100String          getFontName();

        T100VOID            setFontWidth(T100WORD);
        T100WORD            getFontWidth();

        T100VOID            setFontHeight(T100WORD);
        T100WORD            getFontHeight();

        T100VOID            setRowSize(T100WORD);
        T100WORD            getRowSize();

    protected:
        T100String          m_font_name;
        T100WORD            m_font_width;
        T100WORD            m_font_height;
        T100WORD            m_row_size          = 0;

        T100WORD            m_seek_head         = 0;
        T100WORD            m_seek_row          = 0;
        T100WORD            m_seek_item         = 0;

        T100WORD            m_row_current       = 0;
        T100WORD            m_item_current      = 0;
        T100WORD            m_item_total        = 0;

        T100BOOL            divide(T100FONTFILE_ROW*);

    private:
};

#endif // T100FONTFILE1_H


