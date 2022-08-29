#ifndef T100SCANNER_H
#define T100SCANNER_H

#include <atomic>
#include "T100Common.h"
#include "T100Token.h"


class T100Scanner
{
    public:
        T100Scanner();
        virtual ~T100Scanner();

        virtual T100BOOL        next(T100Token&) = 0;

    protected:
        std::atomic_bool        m_loaded;

        T100VOID                create();
        T100VOID                destroy();

        virtual T100VOID        clear();
        virtual T100BOOL        read();
        virtual T100BOOL        append();

        virtual T100VOID        setLoaded(T100BOOL);
        virtual T100BOOL        isLoaded();

        virtual T100BOOL        run() = 0;

    private:
};

#endif // T100SCANNER_H
