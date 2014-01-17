// UserInformation.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "Library.h"
#include "UserInformation.h"
#include "Reader.h"
#include <fstream>
using namespace std;
extern wchar_t chE_Mail[100];
extern void Initial(wchar_t*p);
extern bool Compare(wchar_t *a,wchar_t *b);
#define MAX_OWNED 12
extern CReader ExistedReader;//ȫ�ֱ���
extern long PtrPosition;

// CUserInformation �Ի���

IMPLEMENT_DYNAMIC(CUserInformation, CDialog)

CUserInformation::CUserInformation(CWnd* pParent /*=NULL*/)
	: CDialog(CUserInformation::IDD, pParent)
	, m_strPassWord(_T(""))
	, m_strName(_T(""))
	, m_strInterest(_T(""))
	, m_strMajor(_T(""))
	
	, m_strInteres(_T(""))
{

}

CUserInformation::~CUserInformation()
{
}

void CUserInformation::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST1, m_List);
	
	DDX_Text(pDX, IDC_EDIT_USERNAME, m_strName);
	DDX_Text(pDX,IDC_EDIT_INTEREST,m_strInterest);
	DDX_Text(pDX, IDC_EDIT_MAJOR, m_strMajor);
	DDX_Text(pDX, IDC_EDIT1, m_strMajor);
	DDX_Text(pDX, IDC_EDIT_MAJOR, m_strInteres);
}
	 BOOL CUserInformation::OnInitDialog()
{
	//CReader ExistedReader;
	CDialog::OnInitDialog();
	 m_List.SetExtendedStyle(  LVS_EX_FULLROWSELECT| 
		LVS_EX_GRIDLINES
		| LVS_EX_FLATSB
		| LVS_EX_HEADERDRAGDROP
		| LVS_EX_ONECLICKACTIVATE);   
	
     // m_cbBooklist.ShowWindow(SW_SHOW);
	      m_List.InsertColumn(0,_T("�û���"),LVCFMT_LEFT,100,0);
          m_List.InsertColumn(1,_T("����"),LVCFMT_LEFT,100,1); 
		  m_List.InsertColumn(2,_T("����"),LVCFMT_LEFT,100,2);
		   m_List.InsertColumn(3,_T("��Ȥ"),LVCFMT_LEFT,100,3);
		    m_List.InsertColumn(4,_T("ר��"),LVCFMT_LEFT,100,4);
		 // ifstream IReaderFile("Reader.dat",ios::in|ios::binary);
		 // while(IReaderFile.peek()!=EOF)
		 // {
			//  position=IReaderFile.tellg();
			// IReaderFile.read((char*)&ExistedReader,sizeof(CReader));
			// if(Compare(ExistedReader.m_chE_Mail,chE_Mail))
			// {
            //    for(int count=0;count<MAX_OWNED;count++)
                m_List.InsertItem(0," ");
                m_List.SetItemText(0,0,(LPTSTR)ExistedReader.m_chName);
                m_List.SetItemText(0,1,(LPTSTR)ExistedReader.m_chE_Mail);
				m_List.SetItemText(0,2,(LPTSTR)ExistedReader.m_chPassWord);
				m_List.SetItemText(0,3,(LPTSTR)ExistedReader.m_chInterest);
				m_List.SetItemText(0,4,(LPTSTR)ExistedReader.m_chMajor);
		 // }
	//}
		//  IReaderFile.close();

return true;
}

BEGIN_MESSAGE_MAP(CUserInformation, CDialog)
	ON_NOTIFY(LVN_ITEMCHANGED, IDC_LIST1, &CUserInformation::OnLvnItemchangedList1)
	ON_NOTIFY(NM_CLICK, IDC_LIST1, &CUserInformation::OnNMClickList1)
	ON_BN_CLICKED(IDC_BUTTON_DESTROY, &CUserInformation::OnBnClickedButtonDestroy)
	ON_BN_CLICKED(IDC_BUTTON_SAVE, &CUserInformation::OnBnClickedButtonSave)
	ON_EN_CHANGE(IDC_EDIT1, &CUserInformation::OnEnChangeEdit1)
END_MESSAGE_MAP()


// CUserInformation ��Ϣ�������

void CUserInformation::OnLvnItemchangedList1(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMLISTVIEW pNMLV = reinterpret_cast<LPNMLISTVIEW>(pNMHDR);
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	*pResult = 0;
}

void CUserInformation::OnNMClickList1(NMHDR *pNMHDR, LRESULT *pResult)
{
	//LPNMITEMACTIVATE pNMItemActivate = reinterpret_cast<NMITEMACTIVATE>(pNMHDR);
	// TODO: �ڴ���ӿؼ�֪ͨ����������
   int pos=m_List.GetSelectionMark();
   m_strPassWord=m_List.GetItemText(pos,1);
   m_strName=m_List.GetItemText(pos,0);
   m_strInterest=m_List.GetItemText(pos,2);
   m_strInteres=m_List.GetItemText(pos,3);
   m_strMajor=m_List.GetItemText(pos,4);
   UpdateData(false);
	*pResult = 0;
}

void CUserInformation::OnBnClickedButtonDestroy()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
   //CReader ExistedReader;
	/*fstream ReaderFile(_T("Reader.dat"),ios::in|ios::out|ios::binary);
    //while(IReaderFile.peek!=EOF)
//{
     //IReaderFile.read((char *)ExistedReader,sizeof(CReader));
     //if(Compare(ExistedReader.m_chE_Mail,chE_Mail))
     //{
          ExistedReader.m_nflag=0;
		  ReaderFile.seekp(position,ios::beg);
          ReaderFile.write((char*)&ExistedReader,sizeof(CReader));
          ReaderFile.close();
          //break;
     //}*/
}


void CUserInformation::OnBnClickedButtonSave()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	UpdateData(true);
     Initial(ExistedReader.m_chName);
     Initial(ExistedReader.m_chE_Mail);
	 Initial(ExistedReader.m_chPassWord);
	 Initial(ExistedReader.m_chInterest);
	 Initial(ExistedReader.m_chMajor);
     lstrcpy((LPTSTR)ExistedReader.m_chName,m_strName);
	 lstrcpy((LPTSTR)ExistedReader.m_chE_Mail,m_strPassWord);
	 lstrcpy((LPTSTR)ExistedReader.m_chPassWord,m_strInterest);
	 lstrcpy((LPTSTR)ExistedReader.m_chInterest,m_strInteres);
	  lstrcpy((LPTSTR)ExistedReader.m_chMajor,m_strMajor);
	  fstream ReaderFile(_T("Reader.dat"),ios::in|ios::out|ios::binary);
	  ReaderFile.seekp(PtrPosition,ios::beg);
	  ReaderFile.write((char*)&ExistedReader,sizeof(CReader));
	  ReaderFile.close();
      m_List.SetItemText(0,0,(LPTSTR)ExistedReader.m_chName);
      m_List.SetItemText(0,1,(LPTSTR)ExistedReader.m_chE_Mail);
	  m_List.SetItemText(0,2,(LPTSTR)ExistedReader.m_chPassWord);
	  m_List.SetItemText(0,3,(LPTSTR)ExistedReader.m_chInterest);
	  m_List.SetItemText(0,4,(LPTSTR)ExistedReader.m_chMajor);
}

void CUserInformation::OnEnChangeEdit1()
{
	// TODO:  ����ÿؼ��� RICHEDIT �ؼ�������������
	// ���͸�֪ͨ��������д CDialog::OnInitDialog()
	// ���������� CRichEditCtrl().SetEventMask()��
	// ͬʱ�� ENM_CHANGE ��־�������㵽�����С�

	// TODO:  �ڴ���ӿؼ�֪ͨ����������
}
