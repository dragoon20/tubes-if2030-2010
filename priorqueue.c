#include "priorqueue.h"
#include "kata.h"
#include <stdlib.h>
#include <stdio.h>

extern const addressPQ NilPQ;

/*  *** Prototype manajemen memori ***  */

// procedure Alokasi (output P : addressPQ, input X : infotype)
/*  I.S. P sembarang, X terdefinisi  */
/*  F.S. Alamat P dialokasi, jika berhasil maka Info(P) = X dan Next(P) = NilPQ  */
/*  P = NilPQ jika alokasi gagal  */
void AlokasiPQ (addressPQ *P, infotype X)
{
	(*P)=(ElmtPQueue *) malloc (1*sizeof (ElmtPQueue));
	if ((*P)!=NULL)
	{
		Info(*P)=X;
		Next(*P)=NilPQ;
	}
}

// procedure Dealokasi (input/output P : addressPQ)
/*  I.S. P adalah hasil alokasi, P <> NilPQ  */
/*  F.S. Alamat P didealokasi, dikembalikan ke sistem  */
void DealokasiPQ (addressPQ *P)
{
	free(*P);
}

/*  *** Predikat Pemeriksaan Kondisi PQueue ***  */

// function IsEmpty (Q : PQueue) => boolean
/*  Mengirim true jika Q kosong: HEAD(Q) = NilPQ dan TAIL(Q) = NilPQ  */
bool IsEmptyPQ (PQueue Q)
{
	return (Head(Q)==NilPQ);
}

// function NBElmt (Q : PQueue) => integer
/*  Mengirimkan banyaknya elemen PQueue. Mengirimkan 0 jika Q kosong.  */
int NBElmtPQ (PQueue Q)
{
	addressPQ P=Head(Q);
	int total=0;
	while (P!=NilPQ)
	{
		++total;
		P=Next(P);
	}
	return total;
}

/*  *** Konstruktor ***  */

// procedure CreateEmpty (output Q : PQueue)
/*  I.S. sembarang  */
/*  F.S. Sebuah Q kosong terbentuk  */
void CreateEmptyPQ (PQueue *Q)
{
	Head(*Q)=NilPQ;
}

/*  *** Primitif Add/Delete ***  */

// procedure Add (input/output Q : PQueue, input X : infotype, input Pr : integer)
/*  Proses : Mengalokasi X dan menambahkan X pada bagian TAIL dari Q jika alokasi
berhasil dengan memperhatikan prioritas; jika alokasi gagal Q tetap  */
/*  I.S. Q mungkin kosong, X terdefinisi  */
/*  F.S. X menjadi elemen Q sesuai prioritas Pr,
Q tetap terurut mengecil sesuai prioritas  */
void AddPQ (PQueue *Q, infotype X, int Pr)
{
	addressPQ P=Head(*Q);
	addressPQ temp;
	AlokasiPQ(&temp,X);
	bool cek;
	if (temp!=NULL)
	{
		Prio(temp)=Pr;
		if (IsEmptyPQ(*Q))
		{
			Head(*Q)=temp;
			Next(temp)=NilPQ;
		}
		else
		{
			cek=(bandingkata(Info(P).email,Info(temp).email));
			if (cek)
			{
				if (Prio(P)<Pr)
				{
					Next(temp)=P;
					Head(*Q)=temp;
				}
				else
				{
					while (((bandingkata(Info(temp).nama,Info(P).nama)==1)||(bandingkata(Info(temp).nama,Info(P).nama)==0))&&((Next(P)!=NilPQ)&&(Prio(Next(P))>=Pr))&&(cek))
					{
						P=Next(P);
						cek=(!bandingkata(Info(P).email,Info(temp).email));
					}
					if (cek)
					{
						Next(temp)=Next(P);
						Next(P)=temp;
					}
				}
			}
		}
	}
}

// procedure Del (input/output Q : PQueue, input X : infotype, input Pr : integer)
/*  Proses : Menghapus X pada bagian HEAD dari Q dan mendealokasi elemen HEAD,
X berisi elemen dengan prioritas tertinggi  */
/*  I.S. Q tidak kosong  */
/*  F.S. X = NilPQai elemen HEAD dan Pr = NilPQai elemen prioritas HEAD pd I.S.,
HEAD "maju"  */

void DelPQ (PQueue *Q, infotype *X, int *Pr)
{
	addressPQ P=Head(*Q);
	*Pr=Prio(P);
	*X=Info(P);
	Head(*Q)=Next(P);
	DealokasiPQ(&P);
}

