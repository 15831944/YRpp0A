#pragma once

#include <TeamTypeClass.h>

class HouseClass;
class FootClass;
class CellClass;
class ScriptClass;
class TagClass;
class BuildingClass;
class BuildingTypeClass;

class NOVTABLE TeamClass : public AbstractClass
{
public:
	static const AbstractType AbsID = AbstractType::Team;

	//Static
	static DynamicVectorClass<TeamClass*>* const Array;

	//IPersist
	virtual HRESULT __stdcall GetClassID(CLSID* pClassID) R0;

	//IPersistStream
	virtual HRESULT __stdcall Load(IStream* pStm) R0;
	virtual HRESULT __stdcall Save(IStream* pStm,BOOL fClearDirty) R0;

	//Destructor
	virtual ~TeamClass() RX;

	// fills dest with all types needed to complete this team. each type is
	// included as often as it is needed.
	void GetTaskForceMissingMemberTypes(DynamicVectorClass<TechnoTypeClass *>& dest) const
		{ JMP_THIS(0x6EF4D0); }

	void LiberateMember(FootClass* pFoot, int idx=-1, byte count=0)
		{ JMP_THIS(0x6EA870); }

	void SetFocus(AbstractClass* pFocus)
		{ JMP_THIS(0x6E9050); }

	void AttackFocus() 
		{ JMP_THIS(0x6EB490); }

	//Ares WC added:
	//check whether the team will still heading to destination
	bool IsStillGathering() const
		{ JMP_THIS(0x6EBF50); }

	bool IsUnitRecruitable(FootClass *pUnit, int *pEntryIdx, bool forced)
		{ JMP_THIS(0x6EA610); }

	bool AddMember(FootClass *pNewMember, bool Forced= false) const
		{ JMP_THIS(0x6EA500); }

	bool AddCapturedMemeber(FootClass *pVictim)const
	{
		return  this->AddMember(pVictim, true);
	}//0x6EA4F0
		

	static BuildingClass* __fastcall PickUpSpecificBuildingTarget(
		BuildingTypeClass *pBldType, HouseClass *pEnemyHouse,
		FootClass *pAttacker, int AttackType, char OnlyTargetHouseEnemy)
		{ JMP_STD(0x6EEBD0); }
		
	//AbstractClass
	virtual AbstractType WhatAmI() const RT(AbstractType);
	virtual int Size() const R0;

	//Constructor
	TeamClass(TeamTypeClass* pType) noexcept
		: TeamClass(noinit_t())
	{ JMP_THIS(0x6E8A90); }

protected:
	explicit __forceinline TeamClass(noinit_t) noexcept
		: AbstractClass(noinit_t())
	{ }

	//===========================================================================
	//===== Properties ==========================================================
	//===========================================================================

public:

	TeamTypeClass* Type;
	ScriptClass*   CurrentScript;
	HouseClass*    Owner;
	HouseClass*    Target;
	CellClass*     SpawnCell;
	DWORD          unknown_38;
	AbstractClass* QueuedFocus;
	AbstractClass* Focus;
	int            unknown_44;
	int            TotalObjects;
	int            TotalThreatValue;
	int            CreationFrame;
	FootClass *    FirstUnit;
	TimerStruct GuardAreaTimer;
	TimerStruct SuspendTimer;
	TagClass*      Tag;
	bool           unknown_74;
	bool           unknown_75;
	bool           unknown_76;
	bool           unknown_77;

	bool           TeamIsFull;// unknown_78; - means current member amount equals taskforce count
	bool           unknown_79;
	bool           NeedsReinforce;// unknown_7A;
	bool           unknown_7B;

	bool           NeedsGathering;//unknown_7C;
	bool           NeedsToDisappear;
	bool           unknown_7E;
	bool           unknown_7F;

	bool           StepCompleted; // can proceed to the next step of the script
	bool           unknown_81;
	bool           unknown_82;
	bool           IsSuspended;

	bool           AchievedGreatSuccess; // executed script action 49, 0
	bool           unknown_85;
	bool           unknown_86;
	bool           unknown_87;

	int CountObjects [6]; // counts of each object specified in the Type
};
