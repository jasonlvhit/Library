#pragma once


// CAddbook �Ի���

class CAddbook : public CDialog
{
	DECLARE_DYNAMIC(CAddbook)

public:
	CAddbook(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CAddbook();

// �Ի�������
	enum { IDD = IDD_DIALOG_ADDBOOK };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButtonAdd();
};
