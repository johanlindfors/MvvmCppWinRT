#pragma once

#include "MainViewModel.g.h"
#include "..\Framework\ViewModelBase.h"

namespace winrt::MvvmCppWinRT::implementation
{
	struct MainViewModel : MainViewModelT<MainViewModel, MvvmCppWinRT::implementation::ViewModelBase>
	{
		MainViewModel();

		hstring Title();
		void Title(hstring const& value);
		MvvmCppWinRT::DelegateCommand OnClickCommand() { return clickCommand; }

	private:
		void Click(Windows::Foundation::IInspectable const& parameter);

		hstring title;
		MvvmCppWinRT::DelegateCommand clickCommand{ nullptr };
	};
}

namespace winrt::MvvmCppWinRT::factory_implementation
{
	struct MainViewModel : MainViewModelT<MainViewModel, implementation::MainViewModel>
	{
	};
}
