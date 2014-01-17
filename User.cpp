// User.cpp : 实现文件
//

#include "stdafx.h"
#include <string.h>
#include "Library.h"
#include "User.h"
#include "UserInformation.h"
#include "Search.h"
#include "Reader.h"
#include <fstream>
#include "Recommend.h"
using namespace std;
extern wchar_t chE_Mail[100];
extern void Initial(wchar_t *p);
extern bool Compare(wchar_t *a,wchar_t *b);
#define MAX_OWNED 12
long PtrPosition;
CReader ExistedReader;

// CUser 对话框

IMPLEMENT_DYNAMIC(CUser, CDialog)

CUser::CUser(CWnd* pParent /*=NULL*/)
	: CDialog(CUser::IDD, pParent)
	, m_Title(_T(""))
	, m_Author(_T(""))
	, m_Year(_T(""))
	, m_Classification(_T(""))
	, m_Hot(_T(""))
	, m_DateBorrowed(_T(""))
	, m_DateShouldReturn(_T(""))
	, m_strHot(_T(""))
{
#ifndef _WIN32_WCE
	EnableActiveAccessibility();
#endif

	EnableAutomation();

}

CUser::~CUser()
{
}

void CUser::OnFinalRelease()
{
	// 释放了对自动化对象的最后一个引用后，将调用
	// OnFinalRelease。基类将自动
	// 删除该对象。在调用该基类之前，请添加您的
	// 对象所需的附加清理代码。

	CDialog::OnFinalRelease();
}

void CUser::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST1, m_BookList);
	DDX_Text(pDX, IDC_EDIT1, m_Title);
	DDX_Text(pDX, IDC_EDIT2, m_Author);
	DDX_Text(pDX, IDC_EDIT5, m_Year);
	

	DDX_Text(pDX, IDC_EDIT9, m_DateBorrowed);
	DDX_Text(pDX, IDC_EDIT10, m_DateShouldReturn);
	DDX_Text(pDX, IDC_EDIT4, m_strHot);
}


BEGIN_MESSAGE_MAP(CUser, CDialog)
	ON_BN_CLICKED(IDC_BUTTONRESERVE, &CUser::OnBnClickedButtonreserve)
	ON_BN_CLICKED(IDC_BUTTONDESTROY, &CUser::OnBnClickedButtondestroy)
	ON_BN_CLICKED(IDC_BUTTON1, &CUser::OnBnClickedButton1)
	ON_NOTIFY(NM_CLICK, IDC_LIST1, &CUser::OnNMClickList1)
	ON_BN_CLICKED(IDC_BUTTONSEARCH2, &CUser::OnBnClickedButtonsearch2)
	ON_BN_CLICKED(IDC_BUTTON3, &CUser::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON2, &CUser::OnBnClickedButton2)
END_MESSAGE_MAP()

BEGIN_DISPATCH_MAP(CUser, CDialog)
END_DISPATCH_MAP()

// 注意: 我们添加 IID_IUser 支持
//  以支持来自 VBA 的类型安全绑定。此 IID 必须同附加到 .IDL 文件中的
//  调度接口的 GUID 匹配。

// {70770673-45ED-425A-BD8D-9A3914874C23}
static const IID IID_IUser =
{ 0x70770673, 0x45ED, 0x425A, { 0xBD, 0x8D, 0x9A, 0x39, 0x14, 0x87, 0x4C, 0x23 } };

BEGIN_INTERFACE_MAP(CUser, CDialog)
	INTERFACE_PART(CUser, IID_IUser, Dispatch)
END_INTERFACE_MAP()


// CUser 消息处理程序
void CUser::PostNcDestroy() 
{
	delete this;
}
void CUser::OnCancel()
{
	DestroyWindow();
}
BOOL CUser::OnInitDialog()
{
	CDialog::OnInitDialog();
	m_BookList.SetExtendedStyle(  LVS_EX_FULLROWSELECT| 
		LVS_EX_GRIDLINES
		| LVS_EX_FLATSB
		| LVS_EX_HEADERDRAGDROP
		| LVS_EX_ONECLICKACTIVATE);  
m_BookList.InsertColumn(0,_T("书名"),LVCFMT_LEFT,100,0);
m_BookList.InsertColumn(1,_T("作者"),LVCFMT_LEFT,100,1);
m_BookList.InsertColumn(2,_T("出版年份"),LVCFMT_LEFT,100,2);
m_BookList.InsertColumn(3,_T("种类"),LVCFMT_LEFT,100,3);
m_BookList.InsertColumn(4,_T("借出日期"),LVCFMT_LEFT,100,4);
m_BookList.InsertColumn(5,_T("应还日期"),LVCFMT_LEFT,100,5);
m_BookList.InsertColumn(6,_T("状态"),LVCFMT_LEFT,100,6);
m_BookList.InsertColumn(7,_T("热度"),LVCFMT_LEFT,100,7);
m_BookList.InsertColumn(8,_T("余额"),LVCFMT_LEFT,100,8); 
ifstream IReaderFile("Reader.dat",ios::in|ios::binary);
while(IReaderFile.peek()!=EOF)
		  {
			  PtrPosition=IReaderFile.tellg();
			 IReaderFile.read((char*)&ExistedReader,sizeof(CReader));
			 if(ExistedReader.m_nflag&&Compare(ExistedReader.m_chE_Mail,chE_Mail))
			 {
				 //m_BookList.DeleteAllItems();
                m_BookList.InsertItem(0,_T(" "),0);
				int j=0;
				for(int i=0;i<MAX_OWNED;i++)
				{
					if(ExistedReader.m_BookOwned[i].m_nflag)
					{
						m_BookList.SetItemText(j,0,(LPTSTR)ExistedReader.m_BookOwned[i].m_chBookTitle);
						m_BookList.SetItemText(j,1,(LPTSTR)ExistedReader.m_BookOwned[i].m_chWriter);
						m_BookList.SetItemText(j,2,(LPTSTR)ExistedReader.m_BookOwned[i].m_chYear);
						m_BookList.SetItemText(j,3,(LPTSTR)ExistedReader.m_BookOwned[i].m_chCategory);
						m_BookList.SetItemText(j,4,(LPTSTR)ExistedReader.m_BookOwned[i].m_nDateBorrowed);
						m_BookList.SetItemText(j,5,(LPTSTR)ExistedReader.m_BookOwned[i].m_nDateShouldReturn);
						m_BookList.SetItemText(j,7,ExistedReader.m_BookOwned[i].m_chHot);
						if(ExistedReader.m_BookOwned[i].m_nState)
						{
							m_BookList.SetItemText(j,6,_T("已续借"));
						}
						else
						{
							m_BookList.SetItemText(j,6,_T("未续借"));
						}
						j++;
						m_BookList.InsertItem(j,_T(" "),0);
					}
				}
				CString Financial;
				Financial.Format("%.2f",ExistedReader.m_Financial);
                m_BookList.SetItemText(0,8,Financial);
			   break;
			 }
		  }
IReaderFile.close();
return true;
}
void CUser::OnBnClickedButtonreserve()
{
	CUserInformation UserInformation;
	UserInformation.DoModal();
}

void CUser::OnBnClickedButtondestroy()
{
	// TODO: 在此添加控件通知处理程序代码
	   fstream ReaderFile(_T("Reader.dat"),ios::in|ios::binary|ios::out);
	       ExistedReader.m_nflag=0;
		  ReaderFile.seekp(PtrPosition,ios::beg);
          ReaderFile.write((char*)&ExistedReader,sizeof(CReader));
          ReaderFile.close();
		  MessageBox("删除成功","DONE",0);
		  OnCancel();
}

void CUser::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
      fstream ReaderFile(_T("Reader.dat"),ios::in|ios::out|ios::binary);
	 ReaderFile.seekp(PtrPosition,ios::beg);
	 wchar_t chTitle[100];
	 Initial(chTitle);
	 lstrcpy((LPTSTR)chTitle,m_Title);
	 for(int i=0;i<MAX_OWNED;i++)
	 {
		 if(ExistedReader.m_BookOwned[i].m_nflag&&Compare(chTitle,ExistedReader.m_BookOwned[i].m_chBookTitle))
		 {
			 if(ExistedReader.m_BookOwned[i].m_nState)
			 {
				 MessageBox("已续借","DONE",0);
				 break;
			 }
			 else
			 {
				 ExistedReader.m_BookOwned[i].m_nState=1;
             ReaderFile.write((char*)&ExistedReader,sizeof(CReader));
			 MessageBox("续借成功","DONE",0);
			 break;
			 }
		 }
     }
     int j=0;
	for(int i=0;i<MAX_OWNED;i++)
				{
					if(ExistedReader.m_BookOwned[i].m_nflag)
					{
						if(ExistedReader.m_BookOwned[i].m_nState)
						{
							m_BookList.SetItemText(j,6,_T("已续借"));
						}
						else
						{
							m_BookList.SetItemText(j,6,_T("未续借"));
						}
						j++;
					}
				}
}

void CUser::OnNMClickList1(NMHDR *pNMHDR, LRESULT *pResult)
{
	//LPNMITEMACTIVATE pNMItemActivate = reinterpret_cast<NMITEMACTIVATE>(pNMHDR);
	// TODO: 在此添加控件通知处理程序代码
	 int pos=m_BookList.GetSelectionMark();
	 m_Title=m_BookList.GetItemText(pos,0);
	 m_Author=m_BookList.GetItemText(pos,1);
	 m_Year=m_BookList.GetItemText(pos,2);
	 m_Classification=m_BookList.GetItemText(pos,3);
	 m_DateBorrowed=m_BookList.GetItemText(pos,4);
	 m_DateShouldReturn=m_BookList.GetItemText(pos,5);
	 m_strHot=m_BookList.GetItemText(pos,7);
	 UpdateData(false);
	

		 *pResult = 0;
}




void CUser::OnBnClickedButtonsearch2()
{
	// TODO: 在此添加控件通知处理程序代码
	CSearch se;
	se.DoModal();
}

void CUser::OnBnClickedButton3()
{
	// TODO: 在此添加控件通知处理程序代码
	CRecommend re;
	re.DoModal();
}

void CUser::OnBnClickedButton2()
{
	// TODO: 在此添加控件通知处理程序代码
	int i,j,k;
	CBook Book[100];
	UpdateData();
	if(m_Title =="")
	{
		MessageBox("您尚未选择任何图书","ERROR",0);
	    return ;
	}
	else
	{
		double fHot;
		char chTitle[100];
		wchar_t wchTitle[100];
		Initial(wchTitle);
		memcpy(chTitle,m_Title,100);
		lstrcpy((LPTSTR)wchTitle,m_Title);
		 for( i=0;i<MAX_OWNED;i++)
		 {
							   if(ExistedReader.m_BookOwned[i].m_nflag&&Compare(wchTitle,ExistedReader.m_BookOwned[i].m_chBookTitle))
							   {
								   if(ExistedReader.m_BookOwned[i].m_nadd)
								   {
									   MessageBox("您已经对本书加一","ERROR",0);
									   return ;
								   }
								   else
								   {
                                            ExistedReader.m_BookOwned[i].m_nadd=1;
											break;
								   }
							   }
		 }
		ifstream BookFile("Book.txt",ios::in);
		ofstream OReBookFile(_T("ReBook.txt"),ios::app);
	    for( j=0;BookFile>>Book[j].m_chTitle>>Book[j].m_chAuthor>>Book[j].m_nYear>>Book[j].m_bAvailible>>Book[j].m_chClassification>>Book[j].m_chHit;j++)
		{
			
			if(!strcmp(chTitle,Book[j].m_chTitle))
			{
						   fHot=atof(m_strHot);
						   if(fHot==9.9)
						   {
							   MessageBox("已达到上限","ERROR",0);
							   return ;
						   }
						    fHot+=0.1;
						   m_strHot.Format("%.1f",fHot);
	                       memcpy(Book[j].m_chHit,m_strHot,100);
						   if(fHot==9.0)
							{
                                   OReBookFile<<Book[j].m_chTitle<<" "<<Book[j].m_chAuthor<<" "<<Book[j].m_nYear<<" "<<Book[j].m_bAvailible<<" "<<Book[j].m_chClassification<<" "<<Book[j].m_chHit<<endl;
							}
						   UpdateData(false);
								   memcpy(ExistedReader.m_BookOwned[i].m_chHot,m_strHot,100);
								   fstream ReaderFile(_T("Reader.dat"),ios::in|ios::out);
								   ReaderFile.seekp(PtrPosition,ios::beg);
								   ReaderFile.write((char*)&ExistedReader,sizeof(CReader));
								   ReaderFile.close();
								    int pos=m_BookList.GetSelectionMark();
									m_BookList.SetItemText(pos,7,m_strHot);
									MessageBox("加1成功，我们会把这本书同样推荐给别的读者","+1",0);
			}
		}
		OReBookFile.close();
		BookFile.close();
	}
	ofstream OBookFile(_T("Book.txt"),ios::out);
	for(k=0;k<=j;k++)
    OBookFile<<Book[k].m_chTitle<<" "<<Book[k].m_chAuthor<<" "<<Book[k].m_nYear<<" "<<Book[k].m_bAvailible<<" "<<Book[k].m_chClassification<<" "<<Book[k].m_chHit<<endl;
    OBookFile.close();
}


