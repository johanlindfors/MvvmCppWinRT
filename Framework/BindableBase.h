#pragma once
#include "BindableBase.g.h"

namespace winrt::MvvmCppWinRT::implementation
{
    struct BindableBase : BindableBaseT<BindableBase>
    {		
		void RaisePropertyChanged(winrt::hstring const& propertyName);
		winrt::event_token PropertyChanged(winrt::Windows::UI::Xaml::Data::PropertyChangedEventHandler const& handler);
		void PropertyChanged(winrt::event_token const& token) noexcept;

	private:
		event<winrt::Windows::UI::Xaml::Data::PropertyChangedEventHandler> propertyChanged;
    };
}

namespace winrt::MvvmCppWinRT::factory_implementation
{
    struct BindableBase : BindableBaseT<BindableBase, implementation::BindableBase>
    {
    };
}
