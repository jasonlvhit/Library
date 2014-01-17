#pragma once
#include "afxcmn.h"


// CInsertBook �Ի���

class CInsertBook : public CDialog
{
	DECLARE_DYNAMIC(CInsertBook)

public:
	CInsertBook(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CInsertBook();
	BOOL OnInitDialog();

// �Ի�������
	enum { IDD = IDD_INSERTBOOK };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

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
