﻿// WARNING: Please don't edit this file. It was generated by C++/WinRT v1.0.180227.3

#pragma once
#include "winrt/base.h"

WINRT_WARNING_PUSH

static_assert(winrt::check_version(CPPWINRT_VERSION, "1.0.180227.3"), "Mismatched component and base headers.");
#include "winrt/Windows.Foundation.h"
#include "winrt/Windows.Foundation.Collections.h"
#include "winrt/impl/Windows.UI.Xaml.Data.2.h"
#include "winrt/impl/Windows.UI.Xaml.2.h"
#include "winrt/impl/Windows.UI.Xaml.Input.2.h"
#include "winrt/impl/Framework.2.h"

namespace winrt::impl {

template <typename D> Framework::BindableBase consume_Framework_IBindableBaseFactory<D>::CreateInstance(Windows::Foundation::IInspectable const& baseInterface, Windows::Foundation::IInspectable& innerInterface) const
{
    Framework::BindableBase value{ nullptr };
    check_hresult(WINRT_SHIM(Framework::IBindableBaseFactory)->CreateInstance(get_abi(baseInterface), put_abi(innerInterface), put_abi(value)));
    return value;
}

template <typename D> void consume_Framework_IBindableBaseProtected<D>::RaisePropertyChanged(param::hstring const& propertyName) const
{
    check_hresult(WINRT_SHIM(Framework::IBindableBaseProtected)->RaisePropertyChanged(get_abi(propertyName)));
}

template <typename D> void consume_Framework_IDelegateCommand<D>::RaiseCanExecuteChanged() const
{
    check_hresult(WINRT_SHIM(Framework::IDelegateCommand)->RaiseCanExecuteChanged());
}

template <typename D>
struct produce<D, Framework::IBindableBaseFactory> : produce_base<D, Framework::IBindableBaseFactory>
{
    HRESULT __stdcall CreateInstance(void* baseInterface, void** innerInterface, void** value) noexcept final
    {
        try
        {
            if (innerInterface) *innerInterface = nullptr;
            *value = nullptr;
            typename D::abi_guard guard(this->shim());
            Windows::Foundation::IInspectable __local_innerInterface;
            *value = detach_from<Framework::BindableBase>(this->shim().CreateInstance(*reinterpret_cast<Windows::Foundation::IInspectable const*>(&baseInterface), __local_innerInterface));
            if (innerInterface) *innerInterface = detach_abi(__local_innerInterface);
            return S_OK;
        }
        catch (...)
        {
            return to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Framework::IBindableBaseProtected> : produce_base<D, Framework::IBindableBaseProtected>
{
    HRESULT __stdcall RaisePropertyChanged(HSTRING propertyName) noexcept final
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().RaisePropertyChanged(*reinterpret_cast<hstring const*>(&propertyName));
            return S_OK;
        }
        catch (...)
        {
            return to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Framework::IDelegateCommand> : produce_base<D, Framework::IDelegateCommand>
{
    HRESULT __stdcall RaiseCanExecuteChanged() noexcept final
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().RaiseCanExecuteChanged();
            return S_OK;
        }
        catch (...)
        {
            return to_hresult();
        }
    }
};

}

WINRT_EXPORT namespace winrt::Framework {

inline BindableBase::BindableBase()
{
    Windows::Foundation::IInspectable baseInterface, innerInterface;
    *this = get_activation_factory<BindableBase, Framework::IBindableBaseFactory>().CreateInstance(baseInterface, innerInterface);
}

template <typename D, typename... Interfaces>
struct BindableBaseT :
    implements<D, Windows::Foundation::IInspectable, composing, Interfaces...>,
    impl::require<D, Framework::IBindableBaseProtected, Windows::UI::Xaml::Data::INotifyPropertyChanged, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2>
{
    using composable = BindableBase;

protected:
    BindableBaseT()
    {
        get_activation_factory<Framework::BindableBase, Framework::IBindableBaseFactory>().CreateInstance(*this, this->m_inner);
    }
};

}

WINRT_EXPORT namespace std {

template<> struct hash<winrt::Framework::IBindableBaseFactory> : winrt::impl::hash_base<winrt::Framework::IBindableBaseFactory> {};
template<> struct hash<winrt::Framework::IBindableBaseProtected> : winrt::impl::hash_base<winrt::Framework::IBindableBaseProtected> {};
template<> struct hash<winrt::Framework::IDelegateCommand> : winrt::impl::hash_base<winrt::Framework::IDelegateCommand> {};
template<> struct hash<winrt::Framework::BindableBase> : winrt::impl::hash_base<winrt::Framework::BindableBase> {};
template<> struct hash<winrt::Framework::DelegateCommand> : winrt::impl::hash_base<winrt::Framework::DelegateCommand> {};

}

WINRT_WARNING_POP
