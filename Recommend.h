#pragma once
#include "afxcmn.h"
#include "afxwin.h"


// CRecommend �Ի���

class CRecommend : public CDialog
{
	DECLARE_DYNAMIC(CRecommend)

public:
	CRecommend(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CRecommend();

// �Ի�������
	enum { IDD = IDD_DIALOG_RECOMMEND };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	BOOL OnInitDialog(void);
	CListCtrl m_chList;
	afx_msg void OnNMClickList1(NMHDR *pNMHDR, LRESULT *pResult);
	CString m_Title;
	CString m_Author;

	CString hit;
	CString m_Year;
	afx_msg void OnBnClickedButtonReserve();
};
