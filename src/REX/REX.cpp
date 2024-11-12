#include "REX/REX.h"

#include "SKSE/Logger.h"

#ifdef REX_OPTION_INI
#	include <SimpleIni.h>

void REX::INI::detail::StoreLoadImpl(
	[[maybe_unused]] std::string_view&       a_fileBase,
	[[maybe_unused]] std::string_view&       a_fileUser,
	[[maybe_unused]] std::vector<ISetting*>& a_settings)
{
	CSimpleIniA ini;
	ini.SetUnicode(true);
	ini.SetQuotes(true);

	if (ini.LoadFile(a_fileBase.data()) == SI_OK) {
		for (auto& setting : a_settings) {
			setting->Load(&ini);
		}
	}

	if (ini.LoadFile(a_fileUser.data()) == SI_OK) {
		for (auto& setting : a_settings) {
			setting->Load(&ini);
		}
	}
}

void REX::INI::detail::StoreSaveImpl(
	[[maybe_unused]] std::string_view&       a_fileBase,
	[[maybe_unused]] std::string_view&       a_fileUser,
	[[maybe_unused]] std::vector<ISetting*>& a_settings)
{
	CSimpleIniA ini;
	ini.SetUnicode(true);
	ini.SetQuotes(true);

	ini.LoadFile(a_fileBase.data());
	for (auto& setting : a_settings) {
		setting->Save(&ini);
	}

	ini.SaveFile(a_fileBase.data(), false);
}

template <>
void REX::INI::detail::SettingLoadImpl<bool>(
	[[maybe_unused]] void*             a_file,
	[[maybe_unused]] bool&             a_value,
	[[maybe_unused]] bool&             a_valueDefault,
	[[maybe_unused]] std::string_view& a_section,
	[[maybe_unused]] std::string_view& a_key)
{
	auto file = static_cast<CSimpleIniA*>(a_file);
	a_value = file->GetBoolValue(a_section.data(), a_key.data(), a_valueDefault);
}

template <>
void REX::INI::detail::SettingSaveImpl<bool>(
	[[maybe_unused]] void*             a_file,
	[[maybe_unused]] bool&             a_value,
	[[maybe_unused]] bool&             a_valueDefault,
	[[maybe_unused]] std::string_view& a_section,
	[[maybe_unused]] std::string_view& a_key)
{
	auto file = static_cast<CSimpleIniA*>(a_file);
	file->SetBoolValue(a_section.data(), a_key.data(), a_value);
}

template <>
void REX::INI::detail::SettingLoadImpl<float>(
	[[maybe_unused]] void*             a_file,
	[[maybe_unused]] float&            a_value,
	[[maybe_unused]] float&            a_valueDefault,
	[[maybe_unused]] std::string_view& a_section,
	[[maybe_unused]] std::string_view& a_key)
{
	auto file = static_cast<CSimpleIniA*>(a_file);
	a_value = static_cast<float>(file->GetDoubleValue(a_section.data(), a_key.data(), a_valueDefault));
}

template <>
void REX::INI::detail::SettingSaveImpl<float>(
	[[maybe_unused]] void*             a_file,
	[[maybe_unused]] float&            a_value,
	[[maybe_unused]] float&            a_valueDefault,
	[[maybe_unused]] std::string_view& a_section,
	[[maybe_unused]] std::string_view& a_key)
{
	auto file = static_cast<CSimpleIniA*>(a_file);
	file->SetDoubleValue(a_section.data(), a_key.data(), a_value);
}

template <>
void REX::INI::detail::SettingLoadImpl<double>(
	[[maybe_unused]] void*             a_file,
	[[maybe_unused]] double&           a_value,
	[[maybe_unused]] double&           a_valueDefault,
	[[maybe_unused]] std::string_view& a_section,
	[[maybe_unused]] std::string_view& a_key)
{
	auto file = static_cast<CSimpleIniA*>(a_file);
	a_value = file->GetDoubleValue(a_section.data(), a_key.data(), a_valueDefault);
}

template <>
void REX::INI::detail::SettingSaveImpl<double>(
	[[maybe_unused]] void*             a_file,
	[[maybe_unused]] double&           a_value,
	[[maybe_unused]] double&           a_valueDefault,
	[[maybe_unused]] std::string_view& a_section,
	[[maybe_unused]] std::string_view& a_key)
{
	auto file = static_cast<CSimpleIniA*>(a_file);
	file->SetDoubleValue(a_section.data(), a_key.data(), a_value);
}

template <>
void REX::INI::detail::SettingLoadImpl<std::int8_t>(
	[[maybe_unused]] void*             a_file,
	[[maybe_unused]] std::int8_t&      a_value,
	[[maybe_unused]] std::int8_t&      a_valueDefault,
	[[maybe_unused]] std::string_view& a_section,
	[[maybe_unused]] std::string_view& a_key)
{
	auto file = static_cast<CSimpleIniA*>(a_file);
	a_value = static_cast<std::int8_t>(file->GetLongValue(a_section.data(), a_key.data(), a_valueDefault));
}

template <>
void REX::INI::detail::SettingSaveImpl<std::int8_t>(
	[[maybe_unused]] void*             a_file,
	[[maybe_unused]] std::int8_t&      a_value,
	[[maybe_unused]] std::int8_t&      a_valueDefault,
	[[maybe_unused]] std::string_view& a_section,
	[[maybe_unused]] std::string_view& a_key)
{
	auto file = static_cast<CSimpleIniA*>(a_file);
	file->SetLongValue(a_section.data(), a_key.data(), a_value);
}

template <>
void REX::INI::detail::SettingLoadImpl<std::int16_t>(
	[[maybe_unused]] void*             a_file,
	[[maybe_unused]] std::int16_t&     a_value,
	[[maybe_unused]] std::int16_t&     a_valueDefault,
	[[maybe_unused]] std::string_view& a_section,
	[[maybe_unused]] std::string_view& a_key)
{
	auto file = static_cast<CSimpleIniA*>(a_file);
	a_value = static_cast<std::int16_t>(file->GetLongValue(a_section.data(), a_key.data(), a_valueDefault));
}

template <>
void REX::INI::detail::SettingSaveImpl<std::int16_t>(
	[[maybe_unused]] void*             a_file,
	[[maybe_unused]] std::int16_t&     a_value,
	[[maybe_unused]] std::int16_t&     a_valueDefault,
	[[maybe_unused]] std::string_view& a_section,
	[[maybe_unused]] std::string_view& a_key)
{
	auto file = static_cast<CSimpleIniA*>(a_file);
	file->SetLongValue(a_section.data(), a_key.data(), a_value);
}

template <>
void REX::INI::detail::SettingLoadImpl<std::int32_t>(
	[[maybe_unused]] void*             a_file,
	[[maybe_unused]] std::int32_t&     a_value,
	[[maybe_unused]] std::int32_t&     a_valueDefault,
	[[maybe_unused]] std::string_view& a_section,
	[[maybe_unused]] std::string_view& a_key)
{
	auto file = static_cast<CSimpleIniA*>(a_file);
	a_value = static_cast<std::int32_t>(file->GetLongValue(a_section.data(), a_key.data(), a_valueDefault));
}

template <>
void REX::INI::detail::SettingSaveImpl<std::int32_t>(
	[[maybe_unused]] void*             a_file,
	[[maybe_unused]] std::int32_t&     a_value,
	[[maybe_unused]] std::int32_t&     a_valueDefault,
	[[maybe_unused]] std::string_view& a_section,
	[[maybe_unused]] std::string_view& a_key)
{
	auto file = static_cast<CSimpleIniA*>(a_file);
	file->SetLongValue(a_section.data(), a_key.data(), a_value);
}

template <>
void REX::INI::detail::SettingLoadImpl<std::uint8_t>(
	[[maybe_unused]] void*             a_file,
	[[maybe_unused]] std::uint8_t&     a_value,
	[[maybe_unused]] std::uint8_t&     a_valueDefault,
	[[maybe_unused]] std::string_view& a_section,
	[[maybe_unused]] std::string_view& a_key)
{
	auto file = static_cast<CSimpleIniA*>(a_file);
	a_value = static_cast<std::uint8_t>(file->GetLongValue(a_section.data(), a_key.data(), a_valueDefault));
}

template <>
void REX::INI::detail::SettingSaveImpl<std::uint8_t>(
	[[maybe_unused]] void*             a_file,
	[[maybe_unused]] std::uint8_t&     a_value,
	[[maybe_unused]] std::uint8_t&     a_valueDefault,
	[[maybe_unused]] std::string_view& a_section,
	[[maybe_unused]] std::string_view& a_key)
{
	auto file = static_cast<CSimpleIniA*>(a_file);
	file->SetLongValue(a_section.data(), a_key.data(), a_value);
}

template <>
void REX::INI::detail::SettingLoadImpl<std::uint16_t>(
	[[maybe_unused]] void*             a_file,
	[[maybe_unused]] std::uint16_t&    a_value,
	[[maybe_unused]] std::uint16_t&    a_valueDefault,
	[[maybe_unused]] std::string_view& a_section,
	[[maybe_unused]] std::string_view& a_key)
{
	auto file = static_cast<CSimpleIniA*>(a_file);
	a_value = static_cast<std::uint16_t>(file->GetLongValue(a_section.data(), a_key.data(), a_valueDefault));
}

template <>
void REX::INI::detail::SettingSaveImpl<std::uint16_t>(
	[[maybe_unused]] void*             a_file,
	[[maybe_unused]] std::uint16_t&    a_value,
	[[maybe_unused]] std::uint16_t&    a_valueDefault,
	[[maybe_unused]] std::string_view& a_section,
	[[maybe_unused]] std::string_view& a_key)
{
	auto file = static_cast<CSimpleIniA*>(a_file);
	file->SetLongValue(a_section.data(), a_key.data(), a_value);
}

template <>
void REX::INI::detail::SettingLoadImpl<std::uint32_t>(
	[[maybe_unused]] void*             a_file,
	[[maybe_unused]] std::uint32_t&    a_value,
	[[maybe_unused]] std::uint32_t&    a_valueDefault,
	[[maybe_unused]] std::string_view& a_section,
	[[maybe_unused]] std::string_view& a_key)
{
	auto file = static_cast<CSimpleIniA*>(a_file);
	a_value = static_cast<std::uint32_t>(file->GetLongValue(a_section.data(), a_key.data(), a_valueDefault));
}

template <>
void REX::INI::detail::SettingSaveImpl<std::uint32_t>(
	[[maybe_unused]] void*             a_file,
	[[maybe_unused]] std::uint32_t&    a_value,
	[[maybe_unused]] std::uint32_t&    a_valueDefault,
	[[maybe_unused]] std::string_view& a_section,
	[[maybe_unused]] std::string_view& a_key)
{
	auto file = static_cast<CSimpleIniA*>(a_file);
	file->SetLongValue(a_section.data(), a_key.data(), a_value);
}

template <>
void REX::INI::detail::SettingLoadImpl<std::string>(
	[[maybe_unused]] void*             a_file,
	[[maybe_unused]] std::string&      a_value,
	[[maybe_unused]] std::string&      a_valueDefault,
	[[maybe_unused]] std::string_view& a_section,
	[[maybe_unused]] std::string_view& a_key)
{
	auto file = static_cast<CSimpleIniA*>(a_file);
	a_value = file->GetValue(a_section.data(), a_key.data(), a_valueDefault.c_str());
}

template <>
void REX::INI::detail::SettingSaveImpl<std::string>(
	[[maybe_unused]] void*             a_file,
	[[maybe_unused]] std::string&      a_value,
	[[maybe_unused]] std::string&      a_valueDefault,
	[[maybe_unused]] std::string_view& a_section,
	[[maybe_unused]] std::string_view& a_key)
{
	auto file = static_cast<CSimpleIniA*>(a_file);
	file->SetValue(a_section.data(), a_key.data(), a_value.c_str());
}
#endif

#ifdef REX_OPTION_JSON
#	include <nlohmann/json.hpp>

void REX::JSON::detail::StoreLoadImpl(
	[[maybe_unused]] std::string_view&       a_fileBase,
	[[maybe_unused]] std::string_view&       a_fileUser,
	[[maybe_unused]] std::vector<ISetting*>& a_settings)
{
	if (std::filesystem::exists(a_fileBase)) {
		std::ifstream file{ a_fileBase.data() };
		try {
			auto result = nlohmann::json::parse(file);
			for (auto setting : a_settings) {
				setting->Load(&result);
			}
		} catch (const std::exception& e) {
			SKSE::log::error("{}", e.what());
		}
	}

	if (std::filesystem::exists(a_fileUser)) {
		std::ifstream file{ a_fileUser.data() };
		try {
			auto result = nlohmann::json::parse(file);
			for (auto setting : a_settings) {
				setting->Load(&result);
			}
		} catch (const std::exception& e) {
			SKSE::log::error("{}", e.what());
		}
	}
}

void REX::JSON::detail::StoreSaveImpl(
	[[maybe_unused]] std::string_view&       a_fileBase,
	[[maybe_unused]] std::string_view&       a_fileUser,
	[[maybe_unused]] std::vector<ISetting*>& a_settings)
{
	nlohmann::json output{};
	if (std::filesystem::exists(a_fileBase)) {
		std::ifstream file{ a_fileBase.data() };
		output = nlohmann::json::parse(file);
	}

	for (auto& setting : a_settings) {
		setting->Save(&output);
	}

	std::ofstream file{ a_fileBase.data(), std::ios::trunc };
	file << output.dump(4);
}

template <>
void REX::JSON::detail::SettingLoadImpl<bool>(
	[[maybe_unused]] void*             a_file,
	[[maybe_unused]] bool&             a_value,
	[[maybe_unused]] bool&             a_valueDefault,
	[[maybe_unused]] std::string_view& a_path)
{
	auto file = static_cast<nlohmann::json*>(a_file);
	a_value = file->value<bool>(a_path, a_valueDefault);
}

template <>
void REX::JSON::detail::SettingSaveImpl<bool>(
	[[maybe_unused]] void*             a_file,
	[[maybe_unused]] bool&             a_value,
	[[maybe_unused]] bool&             a_valueDefault,
	[[maybe_unused]] std::string_view& a_path)
{
	auto file = static_cast<nlohmann::json*>(a_file);
	(*file)[a_path] = a_value;
}

template <>
void REX::JSON::detail::SettingLoadImpl<float>(
	[[maybe_unused]] void*             a_file,
	[[maybe_unused]] float&            a_value,
	[[maybe_unused]] float&            a_valueDefault,
	[[maybe_unused]] std::string_view& a_path)
{
	auto file = static_cast<nlohmann::json*>(a_file);
	a_value = file->value<float>(a_path, a_valueDefault);
}

template <>
void REX::JSON::detail::SettingSaveImpl<float>(
	[[maybe_unused]] void*             a_file,
	[[maybe_unused]] float&            a_value,
	[[maybe_unused]] float&            a_valueDefault,
	[[maybe_unused]] std::string_view& a_path)
{
	auto file = static_cast<nlohmann::json*>(a_file);
	(*file)[a_path] = a_value;
}

template <>
void REX::JSON::detail::SettingLoadImpl<double>(
	[[maybe_unused]] void*             a_file,
	[[maybe_unused]] double&           a_value,
	[[maybe_unused]] double&           a_valueDefault,
	[[maybe_unused]] std::string_view& a_path)
{
	auto file = static_cast<nlohmann::json*>(a_file);
	a_value = file->value<double>(a_path, a_valueDefault);
}

template <>
void REX::JSON::detail::SettingSaveImpl<double>(
	[[maybe_unused]] void*             a_file,
	[[maybe_unused]] double&           a_value,
	[[maybe_unused]] double&           a_valueDefault,
	[[maybe_unused]] std::string_view& a_path)
{
	auto file = static_cast<nlohmann::json*>(a_file);
	(*file)[a_path] = a_value;
}

template <>
void REX::JSON::detail::SettingLoadImpl<std::int8_t>(
	[[maybe_unused]] void*             a_file,
	[[maybe_unused]] std::int8_t&      a_value,
	[[maybe_unused]] std::int8_t&      a_valueDefault,
	[[maybe_unused]] std::string_view& a_path)
{
	auto file = static_cast<nlohmann::json*>(a_file);
	a_value = file->value<std::int8_t>(a_path, a_valueDefault);
}

template <>
void REX::JSON::detail::SettingSaveImpl<std::int8_t>(
	[[maybe_unused]] void*             a_file,
	[[maybe_unused]] std::int8_t&      a_value,
	[[maybe_unused]] std::int8_t&      a_valueDefault,
	[[maybe_unused]] std::string_view& a_path)
{
	auto file = static_cast<nlohmann::json*>(a_file);
	(*file)[a_path] = a_value;
}

template <>
void REX::JSON::detail::SettingLoadImpl<std::int16_t>(
	[[maybe_unused]] void*             a_file,
	[[maybe_unused]] std::int16_t&     a_value,
	[[maybe_unused]] std::int16_t&     a_valueDefault,
	[[maybe_unused]] std::string_view& a_path)
{
	auto file = static_cast<nlohmann::json*>(a_file);
	a_value = file->value<std::int16_t>(a_path, a_valueDefault);
}

template <>
void REX::JSON::detail::SettingSaveImpl<std::int16_t>(
	[[maybe_unused]] void*             a_file,
	[[maybe_unused]] std::int16_t&     a_value,
	[[maybe_unused]] std::int16_t&     a_valueDefault,
	[[maybe_unused]] std::string_view& a_path)
{
	auto file = static_cast<nlohmann::json*>(a_file);
	(*file)[a_path] = a_value;
}

template <>
void REX::JSON::detail::SettingLoadImpl<std::int32_t>(
	[[maybe_unused]] void*             a_file,
	[[maybe_unused]] std::int32_t&     a_value,
	[[maybe_unused]] std::int32_t&     a_valueDefault,
	[[maybe_unused]] std::string_view& a_path)
{
	auto file = static_cast<nlohmann::json*>(a_file);
	a_value = file->value<std::int32_t>(a_path, a_valueDefault);
}

template <>
void REX::JSON::detail::SettingSaveImpl<std::int32_t>(
	[[maybe_unused]] void*             a_file,
	[[maybe_unused]] std::int32_t&     a_value,
	[[maybe_unused]] std::int32_t&     a_valueDefault,
	[[maybe_unused]] std::string_view& a_path)
{
	auto file = static_cast<nlohmann::json*>(a_file);
	(*file)[a_path] = a_value;
}

template <>
void REX::JSON::detail::SettingLoadImpl<std::uint8_t>(
	[[maybe_unused]] void*             a_file,
	[[maybe_unused]] std::uint8_t&     a_value,
	[[maybe_unused]] std::uint8_t&     a_valueDefault,
	[[maybe_unused]] std::string_view& a_path)
{
	auto file = static_cast<nlohmann::json*>(a_file);
	a_value = file->value<std::uint8_t>(a_path, a_valueDefault);
}

template <>
void REX::JSON::detail::SettingSaveImpl<std::uint8_t>(
	[[maybe_unused]] void*             a_file,
	[[maybe_unused]] std::uint8_t&     a_value,
	[[maybe_unused]] std::uint8_t&     a_valueDefault,
	[[maybe_unused]] std::string_view& a_path)
{
	auto file = static_cast<nlohmann::json*>(a_file);
	(*file)[a_path] = a_value;
}

template <>
void REX::JSON::detail::SettingLoadImpl<std::uint16_t>(
	[[maybe_unused]] void*             a_file,
	[[maybe_unused]] std::uint16_t&    a_value,
	[[maybe_unused]] std::uint16_t&    a_valueDefault,
	[[maybe_unused]] std::string_view& a_path)
{
	auto file = static_cast<nlohmann::json*>(a_file);
	a_value = file->value<std::uint16_t>(a_path, a_valueDefault);
}

template <>
void REX::JSON::detail::SettingSaveImpl<std::uint16_t>(
	[[maybe_unused]] void*             a_file,
	[[maybe_unused]] std::uint16_t&    a_value,
	[[maybe_unused]] std::uint16_t&    a_valueDefault,
	[[maybe_unused]] std::string_view& a_path)
{
	auto file = static_cast<nlohmann::json*>(a_file);
	(*file)[a_path] = a_value;
}

template <>
void REX::JSON::detail::SettingLoadImpl<std::uint32_t>(
	[[maybe_unused]] void*             a_file,
	[[maybe_unused]] std::uint32_t&    a_value,
	[[maybe_unused]] std::uint32_t&    a_valueDefault,
	[[maybe_unused]] std::string_view& a_path)
{
	auto file = static_cast<nlohmann::json*>(a_file);
	a_value = file->value<std::uint32_t>(a_path, a_valueDefault);
}

template <>
void REX::JSON::detail::SettingSaveImpl<std::uint32_t>(
	[[maybe_unused]] void*             a_file,
	[[maybe_unused]] std::uint32_t&    a_value,
	[[maybe_unused]] std::uint32_t&    a_valueDefault,
	[[maybe_unused]] std::string_view& a_path)
{
	auto file = static_cast<nlohmann::json*>(a_file);
	(*file)[a_path] = a_value;
}

template <>
void REX::JSON::detail::SettingLoadImpl<std::string>(
	[[maybe_unused]] void*             a_file,
	[[maybe_unused]] std::string&      a_value,
	[[maybe_unused]] std::string&      a_valueDefault,
	[[maybe_unused]] std::string_view& a_path)
{
	auto file = static_cast<nlohmann::json*>(a_file);
	a_value = file->value<std::string>(a_path, a_valueDefault);
}

template <>
void REX::JSON::detail::SettingSaveImpl<std::string>(
	[[maybe_unused]] void*             a_file,
	[[maybe_unused]] std::string&      a_value,
	[[maybe_unused]] std::string&      a_valueDefault,
	[[maybe_unused]] std::string_view& a_path)
{
	auto file = static_cast<nlohmann::json*>(a_file);
	(*file)[a_path] = a_value;
}
#endif

#ifdef REX_OPTION_TOML
#	include <toml++/toml.h>

void REX::TOML::detail::StoreLoadImpl(
	[[maybe_unused]] std::string_view&       a_fileBase,
	[[maybe_unused]] std::string_view&       a_fileUser,
	[[maybe_unused]] std::vector<ISetting*>& a_settings)
{
	try {
		auto result = toml::parse_file(a_fileBase);
		for (auto& setting : a_settings) {
			setting->Load(&result);
		}
	} catch (const toml::parse_error& e) {
		SKSE::log::error("{}", e.description());
	}

	try {
		auto result = toml::parse_file(a_fileUser);
		for (auto& setting : a_settings) {
			setting->Load(&result);
		}
	} catch (const toml::parse_error& e) {
		SKSE::log::error("{}", e.description());
	}
}

void REX::TOML::detail::StoreSaveImpl(
	[[maybe_unused]] std::string_view&       a_fileBase,
	[[maybe_unused]] std::string_view&       a_fileUser,
	[[maybe_unused]] std::vector<ISetting*>& a_settings)
{
	toml::parse_result output{};
	try {
		output = toml::parse_file(a_fileBase);
	} catch ([[maybe_unused]] const toml::parse_error& e) {
		// ignore
	}

	for (auto& setting : a_settings) {
		setting->Save(&output);
	}

	std::ofstream fileBase;
	fileBase.open(a_fileBase, std::ios::ate | std::ios::trunc);
	fileBase << toml::toml_formatter{ output };
	fileBase.close();
}

template <>
void REX::TOML::detail::SettingLoadImpl<bool>(
	[[maybe_unused]] void* a_file,

	[[maybe_unused]] bool&             a_value,
	[[maybe_unused]] bool&             a_valueDefault,
	[[maybe_unused]] std::string_view& a_path)
{
	auto file = static_cast<toml::parse_result*>(a_file);
	if (auto node = file->at_path(a_path)) {
		a_value = node.value_or(a_valueDefault);
	}
}

template <>
void REX::TOML::detail::SettingSaveImpl<bool>(
	[[maybe_unused]] void*             a_file,
	[[maybe_unused]] bool&             a_value,
	[[maybe_unused]] bool&             a_valueDefault,
	[[maybe_unused]] std::string_view& a_path)
{
	auto file = static_cast<toml::parse_result*>(a_file);
	file->insert_or_assign(a_path, a_value);
}

template <>
void REX::TOML::detail::SettingLoadImpl<float>(
	[[maybe_unused]] void*             a_file,
	[[maybe_unused]] float&            a_value,
	[[maybe_unused]] float&            a_valueDefault,
	[[maybe_unused]] std::string_view& a_path)
{
	auto file = static_cast<toml::parse_result*>(a_file);
	if (auto node = file->at_path(a_path)) {
		a_value = node.value_or(a_valueDefault);
	}
}

template <>
void REX::TOML::detail::SettingSaveImpl<float>(
	[[maybe_unused]] void*             a_file,
	[[maybe_unused]] float&            a_value,
	[[maybe_unused]] float&            a_valueDefault,
	[[maybe_unused]] std::string_view& a_path)
{
	auto file = static_cast<toml::parse_result*>(a_file);
	file->insert_or_assign(a_path, a_value);
}

template <>
void REX::TOML::detail::SettingLoadImpl<double>(
	[[maybe_unused]] void*             a_file,
	[[maybe_unused]] double&           a_value,
	[[maybe_unused]] double&           a_valueDefault,
	[[maybe_unused]] std::string_view& a_path)
{
	auto file = static_cast<toml::parse_result*>(a_file);
	if (auto node = file->at_path(a_path)) {
		a_value = node.value_or(a_valueDefault);
	}
}

template <>
void REX::TOML::detail::SettingSaveImpl<double>(
	[[maybe_unused]] void*             a_file,
	[[maybe_unused]] double&           a_value,
	[[maybe_unused]] double&           a_valueDefault,
	[[maybe_unused]] std::string_view& a_path)
{
	auto file = static_cast<toml::parse_result*>(a_file);
	file->insert_or_assign(a_path, a_value);
}

template <>
void REX::TOML::detail::SettingLoadImpl<std::int8_t>(
	[[maybe_unused]] void*             a_file,
	[[maybe_unused]] std::int8_t&      a_value,
	[[maybe_unused]] std::int8_t&      a_valueDefault,
	[[maybe_unused]] std::string_view& a_path)
{
	auto file = static_cast<toml::parse_result*>(a_file);
	if (auto node = file->at_path(a_path)) {
		a_value = node.value_or(a_valueDefault);
	}
}

template <>
void REX::TOML::detail::SettingSaveImpl<std::int8_t>(
	[[maybe_unused]] void* a_file,

	[[maybe_unused]] std::int8_t&      a_value,
	[[maybe_unused]] std::int8_t&      a_valueDefault,
	[[maybe_unused]] std::string_view& a_path)
{
	auto file = static_cast<toml::parse_result*>(a_file);
	file->insert_or_assign(a_path, a_value);
}

template <>
void REX::TOML::detail::SettingLoadImpl<std::int16_t>(
	[[maybe_unused]] void*             a_file,
	[[maybe_unused]] std::int16_t&     a_value,
	[[maybe_unused]] std::int16_t&     a_valueDefault,
	[[maybe_unused]] std::string_view& a_path)
{
	auto file = static_cast<toml::parse_result*>(a_file);
	if (auto node = file->at_path(a_path)) {
		a_value = node.value_or(a_valueDefault);
	}
}

template <>
void REX::TOML::detail::SettingSaveImpl<std::int16_t>(
	[[maybe_unused]] void*             a_file,
	[[maybe_unused]] std::int16_t&     a_value,
	[[maybe_unused]] std::int16_t&     a_valueDefault,
	[[maybe_unused]] std::string_view& a_path)
{
	auto file = static_cast<toml::parse_result*>(a_file);
	file->insert_or_assign(a_path, a_value);
}

template <>
void REX::TOML::detail::SettingLoadImpl<std::int32_t>(
	[[maybe_unused]] void*             a_file,
	[[maybe_unused]] std::int32_t&     a_value,
	[[maybe_unused]] std::int32_t&     a_valueDefault,
	[[maybe_unused]] std::string_view& a_path)
{
	auto file = static_cast<toml::parse_result*>(a_file);
	if (auto node = file->at_path(a_path)) {
		a_value = node.value_or(a_valueDefault);
	}
}

template <>
void REX::TOML::detail::SettingSaveImpl<std::int32_t>(
	[[maybe_unused]] void*             a_file,
	[[maybe_unused]] std::int32_t&     a_value,
	[[maybe_unused]] std::int32_t&     a_valueDefault,
	[[maybe_unused]] std::string_view& a_path)
{
	auto file = static_cast<toml::parse_result*>(a_file);
	file->insert_or_assign(a_path, a_value);
}

template <>
void REX::TOML::detail::SettingLoadImpl<std::uint8_t>(
	[[maybe_unused]] void*             a_file,
	[[maybe_unused]] std::uint8_t&     a_value,
	[[maybe_unused]] std::uint8_t&     a_valueDefault,
	[[maybe_unused]] std::string_view& a_path)
{
	auto file = static_cast<toml::parse_result*>(a_file);
	if (auto node = file->at_path(a_path)) {
		a_value = node.value_or(a_valueDefault);
	}
}

template <>
void REX::TOML::detail::SettingSaveImpl<std::uint8_t>(
	[[maybe_unused]] void*             a_file,
	[[maybe_unused]] std::uint8_t&     a_value,
	[[maybe_unused]] std::uint8_t&     a_valueDefault,
	[[maybe_unused]] std::string_view& a_path)
{
	auto file = static_cast<toml::parse_result*>(a_file);
	file->insert_or_assign(a_path, a_value);
}

template <>
void REX::TOML::detail::SettingLoadImpl<std::uint16_t>(
	[[maybe_unused]] void*             a_file,
	[[maybe_unused]] std::uint16_t&    a_value,
	[[maybe_unused]] std::uint16_t&    a_valueDefault,
	[[maybe_unused]] std::string_view& a_path)
{
	auto file = static_cast<toml::parse_result*>(a_file);
	if (auto node = file->at_path(a_path)) {
		a_value = node.value_or(a_valueDefault);
	}
}

template <>
void REX::TOML::detail::SettingSaveImpl<std::uint16_t>(
	[[maybe_unused]] void*             a_file,
	[[maybe_unused]] std::uint16_t&    a_value,
	[[maybe_unused]] std::uint16_t&    a_valueDefault,
	[[maybe_unused]] std::string_view& a_path)
{
	auto file = static_cast<toml::parse_result*>(a_file);
	file->insert_or_assign(a_path, a_value);
}

template <>
void REX::TOML::detail::SettingLoadImpl<std::uint32_t>(
	[[maybe_unused]] void*             a_file,
	[[maybe_unused]] std::uint32_t&    a_value,
	[[maybe_unused]] std::uint32_t&    a_valueDefault,
	[[maybe_unused]] std::string_view& a_path)
{
	auto file = static_cast<toml::parse_result*>(a_file);
	if (auto node = file->at_path(a_path)) {
		a_value = node.value_or(a_valueDefault);
	}
}

template <>
void REX::TOML::detail::SettingSaveImpl<std::uint32_t>(
	[[maybe_unused]] void*             a_file,
	[[maybe_unused]] std::uint32_t&    a_value,
	[[maybe_unused]] std::uint32_t&    a_valueDefault,
	[[maybe_unused]] std::string_view& a_path)
{
	auto file = static_cast<toml::parse_result*>(a_file);
	file->insert_or_assign(a_path, a_value);
}

template <>
void REX::TOML::detail::SettingLoadImpl<std::string>(
	[[maybe_unused]] void*             a_file,
	[[maybe_unused]] std::string&      a_value,
	[[maybe_unused]] std::string&      a_valueDefault,
	[[maybe_unused]] std::string_view& a_path)
{
	auto file = static_cast<toml::parse_result*>(a_file);
	if (auto node = file->at_path(a_path)) {
		a_value = node.value_or(a_valueDefault);
	}
}

template <>
void REX::TOML::detail::SettingSaveImpl<std::string>(
	[[maybe_unused]] void*             a_file,
	[[maybe_unused]] std::string&      a_value,
	[[maybe_unused]] std::string&      a_valueDefault,
	[[maybe_unused]] std::string_view& a_path)
{
	auto file = static_cast<toml::parse_result*>(a_file);
	file->insert_or_assign(a_path, a_value);
}
#endif
