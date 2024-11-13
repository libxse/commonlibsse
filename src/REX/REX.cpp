#include "REX/REX/INI.h"
#include "REX/REX/JSON.h"
#include "REX/REX/TOML.h"

#include "SKSE/Logger.h"

#ifdef REX_OPTION_INI
#include <inicpp.h>

namespace REX::INI
{
	namespace Impl
	{
		template <class T>
		void SettingLoad<T>(
			void*            a_data,
			std::string_view a_section,
			std::string_view a_key,
			T&               a_value,
			T&               a_valueDefault)
		{
			const auto file = static_cast<ini::IniFileCaseInsensitive*>(a_data);
			if (file->contains(a_section.data())) {
				auto& section = (*file)[a_section.data()];
				if (section.contains(a_key.data())) {
					if constexpr (std::is_same_v<T, std::int8_t>)
						a_value = section[a_key.data()].as<char>();
					else
						a_value = section[a_key.data()].as<T>();

					return;
				}
			}

			a_value = a_valueDefault;
		}

		template void SettingLoad<bool>(void*, std::string_view, std::string_view, bool&, bool&);
		template void SettingLoad<float>(void*, std::string_view, std::string_view, float&, float&);
		template void SettingLoad<double>(void*, std::string_view, std::string_view, double&, double&);
		template void SettingLoad<std::uint8_t>(void*, std::string_view, std::string_view, std::uint8_t&, std::uint8_t&);
		template void SettingLoad<std::uint16_t>(void*, std::string_view, std::string_view, std::uint16_t&, std::uint16_t&);
		template void SettingLoad<std::uint32_t>(void*, std::string_view, std::string_view, std::uint32_t&, std::uint32_t&);
		template void SettingLoad<std::int8_t>(void*, std::string_view, std::string_view, std::int8_t&, std::int8_t&);
		template void SettingLoad<std::int16_t>(void*, std::string_view, std::string_view, std::int16_t&, std::int16_t&);
		template void SettingLoad<std::int32_t>(void*, std::string_view, std::string_view, std::int32_t&, std::int32_t&);
		template void SettingLoad<std::string>(void*, std::string_view, std::string_view, std::string&, std::string&);

		template <class T>
		void SettingSave<T>(
			void*            a_data,
			std::string_view a_section,
			std::string_view a_key,
			T&               a_value)
		{
			auto& file = *static_cast<ini::IniFileCaseInsensitive*>(a_data);
			if constexpr (std::is_same_v<T, std::int8_t>)
				file[a_section.data()][a_key.data()] = (char)a_value;
			else
				file[a_section.data()][a_key.data()] = a_value;
		}

		template void SettingSave<bool>(void*, std::string_view, std::string_view, bool&);
		template void SettingSave<float>(void*, std::string_view, std::string_view, float&);
		template void SettingSave<double>(void*, std::string_view, std::string_view, double&);
		template void SettingSave<std::uint8_t>(void*, std::string_view, std::string_view, std::uint8_t&);
		template void SettingSave<std::uint16_t>(void*, std::string_view, std::string_view, std::uint16_t&);
		template void SettingSave<std::uint32_t>(void*, std::string_view, std::string_view, std::uint32_t&);
		template void SettingSave<std::int8_t>(void*, std::string_view, std::string_view, std::int8_t&);
		template void SettingSave<std::int16_t>(void*, std::string_view, std::string_view, std::int16_t&);
		template void SettingSave<std::int32_t>(void*, std::string_view, std::string_view, std::int32_t&);
		template void SettingSave<std::string>(void*, std::string_view, std::string_view, std::string&);
	}

	void SettingStore::Load()
	{
		ini::IniFileCaseInsensitive file;

		if (std::filesystem::exists(m_fileBase)) {
			file.load(m_fileBase.data());
			for (auto& setting : m_settings) {
				setting->Load(&file, true);
			}
		}

		if (std::filesystem::exists(m_fileUser)) {
			file.load(m_fileUser.data());
			for (auto& setting : m_settings) {
				setting->Load(&file, false);
			}
		}
	}

	void SettingStore::Save()
	{
		ini::IniFileCaseInsensitive file;

		file.load(m_fileBase.data());
		for (auto& setting : m_settings) {
			setting->Save(&file);
		}

		file.save(m_fileBase.data());
	}
}
#endif

#ifdef REX_OPTION_JSON
#	include <nlohmann/json.hpp>

namespace REX::JSON
{
	namespace Impl
	{
		template <class T>
		void SettingLoad<T>(
			void*            a_data,
			std::string_view a_path,
			T&               a_value,
			T&               a_valueDefault)
		{
			const auto& json = *static_cast<nlohmann::json*>(a_data);
			if (a_path[0] == '/')
				a_value = json.value<T>(nlohmann::json::json_pointer(a_path.data()), a_valueDefault);
			else
				a_value = json.value<T>(a_path, a_valueDefault);
		}

		template void SettingLoad<bool>(void*, std::string_view, bool&, bool&);
		template void SettingLoad<float>(void*, std::string_view, float&, float&);
		template void SettingLoad<double>(void*, std::string_view, double&, double&);
		template void SettingLoad<std::uint8_t>(void*, std::string_view, std::uint8_t&, std::uint8_t&);
		template void SettingLoad<std::uint16_t>(void*, std::string_view, std::uint16_t&, std::uint16_t&);
		template void SettingLoad<std::uint32_t>(void*, std::string_view, std::uint32_t&, std::uint32_t&);
		template void SettingLoad<std::int8_t>(void*, std::string_view, std::int8_t&, std::int8_t&);
		template void SettingLoad<std::int16_t>(void*, std::string_view, std::int16_t&, std::int16_t&);
		template void SettingLoad<std::int32_t>(void*, std::string_view, std::int32_t&, std::int32_t&);
		template void SettingLoad<std::string>(void*, std::string_view, std::string&, std::string&);

		template <class T>
		void SettingSave<T>(
			void*            a_data,
			std::string_view a_path,
			T&               a_value)
		{
			auto& json = *static_cast<nlohmann::json*>(a_data);
			if (a_path[0] == '/')
				json[nlohmann::json::json_pointer(a_path.data())] = a_value;
			else
				json[a_path] = a_value;
		}

		template void SettingSave<bool>(void*, std::string_view, bool&);
		template void SettingSave<float>(void*, std::string_view, float&);
		template void SettingSave<double>(void*, std::string_view, double&);
		template void SettingSave<std::uint8_t>(void*, std::string_view, std::uint8_t&);
		template void SettingSave<std::uint16_t>(void*, std::string_view, std::uint16_t&);
		template void SettingSave<std::uint32_t>(void*, std::string_view, std::uint32_t&);
		template void SettingSave<std::int8_t>(void*, std::string_view, std::int8_t&);
		template void SettingSave<std::int16_t>(void*, std::string_view, std::int16_t&);
		template void SettingSave<std::int32_t>(void*, std::string_view, std::int32_t&);
		template void SettingSave<std::string>(void*, std::string_view, std::string&);
	}

	void SettingStore::Load()
	{
		if (std::filesystem::exists(m_fileBase)) {
			std::ifstream file{ m_fileBase.data() };
			try {
				auto result = nlohmann::json::parse(file);
				for (auto setting : m_settings) {
					setting->Load(&result, true);
				}
			} catch (const std::exception& e) {
				SKSE::log::error("{}", e.what());
			}
		}

		if (std::filesystem::exists(m_fileUser)) {
			std::ifstream file{ m_fileUser.data() };
			try {
				auto result = nlohmann::json::parse(file);
				for (auto setting : m_settings) {
					setting->Load(&result, false);
				}
			} catch (const std::exception& e) {
				SKSE::log::error("{}", e.what());
			}
		}
	}

	void SettingStore::Save()
	{
		nlohmann::json output{};
		if (std::filesystem::exists(m_fileBase)) {
			std::ifstream file{ m_fileBase.data() };
			output = nlohmann::json::parse(file);
		}

		for (auto& setting : m_settings) {
			setting->Save(&output);
		}

		std::ofstream file{ m_fileBase.data(), std::ios::trunc };
		file << output.dump(4);
	}
}
#endif

#ifdef REX_OPTION_TOML
#	define TOML_EXCEPTIONS 0
#	include <toml++/toml.h>

namespace REX::TOML
{
	namespace Impl
	{
		template <class T>
		void SettingLoad<T>(
			void*            a_data,
			std::string_view a_path,
			T&               a_value,
			T&               a_valueDefault)
		{
			const auto& table = *static_cast<toml::table*>(a_data);
			if (const auto node = table[toml::path(a_path)])
				a_value = node.value_or(a_valueDefault);
		}

		template void SettingLoad<bool>(void*, std::string_view, bool&, bool&);
		template void SettingLoad<float>(void*, std::string_view, float&, float&);
		template void SettingLoad<double>(void*, std::string_view, double&, double&);
		template void SettingLoad<std::uint8_t>(void*, std::string_view, std::uint8_t&, std::uint8_t&);
		template void SettingLoad<std::uint16_t>(void*, std::string_view, std::uint16_t&, std::uint16_t&);
		template void SettingLoad<std::uint32_t>(void*, std::string_view, std::uint32_t&, std::uint32_t&);
		template void SettingLoad<std::int8_t>(void*, std::string_view, std::int8_t&, std::int8_t&);
		template void SettingLoad<std::int16_t>(void*, std::string_view, std::int16_t&, std::int16_t&);
		template void SettingLoad<std::int32_t>(void*, std::string_view, std::int32_t&, std::int32_t&);
		template void SettingLoad<std::string>(void*, std::string_view, std::string&, std::string&);

		template <class T>
		void SettingSave<T>(
			void*            a_data,
			std::string_view a_path,
			T&               a_value)
		{
			// TODO
		}

		template void SettingSave<bool>(void*, std::string_view, bool&);
		template void SettingSave<float>(void*, std::string_view, float&);
		template void SettingSave<double>(void*, std::string_view, double&);
		template void SettingSave<std::uint8_t>(void*, std::string_view, std::uint8_t&);
		template void SettingSave<std::uint16_t>(void*, std::string_view, std::uint16_t&);
		template void SettingSave<std::uint32_t>(void*, std::string_view, std::uint32_t&);
		template void SettingSave<std::int8_t>(void*, std::string_view, std::int8_t&);
		template void SettingSave<std::int16_t>(void*, std::string_view, std::int16_t&);
		template void SettingSave<std::int32_t>(void*, std::string_view, std::int32_t&);
		template void SettingSave<std::string>(void*, std::string_view, std::string&);
	}

	void SettingStore::Load()
	{
		if (auto result = toml::parse_file(m_fileBase)) {
			for (auto& setting : m_settings)
				setting->Load(&result.table(), true);
		}

		if (auto result = toml::parse_file(m_fileUser)) {
			for (auto& setting : m_settings)
				setting->Load(&result.table(), false);
		}
	}

	void SettingStore::Save()
	{
		// TODO
	}
}
#endif
