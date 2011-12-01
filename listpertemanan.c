
#include "listpertemanan.h"
#include "priorqueue.h"

extern const address Nil;
extern const addressf Nilf;

void CreateEmpty(List *L)
{
	First(*L)=Nil;
}

void MakeEmpty(List *L)
{
	address P=First(*L);
	address Q=Nil;
	while (P!=Nil)
	{
		Q=P;
		P=Next(P);
		//tuliskata(Info(Q).email);
		RemoveUser(L,Info(Q));
	}
}

bool IsEmpty(List L)
{
	return (First(L)==Nil);
}

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
		while (Q!=Nilf)
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
	FList(*P)=Nilf;
}

void AlokasiF (addressf *P, address X)
/* I.S. Sembarang */
/* F.S. Alamat P dialokasi, jika berhasil maka Friend(P)=X dan
Next(P)=Nil */
{
	(*P)=(FriendList *) malloc (1*sizeof (FriendList));
	if ((*P) != Nilf)
	{
		Friend(*P) = X;
		Next(*P) = Nilf;
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

bool AddFriend (List *L, infotype X, infotype added)
/*I.S. infotype X ada didalam list L
F.S. Added ditambahakan sebagai teman X dalam list L*/
{
	address P,Q;
	addressf R,S,T;
	
	P = First(*L);
	Q = First(*L);
	
	while (((bandingkata(X.email,Info(P).email)))||(bandingkata(added.email,Info(Q).email)))
	//mencari user yang ingin meng-add dan mencari user dengan info yang ingin di add
	{
		if (bandingkata(X.email,Info(P).email))
		{
			P = Next(P);
		}
		if (bandingkata(added.email,Info(Q).email))
		{
			Q = Next(Q);
		}
	}
	
	AlokasiF(&R,Q); /*AlokasiF untuk mendapatkan address di list teman dari address user*/
	if (R==Nilf)
	{
		return false;
	}
	if (FList(P) == Nilf)
	{
		FList(P) = R;
		Next(R) = Nilf;
	}
	else /*kalau list tidak kosong*/
	{
		S = FList(P);
		T = Nilf;
		while ((bandingkata(Info(Q).nama,Info(Friend(S)).nama)==1) && (Next(S) != Nilf))
		//selama nama orang yang di add lebih besar urutan alfabet dari friend list
		{
			T = S;
			S = Next(S);
		}
		if (Next(S) == Nilf)
		//urutan orang yang di add sudah di paling akhir
		{
			if ((T!=Nilf)&&(bandingkata(Info(Q).nama,Info(Friend(S)).nama)!=1))
			{
				Next(R)=S;
				Next(T)=R;
			}
			else
			{
				Next(S) = R;
				Next(R) = Nilf;
			}
		}
		else//urutan orang yang di add bukan di paling akhir
		{
			if (T != Nilf)
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
	return true;
}

bool DeleteFriend (List *L, address X, infotype deleted)
/*I.S. address X terdapat didalam List L
F.S. Deleted dihapuskan dari teman X dalam list L*/
{
	address Q;
	addressf R,S;
	
	R = FList(X);
	S = Nilf;
	if (FList(X) == Nilf)//bila kosong prosedure tidak melakukan apapun
	{
		return false;
	}
	else /*kalau list tidak kosong*/
	{
		while((R!=Nilf)&&(bandingkata(deleted.email,Info(Friend(R)).email)))
		//mencari teman yang memiliki info yang ingin di delete
		{
			S = R;
			R = Next(R);
		}
		if (S != Nilf)
		//jika teman yang ingin di delete bukan berada di awal
		{
			Next(S) = Next(R);
			Next(R) = Nilf;
			DealokasiF(&R,&Q);
		}
		else if (R==Nilf)
		{
			return false;
		}
		else
		{
		//jika teman yang ingin di delete ada di awal
			FList(X) = Next(R);
			Next(R) = Nilf;
			DealokasiF(&R,&Q);
		}
	}
	return true;
}

void AddUser (List *L, infotype X)
/*I.S. List L terdefinisi dengan X bukan anggota L
F.S X menjadi anggota List L*/
{

	address P,Q,S;

	P = First(*L);
	Alokasi(&Q,X); /*Alokasi untuk mendapatkan address di list user*/
	
	if (P == Nil)
	{
		First(*L) = Q;
		Next(Q) = Nil;
	}
	else /*kalau list tidak kosong*/
	{
		S = Nil;
		while ((bandingkata(Info(Q).nama,Info(P).nama)==1) && (Next(P) != Nil))
		//selama nama orang yang di add lebih besar urutan alfabet dari list user
		{
			S = P;
			P = Next(P);
		}
		if (Next(P) == Nil)
		//urutan list sudah di paling akhir
		{
			if (bandingkata(Info(Q).nama,Info(P).nama)==1)
			{
				Next(P) = Q;
				Next(Q) = Nil;
			}
			else
			{
				Next(Q) = P;
				Next(S) = Q;
			}
		}
		else//urutan user yang bukan di paling akhir
		{
			if (S != Nil)
			//urutan user ada di tengah
			{
				Next(Q) = P;
				Next(S) = Q;
			}
			else
			//urutan user ada di awal
			{
				Next(Q) = First(*L);
				First(*L) = Q;
			}	
		}
	}
}

void RemoveUser (List *L, infotype X)
/*I.S. List dengan info X ada
F.S. X dihapus dari list*/
{
	address P,Q,T;
	addressf R,S;
	
	P = First(*L);	
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
			First(*L) = Next(P);
			Next(P) = Nil;
		}
		R=FList(P);
		while (R!=Nilf)
		{
			FList(P) = Next(R);
			Next(R) = Nilf;
			DealokasiF(&R,&Q);
			R=FList(P);
		}
		T= First(*L);
		while (T != Nil)
		{
			//printf("a");
			R=FList(T);
			S=Nilf;
			while ((R!=Nilf)&&(bandingkata(Info(Friend(R)).email,Info(P).email)))
			{
				S=R;
				R=Next(R);
			}
			if ((S==Nilf)&&(R!=Nilf))
			{
				FList(T)=Next(R);
				Next(R)=Nilf;
				DealokasiF(&R,&Q);
			}
			else if (R!=Nilf)
			{
				Next(S) = Next(R);
				Next(R) = Nilf;
				DealokasiF(&R,&Q);
			}
			// mendelete user yang memiliki P dari friendlist orang orang yang sudah menjadi friendnya
			T = Next(T);
		}
		Dealokasi(&P,&Info(P));
	}
}


void ModifyUser (List *L, infotype X)
{
	address P,Q,R,T;
	addressf U,V;
	infotype x;
	
	P = First(*L);
	Q = Nil;
	while((bandingkata(X.email,Info(P).email)))
	//mencari addres user untuk dilepaskan dari list untuk diubah infotypenya
	{	
		//tuliskata(Info(P).email);
		Q = P;
		P = Next(P);
	}
	Next(Q) = Next(P);
	Next(P) = Nil;
	//user dilepas sementara dari list
	//tuliskata(X.nama);
	AddUser(L,X);
	R = First(*L);
	while((bandingkata(X.email,Info(R).email)))
	//mencari address baru user yang telah diubah infotype nya
	{	
		//tuliskata(Info(R).email);
		R = Next(R);
	}
	FList(R)=FList(P);
	FList(P)=Nilf;
	
	T = First(*L);
	//mengubah alamat user yang lama menjadi yang baru
	while(T != Nil)
	{
		if (T!=R)
		{
			//tuliskata(Info(T).email);
			U = FList(T);
			V = Nilf;
			while((U != Nilf)&&(bandingkata(Info(P).email,Info(Friend(U)).email)))
			{
				V = U;
				U = Next(U);
			}
			if ((U!=Nilf)&&(bandingkata(Info(P).email,Info(Friend(U)).email)==0))
			{
				Friend(U) = R; // address friend telah diubah menjadi yang baru
			}
		}
		T = Next(T);
	}
	Dealokasi(&P,&x);
}

void Save (List L, FILE* namafile)
/*I.S List terdefinisi
F.S. Data pada List L disimpan dalam namafile*/
{
	address P;
	P=First(L);
	tuliskatafile (namafile,"@user\n");
	while(P!=Nil)
	{
		tuliskatafile (namafile, Info(P).email);
		tuliskatafile (namafile," ");
		tuliskatafile(namafile,"\"");
		tuliskatafile (namafile, Info(P).nama);
		tuliskatafile(namafile,"\" ");
		fprintf(namafile,"%d-%d-%d",Info(P).tgllahir.hari,Info(P).tgllahir.bulan,Info(P).tgllahir.tahun);
		
		if(bandingkata(Info(P).kotaasal,""))
		{		
			tuliskatafile(namafile," \"");
			tuliskatafile (namafile, Info(P).kotaasal);
			tuliskatafile(namafile,"\" ");
		}
		else
		{
			tuliskatafile(namafile,"NIL ");
		}
		
		if(bandingkata(Info(P).universitas,""))
		{
			tuliskatafile(namafile," \"");
			tuliskatafile (namafile, Info(P).universitas);
			tuliskatafile(namafile,"\" ");
		}
		else
		{
			tuliskatafile(namafile,"NIL ");
		}
		if(bandingkata(Info(P).smu,""))
		{
			tuliskatafile(namafile,"\"");
			tuliskatafile (namafile, Info(P).smu);
			tuliskatafile(namafile,"\"");
		}
		else
		{
			tuliskatafile(namafile,"NIL");
		}
		tuliskatafile(namafile,"#\n");
		P=Next(P);
	}

	P=First(L);
	addressf x;

	tuliskatafile (namafile,"@friend\n");
	while(P!=Nil)
	{
		x=FList(P);
		while(x!=Nilf)
		{
			tuliskatafile(namafile,Info(P).email);
			tuliskatafile(namafile," ->");
			tuliskatafile (namafile,Info(Friend(x)).email);
			tuliskatafile(namafile,"\n");
			x=Next(x);
		}
		P=Next(P);
	}
	tuliskatafile (namafile,"@end\n");
}

bool Load (List *L, FILE* namafile)
/*I.S. List terdefinisi
F.S. Data List pada namafile di baca sebagai input List L*/
{	
	char x[50];
	char c;
	infotype data;
	bool EOP,temp;
	int tempdat;
	
	temp=bacakatafile(namafile,x,'@','@');
	if (!temp) {return temp;}
	temp=bacakatafile(namafile,x,' ','\n');
	if (!temp) {return temp;}
	lowcase(x);
	
	bool cek=!bandingkata(x,"user");
	bool cek2=!bandingkata(x,"friend");
	bool cek3=!bandingkata(x,"end");
	if (cek)
	{
		temp=bacakatafile (namafile,data.email,' ','\n');
		if (!temp) {return temp;}
		trim (data.email, ' ');
		trim (data.email, '\n');
	
		EOP=(data.email[0]=='@');
		while(!EOP)
		{
			temp=fscanf(namafile,"%c",&c);
			//printf("%c",c);
			if ((temp==0)||(temp==EOF)) {return false;}
			while ((c==' ')||(c=='\n'))
			{
				temp=fscanf(namafile,"%c",&c);
				if ((temp==0)||(temp==EOF)) {return false;}
			}
			//printf("%c",c);
			if (c=='\"')
			{
				temp=bacakatafile(namafile,data.nama,'\"','\"');
				if (!temp) {return temp;}
				temp=bacakatafile(namafile,x,' ','\n');
				if (!temp) {return temp;}
			}
			else
			{
				copykata(data.nama,"");
				temp=bacakatafile(namafile,x,' ','\n');
				if (!temp) {return temp;}
			}
			//tuliskata(data.nama);
			tempdat=fscanf(namafile,"%d-%d-%d",&data.tgllahir.hari,&data.tgllahir.bulan,&data.tgllahir.tahun);
			if ((tempdat==0)||(tempdat==EOF))
			{
				return false;
			}
			
			temp=fscanf(namafile,"%c",&c);
			if ((temp==0)||(temp==EOF)) {return false;}
			while ((c==' ')||(c=='\n'))
			{
				temp=fscanf(namafile,"%c",&c);
				if ((temp==0)||(temp==EOF)) {return false;}
			}
			if (c=='\"')
			{
				temp=bacakatafile (namafile, data.kotaasal,'\"','\"');
				if (!temp) {return temp;}
			}
			else
			{
				copykata(data.kotaasal,"");
				temp=bacakatafile(namafile,x,' ','\n');
				if (!temp) {return temp;}
			}
			
			temp=fscanf(namafile,"%c",&c);
			if ((temp==0)||(temp==EOF)) {return false;}
			while ((c==' ')||(c=='\n'))
			{
				temp=fscanf(namafile,"%c",&c);
				if ((temp==0)||(temp==EOF)) {return false;}
			}
			if (c=='\"')
			{
				temp=bacakatafile (namafile, data.universitas,'\"','\"');
				if (!temp) {return temp;}
			}
			else
			{
				copykata(data.universitas,"");
				temp=bacakatafile(namafile,x,' ','\n');
				if (!temp) {return temp;}
			}
	
			temp=fscanf(namafile,"%c",&c);
			if ((temp==0)||(temp==EOF)) {return false;}
			while ((c==' ')||(c=='\n'))
			{
				temp=fscanf(namafile,"%c",&c);
				if ((temp==0)||(temp==EOF)) {return false;}
			}
			if (c=='\"')
			{
				temp=bacakatafile (namafile, data.smu,'\"','\"');
				if (!temp) {return temp;}
			}
			else
			{
				copykata(data.smu,"");
			}
			
			temp=bacakatafile(namafile,x,'#','#');
			if (!temp) {return temp;}
			
			AddUser(L,data);
			
			temp=bacakatafile (namafile,data.email,'\n','\n');
			if (!temp) {return temp;}
			temp=bacakatafile (namafile,data.email,' ','\n');
			if (!temp) {return temp;}
			
			trim (data.email, ' ');
			trim (data.email, '\n');
		
			EOP=(data.email[0]=='@');
		}
		copykata(x,data.email);
		trim(x,'@');
		lowcase(x);
		
		cek2=!bandingkata(x,"friend");
		cek3=!bandingkata(x,"end");
	}
	if (cek2)
	{
		infotype users;
		infotype teman;
		
		temp=bacakatafile (namafile,users.email,'-','\n');
		if (!temp) {return temp;}
		trim(users.email,' ');
		
		EOP=(users.email[0]=='@');
		while(!EOP)
		{
			temp=bacakatafile (namafile,x,'>','>');
			if (!temp) {return temp;}

			temp=bacakatafile(namafile,teman.email,' ','\n');
			if (!temp) {return temp;}

			AddFriend(L,users,teman);
			
			temp=bacakatafile (namafile,users.email,'-','\n');
			if (!temp) {return temp;}
			trim(users.email,' ');
			EOP=(users.email[0]=='@');
		}
		copykata(x,users.email);
		trim(x,'@');
		lowcase(x);
		
		cek3=!bandingkata(x,"end");
	}
	if (!cek3)
	{
		return false;
	}
	return true;
}

int IsTeman (List L, address X, infotype temanX)
{
	/* Kamus Lokal */
	address P,S;
	addressf Q;
	PQueue PQ;
	bool Found=true;
	infotype temp;
	int x;
	
	CreateEmptyPQ(&PQ);
	
	/* Algoritma */
	P = X;
	
	/* P adalah address user */
	Q = FList(P);
	while ((Q != Nilf)&&(Found))
	{
		Found=bandingkata((Info(Friend(Q)).email),(temanX.email));
		//tuliskata(Info(Friend(Q)).email);
		//printf("\n");
		AddPQ(&PQ,Info(Friend(Q)),3);
		if (Found)
		{
			Q = Next(Q);
		}
	}
	/* Q = Nil (tidak ada di list teman level 1) atau ditemukan info teman yang dicari */
	if (!Found) 
	{
		while (!IsEmptyPQ(PQ))
		{
			DelPQ(&PQ,&temp,&x);
		}
		return 1; /* address ditemukan, teman level 1 */
    }
	else
	{ /* Teman bukan level 1, dicari lagi di level selanjutnya */
        P = First(L);
		while ((!IsEmptyPQ(PQ))&&(Prio(Head(PQ))==3)&&(Found))
		{
			DelPQ(&PQ,&temp,&x);
			//tuliskata(temp.email);
			//printf(" ");
			//tuliskata(Info(Head(PQ)).email);
			//printf(" ");
			while (bandingkata(temp.nama,Info(P).nama)==1)
			{
				P=Next(P);
			}
			S=P;
			while (bandingkata(temp.email,Info(S).email))
			{
				S=Next(S);
			}
			Q=FList(S);
			while ((Q != Nilf)&&(Found))
			{
				//tuliskata(Info(S).email);
				//printf(" ");
				//tuliskata(Info(Friend(Q)).email);
				//printf(" 2\n");
				if (bandingkata(Info(X).email,Info(Friend(Q)).email))
				{
					Found=bandingkata((Info(Friend(Q)).email),(temanX.email));
					AddPQ(&PQ,Info(Friend(Q)),2);
				}
				if (Found)
				{
					Q = Next(Q);
				}
			}
		}
		if (!Found)
		{
			while (!IsEmptyPQ(PQ))
			{
				DelPQ(&PQ,&temp,&x);
			}
			return 2; // ditemukan di level 2
		}
		else
		{
			P = First(L);
			while ((!IsEmptyPQ(PQ))&&(Prio(Head(PQ))==2)&&(Found))
			{
				DelPQ(&PQ,&temp,&x);
				while (bandingkata(temp.nama,Info(P).nama)==1)
				{
					P=Next(P);
				}
				S=P;
				while (bandingkata(temp.email,Info(S).email))
				{
					S=Next(S);
				}
				Q=FList(S);
				while ((Q != Nilf)&&(Found))
				{
					//tuliskata(Info(S).email);
					//printf(" ");
					//tuliskata(Info(Friend(Q)).email);
					//printf(" 3\n");
					Found=bandingkata((Info(Friend(Q)).email),(temanX.email));
					Q = Next(Q);
				}
			}
			if (!Found)
			{
				while (!IsEmptyPQ(PQ))
				{
					DelPQ(&PQ,&temp,&x);
				}
				return 3; //ditemukan di level 3
			}
			else
			{
				while (!IsEmptyPQ(PQ))
				{
					DelPQ(&PQ,&temp,&x);
				}
				return 0; //tidak ditemukan
			}
		}
    }
}

bool IsSame (infotype X, infotype temanX, int parameter)
/* Melihat apakah temanX memiliki kesamaan dengan user X. */
/* Parameter: 1 untuk kota asal, 2 untuk SMU, 3 untuk Universitas */
{ /* Kamus Lokal */

	/* Algoritma */
	if (parameter == 1) 
	{
		return (bandingkata((X.kotaasal),(temanX.kotaasal)) == 0);
	}
	else if (parameter == 2) 
	{
		return (bandingkata((X.smu),(temanX.smu)) == 0);
	}
	else /* parameter == 3 */ 
	{
		return (bandingkata((X.universitas),(temanX.universitas)) == 0);
	}
}
