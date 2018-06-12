//
// Declaration of the BindableBase class.
//

#pragma once

#include "BindableBase.g.h"

using namespace winrt;
using namespace Windows::UI::Xaml::Data;

namespace winrt::Framework::implementation
{
	struct BindableBase : BindableBaseT<BindableBase>
	{
		void RaisePropertyChanged(hstring const& propertyName)
		{
			propertyChanged(*this, PropertyChangedEventArgs(propertyName));
		}

		event_token PropertyChanged(PropertyChangedEventHandler const& handler)
		{
			return propertyChanged.add(handler);
		}

		void PropertyChanged(event_token const& token)
		{
			propertyChanged.remove(token);
		}

	private:
		event<Windows::UI::Xaml::Data::PropertyChangedEventHandler> propertyChanged;
	};
}

namespace winrt::Framework::factory_implementation
{
    struct BindableBase : BindableBaseT<BindableBase, implementation::BindableBase>
    {
    };
}
