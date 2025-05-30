#pragma once

#include "RE/B/BSAtomic.h"
#include "RE/B/BSFixedString.h"
#include "RE/B/BSPointerHandle.h"
#include "RE/B/BSTArray.h"
#include "RE/B/BSTSingleton.h"
#include "RE/N/NiPoint2.h"
#include "RE/N/NiPoint3.h"
#include "RE/N/NiSmartPointer.h"
#include "RE/N/NiTPointerMap.h"

namespace RE
{
	class BSTriShape;
	class NiNode;
	class TESObjectCELL;
	class TESWorldSpace;
	class TESWaterDisplacement;
	class TESWaterForm;
	class TESWaterNormals;
	class TESWaterObject;
	class TESWaterReflections;
	class WadingWaterData;

	class TESWaterSystem : public BSTSingletonSDM<TESWaterSystem>
	{
	public:
		[[nodiscard]] static TESWaterSystem* GetSingleton()
		{
			static REL::Relocation<TESWaterSystem**> singleton{ RELOCATION_ID(514290, 400450) };
			return *singleton;
		}

		void AddRipple(const NiPoint3& a_pos, float a_scale)
		{
			using func_t = decltype(&TESWaterSystem::AddRipple);
			static REL::Relocation<func_t> func{ RELOCATION_ID(31410, 32217) };
			return func(this, a_pos, a_scale);
		}

		// members
		std::uint32_t                                pad000;                     // 000
		BSFixedString*                               type;                       // 008
		std::uint32_t                                unk010;                     // 010
		std::uint32_t                                pad014;                     // 014
		float                                        unk018;                     // 018
		float                                        unk01C;                     // 01C
		BSTArray<NiPointer<TESWaterObject>>          waterObjects;               // 020
		BSTArray<NiPointer<TESWaterReflections>>     waterReflections;           // 038
		BSTArray<NiPointer<TESWaterDisplacement>>    waterDisplacement;          // 050
		BSTArray<NiPointer<TESWaterNormals>>         waterNormals;               // 068
		std::uint32_t                                unk080;                     // 080
		NiPoint2                                     unk084;                     // 084
		std::uint32_t                                pad08C;                     // 08C
		NiPointer<NiNode>                            waterRoot;                  // 090
		TESWaterForm*                                currentWaterType;           // 098
		std::uint32_t                                reflectionExteriorCount;    // 0A0
		std::uint32_t                                reflectionInteriorCount;    // 0A4
		TESWorldSpace*                               worldSpace;                 // 0A8
		bool                                         enabled;                    // 0B0
		std::uint8_t                                 pad0B1;                     // 0B1
		std::uint16_t                                pad0B2;                     // 0B2
		std::uint32_t                                unk0B4;                     // 0B4
		bool                                         playerUnderwater;           // 0B8
		bool                                         unk0B9;                     // 0B9
		bool                                         unk0BA;                     // 0BA
		std::uint8_t                                 pad0BB;                     // 0BB
		std::uint32_t                                unk0BC;                     // 0BC
		float                                        underwaterHeight;           // 0C0
		bool                                         waterRadiusState;           // 0C4
		std::uint8_t                                 pad0C5;                     // 0C5
		std::uint8_t                                 unk0C6;                     // 0C6
		bool                                         showProcedualWater;         // 0C7
		std::uint8_t                                 unk0C8;                     // 0C8
		std::uint8_t                                 padC9;                      // 0C9
		std::uint16_t                                padCA;                      // 0CA
		std::uint32_t                                unk0CC;                     // 0CC
		std::uint32_t                                unk0D0;                     // 0D0
		float                                        timeSinceLastRipplePlaced;  // 0D4
		NiTPointerMap<ActorHandle, WadingWaterData*> wadingWaterData;            // 0D8
		std::uint64_t                                unk0F8;                     // 0F8
		std::uint64_t                                unk100;                     // 108
		std::uint32_t                                unk108;                     // 108
		std::uint32_t                                pad10C;                     // 10C
		std::uint8_t                                 unk110;                     // 110
		std::uint8_t                                 pad111;                     // 111
		std::uint16_t                                pad112;                     // 112
		std::uint32_t                                pad114;                     // 114
		TESObjectCELL*                               unk118;                     // 118
		mutable BSSpinLock                           lock;                       // 120
		NiPointer<BSTriShape>                        autoWater;                  // 128
	};
	static_assert(sizeof(TESWaterSystem) == 0x130);
};
