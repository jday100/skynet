#ifndef T1003DEDITORSCENEGRID_H
#define T1003DEDITORSCENEGRID_H

#include "T1003DEditorGridBase.h"
#include <wx/propgrid/advprops.h>
#include "data/T100Scene.h"

#include "T1003DEditorSceneGridData.h"

class T1003DEditorSceneGrid : public T1003DEditorGridBase
{
    public:
        T1003DEditorSceneGrid(wxPropertyGrid*);
        virtual ~T1003DEditorSceneGrid();

        virtual T100VOID        Update(T100Scene*);
        virtual T100VOID        OnPGChanged(wxPropertyGridEvent& event);

    protected:
        T100Scene*              m_scenePtr      = T100NULL;

        T100VOID                CreateType();

    private:
        T1003DEditorSceneGridData           m_sceneData;

        T100VOID                CreateShader();
        T100VOID                CreateDescriptions();
        T100VOID                CreateParameters();
        T100VOID                CreateSettings();
        T100VOID                CreateVertexShader();
        T100VOID                CreatePixelShader();
};

#endif // T1003DEDITORSCENEGRID_H
