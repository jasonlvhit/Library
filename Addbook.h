#pragma once


// CAddbook 对话框

class CAddbook : public CDialog
{
	DECLARE_DYNAMIC(CAddbook)

public:
	CAddbook(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CAddbook();

// 对话框数据
	enum { IDD = IDD_DIALOG_ADDBOOK };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButtonAdd();
};
