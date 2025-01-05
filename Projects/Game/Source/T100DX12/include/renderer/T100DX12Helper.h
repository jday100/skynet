#ifndef T100DX12HELPER_H
#define T100DX12HELPER_H

#include <stdexcept>
#include <string>
#include <math.h>

#include <d3d12.h>


inline std::string HrToString(HRESULT hr)
{
    char    s_str[64] = {};
    sprintf_s(s_str, "HRESULT of 0x%08X", static_cast<UINT>(hr));
    return std::string(s_str);
}

class HrException : public std::runtime_error
{
public:
    HrException(HRESULT hr) : std::runtime_error(HrToString(hr)), m_hr(hr){}
    HRESULT Error() const {return m_hr;}

private:
    const HRESULT m_hr;
};

inline void ThrowIfFailed(HRESULT hr)
{
    if(FAILED(hr)){
        throw HrException(hr);
    }
}

inline float ConvertDipsToPixels(float dips, float dpi)
{
    static const float dipsPerInch = 96.0f;
    return floorf(dips * dpi / dipsPerInch + 0.5f); // 舍入到最接近的整数。
}

#if defined(_DEBUG)
	inline void SetName(ID3D12Object* pObject, LPCWSTR name)
	{
		pObject->SetName(name);
	}
#else
	inline void SetName(ID3D12Object*, LPCWSTR)
	{
	}
#endif


#define NAME_D3D12_OBJECT(x) SetName(x.Get(), L#x)

#endif // T100DX12HELPER_H
