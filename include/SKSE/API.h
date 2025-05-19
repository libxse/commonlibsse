#pragma once

#include "RE/B/BSTEvent.h"

#include "SKSE/Events.h"
#include "SKSE/Interfaces.h"
#include "SKSE/Version.h"

#define SKSEAPI __cdecl

namespace SKSE
{
	struct InitInfo
	{
		bool        log{ true };
		const char* logName{ nullptr };
		const char* logPattern{ nullptr };
		bool        trampoline{ false };
		std::size_t trampolineSize{ 0 };
		bool        trampolineSKSE{ true };
		bool        hook{ true };
	};

	void Init(const LoadInterface* a_intfc, InitInfo a_info = {}) noexcept;
	void RegisterForAPIInitEvent(std::function<void()> a_fn);

	[[nodiscard]] std::string_view  GetPluginName() noexcept;
	[[nodiscard]] std::string_view  GetPluginAuthor() noexcept;
	[[nodiscard]] REL::Version      GetPluginVersion() noexcept;
	[[nodiscard]] PluginHandle      GetPluginHandle() noexcept;
	[[nodiscard]] const PluginInfo* GetPluginInfo(std::string_view a_plugin) noexcept;
	[[nodiscard]] std::uint32_t     GetReleaseIndex() noexcept;
	[[nodiscard]] std::uint32_t     GetSKSEVersion() noexcept;

	[[nodiscard]] const ScaleformInterface*          GetScaleformInterface() noexcept;
	[[nodiscard]] const PapyrusInterface*            GetPapyrusInterface() noexcept;
	[[nodiscard]] const SerializationInterface*      GetSerializationInterface() noexcept;
	[[nodiscard]] const TaskInterface*               GetTaskInterface() noexcept;
	[[nodiscard]] const MessagingInterface*          GetMessagingInterface() noexcept;
	[[nodiscard]] const ObjectInterface*             GetObjectInterface() noexcept;
	[[nodiscard]] const TrampolineInterface*         GetTrampolineInterface() noexcept;
	[[nodiscard]] const SKSEDelayFunctorManager*     GetDelayFunctorManager() noexcept;
	[[nodiscard]] const SKSEObjectRegistry*          GetObjectRegistry() noexcept;
	[[nodiscard]] const SKSEPersistentObjectStorage* GetPersistentObjectStorage() noexcept;

	[[nodiscard]] RE::BSTEventSource<ModCallbackEvent>*  GetModCallbackEventSource() noexcept;
	[[nodiscard]] RE::BSTEventSource<CameraEvent>*       GetCameraEventSource() noexcept;
	[[nodiscard]] RE::BSTEventSource<CrosshairRefEvent>* GetCrosshairRefEventSource() noexcept;
	[[nodiscard]] RE::BSTEventSource<ActionEvent>*       GetActionEventSource() noexcept;
	[[nodiscard]] RE::BSTEventSource<NiNodeUpdateEvent>* GetNiNodeUpdateEventSource() noexcept;
}

namespace SKSE
{
	void Init(const LoadInterface* a_intfc, bool a_log) noexcept;

	void AllocTrampoline(std::size_t a_size, bool a_trySKSEReserve = true) noexcept;
}
