#include "T100Game.h"
#include "T100GameHelper.h"

T100Game::T100Game(UINT width, UINT height, std::wstring name)
    :m_width(width),
    m_height(height),
    m_title(name),
    m_useWarpDevice(T100FALSE)
{
    //ctor

    WCHAR   assetsPath[512];

    GetAssetsPath(assetsPath, _countof(assetsPath));
    m_assetsPath = assetsPath;

    m_aspectRatio   = static_cast<float>(width) / static_cast<float>(height);

}

T100Game::~T100Game()
{
    //dtor
}

T100VOID T100Game::OnKeyDown(UINT key)
{

}

T100VOID T100Game::OnKeyUp(UINT key)
{

}
