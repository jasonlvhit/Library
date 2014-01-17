#pragma once
#include "afxcmn.h"
#include "afxwin.h"


// CManageBook 对话框

class CManageBook : public CDialog
{
	DECLARE_DYNAMIC(CManageBook)

public:
	CManageBook(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CManageBook();

// 对话框数据
	enum { IDD = IDD_DIALOG_MANAGEBOOK };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	BOOL OnInitDialog(void);
	CListCtrl m_chList;
	
	CString m_Title;
	CString m_Author;
	CString m_Year;
	CString m_Classification;
	CString m_A;
	afx_msg void OnBnClickedButtonAdd();
	afx_msg void OnNMClickList2(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnBnClickedButtonDelete();
	void Clean(void);
	afx_msg void OnBnClickedButtonEdit();
	CComboBox m_chCombo;
	afx_msg void OnCbnSelchangeCombo1();
	afx_msg void OnBnClickedButtonGo();
	CString m_strBy1;
	CString m_strBy2;
	afx_msg void OnBnClickedButtonAll();
	afx_msg void OnBnClickedButtonClean();
	CString hit;
};
