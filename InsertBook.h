#pragma once
#include "afxcmn.h"


// CInsertBook 对话框

class CInsertBook : public CDialog
{
	DECLARE_DYNAMIC(CInsertBook)

public:
	CInsertBook(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CInsertBook();
	BOOL OnInitDialog();

// 对话框数据
	enum { IDD = IDD_INSERTBOOK };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CListCtrl m_chList;
	CString m_Title;
	CString m_Author;
	CString m_Year;
	CString m_Classification;
	CString m_Hot;
	CString m_A;
	afx_msg void OnNMClickList1(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnBnClickedButton1();
	afx_msg void OnEnChangeEdit8();
	CString m_DateBorrowed;
	CString m_DateShouldReturn;
};
