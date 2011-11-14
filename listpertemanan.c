
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
	address P;
	P = First(L);
	addressf Q,R;
	Q = Alokasi(added);
	while(Info(P) != X)
	{
		P = Next(P);
	}
	if (FList(P) == Nil)
	{
		FList(P) = Q;
		Next(Q) = Nil;
	}
	else /*kalau list tidak kosong*/
	{
		R = FList(P);
		while (Next(R)!=Nil);
		{
			R = Next(R);
		}
		Next(R) = Q;
		Next(Q) = Nil;
	}
}

void DeleteFriend (List L, infotype X, infotype deleted)
{
	address P;
	P = First(L);
	addressf Q,R;
	while(Info(P) != X)
	{
		P = Next(P);
	}
	if (FList(P) == Nil)
	{
		
	}
	else /*kalau list tidak kosong*/
	{
		R = FList(P);
		while (Info(Next(R))!= deleted);
		{
			Q = R;
			R = Next(R);
		}
		Next(R) = Nil;
		Next(Q) = Nil;
		Dealokasi (&Q);
	}
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
