#include "T100SceneGridDescriptionReferenceData.h"

#include "data/T100Scene.h"

T100SceneGridDescriptionReferenceData::T100SceneGridDescriptionReferenceData(wxPropertyGrid* grid, T100Scene* scene, T1003DEditorSceneGridData& data, T100UINT index) :
    T100GridClientData(grid),
    m_scenePtr(scene),
    m_sceneData(data),
    m_index(index)
{
    //ctor
}

T100SceneGridDescriptionReferenceData::~T100SceneGridDescriptionReferenceData()
{
    //dtor
}

T100VOID T100SceneGridDescriptionReferenceData::Update(wxPGProperty* property)
{
    T100UINT    value   = property->GetValue().GetInteger();

    if(value != -1){
        T100D3D12_INPUT_ELEMENT_DESC*       desc        = (*m_descs)[value];

        m_desc->SemanticName                = desc->SemanticName;
        m_desc->SemanticIndex               = desc->SemanticIndex;
        m_desc->Format                      = desc->Format;
        m_desc->InputSlot                   = desc->InputSlot;
        m_desc->AlignedByteOffset           = desc->AlignedByteOffset;
        m_desc->InputSlotClass              = desc->InputSlotClass;
        m_desc->InstanceDataStepRate        = desc->InstanceDataStepRate;

        m_descData->Name->SetValue(desc->SemanticName);
        m_descData->Index->SetValueFromInt(desc->SemanticIndex);
        m_descData->Format->SetValueFromInt(desc->Format);
        m_descData->Slot->SetValueFromInt(desc->InputSlot);
        m_descData->Offset->SetValueFromInt(desc->AlignedByteOffset);
        m_descData->InputClass->SetValueFromInt(desc->InputSlotClass);
        m_descData->Rate->SetValueFromInt(desc->InstanceDataStepRate);

    }
}
