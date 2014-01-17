#pragma once


// CCreateAdmin 对话框

class CCreateAdmin : public CDialog
{
	DECLARE_DYNAMIC(CCreateAdmin)

public:
	CCreateAdmin(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CCreateAdmin();

// 对话框数据
	enum { IDD = IDD_DIALOG_CREATEADMIN };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CString AdminName;
	CString Password;
	CString Confirm;
	afx_msg void OnBnClickedButtonAdd();
};
