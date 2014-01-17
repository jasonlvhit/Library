// AdminDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Library.h"
#include "AdminDlg.h"
#include "Admin.h"
#include <string>
#include <fstream>
using namespace std;

extern size_t len(wchar_t *a);
extern bool Compare(wchar_t *a,wchar_t *b);
extern void Initial(wchar_t*p);
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAdminDlg dialog


CAdminDlg::CAdminDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CAdminDlg::IDD, pParent)
	, m_chPassword(_T(""))
	, m_chName(_T(""))
{
	//{{AFX_DATA_INIT(CAdminDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CAdminDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAdminDlg)
	// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP

	DDX_Text(pDX, IDC_EDIT_ADMINCODE, m_chPassword);
	DDX_Text(pDX, IDC_EDIT_ADMINNAME, m_chName);
}


BEGIN_MESSAGE_MAP(CAdminDlg, CDialog)
	//{{AFX_MSG_MAP(CAdminDlg)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
	ON_BN_CLICKED(IDOK, &CAdminDlg::OnBnClickedOk)
	ON_BN_CLICKED(IDC_BUTTON_LOG_HELP, &CAdminDlg::OnBnClickedButtonLogHelp)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CAdminDlg message handlers

void CAdminDlg::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码
	    // 默认管理员登陆
	CString DefaultPassword("0");
	CString DefaultName("A");
	CAdmin ExistedAdmin;
	ifstream ifile("Admin.txt");

	UpdateData(TRUE);
	if(DefaultPassword == m_chPassword && DefaultName == m_chName)
	{
		CAdmin admin;
		admin.DoModal();
	}
	else{
		while(ifile.peek() != EOF)
		{
			ifile >> ExistedAdmin.m_chName >>ExistedAdmin.m_Password;
			if(ExistedAdmin.m_chName == m_chName)
			{
				if(ExistedAdmin.m_Password == m_chPassword)
				{
					CAdmin admin;
					admin.DoModal();
					return;
				}
				else{
					MessageBox("密码错误","ERROR",0);
					return;
				}
			}
		}
		MessageBox("用户名不存在","ERROR",0);
	}

		

			
}

void CAdminDlg::OnBnClickedButtonLogHelp()
{
	// TODO: 在此添加控件通知处理程序代码
	MessageBox("请查看使用说明书","Sorry",0);
}
