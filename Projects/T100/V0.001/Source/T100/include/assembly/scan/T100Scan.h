#ifndef T100SCAN_H
#define T100SCAN_H

#include "T100Common.h"
#include "IScan.h"
#include "T100Token.h"


class T100Scan : protected IScan
{
    public:
        T100Scan();
        virtual ~T100Scan();

        virtual T100BOOL        next(IToken&)=0;

        virtual T100BOOL        open(T100String&)=0;
        virtual T100BOOL        close()=0;

    protected:
        T100BOOL                m_loaded        = T100FALSE;

        virtual T100VOID        clear();
        virtual T100BOOL        read();
        virtual T100BOOL        append();
        virtual T100VOID        setLoaded(T100BOOL);
        virtual T100BOOL        isLoaded();

        virtual T100BOOL        run()=0;

    private:
};

#endif // T100SCAN_H
