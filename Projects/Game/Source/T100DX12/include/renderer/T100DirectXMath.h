#ifndef T100DIRECTXMATH_H
#define T100DIRECTXMATH_H



namespace DirectX
{

    /****************************************************************************
     *
     * Constant definitions
     *
     ****************************************************************************/

#if defined(__XNAMATH_H__) && defined(XM_PI)
#undef XM_PI
#undef XM_2PI
#undef XM_1DIVPI
#undef XM_1DIV2PI
#undef XM_PIDIV2
#undef XM_PIDIV4
#undef XM_SELECT_0
#undef XM_SELECT_1
#undef XM_PERMUTE_0X
#undef XM_PERMUTE_0Y
#undef XM_PERMUTE_0Z
#undef XM_PERMUTE_0W
#undef XM_PERMUTE_1X
#undef XM_PERMUTE_1Y
#undef XM_PERMUTE_1Z
#undef XM_PERMUTE_1W
#undef XM_CRMASK_CR6
#undef XM_CRMASK_CR6TRUE
#undef XM_CRMASK_CR6FALSE
#undef XM_CRMASK_CR6BOUNDS
#undef XM_CACHE_LINE_SIZE
#endif

    constexpr float XM_PI = 3.141592654f;
    constexpr float XM_2PI = 6.283185307f;
    constexpr float XM_1DIVPI = 0.318309886f;
    constexpr float XM_1DIV2PI = 0.159154943f;
    constexpr float XM_PIDIV2 = 1.570796327f;
    constexpr float XM_PIDIV4 = 0.785398163f;

    constexpr uint32_t XM_SELECT_0 = 0x00000000;
    constexpr uint32_t XM_SELECT_1 = 0xFFFFFFFF;

    constexpr uint32_t XM_PERMUTE_0X = 0;
    constexpr uint32_t XM_PERMUTE_0Y = 1;
    constexpr uint32_t XM_PERMUTE_0Z = 2;
    constexpr uint32_t XM_PERMUTE_0W = 3;
    constexpr uint32_t XM_PERMUTE_1X = 4;
    constexpr uint32_t XM_PERMUTE_1Y = 5;
    constexpr uint32_t XM_PERMUTE_1Z = 6;
    constexpr uint32_t XM_PERMUTE_1W = 7;

    constexpr uint32_t XM_SWIZZLE_X = 0;
    constexpr uint32_t XM_SWIZZLE_Y = 1;
    constexpr uint32_t XM_SWIZZLE_Z = 2;
    constexpr uint32_t XM_SWIZZLE_W = 3;

    constexpr uint32_t XM_CRMASK_CR6 = 0x000000F0;
    constexpr uint32_t XM_CRMASK_CR6TRUE = 0x00000080;
    constexpr uint32_t XM_CRMASK_CR6FALSE = 0x00000020;
    constexpr uint32_t XM_CRMASK_CR6BOUNDS = XM_CRMASK_CR6FALSE;

    constexpr size_t XM_CACHE_LINE_SIZE = 64;


    /****************************************************************************
     *
     * Macros
     *
     ****************************************************************************/

#if defined(__XNAMATH_H__) && defined(XMComparisonAllTrue)
#undef XMComparisonAllTrue
#undef XMComparisonAnyTrue
#undef XMComparisonAllFalse
#undef XMComparisonAnyFalse
#undef XMComparisonMixed
#undef XMComparisonAllInBounds
#undef XMComparisonAnyOutOfBounds
#endif

     // Unit conversion

    inline constexpr float XMConvertToRadians(float fDegrees) noexcept { return fDegrees * (XM_PI / 180.0f); }
    inline constexpr float XMConvertToDegrees(float fRadians) noexcept { return fRadians * (180.0f / XM_PI); }

    // Condition register evaluation proceeding a recording (R) comparison

    inline constexpr bool XMComparisonAllTrue(uint32_t CR) noexcept { return (((CR)&XM_CRMASK_CR6TRUE) == XM_CRMASK_CR6TRUE); }
    inline constexpr bool XMComparisonAnyTrue(uint32_t CR) noexcept { return (((CR)&XM_CRMASK_CR6FALSE) != XM_CRMASK_CR6FALSE); }
    inline constexpr bool XMComparisonAllFalse(uint32_t CR) noexcept { return (((CR)&XM_CRMASK_CR6FALSE) == XM_CRMASK_CR6FALSE); }
    inline constexpr bool XMComparisonAnyFalse(uint32_t CR) noexcept { return (((CR)&XM_CRMASK_CR6TRUE) != XM_CRMASK_CR6TRUE); }
    inline constexpr bool XMComparisonMixed(uint32_t CR) noexcept { return (((CR)&XM_CRMASK_CR6) == 0); }
    inline constexpr bool XMComparisonAllInBounds(uint32_t CR) noexcept { return (((CR)&XM_CRMASK_CR6BOUNDS) == XM_CRMASK_CR6BOUNDS); }
    inline constexpr bool XMComparisonAnyOutOfBounds(uint32_t CR) noexcept { return (((CR)&XM_CRMASK_CR6BOUNDS) != XM_CRMASK_CR6BOUNDS); }


    /****************************************************************************
     *
     * Data types
     *
     ****************************************************************************/

#pragma warning(push)
#pragma warning(disable:4068 4201 4365 4324 4820)
     // C4068: ignore unknown pragmas
     // C4201: nonstandard extension used : nameless struct/union
     // C4365: Off by default noise
     // C4324/4820: padding warnings

#ifdef _PREFAST_
#pragma prefast(push)
#pragma prefast(disable : 25000, "FXMVECTOR is 16 bytes")
#endif


//------------------------------------------------------------------------------
#if defined(_XM_NO_INTRINSICS_)
    struct __vector4
    {
        union
        {
            float       vector4_f32[4];
            uint32_t    vector4_u32[4];
        };
    };
#endif // _XM_NO_INTRINSICS_

    //------------------------------------------------------------------------------
    // Vector intrinsic: Four 32 bit floating point components aligned on a 16 byte
    // boundary and mapped to hardware vector registers
#if defined(_XM_SSE_INTRINSICS_) && !defined(_XM_NO_INTRINSICS_)
    using XMVECTOR = __m128;
#elif defined(_XM_ARM_NEON_INTRINSICS_) && !defined(_XM_NO_INTRINSICS_)
    using XMVECTOR = float32x4_t;
#else
    using XMVECTOR = __vector4;
#endif

    // Fix-up for (1st-3rd) XMVECTOR parameters that are pass-in-register for x86, ARM, ARM64, and vector call; by reference otherwise
#if ( defined(_M_IX86) || defined(_M_ARM) || defined(_M_ARM64) || _XM_VECTORCALL_ || __i386__ || __arm__ || __aarch64__ ) && !defined(_XM_NO_INTRINSICS_)
    typedef const XMVECTOR FXMVECTOR;
#else
    typedef const XMVECTOR& FXMVECTOR;
#endif

    // Fix-up for (4th) XMVECTOR parameter to pass in-register for ARM, ARM64, and vector call; by reference otherwise
#if ( defined(_M_ARM) || defined(_M_ARM64) || defined(_M_HYBRID_X86_ARM64) || defined(_M_ARM64EC) || _XM_VECTORCALL_ || __arm__ || __aarch64__ ) && !defined(_XM_NO_INTRINSICS_)
    typedef const XMVECTOR GXMVECTOR;
#else
    typedef const XMVECTOR& GXMVECTOR;
#endif

    // Fix-up for (5th & 6th) XMVECTOR parameter to pass in-register for ARM64 and vector call; by reference otherwise
#if ( defined(_M_ARM64) || defined(_M_HYBRID_X86_ARM64) || defined(_M_ARM64EC) || _XM_VECTORCALL_ || __aarch64__ ) && !defined(_XM_NO_INTRINSICS_)
    typedef const XMVECTOR HXMVECTOR;
#else
    typedef const XMVECTOR& HXMVECTOR;
#endif

    // Fix-up for (7th+) XMVECTOR parameters to pass by reference
    typedef const XMVECTOR& CXMVECTOR;

    //------------------------------------------------------------------------------
    // Conversion types for constants
    XM_ALIGNED_STRUCT(16) XMVECTORF32
    {
        union
        {
            float f[4];
            XMVECTOR v;
        };

        inline operator XMVECTOR() const noexcept { return v; }
        inline operator const float* () const noexcept { return f; }
#ifdef _XM_NO_INTRINSICS_
#elif defined(_XM_SSE_INTRINSICS_)
        inline operator __m128i() const noexcept { return _mm_castps_si128(v); }
        inline operator __m128d() const noexcept { return _mm_castps_pd(v); }
#elif defined(_XM_ARM_NEON_INTRINSICS_) && defined(__GNUC__)
        inline operator int32x4_t() const noexcept { return vreinterpretq_s32_f32(v); }
        inline operator uint32x4_t() const noexcept { return vreinterpretq_u32_f32(v); }
#endif
    };

    XM_ALIGNED_STRUCT(16) XMVECTORI32
    {
        union
        {
            int32_t i[4];
            XMVECTOR v;
        };

        inline operator XMVECTOR() const noexcept { return v; }
#ifdef _XM_NO_INTRINSICS_
#elif defined(_XM_SSE_INTRINSICS_)
        inline operator __m128i() const noexcept { return _mm_castps_si128(v); }
        inline operator __m128d() const noexcept { return _mm_castps_pd(v); }
#elif defined(_XM_ARM_NEON_INTRINSICS_) && defined(__GNUC__)
        inline operator int32x4_t() const noexcept { return vreinterpretq_s32_f32(v); }
        inline operator uint32x4_t() const noexcept { return vreinterpretq_u32_f32(v); }
#endif
    };

    XM_ALIGNED_STRUCT(16) XMVECTORU8
    {
        union
        {
            uint8_t u[16];
            XMVECTOR v;
        };

        inline operator XMVECTOR() const noexcept { return v; }
#ifdef _XM_NO_INTRINSICS_
#elif defined(_XM_SSE_INTRINSICS_)
        inline operator __m128i() const noexcept { return _mm_castps_si128(v); }
        inline operator __m128d() const noexcept { return _mm_castps_pd(v); }
#elif defined(_XM_ARM_NEON_INTRINSICS_) && defined(__GNUC__)
        inline operator int32x4_t() const noexcept { return vreinterpretq_s32_f32(v); }
        inline operator uint32x4_t() const noexcept { return vreinterpretq_u32_f32(v); }
#endif
    };

    XM_ALIGNED_STRUCT(16) XMVECTORU32
    {
        union
        {
            uint32_t u[4];
            XMVECTOR v;
        };

        inline operator XMVECTOR() const noexcept { return v; }
#ifdef _XM_NO_INTRINSICS_
#elif defined(_XM_SSE_INTRINSICS_)
        inline operator __m128i() const noexcept { return _mm_castps_si128(v); }
        inline operator __m128d() const noexcept { return _mm_castps_pd(v); }
#elif defined(_XM_ARM_NEON_INTRINSICS_) && defined(__GNUC__)
        inline operator int32x4_t() const noexcept { return vreinterpretq_s32_f32(v); }
        inline operator uint32x4_t() const noexcept { return vreinterpretq_u32_f32(v); }
#endif
    };

    //------------------------------------------------------------------------------
    // Vector operators

#ifndef _XM_NO_XMVECTOR_OVERLOADS_
    XMVECTOR    XM_CALLCONV     operator+ (FXMVECTOR V) noexcept;
    XMVECTOR    XM_CALLCONV     operator- (FXMVECTOR V) noexcept;

    XMVECTOR& XM_CALLCONV     operator+= (XMVECTOR& V1, FXMVECTOR V2) noexcept;
    XMVECTOR& XM_CALLCONV     operator-= (XMVECTOR& V1, FXMVECTOR V2) noexcept;
    XMVECTOR& XM_CALLCONV     operator*= (XMVECTOR& V1, FXMVECTOR V2) noexcept;
    XMVECTOR& XM_CALLCONV     operator/= (XMVECTOR& V1, FXMVECTOR V2) noexcept;

    XMVECTOR& operator*= (XMVECTOR& V, float S) noexcept;
    XMVECTOR& operator/= (XMVECTOR& V, float S) noexcept;

    XMVECTOR    XM_CALLCONV     operator+ (FXMVECTOR V1, FXMVECTOR V2) noexcept;
    XMVECTOR    XM_CALLCONV     operator- (FXMVECTOR V1, FXMVECTOR V2) noexcept;
    XMVECTOR    XM_CALLCONV     operator* (FXMVECTOR V1, FXMVECTOR V2) noexcept;
    XMVECTOR    XM_CALLCONV     operator/ (FXMVECTOR V1, FXMVECTOR V2) noexcept;
    XMVECTOR    XM_CALLCONV     operator* (FXMVECTOR V, float S) noexcept;
    XMVECTOR    XM_CALLCONV     operator* (float S, FXMVECTOR V) noexcept;
    XMVECTOR    XM_CALLCONV     operator/ (FXMVECTOR V, float S) noexcept;
#endif /* !_XM_NO_XMVECTOR_OVERLOADS_ */


    //------------------------------------------------------------------------------
    // Matrix type: Sixteen 32 bit floating point components aligned on a
    // 16 byte boundary and mapped to four hardware vector registers

    struct XMMATRIX;

    // Fix-up for (1st) XMMATRIX parameter to pass in-register for ARM64 and vector call; by reference otherwise
#if ( defined(_M_ARM64) || defined(_M_HYBRID_X86_ARM64) || defined(_M_ARM64EC) || _XM_VECTORCALL_ || __aarch64__ ) && !defined(_XM_NO_INTRINSICS_)
    typedef const XMMATRIX FXMMATRIX;
#else
    typedef const XMMATRIX& FXMMATRIX;
#endif

    // Fix-up for (2nd+) XMMATRIX parameters to pass by reference
    typedef const XMMATRIX& CXMMATRIX;

#ifdef _XM_NO_INTRINSICS_
    struct XMMATRIX
#else
    XM_ALIGNED_STRUCT(16) XMMATRIX
#endif
    {
#ifdef _XM_NO_INTRINSICS_
        union
        {
            XMVECTOR r[4];
            struct
            {
                float _11, _12, _13, _14;
                float _21, _22, _23, _24;
                float _31, _32, _33, _34;
                float _41, _42, _43, _44;
            };
            float m[4][4];
        };
#else
        XMVECTOR r[4];
#endif

        XMMATRIX() = default;

        XMMATRIX(const XMMATRIX&) = default;

#if defined(_MSC_VER) && (_MSC_FULL_VER < 191426431)
        XMMATRIX& operator= (const XMMATRIX& M) noexcept { r[0] = M.r[0]; r[1] = M.r[1]; r[2] = M.r[2]; r[3] = M.r[3]; return *this; }
#else
        XMMATRIX& operator=(const XMMATRIX&) = default;

        XMMATRIX(XMMATRIX&&) = default;
        XMMATRIX& operator=(XMMATRIX&&) = default;
#endif

        constexpr XMMATRIX(FXMVECTOR R0, FXMVECTOR R1, FXMVECTOR R2, CXMVECTOR R3) noexcept : r{ R0,R1,R2,R3 } {}
        XMMATRIX(float m00, float m01, float m02, float m03,
            float m10, float m11, float m12, float m13,
            float m20, float m21, float m22, float m23,
            float m30, float m31, float m32, float m33) noexcept;
        explicit XMMATRIX(_In_reads_(16) const float* pArray) noexcept;

#ifdef _XM_NO_INTRINSICS_
        float       operator() (size_t Row, size_t Column) const noexcept { return m[Row][Column]; }
        float& operator() (size_t Row, size_t Column) noexcept { return m[Row][Column]; }
#endif

        XMMATRIX    operator+ () const noexcept { return *this; }
        XMMATRIX    operator- () const noexcept;

        XMMATRIX& XM_CALLCONV     operator+= (FXMMATRIX M) noexcept;
        XMMATRIX& XM_CALLCONV     operator-= (FXMMATRIX M) noexcept;
        XMMATRIX& XM_CALLCONV     operator*= (FXMMATRIX M) noexcept;
        XMMATRIX& operator*= (float S) noexcept;
        XMMATRIX& operator/= (float S) noexcept;

        XMMATRIX    XM_CALLCONV     operator+ (FXMMATRIX M) const noexcept;
        XMMATRIX    XM_CALLCONV     operator- (FXMMATRIX M) const noexcept;
        XMMATRIX    XM_CALLCONV     operator* (FXMMATRIX M) const noexcept;
        XMMATRIX    operator* (float S) const noexcept;
        XMMATRIX    operator/ (float S) const noexcept;

        friend XMMATRIX     XM_CALLCONV     operator* (float S, FXMMATRIX M) noexcept;
    };


} // namespace DirectX


#endif // T100DIRECTXMATH_H
