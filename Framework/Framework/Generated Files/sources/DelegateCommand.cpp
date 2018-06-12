#include "pch.h"
#include "DelegateCommand.h"

namespace winrt::Framework::implementation
{
    void DelegateCommand::RaiseCanExecuteChanged()
    {
        throw hresult_not_implemented();
    }

    event_token DelegateCommand::CanExecuteChanged(Windows::Foundation::EventHandler<Windows::Foundation::IInspectable> const& value)
    {
        throw hresult_not_implemented();
    }

    void DelegateCommand::CanExecuteChanged(event_token const& token)
    {
        throw hresult_not_implemented();
    }

    bool DelegateCommand::CanExecute(Windows::Foundation::IInspectable const& parameter)
    {
        throw hresult_not_implemented();
    }

    void DelegateCommand::Execute(Windows::Foundation::IInspectable const& parameter)
    {
        throw hresult_not_implemented();
    }
}
