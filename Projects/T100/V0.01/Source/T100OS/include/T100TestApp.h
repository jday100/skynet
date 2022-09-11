#ifndef T100TESTAPP_H
#define T100TESTAPP_H

#include "T100App.h"


class T100TestApp : public T100App
{
    public:
        T100TestApp();
        virtual ~T100TestApp();

        T100VOID            run(int argc, wchar_t** argv);

    protected:

    private:
};

#endif // T100TESTAPP_H
