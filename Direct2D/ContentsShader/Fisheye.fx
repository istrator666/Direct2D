// HLSL
Texture2D ScreenTexture : register(t0);
SamplerState samLinear : register(s0);

// 간단한 정점 셰이더 정의
float4 Fisheye_VS(float4 pos : POSITION) : SV_POSITION
{
    return pos; // 입력받은 정점 위치를 그대로 출력
}

float strength = 0.5f; // 왜곡의 강도, 높을수록 더 강한 피시아이 효과
float2 center = float2(0.5, 0.5); // 왜곡의 중심, 일반적으로 화면의 중앙

float4 Fisheye_PS(float4 pos : SV_POSITION, float2 uv : TEXCOORD) : SV_TARGET
{
    // uv 좌표와 중심 사이의 거리 계산
    float2 d = uv - center;
    float dist = length(d);
    
    // 왜곡 효과 적용
    float2 newUV = center + normalize(d) * sqrt(dist) * strength;
    
    // 새로운 UV 좌표를 사용해 텍스처 샘플링
    float4 color = ScreenTexture.Sample(samLinear, newUV);
    return color;
}
