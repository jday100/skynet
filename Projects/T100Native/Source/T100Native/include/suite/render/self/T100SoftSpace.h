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

        T100Point           Scale(T100Point&);
        T100Point           Translate(T100Point&, T100FLOAT, T100FLOAT, T100FLOAT);
        T100Point           RevolveX(T100Point&, T100FLOAT);
        T100Point           RevolveY(T100Point&, T100FLOAT);
        T100Point           RevolveZ(T100Point&, T100FLOAT);

    public:
        T100Point           Space(T100Point&);

        T100VOID            Translate(T100FLOAT, T100FLOAT, T100FLOAT);

    protected:
        T100Matrix4         m_space;

        T100Matrix4         m_scale;
        T100Matrix4         m_translate;
        T100Matrix4         m_revolve;
        T100Matrix4         m_revolve_x;
        T100Matrix4         m_revolve_y;
        T100Matrix4         m_revolve_z;

    private:
        T100VOID            TurnOn();
        T100VOID            TurnOff();
};

#endif // T100SOFTSPACE_H
