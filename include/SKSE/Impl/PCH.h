#pragma once

#include <REL/REL.h>
#include <REX/REX.h>

namespace SKSE
{
	using namespace std::literals;
}

namespace RE
{
	using namespace std::literals;
}

namespace stl
{
	template <class... Args>
	[[nodiscard]] inline auto pun_bits(Args... a_args)  //
		requires(std::same_as<std::remove_cv_t<Args>, bool> && ...)
	{
		constexpr auto ARGC = sizeof...(Args);

		std::bitset<ARGC> bits;
		std::size_t       i = 0;
		((bits[i++] = a_args), ...);

		if constexpr (ARGC <= std::numeric_limits<unsigned long>::digits) {
			return bits.to_ulong();
		} else if constexpr (ARGC <= std::numeric_limits<unsigned long long>::digits) {
			return bits.to_ullong();
		} else {
			static_assert(false && sizeof...(Args));
		}
	}
}

#ifdef SKYRIM_SUPPORT_AE
#	define RELOCATION_ID(SE, AE) REL::ID(AE)
#else
#	define RELOCATION_ID(SE, AE) REL::ID(SE)
#endif

#include "RE/Offsets.h"
#include "RE/Offsets_NiRTTI.h"
#include "RE/Offsets_RTTI.h"
#include "RE/Offsets_VTABLE.h"

#include "RE/B/BSCoreTypes.h"
#include "RE/S/SFTypes.h"
