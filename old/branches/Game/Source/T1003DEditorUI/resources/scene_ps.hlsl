struct PSInput
{
    float4 position	:SV_POSITION;
    float2 uv	:TEXCOORD0;
};

Texture2D 	g_txDiffuse	:register(t0);
SamplerState 	g_sampler	:register(s0);

float4 PSMain(PSInput input) : SV_TARGET
{
    return g_txDiffuse.Sample(g_sampler, input.uv);
}