#include "T100MathTest.h"



T100MathTest::T100MathTest()
{
    //ctor
}

T100MathTest::~T100MathTest()
{
    //dtor
}

int T100MathTest::test()
{
    int     result      = 0;

    if(!result){
        result  = vector3_add_test();
    }

    if(!result){
        result  = vector3_mul_test();
    }

    if(!result){
        result  = vector4_add_test();
    }

    if(!result){
        result  = vector4_mul_test();
    }

    if(!result){
        result  = matrix3_add_test();
    }

    if(!result){
        result  = matrix3_mul_test();
    }

    if(!result){
        result  = matrix4_add_test();
    }

    if(!result){
        result  = matrix4_mul_test();
    }

    if(!result){
        result  = mul_test();
    }

    return result;
}

int T100MathTest::vector3_add_test()
{
    int     result      = 0;

    XMFLOAT3            xmfa;
    XMFLOAT3            xmfb;
    XMFLOAT3            xmfc;

    XMVECTOR            xmva;
    XMVECTOR            xmvb;
    XMVECTOR            xmvc;


    T100Vector3         tva;
    T100Vector3         tvb;
    T100Vector3         tvc;

    xmfa    = {1, 2, 3};
    xmfb    = {4, 5, 6};

    xmva    = XMLoadFloat3(&xmfa);
    xmvb    = XMLoadFloat3(&xmfb);

    xmvc    = xmva + xmvb;

    XMStoreFloat3(&xmfc, xmvc);

    tva     = {1, 2, 3};
    tvb     = {4, 5, 6};

    tvc     = tva + tvb;

    result  = equal(xmfc, tvc);

    return result;
}


int T100MathTest::vector3_mul_test()
{
    int     result      = 0;

    XMFLOAT3            xmfa;
    XMFLOAT3            xmfb;
    XMFLOAT3            xmfc;

    XMVECTOR            xmva;
    XMVECTOR            xmvb;
    XMVECTOR            xmvc;


    T100Vector3         tva;
    T100Vector3         tvb;
    T100Vector3         tvc;

    xmfa    = {1, 2, 3};
    xmfb    = {4, 5, 6};

    xmva    = XMLoadFloat3(&xmfa);
    xmvb    = XMLoadFloat3(&xmfb);

    xmvc    = xmva * xmvb;

    XMStoreFloat3(&xmfc, xmvc);

    tva     = {1, 2, 3};
    tvb     = {4, 5, 6};

    tvc     = tva * tvb;

    result  = equal(xmfc, tvc);

    return result;
}


int T100MathTest::vector4_add_test()
{
    int     result      = 0;

    XMFLOAT4            xmfa;
    XMFLOAT4            xmfb;
    XMFLOAT4            xmfc;

    XMVECTOR            xmva;
    XMVECTOR            xmvb;
    XMVECTOR            xmvc;


    T100Vector4         tva;
    T100Vector4         tvb;
    T100Vector4         tvc;

    xmfa    = {1, 2, 3, 4};
    xmfb    = {5, 6, 7, 8};

    xmva    = XMLoadFloat4(&xmfa);
    xmvb    = XMLoadFloat4(&xmfb);

    xmvc    = xmva + xmvb;

    XMStoreFloat4(&xmfc, xmvc);

    tva     = {1, 2, 3, 4};
    tvb     = {5, 6, 7, 8};

    tvc     = tva + tvb;

    result  = equal(xmfc, tvc);

    return result;
}


int T100MathTest::vector4_mul_test()
{
    int     result      = 0;

    XMFLOAT4            xmfa;
    XMFLOAT4            xmfb;
    XMFLOAT4            xmfc;

    XMVECTOR            xmva;
    XMVECTOR            xmvb;
    XMVECTOR            xmvc;


    T100Vector4         tva;
    T100Vector4         tvb;
    T100Vector4         tvc;

    xmfa    = {1, 2, 3, 4};
    xmfb    = {5, 6, 7, 8};

    xmva    = XMLoadFloat4(&xmfa);
    xmvb    = XMLoadFloat4(&xmfb);

    xmvc    = xmva * xmvb;

    XMStoreFloat4(&xmfc, xmvc);

    tva     = {1, 2, 3, 4};
    tvb     = {5, 6, 7, 8};

    tvc     = tva * tvb;

    result  = equal(xmfc, tvc);

    return result;
}


int T100MathTest::matrix3_add_test()
{
    int     result      = 0;

    XMFLOAT3X3          xmfa;
    XMFLOAT3X3          xmfb;
    XMFLOAT3X3          xmfc;

    XMMATRIX            xmma;
    XMMATRIX            xmmb;
    XMMATRIX            xmmc;


    T100Matrix3         tma;
    T100Matrix3         tmb;
    T100Matrix3         tmc;

    xmfa    = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    xmfb    = {9, 8, 7, 6, 5, 4, 3, 2, 1};

    xmma    = XMLoadFloat3x3(&xmfa);
    xmmb    = XMLoadFloat3x3(&xmfb);

    xmmc    = xmma + xmmb;

    XMStoreFloat3x3(&xmfc, xmmc);

    tma     = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    tmb     = {9, 8, 7, 6, 5, 4, 3, 2, 1};

    tmc     = tma + tmb;

    result  = equal(xmfc, tmc);

    return result;
}


int T100MathTest::matrix3_mul_test()
{
    int     result      = 0;

    XMFLOAT3X3          xmfa;
    XMFLOAT3X3          xmfb;
    XMFLOAT3X3          xmfc;

    XMMATRIX            xmma;
    XMMATRIX            xmmb;
    XMMATRIX            xmmc;


    T100Matrix3         tma;
    T100Matrix3         tmb;
    T100Matrix3         tmc;

    xmfa    = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    xmfb    = {9, 8, 7, 6, 5, 4, 3, 2, 1};

    xmma    = XMLoadFloat3x3(&xmfa);
    xmmb    = XMLoadFloat3x3(&xmfb);

    xmmc    = xmma * xmmb;

    XMStoreFloat3x3(&xmfc, xmmc);

    tma     = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    tmb     = {9, 8, 7, 6, 5, 4, 3, 2, 1};

    tmc     = tma * tmb;

    result  = equal(xmfc, tmc);

    return result;
}


int T100MathTest::matrix4_add_test()
{
    int     result      = 0;

    XMFLOAT4X4          xmfa;
    XMFLOAT4X4          xmfb;
    XMFLOAT4X4          xmfc;

    XMMATRIX            xmma;
    XMMATRIX            xmmb;
    XMMATRIX            xmmc;


    T100Matrix4         tma;
    T100Matrix4         tmb;
    T100Matrix4         tmc;

    xmfa    = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16};
    xmfb    = {16, 15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1};

    xmma    = XMLoadFloat4x4(&xmfa);
    xmmb    = XMLoadFloat4x4(&xmfb);

    xmmc    = xmma + xmmb;

    XMStoreFloat4x4(&xmfc, xmmc);

    tma     = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16};
    tmb     = {16, 15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1};

    tmc     = tma + tmb;

    result  = equal(xmfc, tmc);

    return result;
}


int T100MathTest::matrix4_mul_test()
{
    int     result      = 0;

    XMFLOAT4X4          xmfa;
    XMFLOAT4X4          xmfb;
    XMFLOAT4X4          xmfc;

    XMMATRIX            xmma;
    XMMATRIX            xmmb;
    XMMATRIX            xmmc;


    T100Matrix4         tma;
    T100Matrix4         tmb;
    T100Matrix4         tmc;

    xmfa    = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16};
    xmfb    = {16, 15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1};

    xmma    = XMLoadFloat4x4(&xmfa);
    xmmb    = XMLoadFloat4x4(&xmfb);

    xmmc    = xmma * xmmb;

    XMStoreFloat4x4(&xmfc, xmmc);

    tma     = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16};
    tmb     = {16, 15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1};

    tmc     = tma * tmb;

    result  = equal(xmfc, tmc);

    return result;
}

int T100MathTest::mul_test()
{
    int     result      = 0;

    XMFLOAT3            xmfa;
    XMFLOAT3X3          xmfb;
    XMFLOAT3            xmfc;

    XMVECTOR            xmva;
    XMMATRIX            xmmb;
    XMVECTOR            xmvc;


    T100Vector3         tva;
    T100Matrix3         tmb;
    T100Vector3         tvc;

    xmfa    = {1, 2, 3};
    xmfb    = {9, 8, 7, 6, 5, 4, 3, 2, 1};

    xmva    = XMLoadFloat3(&xmfa);
    xmmb    = XMLoadFloat3x3(&xmfb);

    //xmvc    = xmmb * xmva;

    XMStoreFloat3(&xmfc, xmvc);

    tva     = {1, 2, 3};
    tmb     = {9, 8, 7, 6, 5, 4, 3, 2, 1};

    tvc     = tva * tmb;

    result  = equal(xmfc, tvc);

    return result;
}


int T100MathTest::equal(XMFLOAT3 para1, T100Vector3 para2)
{
    if(para1.x == para2.FLOAT3[0]
       && para1.y == para2.FLOAT3[1]
       && para1.z == para2.FLOAT3[2]){
        return 0;
    }
    return -1;
}

int T100MathTest::equal(XMFLOAT4 para1, T100Vector4 para2)
{
    if(para1.x == para2.FLOAT4[0]
       && para1.y == para2.FLOAT4[1]
       && para1.z == para2.FLOAT4[2]
       && para1.w == para2.FLOAT4[3]){
        return 0;
    }
    return -1;
}

int T100MathTest::equal(XMFLOAT3X3 para1, T100Matrix3 para2)
{
    if(para1._11 == para2._11
       && para1._12 == para2._12
       && para1._13 == para2._13
       && para1._21 == para2._21
       && para1._22 == para2._22
       && para1._23 == para2._23
       && para1._31 == para2._31
       && para1._32 == para2._32
       && para1._33 == para2._33){
        return 0;
    }
    return -1;
}

int T100MathTest::equal(XMFLOAT4X4 para1, T100Matrix4 para2)
{
    if(para1._11 == para2._11
       && para1._12 == para2._12
       && para1._13 == para2._13
       && para1._14 == para2._14
       && para1._21 == para2._21
       && para1._22 == para2._22
       && para1._23 == para2._23
       && para1._24 == para2._24
       && para1._31 == para2._31
       && para1._32 == para2._32
       && para1._33 == para2._33
       && para1._34 == para2._34
       && para1._41 == para2._41
       && para1._42 == para2._42
       && para1._43 == para2._43
       && para1._44 == para2._44){
        return 0;
    }
    return -1;
}
