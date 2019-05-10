#pragma once
#include "pch.h"
#include "ScaleConverter.h"

using namespace std;
using namespace winrt;
using namespace Windows::Foundation;
using namespace Windows::UI::Xaml::Interop;

namespace winrt::MvvmCppWinRT::implementation
{
	IInspectable ScaleConverter::Convert(
		IInspectable const& value,
		TypeName const& targetType,
		IInspectable const& parameter,
		hstring const& /*language*/)
	{
		if (targetType.Name != L"Double")
		{
			throw hresult_invalid_argument();
		}

		double numValue = unbox_value<double>(value);

		hstring paramString = unbox_value<hstring>(parameter);

		double numParam = stod(wstring(paramString.data()));
		if (numParam == 0) {
			numParam = 1;
		}

		return box_value(numValue * numParam);
	}

	IInspectable ScaleConverter::ConvertBack(
		IInspectable const& /*value*/,
		TypeName const& /*targetType*/,
		IInspectable const& /*parameter*/,
		hstring const& /*language*/)
	{
		throw hresult_not_implemented();
	}
}
