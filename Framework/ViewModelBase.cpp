#include "pch.h"
#include "ViewModelBase.h"

using namespace winrt;
using namespace Windows::UI::Xaml::Data;
using namespace MvvmCppWinRT::implementation;

void ViewModelBase::RaisePropertyChanged(hstring const& propertyName)
{
	propertyChanged(*this, PropertyChangedEventArgs(propertyName));
}

event_token ViewModelBase::PropertyChanged(Windows::UI::Xaml::Data::PropertyChangedEventHandler const& handler)
{
	return propertyChanged.add(handler);
}

void ViewModelBase::PropertyChanged(event_token const& token)
{
	propertyChanged.remove(token);
}
