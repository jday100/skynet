#ifndef T100DIRECTXMATH_H
#define T100DIRECTXMATH_H

namespace DirectX{
    constexpr float XM_PI = 3.141592654f;
    constexpr float XM_2PI = 6.283185307f;
    constexpr float XM_1DIVPI = 0.318309886f;
    constexpr float XM_1DIV2PI = 0.159154943f;
    constexpr float XM_PIDIV2 = 1.570796327f;
    constexpr float XM_PIDIV4 = 0.785398163f;

#if _XM_VECTORCALL_
#define XM_CALLCONV __vectorcall
#elif defined(__GNUC__)
#define XM_CALLCONV
#else
#define XM_CALLCONV __fastcall
#endif


}


#endif // T100DIRECTXMATH_H
