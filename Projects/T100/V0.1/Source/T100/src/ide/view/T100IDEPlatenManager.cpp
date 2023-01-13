#include "T100IDEPlatenManager.h"

#include "T100IDEDefaultPlaten.h"

namespace T100IDE{

T100IDEPlatenManager::T100IDEPlatenManager(T100IDEView* view)
    :m_view(view)
{
    //ctor
    create();
}

T100IDEPlatenManager::~T100IDEPlatenManager()
{
    //dtor
    destroy();
}

T100VOID T100IDEPlatenManager::create()
{
    m_current = T100NEW T100IDEDefaultPlaten(m_view);
}

T100VOID T100IDEPlatenManager::destroy()
{
    T100SAFE_DELETE(m_current);
}

T100IDEDefaultPlaten* T100IDEPlatenManager::getDefault()
{
    if(!m_default){
        m_default   = T100NEW T100IDEDefaultPlaten(m_view);
    }
    return m_default;
}

T100IDEPlatenBase* T100IDEPlatenManager::getCurrent()
{
    return m_current;
}

T100BOOL T100IDEPlatenManager::Change(T100IDE_TYPE type)
{
    T100BOOL        result;

    switch(type){
    case T100IDE_TYPE_DEFAULT:
        {
            if(!m_default){
                m_default   = T100NEW T100IDEDefaultPlaten(m_view);
            }
            m_default->show();
            m_current = m_default;
        }
        break;
    case T100IDE_TYPE_EDITOR:
        {
            if(!m_editor){
                m_editor    = T100NEW T100IDEEditorPlaten(m_view);
            }
            m_editor->show();
            m_current = m_editor;
        }
        break;
    case T100IDE_TYPE_PAINTER:
        {
            if(!m_painter){
                m_painter   = T100NEW T100IDEPainterPlaten(m_view);
                if(m_painter){
                    result = m_painter->create();
                    if(result){
                        m_painter->show();
                    }
                }
            }
            m_painter->show();
            m_current = m_painter;
        }
        break;
    default:
        if(!m_default){
            m_default   = T100NEW T100IDEDefaultPlaten(m_view);
        }
        m_default->show();
        m_current = m_default;
    };
    return T100TRUE;
}

T100BOOL T100IDEPlatenManager::Exists(T100IDE_TYPE type)
{
    T100BOOL        result;

    switch(type){
    case T100IDE_TYPE_DEFAULT:
        {
            result = m_default;
        }
        break;
    case T100IDE_TYPE_EDITOR:
        {
            result = m_editor;
        }
        break;
    case T100IDE_TYPE_PAINTER:
        {
            result = m_painter;
        }
        break;
    default:
        result = m_default;
    };
    return result;
}

T100IDEPlatenBase* T100IDEPlatenManager::getPlaten(T100IDE_TYPE type)
{
    T100IDEPlatenBase*      result          = T100NULL;

    switch(type){
    case T100IDE_TYPE_DEFAULT:
        {
            if(!m_default){
                m_default   = T100NEW T100IDEDefaultPlaten(m_view);
            }
            result = m_default;
        }
        break;
    case T100IDE_TYPE_EDITOR:
        {
            if(!m_editor){
                m_editor    = T100NEW T100IDEEditorPlaten(m_view);
            }
            result = m_editor;
        }
        break;
    case T100IDE_TYPE_PAINTER:
        {
            if(!m_painter){
                m_painter   = T100NEW T100IDEPainterPlaten(m_view);
            }
            result = m_painter;
        }
        break;
    default:
        if(!m_default){
            m_default   = T100NEW T100IDEDefaultPlaten(m_view);
        }
        result = m_default;
    };
    return result;
}

}
