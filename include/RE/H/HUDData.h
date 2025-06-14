#pragma once

#include "RE/B/BSString.h"
#include "RE/I/IUIMessageData.h"
#include "RE/M/MARKER_TYPE.h"

namespace RE
{
	class TESQuest;
	class TESWordOfPower;

	class HUDData : public IUIMessageData
	{
	public:
		inline static constexpr auto RTTI = RTTI_HUDData;
		inline static constexpr auto VTABLE = VTABLE_HUDData;

		enum class Type
		{
			kUnk0 = 0,
			kNotification = 1,
			kActivate = 2,
			kActivateNoLabel = 3,
			kCenter = 4,
			kSubtitle = 5,
			kSubtitleHide = 6,
			kShowArrowCount = 7,
			kSetBlinking = 11,
			kSetFadeOut = 12,
			kSetPct = 13,
			kQuestStarted = 14,
			kQuestComplete = 15,
			kQuestFailed = 16,
			kObjectiveStarted = 17,
			kObjectiveComplete = 18,
			kObjectiveFailed = 19,
			kSkillIncrease = 20,
			kWordOfPowerLearned = 21,
			kDragonSoulAbsorbed = 22,
			kCrosshairHide = 23,
			kCrosshairSneak = 24,
			kLocationDiscovery = 26,
			kShowLocationName = 29,
			kShowHintText = 30,
		};

		~HUDData() override;  // 00

		// members
		REX::EnumSet<Type, std::uint32_t>        type;          // 10
		std::uint32_t                            pad14;         // 14
		BSString                                 text;          // 18
		ObjectRefHandle                          crossHairRef;  // 28
		std::uint32_t                            pad2C;         // 2C
		TESQuest*                                quest;         // 30
		TESWordOfPower*                          wordOfPower;   // 38
		bool                                     show;          // 40
		std::uint8_t                             pad41;         // 41
		std::uint16_t                            pad42;         // 42
		REX::EnumSet<MARKER_TYPE, std::uint32_t> discovery;     // 44
	};
	static_assert(sizeof(HUDData) == 0x48);
}
