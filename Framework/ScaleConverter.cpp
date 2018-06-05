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
		hstring const& language)
	{
		if (targetType.Name != L"double")
		{
			throw hresult_invalid_argument();
		}

		double numValue = winrt::unbox_value<double>(value);

		hstring paramString = parameter.as<IReference<hstring>>().Value();

		double numParam = stod(wstring(paramString.data()));

		return box_value(numValue * numParam);
	}

	IInspectable ScaleConverter::ConvertBack(
		IInspectable const& value, 
		TypeName const& targetType, 
		IInspectable const& parameter, 
		hstring const& language)
	{
		throw hresult_not_implemented();
	}
}
