#pragma once

#include "RE/H/hkbShapeSetup.h"

namespace RE
{
	struct hkbRigidBodySetup
	{
		enum class Type
		{
			kInvalid = -1,
			kKeyframed,
			kDynamic,
			kFixed,
		};

		// members
		std::uint32_t                   collisionFilterInfo;  // 00
		REX::EnumSet<Type, std::int8_t> type;                 // 04
		hkbShapeSetup                   shapeSetup;           // 05
	};
	static_assert(sizeof(hkbRigidBodySetup) == 0x20);
}
