#pragma once


// CAdmin 对话框

class CAdmin : public CDialog
{
	DECLARE_DYNAMIC(CAdmin)

public:
	CAdmin(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CAdmin();

// 对话框数据
	enum { IDD = IDD_DIALOG_ADMIN };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButtonBookmanage();
	afx_msg void OnBnClickedButtonCreateadmin();
	afx_msg void OnBnClickedButtonUserinfo();
	char m_chName[100];
	char m_Password[100];
	afx_msg void OnBnClickedButtonChangepassword();
};
