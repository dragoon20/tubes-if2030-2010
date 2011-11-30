/*  ADT priority PQueue berkait dengan representasi fisik pointer  */

#ifndef __PRIORPQueue__
#define __PRIORPQueue__

#include "boolean.h"
#include "definisi.h"

/*  Representasi addressPQ dengan pointer  */
/*  infotype adalah integer  */
/*  Prioritas berdasarkan nilai elemen prio yang menunjukkan prioritas  */
/*  PQueue terurut mengecil berdasarkan prioritas  */
// constant Nil : ... /*  terdefinisi  */

/*  *** Definisi Type PQueue ***  */

// type infotype : integer
// type addressPQ : pointer to ElmtPQueue
// type ElmtQ : < info : infotype,
// prio : integer,
// next : addressPQ >

typedef struct tElmtPQ *addressPQ;
typedef struct tElmtPQ
{
	infotype Info;
	int Prio;
	addressPQ Next;
}ElmtPQueue;

// type PQueue : < HEAD : addressPQ >
/*  Definisi priority PQueue :  */
/*  PQueue kosong : Head(Q) = Nil  */
/*  Setiap elemen dengan addressPQ P dapat diacu info(P), Next(P)  */
/*  Elemen terakhir list : jika addressPQnya Last, maka Next(Last)=Nil  */

typedef struct
{
	addressPQ Head;
}PQueue;

#define Prio(P) (*P).Prio
#define Head(Q) (Q).Head

/*  *** Prototype manajemen memori ***  */

// procedure Alokasi (output P : addressPQ, input X : infotype)
/*  I.S. P sembarang, X terdefinisi  */
/*  F.S. Alamat P dialokasi, jika berhasil maka Info(P) = X dan Next(P) = Nil  */
/*  P = Nil jika alokasi gagal  */
void AlokasiPQ (addressPQ *P, infotype X);

// procedure Dealokasi (input/output P : addressPQ)
/*  I.S. P adalah hasil alokasi, P <> Nil  */
/*  F.S. Alamat P didealokasi, dikembalikan ke sistem  */
void DealokasiPQ (addressPQ *P);

/*  *** Predikat Pemeriksaan Kondisi PQueue ***  */

// function IsEmpty (Q : PQueue) => boolean
/*  Mengirim true jika Q kosong: HEAD(Q) = Nil dan TAIL(Q) = Nil  */
bool IsEmptyPQ (PQueue Q);

// function NBElmt (Q : PQueue) => integer
/*  Mengirimkan banyaknya elemen PQueue. Mengirimkan 0 jika Q kosong.  */
int NBElmtPQ (PQueue Q);

/*  *** Konstruktor ***  */

// procedure CreateEmpty (output Q : PQueue)
/*  I.S. sembarang  */
/*  F.S. Sebuah Q kosong terbentuk  */
void CreateEmptyPQ (PQueue *Q);

/*  *** Primitif Add/Delete ***  */

// procedure Add (input/output Q : PQueue, input X : infotype, input Pr : integer)
/*  Proses : Mengalokasi X dan menambahkan X pada bagian TAIL dari Q jika alokasi
berhasil dengan memperhatikan prioritas; jika alokasi gagal Q tetap  */
/*  I.S. Q mungkin kosong, X terdefinisi  */
/*  F.S. X menjadi elemen Q sesuai prioritas Pr,
Q tetap terurut mengecil sesuai prioritas  */
void AddPQ (PQueue *Q, infotype X, int Pr);

void AddPQ2 (PQueue *Q, infotype X, int Pr, int parameter, int gt);

// procedure Del (input/output Q : PQueue, input X : infotype, input Pr : integer)
/*  Proses : Menghapus X pada bagian HEAD dari Q dan mendealokasi elemen HEAD,
X berisi elemen dengan prioritas tertinggi  */
/*  I.S. Q tidak kosong  */
/*  F.S. X = nilai elemen HEAD dan Pr = nilai elemen prioritas HEAD pd I.S.,
HEAD "maju"  */

void DelPQ (PQueue *Q, infotype *X, int *Pr);

#endif
