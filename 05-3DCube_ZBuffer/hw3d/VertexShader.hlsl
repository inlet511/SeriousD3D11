struct v2f
{
    float3 color : COLOR;
    float4 pos : SV_Position;
};

cbuffer CBuf
{
    matrix transform;
};

v2f main( float3 pos : POSITION , float3 color : COLOR)
{
    v2f o;
    o.pos = mul(float4(pos, 1.0f), transform);
    o.color = color;
    return o;
}