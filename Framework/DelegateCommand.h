#pragma once

#include "DelegateCommand.g.h"
#include <functional>

namespace winrt::MvvmCppWinRT::implementation
{
	struct DelegateCommand : DelegateCommandT<DelegateCommand>
	{
		DelegateCommand(std::function<void(winrt::Windows::Foundation::IInspectable)> const& execute);

		DelegateCommand(std::function<void(winrt::Windows::Foundation::IInspectable)> const& execute, std::function<bool(winrt::Windows::Foundation::IInspectable)> const& canExecute);
		
		void RaiseCanExecuteChanged();

		winrt::event_token CanExecuteChanged(winrt::Windows::Foundation::EventHandler<winrt::Windows::Foundation::IInspectable> const& handler);

		void CanExecuteChanged(winrt::event_token const& token);

		bool CanExecute(winrt::Windows::Foundation::IInspectable const& parameter);

		void Execute(winrt::Windows::Foundation::IInspectable const& parameter);

	private:
		event<winrt::Windows::Foundation::EventHandler<winrt::Windows::Foundation::IInspectable>> canExecuteChanged;

		std::function<void(winrt::Windows::Foundation::IInspectable)> executeDelegate;
		std::function<bool(winrt::Windows::Foundation::IInspectable)> canExecuteDelegate;
		bool lastCanExecute = true;
	};
}
