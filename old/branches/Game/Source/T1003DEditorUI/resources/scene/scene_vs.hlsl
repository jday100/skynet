struct VSInput
{
    float3 position    : POSITION;
    float4 color : COLOR;
};

struct PSInput
{
    float4 position : SV_POSITION;
    float4 color : COLOR;
};

cbuffer cb0 : register(b0)
{
    float4x4 g_mWorldViewProjection;
};

PSInput VSMain(VSInput input)
{
    PSInput result;
    
    result.position = mul(float4(input.position, 1.0f), g_mWorldViewProjection);
    result.color = input.color;
    
    return result;
}


