#include "T100FontTest.h"

#include "T100Font.h"
#include "T100FontFile.h"

T100STDSTRING       T100FontTest::m_unit        = "font";


T100FontTest::T100FontTest()
    :T100Test(m_unit)
{
    //ctor
}

T100FontTest::~T100FontTest()
{
    //dtor
}

T100BOOL T100FontTest::test_all()
{
    T100BOOL    result      = T100TRUE;

    if(!test_file()){
        result = T100FALSE;
    }

    if(!test_write()){
        result = T100FALSE;
    }

    return result;
}

T100BOOL T100FontTest::test_file()
{
    T100FontFile    source(T100String("test.fnt"));
    T100FontFile    target(T100String("test.fnt"));

    if(source.exists()){
        if(source.remove()){

        }else{
            return T100FALSE;
        }
    }

    source.setFontName(T100String(u8"字体"));

    if(!source.create()){
        return T100FALSE;
    }

    if(!source.exists()){
        return T100FALSE;
    }

    if(!target.open(T100FILE_READ)){
        return T100FALSE;
    }

    if(T100String(u8"字体") != target.getFontName()){
        return T100FALSE;
    }

    if(!target.close()){
        return T100FALSE;
    }

    return T100TRUE;
}

T100BOOL T100FontTest::test_font()
{
    T100BOOL            result      = T100TRUE;
    T100Font            font;
    T100FILE_HANDLE     handle;
    T100FontFile*       file        = T100NULL;

    /*
    handle = font.create(T100String(u8"test.fnt"));
    if(!handle){
        return T100FALSE;
    }

    T100::T100FONTFILE_ROW* row = new T100::T100FONTFILE_ROW;

    file = font.getFontFile(handle);
    if(!file->add(row)){
        return T100FALSE;
    }

    T100WORD*       data        = T100NULL;
    T100WORD        length;

    if(!file->allot(data, length)){
        return T100FALSE;
    }

    if(!data){
        return T100FALSE;
    }

    T100WORD    font_data[1] = {0};

    if(!file->write_row()){
        return T100FALSE;
    }

    if(!file->write_item()){
        return T100FALSE;
    }

    if(!font.close(handle)){
        return T100FALSE;
    }

    handle = T100NULL;
    handle = font.create(T100String(u8"test.fnt"));
    if(!handle){
        return T100FALSE;
    }

    file = font.getFontFile(handle);
    if(!file->add(row)){
        return T100FALSE;
    }

    if(!file->allot(data, length)){
        return T100FALSE;
    }

    if(!data){
        return T100FALSE;
    }

    if(!file->read_row()){
        return T100FALSE;
    }

    if(!file->read_item()){
        return T100FALSE;
    }

    if(!font.close(handle)){
        return T100FALSE;
    }
    */

    return result;
}

T100BOOL T100FontTest::test_read()
{
    T100BOOL    result      = T100FALSE;
    T100Font            font;
    T100FILE_HANDLE     handle;
    T100FontFile*       file        = T100NULL;

    /*
    handle = font.create(T100String(u8"test.fnt"));
    if(!handle){
        return T100FALSE;
    }

    T100::T100FONTFILE_ROW* row = new T100::T100FONTFILE_ROW;

    file = font.getFontFile(handle);
    if(!file->add(row)){
        return T100FALSE;
    }

    T100WORD*       data        = T100NULL;
    T100WORD        length;

    if(!file->allot(data, length)){
        return T100FALSE;
    }

    if(!data){
        return T100FALSE;
    }

    T100WORD    font_data[1] = {0};

    if(!file->write_row()){
        return T100FALSE;
    }

    if(!file->write_item()){
        return T100FALSE;
    }

    if(!font.close(handle)){
        return T100FALSE;
    }
    */

    return result;
}

T100BOOL T100FontTest::test_write()
{
    T100BOOL            result      = T100FALSE;
    T100Font            font;
    T100FILE_HANDLE     handle;
    T100FontFile*       file        = T100NULL;

    /*
    handle = font.create(T100String(u8"test.fnt"));
    if(!handle){
        return T100FALSE;
    }

    file = font.getFontFile(handle);
    if(!file){
        return T100FALSE;
    }

    file->setFontName(T100String(u8"ascii"));
    file->setFontWidth(16);
    file->setFontHeight(16);
    file->setRowSize(1);

    T100::T100FONTFILE_ROW* row = new T100::T100FONTFILE_ROW;

    row->UNICODE32.WORD = 0;
    row->BEGIN          = 0;
    row->END            = 255;
    row->LENGTH         = 256;
    row->SEEK           = 0;

    if(!file->add(row)){
        return T100FALSE;
    }

    T100WORD*       data        = T100NULL;
    T100WORD        length;

    if(!file->allot(data, length)){
        return T100FALSE;
    }

    if(!data){
        return T100FALSE;
    }

    T100WORD    font_data[8] = {0, 0, 0, 0, 0, 0, 0, 0};

    if(!file->write_row()){
        return T100FALSE;
    }

    if(!file->write_item()){
        return T100FALSE;
    }

    if(!font.close(handle)){
        return T100FALSE;
    }
    */

    return result;
}
