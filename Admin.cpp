// Admin.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "Library.h"
#include "Admin.h"
#include "ManageBook.h"
#include "CreateAdmin.h"
#include "ReaderInfoManage.h"


// CAdmin �Ի���

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


// CAdmin ��Ϣ�������

void CAdmin::OnBnClickedButtonBookmanage()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CManageBook mb;
	mb.DoModal();

}

void CAdmin::OnBnClickedButtonCreateadmin()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CCreateAdmin ca;
	ca.DoModal();
	
}

void CAdmin::OnBnClickedButtonUserinfo()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CReaderInfoManage rim;
	rim.DoModal();
}

