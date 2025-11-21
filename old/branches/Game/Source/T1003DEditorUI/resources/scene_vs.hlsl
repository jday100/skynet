struct VSInput
{
    float3 position	: POSITION;
    float3 normal	:NORMAL;
    float2 uv	:TEXCOORD0;
    float3 tangent	:TANGENT;
};

struct PSInput
{
    float4 position	:SV_POSITION;
    float2 uv	:TEXCOORD0;
};

cbuffer cb0:register(b0)
{
    float4x4 g_mWorldViewProjection;
};

cbuffer cb1:register(b1)
{
    float3	g_light;
    float4   g_color;
};

struct Light
{
    float3		position;
    float4		color
}


StructuredBuffer<Light> lightbuffer : register(t0);


PSInput VSMain(VSInput input)
{
    PSInput result;

    result.position = mul(float4(input.position, 1.0f), g_mWorldViewProjection);
    result.uv = input.uv;

    return result;
}