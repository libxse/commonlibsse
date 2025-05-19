#pragma once

#include <REX/Impl/PCH.h>

namespace SKSE
{
	using namespace std::literals;
	namespace stl = XSE::stl;
}

namespace RE
{
	using namespace std::literals;
	namespace stl = XSE::stl;
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
