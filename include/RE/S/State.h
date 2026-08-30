#pragma once

#include "RE/B/BSTArray.h"
#include "RE/N/NiSmartPointer.h"
#include "RE/N/NiSourceTexture.h"

namespace RE
{
	class NiCamera;

	namespace BSGraphics
	{
		class State
		{
		public:
			[[nodiscard]] static State* GetSingleton()
			{
				static REL::Relocation<State*> singleton{ RELOCATION_ID(524998, 411479) };
				return singleton.get();
			}

			void SetCameraData(const NiCamera* a_camera, std::uint32_t a_flags)
			{
				using func_t = decltype(&State::SetCameraData);
				static REL::Relocation<func_t> func{ RELOCATION_ID(75694, 77503) };
				return func(this, a_camera, a_flags);
			}

			// members
			NiPointer<NiSourceTexture> defaultTextureProjNoiseMap;         // 000
			NiPointer<NiSourceTexture> defaultTextureProjDiffuseMap;       // 008
			NiPointer<NiSourceTexture> defaultTextureProjNormalMap;        // 010
			NiPointer<NiSourceTexture> defaultTextureProjNormalDetailMap;  // 018
			std::uint32_t              unk020;                             // 020
			std::uint32_t              screenWidth;                        // 024
			std::uint32_t              screenHeight;                       // 028
			std::uint32_t              frameBufferViewport[2];             // 030
			std::byte                  unk038[0x54 - 0x38];                // 038
			std::uint32_t              frameCount;                         // 054
			std::byte                  unk058[0x60 - 0x58];                // 058
			bool                       insideFrame;                        // 060
			bool                       letterbox;                          // 061
			std::byte                  unk062[0x70 - 0x62];                // 062
			NiPointer<NiSourceTexture> defaultTextureBlack;                // 070
			NiPointer<NiSourceTexture> defaultTextureWhite;                // 078
			NiPointer<NiSourceTexture> defaultTextureGrey;                 // 080
			NiPointer<NiSourceTexture> defaultHeightMap;                   // 088
			NiPointer<NiSourceTexture> defaultReflectionCubeMap;           // 090
			NiPointer<NiSourceTexture> defaultFaceDetailMap;               // 098
			NiPointer<NiSourceTexture> defaultTexEffectMap;                // 0A0
			NiPointer<NiSourceTexture> defaultTextureNormalMap;            // 0A8
			NiPointer<NiSourceTexture> defaultTextureDitherNoiseMap;       // 0B0
			std::byte                  unk0B8[0x128 - 0xB8];               // 0B8
			volatile std::int32_t      dynamicResolutionLock;              // 128
			bool                       canIncreaseDynamicResolution;       // 12C
			bool                       canDecreaseDynamicResolution;       // 12D
			bool                       canChangeDynamicResolution;         // 12E
		};
		static_assert(sizeof(State) == 0x130);
		static_assert(offsetof(State, screenWidth) == 0x24);
		static_assert(offsetof(State, screenHeight) == 0x28);
		static_assert(offsetof(State, defaultTextureBlack) == 0x70);
		static_assert(offsetof(State, dynamicResolutionLock) == 0x128);
	}
}
