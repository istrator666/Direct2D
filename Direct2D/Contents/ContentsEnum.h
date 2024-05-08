#pragma once

/// <summary>
/// 이미지 오더 순서
/// </summary>
enum class EOrderType
{
	Background,
	Actor,
	CCTVActor,
	UI,
	CutscenBackground,
	Cutscene,
	Overlay,
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

// 1A ShowStage
// 1B DningArea
// 1C PirateCove
// 2A WestHall
// 2B WHallCorner
// 3 SupplyCloset
// 4A EastHall
// 4B EHallCorner
// 5 BackStage
// 6 Kitchen
// 7 Restrooms

enum class ECamMap
{
	ShowStage,
	DiningArea,
	PirateCove,
	WestHall,
	WHallCorner,
	SupplyCloset,
	EastHall,
	EHallCorner,
	BackStage,
	Kitchen,
	Restrooms,
};

enum class EBonniePos
{
	ShowStage,
	DiningArea,
	WestHall,
	WHallCorner,
	SupplyCloset,
	BackStage,
	LeftOffice,
};

enum class EChicaPos
{
	ShowStage,
	DiningArea,
	EastHall,
	EHallCorner,
	Kitchen,
	Restrooms,
	RightOffice,
};

enum class EFoxyPos
{
	PirateCoveLv1,
	PirateCoveLv2,
	PirateCoveLv3,
	PirateCoveLv4,
	WestHall,
	LeftOffice,
};

enum class EFreddyPos
{
	ShowStage,
	DiningArea,

};

enum class EShowStage
{
	ShowStage_AllGone,
	ShowStage_BCGone,
	ShowStage_BCGone_Anomaly,
	ShowStage_BonnieGone,
	ShowStage_ChicaGone,
	ShowStage_Default,
	ShowStage_Default_Anomaly,
};

enum class EDiningArea
{
	DiningArea_Bonnie0,
	DiningArea_Bonnie1,
	DiningArea_Chica0,
	DiningArea_Chica1,
	DiningArea_Default,
	DiningArea_Freddy,
};

enum class EPirateCove
{
	PirateCove_Lv1,
	PirateCove_Lv2,
	PirateCove_Lv3,
	PirateCove_Lv4,
	PirateCove_Lv4_Anomaly,
};

enum class EWestHall
{
	WestHallA_Bonnie,
	WestHallA_Default,
	WestHallA_Lightsup,
};

enum class EWHallCorner
{
	WestHallB_Anomaly0,
	WestHallB_Anomaly1,
	WestHallB_Bonnie0,
	WestHallB_Bonnie1,
	WestHallB_Bonnie2,
	WestHallB_Default,
};

enum class ESupplyCloset
{
	SuppltCloset_Bonnie,
	SupplyCloset_Default,
};

enum class EEastHall
{
	EastHallA_Anomaly0,
	EastHallA_Anomaly1,
	EastHallA_Chica0,
	EastHallA_Chica1,
	EastHallA_Default,
	EastHallA_Freddy,
};

enum class EEHallCorner
{
	EastHallB_Anomaly0,
	EastHallB_Anomaly1,
	EastHallB_Anomaly2,
	EastHallB_Anomaly3,
	EastHallB_Chica0,
	EastHallB_Chica1,
	EastHallB_Chica2,
	EastHallB_Default,
	EastHallB_Freddy,
};

enum class EBackstage
{
	BackStage_Anomaly,
	BackStage_Bonnie0,
	BackStage_Bonnie1,
	BackStage_Default,
};

enum class EKitchen
{
	CameraDisabled,
	Kitchen,
};

enum class ERestRooms
{
	RestRooms_Chica0,
	RestRooms_Chica1,
	RestRooms_Default,
	RestRooms_Freddy,
};

enum class ETheOffice
{
	TheOffice,
	TheOffice_Bonnie,
	TheOffice_Chica,
};

enum class EIn
{

};