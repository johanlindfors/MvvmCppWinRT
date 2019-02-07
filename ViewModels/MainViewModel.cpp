#include "pch.h"
#include "MainViewModel.h"

using namespace winrt;
using namespace MvvmCppWinRT::implementation;
using namespace Windows::Foundation;

MainViewModel::MainViewModel() {
	clickCommand = make<DelegateCommand>(
		//std::bind(&MainViewModel::AnotherClick, this)
		std::bind(&MainViewModel::Click, this, std::placeholders::_1)
		//,[=](IInspectable const& parameter) {
		//	hstring value = parameter.as<IReference<hstring>>().Value();
		//	Title(value + L"Johan Lindfors");
		//}
		//,[=](IInspectable const& /*parameter*/) {
		//	return title != hstring(L"Click meJohan Lindfors");
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
	Title(L"Clicked");

	textSize = 100;
	RaisePropertyChanged(L"TextSize");
}

void MainViewModel::AnotherClick() {

}