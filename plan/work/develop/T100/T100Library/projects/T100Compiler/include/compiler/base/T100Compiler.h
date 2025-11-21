#ifndef T100COMPILER_H
#define T100COMPILER_H

#include "compiler/base/T100FrontEnd.h"
#include "compiler/base/T100MiddleEnd.h"
#include "compiler/base/T100BackEnd.h"

namespace T100LIBRARY{

class T100Compiler : public T100Class
{
    public:
        T100Compiler();
        virtual ~T100Compiler();

        virtual T100VOID            SetFrontEnd(T100FrontEnd*);
        virtual T100FrontEnd*       GetFrontEnd();

        virtual T100VOID            SetMiddleEnd(T100MiddleEnd*);
        virtual T100MiddleEnd*      GetMiddleEnd();

        virtual T100VOID            SetBackEnd(T100BackEnd*);
        virtual T100BackEnd*        GetBackEnd();

        virtual T100INT             Run(const T100WSTRING&);

    protected:
        T100FrontEnd*               m_frontEnd          = T100NULL;
        T100MiddleEnd*              m_middleEnd         = T100NULL;
        T100BackEnd*                m_backEnd           = T100NULL;

    private:
};

}

#endif // T100COMPILER_H
