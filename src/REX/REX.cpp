#include "REX/REX.h"

#include "SKSE/Logger.h"

#ifdef REX_OPTION_INI
#	include <SimpleIni.h>

void REX::INI::detail::StoreLoadImpl(
	std::string_view&       a_fileBase,
	std::string_view&       a_fileUser,
	std::vector<ISetting*>& a_settings)
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
	std::string_view&       a_fileBase,
	std::vector<ISetting*>& a_settings)
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
	void*             a_file,
	bool&             a_value,
	bool&             a_valueDefault,
	std::string_view& a_section,
	std::string_view& a_key)
{
	auto file = static_cast<CSimpleIniA*>(a_file);
	a_value = file->GetBoolValue(a_section.data(), a_key.data(), a_valueDefault);
}

template <>
void REX::INI::detail::SettingSaveImpl<bool>(
	void*             a_file,
	bool&             a_value,
	std::string_view& a_section,
	std::string_view& a_key)
{
	auto file = static_cast<CSimpleIniA*>(a_file);
	file->SetBoolValue(a_section.data(), a_key.data(), a_value);
}

template <>
void REX::INI::detail::SettingLoadImpl<float>(
	void*             a_file,
	float&            a_value,
	float&            a_valueDefault,
	std::string_view& a_section,
	std::string_view& a_key)
{
	auto file = static_cast<CSimpleIniA*>(a_file);
	a_value = static_cast<float>(file->GetDoubleValue(a_section.data(), a_key.data(), a_valueDefault));
}

template <>
void REX::INI::detail::SettingSaveImpl<float>(
	void*             a_file,
	float&            a_value,
	std::string_view& a_section,
	std::string_view& a_key)
{
	auto file = static_cast<CSimpleIniA*>(a_file);
	file->SetDoubleValue(a_section.data(), a_key.data(), a_value);
}

template <>
void REX::INI::detail::SettingLoadImpl<double>(
	void*             a_file,
	double&           a_value,
	double&           a_valueDefault,
	std::string_view& a_section,
	std::string_view& a_key)
{
	auto file = static_cast<CSimpleIniA*>(a_file);
	a_value = file->GetDoubleValue(a_section.data(), a_key.data(), a_valueDefault);
}

template <>
void REX::INI::detail::SettingSaveImpl<double>(
	void*             a_file,
	double&           a_value,
	std::string_view& a_section,
	std::string_view& a_key)
{
	auto file = static_cast<CSimpleIniA*>(a_file);
	file->SetDoubleValue(a_section.data(), a_key.data(), a_value);
}

template <>
void REX::INI::detail::SettingLoadImpl<std::int8_t>(
	void*             a_file,
	std::int8_t&      a_value,
	std::int8_t&      a_valueDefault,
	std::string_view& a_section,
	std::string_view& a_key)
{
	auto file = static_cast<CSimpleIniA*>(a_file);
	a_value = static_cast<std::int8_t>(file->GetLongValue(a_section.data(), a_key.data(), a_valueDefault));
}

template <>
void REX::INI::detail::SettingSaveImpl<std::int8_t>(
	void*             a_file,
	std::int8_t&      a_value,
	std::string_view& a_section,
	std::string_view& a_key)
{
	auto file = static_cast<CSimpleIniA*>(a_file);
	file->SetLongValue(a_section.data(), a_key.data(), a_value);
}

template <>
void REX::INI::detail::SettingLoadImpl<std::int16_t>(
	void*             a_file,
	std::int16_t&     a_value,
	std::int16_t&     a_valueDefault,
	std::string_view& a_section,
	std::string_view& a_key)
{
	auto file = static_cast<CSimpleIniA*>(a_file);
	a_value = static_cast<std::int16_t>(file->GetLongValue(a_section.data(), a_key.data(), a_valueDefault));
}

template <>
void REX::INI::detail::SettingSaveImpl<std::int16_t>(
	void*             a_file,
	std::int16_t&     a_value,
	std::string_view& a_section,
	std::string_view& a_key)
{
	auto file = static_cast<CSimpleIniA*>(a_file);
	file->SetLongValue(a_section.data(), a_key.data(), a_value);
}

template <>
void REX::INI::detail::SettingLoadImpl<std::int32_t>(
	void*             a_file,
	std::int32_t&     a_value,
	std::int32_t&     a_valueDefault,
	std::string_view& a_section,
	std::string_view& a_key)
{
	auto file = static_cast<CSimpleIniA*>(a_file);
	a_value = static_cast<std::int32_t>(file->GetLongValue(a_section.data(), a_key.data(), a_valueDefault));
}

template <>
void REX::INI::detail::SettingSaveImpl<std::int32_t>(
	void*             a_file,
	std::int32_t&     a_value,
	std::string_view& a_section,
	std::string_view& a_key)
{
	auto file = static_cast<CSimpleIniA*>(a_file);
	file->SetLongValue(a_section.data(), a_key.data(), a_value);
}

template <>
void REX::INI::detail::SettingLoadImpl<std::uint8_t>(
	void*             a_file,
	std::uint8_t&     a_value,
	std::uint8_t&     a_valueDefault,
	std::string_view& a_section,
	std::string_view& a_key)
{
	auto file = static_cast<CSimpleIniA*>(a_file);
	a_value = static_cast<std::uint8_t>(file->GetLongValue(a_section.data(), a_key.data(), a_valueDefault));
}

template <>
void REX::INI::detail::SettingSaveImpl<std::uint8_t>(
	void*             a_file,
	std::uint8_t&     a_value,
	std::string_view& a_section,
	std::string_view& a_key)
{
	auto file = static_cast<CSimpleIniA*>(a_file);
	file->SetLongValue(a_section.data(), a_key.data(), a_value);
}

template <>
void REX::INI::detail::SettingLoadImpl<std::uint16_t>(
	void*             a_file,
	std::uint16_t&    a_value,
	std::uint16_t&    a_valueDefault,
	std::string_view& a_section,
	std::string_view& a_key)
{
	auto file = static_cast<CSimpleIniA*>(a_file);
	a_value = static_cast<std::uint16_t>(file->GetLongValue(a_section.data(), a_key.data(), a_valueDefault));
}

template <>
void REX::INI::detail::SettingSaveImpl<std::uint16_t>(
	void*             a_file,
	std::uint16_t&    a_value,
	std::string_view& a_section,
	std::string_view& a_key)
{
	auto file = static_cast<CSimpleIniA*>(a_file);
	file->SetLongValue(a_section.data(), a_key.data(), a_value);
}

template <>
void REX::INI::detail::SettingLoadImpl<std::uint32_t>(
	void*             a_file,
	std::uint32_t&    a_value,
	std::uint32_t&    a_valueDefault,
	std::string_view& a_section,
	std::string_view& a_key)
{
	auto file = static_cast<CSimpleIniA*>(a_file);
	a_value = static_cast<std::uint32_t>(file->GetLongValue(a_section.data(), a_key.data(), a_valueDefault));
}

template <>
void REX::INI::detail::SettingSaveImpl<std::uint32_t>(
	void*             a_file,
	std::uint32_t&    a_value,
	std::string_view& a_section,
	std::string_view& a_key)
{
	auto file = static_cast<CSimpleIniA*>(a_file);
	file->SetLongValue(a_section.data(), a_key.data(), a_value);
}

template <>
void REX::INI::detail::SettingLoadImpl<std::string>(
	void*             a_file,
	std::string&      a_value,
	std::string&      a_valueDefault,
	std::string_view& a_section,
	std::string_view& a_key)
{
	auto file = static_cast<CSimpleIniA*>(a_file);
	a_value = file->GetValue(a_section.data(), a_key.data(), a_valueDefault.c_str());
}

template <>
void REX::INI::detail::SettingSaveImpl<std::string>(
	void*             a_file,
	std::string&      a_value,
	std::string_view& a_section,
	std::string_view& a_key)
{
	auto file = static_cast<CSimpleIniA*>(a_file);
	file->SetValue(a_section.data(), a_key.data(), a_value.c_str());
}
#endif

#ifdef REX_OPTION_JSON
#	include <nlohmann/json.hpp>

void REX::JSON::detail::StoreLoadImpl(
	std::string_view&       a_fileBase,
	std::string_view&       a_fileUser,
	std::vector<ISetting*>& a_settings)
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
	std::string_view&       a_fileBase,
	std::vector<ISetting*>& a_settings)
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
	void*             a_file,
	bool&             a_value,
	bool&             a_valueDefault,
	std::string_view& a_path)
{
	auto file = static_cast<nlohmann::json*>(a_file);
	a_value = file->value<bool>(a_path, a_valueDefault);
}

template <>
void REX::JSON::detail::SettingSaveImpl<bool>(
	void*             a_file,
	bool&             a_value,
	std::string_view& a_path)
{
	auto file = static_cast<nlohmann::json*>(a_file);
	(*file)[a_path] = a_value;
}

template <>
void REX::JSON::detail::SettingLoadImpl<float>(
	void*             a_file,
	float&            a_value,
	float&            a_valueDefault,
	std::string_view& a_path)
{
	auto file = static_cast<nlohmann::json*>(a_file);
	a_value = file->value<float>(a_path, a_valueDefault);
}

template <>
void REX::JSON::detail::SettingSaveImpl<float>(
	void*             a_file,
	float&            a_value,
	std::string_view& a_path)
{
	auto file = static_cast<nlohmann::json*>(a_file);
	(*file)[a_path] = a_value;
}

template <>
void REX::JSON::detail::SettingLoadImpl<double>(
	void*             a_file,
	double&           a_value,
	double&           a_valueDefault,
	std::string_view& a_path)
{
	auto file = static_cast<nlohmann::json*>(a_file);
	a_value = file->value<double>(a_path, a_valueDefault);
}

template <>
void REX::JSON::detail::SettingSaveImpl<double>(
	void*             a_file,
	double&           a_value,
	std::string_view& a_path)
{
	auto file = static_cast<nlohmann::json*>(a_file);
	(*file)[a_path] = a_value;
}

template <>
void REX::JSON::detail::SettingLoadImpl<std::int8_t>(
	void*             a_file,
	std::int8_t&      a_value,
	std::int8_t&      a_valueDefault,
	std::string_view& a_path)
{
	auto file = static_cast<nlohmann::json*>(a_file);
	a_value = file->value<std::int8_t>(a_path, a_valueDefault);
}

template <>
void REX::JSON::detail::SettingSaveImpl<std::int8_t>(
	void*             a_file,
	std::int8_t&      a_value,
	std::string_view& a_path)
{
	auto file = static_cast<nlohmann::json*>(a_file);
	(*file)[a_path] = a_value;
}

template <>
void REX::JSON::detail::SettingLoadImpl<std::int16_t>(
	void*             a_file,
	std::int16_t&     a_value,
	std::int16_t&     a_valueDefault,
	std::string_view& a_path)
{
	auto file = static_cast<nlohmann::json*>(a_file);
	a_value = file->value<std::int16_t>(a_path, a_valueDefault);
}

template <>
void REX::JSON::detail::SettingSaveImpl<std::int16_t>(
	void*             a_file,
	std::int16_t&     a_value,
	std::string_view& a_path)
{
	auto file = static_cast<nlohmann::json*>(a_file);
	(*file)[a_path] = a_value;
}

template <>
void REX::JSON::detail::SettingLoadImpl<std::int32_t>(
	void*             a_file,
	std::int32_t&     a_value,
	std::int32_t&     a_valueDefault,
	std::string_view& a_path)
{
	auto file = static_cast<nlohmann::json*>(a_file);
	a_value = file->value<std::int32_t>(a_path, a_valueDefault);
}

template <>
void REX::JSON::detail::SettingSaveImpl<std::int32_t>(
	void*             a_file,
	std::int32_t&     a_value,
	std::string_view& a_path)
{
	auto file = static_cast<nlohmann::json*>(a_file);
	(*file)[a_path] = a_value;
}

template <>
void REX::JSON::detail::SettingLoadImpl<std::uint8_t>(
	void*             a_file,
	std::uint8_t&     a_value,
	std::uint8_t&     a_valueDefault,
	std::string_view& a_path)
{
	auto file = static_cast<nlohmann::json*>(a_file);
	a_value = file->value<std::uint8_t>(a_path, a_valueDefault);
}

template <>
void REX::JSON::detail::SettingSaveImpl<std::uint8_t>(
	void*             a_file,
	std::uint8_t&     a_value,
	std::string_view& a_path)
{
	auto file = static_cast<nlohmann::json*>(a_file);
	(*file)[a_path] = a_value;
}

template <>
void REX::JSON::detail::SettingLoadImpl<std::uint16_t>(
	void*             a_file,
	std::uint16_t&    a_value,
	std::uint16_t&    a_valueDefault,
	std::string_view& a_path)
{
	auto file = static_cast<nlohmann::json*>(a_file);
	a_value = file->value<std::uint16_t>(a_path, a_valueDefault);
}

template <>
void REX::JSON::detail::SettingSaveImpl<std::uint16_t>(
	void*             a_file,
	std::uint16_t&    a_value,
	std::string_view& a_path)
{
	auto file = static_cast<nlohmann::json*>(a_file);
	(*file)[a_path] = a_value;
}

template <>
void REX::JSON::detail::SettingLoadImpl<std::uint32_t>(
	void*             a_file,
	std::uint32_t&    a_value,
	std::uint32_t&    a_valueDefault,
	std::string_view& a_path)
{
	auto file = static_cast<nlohmann::json*>(a_file);
	a_value = file->value<std::uint32_t>(a_path, a_valueDefault);
}

template <>
void REX::JSON::detail::SettingSaveImpl<std::uint32_t>(
	void*             a_file,
	std::uint32_t&    a_value,
	std::string_view& a_path)
{
	auto file = static_cast<nlohmann::json*>(a_file);
	(*file)[a_path] = a_value;
}

template <>
void REX::JSON::detail::SettingLoadImpl<std::string>(
	void*             a_file,
	std::string&      a_value,
	std::string&      a_valueDefault,
	std::string_view& a_path)
{
	auto file = static_cast<nlohmann::json*>(a_file);
	a_value = file->value<std::string>(a_path, a_valueDefault);
}

template <>
void REX::JSON::detail::SettingSaveImpl<std::string>(
	void*             a_file,
	std::string&      a_value,
	std::string_view& a_path)
{
	auto file = static_cast<nlohmann::json*>(a_file);
	(*file)[a_path] = a_value;
}
#endif

#ifdef REX_OPTION_TOML
#	include <toml++/toml.h>

void REX::TOML::detail::StoreLoadImpl(
	std::string_view&       a_fileBase,
	std::string_view&       a_fileUser,
	std::vector<ISetting*>& a_settings)
{
	try {
		auto result = toml::parse_file(a_fileBase);
		for (auto& setting : a_settings) {
			setting->Load(&result);
		}
	} catch (const std::exception& e) {
		SKSE::log::error("{}", e.what());
	}

	try {
		auto result = toml::parse_file(a_fileUser);
		for (auto& setting : a_settings) {
			setting->Load(&result);
		}
	} catch (const std::exception& e) {
		SKSE::log::error("{}", e.what());
	}
}

void REX::TOML::detail::StoreSaveImpl(
	[[maybe_unused]] std::string_view&       a_fileBase,
	[[maybe_unused]] std::vector<ISetting*>& a_settings)
{
	//	toml::parse_result output{};
	//	try {
	//		output = toml::parse_file(a_fileBase);
	//	} catch (const std::exception& e) {
	//		// ignore
	//	}
	//
	//	for (auto& setting : a_settings) {
	//		setting->Save(&output);
	//	}
	//
	//	std::ofstream file{ a_fileBase.data(), std::ios::trunc };
	//	file << output;
}

template <>
void REX::TOML::detail::SettingLoadImpl<bool>(
	void*             a_file,
	bool&             a_value,
	bool&             a_valueDefault,
	std::string_view& a_path)
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
	[[maybe_unused]] std::string_view& a_path)
{
	//	auto file = static_cast<toml::parse_result*>(a_file);
	//	file->insert_or_assign(a_path, a_value);
}

template <>
void REX::TOML::detail::SettingLoadImpl<float>(
	void*             a_file,
	float&            a_value,
	float&            a_valueDefault,
	std::string_view& a_path)
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
	[[maybe_unused]] std::string_view& a_path)
{
	//	auto file = static_cast<toml::parse_result*>(a_file);
	//	file->insert_or_assign(a_path, a_value);
}

template <>
void REX::TOML::detail::SettingLoadImpl<double>(
	void*             a_file,
	double&           a_value,
	double&           a_valueDefault,
	std::string_view& a_path)
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
	[[maybe_unused]] std::string_view& a_path)
{
	//	auto file = static_cast<toml::parse_result*>(a_file);
	//	file->insert_or_assign(a_path, a_value);
}

template <>
void REX::TOML::detail::SettingLoadImpl<std::int8_t>(
	void*             a_file,
	std::int8_t&      a_value,
	std::int8_t&      a_valueDefault,
	std::string_view& a_path)
{
	auto file = static_cast<toml::parse_result*>(a_file);
	if (auto node = file->at_path(a_path)) {
		a_value = node.value_or(a_valueDefault);
	}
}

template <>
void REX::TOML::detail::SettingSaveImpl<std::int8_t>(
	[[maybe_unused]] void*             a_file,
	[[maybe_unused]] std::int8_t&      a_value,
	[[maybe_unused]] std::string_view& a_path)
{
	//	auto file = static_cast<toml::parse_result*>(a_file);
	//	file->insert_or_assign(a_path, a_value);
}

template <>
void REX::TOML::detail::SettingLoadImpl<std::int16_t>(
	void*             a_file,
	std::int16_t&     a_value,
	std::int16_t&     a_valueDefault,
	std::string_view& a_path)
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
	[[maybe_unused]] std::string_view& a_path)
{
	//	auto file = static_cast<toml::parse_result*>(a_file);
	//	file->insert_or_assign(a_path, a_value);
}

template <>
void REX::TOML::detail::SettingLoadImpl<std::int32_t>(
	void*             a_file,
	std::int32_t&     a_value,
	std::int32_t&     a_valueDefault,
	std::string_view& a_path)
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
	[[maybe_unused]] std::string_view& a_path)
{
	//	auto file = static_cast<toml::parse_result*>(a_file);
	//	file->insert_or_assign(a_path, a_value);
}

template <>
void REX::TOML::detail::SettingLoadImpl<std::uint8_t>(
	void*             a_file,
	std::uint8_t&     a_value,
	std::uint8_t&     a_valueDefault,
	std::string_view& a_path)
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
	[[maybe_unused]] std::string_view& a_path)
{
	//	auto file = static_cast<toml::parse_result*>(a_file);
	//	file->insert_or_assign(a_path, a_value);
}

template <>
void REX::TOML::detail::SettingLoadImpl<std::uint16_t>(
	void*             a_file,
	std::uint16_t&    a_value,
	std::uint16_t&    a_valueDefault,
	std::string_view& a_path)
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
	[[maybe_unused]] std::string_view& a_path)
{
	//	auto file = static_cast<toml::parse_result*>(a_file);
	//	file->insert_or_assign(a_path, a_value);
}

template <>
void REX::TOML::detail::SettingLoadImpl<std::uint32_t>(
	void*             a_file,
	std::uint32_t&    a_value,
	std::uint32_t&    a_valueDefault,
	std::string_view& a_path)
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
	[[maybe_unused]] std::string_view& a_path)
{
	//	auto file = static_cast<toml::parse_result*>(a_file);
	//	file->insert_or_assign(a_path, a_value);
}

template <>
void REX::TOML::detail::SettingLoadImpl<std::string>(
	void*             a_file,
	std::string&      a_value,
	std::string&      a_valueDefault,
	std::string_view& a_path)
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
	[[maybe_unused]] std::string_view& a_path)
{
	//	auto file = static_cast<toml::parse_result*>(a_file);
	//	file->insert_or_assign(a_path, a_value);
}
#endif
