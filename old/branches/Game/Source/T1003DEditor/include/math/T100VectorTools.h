#ifndef T100VECTORTOOLS_H
#define T100VECTORTOOLS_H

#define INLINE __forceinline

#include "T100Vector3.h"
#include "T100Vector4.h"
#include "T100Matrix3.h"
#include "T100Matrix4.h"

#define     T100_PI             3.141592654f
#define     T100_2XPI           6.283185307f
#define     T100_1DIVPI         0.318309886f
#define     T100_1DIV2XPI       0.159154943f
#define     T100_PIDIV2         1.570796327f
#define     T100_PIDIV4         0.785398163f

INLINE float Max( float a, float b ) { return a > b ? a : b; }
INLINE float Min( float a, float b ) { return a < b ? a : b; }
INLINE float Clamp( float v, float a, float b ) { return Min(Max(v, a), b); }


T100Vector3     operator*(T100Vector3&, T100Matrix3&);

T100Vector4     operator*(T100Vector4&, T100Matrix4&);

class T100VectorTools
{
    public:
        T100VectorTools();
        virtual ~T100VectorTools();

        static T100VOID             Translation(T100Vector3, T100Vector3, T100Vector3&);
        static T100VOID             Rotation(T100Vector3, T100Vector3, T100Vector3&);
        static T100VOID             Scaling(T100Vector3, T100Vector3, T100Vector3&);

        static T100Matrix3          ToMatrix3(T100Vector3&);
        static T100Vector3          ToVector3(T100Matrix3&);

        static T100VOID             RotationX(T100Vector3, T100FLOAT, T100Vector3&);

        static T100VOID             RotationZ(T100Vector3, T100FLOAT, T100Vector3&);

        static T100VOID             ToTranslationMatrix4(T100Vector3, T100Matrix4&);
        static T100VOID             ToRotationXMatrix4(T100FLOAT, T100Matrix4&);
        static T100VOID             ToRotationYMatrix4(T100FLOAT, T100Matrix4&);
        static T100VOID             ToRotationZMatrix4(T100FLOAT, T100Matrix4&);

        static T100VOID             ToVector3(T100Vector4, T100Vector3&);
        static T100VOID             ToVector4One(T100Vector3, T100Vector4&);
        static T100VOID             ToVector4Zero(T100Vector3, T100Vector4&);

        static T100VOID             ScalarSinAndCos(T100FLOAT, T100FLOAT&, T100FLOAT&);

    protected:

    private:
};

#endif // T100VECTORTOOLS_H
