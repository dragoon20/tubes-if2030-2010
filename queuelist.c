#include "queuelist.h"
#include <stdlib.h>

extern const addressQ NilQ;

/*  *** Prototype manajemen memori ***  */

// procedure Alokasi (output P : addressQ, input X : infotype)
/*  I.S. P sembarang, X terdefinisi  */
/*  F.S. Alamat P dialokasi, jika berhasil maka Info(P) = X dan Next(P) = NilQ  */
/*  P = NilQ jika alokasi gagal  */
void AlokasiQ (addressQ *P, infotype X)
{
	(*P)=(ElmtQueue *) malloc (1*sizeof (ElmtQueue));
	if ((*P)!=NULL)
	{
		Info(*P)=X;
		Next(*P)=NilQ;
	}
}

// procedure Dealokasi (input/output P : addressQ)
/*  I.S. P adalah hasil alokasi, P <> NilQ  */
/*  F.S. Alamat P didealokasi, dikembalikan ke sistem  */
void DealokasiQ (addressQ *P)
{
	free(*P);
}

/*  *** Predikat Pemeriksaan Kondisi Queue ***  */

// function IsEmpty (Q : Queue) => boolean
/*  Mengirim true jika Q kosong: HEAD(Q) = NilQ and TAIL(Q) = NilQ  */
bool IsEmptyQ (Queue Q)
{
	return ((Head(Q)==NilQ)&&(Tail(Q)==NilQ));
}

// function NBElmt (Q : Queue) => integer
/*  Mengirimkan banyaknya elemen queue. Mengirimkan 0 jika Q kosong.  */
/*  *** Konstruktor ***  */
int NBElmtQ (Queue Q)
{
	addressQ P=Head(Q);
	int total=1;
	while (P!=Tail(Q))
	{
		P=Next(P);
		++total;
	}
	return total;
}

// procedure CreateEmpty (input/output Q : Queue)
/*  I.S. sembarang  */
/*  F.S. Sebuah Q kosong terbentuk  */
void CreateEmptyQ (Queue *Q)
{
	Head(*Q)=NilQ;
	Tail(*Q)=NilQ;
}

/*  *** Primitif Add/Delete ***  */

// procedure Add (input/output Q : Queue, input X : infotype)
/*  Proses : Mengalokasi X dan menambahkan X pada bagian TAIL dari Q jika alokasi
berhasil; jika alokasi gagal Q tetap  */
/*  I.S. Q mungkin kosong  */
/*  F.S. X menjadi TAIL, TAIL "maju"  */
void AddQ (Queue *Q, infotype X)
{
	addressQ P;
	AlokasiQ(&P,X);
	if (IsEmptyQ(*Q))
	{
		if (P!=NULL)
		{
			Head(*Q)=P;
			Tail(*Q)=P;
		}
	}
	else
	{
		if (P!=NULL)
		{
			Next(Tail(*Q))=P;
			Tail(*Q)=P;
		}
	}
}

// procedure Del (input/output Q : Queue, output X : infotype)
/*  Proses : Menghapus X pada bagian HEAD dari Q dan mendealokasi elemen HEAD  */
/*  I.S. Q tidak mungkin kosong  */
/*  F.S. X = NilQai elemen HEAD pd I.S., HEAD "mundur"  */
void DelQ (Queue *Q, infotype *X)
{
	addressQ P=Head(*Q);
	bool cek=false;
	*X=Info(P);
	if (NBElmtQ(*Q)==1)
	{
		cek=true;
	}
	Head(*Q)=Next(P);
	DealokasiQ(&P);
	if (cek)
	{
		Head(*Q)=NilQ;
		Tail(*Q)=NilQ;
	}
}
