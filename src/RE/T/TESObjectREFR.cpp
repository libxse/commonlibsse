#include "RE/T/TESObjectREFR.h"

#include "RE/B/BGSDefaultObjectManager.h"
#include "RE/B/BGSKeyword.h"
#include "RE/B/BSFixedString.h"
#include "RE/E/ExtraCharge.h"
#include "RE/E/ExtraContainerChanges.h"
#include "RE/E/ExtraDroppedItemList.h"
#include "RE/E/ExtraEnchantment.h"
#include "RE/E/ExtraFlags.h"
#include "RE/E/ExtraLock.h"
#include "RE/E/ExtraOwnership.h"
#include "RE/E/ExtraReferenceHandle.h"
#include "RE/E/ExtraTextDisplayData.h"
#include "RE/F/FormTraits.h"
#include "RE/I/InventoryChanges.h"
#include "RE/I/InventoryEntryData.h"
#include "RE/M/Misc.h"
#include "RE/N/NiAVObject.h"
#include "RE/N/NiControllerManager.h"
#include "RE/N/NiControllerSequence.h"
#include "RE/N/NiMath.h"
#include "RE/N/NiTimeController.h"
#include "RE/T/TESContainer.h"
#include "RE/T/TESDataHandler.h"
#include "RE/T/TESEnchantableForm.h"
#include "RE/T/TESFaction.h"
#include "RE/T/TESNPC.h"
#include "SKSE/Logger.h"

namespace RE
{
	ObjectRefHandle TESObjectREFR::CreateReference(ObjectRefHandle& a_handleOut, FormType a_formType, bool a_addActorToProcessList)
	{
		using func_t = decltype(&TESObjectREFR::CreateReference);
		static REL::Relocation<func_t> func{ RELOCATION_ID(19142, 19544) };
		return func(a_handleOut, a_formType, a_addActorToProcessList);
	}

	NiPointer<TESObjectREFR> TESObjectREFR::LookupByHandle(RefHandle a_refHandle)
	{
		NiPointer<TESObjectREFR> ref;
		LookupReferenceByHandle(a_refHandle, ref);
		return ref;
	}

	bool TESObjectREFR::LookupByHandle(RefHandle a_refHandle, NiPointer<TESObjectREFR>& a_refrOut)
	{
		return LookupReferenceByHandle(a_refHandle, a_refrOut);
	}

	TESObjectREFR* TESObjectREFR::FindReferenceFor3D(NiAVObject* a_object3D)
	{
		using func_t = decltype(&TESObjectREFR::FindReferenceFor3D);
		static REL::Relocation<func_t> func{ Offset::TESObjectREFR::FindReferenceFor3D };
		return func(a_object3D);
	}

	bool TESObjectREFR::ActivateRef(TESObjectREFR* a_activator, uint8_t a_arg2, TESBoundObject* a_object, int32_t a_count, bool a_defaultProcessingOnly)
	{
		using func_t = decltype(&TESObjectREFR::ActivateRef);
		static REL::Relocation<func_t> func{ RELOCATION_ID(19369, 20221) };
		return func(this, a_activator, a_arg2, a_object, a_count, a_defaultProcessingOnly);
	}

	REFR_LOCK* TESObjectREFR::AddLock()
	{
		using func_t = decltype(&TESObjectREFR::AddLock);
		static REL::Relocation<func_t> func{ RELOCATION_ID(19816, 20221) };
		return func(this);
	}

	DoorTeleportData* TESObjectREFR::AddTeleport()
	{
		using func_t = decltype(&TESObjectREFR::AddTeleport);
		static REL::Relocation<func_t> func{ RELOCATION_ID(19809, 20214) };
		return func(this);
	}

	ModelReferenceEffect* TESObjectREFR::ApplyArtObject(BGSArtObject* a_artObject, float a_duration, TESObjectREFR* a_facingRef, bool a_faceTarget, bool a_attachToCamera, NiAVObject* a_attachNode, bool a_interfaceEffect)
	{
		using func_t = decltype(&TESObjectREFR::ApplyArtObject);
		static REL::Relocation<func_t> func{ RELOCATION_ID(22289, 22769) };
		return func(this, a_artObject, a_duration, a_facingRef, a_faceTarget, a_attachToCamera, a_attachNode, a_interfaceEffect);
	}

	ShaderReferenceEffect* TESObjectREFR::ApplyEffectShader(TESEffectShader* a_effectShader, float a_duration, TESObjectREFR* a_facingRef, bool a_faceTarget, bool a_attachToCamera, NiAVObject* a_attachNode, bool a_interfaceEffect)
	{
		using func_t = decltype(&TESObjectREFR::ApplyEffectShader);
		static REL::Relocation<func_t> func{ RELOCATION_ID(19446, 19872) };
		return func(this, a_effectShader, a_duration, a_facingRef, a_faceTarget, a_attachToCamera, a_attachNode, a_interfaceEffect);
	}

	bool TESObjectREFR::CanBeMoved()
	{
		using func_t = decltype(&TESObjectREFR::CanBeMoved);
		static REL::Relocation<func_t> func{ RELOCATION_ID(19244, 19670) };
		return func(this);
	}

	ObjectRefHandle TESObjectREFR::CreateRefHandle()
	{
		return GetHandle();
	}

	void TESObjectREFR::DoTrap(TrapData& a_data)
	{
		return DoTrap1(a_data);
	}

	void TESObjectREFR::DoTrap(TrapEntry* a_trap, TargetEntry* a_target)
	{
		return DoTrap2(a_trap, a_target);
	}

	void TESObjectREFR::Enable(bool a_resetInventory)
	{
		using func_t = decltype(&TESObjectREFR::Enable);
		static REL::Relocation<func_t> func{ RELOCATION_ID(19373, 19800) };
		return func(this, a_resetInventory);
	}

	NiAVObject* TESObjectREFR::Get3D() const
	{
		return Get3D2();
	}

	NiAVObject* TESObjectREFR::Get3D(bool a_firstPerson) const
	{
		return Get3D1(a_firstPerson);
	}

	TESNPC* TESObjectREFR::GetActorOwner()
	{
		auto xOwnership = extraList.GetByType<ExtraOwnership>();
		if (xOwnership && xOwnership->owner && xOwnership->owner->Is(FormType::NPC)) {
			return static_cast<TESNPC*>(xOwnership->owner);
		} else {
			return nullptr;
		}
	}

	NiPoint3 TESObjectREFR::GetAngle() const
	{
		return data.angle;
	}

	float TESObjectREFR::GetAngleX() const
	{
		return data.angle.x;
	}

	float TESObjectREFR::GetAngleY() const
	{
		return data.angle.y;
	}

	float TESObjectREFR::GetAngleZ() const
	{
		return data.angle.z;
	}

	float TESObjectREFR::GetBaseHeight() const
	{
		auto height = static_cast<float>(refScale) / 100.0F;
		auto obj = GetObjectReference();
		auto npc = obj ? obj->As<TESNPC>() : nullptr;
		if (npc) {
			height *= npc->GetHeight();
		}
		return height;
	}

	TESBoundObject* TESObjectREFR::GetBaseObject()
	{
		return data.objectReference;
	}

	const TESBoundObject* TESObjectREFR::GetBaseObject() const
	{
		return data.objectReference;
	}

	const BSTSmartPointer<BipedAnim>& TESObjectREFR::GetBiped() const
	{
		return GetBiped2();
	}

	const BSTSmartPointer<BipedAnim>& TESObjectREFR::GetBiped(bool a_firstPerson) const
	{
		return GetBiped1(a_firstPerson);
	}

	std::uint16_t TESObjectREFR::GetCalcLevel(bool a_adjustLevel) const
	{
		using func_t = decltype(&TESObjectREFR::GetCalcLevel);
		static REL::Relocation<func_t> func{ RELOCATION_ID(19800, 20205) };
		return func(this, a_adjustLevel);
	}

	TESContainer* TESObjectREFR::GetContainer() const
	{
		auto obj = GetObjectReference();
		return obj ? obj->As<TESContainer>() : nullptr;
	}

	BGSLocation* TESObjectREFR::GetCurrentLocation() const
	{
		using func_t = decltype(&TESObjectREFR::GetCurrentLocation);
		static REL::Relocation<func_t> func{ RELOCATION_ID(19385, 19812) };
		return func(this);
	}

	const char* TESObjectREFR::GetDisplayFullName()
	{
		using func_t = decltype(&TESObjectREFR::GetDisplayFullName);
		static REL::Relocation<func_t> func{ Offset::TESObjectREFR::GetDisplayFullName };
		return func(this);
	}

	float TESObjectREFR::GetDistance(TESObjectREFR* a_other, bool a_disabledRefs, bool a_ignoreWorldspace) const
	{
		using func_t = decltype(&TESObjectREFR::GetDistance);
		static REL::Relocation<func_t> func{ RELOCATION_ID(19396, 19823) };
		return func(this, a_other, a_disabledRefs, a_ignoreWorldspace);
	}

	auto TESObjectREFR::GetDroppedInventory()
		-> InventoryDropMap
	{
		return GetDroppedInventory([]([[maybe_unused]] TESBoundObject&) -> bool {
			return true;
		});
	}

	auto TESObjectREFR::GetDroppedInventory(std::function<bool(TESBoundObject&)> a_filter)
		-> InventoryDropMap
	{
		using container_t = InventoryDropMap::mapped_type::second_type;

		InventoryDropMap results;

		auto xDrop = extraList.GetByType<ExtraDroppedItemList>();
		if (!xDrop) {
			return results;
		}

		for (auto& handle : xDrop->droppedItemList) {
			auto ref = handle.get();
			if (!ref) {
				continue;
			}

			auto object = ref->GetObjectReference();
			if (!object || !a_filter(*object)) {
				continue;
			}

			auto count = ref->extraList.GetCount();
			auto it = results.find(object);
			if (it != results.end()) {
				it->second.first += count;
				it->second.second.push_back(handle);
			} else {
				auto mapped = std::make_pair(count, container_t());
				mapped.second.push_back(handle);
				auto insIt = results.emplace(object, std::move(mapped));
				assert(insIt.second);
			}
		}

		return results;
	}

	BGSEncounterZone* TESObjectREFR::GetEncounterZone() const
	{
		using func_t = decltype(&TESObjectREFR::GetEncounterZone);
		static REL::Relocation<func_t> func{ RELOCATION_ID(19797, 20202) };
		return func(this);
	}

	BGSLocation* TESObjectREFR::GetEditorLocation() const
	{
		return GetEditorLocation1();
	}

	bool TESObjectREFR::GetEditorLocation(NiPoint3& a_outPos, NiPoint3& a_outRot, TESForm*& a_outWorldOrCell, TESObjectCELL* a_fallback)
	{
		return GetEditorLocation2(a_outPos, a_outRot, a_outWorldOrCell, a_fallback);
	}

	EnchantmentItem* TESObjectREFR::GetEnchantment() const
	{
		auto xEnch = extraList.GetByType<ExtraEnchantment>();
		if (xEnch && xEnch->enchantment) {
			return xEnch->enchantment;
		}

		auto obj = GetObjectReference();
		if (obj) {
			auto ench = obj->As<TESEnchantableForm>();
			if (ench) {
				return ench->formEnchanting;
			}
		}

		return nullptr;
	}

	std::optional<double> TESObjectREFR::GetEnchantmentCharge() const
	{
		std::optional<double> result;
		auto                  obj = GetObjectReference();
		auto                  ench = obj ? obj->As<TESEnchantableForm>() : nullptr;
		if (ench && ench->formEnchanting && ench->amountofEnchantment != 0) {
			result.emplace(100.0);
		}

		auto xCharge = extraList.GetByType<ExtraCharge>();
		auto xEnch = extraList.GetByType<ExtraEnchantment>();
		if (xEnch && xEnch->enchantment && xEnch->charge != 0) {
			if (xCharge) {
				result.emplace((static_cast<double>(xCharge->charge) /
								   static_cast<double>(xEnch->charge)) *
							   100.0);
			} else {
				result.emplace(100.0);
			}
		} else if (xCharge && ench && ench->formEnchanting && ench->amountofEnchantment != 0) {
			result.emplace((static_cast<double>(xCharge->charge) /
							   static_cast<double>(ench->amountofEnchantment)) *
						   100.0);
		}

		return result;
	}

	TESFaction* TESObjectREFR::GetFactionOwner()
	{
		auto xOwnership = extraList.GetByType<ExtraOwnership>();
		if (xOwnership && xOwnership->owner && xOwnership->owner->Is(FormType::Faction)) {
			return static_cast<TESFaction*>(xOwnership->owner);
		} else {
			return nullptr;
		}
	}

	ObjectRefHandle TESObjectREFR::GetHandle()
	{
		return ObjectRefHandle(this);
	}

	float TESObjectREFR::GetHeadingAngle(const NiPoint3& a_pos, bool a_abs)
	{
		float theta = NiFastATan2(a_pos.x - GetPositionX(), a_pos.y - GetPositionY());
		float heading = rad_to_deg(theta - GetAngleZ());

		if (heading < -180.0f) {
			heading += 360.0f;
		}

		if (heading > 180.0f) {
			heading -= 360.0f;
		}

		return a_abs ? NiAbs(heading) : heading;
	}

	float TESObjectREFR::GetHeight() const
	{
		const auto min = GetBoundMin();
		const auto max = GetBoundMax();
		const auto diff = max.z - min.z;
		const auto height = GetBaseHeight() * diff;

		return height;
	}
	auto TESObjectREFR::GetInventory()
		-> InventoryItemMap
	{
		return GetInventory(DEFAULT_INVENTORY_FILTER, false);
	}

	auto TESObjectREFR::GetInventory(std::function<bool(TESBoundObject&)> a_filter, bool a_noInit)
		-> InventoryItemMap
	{
		InventoryItemMap results;

		auto invChanges = GetInventoryChanges(a_noInit);
		if (invChanges && invChanges->entryList) {
			for (auto& entry : *invChanges->entryList) {
				if (entry && entry->object && a_filter(*entry->object)) {
					[[maybe_unused]] auto it =
						results.emplace(
							entry->object,
							std::make_pair(
								entry->countDelta,
								std::make_unique<InventoryEntryData>(*entry)));
					assert(it.second);
				}
			}
		}

		auto container = GetContainer();
		if (container) {
			const auto ignore = [&](TESBoundObject* a_object) {
				const auto it = results.find(a_object);
				const auto entryData =
					it != results.end() ?
						it->second.second.get() :
						nullptr;
				return entryData ? entryData->IsLeveled() : false;
			};

			container->ForEachContainerObject([&](ContainerObject& a_entry) {
				auto obj = a_entry.obj;
				if (obj && !ignore(obj) && a_filter(*obj)) {
					auto it = results.find(obj);
					if (it == results.end()) {
						[[maybe_unused]] auto insIt =
							results.emplace(
								obj,
								std::make_pair(
									a_entry.count,
									std::make_unique<InventoryEntryData>(obj, 0)));
						assert(insIt.second);
					} else {
						it->second.first += a_entry.count;
					}
				}
				return BSContainer::ForEachResult::kContinue;
			});
		}

		return results;
	}

	std::int32_t TESObjectREFR::GetInventoryCount(bool a_noInit)
	{
		auto         counts = GetInventoryCounts(DEFAULT_INVENTORY_FILTER, a_noInit);
		std::int32_t total = 0;
		for (auto& elem : counts) {
			total += elem.second;
		}
		return total;
	}

	auto TESObjectREFR::GetInventoryCounts()
		-> InventoryCountMap
	{
		return GetInventoryCounts(DEFAULT_INVENTORY_FILTER, false);
	}

	auto TESObjectREFR::GetInventoryCounts(std::function<bool(TESBoundObject&)> a_filter, bool a_noInit)
		-> InventoryCountMap
	{
		auto              itemMap = GetInventory(std::move(a_filter), a_noInit);
		InventoryCountMap results;
		for (const auto& [key, value] : itemMap) {
			results[key] = value.first;
		}
		return results;
	}

	// this does not behave like Skyrim's implementation; Skyrim's does not attempt to initialize the container.
	// which is why we have to add "no_init" here if we don't want that to happen.
	InventoryChanges* TESObjectREFR::GetInventoryChanges(bool a_noInit)
	{
		if (!extraList.HasType<ExtraContainerChanges>()) {
			if (a_noInit) {
				return nullptr;
			}
			if (!InitInventoryIfRequired()) {
				ForceInitInventoryChanges();
			}
		}

		auto xContChanges = extraList.GetByType<ExtraContainerChanges>();
		return xContChanges ? xContChanges->changes : nullptr;
	}

	TESObjectREFR* TESObjectREFR::GetLinkedRef(BGSKeyword* a_keyword)
	{
		return extraList.GetLinkedRef(a_keyword);
	}

	REFR_LOCK* TESObjectREFR::GetLock() const
	{
		using func_t = decltype(&TESObjectREFR::GetLock);
		static REL::Relocation<func_t> func{ Offset::TESObjectREFR::GetLock };
		return func(this);
	}

	LOCK_LEVEL TESObjectREFR::GetLockLevel() const
	{
		auto state = GetLock();
		return state ? state->GetLockLevel(this) : LOCK_LEVEL::kUnlocked;
	}

	const char* TESObjectREFR::GetName() const
	{
		auto obj = GetObjectReference();
		return obj ? obj->GetName() : "";
	}

	NiAVObject* TESObjectREFR::GetNodeByName(const BSFixedString& a_nodeName)
	{
		auto node = Get3D();
		return node ? node->GetObjectByName(a_nodeName) : nullptr;
	}

	TESForm* TESObjectREFR::GetOwner() const
	{
		using func_t = decltype(&TESObjectREFR::GetOwner);
		static REL::Relocation<func_t> func{ Offset::TESObjectREFR::GetOwner };
		return func(this);
	}

	float TESObjectREFR::GetScale() const
	{
		using func_t = decltype(&TESObjectREFR::GetScale);
		static REL::Relocation<func_t> func{ RELOCATION_ID(19238, 19664) };
		return func(this);
	}

	NiControllerSequence* TESObjectREFR::GetSequence(std::string_view a_name) const
	{
		auto node = Get3D();
		if (!node) {
			return nullptr;
		}

		auto controller = node->GetControllers();
		if (!controller) {
			return nullptr;
		}

		auto manager = controller->AsNiControllerManager();
		return manager ? manager->GetSequenceByName(a_name) : nullptr;
	}

	std::uint32_t TESObjectREFR::GetStealValue(const InventoryEntryData* a_entryData, std::uint32_t a_numItems, bool a_useMult) const
	{
		using func_t = decltype(&TESObjectREFR::GetStealValue);
		static REL::Relocation<func_t> func{ Offset::TESObjectREFR::GetStealValue };
		return func(this, a_entryData, a_numItems, a_useMult);
	}

	float TESObjectREFR::GetSubmergeLevel(float a_zPos, TESObjectCELL* a_cell) const
	{
		auto waterHeight = !a_cell || a_cell == parentCell ? GetWaterHeight() : a_cell->GetExteriorWaterHeight();

		if (waterHeight == -NI_INFINITY && a_cell) {
			waterHeight = a_cell->GetExteriorWaterHeight();
		}

		if (waterHeight <= a_zPos) {
			return 0.0f;
		}

		return std::fminf((waterHeight - a_zPos) / GetHeight(), 1.0f);
	}

	void TESObjectREFR::GetTransform(NiTransform& a_transform) const
	{
		using func_t = decltype(&TESObjectREFR::GetTransform);
		static REL::Relocation<func_t> func{ RELOCATION_ID(19326, 19753) };
		return func(this, a_transform);
	}

	float TESObjectREFR::GetWaterHeight() const
	{
		float waterHeight = -NI_INFINITY;

		if (loadedData) {
			waterHeight = loadedData->relevantWaterHeight;
			if (waterHeight != -NI_INFINITY) {
				return waterHeight;
			}
		}

		return parentCell ? parentCell->GetExteriorWaterHeight() : waterHeight;
	}

	float TESObjectREFR::GetWeight() const
	{
		auto obj = GetObjectReference();
		return obj ? obj->GetWeight() : 0.0F;
	}

	float TESObjectREFR::GetWeightInContainer()
	{
		using func_t = decltype(&TESObjectREFR::GetWeightInContainer);
		static REL::Relocation<func_t> func{ RELOCATION_ID(19277, 19703) };
		return func(this);
	}

	TESWorldSpace* TESObjectREFR::GetWorldspace() const
	{
		auto cell = parentCell;
		if (!cell) {
			cell = GetSaveParentCell();
		}

		if (cell && cell->IsExteriorCell()) {
			return cell->worldSpace;
		} else {
			return nullptr;
		}
	}

	bool TESObjectREFR::HasCollision() const
	{
		return (GetFormFlags() & RecordFlags::kCollisionsDisabled) == 0;
	}

	bool TESObjectREFR::HasContainer() const
	{
		return GetContainer() != nullptr;
	}

	bool TESObjectREFR::HasKeyword(const BGSKeyword* a_keyword) const
	{
		return HasKeywordHelper(a_keyword);
	}

	bool TESObjectREFR::HasKeywordInArray(const std::vector<BGSKeyword*>& a_keywords, bool a_matchAll) const
	{
		bool hasKeyword = false;

		for (const auto& keyword : a_keywords) {
			hasKeyword = keyword && HasKeyword(keyword);
			if ((a_matchAll && !hasKeyword) || hasKeyword) {
				break;
			}
		}

		return hasKeyword;
	}

	bool TESObjectREFR::HasKeywordInList(BGSListForm* a_keywordList, bool a_matchAll) const
	{
		if (!a_keywordList) {
			return false;
		}

		bool hasKeyword = false;

		a_keywordList->ForEachForm([&](TESForm* a_form) {
			const auto keyword = a_form->As<BGSKeyword>();
			hasKeyword = keyword && HasKeyword(keyword);
			if ((a_matchAll && !hasKeyword) || hasKeyword) {
				return BSContainer::ForEachResult::kStop;
			}
			return BSContainer::ForEachResult::kContinue;
		});

		return hasKeyword;
	}

	bool TESObjectREFR::HasKeywordWithType(DEFAULT_OBJECT keywordType) const
	{
		auto dobj = BGSDefaultObjectManager::GetSingleton();
		if (!dobj) {
			return false;
		}

		auto keyword = dobj->GetObject<BGSKeyword>(keywordType);
		return keyword ? HasKeyword(keyword) : false;
	}

	bool TESObjectREFR::HasQuestObject() const
	{
		using func_t = decltype(&TESObjectREFR::HasQuestObject);
		static REL::Relocation<func_t> func{ RELOCATION_ID(19201, 19627) };
		return func(this);
	}

	void TESObjectREFR::InitChildActivates(TESObjectREFR* a_actionRef)
	{
		using func_t = decltype(&TESObjectREFR::InitChildActivates);
		static REL::Relocation<func_t> func{ RELOCATION_ID(19857, 20264) };
		return func(this, a_actionRef);
	}

	bool TESObjectREFR::InitInventoryIfRequired(bool a_ignoreContainerExtraData)
	{
		using func_t = decltype(&TESObjectREFR::InitInventoryIfRequired);
		static REL::Relocation<func_t> func{ Offset::TESObjectREFR::InitInventoryIfRequired };
		return func(this, a_ignoreContainerExtraData);
	}

	bool TESObjectREFR::Is3DLoaded() const
	{
		return Get3D() != nullptr;
	}

	bool TESObjectREFR::IsActivationBlocked() const
	{
		auto xFlags = extraList.GetByType<ExtraFlags>();
		return xFlags && xFlags->IsActivationBlocked();
	}

	bool TESObjectREFR::IsAnimal() const
	{
		return HasKeywordWithType(DEFAULT_OBJECT::kKeywordAnimal);
	}

	bool TESObjectREFR::IsAnOwner(const Actor* a_testOwner, bool a_useFaction, bool a_requiresOwner) const
	{
		using func_t = decltype(&TESObjectREFR::IsAnOwner);
		static REL::Relocation<func_t> func{ RELOCATION_ID(19805, 20210) };
		return func(this, a_testOwner, a_useFaction, a_requiresOwner);
	}

	bool TESObjectREFR::IsCrimeToActivate()
	{
		using func_t = decltype(&TESObjectREFR::IsCrimeToActivate);
		static REL::Relocation<func_t> func{ RELOCATION_ID(19400, 19827) };
		return func(this);
	}

	bool TESObjectREFR::IsDisabled() const
	{
		return (GetFormFlags() & RecordFlags::kInitiallyDisabled) != 0;
	}

	bool TESObjectREFR::IsDragon() const
	{
		return HasKeywordWithType(DEFAULT_OBJECT::kKeywordDragon);
	}

	bool TESObjectREFR::IsEnchanted() const
	{
		auto xEnch = extraList.GetByType<ExtraEnchantment>();
		if (xEnch && xEnch->enchantment) {
			return true;
		}

		auto obj = GetObjectReference();
		if (obj) {
			auto ench = obj->As<TESEnchantableForm>();
			if (ench && ench->formEnchanting) {
				return true;
			}
		}

		return false;
	}

	bool TESObjectREFR::IsHorse() const
	{
		return HasKeywordWithType(DEFAULT_OBJECT::kKeywordHorse);
	}

	bool TESObjectREFR::IsHumanoid() const
	{
		return HasKeywordWithType(DEFAULT_OBJECT::kKeywordNPC);
	}

	bool TESObjectREFR::IsInitiallyDisabled() const
	{
		return (GetFormFlags() & RecordFlags::kInitiallyDisabled) != 0;
	}

	bool TESObjectREFR::IsJewelry() const
	{
		return HasKeywordWithType(DEFAULT_OBJECT::kKeywordJewelry);
	}

	bool TESObjectREFR::IsInWater() const
	{
		return GetWaterHeight() > GetPositionZ();
	}

	bool TESObjectREFR::IsLocked() const
	{
		return GetLockLevel() != LOCK_LEVEL::kUnlocked;
	}

	bool TESObjectREFR::IsMarkedForDeletion() const
	{
		return (GetFormFlags() & RecordFlags::kDeleted) != 0;
	}

	bool TESObjectREFR::IsOffLimits()
	{
		return IsCrimeToActivate();
	}

	bool TESObjectREFR::IsPersistent() const
	{
		return (GetFormFlags() & RecordFlags::kPersistent) != 0;
	}

	bool TESObjectREFR::IsPointSubmergedMoreThan(const NiPoint3& a_pos, TESObjectCELL* a_cell, const float a_waterLevel) const
	{
		return GetSubmergeLevel(a_pos.z, a_cell) >= a_waterLevel;
	}

	void TESObjectREFR::MoveTo(TESObjectREFR* a_target)
	{
		assert(a_target);

		auto handle = a_target->GetHandle();
		MoveTo_Impl(handle, a_target->GetParentCell(), a_target->GetWorldspace(), a_target->GetPosition(), a_target->data.angle);
	}

	bool TESObjectREFR::MoveToNode(TESObjectREFR* a_target, const BSFixedString& a_nodeName)
	{
		assert(a_target);
		auto node = a_target->Get3D();
		if (!node) {
			REX::DEBUG("Cannot move the target because it does not have 3D");
			return false;
		}

		auto object = node->GetObjectByName(a_nodeName);
		if (!object) {
			REX::DEBUG("Target does not have a node named {}", a_nodeName.c_str());
			return false;
		}

		return MoveToNode(a_target, object);
	}

	bool TESObjectREFR::MoveToNode(TESObjectREFR* a_target, NiAVObject* a_node)
	{
		assert(a_target && a_node);
		auto&    position = a_node->world.translate;
		NiPoint3 rotation;
		a_node->world.rotate.ToEulerAnglesXYZ(rotation);
		auto handle = a_target->GetHandle();
		MoveTo_Impl(handle, a_target->GetParentCell(), GetWorldspace(), position, rotation);
		return true;
	}

	bool TESObjectREFR::NameIncludes(std::string_view a_word) const
	{
		BSFixedString name = GetName();
		return name.contains(a_word);
	}

	void TESObjectREFR::OpenContainer(std::int32_t a_openType) const
	{
		using func_t = decltype(&TESObjectREFR::OpenContainer);
		static REL::Relocation<func_t> func{ RELOCATION_ID(50211, 51140) };
		func(this, a_openType);
	}

	NiPointer<TESObjectREFR> TESObjectREFR::PlaceObjectAtMe(TESBoundObject* a_baseToPlace, bool a_forcePersist) const
	{
		const auto handle = TESDataHandler::GetSingleton()->CreateReferenceAtLocation(a_baseToPlace, GetPosition(), GetAngle(), GetParentCell(), GetWorldspace(), nullptr, nullptr, ObjectRefHandle(), a_forcePersist, true);
		return handle.get();
	}

	void TESObjectREFR::PlayAnimation(std::string_view a_from, std::string_view a_to)
	{
		auto node = Get3D();
		if (!node) {
			return;
		}

		auto controller = node->GetControllers();
		if (!controller) {
			return;
		}

		auto manager = controller->AsNiControllerManager();
		if (!manager) {
			return;
		}

		auto fromSeq = manager->GetSequenceByName(a_from);
		auto toSeq = manager->GetSequenceByName(a_to);
		if (!fromSeq || !toSeq) {
			return;
		}

		PlayAnimation(manager, toSeq, fromSeq);
	}

	void TESObjectREFR::PlayAnimation(NiControllerManager* a_manager, NiControllerSequence* a_toSeq, NiControllerSequence* a_fromSeq)
	{
		PlayAnimation_Impl(a_manager, a_toSeq, a_fromSeq);
	}

	void TESObjectREFR::SetActivationBlocked(bool a_blocked)
	{
		extraList.SetExtraFlags(ExtraFlags::Flag::kBlockActivate, a_blocked);
	}

	void TESObjectREFR::SetAngle(const NiPoint3& a_angle)
	{
		using func_t = decltype(&TESObjectREFR::SetAngle);
		static REL::Relocation<func_t> func{ RELOCATION_ID(19359, 19786) };
		return func(this, a_angle);
	}

	void TESObjectREFR::SetCollision(bool a_enable)
	{
		if (a_enable) {
			formFlags &= ~RecordFlags::kCollisionsDisabled;
		} else {
			formFlags |= RecordFlags::kCollisionsDisabled;
		}
	}

	bool TESObjectREFR::SetDisplayName(const BSFixedString& a_name, bool a_force)
	{
		bool renamed = false;

		auto xTextData = extraList.GetByType<ExtraTextDisplayData>();
		if (xTextData) {
			bool inUse = xTextData->displayNameText || xTextData->ownerQuest;
			if (inUse && a_force) {
				xTextData->displayNameText = nullptr;
				xTextData->ownerQuest = nullptr;
			}
			renamed = !inUse || a_force;
			xTextData->SetName(a_name.c_str());
		} else {
			xTextData = new ExtraTextDisplayData(a_name.c_str());
			extraList.Add(xTextData);
			renamed = true;
		}

		return renamed;
	}

	void TESObjectREFR::SetEncounterZone(BGSEncounterZone* a_zone)
	{
		extraList.SetEncounterZone(a_zone);
		AddChange(ChangeFlags::kEncZoneExtra);
	}

	bool TESObjectREFR::SetMotionType(hkpMotion::MotionType a_motionType, bool a_allowActivate)
	{
		auto node = Get3D();
		if (!node) {
			REX::DEBUG("Target does not have 3D");
			return false;
		}

		auto result = node->SetMotionType(a_motionType, true, false, a_allowActivate);
		AddChange(ChangeFlags::kHavokMoved);
		return result;
	}

	void TESObjectREFR::SetOwner(TESForm* a_owner)
	{
		using func_t = decltype(&TESObjectREFR::SetOwner);
		static REL::Relocation<func_t> func{ RELOCATION_ID(19793, 20198) };
		return func(this, a_owner);
	}

	void TESObjectREFR::SetPosition(float a_x, float a_y, float a_z)
	{
		return SetPosition(NiPoint3(a_x, a_y, a_z));
	}

	void TESObjectREFR::SetPosition(const NiPoint3& a_pos)
	{
		using func_t = void(TESObjectREFR*, const NiPoint3&);
		static REL::Relocation<func_t> func{ RELOCATION_ID(19363, 19790) };
		return func(this, a_pos);
	}

	void TESObjectREFR::SetScale(float a_scale)
	{
		using func_t = decltype(&TESObjectREFR::SetScale);
		static REL::Relocation<func_t> func{ RELOCATION_ID(19239, 19665) };
		func(this, a_scale);
	}

	void TESObjectREFR::SetTemporary()
	{
		using func_t = decltype(&TESObjectREFR::SetTemporary);
		static REL::Relocation<func_t> func{ RELOCATION_ID(14485, 14642) };
		func(this);
	}

	InventoryChanges* TESObjectREFR::ForceInitInventoryChanges()
	{
		auto changes = MakeInventoryChanges();
		if (changes) {
			changes->InitLeveledItems();
			changes->InitFromContainerExtra();
			changes->InitScripts();
		}
		return changes;
	}

	InventoryChanges* TESObjectREFR::MakeInventoryChanges()
	{
		using func_t = decltype(&TESObjectREFR::MakeInventoryChanges);
		static REL::Relocation<func_t> func{ RELOCATION_ID(15802, 16040) };
		return func(this);
	}

	void TESObjectREFR::MoveTo_Impl(const ObjectRefHandle& a_targetHandle, TESObjectCELL* a_targetCell, TESWorldSpace* a_selfWorldSpace, const NiPoint3& a_position, const NiPoint3& a_rotation)
	{
		using func_t = decltype(&TESObjectREFR::MoveTo_Impl);
		static REL::Relocation<func_t> func{ Offset::TESObjectREFR::MoveTo };
		return func(this, a_targetHandle, a_targetCell, a_selfWorldSpace, a_position, a_rotation);
	}

	void TESObjectREFR::PlayAnimation_Impl(NiControllerManager* a_manager, NiControllerSequence* a_toSeq, NiControllerSequence* a_fromSeq, bool a_arg4)
	{
		using func_t = decltype(&TESObjectREFR::PlayAnimation_Impl);
		static REL::Relocation<func_t> func{ Offset::TESObjectREFR::PlayAnimation };
		return func(this, a_manager, a_toSeq, a_fromSeq, a_arg4);
	}
}
