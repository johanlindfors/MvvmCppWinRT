#include "pch.h"
#include "BindableBase.h"
#include "BindableBase.g.cpp"

using namespace winrt;
using namespace Windows::UI::Xaml::Data;

namespace winrt::MvvmCppWinRT::implementation
{
	void BindableBase::RaisePropertyChanged(hstring const& propertyName)
	{
		propertyChanged(*this, PropertyChangedEventArgs(propertyName));
	}
	
	event_token BindableBase::PropertyChanged(PropertyChangedEventHandler const& handler)
	{
		return propertyChanged.add(handler);
	}
	
	void BindableBase::PropertyChanged(winrt::event_token const& token) noexcept
	{
		propertyChanged.remove(token);
	}
}
