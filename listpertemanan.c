
#include "listpertemanan.h"

extern const address Nil;

int NUser (List L)
{
	address P=First(L);
	int total=0;
	while (P!=Nil)
	{
		total++;
		P=Next(P);
	}
	return total;
}

int NFriend (List L, infotype X)
{
	address P=First(L);
	while (P!=Nil)
	{
	}
}

void AddFriend (List L, infotype X, infotype added)
{
	jordan nanya, ini primitif isempty gtan make kaga? 
	trus ini infotype kenapa2? 1 kan buat infonya temen 1 lagi buat apa?
	if ()
	{
	}
	else /*kalau list tidak kosong*/
	{
	}
}

void DeleteFriend (List L, infotype X, infotype deleted)
{
}

void AddUser (List L, infotype X)
{
}

void RemoveUser (List L, infotype X)
{
}

void ModifyUser (List L, infotype X)
{
}

void Save (List L, char namafile[50])
{
}

void Load (List L, char namafile[50])
{
}

void SortAsc ()
{
}

void SortDesc ()
{
}

int IsTeman (List L, infotype X, infotype temanX)
{
}

bool IsSame (List L, infotype X, infotype temanX, int parameter)
{
}
