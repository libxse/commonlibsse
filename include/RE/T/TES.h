#pragma once

#include "RE/B/BSContainer.h"
#include "RE/B/BSTEvent.h"
#include "RE/B/BSTList.h"
#include "RE/B/BSTTuple.h"
#include "RE/I/ICellAttachDetachEventSource.h"
#include "RE/M/MaterialIDs.h"
#include "RE/N/NiPoint3.h"
#include "RE/N/NiSmartPointer.h"

namespace RE
{
	namespace BSResource
	{
		struct ArchiveStreamOpenedEvent;
	}

	class BSSystemEvent;
	class BSTempNodeManager;
	class GridCellArray;
	class ImageSpaceModifierInstance;
	class NavMeshInfoMap;
	class NiAVObject;
	class NiDirectionalLight;
	class NiFogProperty;
	class NiNode;
	class Sky;
	class TESLandTexture;
	class TESNPC;
	class TESObjectCELL;
	class TESObjectREFR;
	class TESWorldSpace;

	struct bhkPickData;
	struct PositionPlayerEvent;

	class TES :
		public ICellAttachDetachEventSource,                        // 000
		public BSTEventSink<BSResource::ArchiveStreamOpenedEvent>,  // 060
		public BSTEventSink<PositionPlayerEvent>                    // 068
	{
	public:
		inline static constexpr auto RTTI = RTTI_TES;
		inline static constexpr auto VTABLE = VTABLE_TES;

		class SystemEventAdapter : public BSTEventSink<BSSystemEvent>
		{
		public:
			inline static constexpr auto RTTI = RTTI_TES;
			inline static constexpr auto VTABLE = VTABLE_TES;

			~SystemEventAdapter() override;  // 00

			// override (BSTEventSink<BSSystemEvent>)
			BSEventNotifyControl ProcessEvent(const BSSystemEvent* a_event, BSTEventSource<BSSystemEvent>* a_eventSource) override;  // 01

			// members
			std::uint64_t unk08;  // 08
		};
		static_assert(sizeof(SystemEventAdapter) == 0x10);

		~TES() override;  // 00

		// override (BSTEventSink<BSResource::ArchiveStreamOpenedEvent>)
		BSEventNotifyControl ProcessEvent(const BSResource::ArchiveStreamOpenedEvent* a_event, BSTEventSource<BSResource::ArchiveStreamOpenedEvent>* a_eventSource) override;  // 01 - { return BSEventNotifyControl::kContinue; }

		// override (BSTEventSink<PositionPlayerEvent>)
		BSEventNotifyControl ProcessEvent(const PositionPlayerEvent* a_event, BSTEventSource<PositionPlayerEvent>* a_eventSource) override;  // 01

		static TES* GetSingleton();

		void ForEachCell(std::function<void(TESObjectCELL*)> a_callback);
		void ForEachCellInRange(TESObjectREFR* a_origin, float a_radius, std::function<void(TESObjectCELL*)> a_callback);
		void ForEachReference(std::function<BSContainer::ForEachResult(TESObjectREFR*)> a_callback);
		void ForEachReferenceInRange(TESObjectREFR* a_origin, float a_radius, std::function<BSContainer::ForEachResult(TESObjectREFR*)> a_callback);

		TESObjectCELL*  GetCell(const NiPoint3& a_position) const;
		MATERIAL_ID     GetLandMaterialType(const NiPoint3& a_position) const;
		bool            GetLandHeight(const NiPoint3& a_positionIn, float& a_heightOut);
		TESLandTexture* GetLandTexture(const NiPoint3& a_position) const;
		float           GetWaterHeight(const NiPoint3& a_pos, TESObjectCELL* a_cell) const;
		NiAVObject*     Pick(bhkPickData& a_pickData);
		void            PurgeBufferedCells();

		// members
		std::uint64_t                                       unk070;                     // 070
		GridCellArray*                                      gridCells;                  // 078
		NiNode*                                             objRoot;                    // 080
		NiNode*                                             lodLandRoot;                // 088
		NiNode*                                             objLODWaterRoot;            // 090
		BSTempNodeManager*                                  tempNodeManager;            // 098
		NiDirectionalLight*                                 objLight;                   // 0A0
		NiFogProperty*                                      objFog;                     // 0A8
		std::int32_t                                        currentGridX;               // 0B0
		std::int32_t                                        currentGridY;               // 0B4
		std::int32_t                                        currentQueuedX;             // 0B8
		std::int32_t                                        currentQueuedY;             // 0BC
		TESObjectCELL*                                      interiorCell;               // 0C0
		TESObjectCELL**                                     interiorBuffer;             // 0C8
		TESObjectCELL**                                     exteriorBuffer;             // 0D0
		std::uint64_t                                       unk0D8;                     // 0D8
		std::int32_t                                        saveGridX;                  // 0E0
		std::int32_t                                        saveGridY;                  // 0E0
		std::uint64_t                                       unk0E8;                     // 0E8
		std::uint64_t                                       unk0F0;                     // 0F0
		std::uint64_t                                       unk0F8;                     // 0F8
		Sky*                                                sky;                        // 100
		BSSimpleList<NiPointer<ImageSpaceModifierInstance>> activeImageSpaceModifiers;  // 108
		std::uint64_t                                       unk118;                     // 118
		std::uint64_t                                       unk120;                     // 120
		std::uint32_t                                       unk128;                     // 128
		std::uint32_t                                       landBorderMode;             // 12C
		std::uint32_t                                       borderColorAGBR;            // 130
		std::uint32_t                                       unk134;                     // 134
		std::uint64_t                                       unk138;                     // 138
		std::uint64_t                                       unk140;                     // 140 - actual offset change is somewhere near showLandBorder
		TESWorldSpace*                                      worldSpace;                 // 140
		BSSimpleList<BSTTuple<TESNPC*, std::uint16_t>*>     deadCount;                  // 148
		void*                                               unk158;                     // 158 - smart ptr
		void*                                               unk160;                     // 160 - smart ptr
		void*                                               unk168;                     // 168 - smart ptr
		void*                                               unk170;                     // 170 - smart ptr
		std::uint64_t                                       unk178;                     // 178
		std::uint64_t                                       unk180;                     // 180
		std::uint64_t                                       unk188;                     // 188
		std::uint64_t                                       unk190;                     // 190
		std::uint64_t                                       unk198;                     // 198
		std::uint64_t                                       unk1A0;                     // 1A0
		std::uint64_t                                       unk1A8;                     // 1A8
		std::uint64_t                                       unk1B0;                     // 1B0
		std::uint64_t                                       unk1B8;                     // 1B8
		std::uint64_t                                       unk1C0;                     // 1C0
		std::uint64_t                                       unk1C8;                     // 1C8
		std::uint64_t                                       unk1D0;                     // 1D0
		std::uint64_t                                       unk1D8;                     // 1D8
		std::uint64_t                                       unk1E0;                     // 1E0
		std::uint64_t                                       unk1E8;                     // 1E8
		std::uint64_t                                       unk1F0;                     // 1F0
		std::uint64_t                                       unk1F8;                     // 1F8
		std::uint64_t                                       unk200;                     // 200
		std::uint64_t                                       unk208;                     // 208
		std::uint64_t                                       unk210;                     // 210
		std::uint64_t                                       unk218;                     // 218
		std::uint64_t                                       unk220;                     // 220
		std::uint64_t                                       unk228;                     // 228
		std::uint64_t                                       unk230;                     // 230
		std::uint64_t                                       unk238;                     // 238
		std::uint64_t                                       unk240;                     // 240
		std::uint64_t                                       unk248;                     // 248
		std::uint64_t                                       unk250;                     // 250
		std::uint64_t                                       unk258;                     // 258
		std::uint64_t                                       unk260;                     // 260
		std::uint64_t                                       unk268;                     // 268
		std::uint64_t                                       unk270;                     // 270
		std::uint64_t                                       unk278;                     // 278
		std::uint64_t                                       unk280;                     // 280
		std::uint64_t                                       unk288;                     // 288
		SystemEventAdapter                                  unk290;                     // 290
		std::uint64_t                                       unk2A0;                     // 2A0
		NavMeshInfoMap*                                     unk2A8;                     // 2A8
		std::uint64_t                                       unk2B0;                     // 2B0
	};
	static_assert(sizeof(TES) == 0x2C0);
}
