#pragma once


// CAdmin �Ի���

class CAdmin : public CDialog
{
	DECLARE_DYNAMIC(CAdmin)

public:
	CAdmin(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CAdmin();

// �Ի�������
	enum { IDD = IDD_DIALOG_ADMIN };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButtonBookmanage();
	afx_msg void OnBnClickedButtonCreateadmin();
	afx_msg void OnBnClickedButtonUserinfo();
	char m_chName[100];
	char m_Password[100];
	afx_msg void OnBnClickedButtonChangepassword();
};
