#ifndef T100FONTTOOLS_H
#define T100FONTTOOLS_H

#include <wx/wx.h>
#include <wx/panel.h>
#include "T100FontFile.h"


class T100FontTools
{
    friend class T100FontPanel;
    public:
        T100FontTools();
        virtual ~T100FontTools();

        T100BOOL                    verify();
        T100BOOL                    m_convert           = T100FALSE;

        T100BOOL                    append(T100WORD, T100WORD);
        T100BOOL                    remove(T100HWORD);

        static wxArrayString        getAllFontNames();
        static wxArrayString        getAllFontSizes();

        T100BOOL                    draw(wxPaintDC&);
        T100BOOL                    capture(wxPaintDC&);
        T100VOID                    setBit(T100BYTE);


        T100BOOL                    createFile(T100STDSTRING);
        T100BOOL                    writeHead();
        T100BOOL                    writeRows();
        T100BOOL                    writeItem();
        T100BOOL                    closeFile();

        static T100STDSTRING        T100FONTCODE[3][4];

    protected:
        T100WORD                    m_index         = 0;
        T100WORD                    m_offset        = 0;
        T100STDSTRING               m_fontname      = "";
        T100WORD                    m_row_size      = 0;
        T100INTEGER                 m_row_current   = -1;

        T100BOOL                    row_next();

    private:
        T100BOOL                    m_opened        = T100FALSE;
        T100WORD*                   m_data          = T100NULL;
        T100WORD                    m_value         = 1;
        wxString                    m_current;
        T100WORD                    m_amount        = 0;

        T100FontFile*               m_file          = T100NULL;

        T100HWORD                   m_length        = 0;
        T100BYTE                    m_width         = 16;
        T100BYTE                    m_height        = 16;

        T100WORD                    m_begin         = 0;
        T100WORD                    m_end           = 0;


        T100FONTFILE_ROW_VECTOR     m_rows;

};

#endif // T100FONTTOOLS_H
