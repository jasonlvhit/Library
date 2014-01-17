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