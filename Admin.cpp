// Admin.cpp : 实现文件
//

#include "stdafx.h"
#include "Library.h"
#include "Admin.h"
#include "ManageBook.h"
#include "CreateAdmin.h"
#include "ReaderInfoManage.h"


// CAdmin 对话框

IMPLEMENT_DYNAMIC(CAdmin, CDialog)

CAdmin::CAdmin(CWnd* pParent /*=NULL*/)
	: CDialog(CAdmin::IDD, pParent)
{

}

CAdmin::~CAdmin()
{
}

void CAdmin::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CAdmin, CDialog)
	ON_BN_CLICKED(IDC_BUTTON_BOOKMANAGE, &CAdmin::OnBnClickedButtonBookmanage)
	ON_BN_CLICKED(IDC_BUTTON_CREATEADMIN, &CAdmin::OnBnClickedButtonCreateadmin)
	ON_BN_CLICKED(IDC_BUTTON_USERINFO, &CAdmin::OnBnClickedButtonUserinfo)
	
END_MESSAGE_MAP()


// CAdmin 消息处理程序

void CAdmin::OnBnClickedButtonBookmanage()
{
	// TODO: 在此添加控件通知处理程序代码
	CManageBook mb;
	mb.DoModal();

}

void CAdmin::OnBnClickedButtonCreateadmin()
{
	// TODO: 在此添加控件通知处理程序代码
	CCreateAdmin ca;
	ca.DoModal();
	
}

void CAdmin::OnBnClickedButtonUserinfo()
{
	// TODO: 在此添加控件通知处理程序代码
	CReaderInfoManage rim;
	rim.DoModal();
}

