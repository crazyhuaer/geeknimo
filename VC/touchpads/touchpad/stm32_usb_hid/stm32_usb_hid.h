// stm32_usb_hid.h : main header file for the STM32_USB_HID application
//

#if !defined(AFX_STM32_USB_HID_H__8AF40FAD_6CDB_431E_B436_EC0CBBB1B836__INCLUDED_)
#define AFX_STM32_USB_HID_H__8AF40FAD_6CDB_431E_B436_EC0CBBB1B836__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CStm32_usb_hidApp:
// See stm32_usb_hid.cpp for the implementation of this class
//

class CStm32_usb_hidApp : public CWinApp
{
public:
	CStm32_usb_hidApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CStm32_usb_hidApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CStm32_usb_hidApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_STM32_USB_HID_H__8AF40FAD_6CDB_431E_B436_EC0CBBB1B836__INCLUDED_)
