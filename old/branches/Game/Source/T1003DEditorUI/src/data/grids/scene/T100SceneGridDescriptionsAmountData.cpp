#include "T100SceneGridDescriptionsAmountData.h"

#include "data/T100Scene.h"
#include "T100SceneGridDescriptionReferenceData.h"
#include "T100SceneGridDescriptionNameData.h"
#include "T100SceneGridDescriptionIndexData.h"
#include "T100SceneGridDescriptionFormatData.h"
#include "T100SceneGridDescriptionSlotData.h"
#include "T100SceneGridDescriptionInputClassData.h"
#include "T100SceneGridDescriptionRateData.h"

#include "T1003DEditorCallback.h"

T100SceneGridDescriptionsAmountData::T100SceneGridDescriptionsAmountData(wxPropertyGrid* grid, T100Scene* scene, T1003DEditorSceneGridData& data) :
    T100GridClientData(grid),
    m_scenePtr(scene),
    m_sceneData(data)
{
    //ctor
}

T100SceneGridDescriptionsAmountData::~T100SceneGridDescriptionsAmountData()
{
    //dtor
}

T100VOID T100SceneGridDescriptionsAmountData::Update(wxPGProperty* property)
{
    T100UINT    value   = property->GetValue().GetInteger();

    m_scenePtr->VertexDescriptions.Amount   = value;

    RemoveDescriptions();

    if(value){
        m_scenePtr->VertexDescriptions.Descs    = T100NEW T100D3D12_INPUT_ELEMENT_DESC[value];
    }

    CreateDescriptions();
}

T100VOID T100SceneGridDescriptionsAmountData::CreateDescriptions()
{
    T100UINT    value   = m_scenePtr->VertexDescriptions.Amount;

    m_sceneData.m_descriptionProperties.resize(value);

    wxArrayString       enumLabels;
    wxArrayInt          enumValues;

    T1003DEditorCallback::GetDescriptions(enumLabels, enumValues);

    for(T100UINT i = 0; i < value; i++){
        CreateDescription(enumLabels, enumValues, m_sceneData.m_descriptions, i);
    }
}

T100VOID T100SceneGridDescriptionsAmountData::RemoveDescriptions()
{
    if(m_scenePtr->VertexDescriptions.Amount){
        T100SAFE_DELETES m_scenePtr->VertexDescriptions.Descs;
        m_scenePtr->VertexDescriptions.Descs        = T100NULL;
    }

    for(T1003DEDITOR_GRID_DATA_DESCRIPTION& description : m_sceneData.m_descriptionProperties){
        m_gridPtr->DeleteProperty(description.Name);
        m_gridPtr->DeleteProperty(description.Index);
        m_gridPtr->DeleteProperty(description.Format);
        m_gridPtr->DeleteProperty(description.Slot);
        m_gridPtr->DeleteProperty(description.InputClass);
        m_gridPtr->DeleteProperty(description.Rate);
        m_gridPtr->DeleteProperty(description.Category);
    }
}

T100VOID T100SceneGridDescriptionsAmountData::CreateDescription(wxArrayString& labels, wxArrayInt& values, wxPGProperty* parent, T100UINT index)
{
    T1003DEDITOR_GRID_DATA_DESCRIPTION&     description     = m_sceneData.m_descriptionProperties[index];
    T100D3D12_INPUT_ELEMENT_DESC&           desc            = m_scenePtr->VertexDescriptions.Descs[index];

    wxString    label           = wxString::Format(L"Description%u", index + 1);
    description.Category        = T100NEW wxStringProperty(label);
    description.Reference       = T100NEW wxEnumProperty(wxT("Reference"), wxT("Reference"), labels, values);
    description.Name            = T100NEW wxStringProperty(wxT("Name"), wxT("name"), desc.SemanticName);
    description.Index           = T100NEW wxUIntProperty(wxT("Index"), wxT("Index"), desc.SemanticIndex);
    description.Format          = T100NEW wxEnumProperty(wxT("Format"), wxT("Format"), enumFormatLabels, enumFormatValues, desc.Format);
    description.Slot            = T100NEW wxUIntProperty(wxT("Slot"), wxT("Slot"), desc.InputSlot);
    description.Offset          = T100NEW wxUIntProperty(wxT("Offset"), wxT("Offset"), desc.AlignedByteOffset);
    description.InputClass      = T100NEW wxEnumProperty(wxT("InputClass"), wxT("InputClass"), enumClassificationLabels, enumClassificationValues, desc.InputSlotClass);
    description.Rate            = T100NEW wxUIntProperty(wxT("Rate"), wxT("Rate"), desc.InstanceDataStepRate);

    description.Category->ChangeFlag(wxPG_PROP_READONLY, T100TRUE);
    description.Category->AppendChild(description.Reference);
    description.Category->AppendChild(description.Name);
    description.Category->AppendChild(description.Index);
    description.Category->AppendChild(description.Format);
    description.Category->AppendChild(description.Slot);
    description.Category->AppendChild(description.Offset);
    description.Category->AppendChild(description.InputClass);
    description.Category->AppendChild(description.Rate);

    T100SceneGridDescriptionReferenceData*      referenceData       = T100NEW T100SceneGridDescriptionReferenceData(m_gridPtr, m_scenePtr, m_sceneData, index);
    referenceData->m_descData       = &description;
    referenceData->m_desc           = &desc;
    referenceData->m_descs          = &T1003DEditorCallback::GetDescriptions();
    description.Reference->SetClientObject(referenceData);
    T100SceneGridDescriptionNameData*           nameData            = T100NEW T100SceneGridDescriptionNameData(m_gridPtr, m_scenePtr, m_sceneData, index);
    description.Name->SetClientObject(nameData);
    T100SceneGridDescriptionIndexData*          indexData           = T100NEW T100SceneGridDescriptionIndexData(m_gridPtr, m_scenePtr, m_sceneData, index);
    description.Index->SetClientObject(indexData);
    T100SceneGridDescriptionFormatData*         formatData          = T100NEW T100SceneGridDescriptionFormatData(m_gridPtr, m_scenePtr, m_sceneData, index);
    description.Format->SetClientObject(formatData);
    T100SceneGridDescriptionSlotData*           slotData            = T100NEW T100SceneGridDescriptionSlotData(m_gridPtr, m_scenePtr, m_sceneData, index);
    description.Slot->SetClientObject(slotData);
    T100SceneGridDescriptionInputClassData*     inputClassData      = T100NEW T100SceneGridDescriptionInputClassData(m_gridPtr, m_scenePtr, m_sceneData, index);
    description.InputClass->SetClientObject(inputClassData);
    T100SceneGridDescriptionRateData*           rateData            = T100NEW T100SceneGridDescriptionRateData(m_gridPtr, m_scenePtr, m_sceneData, index);
    description.Rate->SetClientObject(rateData);

    parent->AppendChild(description.Category);
}
