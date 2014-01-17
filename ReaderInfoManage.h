#pragma once
#include "afxcmn.h"


// CReaderInfoManage �Ի���

class CReaderInfoManage : public CDialog
{
	DECLARE_DYNAMIC(CReaderInfoManage)

public:
	CReaderInfoManage(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CReaderInfoManage();

// �Ի�������
	enum { IDD = IDD_DIALOG_READERINFOMANAGE };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

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
