/*
	DiskLasers are the floating disks' purple lasers.
*/

#pragma once

#include <AbstractClass.h>

class LaserDrawClass;
class TechnoClass;
class WeaponTypeClass;

class NOVTABLE DiskLaserClass : public AbstractClass
{
public:
	static const AbstractType AbsID = AbstractType::DiskLaser;

	// static
	static DynamicVectorClass<DiskLaserClass*>* const Array;
	static const Point2D* Circle()
		{ return *reinterpret_cast<Point2D**>(0x8A0180); }
	/* each point from Circle()
	int ForX[16] = {    0,	 89,   169, 220,  240,  222,169, 93,   0, -89,-169,-220,-240,-222,-137,  -54 };
	int ForY[16] = { -240,-222,-169,  -93,	  0,	 89, 169,220,240,222,169,  93,     0,   -89,-196,-233 };
	*/
	//IPersist
	virtual HRESULT __stdcall GetClassID(CLSID* pClassID) R0;

	//IPersistStream
	virtual HRESULT __stdcall Load(IStream* pStm) R0;
	virtual HRESULT __stdcall Save(IStream* pStm,BOOL fClearDirty) R0;

	//Destructor
	virtual ~DiskLaserClass() RX;

	//AbstractClass
	virtual AbstractType WhatAmI() const RT(AbstractType);
	virtual int Size() const R0;

	//non-virtual
	void Fire(TechnoClass* pOwner, TechnoClass* pTarget, WeaponTypeClass* pWeapon, int nDamage)
		{ JMP_THIS(0x4A71A0); }

	void PointerGotInvalid(AbstractClass* pInvalid)
		{ JMP_THIS(0x4A7900); }

	//Constructor
	DiskLaserClass() noexcept
		: DiskLaserClass(noinit_t())
	{ JMP_THIS(0x4A7A30); }

protected:
	explicit __forceinline DiskLaserClass(noinit_t) noexcept
		: AbstractClass(noinit_t())
	{ }

	//===========================================================================
	//===== Properties ==========================================================
	//===========================================================================

public:

	TechnoClass* Owner;
	TechnoClass* Target;
	WeaponTypeClass* Weapon;
	int DrawRateCounter;//dec per update
	DWORD Facing;//0-15
	int DrawCounter;//inc per draw
	int Damage;
};
