#pragma once


// CCreateAdmin �Ի���

class CCreateAdmin : public CDialog
{
	DECLARE_DYNAMIC(CCreateAdmin)

public:
	CCreateAdmin(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CCreateAdmin();

// �Ի�������
	enum { IDD = IDD_DIALOG_CREATEADMIN };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	CString AdminName;
	CString Password;
	CString Confirm;
	afx_msg void OnBnClickedButtonAdd();
};
