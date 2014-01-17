// CreateAdmin.cpp : 实现文件
//

#include "stdafx.h"
#include "Library.h"
#include "CreateAdmin.h"
#include "Admin.h"
#include <fstream>

using namespace std;


// CCreateAdmin 对话框

IMPLEMENT_DYNAMIC(CCreateAdmin, CDialog)

CCreateAdmin::CCreateAdmin(CWnd* pParent /*=NULL*/)
	: CDialog(CCreateAdmin::IDD, pParent)
	, AdminName(_T(""))
	, Password(_T(""))
	, Confirm(_T(""))
{

}

CCreateAdmin::~CCreateAdmin()
{
}

void CCreateAdmin::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT_NAME, AdminName);
	DDX_Text(pDX, IDC_EDIT_PASSWORD, Password);
	DDX_Text(pDX, IDC_EDIT_CONFIRM, Confirm);
}


BEGIN_MESSAGE_MAP(CCreateAdmin, CDialog)
	ON_BN_CLICKED(IDC_BUTTON_ADD, &CCreateAdmin::OnBnClickedButtonAdd)
END_MESSAGE_MAP()


// CCreateAdmin 消息处理程序

void CCreateAdmin::OnBnClickedButtonAdd()
{
	// TODO: 在此添加控件通知处理程序代码
	CAdmin Admin;
	
	CAdmin ExistedAdmin;
	fstream ifile("Admin.txt",ios::in);
	fstream ofile("Admin.txt",ios::app);
	UpdateData();

		ifile >>ExistedAdmin.m_chName >>ExistedAdmin.m_Password;
		
		if(ExistedAdmin.m_chName == AdminName)
		{
			MessageBox("用户名已存在","ERROR",0);
			return;
		}
	
		if(Confirm == Password)
		{
			memcpy(Admin.m_chName,AdminName,100);
			memcpy(Admin.m_Password,Password,100);
			ofile <<Admin.m_chName <<" "<<Admin.m_Password<<" ";
			MessageBox(Admin.m_chName,"Congratulations",0);
		}
		else {
			MessageBox("密码输入不一致","ERROR",0);
		}


	

	
}
