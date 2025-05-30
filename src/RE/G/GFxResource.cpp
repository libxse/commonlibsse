#include "RE/G/GFxResource.h"
#include "RE/G/GFxResourceLibBase.h"

namespace RE
{
	GFxResource::GFxResource() :
		_refCount{ 1 },
		_pad0C(0),
		_lib(nullptr)
	{}

	GFxResource::~GFxResource()
	{}

	GFxResourceKey GFxResource::GetKey()
	{
		return GFxResourceKey();
	}

	std::uint32_t GFxResource::GetResourceTypeCode() const
	{
		return MakeTypeCode(ResourceType::kNone);
	}

	GFxResourceReport* GFxResource::GetResourceReport()
	{
		return nullptr;
	}

	void GFxResource::AddRef()
	{
		REX::TAtomicRef myRefCount{ _refCount.value };
		++myRefCount;
	}

	bool GFxResource::AddRef_NotZero()
	{
		REX::TAtomicRef myRefCount{ _refCount.value };
		if (myRefCount != 0) {
			++myRefCount;
			return true;
		} else {
			return false;
		}
	}

	void GFxResource::Release()
	{
		REX::TAtomicRef myRefCount{ _refCount.value };
		if (--myRefCount == 0) {
			if (_lib) {
				_lib->RemoveResourceOnRelease(this);
				_lib = nullptr;
			}
			delete this;
		}
	}

	std::int32_t GFxResource::GetRefCount() const
	{
		return _refCount.value;
	}

	void GFxResource::SetOwnerResourceLib(GFxResourceLibBase* a_lib)
	{
		assert((_lib == nullptr) || (a_lib == nullptr));
		_lib = a_lib;
	}

	GFxResource::ResourceType GFxResource::GetResourceType() const
	{
		return static_cast<GFxResource::ResourceType>(
			GetResourceTypeCode() >>
			std::to_underlying(ResourceType::kTypeCode_Shift));
	}

	GFxResource::ResourceUse GFxResource::GetResourceUse() const
	{
		return static_cast<ResourceUse>(
			GetResourceTypeCode() &
			std::to_underlying(ResourceUse::kTypeCode_Mask));
	}

	std::uint32_t GFxResource::MakeTypeCode(ResourceType a_resourceType, ResourceUse a_resourceUse)
	{
		return (std::to_underlying(a_resourceType) << std::to_underlying(ResourceType::kTypeCode_Shift)) |
		       std::to_underlying(a_resourceUse);
	}
}
