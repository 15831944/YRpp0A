#include <AbstractClass.h>

class NOVTABLE FoggedObjectClass : public AbstractClass
{
	public:
	static const AbstractType AbsID = AbstractType::FoggedObject;

	static DynamicVectorClass<FoggedObjectClass *>* const Array;

	class DrawRecord
	{

	};

	//IPersistStream
	//Destructor
	virtual ~FoggedObjectClass() RX;

	virtual CellStruct* GetMapCoords(CellStruct* pUCell) const R0;

	CellStruct GetMapCoords() const {
		CellStruct ret;
		this->GetMapCoords(&ret);
		return ret;
	}

	//Constructor
	FoggedObjectClass() noexcept
		: AbstractClass(noinit_t())
		{ JMP_THIS(0x4D08B0); }

protected:
	explicit __forceinline FoggedObjectClass(noinit_t) noexcept
		: AbstractClass(noinit_t())
	{ }

	//===========================================================================
	//===== Properties ==========================================================
	//===========================================================================
public:
	int OverlayIndex;
	HouseClass* Owner;
	int field_2C;
	AbstractType CoveredAbstractType;
	CoordStruct Location;
	RectangleStruct Bound;
	/*int field_40;
	int field_44;
	int field_48;
	int field_4C;*/
	int Level;
	int field_54;
	int field_58;
	int DrawRecords;//vector ?
	int field_60;
	int field_64;
	char field_68;
	char field_69;
	char gap_6A[2];
	int field_6C;
	int field_70;
	char field_74;
	char gap_75[1];
	char field_76;
	char field_77;

};