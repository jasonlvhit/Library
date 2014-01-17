// Reader.cpp: implementation of the CReader class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "Library.h"
#include "Reader.h"
#include "Book.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CReader::CReader()
{
	m_nflag=1;
	for(int i=0;i<100;i++)
	{
		m_chName[i]=' ';
	    m_chE_Mail[i]=' ';
	    m_chPassWord[i]=' ';
	}
	for(int i=0;i<MAX_OWNED;i++)
	{
		m_BookOwned[i].m_nadd=0;
		m_BookOwned[i].m_nflag=0;
		m_BookOwned[i].m_nState=0;
	}
}
	