//
// Declaration of the DelegateCommand class.
//

#pragma once

#include "DelegateCommand.g.h"

using namespace std;
using namespace winrt;
using namespace Windows::Foundation;

namespace winrt::Framework::implementation
{
	struct DelegateCommand : DelegateCommandT<DelegateCommand>
	{
		DelegateCommand(function<void(IInspectable)> execute)
			: DelegateCommand(execute, nullptr)
		{}

		DelegateCommand(function<void(IInspectable)> execute, function<bool(IInspectable)> canExecute)
		{
			if (execute == nullptr) {
				throw hresult_invalid_argument(L"execute");
			}
			executeDelegate = execute;
			canExecuteDelegate = canExecute;
		}

		void RaiseCanExecuteChanged()
		{
			canExecuteChanged(*this, IInspectable());
		}

		event_token CanExecuteChanged(EventHandler<IInspectable> const& handler)
		{
			return canExecuteChanged.add(handler);
		}

		void CanExecuteChanged(event_token const& token)
		{
			canExecuteChanged.remove(token);
		}

		bool CanExecute(IInspectable const& parameter)
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

		void Execute(IInspectable const& parameter)
		{
			if (executeDelegate != nullptr) {
				executeDelegate(parameter);
			}
		}

	private:
		event<EventHandler<IInspectable>> canExecuteChanged;

		function<void(IInspectable)> executeDelegate;
		function<bool(IInspectable)> canExecuteDelegate;
		bool lastCanExecute = true;
	};
}