#pragma once

namespace REX
{
	template <
		class E,
		class U = std::underlying_type_t<E>>
	class Enum
	{
	public:
		using enum_type = E;
		using underlying_type = U;

		static_assert(std::is_enum_v<E>, "Enum<E, ...> must be an enum");
		static_assert(std::is_integral_v<U>, "Enum<..., U> must be an integral");

		constexpr Enum() noexcept = default;
		constexpr Enum(const Enum&) noexcept = default;
		constexpr Enum(Enum&&) noexcept = default;

		template <class U2>  // NOLINTNEXTLINE(google-explicit-constructor)
		constexpr Enum(Enum<E, U2> a_rhs) noexcept :
			_impl(static_cast<U>(a_rhs.get()))
		{}

		constexpr Enum(E a_value) noexcept :
			_impl(static_cast<U>(a_value))
		{}

		~Enum() noexcept = default;

		constexpr Enum& operator=(const Enum&) noexcept = default;
		constexpr Enum& operator=(Enum&&) noexcept = default;

		template <class U2>
		constexpr Enum& operator=(Enum<E, U2> a_rhs) noexcept
		{
			_impl = static_cast<U>(a_rhs.get());
		}

		constexpr Enum& operator=(E a_value) noexcept
		{
			_impl = static_cast<U>(a_value);
			return *this;
		}

	public:
		[[nodiscard]] explicit constexpr operator bool() const noexcept { return _impl != static_cast<U>(0); }

		[[nodiscard]] constexpr E operator*() const noexcept { return get(); }
		[[nodiscard]] constexpr E get() const noexcept { return static_cast<E>(_impl); }
		[[nodiscard]] constexpr U underlying() const noexcept { return _impl; }

	public:
		friend constexpr bool operator==(Enum a_lhs, Enum a_rhs) noexcept { return a_lhs.underlying() == a_rhs.underlying(); }
		friend constexpr bool operator==(Enum a_lhs, E a_rhs) noexcept { return a_lhs.underlying() == static_cast<U>(a_rhs); }
		friend constexpr bool operator==(E a_lhs, Enum a_rhs) noexcept { return static_cast<U>(a_lhs) == a_rhs.underlying(); }

	private:
		U _impl{ 0 };
	};

	template <class... Args>
	Enum(Args...) -> Enum<
		std::common_type_t<Args...>,
		std::underlying_type_t<
			std::common_type_t<Args...>>>;
}

namespace REX
{
	template <
		class E,
		class U = std::underlying_type_t<E>>
	class EnumSet
	{
	public:
		using enum_type = E;
		using underlying_type = U;

		static_assert(std::is_enum_v<E>, "EnumSet<E, ...> must be an enum");
		static_assert(std::is_integral_v<U>, "EnumSet<..., U> must be an integral");

		constexpr EnumSet() noexcept = default;
		constexpr EnumSet(const EnumSet&) noexcept = default;
		constexpr EnumSet(EnumSet&&) noexcept = default;

		template <class U2>  // NOLINTNEXTLINE(google-explicit-constructor)
		constexpr EnumSet(EnumSet<E, U2> a_rhs) noexcept :
			_impl(static_cast<U>(a_rhs.get()))
		{}

		template <class... Args>
		constexpr EnumSet(Args... a_values) noexcept
			requires(std::same_as<Args, E>&&...) :
			_impl((static_cast<U>(a_values) | ...))
		{}

		~EnumSet() noexcept = default;

		constexpr EnumSet& operator=(const EnumSet&) noexcept = default;
		constexpr EnumSet& operator=(EnumSet&&) noexcept = default;

		template <class U2>
		constexpr EnumSet& operator=(EnumSet<E, U2> a_rhs) noexcept
		{
			_impl = static_cast<U>(a_rhs.get());
		}

		constexpr EnumSet& operator=(E a_value) noexcept
		{
			_impl = static_cast<U>(a_value);
			return *this;
		}

	public:
		[[nodiscard]] explicit constexpr operator bool() const noexcept { return _impl != static_cast<U>(0); }

		[[nodiscard]] constexpr E operator*() const noexcept { return get(); }
		[[nodiscard]] constexpr E get() const noexcept { return static_cast<E>(_impl); }
		[[nodiscard]] constexpr U underlying() const noexcept { return _impl; }

	public:
		template <class... Args>
		constexpr EnumSet& set(Args... a_args) noexcept
			requires(std::same_as<Args, E>&&...)
		{
			_impl |= (static_cast<U>(a_args) | ...);
			return *this;
		}

		template <class... Args>
		constexpr EnumSet& set(bool a_set, Args... a_args) noexcept
			requires(std::same_as<Args, E>&&...)
		{
			if (a_set)
				_impl |= (static_cast<U>(a_args) | ...);
			else
				_impl &= ~(static_cast<U>(a_args) | ...);

			return *this;
		}

		template <class... Args>
		constexpr EnumSet& reset(Args... a_args) noexcept
			requires(std::same_as<Args, E>&&...)
		{
			_impl &= ~(static_cast<U>(a_args) | ...);
			return *this;
		}

		constexpr EnumSet& reset() noexcept
		{
			_impl = 0;
			return *this;
		}

		template <class... Args>
		[[nodiscard]] constexpr bool any(Args... a_args) const noexcept
			requires(std::same_as<Args, E>&&...)
		{
			return (_impl & (static_cast<U>(a_args) | ...)) != static_cast<U>(0);
		}

		template <class... Args>
		[[nodiscard]] constexpr bool all(Args... a_args) const noexcept
			requires(std::same_as<Args, E>&&...)
		{
			return (_impl & (static_cast<U>(a_args) | ...)) == (static_cast<U>(a_args) | ...);
		}

		template <class... Args>
		[[nodiscard]] constexpr bool none(Args... a_args) const noexcept
			requires(std::same_as<Args, E>&&...)
		{
			return (_impl & (static_cast<U>(a_args) | ...)) == static_cast<U>(0);
		}

	public:
		friend constexpr bool operator==(EnumSet a_lhs, EnumSet a_rhs) noexcept { return a_lhs.underlying() == a_rhs.underlying(); }
		friend constexpr bool operator==(EnumSet a_lhs, E a_rhs) noexcept { return a_lhs.underlying() == static_cast<U>(a_rhs); }
		friend constexpr bool operator==(E a_lhs, EnumSet a_rhs) noexcept { return static_cast<U>(a_lhs) == a_rhs.underlying(); }

		friend constexpr std::strong_ordering operator<=>(EnumSet a_lhs, EnumSet a_rhs) noexcept { return a_lhs.underlying() <=> a_rhs.underlying(); }
		friend constexpr std::strong_ordering operator<=>(EnumSet a_lhs, E a_rhs) noexcept { return a_lhs.underlying() <=> static_cast<U>(a_rhs); }
		friend constexpr std::strong_ordering operator<=>(E a_lhs, EnumSet a_rhs) noexcept { return static_cast<U>(a_lhs) <=> a_rhs.underlying(); }

		friend constexpr EnumSet operator&(EnumSet a_lhs, EnumSet a_rhs) noexcept { return static_cast<E>(a_lhs.underlying() & a_rhs.underlying()); }
		friend constexpr EnumSet operator&(EnumSet a_lhs, E a_rhs) noexcept { return static_cast<E>(a_lhs.underlying() & static_cast<U>(a_rhs)); }
		friend constexpr EnumSet operator&(E a_lhs, EnumSet a_rhs) noexcept { return static_cast<E>(static_cast<U>(a_lhs) & a_rhs.underlying()); }

		friend constexpr EnumSet& operator&=(EnumSet& a_lhs, EnumSet a_rhs) noexcept { return a_lhs = a_lhs & a_rhs; }
		friend constexpr EnumSet& operator&=(EnumSet& a_lhs, E a_rhs) noexcept { return a_lhs = a_lhs & a_rhs; }

		friend constexpr EnumSet operator|(EnumSet a_lhs, EnumSet a_rhs) noexcept { return static_cast<E>(a_lhs.underlying() | a_rhs.underlying()); }
		friend constexpr EnumSet operator|(EnumSet a_lhs, E a_rhs) noexcept { return static_cast<E>(a_lhs.underlying() | static_cast<U>(a_rhs)); }
		friend constexpr EnumSet operator|(E a_lhs, EnumSet a_rhs) noexcept { return static_cast<E>(static_cast<U>(a_lhs) | a_rhs.underlying()); }

		friend constexpr EnumSet& operator|=(EnumSet& a_lhs, EnumSet a_rhs) noexcept { return a_lhs = a_lhs | a_rhs; }
		friend constexpr EnumSet& operator|=(EnumSet& a_lhs, E a_rhs) noexcept { return a_lhs = a_lhs | a_rhs; }

		friend constexpr EnumSet operator^(EnumSet a_lhs, EnumSet a_rhs) noexcept { return static_cast<E>(a_lhs.underlying() ^ a_rhs.underlying()); }
		friend constexpr EnumSet operator^(EnumSet a_lhs, E a_rhs) noexcept { return static_cast<E>(a_lhs.underlying() ^ static_cast<U>(a_rhs)); }
		friend constexpr EnumSet operator^(E a_lhs, EnumSet a_rhs) noexcept { return static_cast<E>(static_cast<U>(a_lhs) ^ a_rhs.underlying()); }

		friend constexpr EnumSet& operator^=(EnumSet& a_lhs, EnumSet a_rhs) noexcept { return a_lhs = a_lhs ^ a_rhs; }
		friend constexpr EnumSet& operator^=(EnumSet& a_lhs, E a_rhs) noexcept { return a_lhs = a_lhs ^ a_rhs; }

		friend constexpr EnumSet operator+(EnumSet a_lhs, EnumSet a_rhs) noexcept { return static_cast<E>(a_lhs.underlying() + a_rhs.underlying()); }
		friend constexpr EnumSet operator+(EnumSet a_lhs, E a_rhs) noexcept { return static_cast<E>(a_lhs.underlying() + static_cast<U>(a_rhs)); }
		friend constexpr EnumSet operator+(E a_lhs, EnumSet a_rhs) noexcept { return static_cast<E>(static_cast<U>(a_lhs) + a_rhs.underlying()); }

		friend constexpr EnumSet& operator+=(EnumSet& a_lhs, EnumSet a_rhs) noexcept { return a_lhs = a_lhs + a_rhs; }
		friend constexpr EnumSet& operator+=(EnumSet& a_lhs, E a_rhs) noexcept { return a_lhs = a_lhs + a_rhs; }

		friend constexpr EnumSet operator-(EnumSet a_lhs, EnumSet a_rhs) noexcept { return static_cast<E>(a_lhs.underlying() - a_rhs.underlying()); }
		friend constexpr EnumSet operator-(EnumSet a_lhs, E a_rhs) noexcept { return static_cast<E>(a_lhs.underlying() - static_cast<U>(a_rhs)); }
		friend constexpr EnumSet operator-(E a_lhs, EnumSet a_rhs) noexcept { return static_cast<E>(static_cast<U>(a_lhs) - a_rhs.underlying()); }

		friend constexpr EnumSet& operator-=(EnumSet& a_lhs, EnumSet a_rhs) noexcept { return a_lhs = a_lhs - a_rhs; }
		friend constexpr EnumSet& operator-=(EnumSet& a_lhs, E a_rhs) noexcept { return a_lhs = a_lhs - a_rhs; }

		friend constexpr EnumSet operator<<(EnumSet a_lhs, EnumSet a_rhs) noexcept { return static_cast<E>(a_lhs.underlying() << a_rhs.underlying()); }
		friend constexpr EnumSet operator<<(EnumSet a_lhs, E a_rhs) noexcept { return static_cast<E>(a_lhs.underlying() << static_cast<U>(a_rhs)); }
		friend constexpr EnumSet operator<<(E a_lhs, EnumSet a_rhs) noexcept { return static_cast<E>(static_cast<U>(a_lhs) << a_rhs.underlying()); }

		friend constexpr EnumSet& operator<<=(EnumSet& a_lhs, EnumSet a_rhs) noexcept { return a_lhs = a_lhs << a_rhs; }
		friend constexpr EnumSet& operator<<=(EnumSet& a_lhs, E a_rhs) noexcept { return a_lhs = a_lhs << a_rhs; }

		friend constexpr EnumSet operator>>(EnumSet a_lhs, EnumSet a_rhs) noexcept { return static_cast<E>(a_lhs.underlying() >> a_rhs.underlying()); }
		friend constexpr EnumSet operator>>(EnumSet a_lhs, E a_rhs) noexcept { return static_cast<E>(a_lhs.underlying() >> static_cast<U>(a_rhs)); }
		friend constexpr EnumSet operator>>(E a_lhs, EnumSet a_rhs) noexcept { return static_cast<E>(static_cast<U>(a_lhs) >> a_rhs.underlying()); }

		friend constexpr EnumSet& operator>>=(EnumSet& a_lhs, EnumSet a_rhs) noexcept { return a_lhs = a_lhs >> a_rhs; }
		friend constexpr EnumSet& operator>>=(EnumSet& a_lhs, E a_rhs) noexcept { return a_lhs = a_lhs >> a_rhs; }

		friend constexpr EnumSet& operator~(EnumSet& a_lhs) noexcept { return a_lhs = ~a_lhs.underlying(); }

	private:
		U _impl{ 0 };
	};

	template <class... Args>
	EnumSet(Args...) -> EnumSet<
		std::common_type_t<Args...>,
		std::underlying_type_t<
			std::common_type_t<Args...>>>;
}

namespace REX
{
	template <class T>
	class Singleton
	{
	public:
		static T* GetSingleton()
		{
			static T singleton;
			return std::addressof(singleton);
		}

	protected:
		Singleton() = default;
		~Singleton() = default;

		Singleton(const Singleton&) = delete;
		Singleton(Singleton&&) = delete;

		Singleton& operator=(const Singleton&) = delete;
		Singleton& operator=(Singleton&&) = delete;
	};
}

namespace REX
{
	class ISetting
	{
	public:
		virtual void Load(void* a_file) = 0;
		virtual void Save(void* a_file) = 0;
	};

	class ISettingStore
	{
	public:
		virtual void Init(const char* a_file, const char* a_fileCustom) = 0;
		virtual void Load() = 0;
		virtual void Save() = 0;
		virtual void Register(ISetting* a_setting) = 0;
	};

	template <class T, class Store>
	class TSetting :
		public ISetting
	{
	public:
		TSetting() = delete;

		TSetting(T a_default) :
			m_value(a_default),
			m_valueDefault(a_default)
		{
			Store::GetSingleton()->Register(this);
		}

	public:
		T GetValue() const { return m_value; }

		T GetValueDefault() const { return m_valueDefault; }

		void SetValue(T a_value) const { m_value = a_value; }

	protected:
		T m_value;
		T m_valueDefault;
	};

	template <class T>
	class TSettingStore :
		public ISettingStore,
		public Singleton<T>
	{
	public:
		virtual void Init(const char* a_fileBase, const char* a_fileUser) override
		{
			m_fileBase = a_fileBase;
			m_fileUser = a_fileUser;
		}

		virtual void Register(ISetting* a_setting) override
		{
			m_settings.emplace_back(a_setting);
		}

	protected:
		std::string_view       m_fileBase;
		std::string_view       m_fileUser;
		std::vector<ISetting*> m_settings;
	};
}

#ifdef REX_OPTION_INI
#	include <SimpleIni.h>

namespace REX::INI
{
	class SettingStore :
		public TSettingStore<SettingStore>
	{
	public:
		virtual void Load() override
		{
			CSimpleIniA ini;
			ini.SetUnicode(true);
			ini.SetQuotes(true);

			if (ini.LoadFile(m_fileBase.data()) == SI_OK) {
				for (auto& setting : m_settings) {
					setting->Load(&ini);
				}
			}

			if (ini.LoadFile(m_fileUser.data()) == SI_OK) {
				for (auto& setting : m_settings) {
					setting->Load(&ini);
				}
			}
		}

		virtual void Save() override
		{
			CSimpleIniA ini;
			ini.SetUnicode(true);
			ini.SetQuotes(true);

			ini.LoadFile(m_fileBase.data());
			for (auto& setting : m_settings) {
				setting->Save(&ini);
			}

			ini.SaveFile(m_fileBase.data(), false);
		}
	};

	template <class T, class Store = SettingStore>
	class Setting :
		public TSetting<T, Store>
	{
	public:
		Setting(std::string_view a_section, std::string_view a_key, T a_default) :
			TSetting<T, Store>(a_default),
			m_section(a_section),
			m_key(a_key)
		{}

	public:
		virtual void Load(void* a_file) override
		{
			auto file = static_cast<CSimpleIniA*>(a_file);
			if constexpr (std::is_same_v<T, bool>) {
				this->m_value = file->GetBoolValue(m_section.data(), m_key.data(), this->m_valueDefault);
			} else if constexpr (std::is_floating_point_v<T>) {
				this->m_value = static_cast<T>(file->GetDoubleValue(m_section.data(), m_key.data(), this->m_valueDefault));
			} else if constexpr (std::is_same_v<T, std::uint8_t> || std::is_same_v<T, std::uint16_t> || std::is_same_v<T, std::uint32_t> || std::is_same_v<T, std::int8_t> || std::is_same_v<T, std::int16_t> || std::is_same_v<T, std::int32_t>) {
				this->m_value = static_cast<T>(file->GetLongValue(m_section.data(), m_key.data(), this->m_valueDefault));
			} else if constexpr (std::is_same_v<T, std::string>) {
				this->m_value = file->GetValue(m_section.data(), m_key.data(), this->m_valueDefault.c_str());
			}
		}

		virtual void Save(void* a_file) override
		{
			auto file = static_cast<CSimpleIniA*>(a_file);
			if constexpr (std::is_same_v<T, bool>) {
				file->SetBoolValue(m_section.data(), m_key.data(), this->m_value);
			} else if constexpr (std::is_floating_point_v<T>) {
				file->SetDoubleValue(m_section.data(), m_key.data(), static_cast<double>(this->m_value));
			} else if constexpr (std::is_same_v<T, std::uint8_t> || std::is_same_v<T, std::uint16_t> || std::is_same_v<T, std::uint32_t> || std::is_same_v<T, std::int8_t> || std::is_same_v<T, std::int16_t> || std::is_same_v<T, std::int32_t>) {
				file->SetLongValue(m_section.data(), m_key.data(), static_cast<long>(this->m_value));
			} else if constexpr (std::is_same_v<T, std::string>) {
				file->SetValue(m_section.data(), m_key.data(), this->m_value.c_str());
			}
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
#endif

#ifdef REX_OPTION_TOML
#	define TOML_EXCEPTIONS 0
#	include <toml++/toml.h>

namespace REX::TOML
{
	class SettingStore :
		public TSettingStore<SettingStore>
	{
	public:
		virtual void Load() override
		{
			if (auto result = toml::parse_file(m_file)) {
				for (auto& setting : m_settings)
					setting->Load(&result);
			}

			if (auto result = toml::parse_file(m_fileCustom)) {
				for (auto& setting : m_settings)
					setting->Load(&result);
			}
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
			auto file = static_cast<toml::parse_result*>(a_file);
			if (auto node = file->at_path(m_path)) {
				this->m_value = node.value_or(this->m_valueDefault);
			}
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
