// InsertBook.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "Library.h"
#include "InsertBook.h"
#include "string"
#include "Book.h"
#include "Reader.h"
#include <fstream>

using namespace std;
extern CReader AimReader;
extern long Position;
extern void Initial(wchar_t*p);
#define MAX_OWNED 12


// CInsertBook �Ի���

IMPLEMENT_DYNAMIC(CInsertBook, CDialog)

CInsertBook::CInsertBook(CWnd* pParent /*=NULL*/)
	: CDialog(CInsertBook::IDD, pParent)
	, m_Title(_T(""))
	, m_Author(_T(""))
	, m_Year(_T(""))
	, m_Classification(_T(""))
	, m_Hot(_T(""))
	, m_A(_T(""))
	, m_DateBorrowed(_T(""))
	, m_DateShouldReturn(_T(""))
{

}

CInsertBook::~CInsertBook()
{
	
}

void CInsertBook::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST1, m_chList);
	DDX_Text(pDX, IDC_EDIT1, m_Title);
	DDX_Text(pDX, IDC_EDIT2, m_Author);
	DDX_Text(pDX, IDC_EDIT3, m_Year);
	DDX_Text(pDX, IDC_EDIT4, m_Classification);
	DDX_Text(pDX, IDC_EDIT5, m_Hot);
	DDX_Text(pDX, IDC_EDIT7, m_A);
	DDX_Text(pDX, IDC_EDIT6, m_DateBorrowed);
	DDX_Text(pDX, IDC_EDIT8, m_DateShouldReturn);
}


BEGIN_MESSAGE_MAP(CInsertBook, CDialog)
	ON_NOTIFY(NM_CLICK, IDC_LIST1, &CInsertBook::OnNMClickList1)
	ON_BN_CLICKED(IDC_BUTTON1, &CInsertBook::OnBnClickedButton1)
	ON_EN_CHANGE(IDC_EDIT8, &CInsertBook::OnEnChangeEdit8)
END_MESSAGE_MAP()


// CInsertBook ��Ϣ�������
BOOL CInsertBook::OnInitDialog()
{
   CDialog::OnInitDialog();
	//CString str[5]={"����","����","���","����","�ڹ����"};
	//for(int i=0;i<5;i++)
	//{
		//m_chCombo.InsertString(i-1,str[i]);
	//}
	//����Ĭ�ϲ�ѯ����Ϊ����
	//m_chCombo.SetCurSel(1);


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
	return TRUE;
}


void CInsertBook::OnNMClickList1(NMHDR *pNMHDR, LRESULT *pResult)
{
	//LPNMITEMACTIVATE pNMItemActivate = reinterpret_cast<NMITEMACTIVATE>(pNMHDR);
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	int pos=m_chList.GetSelectionMark();
	m_Title=m_chList.GetItemText(pos,0);
	m_Author=m_chList.GetItemText(pos,1);
	m_Year=m_chList.GetItemText(pos,2);
	m_Classification=m_chList.GetItemText(pos,3);
	m_A=m_chList.GetItemText(pos,4);
	m_Hot=m_chList.GetItemText(pos,5);
	UpdateData(false);
	*pResult = 0;
}

void CInsertBook::OnBnClickedButton1()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	int i;
	for( i=0;i<MAX_OWNED;i++)
	{
		UpdateData(true);
		if(m_DateBorrowed=="")
		{
			MessageBox("������������","ERROR",0);
             break;
		}
		if(m_DateShouldReturn=="")
		{
               MessageBox("������������","ERROR",0);
			   break;
		}
		if(!AimReader.m_BookOwned[i].m_nflag)
		{
			fstream ReaderFile(_T("Reader.dat"),ios::in|ios::out|ios::binary);
            AimReader.m_BookOwned[i].m_nflag=1;
			Initial(AimReader.m_BookOwned[i].m_chBookTitle);
			lstrcpy((LPTSTR)AimReader.m_BookOwned[i].m_chBookTitle,m_Title);
            lstrcpy((LPTSTR)AimReader.m_BookOwned[i].m_chWriter,m_Author);
			lstrcpy((LPTSTR)AimReader.m_BookOwned[i].m_chYear,m_Year);
			lstrcpy((LPTSTR)AimReader.m_BookOwned[i].m_chCategory,m_Classification);
			lstrcpy((LPTSTR)AimReader.m_BookOwned[i].m_nDateBorrowed,m_DateBorrowed);
			lstrcpy((LPTSTR)AimReader.m_BookOwned[i].m_nDateShouldReturn,m_DateShouldReturn);
			lstrcpy(AimReader.m_BookOwned[i].m_chHot,m_Hot);
			ReaderFile.seekp(Position,ios::beg);
            ReaderFile.write((char*)&AimReader,sizeof(CReader));
			ReaderFile.close();
		    MessageBox("����ɹ�","DONE",0);
			break;
		}
	}
	if(i==MAX_OWNED)
		MessageBox("�Ѵ�����","ERROR",0);
	

}

void CInsertBook::OnEnChangeEdit8()
{
	// TODO:  ����ÿؼ��� RICHEDIT �ؼ�������������
	// ���͸�֪ͨ��������д CDialog::OnInitDialog()
	// ���������� CRichEditCtrl().SetEventMask()��
	// ͬʱ�� ENM_CHANGE ��־�������㵽�����С�

	// TODO:  �ڴ���ӿؼ�֪ͨ����������
}
