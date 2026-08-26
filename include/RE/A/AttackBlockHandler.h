#pragma once

#include "RE/H/HeldStateHandler.h"

namespace RE
{
	struct AttackBlockHandler : public HeldStateHandler
	{
	public:
		inline static constexpr auto RTTI = RTTI_AttackBlockHandler;
		inline static constexpr auto VTABLE = VTABLE_AttackBlockHandler;

		enum class AttackType : std::uint8_t
		{
			kRight = 0,
			kLeft = 1,
			kDual = 2
		};

		virtual ~AttackBlockHandler();  // 00

		// override (PlayerInputHandler)
		virtual bool CanProcess(InputEvent* a_event) override;                                  // 01
		virtual void ProcessButton(ButtonEvent* a_event, PlayerControlsData* a_data) override;  // 04
		virtual void UpdateHeldStateActive(const ButtonEvent* a_event) override;                // 05
		virtual void SetHeldStateActive(bool a_flag) override;                                  // 06

		// members
		BSFixedString unk18[8];                    // 18
		std::uint32_t heldTimeMs;                  // 18
		std::uint32_t unk1C;                       // 1C
		BSFixedString controlID;                   // 20
		AttackType    attackType;                  // 28
		std::uint8_t  pad29;                       // 29
		std::uint16_t pad2A;                       // 2A
		std::uint8_t  attackCount;                 // 2C
		float         initialPowerAttackDelay;     // 30
		std::uint32_t pad34;                       // 34
		float         subsequentPowerAttackDelay;  // 38
		std::uint8_t  unk7C[0x3C];                 // 7C
		bool          ignore;                      // 3C
		bool          unk41;                       // 3D
		bool          heldLeft;                    // 3E
		bool          heldRight;                   // 3F
		std::uint32_t unk44;                       // 40
	};
	static_assert(sizeof(AttackBlockHandler) == 0xC0);
}
