//
// Declaration of the MainPage class.
//

#pragma once

#include "MainPage.g.h"

namespace winrt::MvvmCppWinRT::implementation
{
    struct MainPage : MainPageT<MainPage>
    {
        MainPage();

		MvvmCppWinRT::MainViewModel ViewModel();

	private:
		MvvmCppWinRT::MainViewModel viewModel{ nullptr };
    };
}

namespace winrt::MvvmCppWinRT::factory_implementation
{
    struct MainPage : MainPageT<MainPage, implementation::MainPage>
    {
    };
}
