#ifndef T100FONTFILEREADER_H
#define T100FONTFILEREADER_H

#include "T100FontCommon.h"
#include "T100FileReader.h"
class T100FontFile;
class T100Font;


class T100FontFileReader : public T100FileReader
{
    public:
        T100FontFileReader(T100FontFile*, T100Font*);
        virtual ~T100FontFileReader();

        T100BOOL                load();


        T100BOOL                read_head();

        T100BOOL                read_row(T100FONTFILE_ROW*);

        T100BOOL                read_item(T100WORD*, T100WORD);

    protected:

    private:
        T100FontFile*           m_file              = T100NULL;
        T100Font*               m_font              = T100NULL;

        T100DWORD               m_length            = 0;

        T100WORD                m_row_size          = 0;

        T100WORD                m_row_current       = 0;
        T100WORD                m_item_current      = 0;

};

#endif // T100FONTFILEREADER_H
