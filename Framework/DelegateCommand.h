#pragma once

#include "DelegateCommand.g.h"

namespace winrt::MvvmCppWinRT::implementation
{
	template<typename T>
	struct DelegateCommand : DelegateCommandT<DelegateCommand<T>>
	{
		DelegateCommand(std::function<void(T)> execute) 
			: DelegateCommand(execute, nullptr) 
		{}

		DelegateCommand(std::function<void(T)> execute, std::function<bool(T)> canExecute)
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

		std::function<void(T)> executeDelegate;
		std::function<bool(T)> canExecuteDelegate;
		bool lastCanExecute = true;
	};
}
