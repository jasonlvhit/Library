#pragma once
#include "afxcmn.h"
#include "afxwin.h"


// CSearch �Ի���

class CSearch : public CDialog
{
	DECLARE_DYNAMIC(CSearch)

public:
	CSearch(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CSearch();

// �Ի�������
	enum { IDD = IDD_DIALOG_SEARCH };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButtonSearch();
	CListCtrl m_chList;

	CString m_Author;
	CString m_Title;
	CString m_Year;
	CString m_Classification;
	CString m_A;
	BOOL OnInitDialog(void);
	CComboBox m_chCombo;
	afx_msg void OnNMClickList1(NMHDR *pNMHDR, LRESULT *pResult);
	CString m_strBy1;
	CString m_strBy2;
	afx_msg void OnBnClickedButtonAll();
	CString hit;
	afx_msg void OnBnClickedButtonReserve();
};
