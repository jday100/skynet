#ifndef T100FONTTOOLS_H
#define T100FONTTOOLS_H

#include <atomic>
#include <wx/wx.h>
#include "T100Common.h"
#include "T100String.h"
#include "T100FontFile.h"
#include "T100FontFileWriter.h"
#include "T100Font.h"


class T100FontTools
{
    friend class T100FontPanel;
    public:
        T100FontTools();
        virtual ~T100FontTools();

        T100BOOL                    m_convert           = T100FALSE;

        static wxArrayString        getAllFontNames();
        static wxArrayString        getAllFontSizes();

        T100BOOL                    append(T100WORD, T100WORD);
        T100BOOL                    remove(T100HWORD);

        T100BOOL                    createFile(T100STRING);
        T100BOOL                    writeHead();
        T100BOOL                    writeRows();
        T100BOOL                    writeItem();
        T100BOOL                    closeFile();

        T100BOOL                    draw(wxPaintDC&);
        T100BOOL                    capture(wxPaintDC&);
        T100VOID                    setBit(T100BYTE);

    protected:
        T100VOID                    create();
        T100VOID                    destroy();

        T100STDSTRING               m_fontname      = "";
        wxString                    m_current;

        T100WORD                    m_index         = 0;
        T100WORD                    m_offset        = 0;

        T100WORD                    m_row_size      = 0;
        T100INT                     m_row_current   = -1;

        T100BOOL                    row_next();

    private:
        T100HWORD                   m_length        = 0;
        T100BYTE                    m_width         = 16;
        T100BYTE                    m_height        = 16;

        T100WORD                    m_begin         = 0;
        T100WORD                    m_end           = 0;

        T100FontFile*               m_file          = T100NULL;
        T100FontFileWriter*         m_writer        = T100NULL;

        std::atomic_bool            m_opened;
        T100WORD*                   m_data          = T100NULL;
        T100WORD                    m_value         = 1;
        T100WORD                    m_amount        = 0;

        T100Font                    m_font;
        T100FONTFILE_ROW_VECTOR     m_rows;

};

#endif // T100FONTTOOLS_H
