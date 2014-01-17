// Addbook.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "Library.h"
#include "Addbook.h"
#include <fstream>
#include "Book.h"

using namespace std;

// CAddbook �Ի���

IMPLEMENT_DYNAMIC(CAddbook, CDialog)

CAddbook::CAddbook(CWnd* pParent /*=NULL*/)
	: CDialog(CAddbook::IDD, pParent)
{

}

CAddbook::~CAddbook()
{
}

void CAddbook::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CAddbook, CDialog)
	ON_BN_CLICKED(IDC_BUTTON_ADD, &CAddbook::OnBnClickedButtonAdd)
END_MESSAGE_MAP()


// CAddbook ��Ϣ�������

void CAddbook::OnBnClickedButtonAdd()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	fstream file("Book.txt",ios::app|ios::out);
	CBook Book;
	if(GetDlgItemText(IDC_EDIT_TITLE,(LPTSTR)Book.m_chTitle,100) == 0)
	{
		MessageBox("������ͼ������","ERROR",0);
	}
	else{
			if(GetDlgItemText(IDC_EDIT_AUTHOR,(LPTSTR)Book.m_chAuthor,100) == 0)
			{
				MessageBox("��������������","ERROR",0);
			}
			else{
				if(GetDlgItemText(IDC_EDIT_ID,(LPTSTR)Book.m_nId,100) == 0)
				{
					MessageBox("������ͼ����","ERROR",0);
				}
				else{
					if(GetDlgItemText(IDC_EDIT_PUBLICYEAR,(LPTSTR)Book.m_nYear,100) == 0)
					{
						MessageBox("�����������","ERROR",0);
					}
					else {
						if(GetDlgItemText(IDC_EDIT_CLASSIFICATION,(LPTSTR)Book.m_chClassification,100) == 0)
						{
							MessageBox("���������","ERROR",0);
						}
						else{
						Book.m_bAvailible = true;
						file.write((char*)&Book,sizeof(Book));
						file.close();
						MessageBox("��ӳɹ�","OK",0);
						}
					}
				}
			}
	}


}
