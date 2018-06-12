#pragma once

#include "MainViewModel.g.h"
#include "..\Framework\BindableBase.h"
#include "DelegateCommand.h"

namespace winrt::MvvmCppWinRT::implementation
{
	struct MainViewModel : MainViewModelT<MainViewModel, MvvmCppWinRT::implementation::BindableBase>
	{
		MainViewModel();

		hstring Title();
		void Title(hstring const& value);
		double TextSize();
		MvvmCppWinRT::DelegateCommand OnClickCommand() { return clickCommand; }

	private:
		void Click(Windows::Foundation::IInspectable const& parameter);
		void AnotherClick();

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
