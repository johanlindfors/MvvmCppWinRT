//
// Declaration of the DelegateCommand class.
//

#pragma once

#include "DelegateCommand.g.h"

namespace winrt::Framework::implementation
{
	struct DelegateCommand : DelegateCommandT<DelegateCommand>
	{
		DelegateCommand(std::function<void(Windows::Foundation::IInspectable)> execute)
			: DelegateCommand(execute, nullptr)
		{}

		DelegateCommand(std::function<void(Windows::Foundation::IInspectable)> execute, std::function<bool(Windows::Foundation::IInspectable)> canExecute)
		{
			if (execute == nullptr) {
				throw winrt::hresult_invalid_argument(L"execute");
			}
			executeDelegate = execute;
			canExecuteDelegate = canExecute;
		}

		void RaiseCanExecuteChanged()
		{
			canExecuteChanged(*this, Windows::Foundation::IInspectable());
		}

		winrt::event_token CanExecuteChanged(Windows::Foundation::EventHandler<Windows::Foundation::IInspectable> const& handler)
		{
			return canExecuteChanged.add(handler);
		}

		void CanExecuteChanged(event_token const& token)
		{
			canExecuteChanged.remove(token);
		}

		bool CanExecute(Windows::Foundation::IInspectable const& parameter)
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

		void Execute(Windows::Foundation::IInspectable const& parameter)
		{
			if (executeDelegate != nullptr) {
				executeDelegate(parameter);
			}
		}

	private:
		event<Windows::Foundation::EventHandler<Windows::Foundation::IInspectable>> canExecuteChanged;

		std::function<void(Windows::Foundation::IInspectable)> executeDelegate;
		std::function<bool(Windows::Foundation::IInspectable)> canExecuteDelegate;
		bool lastCanExecute = true;
	};
}