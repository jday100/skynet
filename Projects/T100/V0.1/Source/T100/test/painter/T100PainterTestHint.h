#ifndef T100PAINTERTESTHINT_H
#define T100PAINTERTESTHINT_H

#include "T100Hint.h"

namespace T100Painter{

static T100WSTRING          T100TEST_HINT_PAINTER_TEST_START                                    = L"Painter test is starting ... ";
static T100WSTRING          T100TEST_HINT_PAINTER_TEST_STOP                                     = L"Painter test is stopped . ";


class T100PainterTestHint : public T100Library::T100Hint
{
    public:
        T100PainterTestHint();
        virtual ~T100PainterTestHint();

    protected:

    private:
};

}

#endif // T100PAINTERTESTHINT_H
