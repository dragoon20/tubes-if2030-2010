
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

void Alokasi (address *P, infotype X)
{
	(*P)=(ElmtList *) malloc (1*sizeof (ElmtList));
	if ((*P) != Nil)
	{
		Info(*P) = X;
		Next(*P) = Nil;
	}
}

void AlokasiF (addressf *P, address X)
{
	(*P)=(FriendList *) malloc (1*sizeof (FriendList));
	if ((*P) != Nil)
	{
		Friend(*P) = X;
		Next(*P) = Nil;
	}
}

void Dealokasi (address *P, infotype *X)
{
	free(*P);
}

void DealokasiF (addressf *P, address *X)
{
	free(*P);
}

void AddFriend (List L, infotype X, infotype added)
{
	address P,Q;
	P = First(L);
	Q = First(L);
	addressf R,S,T;
	while(Info(P) != X)
	//mencari user yang ingin meng-add
	{
		P = Next(P);
	}
	while(Info(Q) != added)
	//mencari user dengan info yang ingin di add
	{
		Q = Next(Q);
	}
	R = AlokasiF(Q); /*AlokasiF untuk mendapatkan address di list teman dari address user*/
	if (FList(P) == Nil)
	{
		FList(P) = R;
		Next(R) = Nil;
	}
	else /*kalau list tidak kosong*/
	{
		S = FList(P);
		T = Nil;
		while ((bandingkata(Info(Q).nama,Info(Friend(S)).nama)==1) && (Next(S) != Nil))
		//selama nama orang yang di add lebih besar urutan alfabet dari friend list
		{
			T = S;
			S = Next(S);
		}
		if (Next(S) == Nil)
		//urutan orang yang di add sudah di paling akhir
		{
			Next(S) = R;
			Next(R) = Nil;
		}
		else//urutan orang yang di add bukan di paling akhir
		{
			if (T != Nil)
			//urutan orang yang di add ada di tengah
			{
				Next(R) = S;
				Next(T) = R;
			}
			else
			//urutan orang yang di add ada di awal
			{
				Next(R) = FList(P);
				FList(P) = R;
			}	
		}
	}
}

void DeleteFriend (List L, infotype X, infotype deleted)
{
	address P,Q;
	P = First(L);
	addressf R,S;
	while(Info(P) != X)
	//mencari addres user yang ingin men-delete
	{
		P = Next(P);
	}
	R = FList(P);
	S = Nil;
	if (FList(P) == Nil)//bila kosong prosedure tidak melakukan apapun
	{
		
	}
	else /*kalau list tidak kosong*/
	{
		while(Info(Friend(R)) != deleted)
		//mencari teman yang memiliki info yang ingin di delete
		{
			S = R;
			R = Next(R);
		}
		if (S != Nil)
		//jika teman yang ingin di delete bukan berada di awal
		{
			Next(S) = Next(R);
			Next(R) = Nil;
			DealokasiF(&R);
		}
		else
		{
		//jika teman yang ingin di delete ada di awal
			FList(P) = Next(R);
			Next(R) = Nil;
			DealokasiF(&R);
		}
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

void Load (List *L, char namafile[50])
{
}

void SortAsc ()
{
}

void SortDesc ()
{
}

int IsTeman (List L, infotype X, infotype temanX)
{/* Kamus Lokal */
  address P;
  addressf Q;
  /* Algoritma */
  P = First(L);
  while (Info(P) != X) {
         P = Next(P);
		 }
  /* P adalah address user */
  Q = FList(P);
  while ((Info(Friend(Q)) != temanX) && (Q != Nil)){
         Q = Next(Q);
		 }
  /* Q = Nil (tidak ada di list teman level 1) atau ditemukan info teman yang dicari */
  if (Q != Nil) {
      return 1; /* address ditemukan, teman level 1 */
     }
  else { /* Teman bukan level 1, dicari lagi di level selanjutnya */
        }
}

bool IsSame (List L, infotype X, infotype temanX, int parameter)
/* Melihat apakah temanX memiliki kesamaan dengan user X. */
/* Parameter: 1 untuk kota asal, 2 untuk SMU, 3 untuk Universitas */
{ /* Kamus Lokal */
  address P;
  addressf Q;
  /* Algoritma */
  if ((IsTeman(L,X,temanX) == 1) || (IsTeman(L,X,temanX) == 2) || (IsTeman(L,X,temanX) == 3)){
       /* Teman level 1/2/3 */
	   if (parameter == 1) {
	          return (bandingkata((X.kotaasal),(temanX.kotaasal)));
	         }
	   else if (parameter == 2) {
	               return (bandingkata((X.smu),(temanX.smu)));
	         }
			else /* parameter == 3 */ {
			        return (bandingkata((X.universitas),(temanX.universitas)));
					}
	   }
  else {return false;} /* Bukan teman tingkat 1/2/3, tidak sama */
}
