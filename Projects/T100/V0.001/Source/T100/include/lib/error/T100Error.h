#ifndef T100ERROR_H
#define T100ERROR_H

#include "T100ErrorCommon.h"
#include "T100Log.h"


class T100Error
{
    public:
        T100Error();
        virtual ~T100Error();

        static T100BOOL             err;

        static T100BOOL             fatal(T100STDSTRING);
        static T100BOOL             error(T100STDSTRING);
        static T100BOOL             warn(T100STDSTRING);

    protected:
        static T100WORD             m_fatal_count;
        static T100WORD             m_error_count;
        static T100WORD             m_warn_count;

    private:
};

#endif // T100ERROR_H
