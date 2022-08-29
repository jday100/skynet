#include "T100FontTools.h"

#include <wx/fontenum.h>
#include "T100Log.h"
#include "T100Unicode.h"


T100STDSTRING   T100FontTools::T100FONTCODE[3][4] = {
    {
        "中国",     "chinese",    "00000000",     "000000FF"
    },
    {
        "美国",     "ascii",      "00000000",     "000000FF"
    },
    {
        "",     ""
    }
};


T100FontTools::T100FontTools()
{
    //ctor
}

T100FontTools::~T100FontTools()
{
    //dtor
}

wxArrayString T100FontTools::getAllFontNames()
{
    wxArrayString       result;
    wxFontEnumerator    fonts;
    wxFontEncoding      encoding        = wxFONTENCODING_DEFAULT;

    result = fonts.GetFacenames(encoding);

    return result;
}

wxArrayString T100FontTools::getAllFontSizes()
{
    wxArrayString result;

    //result.Add(wxString("一号"));

    result.Add(wxString("16"));
    result.Add(wxString("24"));
    result.Add(wxString("32"));

    return result;
}

T100BOOL T100FontTools::verify()
{
    return T100TRUE;
}

T100BOOL T100FontTools::append(T100WORD begin, T100WORD end)
{
    T100FONTFILE_ROW* row = T100NEW T100FONTFILE_ROW;

    row->BEGIN  = begin;
    row->END    = end;
    row->LENGTH = row->END - row->BEGIN + 1;

    m_rows.push_back(row);

    return T100TRUE;
}

T100BOOL T100FontTools::remove(T100HWORD index)
{
    if(index < m_rows.size()){
        T100FONTFILE_ROW*   row;

        row = m_rows.at(index);
        if(row)T100DELETE(row);
        m_rows.erase(std::begin(m_rows) + index);
        return T100TRUE;
    }

    return T100FALSE;
}

T100BOOL T100FontTools::row_next()
{
    if(0 >= m_rows.size())return T100FALSE;

    m_row_current++;
    if(0 <= m_row_current && m_rows.size() > m_row_current){
        T100FONTFILE_ROW*   row;

        row = m_rows.at(m_row_current);
        if(row){
            m_begin     = row->BEGIN;
            m_end       = row->END;
            m_value     = row->BEGIN;

            return T100TRUE;
        }
    }

    return T100FALSE;
}

T100BOOL T100FontTools::draw(wxPaintDC& dc)
{
    if(m_value > m_end){
        if(!row_next())return T100FALSE;
    }

    wxUniChar uc(m_value);
    m_current = uc;

    dc.DrawText(m_current, 0, 0);

    m_value++;

    return T100TRUE;
}

T100BOOL T100FontTools::capture(wxPaintDC& dc)
{
    wxColor     colour;
    wxColor     background;

    background = dc.GetTextBackground();

    for(int m=0;m<m_height;m++){
        for(int n=0;n<m_width;n++){
            dc.GetPixel(n, m, &colour);

            //T100Log::info(colour.GetAsString().ToStdString());

            if(background == colour){
                setBit(0);
            }else{
                setBit(1);
            }
        }
    }

    return T100TRUE;
}

T100VOID T100FontTools::setBit(T100BYTE value)
{
    T100WORD    mask;
    T100BOOL    result;

    mask    = value & 1;

    if(1 == mask){
        result = T100TRUE;
    }else{
        result = T100FALSE;
    }

    T100WORD_BITS   word;
    T100BYTE        index;
    T100BYTE        offset;

    index   = m_index % m_length;
    offset  = m_offset % 32;

    word.WORD = m_data[index];

    switch(offset)
    {
    case 0:
        {
            word.BYTE0.BIT0 = result;
        }
        break;
    case 1:
        {
            word.BYTE0.BIT1 = result;
        }
        break;
    case 2:
        {
            word.BYTE0.BIT2 = result;
        }
        break;
    case 3:
        {
            word.BYTE0.BIT3 = result;
        }
        break;
    case 4:
        {
            word.BYTE0.BIT4 = result;
        }
        break;
    case 5:
        {
            word.BYTE0.BIT5 = result;
        }
        break;
    case 6:
        {
            word.BYTE0.BIT6 = result;
        }
        break;
    case 7:
        {
            word.BYTE0.BIT7 = result;
        }
        break;
    case 8:
        {
            word.BYTE1.BIT0 = result;
        }
        break;
    case 9:
        {
            word.BYTE1.BIT1 = result;
        }
        break;
    case 10:
        {
            word.BYTE1.BIT2 = result;
        }
        break;
    case 11:
        {
            word.BYTE1.BIT3 = result;
        }
        break;
    case 12:
        {
            word.BYTE1.BIT4 = result;
        }
        break;
    case 13:
        {
            word.BYTE1.BIT5 = result;
        }
        break;
    case 14:
        {
            word.BYTE1.BIT6 = result;
        }
        break;
    case 15:
        {
            word.BYTE1.BIT7 = result;
        }
        break;
    case 16:
        {
            word.BYTE2.BIT0 = result;
        }
        break;
    case 17:
        {
            word.BYTE2.BIT1 = result;
        }
        break;
    case 18:
        {
            word.BYTE2.BIT2 = result;
        }
        break;
    case 19:
        {
            word.BYTE2.BIT3 = result;
        }
        break;
    case 20:
        {
            word.BYTE2.BIT4 = result;
        }
        break;
    case 21:
        {
            word.BYTE2.BIT5 = result;
        }
        break;
    case 22:
        {
            word.BYTE2.BIT6 = result;
        }
        break;
    case 23:
        {
            word.BYTE2.BIT7 = result;
        }
        break;
    case 24:
        {
            word.BYTE3.BIT0 = result;
        }
        break;
    case 25:
        {
            word.BYTE3.BIT1 = result;
        }
        break;
    case 26:
        {
            word.BYTE3.BIT2 = result;
        }
        break;
    case 27:
        {
            word.BYTE3.BIT3 = result;
        }
        break;
    case 28:
        {
            word.BYTE3.BIT4 = result;
        }
        break;
    case 29:
        {
            word.BYTE3.BIT5 = result;
        }
        break;
    case 30:
        {
            word.BYTE3.BIT6 = result;
        }
        break;
    case 31:
        {
            word.BYTE3.BIT7 = result;
        }
        break;
    }

    m_data[index] = word.WORD;
    m_offset++;

    if(31 == offset){
        m_index++;
    }
}

T100BOOL T100FontTools::createFile(T100STDSTRING file)
{
    T100WORD    amount;
    T100WORD    length;

    if(m_opened)return T100FALSE;

    amount      = m_width * m_height + 31;
    length      = amount / 32;

    m_length    = length;

    m_data      = T100NEW T100WORD[length];
    //m_value     = m_begin;

    m_file      = T100NEW T100FontFile(file);

    if(!m_file->exists()){
        if(m_file->create()){

        }else{
            T100DELETE(m_data);
            T100DELETE(m_file);
            return T100FALSE;
        }
    }

    if(m_file->open(T100FILE_WRITE)){
        if(writeHead()){
            m_row_current   = -1;
            m_value         = 1;
            m_begin         = 0;
            m_end           = 0;

            if(writeRows()){
                m_opened        = T100TRUE;
                return T100TRUE;
            }
        }
    }

    T100DELETE(m_data);
    T100DELETE(m_file);
    return T100FALSE;
}

T100BOOL T100FontTools::writeHead()
{
    //test
    //m_file->setFontName(T100String(m_fontname));
    //m_file->setFontName(T100String(u8"仿宋"));

    if(m_convert){
        T100STDSTRING   name;

        name = T100Unicode::gbk_to_utf8(m_fontname);
        if(name.empty()){
            return T100FALSE;
        }
        m_file->setFontName(T100String(name));
    }else{
        m_file->setFontName(T100String(m_fontname));
    }

    m_file->setFontWidth(m_width);
    m_file->setFontHeight(m_height);
    m_file->setRowSize(m_row_size);

    return m_file->write_head();
}

T100BOOL T100FontTools::writeRows()
{
    if(0 >= m_rows.size())return T100FALSE;

    for(auto row : m_rows){
        if(row){
            if(m_file->write_row(row)){

            }else{
                return T100FALSE;
            }
        }else{
            return T100FALSE;
        }
    }
    return T100TRUE;
}

T100BOOL T100FontTools::writeItem()
{
    return m_file->write_item(m_data, m_length);
}

T100BOOL T100FontTools::closeFile()
{
    T100BOOL    result      = T100TRUE;

    if(m_opened){
        if(m_file->close()){
            result = T100FALSE;
        }
        T100DELETE(m_data);
        T100DELETE(m_file);
        m_opened    = T100FALSE;
        return result;
    }

    return T100FALSE;
}
