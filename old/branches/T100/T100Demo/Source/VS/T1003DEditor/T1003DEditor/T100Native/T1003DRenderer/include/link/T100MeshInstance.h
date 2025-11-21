#ifndef T100MESHINSTANCE_H
#define T100MESHINSTANCE_H

#include "T100Instance.h"

class T100MeshInstance : public T100Instance
{
    public:
        T100MeshInstance();
        virtual ~T100MeshInstance();

        virtual T100VOID        SetScaling(T100FLOAT, T100FLOAT, T100FLOAT) = 0;
        virtual T100VOID        SetScaling(T100Vector3f&) = 0;

        T100Vector3f&           GetScaling();

        virtual T100VOID        SetVisible(T100BOOL) = 0;
        T100BOOL                IsVisible();

        T100VOID                SetAmount(T100UINT);
        T100UINT                GetAmount();


    protected:
        T100Vector3f            m_scaling;
        T100BOOL                m_visible           = T100TRUE;
        T100UINT                m_amount            = 0;

    private:
};

#endif // T100MESHINSTANCE_H
