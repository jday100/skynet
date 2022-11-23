#include "T100FontBuilderTest.h"

#include "T100ThisAppSetup.h"
#include "T100FontBuilderTestHint.h"
#include "T100FontBuilder.h"
#include "T100FontView.h"
#include "T100FontFrame.h"
#include "T100FontPanel.h"


namespace T100Font{

T100WSTRING         T100FontBuilderTest::m_name                         = L"font";

T100FontBuilderTest::T100FontBuilderTest(T100Test* parent)
    :T100Test(parent, m_name)
{
    //ctor
}

T100FontBuilderTest::~T100FontBuilderTest()
{
    //dtor
}

T100BOOL T100FontBuilderTest::do_test()
{
    T100BOOL        result          = T100TRUE;
    T100BOOL        value;

    value = test_font();
    if(!value){
        result = T100FALSE;
    }
    return result;
}

T100BOOL T100FontBuilderTest::test_font()
{
    T100BOOL        result          = T100TRUE;
    T100BOOL        value;

    T100Library::T100Log::info(T100TEST_HINT_FONT_BUILDER_BASIC_TEST_START);

    T100STRING      file;
    T100INT         index;
    T100FontBuilder::T100FontBuilder        builder;
    T100FontBuilder::T100FontPanel*         panel;

    builder.show();

    panel   = builder.getView()->getFrame()->FontPanel;


    index   = panel->FontNameChoice->FindString(L"System");
    if(0 <= index){
        panel->FontNameChoice->SetSelection(index);
    }else{
        result = T100FALSE;
    }

    if(result){
        panel->NameCodeRadioButton1->SetValue(T100TRUE);
        panel->FontSizeComboBox->SetSelection(0);
        panel->CountryListBox->SetSelection(1);
        panel->CodeBeginComboBox->SetSelection(0);
        panel->CodeEndComboBox->SetSelection(0);
        panel->AppendButton->HitTest(0, 0);
        panel->FileComboBox->SetValue(file.to_wstring());
        panel->RunButton->HitTest(0, 0);
    }

    //builder.quit();

    show_result(result, T100TEST_HINT_FONT_BUILDER_BASIC_TEST_STOP);
    return result;
}

}
