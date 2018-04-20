//Locomotor = {92612C46-F71F-11d1-AC9F-006008055BB5} 

#pragma once

#include <LocomotionClass.h>

enum class JumpjetMission
{
	Initialize = 0,
	Rise = 1,
	Idle = 2,
	Move = 3,
	Land = 4,
	FallDown = 5,
	AfterFalling = 6
};

class NOVTABLE JumpjetLocomotionClass : public LocomotionClass, public IPiggyback
{
public:
	//IUnknown
	virtual HRESULT __stdcall QueryInterface(REFIID iid, void** ppvObject) R0;
	virtual ULONG __stdcall AddRef() R0;
	virtual ULONG __stdcall Release() R0;

	//IPiggyback
	virtual HRESULT __stdcall Begin_Piggyback(ILocomotion* pointer) R0;
	virtual HRESULT __stdcall End_Piggyback(ILocomotion** pointer) R0;
	virtual bool __stdcall Is_Ok_To_End() R0;
	virtual HRESULT __stdcall Piggyback_CLSID(GUID* classid) R0;
	virtual bool __stdcall Is_Piggybacking() R0;

	//ILocomotion
	virtual bool __stdcall Is_Moving() R0;
	virtual CoordStruct* __stdcall Destination(CoordStruct* pcoord) R0;
	virtual bool __stdcall Process() R0;
	virtual void __stdcall Move_To(CoordStruct to) RX;
	virtual void __stdcall Stop_Moving() RX;
	virtual void __stdcall Do_Turn(DirStruct coord) RX;
	virtual Layer __stdcall In_Which_Layer() RT(Layer);
	virtual void __stdcall Mark_All_Occupation_Bits(int mark) RX;
	virtual void __stdcall ILocomotion_B8() RX;

	//IPersist
	virtual HRESULT __stdcall GetClassID(CLSID* pClassID) R0;

	//IPersistStream
	virtual HRESULT __stdcall Load(IStream* pStm) R0;
	virtual HRESULT __stdcall Save(IStream* pStm, BOOL fClearDirty) R0;

	//Destructor
	virtual ~JumpjetLocomotionClass() RX;

	//LocomotionClass
	virtual	int Size() R0;

	//JumpjetLocomotionClass
	//non-virtual
	bool HasMoveOrder() 
	{
		auto mission = this->NextMission;
		return mission == JumpjetMission::Move 
			|| mission == JumpjetMission::Rise 
			|| mission == JumpjetMission::Land;
	}

	//Constructor
	JumpjetLocomotionClass()
		: JumpjetLocomotionClass(noinit_t())
	{ JMP_THIS(0x54AC40); }

protected:
	explicit __forceinline JumpjetLocomotionClass(noinit_t)
		: LocomotionClass(noinit_t())
	{ }

	//===========================================================================
	//===== Properties ==========================================================
	//===========================================================================

public:
	int JumpjetTurnRate;
	int JumpjetSpeed;
	float JumpjetClimb;
	float JumpjetCrash;
	int JumpjetHeight;
	float JumpjetAccel;
	float JumpjetWobbles;
	int JumpjetDeviation;
	bool JumpjetNoWobbles;
	char gap_25[3];
	CoordStruct HeadingCoord;
	bool HasDestination;
	char gap_4D[3];
	JumpjetMission NextMission;
	FacingStruct LocomotionFacing;
	char gap_6C[4];
	double unknown_double_70;
	char field_78;
	char field_79;
	char gap_7A[2];
	ILocomotion* OldLocomotor;
	int CurrentHeight;
	char unknown84;
	char gap_85[3];
	int field_88;
	int field_8C;
	bool DestinationReached;
	bool unknown_bool_91;
	char gap_92[2];
	int field_94;

};
