#include "pch.h"
#include "BindableBase.h"

namespace winrt::Framework::implementation
{
    void BindableBase::RaisePropertyChanged(hstring const& propertyName)
    {
        throw hresult_not_implemented();
    }

    event_token BindableBase::PropertyChanged(Windows::UI::Xaml::Data::PropertyChangedEventHandler const& value)
    {
        throw hresult_not_implemented();
    }

    void BindableBase::PropertyChanged(event_token const& token)
    {
        throw hresult_not_implemented();
    }
}
