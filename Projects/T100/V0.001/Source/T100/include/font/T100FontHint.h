#ifndef T100FONTHINT_H
#define T100FONTHINT_H

#include "T100Hint.h"

static std::string      T100FONTBUILDER_HINT_APP_START                      =   "The FontBuilder is starting...";
static std::string      T100FONTBUILDER_HINT_APP_STOP                       =   "The FontBuilder is stoped.";

static std::string      T100FONTBUILDER_HINT_PARAMETERS_ERROR               =   "Parameters error!";
static std::string      T100FONTBUILDER_HINT_CODE_BEGIN_NOT_SELECTED        =   "Font code begin is not selected!";
static std::string      T100FONTBUILDER_HINT_CODE_END_NOT_SELECTED          =   "Font code end is not selected!";
static std::string      T100FONTBUILDER_HINT_CODE_LIST_NOT_SELECTED         =   "Font code list is not selected!";


class T100FontHint : public T100Hint
{
    public:
        T100FontHint();
        virtual ~T100FontHint();

    protected:

    private:
};

#endif // T100FONTHINT_H
