#pragma once

#include <wchar.h>

//class StartingSlotClass;


struct StartingSlotClass
{
	int HouseTypeIndex;
	PROTECTED_PROPERTY(char, field_4)
	PROTECTED_PROPERTY(BYTE, gap5[27])
	int ColorSchemeIndex;
	PROTECTED_PROPERTY(BYTE, gap24[28])
	int StartingCell;
	PROTECTED_PROPERTY(BYTE, gap44[28])
	int StartingAllies;
};


struct AISlotsStruct
{
	int AIDifficulties[8];
	StartingSlotClass* StartingSpots[8];
	int Colours[8];
	int Starts[8];
	int Teams[8];
};

class GameModeOptionsClass
{
public:
	// this is the same as SessionClass::Instance->Config
	static GameModeOptionsClass* const Instance;

	void Init()
	{ JMP_THIS(0x69B540); }

	int MPModeIndex;
	int ScenarioIndex;
	bool Bases;
	int Money;
	bool BridgeDestruction;
	bool Crates;
	bool ShortGame;
	bool SWAllowed;
	bool BuildOffAlly;
	int GameSpeed;
	bool MultiEngineer;
	int UnitCount;
	int AIPlayers;
	int AIDifficulty;
	AISlotsStruct AISlots;
	bool AlliesAllowed;
	bool HarvesterTruce;
	bool CTF;
	bool FogOfWar;
	bool MCVRedeploy;
	wchar_t MapDescription[45];
};
