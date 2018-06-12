#pragma once

#include "BindableBase.g.h"

namespace winrt::Framework::implementation
{
    struct BindableBase : BindableBaseT<BindableBase>
    {
        BindableBase() = default;

        void RaisePropertyChanged(hstring const& propertyName);
        event_token PropertyChanged(Windows::UI::Xaml::Data::PropertyChangedEventHandler const& value);
        void PropertyChanged(event_token const& token);
    };
}

namespace winrt::Framework::factory_implementation
{
    struct BindableBase : BindableBaseT<BindableBase, implementation::BindableBase>
    {
    };
}
