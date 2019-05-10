#include "pch.h"
#include "MainPage.h"
#include "MainPage.g.cpp"
#include "MainViewModel.h"

using namespace winrt;
using namespace Windows::UI::Xaml;

namespace winrt::MvvmCppWinRT::implementation
{
    MainPage::MainPage()
    {
		viewModel = make<MvvmCppWinRT::implementation::MainViewModel>();
		viewModel.Title(L"Click me");

        InitializeComponent();

		DataContext(ViewModel());
	}

	MvvmCppWinRT::MainViewModel MainPage::ViewModel()
    {
		return viewModel;
    }
}
