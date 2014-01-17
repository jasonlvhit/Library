#pragma once
#include "afxcmn.h"


// CReaderInfoManage 对话框

class CReaderInfoManage : public CDialog
{
	DECLARE_DYNAMIC(CReaderInfoManage)

public:
	CReaderInfoManage(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CReaderInfoManage();

// 对话框数据
	enum { IDD = IDD_DIALOG_READERINFOMANAGE };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CListCtrl m_chList1;
	afx_msg void OnLvnItemchangedList1(NMHDR *pNMHDR, LRESULT *pResult);
	BOOL OnInitDialog(void);
	CListCtrl m_chList2;
	afx_msg void OnNMClickList1(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnBnClickedButtonAdd();
	afx_msg void OnBnClickedButtonDelete();
	CString m_strE_Mail;
	CString m_strName;
	CString m_strPassWord;
	CString m_strInterest;
	CString m_strMajor;
	CString m_strFinancial;
	afx_msg void OnLvnItemchangedList2(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnBnClickedButtonOut();
	CString search;
	afx_msg void OnBnClickedButtonGo();
};
