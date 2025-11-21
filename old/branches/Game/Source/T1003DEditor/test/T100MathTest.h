#ifndef T100MATHTEST_H
#define T100MATHTEST_H

#include "dx12/DirectXMath.h"
#include "T100VectorTools.h"

using namespace DirectX;

class T100MathTest
{
    public:
        T100MathTest();
        virtual ~T100MathTest();

        int             test();

    protected:
        int             vector3_add_test();
        int             vector3_mul_test();

        int             vector4_add_test();
        int             vector4_mul_test();

        int             matrix3_add_test();
        int             matrix3_mul_test();

        int             matrix4_add_test();
        int             matrix4_mul_test();

        int             mul_test();

    private:
        int             equal(XMFLOAT3, T100Vector3);
        int             equal(XMFLOAT4, T100Vector4);

        int             equal(XMFLOAT3X3, T100Matrix3);
        int             equal(XMFLOAT4X4, T100Matrix4);
};

#endif // T100MATHTEST_H
