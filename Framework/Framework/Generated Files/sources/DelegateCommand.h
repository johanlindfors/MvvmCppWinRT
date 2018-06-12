#pragma once

#include "DelegateCommand.g.h"

namespace winrt::Framework::implementation
{
    struct DelegateCommand : DelegateCommandT<DelegateCommand>
    {
        DelegateCommand() = delete;

        void RaiseCanExecuteChanged();
        event_token CanExecuteChanged(Windows::Foundation::EventHandler<Windows::Foundation::IInspectable> const& value);
        void CanExecuteChanged(event_token const& token);
        bool CanExecute(Windows::Foundation::IInspectable const& parameter);
        void Execute(Windows::Foundation::IInspectable const& parameter);
    };
}
