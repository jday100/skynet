#include "T100DX12ContextManager.h"

#include "T100Debug.h"
#include "T100DX12Tools.h"
#include "T100DX12Studio.h"

#include "T100DX12AllContexts.h"

T100DX12ContextManager::T100DX12ContextManager(T100DX12Studio* studio) :
    T100DX12ContextManagerBase(),
    m_studio(studio)
{
    //ctor
}

T100DX12ContextManager::~T100DX12ContextManager()
{
    //dtor
}

T100VOID T100DX12ContextManager::Convert(T100DX12Frame* frame, T100DX12Model* model, T100DX12Context** ppContext)
{
    //DEBUGPRINT("Convert 1 %d", model->Type);
    ContextManagerConvert(frame, model, ppContext);
}

T100VOID T100DX12ContextManager::Update(T100DX12Frame* frame, T100DX12Context* context)
{
    ContextManagerUpdate(frame, context);
}

T100VOID T100DX12ContextManager::Render(T100DX12Frame* frame, T100DX12Context* context)
{
    ContextManagerRender(frame, context);
}

T100VOID T100DX12ContextManager::ContextManagerConvert(T100DX12Frame* frame, T100DX12Model* model, T100DX12Context** ppContext)
{
    //DEBUGPRINT("Convert 2 %d", model->Type);
    switch(model->Type){
    case T100DX12_MODEL_DOT:
        {
            ConvertDot(frame, model, ppContext);
        }
        break;
    case T100DX12_MODEL_LINE:
        {
            ConvertLine(frame, model, ppContext);
        }
        break;
    case T100DX12_MODEL_TRIANGLE:
        {
            ConvertTriangle(frame, model, ppContext);
        }
        break;
    case T100DX12_MODEL_PLANE:
        {
            ConvertPlane(frame, model, ppContext);
        }
        break;
    case T100DX12_MODEL_CITY:
        {
            ConvertCity(frame, model, ppContext);
        }
        break;
    case T100DX12_MODEL_SPHERE:
        {
            ConvertSphere(frame, model, ppContext);
        }
        break;
    case T100DX12_MODEL_RECTANGLE:
        {
            ConvertRectangle(frame, model, ppContext);
        }
        break;
    }
}

T100VOID T100DX12ContextManager::ContextManagerUpdate(T100DX12Frame* frame, T100DX12Context* context)
{
    Events(context);
}

T100VOID T100DX12ContextManager::ContextManagerRender(T100DX12Frame* frame, T100DX12Context* context)
{

}


T100VOID T100DX12ContextManager::ConvertDot(T100DX12Frame* frame, T100DX12Model* model, T100DX12Context** ppContext)
{
    T100DX12ContextDot*     result      = T100NEW T100DX12ContextDot();

    ConvertModel(model, result);

    result->SetFramePtr(frame);
    result->SetStudioPtr(m_studio);

    CreateAndCloseCommandList(m_studio, frame, result);

    result->Create();

    *ppContext  = result;
}

T100VOID T100DX12ContextManager::ConvertLine(T100DX12Frame* frame, T100DX12Model* model, T100DX12Context** ppContext)
{
    T100DX12ContextLine*    result      = T100NEW T100DX12ContextLine();

    ConvertModel(model, result);

    result->SetFramePtr(frame);
    result->SetStudioPtr(m_studio);

    CreateAndCloseCommandList(m_studio, frame, result);

    result->Create();

    *ppContext  = result;
}

T100VOID T100DX12ContextManager::ConvertTriangle(T100DX12Frame* frame, T100DX12Model* model, T100DX12Context** ppContext)
{
    T100DX12ContextTriangle*        result      = T100NEW T100DX12ContextTriangle();

    ConvertModel(model, result);

    result->SetFramePtr(frame);
    result->SetStudioPtr(m_studio);

    CreateAndCloseCommandList(m_studio, frame, result);

    result->Create();

    *ppContext  = result;
}

T100VOID T100DX12ContextManager::ConvertPlane(T100DX12Frame* frame, T100DX12Model* model, T100DX12Context** ppContext)
{
    T100DX12ContextPlane*        result      = T100NEW T100DX12ContextPlane();

    ConvertModel(model, result);

    result->SetFramePtr(frame);
    result->SetStudioPtr(m_studio);

    CreateAndCloseCommandList(m_studio, frame, result);

    result->Create();

    *ppContext  = result;
}

T100VOID T100DX12ContextManager::ConvertCity(T100DX12Frame* frame, T100DX12Model* model, T100DX12Context** ppContext)
{
    T100DX12ContextCity*    result      = T100NEW T100DX12ContextCity();

    ConvertModel(model, result);

    result->SetFramePtr(frame);
    result->SetStudioPtr(m_studio);

    CreateAndCloseCommandList(m_studio, frame, result);

    result->Create();

    *ppContext  = result;
}

T100VOID T100DX12ContextManager::ConvertSphere(T100DX12Frame* frame, T100DX12Model* model, T100DX12Context** ppContext)
{
    T100DX12ContextSphere*        result      = T100NEW T100DX12ContextSphere();

    ConvertModel(model, result);

    result->SetFramePtr(frame);
    result->SetStudioPtr(m_studio);

    CreateAndCloseCommandList(m_studio, frame, result);

    result->Create();

    *ppContext  = result;
}

T100VOID T100DX12ContextManager::ConvertRectangle(T100DX12Frame* frame, T100DX12Model* model, T100DX12Context** ppContext)
{
    T100DX12ContextRectangle*        result      = T100NEW T100DX12ContextRectangle();

    ConvertModel(model, result);

    result->SetFramePtr(frame);
    result->SetStudioPtr(m_studio);

    CreateAndCloseCommandList(m_studio, frame, result);

    result->Create();

    *ppContext  = result;
}

T100VOID T100DX12ContextManager::Events(T100DX12Context* context)
{
    while(!context->m_events.empty()){
        T100DX12Event&  event = context->m_events.front();
        RunEvent(event, context);
        context->m_events.pop();
    }
}

T100VOID T100DX12ContextManager::RunEvent(T100DX12Event& event, T100DX12Context* context)
{
    //DEBUGPRINT("Position: %f %f %f", event.Value.x, event.Value.y, event.Value.z);

    switch(event.Type){
    case T100DX12_CONTEXT_EVENT_POSITION:
        {
            context->SetPosition(event.Value);
        }
        break;
    case T100DX12_CONTEXT_EVENT_VISIBLE:
        {
            context->m_visible  = event.Item.BoolValue;
        }
        break;
    case T100DX12_CONTEXT_EVENT_REMOVE:
        {
           m_studio->m_frame_manager.Remove(context);
        }
        break;
    }
}
