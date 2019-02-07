#include "pch.h"
#include "MainViewModel.h"

using namespace winrt;
using namespace MvvmCppWinRT::implementation;
using namespace Windows::Foundation;

MainViewModel::MainViewModel() {
	clickCommand = make<DelegateCommand>(
		// Method without parameters
		std::bind(&MainViewModel::AnotherClick, this)

		//// Method without parameters
		//std::bind(&MainViewModel::AnotherClick, this),
		//std::bind(&MainViewModel::CanClick, this)

		//// Method with parameters
		//std::bind(&MainViewModel::Click, this, std::placeholders::_1)

		//// Simple lambdas
		//[](auto &&) {},
		//[](auto &&) -> bool { return false; }

		//// Slightly more advanced lambdas
		//[&](auto &&) { Title(L"Clicked"); },
		//[&](auto &&) -> bool { return Title() != L"Clicked"; }

		//// Lambdas
		//[=](IInspectable const& parameter) {
		//	hstring value = parameter.as<IReference<hstring>>().Value();
		//	Title(L"Clicked");
		//}
		//,[=](IInspectable const& /*parameter*/) {
		//	return title != hstring(L"Clicked");
		//}
	);

	textSize = 150;
}

hstring MainViewModel::Title() {
	return title;
}

void MainViewModel::Title(hstring const& value)
{
	if (title != value) {
		title = value;
		RaisePropertyChanged(L"Title");
		clickCommand.RaiseCanExecuteChanged();
	}
}

double MainViewModel::TextSize() {
	return textSize;
}

void MainViewModel::Click(IInspectable const& parameter) {
	hstring value = unbox_value<hstring>(parameter);
	AnotherClick();
}

void MainViewModel::AnotherClick() {
	Title(L"Clicked");

	textSize = 100;
	RaisePropertyChanged(L"TextSize");
}

bool MainViewModel::CanClick() {
	return Title() != L"Clicked";
}