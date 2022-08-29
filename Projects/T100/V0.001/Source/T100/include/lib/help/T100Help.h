#ifndef T100HELP_H
#define T100HELP_H

#include "T100Log.h"


class T100Help
{
    public:
        T100Help();
        virtual ~T100Help();

        virtual T100BOOL    show()=0;

    protected:

    private:
};

#endif // T100HELP_H
