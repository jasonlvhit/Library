// Register.cpp : implementation file
//
#include "stdafx.h"
#include "library.h"
#include "Register.h"
#include "Reader.h"
#include <fstream>
using namespace std;

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CRegister dialog
#include "stdafx.h"

size_t len(wchar_t *a)
{
	size_t i = 0;
	while(a[i] != ' ')
	{
		++i;
	}
	return i;
}

bool Compare(wchar_t *a,wchar_t *b)
{
	size_t i = 0;
	size_t lenofa = len(a);
	size_t lenofb = len(b);
	if(lenofa != lenofb)
		return false;

	while(a[i] != ' ')
	{
		if(a[i] != b[i])
			return false;
		++i;
	}
	return true;
}
void Initial(wchar_t * ch)
{
	for(int i=0;i<100;i++)
		ch[i]=' ';
}

CRegister::CRegister(CWnd* pParent /*=NULL*/)
	: CDialog(CRegister::IDD, pParent)
{
	//{{AFX_DATA_INIT(CRegister)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CRegister::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CRegister)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CRegister, CDialog)
	//{{AFX_MSG_MAP(CRegister)
	ON_BN_CLICKED(IDC_BUTTON_OKTODETAIL, OnButtonOktodetail)
	//}}AFX_MSG_MAP
	ON_BN_CLICKED(IDC_BUTTON_REGISTER_CANCEL, &CRegister::OnBnClickedButtonRegisterCancel)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CRegister message handlers

void CRegister::OnButtonOktodetail() 
{
START:
	 //Create a Reader which store the information readed from FILE READER.DAT

	
	/*CString ConfirmPassword;

	CFile file;
	CFileStatus status;
	CFileException fileException;
	if(CFile::GetStatus(_T("Reader.dat"),status))
	{
		if ( !file.Open( _T("Reader.dat"),   CFile::modeReadWrite, &fileException ) )
{
    TRACE( "Can't open file "Reader.dat", error = %u\n",  fileException.m_cause );
}
	}
	else
	{
		if ( !file.Open( pszFileName, CFile::modeCreate |   CFile::modeReadWrite, &fileException ) )
    {
    TRACE( "Can't open file "Reader.dat", error = %u\n",fileException.m_cause );
    }
	}
  DWORD position;*/
	CReader Reader;
	CReader ExistedReader;
	//memset(Reader.m_chPassWord,' ',100);
	wchar_t  chConfirmPassWord[100];
    Initial(chConfirmPassWord);
	//memset(ExistedReader.m_chPassWord,' ',100);
	//memset(chConfirmPassWord,' ',100);
	ifstream IReaderFile("Reader.dat",ios::in|ios::binary);
	
   //Get the information from Edit line

	if(GetDlgItemText(IDC_EDIT_REGISTERNAME,(LPTSTR)Reader.m_chName,100) == 0)
	{
		MessageBox("请输入用户名","Error",0);
	}
	else{

		if(GetDlgItemText(IDC_EDIT_MAIL,(LPTSTR)Reader.m_chE_Mail,100) == 0)
		{
			MessageBox("请输入您的邮箱，您的邮箱将成为您以后的登录方式","Error",0);
		}
		else{
			//position=file.GetPosition();
			//CArchive ar(&file,CArchive::load);
			//examinate the E_mail whether existed!
            
			while(IReaderFile.peek()!=EOF)
			{
				IReaderFile.read((char*)&ExistedReader,sizeof(ExistedReader));
				
				if(ExistedReader.m_nflag&&Compare(Reader.m_chE_Mail,ExistedReader.m_chE_Mail))
				{
					MessageBox("很抱歉，邮箱已存在",ERROR,0);
					SetDlgItemText(IDC_EDIT_MAIL,"");
					goto START;
				}
			}
			IReaderFile.close();

			if(GetDlgItemText(IDC_EDIT_REGISTERCODE,(LPTSTR)Reader.m_chPassWord,100) == 0)
			{
				MessageBox("请输入密码","Error",0);
			}
			else{

				if(GetDlgItemText(IDC_EDIT_REGISTERCODE_CONFIRM,(LPTSTR)chConfirmPassWord,100) == 0)
				{
					MessageBox("的确有点烦，但请您确认密码，最后一步了哦","Error",0);
				}
				else
				{
					
					GetDlgItemText(IDC_EDIT_REGISTERINTEREST,(LPTSTR)Reader.m_chInterest,100);
	                GetDlgItemText(IDC_EDIT_REGISTERMAJOR,(LPTSTR)Reader.m_chMajor,100);
					Reader.m_Financial = 1499.00;
	
					//examinate the password and comfirmed password whether identical!
	               
					if(!Compare(chConfirmPassWord,Reader.m_chPassWord))
					{
						MessageBox("很抱歉，你两次输入的密码不一致",ERROR,0);
					}
					else
					{
						ofstream OReaderFile("Reader.dat",ios::out|ios::app|ios::binary);
						OReaderFile.write((char*)&Reader,sizeof(Reader));
						MessageBox("注册成功！","Congratulation",0);
						OReaderFile.close();
	                    this->OnCancel();
					}
				}
			}
		}
	}

	//close the file stream
}

void CRegister::OnBnClickedButtonRegisterCancel()
{
	OnCancel();
	// TODO: 在此添加控件通知处理程序代码
}
