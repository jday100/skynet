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




struct XMMATRIX{
};

typedef const XMMATRIX& FXMMATRIX;

typedef const XMMATRIX& CXMMATRIX;

struct __vector4
{
    union
    {
        float       vector4_f32[4];
        uint32_t    vector4_u32[4];
    };
};

using XMVECTOR = __vector4;

typedef const XMVECTOR& FXMVECTOR;



//------------------------------------------------------------------------------
// Return the X component in an FPU register.
inline float XM_CALLCONV XMVectorGetX(FXMVECTOR V) noexcept
{
#if defined(_XM_NO_INTRINSICS_)
    return V.vector4_f32[0];
#elif defined(_XM_ARM_NEON_INTRINSICS_)
    return vgetq_lane_f32(V, 0);
#elif defined(_XM_SSE_INTRINSICS_)
    return _mm_cvtss_f32(V);
#endif
}

// Return the Y component in an FPU register.
inline float XM_CALLCONV XMVectorGetY(FXMVECTOR V) noexcept
{
#if defined(_XM_NO_INTRINSICS_)
    return V.vector4_f32[1];
#elif defined(_XM_ARM_NEON_INTRINSICS_)
    return vgetq_lane_f32(V, 1);
#elif defined(_XM_SSE_INTRINSICS_)
    XMVECTOR vTemp = XM_PERMUTE_PS(V, _MM_SHUFFLE(1, 1, 1, 1));
    return _mm_cvtss_f32(vTemp);
#endif
}

// Return the Z component in an FPU register.
inline float XM_CALLCONV XMVectorGetZ(FXMVECTOR V) noexcept
{
#if defined(_XM_NO_INTRINSICS_)
    return V.vector4_f32[2];
#elif defined(_XM_ARM_NEON_INTRINSICS_)
    return vgetq_lane_f32(V, 2);
#elif defined(_XM_SSE_INTRINSICS_)
    XMVECTOR vTemp = XM_PERMUTE_PS(V, _MM_SHUFFLE(2, 2, 2, 2));
    return _mm_cvtss_f32(vTemp);
#endif
}

// Return the W component in an FPU register.
inline float XM_CALLCONV XMVectorGetW(FXMVECTOR V) noexcept
{
#if defined(_XM_NO_INTRINSICS_)
    return V.vector4_f32[3];
#elif defined(_XM_ARM_NEON_INTRINSICS_)
    return vgetq_lane_f32(V, 3);
#elif defined(_XM_SSE_INTRINSICS_)
    XMVECTOR vTemp = XM_PERMUTE_PS(V, _MM_SHUFFLE(3, 3, 3, 3));
    return _mm_cvtss_f32(vTemp);
#endif
}


inline XMVECTOR XM_CALLCONV XMLoadFloat3(const XMFLOAT3* pSource) noexcept
{
    //assert(pSource);
#if defined(_XM_NO_INTRINSICS_)
    XMVECTOR V;
    V.vector4_f32[0] = pSource->x;
    V.vector4_f32[1] = pSource->y;
    V.vector4_f32[2] = pSource->z;
    V.vector4_f32[3] = 0.f;
    return V;
#elif defined(_XM_ARM_NEON_INTRINSICS_)
    float32x2_t x = vld1_f32(reinterpret_cast<const float*>(pSource));
    float32x2_t zero = vdup_n_f32(0);
    float32x2_t y = vld1_lane_f32(reinterpret_cast<const float*>(pSource) + 2, zero, 0);
    return vcombine_f32(x, y);
#elif defined(_XM_SSE4_INTRINSICS_)
    __m128 xy = _mm_castpd_ps(_mm_load_sd(reinterpret_cast<const double*>(pSource)));
    __m128 z = _mm_load_ss(&pSource->z);
    return _mm_insert_ps(xy, z, 0x20);
#elif defined(_XM_SSE_INTRINSICS_)
    __m128 xy = _mm_castpd_ps(_mm_load_sd(reinterpret_cast<const double*>(pSource)));
    __m128 z = _mm_load_ss(&pSource->z);
    return _mm_movelh_ps(xy, z);
#endif
}



inline XMVECTOR XM_CALLCONV XMVector3Normalize(FXMVECTOR V) noexcept
{
#if defined(_XM_NO_INTRINSICS_)
    float fLength;
    XMVECTOR vResult;

    vResult = XMVector3Length(V);
    fLength = vResult.vector4_f32[0];

    // Prevent divide by zero
    if (fLength > 0)
    {
        fLength = 1.0f / fLength;
    }

    vResult.vector4_f32[0] = V.vector4_f32[0] * fLength;
    vResult.vector4_f32[1] = V.vector4_f32[1] * fLength;
    vResult.vector4_f32[2] = V.vector4_f32[2] * fLength;
    vResult.vector4_f32[3] = V.vector4_f32[3] * fLength;
    return vResult;

#elif defined(_XM_ARM_NEON_INTRINSICS_)
    // Dot3
    float32x4_t vTemp = vmulq_f32(V, V);
    float32x2_t v1 = vget_low_f32(vTemp);
    float32x2_t v2 = vget_high_f32(vTemp);
    v1 = vpadd_f32(v1, v1);
    v2 = vdup_lane_f32(v2, 0);
    v1 = vadd_f32(v1, v2);
    uint32x2_t VEqualsZero = vceq_f32(v1, vdup_n_f32(0));
    uint32x2_t VEqualsInf = vceq_f32(v1, vget_low_f32(g_XMInfinity));
    // Reciprocal sqrt (2 iterations of Newton-Raphson)
    float32x2_t S0 = vrsqrte_f32(v1);
    float32x2_t P0 = vmul_f32(v1, S0);
    float32x2_t R0 = vrsqrts_f32(P0, S0);
    float32x2_t S1 = vmul_f32(S0, R0);
    float32x2_t P1 = vmul_f32(v1, S1);
    float32x2_t R1 = vrsqrts_f32(P1, S1);
    v2 = vmul_f32(S1, R1);
    // Normalize
    XMVECTOR vResult = vmulq_f32(V, vcombine_f32(v2, v2));
    vResult = vbslq_f32(vcombine_u32(VEqualsZero, VEqualsZero), vdupq_n_f32(0), vResult);
    return vbslq_f32(vcombine_u32(VEqualsInf, VEqualsInf), g_XMQNaN, vResult);
#elif defined(_XM_SSE4_INTRINSICS_)
    XMVECTOR vLengthSq = _mm_dp_ps(V, V, 0x7f);
    // Prepare for the division
    XMVECTOR vResult = _mm_sqrt_ps(vLengthSq);
    // Create zero with a single instruction
    XMVECTOR vZeroMask = _mm_setzero_ps();
    // Test for a divide by zero (Must be FP to detect -0.0)
    vZeroMask = _mm_cmpneq_ps(vZeroMask, vResult);
    // Failsafe on zero (Or epsilon) length planes
    // If the length is infinity, set the elements to zero
    vLengthSq = _mm_cmpneq_ps(vLengthSq, g_XMInfinity);
    // Divide to perform the normalization
    vResult = _mm_div_ps(V, vResult);
    // Any that are infinity, set to zero
    vResult = _mm_and_ps(vResult, vZeroMask);
    // Select qnan or result based on infinite length
    XMVECTOR vTemp1 = _mm_andnot_ps(vLengthSq, g_XMQNaN);
    XMVECTOR vTemp2 = _mm_and_ps(vResult, vLengthSq);
    vResult = _mm_or_ps(vTemp1, vTemp2);
    return vResult;
#elif defined(_XM_SSE3_INTRINSICS_)
    // Perform the dot product on x,y and z only
    XMVECTOR vLengthSq = _mm_mul_ps(V, V);
    vLengthSq = _mm_and_ps(vLengthSq, g_XMMask3);
    vLengthSq = _mm_hadd_ps(vLengthSq, vLengthSq);
    vLengthSq = _mm_hadd_ps(vLengthSq, vLengthSq);
    // Prepare for the division
    XMVECTOR vResult = _mm_sqrt_ps(vLengthSq);
    // Create zero with a single instruction
    XMVECTOR vZeroMask = _mm_setzero_ps();
    // Test for a divide by zero (Must be FP to detect -0.0)
    vZeroMask = _mm_cmpneq_ps(vZeroMask, vResult);
    // Failsafe on zero (Or epsilon) length planes
    // If the length is infinity, set the elements to zero
    vLengthSq = _mm_cmpneq_ps(vLengthSq, g_XMInfinity);
    // Divide to perform the normalization
    vResult = _mm_div_ps(V, vResult);
    // Any that are infinity, set to zero
    vResult = _mm_and_ps(vResult, vZeroMask);
    // Select qnan or result based on infinite length
    XMVECTOR vTemp1 = _mm_andnot_ps(vLengthSq, g_XMQNaN);
    XMVECTOR vTemp2 = _mm_and_ps(vResult, vLengthSq);
    vResult = _mm_or_ps(vTemp1, vTemp2);
    return vResult;
#elif defined(_XM_SSE_INTRINSICS_)
    // Perform the dot product on x,y and z only
    XMVECTOR vLengthSq = _mm_mul_ps(V, V);
    XMVECTOR vTemp = XM_PERMUTE_PS(vLengthSq, _MM_SHUFFLE(2, 1, 2, 1));
    vLengthSq = _mm_add_ss(vLengthSq, vTemp);
    vTemp = XM_PERMUTE_PS(vTemp, _MM_SHUFFLE(1, 1, 1, 1));
    vLengthSq = _mm_add_ss(vLengthSq, vTemp);
    vLengthSq = XM_PERMUTE_PS(vLengthSq, _MM_SHUFFLE(0, 0, 0, 0));
    // Prepare for the division
    XMVECTOR vResult = _mm_sqrt_ps(vLengthSq);
    // Create zero with a single instruction
    XMVECTOR vZeroMask = _mm_setzero_ps();
    // Test for a divide by zero (Must be FP to detect -0.0)
    vZeroMask = _mm_cmpneq_ps(vZeroMask, vResult);
    // Failsafe on zero (Or epsilon) length planes
    // If the length is infinity, set the elements to zero
    vLengthSq = _mm_cmpneq_ps(vLengthSq, g_XMInfinity);
    // Divide to perform the normalization
    vResult = _mm_div_ps(V, vResult);
    // Any that are infinity, set to zero
    vResult = _mm_and_ps(vResult, vZeroMask);
    // Select qnan or result based on infinite length
    XMVECTOR vTemp1 = _mm_andnot_ps(vLengthSq, g_XMQNaN);
    XMVECTOR vTemp2 = _mm_and_ps(vResult, vLengthSq);
    vResult = _mm_or_ps(vTemp1, vTemp2);
    return vResult;
#endif
}


inline XMVECTOR XM_CALLCONV XMVectorNegate(FXMVECTOR V) noexcept
{
#if defined(_XM_NO_INTRINSICS_)

    XMVECTORF32 Result = { { {
            -V.vector4_f32[0],
            -V.vector4_f32[1],
            -V.vector4_f32[2],
            -V.vector4_f32[3]
        } } };
    return Result.v;

#elif defined(_XM_ARM_NEON_INTRINSICS_)
    return vnegq_f32(V);
#elif defined(_XM_SSE_INTRINSICS_)
    XMVECTOR Z;

    Z = _mm_setzero_ps();

    return _mm_sub_ps(Z, V);
#endif
}


 //------------------------------------------------------------------------------

inline bool XM_CALLCONV XMVector3Equal
(
    FXMVECTOR V1,
    FXMVECTOR V2
) noexcept
{
#if defined(_XM_NO_INTRINSICS_)
    return (((V1.vector4_f32[0] == V2.vector4_f32[0]) && (V1.vector4_f32[1] == V2.vector4_f32[1]) && (V1.vector4_f32[2] == V2.vector4_f32[2])) != 0);
#elif defined(_XM_ARM_NEON_INTRINSICS_)
    uint32x4_t vResult = vceqq_f32(V1, V2);
    uint8x8x2_t vTemp = vzip_u8(vget_low_u8(vreinterpretq_u8_u32(vResult)), vget_high_u8(vreinterpretq_u8_u32(vResult)));
    uint16x4x2_t vTemp2 = vzip_u16(vreinterpret_u16_u8(vTemp.val[0]), vreinterpret_u16_u8(vTemp.val[1]));
    return ((vget_lane_u32(vreinterpret_u32_u16(vTemp2.val[1]), 1) & 0xFFFFFFU) == 0xFFFFFFU);
#elif defined(_XM_SSE_INTRINSICS_)
    XMVECTOR vTemp = _mm_cmpeq_ps(V1, V2);
    return (((_mm_movemask_ps(vTemp) & 7) == 7) != 0);
#endif
}

//------------------------------------------------------------------------------

inline uint32_t XM_CALLCONV XMVector3EqualR
(
    FXMVECTOR V1,
    FXMVECTOR V2
) noexcept
{
#if defined(_XM_NO_INTRINSICS_)
    uint32_t CR = 0;
    if ((V1.vector4_f32[0] == V2.vector4_f32[0]) &&
        (V1.vector4_f32[1] == V2.vector4_f32[1]) &&
        (V1.vector4_f32[2] == V2.vector4_f32[2]))
    {
        CR = XM_CRMASK_CR6TRUE;
    }
    else if ((V1.vector4_f32[0] != V2.vector4_f32[0]) &&
        (V1.vector4_f32[1] != V2.vector4_f32[1]) &&
        (V1.vector4_f32[2] != V2.vector4_f32[2]))
    {
        CR = XM_CRMASK_CR6FALSE;
    }
    return CR;
#elif defined(_XM_ARM_NEON_INTRINSICS_)
    uint32x4_t vResult = vceqq_f32(V1, V2);
    uint8x8x2_t vTemp = vzip_u8(vget_low_u8(vreinterpretq_u8_u32(vResult)), vget_high_u8(vreinterpretq_u8_u32(vResult)));
    uint16x4x2_t vTemp2 = vzip_u16(vreinterpret_u16_u8(vTemp.val[0]), vreinterpret_u16_u8(vTemp.val[1]));
    uint32_t r = vget_lane_u32(vreinterpret_u32_u16(vTemp2.val[1]), 1) & 0xFFFFFFU;

    uint32_t CR = 0;
    if (r == 0xFFFFFFU)
    {
        CR = XM_CRMASK_CR6TRUE;
    }
    else if (!r)
    {
        CR = XM_CRMASK_CR6FALSE;
    }
    return CR;
#elif defined(_XM_SSE_INTRINSICS_)
    XMVECTOR vTemp = _mm_cmpeq_ps(V1, V2);
    int iTest = _mm_movemask_ps(vTemp) & 7;
    uint32_t CR = 0;
    if (iTest == 7)
    {
        CR = XM_CRMASK_CR6TRUE;
    }
    else if (!iTest)
    {
        CR = XM_CRMASK_CR6FALSE;
    }
    return CR;
#endif
}

//------------------------------------------------------------------------------

inline bool XM_CALLCONV XMVector3EqualInt
(
    FXMVECTOR V1,
    FXMVECTOR V2
) noexcept
{
#if defined(_XM_NO_INTRINSICS_)
    return (((V1.vector4_u32[0] == V2.vector4_u32[0]) && (V1.vector4_u32[1] == V2.vector4_u32[1]) && (V1.vector4_u32[2] == V2.vector4_u32[2])) != 0);
#elif defined(_XM_ARM_NEON_INTRINSICS_)
    uint32x4_t vResult = vceqq_u32(vreinterpretq_u32_f32(V1), vreinterpretq_u32_f32(V2));
    uint8x8x2_t vTemp = vzip_u8(vget_low_u8(vreinterpretq_u8_u32(vResult)), vget_high_u8(vreinterpretq_u8_u32(vResult)));
    uint16x4x2_t vTemp2 = vzip_u16(vreinterpret_u16_u8(vTemp.val[0]), vreinterpret_u16_u8(vTemp.val[1]));
    return ((vget_lane_u32(vreinterpret_u32_u16(vTemp2.val[1]), 1) & 0xFFFFFFU) == 0xFFFFFFU);
#elif defined(_XM_SSE_INTRINSICS_)
    __m128i vTemp = _mm_cmpeq_epi32(_mm_castps_si128(V1), _mm_castps_si128(V2));
    return (((_mm_movemask_ps(_mm_castsi128_ps(vTemp)) & 7) == 7) != 0);
#endif
}

//------------------------------------------------------------------------------

inline uint32_t XM_CALLCONV XMVector3EqualIntR
(
    FXMVECTOR V1,
    FXMVECTOR V2
) noexcept
{
#if defined(_XM_NO_INTRINSICS_)
    uint32_t CR = 0;
    if ((V1.vector4_u32[0] == V2.vector4_u32[0]) &&
        (V1.vector4_u32[1] == V2.vector4_u32[1]) &&
        (V1.vector4_u32[2] == V2.vector4_u32[2]))
    {
        CR = XM_CRMASK_CR6TRUE;
    }
    else if ((V1.vector4_u32[0] != V2.vector4_u32[0]) &&
        (V1.vector4_u32[1] != V2.vector4_u32[1]) &&
        (V1.vector4_u32[2] != V2.vector4_u32[2]))
    {
        CR = XM_CRMASK_CR6FALSE;
    }
    return CR;
#elif defined(_XM_ARM_NEON_INTRINSICS_)
    uint32x4_t vResult = vceqq_u32(vreinterpretq_u32_f32(V1), vreinterpretq_u32_f32(V2));
    uint8x8x2_t vTemp = vzip_u8(vget_low_u8(vreinterpretq_u8_u32(vResult)), vget_high_u8(vreinterpretq_u8_u32(vResult)));
    uint16x4x2_t vTemp2 = vzip_u16(vreinterpret_u16_u8(vTemp.val[0]), vreinterpret_u16_u8(vTemp.val[1]));
    uint32_t r = vget_lane_u32(vreinterpret_u32_u16(vTemp2.val[1]), 1) & 0xFFFFFFU;

    uint32_t CR = 0;
    if (r == 0xFFFFFFU)
    {
        CR = XM_CRMASK_CR6TRUE;
    }
    else if (!r)
    {
        CR = XM_CRMASK_CR6FALSE;
    }
    return CR;
#elif defined(_XM_SSE_INTRINSICS_)
    __m128i vTemp = _mm_cmpeq_epi32(_mm_castps_si128(V1), _mm_castps_si128(V2));
    int iTemp = _mm_movemask_ps(_mm_castsi128_ps(vTemp)) & 7;
    uint32_t CR = 0;
    if (iTemp == 7)
    {
        CR = XM_CRMASK_CR6TRUE;
    }
    else if (!iTemp)
    {
        CR = XM_CRMASK_CR6FALSE;
    }
    return CR;
#endif
}

//------------------------------------------------------------------------------

inline bool XM_CALLCONV XMVector3NearEqual
(
    FXMVECTOR V1,
    FXMVECTOR V2,
    FXMVECTOR Epsilon
) noexcept
{
#if defined(_XM_NO_INTRINSICS_)
    float dx, dy, dz;

    dx = fabsf(V1.vector4_f32[0] - V2.vector4_f32[0]);
    dy = fabsf(V1.vector4_f32[1] - V2.vector4_f32[1]);
    dz = fabsf(V1.vector4_f32[2] - V2.vector4_f32[2]);
    return (((dx <= Epsilon.vector4_f32[0]) &&
        (dy <= Epsilon.vector4_f32[1]) &&
        (dz <= Epsilon.vector4_f32[2])) != 0);
#elif defined(_XM_ARM_NEON_INTRINSICS_)
    float32x4_t vDelta = vsubq_f32(V1, V2);
#if defined(_MSC_VER) && !defined(__clang__)
    uint32x4_t vResult = vacleq_f32(vDelta, Epsilon);
#else
    uint32x4_t vResult = vcleq_f32(vabsq_f32(vDelta), Epsilon);
#endif
    uint8x8x2_t vTemp = vzip_u8(vget_low_u8(vreinterpretq_u8_u32(vResult)), vget_high_u8(vreinterpretq_u8_u32(vResult)));
    uint16x4x2_t vTemp2 = vzip_u16(vreinterpret_u16_u8(vTemp.val[0]), vreinterpret_u16_u8(vTemp.val[1]));
    return ((vget_lane_u32(vreinterpret_u32_u16(vTemp2.val[1]), 1) & 0xFFFFFFU) == 0xFFFFFFU);
#elif defined(_XM_SSE_INTRINSICS_)
    // Get the difference
    XMVECTOR vDelta = _mm_sub_ps(V1, V2);
    // Get the absolute value of the difference
    XMVECTOR vTemp = _mm_setzero_ps();
    vTemp = _mm_sub_ps(vTemp, vDelta);
    vTemp = _mm_max_ps(vTemp, vDelta);
    vTemp = _mm_cmple_ps(vTemp, Epsilon);
    // w is don't care
    return (((_mm_movemask_ps(vTemp) & 7) == 0x7) != 0);
#endif
}

//------------------------------------------------------------------------------

inline bool XM_CALLCONV XMVector3NotEqual
(
    FXMVECTOR V1,
    FXMVECTOR V2
) noexcept
{
#if defined(_XM_NO_INTRINSICS_)
    return (((V1.vector4_f32[0] != V2.vector4_f32[0]) || (V1.vector4_f32[1] != V2.vector4_f32[1]) || (V1.vector4_f32[2] != V2.vector4_f32[2])) != 0);
#elif defined(_XM_ARM_NEON_INTRINSICS_)
    uint32x4_t vResult = vceqq_f32(V1, V2);
    uint8x8x2_t vTemp = vzip_u8(vget_low_u8(vreinterpretq_u8_u32(vResult)), vget_high_u8(vreinterpretq_u8_u32(vResult)));
    uint16x4x2_t vTemp2 = vzip_u16(vreinterpret_u16_u8(vTemp.val[0]), vreinterpret_u16_u8(vTemp.val[1]));
    return ((vget_lane_u32(vreinterpret_u32_u16(vTemp2.val[1]), 1) & 0xFFFFFFU) != 0xFFFFFFU);
#elif defined(_XM_SSE_INTRINSICS_)
    XMVECTOR vTemp = _mm_cmpeq_ps(V1, V2);
    return (((_mm_movemask_ps(vTemp) & 7) != 7) != 0);
#endif
}

//------------------------------------------------------------------------------

inline bool XM_CALLCONV XMVector3NotEqualInt
(
    FXMVECTOR V1,
    FXMVECTOR V2
) noexcept
{
#if defined(_XM_NO_INTRINSICS_)
    return (((V1.vector4_u32[0] != V2.vector4_u32[0]) || (V1.vector4_u32[1] != V2.vector4_u32[1]) || (V1.vector4_u32[2] != V2.vector4_u32[2])) != 0);
#elif defined(_XM_ARM_NEON_INTRINSICS_)
    uint32x4_t vResult = vceqq_u32(vreinterpretq_u32_f32(V1), vreinterpretq_u32_f32(V2));
    uint8x8x2_t vTemp = vzip_u8(vget_low_u8(vreinterpretq_u8_u32(vResult)), vget_high_u8(vreinterpretq_u8_u32(vResult)));
    uint16x4x2_t vTemp2 = vzip_u16(vreinterpret_u16_u8(vTemp.val[0]), vreinterpret_u16_u8(vTemp.val[1]));
    return ((vget_lane_u32(vreinterpret_u32_u16(vTemp2.val[1]), 1) & 0xFFFFFFU) != 0xFFFFFFU);
#elif defined(_XM_SSE_INTRINSICS_)
    __m128i vTemp = _mm_cmpeq_epi32(_mm_castps_si128(V1), _mm_castps_si128(V2));
    return (((_mm_movemask_ps(_mm_castsi128_ps(vTemp)) & 7) != 7) != 0);
#endif
}

//------------------------------------------------------------------------------

inline bool XM_CALLCONV XMVector3Greater
(
    FXMVECTOR V1,
    FXMVECTOR V2
) noexcept
{
#if defined(_XM_NO_INTRINSICS_)
    return (((V1.vector4_f32[0] > V2.vector4_f32[0]) && (V1.vector4_f32[1] > V2.vector4_f32[1]) && (V1.vector4_f32[2] > V2.vector4_f32[2])) != 0);
#elif defined(_XM_ARM_NEON_INTRINSICS_)
    uint32x4_t vResult = vcgtq_f32(V1, V2);
    uint8x8x2_t vTemp = vzip_u8(vget_low_u8(vreinterpretq_u8_u32(vResult)), vget_high_u8(vreinterpretq_u8_u32(vResult)));
    uint16x4x2_t vTemp2 = vzip_u16(vreinterpret_u16_u8(vTemp.val[0]), vreinterpret_u16_u8(vTemp.val[1]));
    return ((vget_lane_u32(vreinterpret_u32_u16(vTemp2.val[1]), 1) & 0xFFFFFFU) == 0xFFFFFFU);
#elif defined(_XM_SSE_INTRINSICS_)
    XMVECTOR vTemp = _mm_cmpgt_ps(V1, V2);
    return (((_mm_movemask_ps(vTemp) & 7) == 7) != 0);
#endif
}

//------------------------------------------------------------------------------

inline uint32_t XM_CALLCONV XMVector3GreaterR
(
    FXMVECTOR V1,
    FXMVECTOR V2
) noexcept
{
#if defined(_XM_NO_INTRINSICS_)
    uint32_t CR = 0;
    if ((V1.vector4_f32[0] > V2.vector4_f32[0]) &&
        (V1.vector4_f32[1] > V2.vector4_f32[1]) &&
        (V1.vector4_f32[2] > V2.vector4_f32[2]))
    {
        CR = XM_CRMASK_CR6TRUE;
    }
    else if ((V1.vector4_f32[0] <= V2.vector4_f32[0]) &&
        (V1.vector4_f32[1] <= V2.vector4_f32[1]) &&
        (V1.vector4_f32[2] <= V2.vector4_f32[2]))
    {
        CR = XM_CRMASK_CR6FALSE;
    }
    return CR;

#elif defined(_XM_ARM_NEON_INTRINSICS_)
    uint32x4_t vResult = vcgtq_f32(V1, V2);
    uint8x8x2_t vTemp = vzip_u8(vget_low_u8(vreinterpretq_u8_u32(vResult)), vget_high_u8(vreinterpretq_u8_u32(vResult)));
    uint16x4x2_t vTemp2 = vzip_u16(vreinterpret_u16_u8(vTemp.val[0]), vreinterpret_u16_u8(vTemp.val[1]));
    uint32_t r = vget_lane_u32(vreinterpret_u32_u16(vTemp2.val[1]), 1) & 0xFFFFFFU;

    uint32_t CR = 0;
    if (r == 0xFFFFFFU)
    {
        CR = XM_CRMASK_CR6TRUE;
    }
    else if (!r)
    {
        CR = XM_CRMASK_CR6FALSE;
    }
    return CR;
#elif defined(_XM_SSE_INTRINSICS_)
    XMVECTOR vTemp = _mm_cmpgt_ps(V1, V2);
    uint32_t CR = 0;
    int iTest = _mm_movemask_ps(vTemp) & 7;
    if (iTest == 7)
    {
        CR = XM_CRMASK_CR6TRUE;
    }
    else if (!iTest)
    {
        CR = XM_CRMASK_CR6FALSE;
    }
    return CR;
#endif
}

//------------------------------------------------------------------------------

inline bool XM_CALLCONV XMVector3GreaterOrEqual
(
    FXMVECTOR V1,
    FXMVECTOR V2
) noexcept
{
#if defined(_XM_NO_INTRINSICS_)
    return (((V1.vector4_f32[0] >= V2.vector4_f32[0]) && (V1.vector4_f32[1] >= V2.vector4_f32[1]) && (V1.vector4_f32[2] >= V2.vector4_f32[2])) != 0);
#elif defined(_XM_ARM_NEON_INTRINSICS_)
    uint32x4_t vResult = vcgeq_f32(V1, V2);
    uint8x8x2_t vTemp = vzip_u8(vget_low_u8(vreinterpretq_u8_u32(vResult)), vget_high_u8(vreinterpretq_u8_u32(vResult)));
    uint16x4x2_t vTemp2 = vzip_u16(vreinterpret_u16_u8(vTemp.val[0]), vreinterpret_u16_u8(vTemp.val[1]));
    return ((vget_lane_u32(vreinterpret_u32_u16(vTemp2.val[1]), 1) & 0xFFFFFFU) == 0xFFFFFFU);
#elif defined(_XM_SSE_INTRINSICS_)
    XMVECTOR vTemp = _mm_cmpge_ps(V1, V2);
    return (((_mm_movemask_ps(vTemp) & 7) == 7) != 0);
#endif
}

//------------------------------------------------------------------------------

inline uint32_t XM_CALLCONV XMVector3GreaterOrEqualR
(
    FXMVECTOR V1,
    FXMVECTOR V2
) noexcept
{
#if defined(_XM_NO_INTRINSICS_)

    uint32_t CR = 0;
    if ((V1.vector4_f32[0] >= V2.vector4_f32[0]) &&
        (V1.vector4_f32[1] >= V2.vector4_f32[1]) &&
        (V1.vector4_f32[2] >= V2.vector4_f32[2]))
    {
        CR = XM_CRMASK_CR6TRUE;
    }
    else if ((V1.vector4_f32[0] < V2.vector4_f32[0]) &&
        (V1.vector4_f32[1] < V2.vector4_f32[1]) &&
        (V1.vector4_f32[2] < V2.vector4_f32[2]))
    {
        CR = XM_CRMASK_CR6FALSE;
    }
    return CR;

#elif defined(_XM_ARM_NEON_INTRINSICS_)
    uint32x4_t vResult = vcgeq_f32(V1, V2);
    uint8x8x2_t vTemp = vzip_u8(vget_low_u8(vreinterpretq_u8_u32(vResult)), vget_high_u8(vreinterpretq_u8_u32(vResult)));
    uint16x4x2_t vTemp2 = vzip_u16(vreinterpret_u16_u8(vTemp.val[0]), vreinterpret_u16_u8(vTemp.val[1]));
    uint32_t r = vget_lane_u32(vreinterpret_u32_u16(vTemp2.val[1]), 1) & 0xFFFFFFU;

    uint32_t CR = 0;
    if (r == 0xFFFFFFU)
    {
        CR = XM_CRMASK_CR6TRUE;
    }
    else if (!r)
    {
        CR = XM_CRMASK_CR6FALSE;
    }
    return CR;
#elif defined(_XM_SSE_INTRINSICS_)
    XMVECTOR vTemp = _mm_cmpge_ps(V1, V2);
    uint32_t CR = 0;
    int iTest = _mm_movemask_ps(vTemp) & 7;
    if (iTest == 7)
    {
        CR = XM_CRMASK_CR6TRUE;
    }
    else if (!iTest)
    {
        CR = XM_CRMASK_CR6FALSE;
    }
    return CR;
#endif
}

//------------------------------------------------------------------------------

inline bool XM_CALLCONV XMVector3Less
(
    FXMVECTOR V1,
    FXMVECTOR V2
) noexcept
{
#if defined(_XM_NO_INTRINSICS_)
    return (((V1.vector4_f32[0] < V2.vector4_f32[0]) && (V1.vector4_f32[1] < V2.vector4_f32[1]) && (V1.vector4_f32[2] < V2.vector4_f32[2])) != 0);
#elif defined(_XM_ARM_NEON_INTRINSICS_)
    uint32x4_t vResult = vcltq_f32(V1, V2);
    uint8x8x2_t vTemp = vzip_u8(vget_low_u8(vreinterpretq_u8_u32(vResult)), vget_high_u8(vreinterpretq_u8_u32(vResult)));
    uint16x4x2_t vTemp2 = vzip_u16(vreinterpret_u16_u8(vTemp.val[0]), vreinterpret_u16_u8(vTemp.val[1]));
    return ((vget_lane_u32(vreinterpret_u32_u16(vTemp2.val[1]), 1) & 0xFFFFFFU) == 0xFFFFFFU);
#elif defined(_XM_SSE_INTRINSICS_)
    XMVECTOR vTemp = _mm_cmplt_ps(V1, V2);
    return (((_mm_movemask_ps(vTemp) & 7) == 7) != 0);
#endif
}

//------------------------------------------------------------------------------

inline bool XM_CALLCONV XMVector3LessOrEqual
(
    FXMVECTOR V1,
    FXMVECTOR V2
) noexcept
{
#if defined(_XM_NO_INTRINSICS_)
    return (((V1.vector4_f32[0] <= V2.vector4_f32[0]) && (V1.vector4_f32[1] <= V2.vector4_f32[1]) && (V1.vector4_f32[2] <= V2.vector4_f32[2])) != 0);
#elif defined(_XM_ARM_NEON_INTRINSICS_)
    uint32x4_t vResult = vcleq_f32(V1, V2);
    uint8x8x2_t vTemp = vzip_u8(vget_low_u8(vreinterpretq_u8_u32(vResult)), vget_high_u8(vreinterpretq_u8_u32(vResult)));
    uint16x4x2_t vTemp2 = vzip_u16(vreinterpret_u16_u8(vTemp.val[0]), vreinterpret_u16_u8(vTemp.val[1]));
    return ((vget_lane_u32(vreinterpret_u32_u16(vTemp2.val[1]), 1) & 0xFFFFFFU) == 0xFFFFFFU);
#elif defined(_XM_SSE_INTRINSICS_)
    XMVECTOR vTemp = _mm_cmple_ps(V1, V2);
    return (((_mm_movemask_ps(vTemp) & 7) == 7) != 0);
#endif
}

//------------------------------------------------------------------------------

inline bool XM_CALLCONV XMVector3InBounds
(
    FXMVECTOR V,
    FXMVECTOR Bounds
) noexcept
{
#if defined(_XM_NO_INTRINSICS_)
    return (((V.vector4_f32[0] <= Bounds.vector4_f32[0] && V.vector4_f32[0] >= -Bounds.vector4_f32[0]) &&
        (V.vector4_f32[1] <= Bounds.vector4_f32[1] && V.vector4_f32[1] >= -Bounds.vector4_f32[1]) &&
        (V.vector4_f32[2] <= Bounds.vector4_f32[2] && V.vector4_f32[2] >= -Bounds.vector4_f32[2])) != 0);
#elif defined(_XM_ARM_NEON_INTRINSICS_)
    // Test if less than or equal
    uint32x4_t ivTemp1 = vcleq_f32(V, Bounds);
    // Negate the bounds
    float32x4_t vTemp2 = vnegq_f32(Bounds);
    // Test if greater or equal (Reversed)
    uint32x4_t ivTemp2 = vcleq_f32(vTemp2, V);
    // Blend answers
    ivTemp1 = vandq_u32(ivTemp1, ivTemp2);
    // in bounds?
    uint8x8x2_t vTemp = vzip_u8(vget_low_u8(vreinterpretq_u8_u32(ivTemp1)), vget_high_u8(vreinterpretq_u8_u32(ivTemp1)));
    uint16x4x2_t vTemp3 = vzip_u16(vreinterpret_u16_u8(vTemp.val[0]), vreinterpret_u16_u8(vTemp.val[1]));
    return ((vget_lane_u32(vreinterpret_u32_u16(vTemp3.val[1]), 1) & 0xFFFFFFU) == 0xFFFFFFU);
#elif defined(_XM_SSE_INTRINSICS_)
    // Test if less than or equal
    XMVECTOR vTemp1 = _mm_cmple_ps(V, Bounds);
    // Negate the bounds
    XMVECTOR vTemp2 = _mm_mul_ps(Bounds, g_XMNegativeOne);
    // Test if greater or equal (Reversed)
    vTemp2 = _mm_cmple_ps(vTemp2, V);
    // Blend answers
    vTemp1 = _mm_and_ps(vTemp1, vTemp2);
    // x,y and z in bounds? (w is don't care)
    return (((_mm_movemask_ps(vTemp1) & 0x7) == 0x7) != 0);
#else
    return XMComparisonAllInBounds(XMVector3InBoundsR(V, Bounds));
#endif
}




 //------------------------------------------------------------------------------
 // Return a vector with all elements equaling zero
inline XMVECTOR XM_CALLCONV XMVectorZero() noexcept
{
#if defined(_XM_NO_INTRINSICS_)
    XMVECTORF32 vResult = { { { 0.0f, 0.0f, 0.0f, 0.0f } } };
    return vResult.v;
#elif defined(_XM_ARM_NEON_INTRINSICS_)
    return vdupq_n_f32(0);
#elif defined(_XM_SSE_INTRINSICS_)
    return _mm_setzero_ps();
#endif
}


//------------------------------------------------------------------------------

inline XMMATRIX XM_CALLCONV XMMatrixLookToLH
(
    FXMVECTOR EyePosition,
    FXMVECTOR EyeDirection,
    FXMVECTOR UpDirection
) noexcept
{
    assert(!XMVector3Equal(EyeDirection, XMVectorZero()));
    assert(!XMVector3IsInfinite(EyeDirection));
    assert(!XMVector3Equal(UpDirection, XMVectorZero()));
    assert(!XMVector3IsInfinite(UpDirection));

    XMVECTOR R2 = XMVector3Normalize(EyeDirection);

    XMVECTOR R0 = XMVector3Cross(UpDirection, R2);
    R0 = XMVector3Normalize(R0);

    XMVECTOR R1 = XMVector3Cross(R2, R0);

    XMVECTOR NegEyePosition = XMVectorNegate(EyePosition);

    XMVECTOR D0 = XMVector3Dot(R0, NegEyePosition);
    XMVECTOR D1 = XMVector3Dot(R1, NegEyePosition);
    XMVECTOR D2 = XMVector3Dot(R2, NegEyePosition);

    XMMATRIX M;
    M.r[0] = XMVectorSelect(D0, R0, g_XMSelect1110.v);
    M.r[1] = XMVectorSelect(D1, R1, g_XMSelect1110.v);
    M.r[2] = XMVectorSelect(D2, R2, g_XMSelect1110.v);
    M.r[3] = g_XMIdentityR3.v;

    M = XMMatrixTranspose(M);

    return M;
}



inline XMMATRIX XM_CALLCONV XMMatrixLookToRH
(
    FXMVECTOR EyePosition,
    FXMVECTOR EyeDirection,
    FXMVECTOR UpDirection
) noexcept
{
    XMVECTOR NegEyeDirection = XMVectorNegate(EyeDirection);
    return XMMatrixLookToLH(EyePosition, NegEyeDirection, UpDirection);
}


//------------------------------------------------------------------------------

inline XMMATRIX XM_CALLCONV XMMatrixPerspectiveFovRH
(
    float FovAngleY,
    float AspectRatio,
    float NearZ,
    float FarZ
) noexcept
{
    assert(NearZ > 0.f && FarZ > 0.f);
    assert(!XMScalarNearEqual(FovAngleY, 0.0f, 0.00001f * 2.0f));
    assert(!XMScalarNearEqual(AspectRatio, 0.0f, 0.00001f));
    assert(!XMScalarNearEqual(FarZ, NearZ, 0.00001f));

#if defined(_XM_NO_INTRINSICS_)

    float    SinFov;
    float    CosFov;
    XMScalarSinCos(&SinFov, &CosFov, 0.5f * FovAngleY);

    float Height = CosFov / SinFov;
    float Width = Height / AspectRatio;
    float fRange = FarZ / (NearZ - FarZ);

    XMMATRIX M;
    M.m[0][0] = Width;
    M.m[0][1] = 0.0f;
    M.m[0][2] = 0.0f;
    M.m[0][3] = 0.0f;

    M.m[1][0] = 0.0f;
    M.m[1][1] = Height;
    M.m[1][2] = 0.0f;
    M.m[1][3] = 0.0f;

    M.m[2][0] = 0.0f;
    M.m[2][1] = 0.0f;
    M.m[2][2] = fRange;
    M.m[2][3] = -1.0f;

    M.m[3][0] = 0.0f;
    M.m[3][1] = 0.0f;
    M.m[3][2] = fRange * NearZ;
    M.m[3][3] = 0.0f;
    return M;

#elif defined(_XM_ARM_NEON_INTRINSICS_)
    float    SinFov;
    float    CosFov;
    XMScalarSinCos(&SinFov, &CosFov, 0.5f * FovAngleY);
    float fRange = FarZ / (NearZ - FarZ);
    float Height = CosFov / SinFov;
    float Width = Height / AspectRatio;
    const float32x4_t Zero = vdupq_n_f32(0);

    XMMATRIX M;
    M.r[0] = vsetq_lane_f32(Width, Zero, 0);
    M.r[1] = vsetq_lane_f32(Height, Zero, 1);
    M.r[2] = vsetq_lane_f32(fRange, g_XMNegIdentityR3.v, 2);
    M.r[3] = vsetq_lane_f32(fRange * NearZ, Zero, 2);
    return M;
#elif defined(_XM_SSE_INTRINSICS_)
    float    SinFov;
    float    CosFov;
    XMScalarSinCos(&SinFov, &CosFov, 0.5f * FovAngleY);
    float fRange = FarZ / (NearZ - FarZ);
    // Note: This is recorded on the stack
    float Height = CosFov / SinFov;
    XMVECTOR rMem = {
        Height / AspectRatio,
        Height,
        fRange,
        fRange * NearZ
    };
    // Copy from memory to SSE register
    XMVECTOR vValues = rMem;
    XMVECTOR vTemp = _mm_setzero_ps();
    // Copy x only
    vTemp = _mm_move_ss(vTemp, vValues);
    // CosFov / SinFov,0,0,0
    XMMATRIX M;
    M.r[0] = vTemp;
    // 0,Height / AspectRatio,0,0
    vTemp = vValues;
    vTemp = _mm_and_ps(vTemp, g_XMMaskY);
    M.r[1] = vTemp;
    // x=fRange,y=-fRange * NearZ,0,-1.0f
    vTemp = _mm_setzero_ps();
    vValues = _mm_shuffle_ps(vValues, g_XMNegIdentityR3, _MM_SHUFFLE(3, 2, 3, 2));
    // 0,0,fRange,-1.0f
    vTemp = _mm_shuffle_ps(vTemp, vValues, _MM_SHUFFLE(3, 0, 0, 0));
    M.r[2] = vTemp;
    // 0,0,fRange * NearZ,0.0f
    vTemp = _mm_shuffle_ps(vTemp, vValues, _MM_SHUFFLE(2, 1, 0, 0));
    M.r[3] = vTemp;
    return M;
#endif
}

}


#endif // T100DIRECTXMATH_H
