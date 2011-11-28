
#include "listpertemanan.h"

extern const address Nil;

int NUser (List L)
/*Mengirimkan jumlah user*/
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
/*Mengirimkan jumlah teman dari user*/
{
	address P=First(L);
	addressf Q;
	int total=0;
	while ((P!=Nil)&&(bandingkata(X.nama,Info(P).nama)))
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
/* I.S. Sembarang */
/* F.S. Alamat P dialokasi, jika berhasil maka Info(P)=X dan
Next(P)=Nil */
{
	(*P)=(ElmtList *) malloc (1*sizeof (ElmtList));
	if ((*P) != Nil)
	{
		Info(*P) = X;
		Next(*P) = Nil;
	}
}

void AlokasiF (addressf *P, address X)
/* I.S. Sembarang */
/* F.S. Alamat P dialokasi, jika berhasil maka Friend(P)=X dan
Next(P)=Nil */
{
	(*P)=(FriendList *) malloc (1*sizeof (FriendList));
	if ((*P) != Nil)
	{
		Friend(*P) = X;
		Next(*P) = Nil;
	}
}

void Dealokasi (address *P, infotype *X)
/* I.S. P adalah hasil alokasi, P <> Nil */
/* F.S. Alamat P didealokasi, dikembalikan ke sistem */
{
	free(*P);
}

void DealokasiF (addressf *P, address *X)
/* I.S. P adalah hasil alokasi, P <> Nil */
/* F.S. Alamat P didealokasi, dikembalikan ke sistem */
{
	free(*P);
}

void AddFriend (List L, infotype X, infotype added)
/*I.S. infotype X ada didalam list L
F.S. Added ditambahakan sebagai teman X dalam list L*/
{
	address P,Q;
	P = First(L);
	Q = First(L);
	addressf R,S,T;
	
	while((bandingkata(X.email,Info(P).email)))
	//mencari user yang ingin meng-add
	{
		P = Next(P);
	}
	
	while((bandingkata(added.email,Info(Q).email)))
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
/*I.S. Infotype X terdapat didalam List L
F.S. Deleted dihapuskan dari teman X dalam list L*/
{
	address P,Q;
	P = First(L);
	addressf R,S;
	
	while((bandingkata(X.email,Info(P).email)))
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
		while((bandingkata(deleted.email,Info(Friend(R)).email)))
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
/*I.S. List L terdefinisi dengan X bukan anggota L
F.S X menjadi anggota List L*/
{

	address P,Q,R,S;
	P = First(L);
	Alokasi(&Q,X); /*Alokasi untuk mendapatkan address di list user*/
	if (P == Nil)
	{
		First(L) = Q;
		Next(Q) = Nil;
	}
	else /*kalau list tidak kosong*/
	{
		R = First(L);
		S = Nil;
		while ((bandingkata(Info(Q).nama,Info(R).nama)==1) && (Next(R) != Nil))
		//selama nama orang yang di add lebih besar urutan alfabet dari list user
		{
			S = R;
			R = Next(R);
		}
		if (Next(R) == Nil)
		//urutan list sudah di paling akhir
		{
			Next(R) = Q;
			Next(Q) = Nil;
		}
		else//urutan user yang bukan di paling akhir
		{
			if (S != Nil)
			//urutan user ada di tengah
			{
				Next(Q) = R;
				Next(S) = Q;
			}
			else
			//urutan user ada di awal
			{
				Next(Q) = First(L);
				First(L) = Q;
			}	
		}
	}
}

void RemoveUser (List L, infotype X)
/*I.S. List dengan info X ada
F.S. X dihapus dari list*/
{
	address P,Q,R,T;
	P = First(L);	
	Q = Nil;
	if (P == Nil)//bila kosong prosedure tidak melakukan apapun
	{
		
	}
	else /*kalau list tidak kosong*/
	{
		while((bandingkata(X.email,Info(P).email)))
		//mencari user yang memiliki info yang ingin di delete
		{
			Q = P;
			P = Next(P);
		}
		if (Q != Nil)
		//jika user yang ingin di delete bukan berada di awal
		{	
			Next(Q) = Next(P);
			Next(P) = Nil;
		}
		else
		{
		//jika user yang ingin di delete ada di awal
			First(L) = Next(P);
			Next(P) = Nil;
		}
		T= First(L);
		while(T != Nil)
		{
			if(IsTeman(L,Info(T),Info(P))==1)
			{ DeleteFriend(L,Info(T),Info(P)); // mendelete user yang memiliki P dari friendlist orang orang yang sudah menjadi friendnya
			}
			T = Next(T);
		}
		Dealokasi(&P,&Info(P));
	}
}


void ModifyUser (List L, infotype X)
{
	address P,Q,R,S,T;
	addressf U,V;
	P = First(L);
	Q = Nil;
	while((bandingkata(X.email,Info(P).email)))
	//mencari addres user untuk dilepaskan dari list untuk diubah infotypenya
	{	
		Q = P;
		P = Next(P);
	}
	Next(Q) = Next(P);
	Next(P) = Nil;
	//user dilepas sementara dari list
	AddUser(L,X);
	R = First(L);
	S = Nil;
	while((bandingkata(X.email,Info(R).email)))
	//mencari address baru user yang telah diubah infotype nya
	{	
		S = R;
		R = Next(R);
	}
	T = First(L);
	//mengubah alamat user yang lama menjadi yang baru
	while(T != Nil)
	{
		U = Flist(T);
		V = Nil;
		while((bandingkata(Info(P).email,Info(Friend(U)).email)) && (Next(U) != Nil))
		{
			V = U;
			U = Next(U);
		}
		if (Next(U) != Nil)
		{
			Friend(U) = R; // address friend telah diubah menjadi yang baru
		}
		T = Next(T);
	}
	Dealokasi(&P,&Info(P));
}

void Save (List L, FILE* namafile)
/*I.S List terdefinisi
F.S. Data pada List L disimpan dalam namafile*/
{address P;
P=First(L);
tuliskatafile (namafile,"@user\n");
while(Next(L)!=Nil)
{
	tuliskatafile (namafile, Info(P).email);
	tuliskatafile (namafile,' ');
	tuliskatafile(namafile,'\"');
	tuliskatafile (namafile, Info(P).nama);
	tuliskatafile(namafile,'\"');
	tuliskatafile (namafile, Info(P).tgllahir.hari);
	tuliskatafile(namafile,'-');
	tuliskatafile (namafile, Info(P).tgllahir.bulan);
	tuliskatafile(namafile,'-');
	tuliskatafile (namafile, Info(P).tgllahir.tahun);
	tuliskatafile(namafile,' \"');
	tuliskatafile (namafile, Info(P).kotaasal);
	tuliskatafile(namafile,'\"');
	tuliskatafile(namafile,' \"');
	tuliskatafile (namafile, Info(P).universitas);
	tuliskatafile(namafile,'\" ');
	tuliskatafile(namafile,'\"');
	tuliskatafile (namafile, Info(P).smu);
	tuliskatafile(namafile,'\"');
	tuliskatafile(namafile,"#\n");
	P=Next(P);

}

P=First (L);
addressf x;
x=FList(P);

tuliskatafile(namafile,'\n');
tuliskatafile (namafile,"@friend\n");
while(Next(P)!=Nil)
{while(Next(x)!=Nil)
	{
	tuliskatafile(namafile,Info(P).email);
	tuliskatafile(namafile," ->");
	tuliskatafile (namafile,Info(Friend(x)).email);
	tuliskatafile(namafile,'\n');
	x=Next(x);
	}
 P=Next(P);
}
tuliskatafile (namafile,"@end\n");
}

void Load (List *L, FILE* namafile)
/*I.S. List terdefinisi
F.S. Data List pada namafile di baca sebagai input List L*/
{	char x[10];
	infotype data;
	bacakatafile(namafile,x,' ','\n');
		 int EOP=1;
		 while(EOP!=0)
			{
				bacakatafile(namafile,x,' ','\n');
				bacakatafile(namafile,x,' ','\n');
				bacakatafile (namafile,data.email,'\"','\"');
				trim (data.email, ' ');
				trim (data.email, '\n');
				bacakatafile (namafile,x,'\"','\"');
				bacakatafile(namafile,data.nama,'\"','\"');
				bacakatafile(namafile,x,' ','\n');
				fscanf(namafile,"%d-%d-%d",&data.tanggal.hari,&data.tanggal.bulan,&data.tanggal.tahun);
				bacakatafile(namafile,x,' ','\n');
				bacakatafile (namafile,x,'\"','\"');
				bacakatafile (namafile, data.kotaasal,'\"','\"');
		
				bacakatafile (namafile,x,'\"','\"'); 
				bacakatafile (namafile, data.universitas,'\"','\"');
				// bacakatafile(namafile,x," ","\n");
				bacakatafile (namafile,x,'\"','\"');
				bacakatafile (namafile, data.smu,'\"','\"');
				bacakatafile(namafile,x,'\n','\n');
				trim(x,' ');
				AddUser(L,data);
				EOP=bandingkata(x,'#');
			}
			bacakatafile(namafile,x,'\n','\n');
			trim(x,' ');
			int Friends;
			Friends=bandingkata(x,"@friend");
			if (Friends==0)
				{EOF=bandingkata(x,"@end");
				if(EOF!=0)
				{infotype temp;
				infotype users;
				infotype teman;
				bacakatafile (namafile,users.email,' ',' ');
				trim (users.email, '\n');
				bacakatafile (namafile,x,'>','>');
				while(!EOF)
				{	
					bacakatafile(namafile,teman.email,' ','\n');
					trim (teman.email, ' ');
					trim (teman.email, '\n');
					AddFriend(L,users,teman);
					bacakatafile(namafile,temp.email,'-','\n');//membaca baris berikutnya
					trim (temp.email, ' ');
					trim (temp.email, '\n');
					EOF=bandingkata(temp.email,"@end");
					users.email=temp.email;
				}
				}
				}
}


void SortAsc ()
/*I.S.List terdefinisi
F.S. List terurut membesar (A-Z)*/
{
}

void SortDesc ()
/*I.S List terdefinisi
F.S List terurut mengecil (Z-A)*/
{
}

int IsTeman (List L, infotype X, infotype temanX)
{/* Kamus Lokal */
  address P;
  addressf Q,R;
  boolean Found;
  /* Algoritma */
  P = First(L);
  while (bandingkata((Info(P).email),(X.email)) != 0) {
         P = Next(P);
		 }
  /* P adalah address user */
  Q = FList(P);
  while ((bandingkata((Info(Friend(Q)).email),(temanX.email)) != 0) && (Q != Nil)){
         Q = Next(Q);
		 }
  /* Q = Nil (tidak ada di list teman level 1) atau ditemukan info teman yang dicari */
  if (Q != Nil) {
      return 1; /* address ditemukan, teman level 1 */
     }
  else { /* Teman bukan level 1, dicari lagi di level selanjutnya */
         Q = FList(P);
		 while ((Q != Nil) && !Found) {
		         R = FList(Friend(Q));
		         while ((bandingkata((Info(Friend(R)).email),(temanX.email)) != 0) && (R != Nil)){
                         R = Next(R);
		                 }
		         if (R != Nil){ /* Ditemukan teman level 2 */
		                 Found = true;
		                 return 2;}
		         else  {Q = Next(Q); /* Dicari lagi di list teman dari teman berikutnya */}
				  }
		 /* Keluar dari while: ditemukan di list teman dari teman atau tidak ditemukan di antara temannya teman (Q = Nil) */
		 if (Q == Nil) { /* Pencarian di list teman pertama sudah berakhir, tidak ditemukan sampai akhir list teman pertama */
		                Q = FList(Friend(P));
						while ((Q != Nil) && !Found) {
		                        R = FList(Friend(Q));
		                        while ((bandingkata((Info(Friend(R)).email),(temanX.email)) != 0) && (R != Nil)){
                                        R = Next(R);
		                                }
		                        if (R != Nil){ /* Ditemukan teman level 3 */
		                                      Found = true;
		                                      return 3;}
		                        else  {Q = Next(Q); /* Dicari lagi di list teman dari teman dari teman berikutnya */}
				            }
						if (Q == Nil) { /* Tidak ditemukan di list teman dari teman dari teman */
						               return 0;
									  }
		               }
        }
}

bool IsSame (List L, infotype X, infotype temanX, int parameter)
/* Melihat apakah temanX memiliki kesamaan dengan user X. */
/* Parameter: 1 untuk kota asal, 2 untuk SMU, 3 untuk Universitas */
{ /* Kamus Lokal */
  address P;
  addressf Q;
  /* Algoritma */
  if (IsTeman(L,X,temanX) != 0) {
       /* Teman level 1/2/3 */
	   if (parameter == 1) {
	          return (bandingkata((X.kotaasal),(temanX.kotaasal)) == 0);
	         }
	   else if (parameter == 2) {
	               return (bandingkata((X.smu),(temanX.smu)) == 0);
	         }
			else /* parameter == 3 */ {
			        return (bandingkata((X.universitas),(temanX.universitas)) == 0);
					}
	   }
  else {return false;} /* Bukan teman, tidak sama */
}
