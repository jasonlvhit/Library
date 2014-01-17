#include "afxwin.h"
#if !defined(AFX_ADMINDLG_H__C881439C_E138_4ADE_9CE0_00E5393F8105__INCLUDED_)
#define AFX_ADMINDLG_H__C881439C_E138_4ADE_9CE0_00E5393F8105__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// AdminDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CAdminDlg dialog

class CAdminDlg : public CDialog
{
// Construction
public:
	CAdminDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CAdminDlg)
	enum { IDD = IDD_DIALOG_ADMINLOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAdminDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CAdminDlg)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
	

	
	CString m_chPassword;
	CString m_chName;
	afx_msg void OnBnClickedButtonLogHelp();
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ADMINDLG_H__C881439C_E138_4ADE_9CE0_00E5393F8105__INCLUDED_)
