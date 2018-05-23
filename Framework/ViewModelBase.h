#pragma once

#include "ViewModelBase.g.h"

namespace winrt::MvvmCppWinRT::implementation
{
	struct ViewModelBase : ViewModelBaseT<ViewModelBase>
	{
		ViewModelBase() = default;

		void RaisePropertyChanged(hstring const& propertyName);
		event_token PropertyChanged(Windows::UI::Xaml::Data::PropertyChangedEventHandler const& value);
		void PropertyChanged(event_token const& token);

	private:
		event<Windows::UI::Xaml::Data::PropertyChangedEventHandler> propertyChanged;
	};
}

namespace winrt::MvvmCppWinRT::factory_implementation
{
	struct ViewModelBase : ViewModelBaseT<ViewModelBase, implementation::ViewModelBase>
	{
	};
}
