#pragma once

#include "MainViewModel.g.h"
#include "Framework/BindableBase.h"
#include "Framework/DelegateCommand.h"

namespace winrt::MvvmCppWinRT::implementation
{
	struct MainViewModel : MainViewModelT<MainViewModel, BindableBase>
	{
		MainViewModel();

		winrt::hstring Title();
		void Title(winrt::hstring const& value);
		double TextSize();
		winrt::Windows::UI::Xaml::Input::ICommand OnClickCommand() { return clickCommand; }

	private:
		void Click(winrt::Windows::Foundation::IInspectable const& parameter);
		void AnotherClick();
		bool CanClick();

		winrt::hstring title;
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
