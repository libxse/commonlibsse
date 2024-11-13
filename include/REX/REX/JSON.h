#pragma once

#include "REX/REX/Setting.h"

#ifdef REX_OPTION_JSON
namespace REX::JSON
{
	namespace detail
	{
		void StoreLoadImpl(std::string_view& a_fileBase, std::string_view& a_fileUser, std::vector<ISetting*>& a_settings);
		void StoreSaveImpl(std::string_view& a_fileBase, std::vector<ISetting*>& a_settings);
		template <class T>
		void SettingLoadImpl(void* a_file, T& a_value, T& a_valueDefault, std::string_view& a_path);
		template <class T>
		void SettingSaveImpl(void* a_file, T& a_value, std::string_view& a_path);
	}

	class SettingStore :
		public TSettingStore<SettingStore>
	{
	public:
		virtual void Load() override
		{
			detail::StoreLoadImpl(m_fileBase, m_fileUser, m_settings);
		}

		virtual void Save() override
		{
			detail::StoreSaveImpl(m_fileBase, m_settings);
		}
	};

	template <class T, class Store = SettingStore>
	class Setting :
		public TSetting<T, Store>
	{
	public:
		Setting(std::string_view a_path, T a_default) :
			TSetting<T, Store>(a_default),
			m_path(a_path)
		{}

	public:
		virtual void Load(void* a_file) override
		{
			detail::SettingLoadImpl(a_file, this->m_value, this->m_valueDefault, m_path);
		}

		virtual void Save(void* a_file) override
		{
			detail::SettingSaveImpl(a_file, this->m_value, m_path);
		}

	private:
		std::string_view m_path;
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
#endif
