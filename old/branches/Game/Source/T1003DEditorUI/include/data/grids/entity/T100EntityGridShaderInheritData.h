#ifndef T100ENTITYGRIDSHADERINHERITDATA_H
#define T100ENTITYGRIDSHADERINHERITDATA_H

#include "common/T100DX12Common.h"
#include "T100GridClientData.h"
#include "T1003DEditorEntityGridData.h"

class T100Entity;

class T100EntityGridShaderInheritData : public T100GridClientData
{
    public:
        T100EntityGridShaderInheritData(wxPropertyGrid*, T100Entity*, T1003DEditorEntityGridData&);
        virtual ~T100EntityGridShaderInheritData();

        virtual T100VOID                Update(wxPGProperty*);

        T100VOID                        CreateShader();

    protected:
        T100UINT                        m_index             = 0;
        T100Entity*                     m_entityPtr         = T100NULL;
        T1003DEditorEntityGridData&     m_entityData;

    private:
        T100VOID                        RemoveShader();
        T100VOID                        BuildShader();

        T100VOID                        CreateDescriptions();
        T100VOID                        CreateDescription(wxPGProperty*, T100UINT);


        T100VOID                        CreateParameters();
        T100VOID                        CreateSettings();
        T100VOID                        CreateVertexShader();
        T100VOID                        CreatePixelShader();
};

#endif // T100ENTITYGRIDSHADERINHERITDATA_H
