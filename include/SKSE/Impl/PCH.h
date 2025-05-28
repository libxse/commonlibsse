#pragma once

#include <REL/REL.h>
#include <REX/REX.h>

namespace RE
{
	using namespace std::literals;
}

namespace SKSE
{
	using namespace std::literals;
}

#define RELOCATION_ID(SE, AE) REL::ID(AE)

#include "RE/Offsets.h"
#include "RE/Offsets_NiRTTI.h"
#include "RE/Offsets_RTTI.h"
#include "RE/Offsets_VTABLE.h"

#include "RE/B/BSCoreTypes.h"
#include "RE/S/SFTypes.h"
