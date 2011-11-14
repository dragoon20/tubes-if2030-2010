
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
	addressf Q;
	int total=0;
	while ((P!=Nil)&&(!(bandingkata(X.nama,Info(P).nama))))
	{
		P=Next(P);
	}
	if (P==Nil)
	{
		return -1;
	}
	else
	{
		Q=FList(P);
		while (Q!=Nil)
		{
			total++;
			Q=Next(Q);
		}
		return total;
	}
}

void AddFriend (List L, infotype X, infotype added)
{
	jordan nanya, ini primitif isempty gtan make kaga? 
	trus ini infotype kenapa2? 1 kan buat infonya temen 1 lagi buat apa?
	misal sih a mau add b, maka X itu a dan added itu sih b.
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
