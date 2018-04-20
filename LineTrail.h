#pragma once

#include <GeneralDefinitions.h>

struct LineTrailNode
{
	CoordStruct Position;
	DWORD unknown;
};

class LineTrail
{
public:
	static DynamicVectorClass<LineTrail*>* const Array;

	//Constructor, Destructor
	LineTrail()
		{ JMP_THIS(0x556A20); }

	~LineTrail()
	/*{
		if (auto pOwner = this->Owner) {
			pOwner->LineTrailer = nullptr;
			this->Owner = nullptr;
		}
	}*/ //since we uses ext data , so hook is needed now
		{ JMP_THIS(0x556B30); }

	void Draw()
		{ JMP_THIS(0x556B70); }

	void SetDecrement(int val)
		{ JMP_THIS(0x556B50); }
	//this function only called before a new game started
	static void DeleteAll()
		{ JMP_STD(0x556DF0); }

	//Ares WC added:
	const char*  get_ID() const
		{ return this->Owner->GetType() ? this->Owner->GetType()->ID : nullptr; }

	//===========================================================================
	//===== Properties ==========================================================
	//===========================================================================

public:

	ColorStruct Color;
	ObjectClass* Owner;
	DWORD Decrement;
	DWORD ActiveSlot;
	LineTrailNode Trails [32];
};
