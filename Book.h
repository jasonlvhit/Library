// Book.h: interface for the CBook class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_BOOK_H__5A8F684A_9D9C_4D7A_B429_06BA65F96CDC__INCLUDED_)
#define AFX_BOOK_H__5A8F684A_9D9C_4D7A_B429_06BA65F96CDC__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

struct CBook
{
	char m_chTitle[100];
	char m_chAuthor[100];
	char m_nYear[100];
	char m_bAvailible[100];
	char m_chClassification[100];
	char m_chHit[100];
};










#endif // !defined(AFX_BOOK_H__5A8F684A_9D9C_4D7A_B429_06BA65F96CDC__INCLUDED_)