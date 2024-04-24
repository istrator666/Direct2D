#pragma once


/// <summary>
/// 이미지 오더 순서
/// </summary>
enum class EOrderType
{
	Background,
	Overlay,
	Actor,
	CCTVActor,
	UI,
	CutscenBackground,
	Cutscene,

};

/// <summary>
/// 충돌(콜리전) 타입
/// </summary>
enum class EColType
{
	Mouse,
	LeftDoor,
	RightDoor,
	LeftLight,
	RightLight,
	ChangeBar,

};