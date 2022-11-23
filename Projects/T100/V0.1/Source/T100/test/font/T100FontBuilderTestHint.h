#ifndef T100FONTBUILDERTESTHINT_H
#define T100FONTBUILDERTESTHINT_H

#include "T100Hint.h"

namespace T100Font{

static T100WSTRING          T100TEST_HINT_FONT_BUILDER_BASIC_TEST_START                         = L"Font builder basic test is starting ... ";
static T100WSTRING          T100TEST_HINT_FONT_BUILDER_BASIC_TEST_STOP                          = L"Font builder basic test is stopped . ";



class T100FontBuilderTestHint : public T100Library::T100Hint
{
    public:
        T100FontBuilderTestHint();
        virtual ~T100FontBuilderTestHint();

    protected:

    private:
};

}

#endif // T100FONTBUILDERTESTHINT_H
