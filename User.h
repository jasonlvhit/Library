#pragma once
#include "LibraryDlg.h"
#include "afxcmn.h"

// CUser 对话框

class CUser : public CDialog
{
	DECLARE_DYNAMIC(CUser)

public:
	CUser(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CUser();

	virtual void OnFinalRelease();
	BOOL OnInitDialog();


// 对话框数据
	enum { IDD = IDD_DIALOG_USER };
	void PostNcDestroy() ;
	void OnCancel();

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
	DECLARE_DISPATCH_MAP()
	DECLARE_INTERFACE_MAP()
private:
	
public:
	afx_msg void OnBnClickedButtonreserve();
	CListCtrl m_BookList;
	afx_msg void OnBnClickedButtondestroy();
	afx_msg void OnBnClickedButton1();
	CString m_Title;
	CString m_Author;
	CString m_Year;
	CString m_Classification;
	CString m_Hot;
	afx_msg void OnNMClickList1(NMHDR *pNMHDR, LRESULT *pResult);
	CString m_DateBorrowed;
	CString m_DateShouldReturn;
	afx_msg void OnBnClickedButtonsearch2();
	afx_msg void OnBnClickedButton3();
	afx_msg void OnBnClickedButton2();
	CString m_strHot;
};
