#pragma once

#include "RE/B/BSExtraData.h"
#include "RE/E/ExtraDataTypes.h"
#include "RE/M/MARKER_TYPE.h"
#include "RE/T/TESFullName.h"

namespace RE
{
	class MapMarkerData
	{
	public:
		enum class Flag
		{
			kNone = 0,
			kVisible = 1 << 0,
			kCanTravelTo = 1 << 1,
			kShowAllHidden = 1 << 2,
			kUnk3 = 1 << 3,
			kUnk4 = 1 << 4,
			kUnk5 = 1 << 5,
			kUnk6 = 1 << 6,
			kUnk7 = 1 << 7
		};

		constexpr void SetHidden(bool a_value) noexcept { a_value ? flags.set(Flag::kShowAllHidden) : flags.reset(Flag::kShowAllHidden); }
		constexpr void SetVisible(bool a_value) noexcept { a_value ? flags.set(Flag::kVisible) : flags.reset(Flag::kVisible); }

		// members
		TESFullName                              locationName;  // 00
		REX::EnumSet<Flag, std::uint8_t>         flags;         // 10
		std::uint8_t                             pad11;         // 11
		REX::EnumSet<MARKER_TYPE, std::uint16_t> type;          // 12
		std::uint32_t                            pad14;         // 14
	};
	static_assert(sizeof(MapMarkerData) == 0x18);

	class ExtraMapMarker : public BSExtraData
	{
	public:
		inline static constexpr auto RTTI = RTTI_ExtraMapMarker;
		inline static constexpr auto VTABLE = VTABLE_ExtraMapMarker;
		inline static constexpr auto EXTRADATATYPE = ExtraDataType::kMapMarker;

		virtual ~ExtraMapMarker();  // 00

		// override (BSExtraData)
		ExtraDataType GetType() const override;                             // 01 - { return kMapMarker; }
		bool          IsNotEqual(const BSExtraData* a_rhs) const override;  // 02

		// members
		MapMarkerData* mapData;  // 10
	};
	static_assert(sizeof(ExtraMapMarker) == 0x18);
}
