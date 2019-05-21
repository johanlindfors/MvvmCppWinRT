#pragma once

#include "winrt/Windows.UI.Xaml.h"
#include "winrt/Windows.UI.Xaml.Markup.h"
#include "winrt/Windows.UI.Xaml.Interop.h"
#include "winrt/Windows.UI.Xaml.Controls.Primitives.h"
#include "SimpleUserControl.g.h"

namespace winrt::MvvmCppWinRT::implementation
{
    struct SimpleUserControl : SimpleUserControlT<SimpleUserControl>
    {
        SimpleUserControl();

        int32_t MyProperty();
        void MyProperty(int32_t value);

        void ClickHandler(Windows::Foundation::IInspectable const& sender, Windows::UI::Xaml::RoutedEventArgs const& args);
    };
}

namespace winrt::MvvmCppWinRT::factory_implementation
{
    struct SimpleUserControl : SimpleUserControlT<SimpleUserControl, implementation::SimpleUserControl>
    {
    };
}
