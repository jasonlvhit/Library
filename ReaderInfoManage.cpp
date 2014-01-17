// ReaderInfoManage.cpp : 实现文件
//

#include "stdafx.h"
#include "Library.h"
#include "ReaderInfoManage.h"
#include "Reader.h"
#include "InsertBook.h"
#include <fstream>
using namespace std;
#define MAX_OWNED 12
CReader AimReader;
long Position;
CString strPosition;
char chPosition[50];
extern bool Compare(wchar_t *a,wchar_t *b);
extern void Initial(wchar_t*p);

// CReaderInfoManage 对话框

IMPLEMENT_DYNAMIC(CReaderInfoManage, CDialog)

CReaderInfoManage::CReaderInfoManage(CWnd* pParent /*=NULL*/)
	: CDialog(CReaderInfoManage::IDD, pParent)
	, m_strE_Mail(_T(""))
	, m_strName(_T(""))
	, m_strPassWord(_T(""))
	, m_strInterest(_T(""))
	, m_strMajor(_T(""))
	, m_strFinancial(_T(""))
	, search(_T(""))
{

}

CReaderInfoManage::~CReaderInfoManage()
{
}

void CReaderInfoManage::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST1, m_chList1);
	DDX_Control(pDX, IDC_LIST2, m_chList2);
	DDX_Text(pDX, IDC_EDIT_E_MAIL, m_strE_Mail);
	DDX_Text(pDX, IDC_EDIT_NAME, m_strName);
	DDX_Text(pDX, IDC_EDIT_PASSWORD, m_strPassWord);
	DDX_Text(pDX, IDC_EDIT_INTEREST, m_strInterest);
	DDX_Text(pDX, IDC_EDIT_MAJOR, m_strMajor);
	DDX_Text(pDX, IDC_EDIT_F, m_strFinancial);
	
}


BEGIN_MESSAGE_MAP(CReaderInfoManage, CDialog)
	ON_NOTIFY(LVN_ITEMCHANGED, IDC_LIST1, &CReaderInfoManage::OnLvnItemchangedList1)
	ON_NOTIFY(NM_CLICK, IDC_LIST1, &CReaderInfoManage::OnNMClickList1)
	ON_BN_CLICKED(IDC_BUTTON_ADD, &CReaderInfoManage::OnBnClickedButtonAdd)
	ON_BN_CLICKED(IDC_BUTTON_DELETE, &CReaderInfoManage::OnBnClickedButtonDelete)
	ON_NOTIFY(LVN_ITEMCHANGED, IDC_LIST2, &CReaderInfoManage::OnLvnItemchangedList2)
	ON_BN_CLICKED(IDC_BUTTON_OUT, &CReaderInfoManage::OnBnClickedButtonOut)
	
END_MESSAGE_MAP()


// CReaderInfoManage 消息处理程序

void CReaderInfoManage::OnLvnItemchangedList1(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMLISTVIEW pNMLV = reinterpret_cast<LPNMLISTVIEW>(pNMHDR);
	// TODO: 在此添加控件通知处理程序代码
	*pResult = 0;
}

BOOL CReaderInfoManage::OnInitDialog(void)
{
	
	CDialog::OnInitDialog();
	m_chList1.DeleteAllItems();
	m_chList1.SetExtendedStyle(LVS_EX_FULLROWSELECT 
		| LVS_EX_GRIDLINES
		| LVS_EX_FLATSB
		| LVS_EX_HEADERDRAGDROP
		| LVS_EX_ONECLICKACTIVATE);   
	
    m_chList1.ShowWindow(SW_SHOW);

    // 为列表视图控件添加6列
    m_chList1.InsertColumn(0, "邮箱", LVCFMT_LEFT, 100);    
    m_chList1.InsertColumn(1, "用户名", LVCFMT_LEFT, 100);    
    m_chList1.InsertColumn(2, "密码", LVCFMT_LEFT, 100); 
    m_chList1.InsertColumn(3, "兴趣爱好", LVCFMT_LEFT, 100); 
	m_chList1.InsertColumn(4, "专攻", LVCFMT_LEFT, 100);
	m_chList1.InsertColumn(5, "余额", LVCFMT_LEFT, 100); 
    m_chList1.InsertColumn(6, "位置", LVCFMT_LEFT, 100); 
	CReader ExistedReader;
	CString Financial;
	ifstream IReaderFile(_T("Reader.dat"),ios::in|ios::binary);
	int i=0;
	while(IReaderFile.peek()!=EOF)
	{
		Position=IReaderFile.tellg();
        IReaderFile.read((char*)&ExistedReader,sizeof(CReader));
		if(ExistedReader.m_nflag)
		{
			m_chList1.InsertItem(i,_T(" "),0);
        m_chList1.SetItemText(i,0,(LPTSTR)ExistedReader.m_chE_Mail);
		m_chList1.SetItemText(i,1,(LPTSTR)ExistedReader.m_chName);
        m_chList1.SetItemText(i,2,(LPTSTR)ExistedReader.m_chPassWord);
		m_chList1.SetItemText(i,3,(LPTSTR)ExistedReader.m_chInterest);
		m_chList1.SetItemText(i,4,(LPTSTR)ExistedReader.m_chMajor);
		Financial.Format("%.2f",ExistedReader.m_Financial);
        m_chList1.SetItemText(i,5,Financial);
		strPosition.Format("%ld",Position);
        m_chList1.SetItemText(i,6,strPosition);
		i++;
		}
	}
	IReaderFile.close();
		m_chList2.SetExtendedStyle(LVS_EX_FULLROWSELECT 
		| LVS_EX_GRIDLINES
		| LVS_EX_FLATSB
		| LVS_EX_HEADERDRAGDROP
		| LVS_EX_ONECLICKACTIVATE);   
	
    m_chList2.ShowWindow(SW_SHOW);

    // 为列表视图控件添加6列
    m_chList2.InsertColumn(0, "书名", LVCFMT_LEFT, 100);    
    m_chList2.InsertColumn(1, "作者", LVCFMT_LEFT, 100);    
    m_chList2.InsertColumn(2, "出版年", LVCFMT_LEFT, 100); 
    m_chList2.InsertColumn(3, "种类", LVCFMT_LEFT, 100); 
	m_chList2.InsertColumn(4, "借入日期", LVCFMT_LEFT, 100);
	m_chList2.InsertColumn(5, "应还日期", LVCFMT_LEFT, 100);
	m_chList2.InsertColumn(6, "是否续借", LVCFMT_LEFT, 100);

	return false;
}

void CReaderInfoManage::OnNMClickList1(NMHDR *pNMHDR, LRESULT *pResult)
{
	//LPNMITEMACTIVATE pNMItemActivate = reinterpret_cast<NMITEMACTIVATE>(pNMHDR);
	// TODO: 在此添加控件通知处理程序代码
	m_chList2.DeleteAllItems();
	 int pos=m_chList1.GetSelectionMark();
	 m_strE_Mail=m_chList1.GetItemText(pos,0);
	 m_strName=m_chList1.GetItemText(pos,1);
	 m_strPassWord=m_chList1.GetItemText(pos,2);
	 m_strInterest=m_chList1.GetItemText(pos,3);
	 m_strMajor=m_chList1.GetItemText(pos,4);
	 m_strFinancial=m_chList1.GetItemText(pos,5);
	 UpdateData(false);
   strPosition=m_chList1.GetItemText(pos,6);
   lstrcpy(chPosition,strPosition);
   sscanf(chPosition,"%ld",&Position);
   fstream ReaderFile(_T("Reader.dat"),ios::in|ios::out|ios::binary);
   ReaderFile.seekp(Position);
   ReaderFile.read((char*)&AimReader,sizeof(CReader));
   m_chList2.InsertItem(0,_T(" "),0);
   int j=0;
	for(int i=0;i<MAX_OWNED;i++)
				{
					if(AimReader.m_BookOwned[i].m_nflag)
					{
						m_chList2.SetItemText(j,0,(LPTSTR)AimReader.m_BookOwned[i].m_chBookTitle);
                        m_chList2.SetItemText(j,1,(LPTSTR)AimReader.m_BookOwned[i].m_chWriter);
                       m_chList2.SetItemText(j,2,(LPTSTR)AimReader.m_BookOwned[i].m_chYear);
                       m_chList2.SetItemText(j,3,(LPTSTR)AimReader.m_BookOwned[i].m_chCategory);
                       m_chList2.SetItemText(j,4,(LPTSTR)AimReader.m_BookOwned[i].m_nDateBorrowed);
						m_chList2.SetItemText(j,5,(LPTSTR)AimReader.m_BookOwned[i].m_nDateShouldReturn);
						if(AimReader.m_BookOwned[i].m_nState)
						{
							m_chList2.SetItemText(j,6,_T("已续借"));
						}
						else
						{
							m_chList2.SetItemText(j,6,_T("未续借"));
						}
						j++;
						m_chList2.InsertItem(j,_T(" "),0);
					}
	}
	*pResult = 0;
}

void CReaderInfoManage::OnBnClickedButtonAdd()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(true);
    if(m_strE_Mail=="")
		MessageBox("请选中读者","ERROR",0);
	else
	{
		CInsertBook InsertBook;
	     InsertBook.DoModal();
	}
}

void CReaderInfoManage::OnBnClickedButtonDelete()
{
	fstream ReaderFile(_T("Reader.dat"),ios::in|ios::out|ios::binary);
	ReaderFile.seekp(Position);
	AimReader.m_nflag=0;
	ReaderFile.write((char*)&AimReader,sizeof(CReader));
	ReaderFile.close();
	m_chList1.DeleteAllItems();
	m_chList2.DeleteAllItems();
    CReader ExistedReader;
	CString Financial;
	ifstream IReaderFile(_T("Reader.dat"),ios::in|ios::binary);
	int i=0;
	while(IReaderFile.peek()!=EOF)
	{
		Position=IReaderFile.tellg();
        IReaderFile.read((char*)&ExistedReader,sizeof(CReader));
		if(ExistedReader.m_nflag)
		{
			m_chList1.InsertItem(i,_T(" "),0);
        m_chList1.SetItemText(i,0,(LPTSTR)ExistedReader.m_chE_Mail);
		m_chList1.SetItemText(i,1,(LPTSTR)ExistedReader.m_chName);
        m_chList1.SetItemText(i,2,(LPTSTR)ExistedReader.m_chPassWord);
		m_chList1.SetItemText(i,3,(LPTSTR)ExistedReader.m_chInterest);
		m_chList1.SetItemText(i,4,(LPTSTR)ExistedReader.m_chMajor);
		Financial.Format("%.2f",ExistedReader.m_Financial);
        m_chList1.SetItemText(i,5,Financial);
		strPosition.Format("%ld",Position);
        m_chList1.SetItemText(i,6,strPosition);
		i++;
		}
	}
	m_strE_Mail=m_strName=m_strPassWord=m_strInterest=m_strMajor=m_strFinancial="";
	UpdateData(false);
	// TODO: 在此添加控件通知处理程序代码
}

void CReaderInfoManage::OnLvnItemchangedList2(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMLISTVIEW pNMLV = reinterpret_cast<LPNMLISTVIEW>(pNMHDR);
	// TODO: 在此添加控件通知处理程序代码
	*pResult = 0;
}
void CReaderInfoManage::OnBnClickedButtonOut()
{
	// TODO: 在此添加控件通知处理程序代码
	fstream ReaderFile(_T("Reader.dat"),ios::in|ios::binary|ios::out);
	ReaderFile.seekp(Position,ios::beg);
	int pos=m_chList2.GetSelectionMark();
	CString strBookTitle=m_chList2.GetItemText(pos,0);
	wchar_t chBookTitle[100];
	Initial(chBookTitle);
	lstrcpy((LPTSTR)chBookTitle,strBookTitle);
	for(int i=0;i<MAX_OWNED;i++)
	{
		if(AimReader.m_BookOwned[i].m_nflag&&Compare(AimReader.m_BookOwned[i].m_chBookTitle,chBookTitle))
		{
			AimReader.m_BookOwned[i].m_nflag=0;
           ReaderFile.write((char*)&AimReader,sizeof(CReader));
		   ReaderFile.close();
			MessageBox("导出成功","DONE",0);
			break;
		}
	}
	m_chList2.DeleteAllItems();
   m_chList2.InsertItem(0,_T(" "),0);
   int j=0;
	for(int i=0;i<MAX_OWNED;i++)
				{
					if(AimReader.m_BookOwned[i].m_nflag)
					{
						m_chList2.SetItemText(j,0,(LPTSTR)AimReader.m_BookOwned[i].m_chBookTitle);
                        m_chList2.SetItemText(j,1,(LPTSTR)AimReader.m_BookOwned[i].m_chWriter);
                       m_chList2.SetItemText(j,2,(LPTSTR)AimReader.m_BookOwned[i].m_chYear);
                       m_chList2.SetItemText(j,3,(LPTSTR)AimReader.m_BookOwned[i].m_chCategory);
                       m_chList2.SetItemText(j,4,(LPTSTR)AimReader.m_BookOwned[i].m_nDateBorrowed);
						m_chList2.SetItemText(j,5,(LPTSTR)AimReader.m_BookOwned[i].m_nDateShouldReturn);
						if(AimReader.m_BookOwned[i].m_nState)
						{
							m_chList2.SetItemText(j,6,_T("已续借"));
						}
						else
						{
							m_chList2.SetItemText(j,6,_T("未续借"));
						}
						j++;
						m_chList2.InsertItem(j,_T(" "),0);
					}
	}
}

