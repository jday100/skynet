#ifndef T100DX12TOOLS_H
#define T100DX12TOOLS_H

#include <stdexcept>
#include <string>
#include <windows.h>
#include <wrl.h>

using Microsoft::WRL::ComPtr;

inline std::string HrToString(HRESULT hr)
{
    char s_str[64] = {};
    sprintf_s(s_str, "HRESULT of 0x%08X", static_cast<UINT>(hr));
    return std::string(s_str);
}

class HrException : public std::runtime_error
{
public:
    HrException(HRESULT hr) : std::runtime_error(HrToString(hr)), m_hr(hr) {}
    HRESULT Error() const { return m_hr; }
private:
    const HRESULT m_hr;
};

#define SAFE_RELEASE(p) if (p) (p)->Release()

inline void ThrowIfFailed(HRESULT hr)
{
    if (FAILED(hr))
    {
        throw HrException(hr);
    }
}


class T100DX12Tools
{
    public:
        T100DX12Tools();
        virtual ~T100DX12Tools();

    protected:

    private:
};

#endif // T100DX12TOOLS_H
