// Search.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "Library.h"
#include "Search.h"
#include "Book.h"
#include <fstream>
#include <string>
using namespace std;


// CSearch �Ի���

IMPLEMENT_DYNAMIC(CSearch, CDialog)

CSearch::CSearch(CWnd* pParent /*=NULL*/)
	: CDialog(CSearch::IDD, pParent)
	, m_Author(_T(""))
	, m_Title(_T(""))
	, m_Year(_T(""))
	, m_Classification(_T(""))
	, m_A(_T(""))
	, m_strBy1(_T(""))
	, m_strBy2(_T(""))
	, hit(_T(""))
{

}

CSearch::~CSearch()
{
}

void CSearch::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST1, m_chList);

	DDX_Text(pDX, IDC_EDIT2, m_Author);
	DDX_Text(pDX, IDC_EDIT1, m_Title);
	DDX_Text(pDX, IDC_EDIT3, m_Year);
	DDX_Text(pDX, IDC_EDIT4, m_Classification);
	DDX_Text(pDX, IDC_EDIT5, m_A);
	DDX_Control(pDX, IDC_COMBO1, m_chCombo);
	DDX_CBString(pDX, IDC_COMBO1, m_strBy1);
	DDX_Text(pDX, IDC_EDIT_SEARCH, m_strBy2);
	DDX_Text(pDX, IDC_EDIT6, hit);
}


BEGIN_MESSAGE_MAP(CSearch, CDialog)
	ON_BN_CLICKED(IDC_BUTTON_SEARCH, &CSearch::OnBnClickedButtonSearch)
	ON_NOTIFY(NM_CLICK, IDC_LIST1, &CSearch::OnNMClickList1)
	ON_BN_CLICKED(IDC_BUTTON_ALL, &CSearch::OnBnClickedButtonAll)
	ON_BN_CLICKED(IDC_BUTTON_RESERVE, &CSearch::OnBnClickedButtonReserve)
END_MESSAGE_MAP()


// CSearch ��Ϣ�������

void CSearch::OnBnClickedButtonSearch()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	UpdateData();
	int nIndex,flag=0;
	CBook *book=new CBook;
	//MessageBox(m_strBy1);
	if(m_strBy1=="����")
	{
		nIndex=0;
	}
	else if(m_strBy1=="����")
	{
		nIndex=1;
	}
	else if(m_strBy1=="���")
	{
		nIndex=2;
	}
	else if(m_strBy1=="����")
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
		MessageBox("���޴���!","��ʾ",MB_ICONWARNING);
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
		total/=6;
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

BOOL CSearch::OnInitDialog(void)
{
	CDialog::OnInitDialog();
	CString str[5]={"����","����","���","����","�ڹ����"};
	for(int i=0;i<5;i++)
	{
		m_chCombo.InsertString(i-1,str[i]);
	}
	//����Ĭ�ϲ�ѯ����Ϊ���
	m_chCombo.SetCurSel(1);


	m_chList.SetExtendedStyle(LVS_EX_FULLROWSELECT 
		| LVS_EX_GRIDLINES
		| LVS_EX_FLATSB
		| LVS_EX_HEADERDRAGDROP
		| LVS_EX_ONECLICKACTIVATE);   
	
    m_chList.ShowWindow(SW_SHOW);

    
    m_chList.InsertColumn(0, "ͼ������", LVCFMT_LEFT, 100);    
    m_chList.InsertColumn(1, "����", LVCFMT_LEFT, 100);    
    m_chList.InsertColumn(2, "�������", LVCFMT_LEFT, 100); 
    m_chList.InsertColumn(3, "���", LVCFMT_LEFT, 100); 
	m_chList.InsertColumn(4, "�Ƿ��ڹ�", LVCFMT_LEFT, 100);
	m_chList.InsertColumn(5, "�ȶ�", LVCFMT_LEFT, 100);
	//��������Ŀ
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
	return 0;
}

void CSearch::OnNMClickList1(NMHDR *pNMHDR, LRESULT *pResult)
{
	//LPNMITEMACTIVATE pNMItemActivate = reinterpret_cast<NMITEMACTIVATE>(pNMHDR);
	// TODO: �ڴ���ӿؼ�֪ͨ����������
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

void CSearch::OnBnClickedButtonAll()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
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

void CSearch::OnBnClickedButtonReserve()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	UpdateData();
	if(m_Title == "")
	{
		MessageBox("����δѡ��ͼ��","ERROR",0);
	}
	else{
		MessageBox("ԤԼ�ɹ������ǻ��ڽ����ڸ��������ʼ�","ԤԼ�ɹ�",0);
	}
}
