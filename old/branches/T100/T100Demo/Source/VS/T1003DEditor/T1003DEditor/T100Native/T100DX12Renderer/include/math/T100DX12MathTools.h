#ifndef T100DX12MATHTOOLS_H
#define T100DX12MATHTOOLS_H

#include "T100MathTools.h"

#include "T100Common.h"
#include "dx12/T100DX12header.h"
#include "vector/T100Vector2u.h"
#include "vector/T100Vector2f.h"
#include "vector/T100Vector3u.h"
#include "vector/T100Vector3f.h"
#include "matrix/T100Matrix4f.h"

inline T100VOID     Convert(const XMFLOAT3& source, T100Vector3f& target)
{
    target.X    = source.x;
    target.Y    = source.y;
    target.Z    = source.z;
}

inline T100VOID     Convert(const T100Vector3f& source, XMFLOAT3& target)
{
    target.x    = source.X;
    target.y    = source.Y;
    target.z    = source.Z;
}

inline T100VOID     Convert(const XMVECTOR& source, T100Vector3f& target)
{
    XMFLOAT3    value;

    XMStoreFloat3(&value, source);

    Convert(value, target);
}

inline T100VOID     Convert(const T100Vector3f& source, XMVECTOR& target)
{
    XMFLOAT3    value;

    Convert(source, value);

    target  = XMLoadFloat3(&value);
}

inline T100VOID     Convert(const XMFLOAT4X4& source, T100Matrix4f& target)
{
    target._11      = source._11;
    target._12      = source._12;
    target._13      = source._13;
    target._14      = source._14;

    target._21      = source._21;
    target._22      = source._22;
    target._23      = source._23;
    target._24      = source._24;

    target._31      = source._31;
    target._32      = source._32;
    target._33      = source._33;
    target._34      = source._34;

    target._41      = source._41;
    target._42      = source._42;
    target._43      = source._43;
    target._44      = source._44;
}

inline T100VOID     Convert(const T100Matrix4f& source, XMFLOAT4X4& target)
{
    target._11      = source._11;
    target._12      = source._12;
    target._13      = source._13;
    target._14      = source._14;

    target._21      = source._21;
    target._22      = source._22;
    target._23      = source._23;
    target._24      = source._24;

    target._31      = source._31;
    target._32      = source._32;
    target._33      = source._33;
    target._34      = source._34;

    target._41      = source._41;
    target._42      = source._42;
    target._43      = source._43;
    target._44      = source._44;
}

inline T100VOID     Convert(const XMMATRIX& source, T100Matrix4f& target)
{
    XMFLOAT4X4      result;

    XMStoreFloat4x4(&result, source);

    Convert(result, target);
}

inline T100VOID     Convert(const T100Matrix4f& source, XMMATRIX& target)
{
    XMFLOAT4X4      value;

    Convert(source, value);

    target = XMLoadFloat4x4(&value);
}

inline T100VOID     ConvertScreenCoordinate(const T100Vector2u& source, T100UINT width, T100UINT height, T100Vector2f& target)
{
    T100FLOAT   w   = width / 2.0f;
    T100FLOAT   h   = height / 2.0f;

    target.X    = (source.X - w) / w;
    target.Y    = (h - source.Y) / h;
}

inline T100VOID     ConvertScreenCoordinate(const T100Vector2f& source, T100UINT width, T100UINT height, T100Vector2u& target)
{
    T100FLOAT   w   = width / 2.0f;
    T100FLOAT   h   = height / 2.0f;

    target.X    = (source.X + 1) * w;
    target.Y    = (source.Y - 1) * h;
}

inline T100VOID     ConvertScreenCoordinate(const T100Vector3u& source, T100UINT width, T100UINT height, T100Vector3f& target)
{
    T100Vector2u    value   = {source.X, source.Y};
    T100Vector2f    result;

    ConvertScreenCoordinate(value, width, height, result);

    target  = {result.X, result.Y, 0};
}

inline T100VOID     ConvertScreenCoordinate(const T100Vector3f& source, T100UINT width, T100UINT height, T100Vector3u& target)
{
    T100Vector2f    value   = {source.X, source.Y};
    T100Vector2u    result;

    ConvertScreenCoordinate(value, width, height, result);

    target  = {result.X, result.Y, 0};
}

inline T100VOID     ScreenToView(const T100Vector3f& source, T100UINT width, T100UINT height, T100Vector3f& target)
{
    T100FLOAT   w   = width / 2.0f;
    T100FLOAT   h   = height / 2.0f;

    target.X    = (source.X - w) / w;
    target.Y    = (h - source.Y) / h;
    target.Z    = 0;
}

inline T100VOID     ScreenToView(const XMFLOAT3& source, T100UINT width, T100UINT height, XMFLOAT3& target)
{
    T100FLOAT   w   = width / 2.0f;
    T100FLOAT   h   = height / 2.0f;

    target.x    = (source.x - w) / w;
    target.y    = (h - source.y) / h;
    target.z    = 0;
}

inline T100VOID     ViewToScreen(const T100Vector3f& source, T100UINT width, T100UINT height, T100Vector3f& target)
{
    T100FLOAT   w   = width / 2.0f;
    T100FLOAT   h   = height / 2.0f;

    target.X    = (source.X + 1) * w;
    target.Y    = (source.Y - 1) * h;
    target.Z    = 0;
}

inline T100VOID     AngleToRadian(T100Vector3f& source, T100Vector3f& target)
{
    target  = source / 180.0f * T100_PI;
}

inline T100VOID     AngleToRadian(XMFLOAT3& source, XMFLOAT3& target)
{
    T100FLOAT   value   = T100_PI / 180.0f;

    target.x    = source.x * value;
    target.y    = source.y * value;
    target.z    = source.z * value;
}

class T100DX12MathTools
{
    public:
        T100DX12MathTools() {}
        virtual ~T100DX12MathTools() {}

    protected:

    private:
};

#endif // T100DX12MATHTOOLS_H
