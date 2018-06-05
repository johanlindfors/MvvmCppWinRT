#pragma once

#include "ScaleConverter.g.h"

namespace winrt::MvvmCppWinRT::implementation
{
	struct ScaleConverter : ScaleConverterT<ScaleConverter>
	{
		ScaleConverter() = default;

		Windows::Foundation::IInspectable Convert(Windows::Foundation::IInspectable const& value, Windows::UI::Xaml::Interop::TypeName const& targetType, Windows::Foundation::IInspectable const& parameter, hstring const& language);
		Windows::Foundation::IInspectable ConvertBack(Windows::Foundation::IInspectable const& value, Windows::UI::Xaml::Interop::TypeName const& targetType, Windows::Foundation::IInspectable const& parameter, hstring const& language);
	};
}

namespace winrt::MvvmCppWinRT::factory_implementation
{
	struct ScaleConverter : ScaleConverterT<ScaleConverter, implementation::ScaleConverter>
	{
	};
}
