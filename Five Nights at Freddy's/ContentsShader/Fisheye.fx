struct FEngineVertex
{
    float4 POSITION : POSITION;
    float4 TEXCOORD : TEXCOORD;
};

//

struct ImageVSOutPut
{
    float4 POSITION : SV_POSITION;
    float4 TEXCOORD : TEXCOORD;
};


ImageVSOutPut Fisheye_VS(FEngineVertex _Input)
{
    ImageVSOutPut Out = (ImageVSOutPut) 0;
    Out.POSITION = _Input.POSITION;
    Out.TEXCOORD = _Input.TEXCOORD;
    return Out;
}

struct ImagePSOutPut
{
    float4 COLOR : SV_Target0;
};

Texture2D Image : register(t0); 

SamplerState Image_Sampler : register(s0);

ImagePSOutPut Fisheye_PS(ImageVSOutPut _Input)
{
    ImagePSOutPut Out = (ImagePSOutPut) 0;
    
    float PX = distance(_Input.TEXCOORD.x, 0.5f);
    float PY = distance(_Input.TEXCOORD.y, 0.5f);

    float Offset = (PX * 0.2f) * PY;
    
    float Dir = 0.0f;
    if (_Input.TEXCOORD.y <= 0.5f)
    {
        Dir = 1.0f;
    } else
    {
        Dir = -1.0f;
    }
    
    float2 UV = float2(_Input.TEXCOORD.x, _Input.TEXCOORD.y + PX * (Offset * 3.0f * Dir));
    
    Out.COLOR = Image.Sample(Image_Sampler, UV);
    
    return Out;
}