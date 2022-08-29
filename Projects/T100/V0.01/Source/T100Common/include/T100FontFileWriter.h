#ifndef T100FONTFILEWRITER_H
#define T100FONTFILEWRITER_H

#include "T100FontCommon.h"
#include "T100FileWriter.h"
class T100FontFile;
class T100Font;


class T100FontFileWriter : public T100FileWriter
{
    friend class T100FontTools;
    public:
        T100FontFileWriter(T100FontFile*, T100Font*);
        virtual ~T100FontFileWriter();

        T100BOOL                save();

    protected:
        T100BOOL                write_head();

        T100BOOL                write_row(T100FONTFILE_ROW*);

        T100BOOL                write_item(T100WORD*, T100WORD);

        T100BOOL                divide(T100FONTFILE_ROW*);


    private:
        T100FontFile*           m_file              = T100NULL;
        T100Font*               m_font              = T100NULL;

        T100WORD                m_row_size          = 0;

        T100WORD                m_row_current       = 0;
        T100WORD                m_item_current      = 0;
        T100WORD                m_item_total        = 0;

};

#endif // T100FONTFILEWRITER_H
