//
// pch.h
// Header for platform projection include files
//

#pragma once

#define NOMINMAX

#include "winrt/Windows.Foundation.h"
#include "winrt/Windows.ApplicationModel.Activation.h"
#include "winrt/Windows.UI.Xaml.h"
#include "winrt/Windows.UI.Xaml.Controls.h"
#include "winrt/Windows.UI.Xaml.Controls.Primitives.h"
#include "winrt/Windows.UI.Xaml.Data.h"
#include "winrt/Windows.UI.Xaml.Interop.h"
#include "winrt/Windows.UI.Xaml.Markup.h"
#include "winrt/Windows.UI.Xaml.Navigation.h"
#include "winrt/Windows.UI.Xaml.Input.h"

#include "DelegateCommand.h"
#include "ViewModelBase.h"
#include "MainViewModel.h"
#include "ScaleConverter.h"