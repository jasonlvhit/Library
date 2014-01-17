#pragma once
#include "afxcmn.h"



// CUserInformation 对话框

class CUserInformation : public CDialog
{
	DECLARE_DYNAMIC(CUserInformation)

public:
	CUserInformation(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CUserInformation();
	BOOL OnInitDialog();

// 对话框数据
	enum { IDD = IDD_DIALOG_USERINFORMATION };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnLvnItemchangedList1(NMHDR *pNMHDR, LRESULT *pResult);
	CListCtrl m_List;
	
	afx_msg void OnNMClickList1(NMHDR *pNMHDR, LRESULT *pResult);
	CString m_strPassWord;
	CString m_strName;
	CString m_strInterest;
	CString m_strMajor;
	CString m_strInteres;
	afx_msg void OnBnClickedButtonDestroy();
	afx_msg void OnBnClickedButtonSave();
	afx_msg void OnEnChangeEdit1();
};
