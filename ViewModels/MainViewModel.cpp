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

void MainViewModel::Click(IInspectable const& parameter) {
	hstring value = parameter.as<IReference<hstring>>().Value();
	Title(value + L"Johan Lindfors");
}

void MainViewModel::AnotherClick() {

}