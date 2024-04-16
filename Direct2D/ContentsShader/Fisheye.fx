// HLSL
Texture2D ScreenTexture : register(t0);
SamplerState samLinear : register(s0);

// ������ ���� ���̴� ����
float4 Fisheye_VS(float4 pos : POSITION) : SV_POSITION
{
    return pos; // �Է¹��� ���� ��ġ�� �״�� ���
}

float strength = 0.5f; // �ְ��� ����, �������� �� ���� �ǽþ��� ȿ��
float2 center = float2(0.5, 0.5); // �ְ��� �߽�, �Ϲ������� ȭ���� �߾�

float4 Fisheye_PS(float4 pos : SV_POSITION, float2 uv : TEXCOORD) : SV_TARGET
{
    // uv ��ǥ�� �߽� ������ �Ÿ� ���
    float2 d = uv - center;
    float dist = length(d);
    
    // �ְ� ȿ�� ����
    float2 newUV = center + normalize(d) * sqrt(dist) * strength;
    
    // ���ο� UV ��ǥ�� ����� �ؽ�ó ���ø�
    float4 color = ScreenTexture.Sample(samLinear, newUV);
    return color;
}
