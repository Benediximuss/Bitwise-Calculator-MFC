
// Bitwise_Calculator.h : main header file for the PROJECT_NAME application
//

#pragma once

#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif

#include "resource.h"		// main symbols


// CBitwise_CalculatorApp:
// See Bitwise_Calculator.cpp for the implementation of this class
//

class CBitwise_CalculatorApp : public CWinApp
{
public:
	CBitwise_CalculatorApp();

// Overrides
public:
	virtual BOOL InitInstance();

// Implementation

	DECLARE_MESSAGE_MAP()
};

extern CBitwise_CalculatorApp theApp;