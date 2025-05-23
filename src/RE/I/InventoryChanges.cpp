#include "RE/I/InventoryChanges.h"

namespace RE
{
	InventoryChanges::InventoryChanges() :
		InventoryChanges(nullptr)
	{}

	InventoryChanges::InventoryChanges(TESObjectREFR* a_ref)
	{
		Ctor(a_ref);
	}

	InventoryChanges::~InventoryChanges()
	{
		Dtor();
	}

	void InventoryChanges::AddEntryData(InventoryEntryData* a_entry)
	{
		if (!entryList) {
			entryList = new std::remove_pointer_t<decltype(entryList)>;
		}

		entryList->push_front(a_entry);
		changed = true;
	}

	TESObjectARMO* InventoryChanges::GetArmorInSlot(std::int32_t a_slot)
	{
		using func_t = decltype(&InventoryChanges::GetArmorInSlot);
		static REL::Relocation<func_t> func{ RELOCATION_ID(15873, 16113) };
		return func(this, a_slot);
	}

	float InventoryChanges::GetInventoryWeight()
	{
		using func_t = decltype(&InventoryChanges::GetInventoryWeight);
		static REL::Relocation<func_t> func{ RELOCATION_ID(15883, 16123) };
		return func(this);
	}

	std::uint16_t InventoryChanges::GetNextUniqueID()
	{
		using func_t = decltype(&InventoryChanges::GetNextUniqueID);
		static REL::Relocation<func_t> func{ Offset::InventoryChanges::GetNextUniqueID };
		return func(this);
	}

	std::uint32_t InventoryChanges::GetWornMask()
	{
		using func_t = decltype(&InventoryChanges::GetWornMask);
		static REL::Relocation<func_t> func{ RELOCATION_ID(15806, 16044) };
		return func(this);
	}

	void InventoryChanges::RemoveFavorite(InventoryEntryData* a_entry, ExtraDataList* a_itemList)
	{
		using func_t = decltype(&InventoryChanges::RemoveFavorite);
		static REL::Relocation<func_t> func{ RELOCATION_ID(15859, 16099) };
		return func(this, a_entry, a_itemList);
	}

	ObjectRefHandle InventoryChanges::RemoveItem(TESObjectREFR* a_ref, TESBoundObject* a_item, std::int32_t a_count, ITEM_REMOVE_REASON a_reason, ExtraDataList* a_extraDataList, TESObjectREFR* a_moveToRef, const NiPoint3& a_dropLoc, TESObjectREFR* a_dropRef)
	{
		using func_t = decltype(&InventoryChanges::RemoveItem);
		static REL::Relocation<func_t> func{ RELOCATION_ID(15821, 16059) };
		return func(this, a_ref, a_item, a_count, a_reason, a_extraDataList, a_moveToRef, a_dropLoc, a_dropRef);
	}

	void InventoryChanges::RemoveAllItems(TESObjectREFR* a_ref, TESObjectREFR* a_moveToRef, bool a_stealing, bool a_keepOwnership, bool a_arg6)
	{
		using func_t = decltype(&InventoryChanges::RemoveAllItems);
		static REL::Relocation<func_t> func{ RELOCATION_ID(15878, 441567) };
		return func(this, a_ref, a_moveToRef, a_stealing, a_keepOwnership, a_arg6);
	}

	void InventoryChanges::SendContainerChangedEvent(ExtraDataList* a_itemExtraList, TESObjectREFR* a_fromRefr, TESForm* a_item, std::int32_t a_count)
	{
		using func_t = decltype(&InventoryChanges::SendContainerChangedEvent);
		static REL::Relocation<func_t> func{ Offset::InventoryChanges::SendContainerChangedEvent };
		return func(this, a_itemExtraList, a_fromRefr, a_item, a_count);
	}

	void InventoryChanges::SetFavorite(InventoryEntryData* a_entry, ExtraDataList* a_itemList)
	{
		using func_t = decltype(&InventoryChanges::SetFavorite);
		static REL::Relocation<func_t> func{ RELOCATION_ID(15858, 16098) };
		return func(this, a_entry, a_itemList);
	}

	void InventoryChanges::SetUniqueID(ExtraDataList* a_itemList, TESForm* a_oldForm, TESForm* a_newForm)
	{
		using func_t = decltype(&InventoryChanges::SetUniqueID);
		static REL::Relocation<func_t> func{ Offset::InventoryChanges::SetUniqueID };
		return func(this, a_itemList, a_oldForm, a_newForm);
	}

	void InventoryChanges::VisitInventory(IItemChangeVisitor& visitor)
	{
		using func_t = decltype(&InventoryChanges::VisitInventory);
		static REL::Relocation<func_t> func{ RELOCATION_ID(15855, 16095) };
		return func(this, visitor);
	}

	void InventoryChanges::VisitWornItems(IItemChangeVisitor& visitor)
	{
		using func_t = decltype(&InventoryChanges::VisitWornItems);
		static REL::Relocation<func_t> func{ RELOCATION_ID(15856, 16096) };
		return func(this, visitor);
	}

	void InventoryChanges::InitFromContainerExtra()
	{
		using func_t = decltype(&InventoryChanges::InitFromContainerExtra);
		static REL::Relocation<func_t> func{ RELOCATION_ID(15890, 16130) };
		return func(this);
	}

	void InventoryChanges::InitLeveledItems()
	{
		using func_t = decltype(&InventoryChanges::InitLeveledItems);
		static REL::Relocation<func_t> func{ RELOCATION_ID(15889, 16129) };
		return func(this);
	}

	void InventoryChanges::InitOutfitItems(BGSOutfit* a_outfit, std::uint16_t a_npcLevel)
	{
		using func_t = decltype(&InventoryChanges::InitOutfitItems);
		static REL::Relocation<func_t> func{ RELOCATION_ID(15833, 16072) };
		return func(this, a_outfit, a_npcLevel);
	}

	void InventoryChanges::InitScripts()
	{
		using func_t = decltype(&InventoryChanges::InitScripts);
		static REL::Relocation<func_t> func{ RELOCATION_ID(15829, 16068) };
		return func(this);
	}

	InventoryChanges* InventoryChanges::Ctor(TESObjectREFR* a_ref)
	{
		using func_t = decltype(&InventoryChanges::Ctor);
		static REL::Relocation<func_t> func{ RELOCATION_ID(15812, 16050) };
		return func(this, a_ref);
	}

	void InventoryChanges::Dtor()
	{
		using func_t = decltype(&InventoryChanges::Dtor);
		static REL::Relocation<func_t> func{ RELOCATION_ID(15813, 16051) };
		return func(this);
	}
}
