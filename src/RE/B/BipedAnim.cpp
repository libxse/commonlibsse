#include "RE/B/BipedAnim.h"

#include "RE/N/NiAVObject.h"

namespace RE
{
	BipedAnim::~BipedAnim()
	{
		Dtor();
	}

	void BipedAnim::RemoveAllParts()
	{
		using func_t = decltype(&BipedAnim::RemoveAllParts);
		static REL::Relocation<func_t> func{ Offset::BipedAnim::RemoveAllParts };
		return func(this);
	}

	BIPOBJECT* BipedAnim::GetShieldObject()
	{
		using func_t = decltype(&BipedAnim::GetShieldObject);
		static REL::Relocation<func_t> func{ RELOCATION_ID(15518, 15695) };
		return func(this);
	}

	void BipedAnim::Dtor()
	{
		using func_t = decltype(&BipedAnim::Dtor);
		static REL::Relocation<func_t> func{ Offset::BipedAnim::Dtor };
		return func(this);
	}
}
