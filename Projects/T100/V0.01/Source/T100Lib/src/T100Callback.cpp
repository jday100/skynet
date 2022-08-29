#include "T100Callback.h"

T100Callback::T100Callback()
{
    //ctor
}

T100Callback::~T100Callback()
{
    //dtor
}

T100BOOL T100Callback::append(T100CALLBACK_HANDLE handle, void* obj)
{
    for(T100CALLBACK_ENTRY* entry : m_callbacks){
        if(entry && entry->HANDLE == handle){
            return T100FALSE;
        }
    }

    T100CALLBACK_ENTRY* entry = T100NEW T100CALLBACK_ENTRY;
    if(!entry){
        return T100FALSE;
    }

    entry->OBJECT   = obj;
    entry->HANDLE   = handle;

    m_callbacks.push_back(entry);

    return T100TRUE;
}

T100BOOL T100Callback::erase(T100CALLBACK_HANDLE handle)
{
    for(T100CALLBACK_VECTOR::iterator it = m_callbacks.begin();it != m_callbacks.end();it++){
        T100CALLBACK_ENTRY* entry = (*it);

        if(entry && entry->HANDLE == handle){
            m_callbacks.erase(it);
            T100SAFE_DELETE(entry);
            return T100TRUE;
        }
    }

    return T100FALSE;
}

T100BOOL T100Callback::clear()
{
    for(T100CALLBACK_ENTRY* entry : m_callbacks){
        if(entry){
            T100SAFE_DELETE(entry);
        }else{
            return T100FALSE;
        }
    }

    m_callbacks.clear();
    return T100TRUE;
}

T100BOOL T100Callback::run(void* value)
{
    T100BOOL        result      = T100TRUE;

    for(T100CALLBACK_ENTRY* entry : m_callbacks){
        if(entry){
            entry->VALUE = value;
            if(!(entry->HANDLE(T100NULL, T100NULL, T100NULL, entry->OBJECT, value))){
                result = T100FALSE;
            }
        }else{
            result = T100FALSE;
        }
    }

    return result;
}
