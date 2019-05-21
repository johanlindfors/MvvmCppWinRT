#include "pch.h"
#include "SimpleUserControl.h"
#if __has_include("SimpleUserControl.g.cpp")
#include "SimpleUserControl.g.cpp"
#endif

using namespace winrt;
using namespace Windows::UI::Xaml;

namespace winrt::MvvmCppWinRT::implementation
{
    SimpleUserControl::SimpleUserControl()
    {
        InitializeComponent();
    }

    int32_t SimpleUserControl::MyProperty()
    {
        throw hresult_not_implemented();
    }

    void SimpleUserControl::MyProperty(int32_t /* value */)
    {
        throw hresult_not_implemented();
    }

    void SimpleUserControl::ClickHandler(IInspectable const&, RoutedEventArgs const&)
    {
        Button().Content(box_value(L"Clicked"));
    }
}
