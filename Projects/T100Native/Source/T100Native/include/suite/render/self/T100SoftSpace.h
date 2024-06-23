#ifndef T100SOFTSPACE_H
#define T100SOFTSPACE_H

#include "T100Matrix4.h"
#include "T100SpaceBase.h"

class T100SoftSpace : public T100SpaceBase
{
    public:
        T100SoftSpace();
        virtual ~T100SoftSpace();

        T100VOID            SetSpaceMatrix(T100Matrix4&);
        T100Matrix4&        GetSpaceMatrix();

        T100Point           Translate(T100Point&, T100FLOAT, T100FLOAT, T100FLOAT);
        T100Point           RevolveX(T100Point&, T100FLOAT);
        T100Point           RevolveY(T100Point&, T100FLOAT);
        T100Point           RevolveZ(T100Point&, T100FLOAT);

    protected:
        T100Matrix4         m_space;

    private:
};

#endif // T100SOFTSPACE_H
