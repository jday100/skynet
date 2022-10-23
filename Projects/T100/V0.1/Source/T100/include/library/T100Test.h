#ifndef T100TEST_H
#define T100TEST_H

#include "T100Class.h"

namespace T100Library{

class T100Test : public T100Class
{
    public:
        T100Test();
        virtual ~T100Test();

        virtual T100BOOL            test_all();

        virtual T100VOID            list();

        virtual T100BOOL            find();

    protected:

    private:
};

}

#endif // T100TEST_H
