#pragma once

#include "RE/B/BSAtomic.h"
#include "RE/B/BSExtraData.h"
#include "RE/B/BSPointerHandle.h"
#include "RE/E/ExtraDataTypes.h"
#include "RE/E/ExtraFlags.h"
#include "RE/E/ExtraLevCreaModifier.h"
#include "RE/F/FormTypes.h"
#include "RE/M/MemoryManager.h"
#include "RE/S/SoulLevels.h"

namespace RE
{
	class InventoryChanges;
	class TESBoundObject;

	class BaseExtraList
	{
	public:
		struct PresenceBitfield
		{
		public:
			[[nodiscard]] bool HasType(std::uint32_t a_type) const;
			void               MarkType(std::uint32_t a_type, bool a_cleared);

			// members
			std::uint8_t bits[0x18];  // 00
		};
		static_assert(sizeof(PresenceBitfield) == 0x18);

		virtual ~BaseExtraList();  // 00

		// members
		BSExtraData*      data = nullptr;      // 08
		PresenceBitfield* presence = nullptr;  // 10
	};
	static_assert(sizeof(BaseExtraList) == 0x18);

	class ExtraDataList
	{
	public:
		template <class T>
		class iterator_base
		{
		public:
			using difference_type = std::ptrdiff_t;
			using value_type = T;
			using pointer = value_type*;
			using reference = value_type&;
			using iterator_category = std::forward_iterator_tag;

			constexpr iterator_base() noexcept :
				_cur(nullptr)
			{}

			constexpr iterator_base(pointer a_node) noexcept :
				_cur(a_node)
			{}

			constexpr iterator_base(const iterator_base& a_rhs) noexcept :
				_cur(a_rhs._cur)
			{}

			constexpr iterator_base(iterator_base&& a_rhs) noexcept :
				_cur(std::move(a_rhs._cur))
			{
				a_rhs._cur = nullptr;
			}

			~iterator_base() = default;

			constexpr iterator_base& operator=(const iterator_base& a_rhs) noexcept
			{
				if (this != std::addressof(a_rhs)) {
					_cur = a_rhs._cur;
				}
				return *this;
			}

			constexpr iterator_base& operator=(iterator_base&& a_rhs) noexcept
			{
				if (this != std::addressof(a_rhs)) {
					_cur = a_rhs._cur;
					a_rhs._cur = nullptr;
				}
				return *this;
			}

			[[nodiscard]] constexpr reference operator*() const noexcept { return *_cur; }
			[[nodiscard]] constexpr pointer   operator->() const noexcept { return _cur; }

			[[nodiscard]] constexpr friend bool operator==(const iterator_base& a_lhs, const iterator_base& a_rhs) noexcept { return a_lhs._cur == a_rhs._cur; }
			[[nodiscard]] constexpr friend bool operator!=(const iterator_base& a_lhs, const iterator_base& a_rhs) noexcept { return !(a_lhs == a_rhs); }

			// prefix
			constexpr iterator_base& operator++() noexcept
			{
				assert(_cur != nullptr);
				_cur = _cur->next;
				return *this;
			}

			// postfix
			[[nodiscard]] constexpr iterator_base operator++(int) noexcept
			{
				iterator_base tmp{ *this };
				++(*this);
				return tmp;
			}

			inline friend void swap(const iterator_base& a_lhs, const iterator_base& a_rhs) noexcept
			{
				std::swap(a_lhs._cur, a_rhs._cur);
			}

		private:
			pointer _cur;
		};

		using iterator = iterator_base<BSExtraData>;
		using const_iterator = iterator_base<const BSExtraData>;

		TES_HEAP_REDEFINE_NEW();

		iterator       begin();
		const_iterator cbegin() const;
		const_iterator begin() const;
		iterator       end();
		const_iterator cend() const;
		const_iterator end() const;

		BSExtraData*       GetByType(ExtraDataType a_type);
		const BSExtraData* GetByType(ExtraDataType a_type) const;

		template <class T>
		inline T* GetByType()
		{
			return static_cast<T*>(GetByType(T::EXTRADATATYPE));
		}

		template <class T>
		inline const T* GetByType() const
		{
			return static_cast<const T*>(GetByType(T::EXTRADATATYPE));
		}

		bool HasType(ExtraDataType a_type) const;

		template <class T>
		inline bool HasType() const
		{
			return HasType(T::EXTRADATATYPE);
		}

		bool Remove(ExtraDataType a_type, BSExtraData* a_toRemove);

		template <class T>
		inline bool Remove(T* a_toRemove)
		{
			return Remove(T::EXTRADATATYPE, a_toRemove);
		}

		bool RemoveByType(ExtraDataType a_type);

		BSExtraData*          Add(BSExtraData* a_toAdd);
		ObjectRefHandle       GetAshPileRef();
		std::int32_t          GetCount() const;
		const char*           GetDisplayName(TESBoundObject* a_baseObject);
		BGSEncounterZone*     GetEncounterZone();
		ExtraTextDisplayData* GetExtraTextDisplayData();
		TESObjectREFR*        GetLinkedRef(BGSKeyword* a_keyword);
		TESForm*              GetOwner();
		SOUL_LEVEL            GetSoulLevel() const;
		ObjectRefHandle       GetTeleportLinkedDoor();
		bool                  HasQuestObjectAlias();
		void                  SetCount(std::uint16_t a_count);
		void                  SetEncounterZone(BGSEncounterZone* a_zone);
		void                  SetExtraFlags(ExtraFlags::Flag a_flags, bool a_enable);
		void                  SetHeadingTargetRefHandle(ObjectRefHandle& a_handle);
		void                  SetInventoryChanges(InventoryChanges* a_changes);
		void                  SetLevCreaModifier(LEV_CREA_MODIFIER a_modifier);
		void                  SetLinkedRef(TESObjectREFR* a_targetRef, BGSKeyword* a_keyword);
		void                  SetOwner(TESForm* a_owner);

	private:
		BSExtraData* GetByTypeImpl(ExtraDataType a_type) const;
		void         MarkType(std::uint32_t a_type, bool a_cleared);
		void         MarkType(ExtraDataType a_type, bool a_cleared);

		// members
		BaseExtraList           _extraData;  // 00
		mutable BSReadWriteLock _lock;       // 18
	};
	static_assert(sizeof(ExtraDataList) == 0x20);
}
