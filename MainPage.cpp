#include "pch.h"
#include "MainPage.h"
#include "ViewModels/MainViewModel.h"

using namespace winrt;
using namespace Windows::UI::Xaml;

namespace winrt::MvvmCppWinRT::implementation
{
    MainPage::MainPage()
    {
		viewModel = make<MvvmCppWinRT::implementation::MainViewModel>();
		viewModel.Title(L"Click me");

        InitializeComponent();
    }

	MvvmCppWinRT::MainViewModel MainPage::ViewModel()
    {
		return viewModel;
    }
}
