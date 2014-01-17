// Recommend.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "Library.h"
#include "Recommend.h"
#include "Book.h"
#include <fstream>
#include <string>

using namespace std;


// CRecommend �Ի���

IMPLEMENT_DYNAMIC(CRecommend, CDialog)

CRecommend::CRecommend(CWnd* pParent /*=NULL*/)
	: CDialog(CRecommend::IDD, pParent)
	, m_Title(_T(""))
	, m_Author(_T(""))
	, hit(_T(""))
	, m_Year(_T(""))
{

}

CRecommend::~CRecommend()
{
}

void CRecommend::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST1, m_chList);
	DDX_Text(pDX, IDC_EDIT1, m_Title);
	DDX_Text(pDX, IDC_EDIT2, m_Author);
	
	
	DDX_Text(pDX, IDC_EDIT4, hit);
	DDX_Text(pDX, IDC_EDIT3, m_Year);
}


BEGIN_MESSAGE_MAP(CRecommend, CDialog)
	ON_NOTIFY(NM_CLICK, IDC_LIST1, &CRecommend::OnNMClickList1)
	ON_BN_CLICKED(IDC_BUTTON_RESERVE, &CRecommend::OnBnClickedButtonReserve)
END_MESSAGE_MAP()


// CRecommend ��Ϣ�������

BOOL CRecommend::OnInitDialog(void)
{
	CDialog::OnInitDialog();
		m_chList.SetExtendedStyle(LVS_EX_FULLROWSELECT 
		| LVS_EX_GRIDLINES
		| LVS_EX_FLATSB
		| LVS_EX_HEADERDRAGDROP
		| LVS_EX_ONECLICKACTIVATE);   
	
    m_chList.ShowWindow(SW_SHOW);

    
    m_chList.InsertColumn(0, "����", LVCFMT_LEFT, 100);    
    m_chList.InsertColumn(1, "����", LVCFMT_LEFT, 100);    
    m_chList.InsertColumn(2, "�������", LVCFMT_LEFT, 100); 
    m_chList.InsertColumn(3, "����", LVCFMT_LEFT, 100); 
	m_chList.InsertColumn(4, "�Ƿ��ڹ�", LVCFMT_LEFT, 100);
	m_chList.InsertColumn(5, "�ȶ�", LVCFMT_LEFT, 100);

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

	ifstream file("ReBook.txt");
	CBook book;
	char standar[100] = {'0'};
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

void CRecommend::OnNMClickList1(NMHDR *pNMHDR, LRESULT *pResult)
{
	//LPNMITEMACTIVATE pNMItemActivate = reinterpret_cast<NMITEMACTIVATE>(pNMHDR);
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	
	int pos=m_chList.GetSelectionMark();
	m_Title=m_chList.GetItemText(pos,0);
	m_Author=m_chList.GetItemText(pos,1);
	m_Year=m_chList.GetItemText(pos,2);
	
	
	hit=m_chList.GetItemText(pos,5);
	UpdateData(false);
	*pResult = 0;
}

void CRecommend::OnBnClickedButtonReserve()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	UpdateData();
	if(m_Title== "")
	{
		MessageBox("����δѡ��ͼ��","Error",0);
	}
	else
	{
		MessageBox("ԤԼ�ɹ������ǻ��ڽ���֪ͨ����ȡ��","ԤԼ�ɹ�",0);
	}
}
