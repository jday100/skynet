#ifndef T100SCANNER_H
#define T100SCANNER_H

#include <atomic>
#include "T100Token.h"


class T100Scanner
{
    public:
        T100Scanner();
        virtual ~T100Scanner();

        virtual T100BOOL            next(T100Token&) = 0;

        virtual T100BOOL            read();
        virtual T100BOOL            append();
        virtual T100VOID            clear();

    protected:
        virtual T100VOID            setLoaded(T100BOOL);
        virtual T100BOOL            isLoaded();

        T100ASM64_TOKEN_TYPE        m_type          = T100TOKEN_NONE;

    private:
        std::atomic_bool            m_loaded;
};

#endif // T100SCANNER_H
