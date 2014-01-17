#if !defined(AFX_REGISTER_H__7B3C0E1D_80C9_4B94_9B4D_85E3B95C691E__INCLUDED_)
#define AFX_REGISTER_H__7B3C0E1D_80C9_4B94_9B4D_85E3B95C691E__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// Register.h : header file
//
#include "Resource.h"
/////////////////////////////////////////////////////////////////////////////
// CRegister dialog

class CRegister : public CDialog
{
// Construction
public:
	CRegister(CWnd* pParent = NULL);   // standard constructor
   // Generated message map f7unctions
	//{{AFX_MSG(CRegister)
	afx_msg void OnButtonOktodetail();
// Dialog Data
	//{{AFX_DATA(CRegister)
	enum { IDD = IDD_DIALOG_REGISTER };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CRegister)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButtonRegisterCancel();
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_REGISTER_H__7B3C0E1D_80C9_4B94_9B4D_85E3B95C691E__INCLUDED_)
