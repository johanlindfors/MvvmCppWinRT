#pragma once

#include "ScaleConverter.g.h"

using namespace std;
using namespace winrt;
using namespace Windows::Foundation;
using namespace Windows::UI::Xaml::Interop;

namespace winrt::MvvmCppWinRT::implementation
{
	struct ScaleConverter : ScaleConverterT<ScaleConverter>
	{
		ScaleConverter() = default;

		IInspectable Convert(
			IInspectable const& value,
			TypeName const& targetType,
			IInspectable const& parameter,
			hstring const& /*language*/) 
		{
			if (targetType.Name != L"Double")
			{
				throw hresult_invalid_argument();
			}

			double numValue = winrt::unbox_value<double>(value);

			hstring paramString = unbox_value<hstring>(parameter);

			double numParam = stod(wstring(paramString.data()));
			if (numParam == 0) {
				numParam = 1;
			}

			return box_value(numValue * numParam);
		}

		IInspectable ConvertBack(
			IInspectable const& /*value*/,
			TypeName const& /*targetType*/,
			IInspectable const& /*parameter*/,
			hstring const& /*language*/) 
		{
			throw hresult_not_implemented();
		}
	};
}

namespace winrt::MvvmCppWinRT::factory_implementation
{
	struct ScaleConverter : ScaleConverterT<ScaleConverter, implementation::ScaleConverter>
	{
	};
}
