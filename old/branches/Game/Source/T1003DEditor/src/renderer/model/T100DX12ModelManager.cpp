#include "T100DX12ModelManager.h"

#include "T100DX12Tools.h"
#include "T100DX12Studio.h"

T100DX12ModelManager::T100DX12ModelManager(T100DX12Studio* studio) :
    T100DX12ModelManagerBase(),
    m_studio(studio),
    m_models()
{
    //ctor
}

T100DX12ModelManager::~T100DX12ModelManager()
{
    //dtor
}

T100VOID T100DX12ModelManager::Append(T100DX12Model* model)
{
    ModelManagerAppend(model);
}

T100VOID T100DX12ModelManager::Remove(T100DX12Model* model)
{
    ModelManagerRemove(model);
}

T100VOID T100DX12ModelManager::ModelManagerAppend(T100DX12Model* model)
{
    switch(model->Type){
    case T100DX12_MODEL_LIGHT:
        {

        }
        break;
    default:
        {
            Upload(m_studio, model);
            m_studio->m_frame_manager.Append(model);
        }
    };

}

T100VOID T100DX12ModelManager::ModelManagerRemove(T100DX12Model* model)
{
    m_studio->m_frame_manager.Remove(model);
}
