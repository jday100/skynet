#ifndef T100SCENEGRIDPARAMETERSAMOUNTDATA_H
#define T100SCENEGRIDPARAMETERSAMOUNTDATA_H

#include "common/T100DX12Common.h"
#include "T100GridClientData.h"
#include "T1003DEditorSceneGridData.h"

class T100Scene;

class T100SceneGridParametersAmountData : public T100GridClientData
{
    public:
        T100SceneGridParametersAmountData(wxPropertyGrid*, T100Scene*, T1003DEditorSceneGridData&);
        virtual ~T100SceneGridParametersAmountData();

        virtual T100VOID            Update(wxPGProperty*);

        T100VOID                    CreateParameters();

    protected:
        T100Scene*                  m_scenePtr          = T100NULL;
        T1003DEditorSceneGridData&  m_sceneData;

    private:
        T100VOID                    RemoveParameters();
        T100VOID                    CreateParameter(wxArrayString&, wxArrayInt&, wxPGProperty*, T100UINT);
};

#endif // T100SCENEGRIDPARAMETERSAMOUNTDATA_H
