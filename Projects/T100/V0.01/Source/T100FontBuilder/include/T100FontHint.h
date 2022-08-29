#ifndef T100FONTHINT_H
#define T100FONTHINT_H

#include "T100Hint.h"

static T100WSTRING      T100FONTBUILDER_HINT_APP_START                      =   L"The FontBuilder is starting...";
static T100WSTRING      T100FONTBUILDER_HINT_APP_STOP                       =   L"The FontBuilder is stoped.";

static T100WSTRING      T100FONTBUILDER_HINT_PARAMETERS_ERROR               =   L"Parameters error!";
static T100WSTRING      T100FONTBUILDER_HINT_CODE_BEGIN_NOT_SELECTED        =   L"Font code begin is not selected!";
static T100WSTRING      T100FONTBUILDER_HINT_CODE_END_NOT_SELECTED          =   L"Font code end is not selected!";
static T100WSTRING      T100FONTBUILDER_HINT_CODE_LIST_NOT_SELECTED         =   L"Font code list is not selected!";


class T100FontHint : public T100Hint
{
    public:
        T100FontHint();
        virtual ~T100FontHint();

    protected:

    private:
};

#endif // T100FONTHINT_H
