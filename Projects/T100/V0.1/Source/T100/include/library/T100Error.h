#ifndef T100ERROR_H
#define T100ERROR_H

#include "T100Class.h"
#include "T100Common.h"

#define     T100ERROR_TYPE                      T100WORD
#define     T100ERROR_NONE                      0

namespace T100Library{

class T100Error : public T100Class
{
    public:
        T100Error();
        virtual ~T100Error();

        static T100BOOL         err;

    protected:

    private:
};

}

#endif // T100ERROR_H
