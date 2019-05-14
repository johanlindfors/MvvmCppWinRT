#pragma once
#include "ScaleConverter.g.h"

namespace winrt::MvvmCppWinRT::implementation
{
	struct ScaleConverter : ScaleConverterT<ScaleConverter>
	{
		ScaleConverter() = default;

		winrt::Windows::Foundation::IInspectable Convert(
			winrt::Windows::Foundation::IInspectable const& value,
			winrt::Windows::UI::Xaml::Interop::TypeName const& targetType,
			winrt::Windows::Foundation::IInspectable const& parameter,
			winrt::hstring const& language);

		winrt::Windows::Foundation::IInspectable ConvertBack(
			winrt::Windows::Foundation::IInspectable const& value,
			winrt::Windows::UI::Xaml::Interop::TypeName const& targetType,
			winrt::Windows::Foundation::IInspectable const& parameter,
			winrt::hstring const& language);
	};
}

namespace winrt::MvvmCppWinRT::factory_implementation
{
	struct ScaleConverter : ScaleConverterT<ScaleConverter, implementation::ScaleConverter>
	{
	};
}
