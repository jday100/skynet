#ifndef T100BACKEND_H
#define T100BACKEND_H

#include "compiler/base/T100Builder.h"

namespace T100LIBRARY{

class T100BackEnd : public T100Class
{
    public:
        T100BackEnd();
        virtual ~T100BackEnd();

        virtual T100VOID            SetBuilder(T100Builder*);
        virtual T100Builder*        GetBuilder();

        virtual T100BOOL            Build(const T100BackInfo&);

    protected:

    private:
        T100Builder*                m_builder       = T100NULL;
};

}

#endif // T100BACKEND_H
