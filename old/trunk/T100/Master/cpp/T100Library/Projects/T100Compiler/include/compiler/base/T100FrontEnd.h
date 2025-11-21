#ifndef T100FRONTEND_H
#define T100FRONTEND_H

#include "compiler/data/T100FrontInfo.h"
#include "compiler/base/T100Parser.h"

namespace T100LIBRARY{

class T100FrontEnd : public T100Class
{
    public:
        T100FrontEnd();
        virtual ~T100FrontEnd();

        virtual T100VOID            SetParser(T100Parser*);
        virtual T100Parser*         GetParser();

        virtual T100BOOL            Parse(const T100WSTRING&, T100FrontInfo&);

    protected:
        T100Parser*                 m_parser        = T100NULL;

    private:
        T100VOID                    init();
        T100VOID                    uninit();
};

}

#endif // T100FRONTEND_H
