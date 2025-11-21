#ifndef T100MATERIAL_H
#define T100MATERIAL_H

#include <vector>
#include "T100Common.h"
#include "game/file/T100JSON.h"
#include "math/T100Vector4.h"

class T100DX12Materail;

#define     T100MATERIAL_VECTOR         std::vector<T100Material*>

class T100Material
{
    public:
        T100Material();
        virtual ~T100Material();

        T100WSTRING                 Name;

        virtual T100VOID            ToJSON(JSON&);
        virtual T100VOID            FromJSON(JSON&);


        T100VOID                    SetDiffuse(T100FLOAT, T100FLOAT, T100FLOAT, T100FLOAT);
        T100VOID                    SetDiffuse(T100Vector4&);
        T100Vector4&                GetDiffuse();

        T100VOID                    SetSpecular(T100FLOAT, T100FLOAT, T100FLOAT, T100FLOAT);
        T100VOID                    SetSpecular(T100Vector4&);
        T100Vector4&                GetSpecular();

        T100VOID                    SetAmbient(T100FLOAT, T100FLOAT, T100FLOAT, T100FLOAT);
        T100VOID                    SetAmbient(T100Vector4&);
        T100Vector4&                GetAmbient();

        T100VOID                    SetEmissive(T100FLOAT, T100FLOAT, T100FLOAT, T100FLOAT);
        T100VOID                    SetEmissive(T100Vector4&);
        T100Vector4&                GetEmissive();

        T100VOID                    SetTransparent(T100FLOAT, T100FLOAT, T100FLOAT, T100FLOAT);
        T100VOID                    SetTransparent(T100Vector4&);
        T100Vector4&                GetTransparent();

    protected:
        T100Vector4                 m_diffuse;
        T100Vector4                 m_specular;
        T100Vector4                 m_ambient;
        T100Vector4                 m_emissive;
        T100Vector4                 m_transparent;

    private:
};

#endif // T100MATERIAL_H
