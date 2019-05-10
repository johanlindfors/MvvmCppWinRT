#pragma once

#include "MainViewModel.g.h"
#include "BindableBase.h"
#include "DelegateCommand.h"

namespace winrt::MvvmCppWinRT::implementation
{
	struct MainViewModel : MainViewModelT<MainViewModel, BindableBase>
	{
		MainViewModel();

		hstring Title();
		void Title(hstring const& value);
		double TextSize();
		winrt::Windows::UI::Xaml::Input::ICommand OnClickCommand() { return clickCommand; }

	private:
		void Click(Windows::Foundation::IInspectable const& parameter);
		void AnotherClick();
		bool CanClick();

		hstring title;
		double textSize;
		MvvmCppWinRT::DelegateCommand clickCommand{ nullptr };
	};
}

namespace winrt::MvvmCppWinRT::factory_implementation
{
	struct MainViewModel : MainViewModelT<MainViewModel, implementation::MainViewModel>
	{
	};
}
