#include "pch.h"
#include "DelegateCommand.h"

using namespace std;
using namespace winrt;
using namespace Windows::Foundation;

namespace winrt::MvvmCppWinRT::implementation
{
	DelegateCommand::DelegateCommand(function<void(IInspectable)> const& execute)
		: DelegateCommand(execute, nullptr)
	{}

	DelegateCommand::DelegateCommand(function<void(IInspectable)> const& execute, function<bool(IInspectable)> const& canExecute)
	{
		if (execute == nullptr) {
			throw hresult_invalid_argument(L"execute");
		}
		executeDelegate = execute;
		canExecuteDelegate = canExecute;
	}

	void DelegateCommand::RaiseCanExecuteChanged()
	{
		canExecuteChanged(*this, IInspectable());
	}

	event_token DelegateCommand::CanExecuteChanged(EventHandler<IInspectable> const& handler)
	{
		return canExecuteChanged.add(handler);
	}

	void DelegateCommand::CanExecuteChanged(event_token const& token)
	{
		canExecuteChanged.remove(token);
	}

	bool DelegateCommand::CanExecute(IInspectable const& parameter)
	{
		if (canExecuteDelegate == nullptr) {
			return true;
		}

		bool canExecute = canExecuteDelegate(parameter);

		if (lastCanExecute != canExecute) {
			lastCanExecute = canExecute;
			RaiseCanExecuteChanged();
		}

		return lastCanExecute;
	}

	void DelegateCommand::Execute(IInspectable const& parameter)
	{
		if (executeDelegate != nullptr) {
			executeDelegate(parameter);
		}
	}

}