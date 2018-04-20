/*
	Infantry
*/

#pragma once

#include <FootClass.h>
#include <InfantryTypeClass.h>

class NOVTABLE InfantryClass : public FootClass
{
public:
	static const AbstractType AbsID = AbstractType::Infantry;

	//Static
	static DynamicVectorClass<InfantryClass*>* const Array;

	//IPersist
	virtual HRESULT __stdcall GetClassID(CLSID* pClassID) R0;

	//Destructor
	virtual ~InfantryClass() RX;

	//AbstractClass
	virtual AbstractType WhatAmI() const RT(AbstractType);
	virtual int	Size() const R0;

	//ObjectClass
	virtual InfantryTypeClass* GetType() const override
		{ return this->Type; }

	//TechnoClass
	virtual InfantryTypeClass* GetTechnoType() const override
		{ return this->Type; }

	//InfantryClass
	virtual bool IsDeployed() const R0;
	virtual bool PlayAnim(Sequence index, bool force = false, bool randomStartFrame = false) R0;

	//non virtual
	void UpdateSequence()
	{ JMP_THIS(0x520AE0); }

	//Ares WC added
	bool UnderDeployState() const
	{
		auto sequenceAnim = this->SequenceAnim;
		/*return sequenceAnim == Sequence::Deploy
			|| sequenceAnim == Sequence::Deployed
			|| sequenceAnim == Sequence::DeployedFire
			|| sequenceAnim == Sequence::DeployedIdle;	*/
		//bellow is faster
		return sequenceAnim >= Sequence::Deploy && sequenceAnim <= Sequence::DeployedIdle;
	}

	bool PlayAnim(int index, bool force = false, bool randomStartFrame = false)
	{
		return this->PlayAnim(static_cast<Sequence>(index), force, randomStartFrame);
	}

	//InfantryClass::Update()->UpdatePanic()
	void UpdatePanic()
		{ JMP_THIS(0x5200B0); }
	//end

	//Constructor
	InfantryClass(InfantryTypeClass* pType, HouseClass* pOwner) noexcept
		: InfantryClass(noinit_t())
	{ JMP_THIS(0x517A50); }

protected:
	explicit __forceinline InfantryClass(noinit_t) noexcept
		: FootClass(noinit_t())
	{ }

	//===========================================================================
	//===== Properties ==========================================================
	//===========================================================================

public:

	InfantryTypeClass* Type;
	Sequence SequenceAnim; //which is currently playing
	TimerStruct unknown_Timer_6C8;
	DWORD          PanicDurationLeft; // set in ReceiveDamage on panicky units
	bool           PermanentBerzerk; // set by script action, not cleared anywhere
	bool           Technician;
	bool           unknown_bool_6DA;
	bool           Crawling;
	bool           unknown_bool_6DC;
	bool           unknown_bool_6DD;
	DWORD          unknown_6E0;
	bool           ShouldDeploy;
	BOOL           IsOnLand;//int unknown_int_6E8; used for enter/leave water sound play
	PROTECTED_PROPERTY(DWORD, unused_6EC); //??
};
