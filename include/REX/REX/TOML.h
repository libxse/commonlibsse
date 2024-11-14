#pragma once

#include "REX/REX/Setting.h"

#ifdef REX_OPTION_TOML
namespace REX::TOML
{
	namespace Impl
	{
		template <class T>
		void SettingLoad(void* a_file, std::string_view a_section, std::string_view a_key, T& a_value, T& a_valueDefault);

		template <class T>
		void SettingSave(void* a_file, std::string_view a_section, std::string_view a_key, T& a_value);
	}

	class SettingStore :
		public TSettingStore<SettingStore>
	{
	public:
		virtual void Load() override;
		virtual void Save() override;
	};

	template <class T, class Store = SettingStore>
	class Setting :
		public TSetting<T, Store>
	{
	public:
		Setting(std::string_view a_key, T a_default) :
			TSetting<T, Store>(a_default),
			m_section(),
			m_key(a_key)
		{}

		Setting(std::string_view a_section, std::string_view a_key, T a_default) :
			TSetting<T, Store>(a_default),
			m_section(a_section),
			m_key(a_key)
		{}

	public:
		virtual void Load(void* a_data, bool a_isBase) override
		{
			if (a_isBase) {
				Impl::SettingLoad(a_data, m_section, m_key, this->m_valueDefault, this->m_valueDefault);
				this->SetValue(this->m_valueDefault);
			} else {
				Impl::SettingLoad(a_data, m_section, m_key, this->m_value, this->m_valueDefault);
			}
		}

		virtual void Save(void* a_data) override
		{
			Impl::SettingSave(a_data, m_section, m_key, this->m_value);
		}

	private:
		std::string_view m_section;
		std::string_view m_key;
	};

	template <class Store = SettingStore>
	using Bool = Setting<bool, Store>;

	template <class Store = SettingStore>
	using F32 = Setting<float, Store>;

	template <class Store = SettingStore>
	using F64 = Setting<double, Store>;

	template <class Store = SettingStore>
	using I8 = Setting<std::int8_t, Store>;

	template <class Store = SettingStore>
	using I16 = Setting<std::int16_t, Store>;

	template <class Store = SettingStore>
	using I32 = Setting<std::int32_t, Store>;

	template <class Store = SettingStore>
	using U8 = Setting<std::uint8_t, Store>;

	template <class Store = SettingStore>
	using U16 = Setting<std::uint16_t, Store>;

	template <class Store = SettingStore>
	using U32 = Setting<std::uint32_t, Store>;

	template <class Store = SettingStore>
	using Str = Setting<std::string, Store>;
}

namespace REX::TOML::Impl
{
#	ifdef __cpp_lib_format
	template <class T, class CharT>
	struct formatter : std::formatter<T, CharT>
	{
		template <class FormatContext>
		auto format(REX::TOML::Setting<T> a_setting, FormatContext& a_ctx) const
		{
			return std::formatter<T, CharT>::format(a_setting.GetValue(), a_ctx);
		}
	};
#	endif
}

#	ifdef __cpp_lib_format
namespace std
{
	// clang-format off
	template <class CharT> struct formatter<REX::TOML::Bool<>, CharT> : REX::TOML::Impl::formatter<bool, CharT> {};
	template <class CharT> struct formatter<REX::TOML::F32<>, CharT> : REX::TOML::Impl::formatter<float, CharT> {};
	template <class CharT> struct formatter<REX::TOML::F64<>, CharT> : REX::TOML::Impl::formatter<double, CharT> {};
	template <class CharT> struct formatter<REX::TOML::I8<>, CharT> : REX::TOML::Impl::formatter<std::int8_t, CharT> {};
	template <class CharT> struct formatter<REX::TOML::I16<>, CharT> : REX::TOML::Impl::formatter<std::int16_t, CharT> {};
	template <class CharT> struct formatter<REX::TOML::I32<>, CharT> : REX::TOML::Impl::formatter<std::int32_t, CharT> {};
	template <class CharT> struct formatter<REX::TOML::U8<>, CharT> : REX::TOML::Impl::formatter<std::uint8_t, CharT> {};
	template <class CharT> struct formatter<REX::TOML::U16<>, CharT> : REX::TOML::Impl::formatter<std::uint16_t, CharT> {};
	template <class CharT> struct formatter<REX::TOML::U32<>, CharT> : REX::TOML::Impl::formatter<std::uint32_t, CharT> {};
	template <class CharT> struct formatter<REX::TOML::Str<>, CharT> : REX::TOML::Impl::formatter<std::string, CharT> {};
	// clang-format on
}
#	endif
#endif
