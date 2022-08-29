#include "T100FontTest.h"

#include "T100AppSetup.h"
#include "T100TestTools.h"
#include "T100Font.h"
#include "T100FontFile.h"
#include "T100FontFileReader.h"
#include "T100FontFileWriter.h"


T100WSTRING         T100FontTest::m_name                        = L"common.font";


T100FontTest::T100FontTest(T100Test* parent)
    :T100Test(parent, m_name)
{
    //ctor
}

T100FontTest::~T100FontTest()
{
    //dtor
}

T100BOOL T100FontTest::do_test()
{
    T100BOOL            result          = T100TRUE;
    T100BOOL            value;

    value = test_font();
    if(!value){
        result = T100FALSE;
    }

    return result;
}

T100BOOL T100FontTest::test_font()
{
    T100BOOL                result          = T100TRUE;
    T100BOOL                value;

    T100WORD                source_code;
    T100WORD_VECTOR         source_data;
    T100Font                source_font;

    T100WORD                target_code;
    T100WORD_VECTOR*        target_data     = T100NULL;
    T100Font                target_font;

    T100WSTRING             name;

    name = T100AppSetup::getTestStores(L"test_font.fnt");

    T100FontFile            source_file(name);
    T100FontFile            target_file(name);


    T100FontFileReader*     reader          = T100NULL;
    T100FontFileWriter*     writer          = T100NULL;


    //
    source_code     = 1;
    source_data     = {0, 1, 2, 3, 4, 5, 6, 7};

    T100FONT_VECTOR         fonts;
    T100FONTFILE_ROW        row;
    T100FONT_ROW            item;
    T100FONT_ROW_VECTOR     rows;

    row.BEGIN       = 0;
    row.END         = 1;
    row.LENGTH      = 1;
    row.SEEK        = 0;

    item.ROW    = &row;
    item.FONTS  = &fonts;

    fonts.push_back(&source_data);


    value = source_font.setFont(source_code, &source_data);
    if(!value){
        result = T100FALSE;
    }

    if(result){
        source_font.setRowSize(1);

        value = source_font.appendRow(&row);
        if(!value){
            result = T100FALSE;
        }
    }

    if(result){
        source_font.getFonts()[0]->FONTS = &fonts;
    }

    if(result){
        writer = source_file.getWriter(&source_font);
        if(!writer){
            result = T100FALSE;
        }
    }

    if(result){
        value = T100TestTools::CleanAndCreate(source_file);
        if(!value){
            result = T100FALSE;
        }
    }

    if(result){
        value = writer->save();
        if(!value){
            result = T100FALSE;
        }
    }

    if(result){
        reader = target_file.getReader(&target_font);
        if(!reader){
            result = T100FALSE;
        }
    }

    if(result){
        value = reader->load();
        if(!value){
            result = T100FALSE;
        }
    }

    if(result){
        target_code = 1;
        value = target_font.getFont(target_code, target_data);
        if(!value){
            result = T100FALSE;
        }
    }

    if(result){
        if(target_data){
            for(int i=0;i<target_data->size();i++){
                if(i == (*target_data)[i]){

                }else{
                    result = T100FALSE;
                    break;
                }
            }
        }else{
            result = T100FALSE;
        }
    }

    return result;
}
