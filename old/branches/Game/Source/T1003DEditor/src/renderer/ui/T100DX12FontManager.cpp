#include "T100DX12FontManager.h"

#include "consola24.h"

T100DX12FontManager::T100DX12FontManager()
{
    //ctor
}

T100DX12FontManager::~T100DX12FontManager()
{
    //dtor
}

T100DX12Font* T100DX12FontManager::GetFont(T100WSTRING name)
{
    if(name == L"default"){
        LoadFromBinary(g_pconsola24, sizeof(g_pconsola24));
    }
}

T100VOID T100DX12FontManager::LoadFromBinary(T100UCHAR* data, T100UINT length)
{
    T100DX12FontHeader* header = (T100DX12FontHeader*)data;
}
