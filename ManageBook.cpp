// ManageBook.cpp : 实现文件
//

#include "stdafx.h"
#include "Library.h"
#include "ManageBook.h"
#include "string"
#include "fstream"
#include "Book.h"

using namespace std;

// CManageBook 对话框

IMPLEMENT_DYNAMIC(CManageBook, CDialog)

CManageBook::CManageBook(CWnd* pParent /*=NULL*/)
	: CDialog(CManageBook::IDD, pParent)
	, m_Title(_T(""))
	, m_Author(_T(""))
	, m_Year(_T(""))
	, m_Classification(_T(""))
	, m_A(_T(""))
	, m_strBy1(_T(""))
	, m_strBy2(_T(""))
	, hit(_T(""))
{

}

CManageBook::~CManageBook()
{
}

void CManageBook::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST2, m_chList);
	DDX_Text(pDX, IDC_EDIT_TITLE, m_Title);
	DDX_Text(pDX, IDC_EDIT_AUTHOR, m_Author);
	DDX_Text(pDX, IDC_EDIT_YEAR, m_Year);
	DDX_Text(pDX, IDC_EDIT_CLASSIFACATION, m_Classification);
	DDX_Text(pDX, IDC_EDIT_AV, m_A);
	DDX_Control(pDX, IDC_COMBO1, m_chCombo);
	DDX_CBString(pDX, IDC_COMBO1, m_strBy1);
	DDX_Text(pDX, IDC_EDIT_SEARCH, m_strBy2);
	DDX_Text(pDX, IDC_EDIT_HIT, hit);
}


BEGIN_MESSAGE_MAP(CManageBook, CDialog)
	
	ON_BN_CLICKED(IDC_BUTTON_ADD, &CManageBook::OnBnClickedButtonAdd)
	ON_NOTIFY(NM_CLICK, IDC_LIST2, &CManageBook::OnNMClickList2)
	ON_BN_CLICKED(IDC_BUTTON_DELETE, &CManageBook::OnBnClickedButtonDelete)
	ON_BN_CLICKED(IDC_BUTTON_EDIT, &CManageBook::OnBnClickedButtonEdit)
	ON_CBN_SELCHANGE(IDC_COMBO1, &CManageBook::OnCbnSelchangeCombo1)
	ON_BN_CLICKED(IDC_BUTTON_GO, &CManageBook::OnBnClickedButtonGo)
	ON_BN_CLICKED(IDC_BUTTON_ALL, &CManageBook::OnBnClickedButtonAll)
	ON_BN_CLICKED(IDC_BUTTON_CLEAN, &CManageBook::OnBnClickedButtonClean)
END_MESSAGE_MAP()


// CManageBook 消息处理程序

BOOL CManageBook::OnInitDialog(void)
{
	CDialog::OnInitDialog();
	CString str[5]={"书名","作者","年份","种类","在馆与否"};
	for(int i=0;i<5;i++)
	{
		m_chCombo.InsertString(i-1,str[i]);
	}
	//设置默认查询依据为书名
	m_chCombo.SetCurSel(1);


	m_chList.SetExtendedStyle(LVS_EX_FULLROWSELECT 
		| LVS_EX_GRIDLINES
		| LVS_EX_FLATSB
		| LVS_EX_HEADERDRAGDROP
		| LVS_EX_ONECLICKACTIVATE);   
	
    m_chList.ShowWindow(SW_SHOW);

    
    m_chList.InsertColumn(0, "图书名称", LVCFMT_LEFT, 100);    
    m_chList.InsertColumn(1, "作者", LVCFMT_LEFT, 100);    
    m_chList.InsertColumn(2, "出版年份", LVCFMT_LEFT, 100); 
    m_chList.InsertColumn(3, "类别", LVCFMT_LEFT, 100); 
	m_chList.InsertColumn(4, "是否在馆", LVCFMT_LEFT, 100);
	m_chList.InsertColumn(5, "热度", LVCFMT_LEFT, 100);
	//计算总书目
	ifstream ifile("Book.txt");
	string temp;
	int i = 0;
	while(ifile >> temp)
	{
		++i;
	}
	int total = i /6;
	ifile.close();
	//read books from Book.txt;

	ifstream file("Book.txt");
	CBook book;
	for(i=0;i<total;i++)
	{
		file>>book.m_chTitle
			>>book.m_chAuthor
			>>book.m_nYear
			>>book.m_chClassification
			>>book.m_bAvailible
			>>book.m_chHit;



		m_chList.InsertItem(i,"");   
		m_chList.SetItemText(i, 0, book.m_chTitle); 
		m_chList.SetItemText(i, 1, book.m_chAuthor);  
		m_chList.SetItemText(i, 2, book.m_nYear);  
		m_chList.SetItemText(i, 3, book.m_chClassification);  
		m_chList.SetItemText(i, 4, book.m_bAvailible); 
		m_chList.SetItemText(i, 5, book.m_chHit);
		//MessageBox(book->strName,book->strAuthor,MB_OK);
	}
	file.close();
	
	
	return TRUE;
}


void CManageBook::OnBnClickedButtonAdd()
{
	// TODO: 在此添加控件通知处理程序代码
	ofstream f("Book.txt",ios::app);
    if(!f)
    {
        MessageBox("文件无法打开");
        exit(1);
    }
    else
    {
		UpdateData();
		if(m_Title== "" || m_Author == "" || m_Year==""||m_A == "" || m_Classification == "" ) 
		{
			MessageBox("请填写所有信息");
			return;
		}
		CBook *b=new CBook;
		memcpy(b->m_chTitle,m_Title,100);
		memcpy(b->m_chAuthor,m_Author,100);
		memcpy(b->m_chClassification,m_Classification,100);
		memcpy(b->m_bAvailible,m_A,100);
		memcpy(b->m_nYear,m_Year,100);
		memcpy(b->m_chHit,hit,100);
		
		f<<b->m_chTitle<<' '<<b->m_chAuthor<<' '<<b->m_nYear<<' '<<b->m_chClassification<<' '<<b->m_bAvailible<<' '<<b->m_chHit<<endl;
		f.close();
		if(hit > '9')
		{
			ofstream re("ReBook.txt",ios::app);
			re<<b->m_chTitle<<' '<<b->m_chAuthor<<' '<<b->m_nYear<<' '<<b->m_chClassification<<' '<<b->m_bAvailible<<' '<<b->m_chHit<<endl;
			re.close();
		}
		ifstream ifile("Book.txt");
		string temp;
		int i = 0;
		while(ifile >> temp)
		{
			++i;
		} 
		int total = i /6 +1;
		ifile.close();
		int k = 0;
		m_chList.InsertItem(k, ""); 
		m_chList.SetItemText(k, 0, m_Title);
		m_chList.SetItemText(k, 1, m_Author);  
		m_chList.SetItemText(k, 2, m_Year);  
		m_chList.SetItemText(k, 3, m_Classification);  
		m_chList.SetItemText(k, 4, m_A); 
		m_chList.SetItemText(k, 5, hit);
	}
	

}

void CManageBook::OnNMClickList2(NMHDR *pNMHDR, LRESULT *pResult)
{
	//LPNMITEMACTIVATE pNMItemActivate = reinterpret_cast<NMITEMACTIVATE>(pNMHDR);
	// TODO: 在此添加控件通知处理程序代码
	int pos=m_chList.GetSelectionMark();
	m_Title=m_chList.GetItemText(pos,0);
	m_Author=m_chList.GetItemText(pos,1);
	m_Year=m_chList.GetItemText(pos,2);
	m_Classification=m_chList.GetItemText(pos,3);
	m_A=m_chList.GetItemText(pos,4);
	hit=m_chList.GetItemText(pos,5);
	UpdateData(false);
	
	*pResult = 0;
}

void CManageBook::OnBnClickedButtonDelete()
{
	// TODO: 在此添加控件通知处理程序代码

	int cbYN = MessageBox("确认删除图书", "Warning", MB_YESNO|MB_ICONQUESTION);
	if(cbYN == IDNO) 
	{
		return;      	
	}
	else
	{
		int pos=m_chList.GetSelectionMark();
		m_chList.DeleteItem(pos);	
	}
	CBook *book=new CBook;
	ofstream f("Book.txt",ios::out);
	for(int i=0; i<m_chList.GetItemCount(); i++)
	{
		memcpy(book->m_chTitle,m_chList.GetItemText(i, 0 ),100);
		memcpy(book->m_chAuthor,m_chList.GetItemText(i, 1 ),100);
		memcpy(book->m_nYear,m_chList.GetItemText(i, 2 ),100);
		memcpy(book->m_chClassification,m_chList.GetItemText(i, 3 ),100);
		memcpy(book->m_bAvailible,m_chList.GetItemText(i, 4 ),100);
		memcpy(book->m_chHit,m_chList.GetItemText(i, 5 ),100);
		f<<book->m_chTitle<<' '<<book->m_chAuthor<<' '<<book->m_nYear<<' '<<book->m_chClassification<<' '<<book->m_bAvailible<<' '<<book->m_chHit<<endl;
		
	}
	f.close();
	Clean();
}

void CManageBook::Clean(void)
{
	m_Title = _T("");
	m_Author = _T("");
	m_Year = _T("");
	m_Classification = _T("");
	m_A = _T("");
	hit = _T("");
	UpdateData(false);

}

void CManageBook::OnBnClickedButtonEdit()
{
	// TODO: 在此添加控件通知处理程序代码
	int cbYN = MessageBox("确认修改该图书？", "Warning", MB_YESNO|MB_ICONQUESTION);
	if(cbYN == IDNO) 
	{
		return;      	
	}
	else
	{
		CBook *book=new CBook;
		int pos=m_chList.GetSelectionMark();
		UpdateData(TRUE);

		if(m_Title==m_chList.GetItemText(pos,0)
			&&m_Author==m_chList.GetItemText(pos,1)
			&&m_Year==m_chList.GetItemText(pos,2)
			&&m_Classification==m_chList.GetItemText(pos,3)
			&&m_A==m_chList.GetItemText(pos,4)
			&&hit ==m_chList.GetItemText(pos,5)
			)
		{
			MessageBox("温馨提示，您修改的图书未改动");
		}
		else
		{
			//UpdateData(TRUE);
		
			//m_chList.InsertItem(0,"");   
			m_chList.SetItemText(pos, 0, m_Title); 
			m_chList.SetItemText(pos, 1, m_Author);  
			m_chList.SetItemText(pos, 2, m_Year);  
			m_chList.SetItemText(pos, 3, m_Classification);  
			m_chList.SetItemText(pos, 4, m_A);   
			m_chList.SetItemText(pos, 5, hit); 

		
			/*	CString csCount = _T("");
			csCount.Format(_T("%d"),m_nCount);
			m_cbBooklist.GetItemText(pos,0)=m_strStype;
			m_cbBooklist.GetItemText(pos,1)=m_strName;
			m_cbBooklist.GetItemText(pos,2)=m_strAuthor;
			m_cbBooklist.GetItemText(pos,3)=m_strNumber;
			m_cbBooklist.GetItemText(pos,4)=m_strPublic;
			m_cbBooklist.GetItemText(pos,5)=csCount;
			//m_cbBooklist.DeleteItem(pos+1);*/
		}
		
		
	}
			CBook *book=new CBook;
			ofstream f("Book.txt",ios::out);
			for(int i=0; i<m_chList.GetItemCount(); i++)
			{
				memcpy(book->m_chTitle,m_chList.GetItemText(i, 0 ),100);
				memcpy(book->m_chAuthor,m_chList.GetItemText(i, 1 ),100);
				memcpy(book->m_nYear,m_chList.GetItemText(i, 2 ),100);
				memcpy(book->m_chClassification,m_chList.GetItemText(i, 3 ),100);
				memcpy(book->m_bAvailible,m_chList.GetItemText(i, 4 ),100);
				memcpy(book->m_chHit,m_chList.GetItemText(i, 5 ),100);
				f<<book->m_chTitle<<' '<<book->m_chAuthor<<' '<<book->m_nYear<<' '<<book->m_chClassification<<' '<<book->m_bAvailible<<' '<<book->m_chHit<<endl;
				
			}
			f.close();
			Clean();
}

void CManageBook::OnCbnSelchangeCombo1()
{
	// TODO: 在此添加控件通知处理程序代码
}

void CManageBook::OnBnClickedButtonGo()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData();
	int nIndex,flag=0;
	CBook *book=new CBook;
	//MessageBox(m_strBy1);
	if(m_strBy1=="书名")
	{
		nIndex=0;
	}
	else if(m_strBy1=="作者")
	{
		nIndex=1;
	}
	else if(m_strBy1=="年份")
	{
		nIndex=2;
	}
	else if(m_strBy1=="种类")
	{
		nIndex=3;
	}	
	else
	{
		nIndex=4;
	}
/*
	CString k = "";
	k.Format("%d",nIndex);
	MessageBox(k);
	*/
	//MessageBox("m_strBy2",m_strBy2);
	fstream f("Search.txt",ios::out);
	for(int i=0; i<m_chList.GetItemCount(); i++)
	{	
		if(m_strBy2==m_chList.GetItemText(i,nIndex))
		{
			flag=1;
			//MessageBox(m_SearchResultList.GetItemText(i,0),m_SearchResultList.GetItemText(i,1),MB_ICONWARNING);
			

			memcpy(book->m_chTitle,m_chList.GetItemText(i, 0 ),100);
			memcpy(book->m_chAuthor,m_chList.GetItemText(i, 1 ),100);
			memcpy(book->m_nYear,m_chList.GetItemText(i, 2 ),100);
			memcpy(book->m_chClassification,m_chList.GetItemText(i, 3 ),100);
			memcpy(book->m_bAvailible,m_chList.GetItemText(i, 4 ),100);
			memcpy(book->m_chHit,m_chList.GetItemText(i, 5 ),100);
				f<<book->m_chTitle<<' '<<book->m_chAuthor<<' '<<book->m_nYear<<' '<<book->m_chClassification<<' '<<book->m_bAvailible<<' '<<book->m_chHit<<endl;
			
		}
		
	}
	f.close();
	if(flag==0)
	{
		MessageBox("查无此书!","提示",MB_ICONWARNING);
	}
	else
	{
		m_chList.DeleteAllItems();
		fstream f1("Search.txt",ios::in);
		int total=0;
		string str1;
		while(f1>>str1)
		{
			total++;
		}
		f1.close();
		total/=5;
/*
		CString k1 = "";
		k1.Format("%d",total);
		MessageBox(k1);*/
		
		fstream f("Search.txt",ios::in);
	
		for(int i=0;i<total;i++)
		{
			f>>book->m_chTitle
				>>book->m_chAuthor
				>>book->m_nYear
				>>book->m_chClassification
				>>book->m_bAvailible
				>>book->m_chHit;



			m_chList.InsertItem(i,"");   
			m_chList.SetItemText(i, 0, book->m_chTitle); 
			m_chList.SetItemText(i, 1, book->m_chAuthor);  
			m_chList.SetItemText(i, 2, book->m_nYear);  
			m_chList.SetItemText(i, 3, book->m_chClassification);  
			m_chList.SetItemText(i, 4, book->m_bAvailible); 
			m_chList.SetItemText(i, 5, book->m_chHit); 
		}
		f.close();
	}
	return;
}

void CManageBook::OnBnClickedButtonAll()
{
	// TODO: 在此添加控件通知处理程序代码
	m_chList.DeleteAllItems();
	ifstream ifile("Book.txt");
	string temp;
	int i = 0;
	while(ifile >> temp)
	{
		++i;
	}
	int total = i /6;
	ifile.close();
	//read books from Book.txt;

	ifstream file("Book.txt");
	CBook book;
	for(i=0;i<total;i++)
	{
		file>>book.m_chTitle
			>>book.m_chAuthor
			>>book.m_nYear
			>>book.m_chClassification
			>>book.m_bAvailible
			>>book.m_chHit;



		m_chList.InsertItem(i,"");   
		m_chList.SetItemText(i, 0, book.m_chTitle); 
		m_chList.SetItemText(i, 1, book.m_chAuthor);  
		m_chList.SetItemText(i, 2, book.m_nYear);  
		m_chList.SetItemText(i, 3, book.m_chClassification);  
		m_chList.SetItemText(i, 4, book.m_bAvailible); 
		m_chList.SetItemText(i, 5, book.m_chHit);
		//MessageBox(book->strName,book->strAuthor,MB_OK);
	}
	file.close();
	return;
}

void CManageBook::OnBnClickedButtonClean()
{
	// TODO: 在此添加控件通知处理程序代码
	Clean();
}
