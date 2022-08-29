#ifndef T100HELPAPP_H
#define T100HELPAPP_H

#include "T100Help.h"


class T100HelpApp : public T100Help
{
    public:
        T100HelpApp();
        virtual ~T100HelpApp();

        T100BOOL            show();

    protected:

    private:
};

#endif // T100HELPAPP_H
