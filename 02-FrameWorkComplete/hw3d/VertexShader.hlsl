struct v2f
{
    float3 color : COLOR;
    float4 pos : SV_Position;
};

v2f main( float2 pos : POSITION , float3 color : COLOR)
{
    v2f o;
    o.pos = float4(pos, 0, 1.0f);
    o.color = color;
    return o;
}