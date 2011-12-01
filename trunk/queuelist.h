/*  Modul Queue  */

#ifndef __QUEUELIST__
#define __QUEUELIST__

#include "definisi.h"
#include "boolean.h"

/*  Direpresentasikan dengan list linier, secara fisik dengan pointer  */
/*  Queue direpresentasikan sebagai list dengan first dan last  */
// constant Nil : ... /*  terdefinisi  */

/*  *** Definisi Type Queue ***  */

// type infotype : integer
// type addressQ : pointer to ElmtQueue
// type ElmtQueue : < info : infotype,
// next : addressQ >
typedef struct tElmtQ *addressQ;
typedef struct tElmtQ
{
	infotype Info;
	addressQ Next;
}ElmtQueue;

/*  Type Queue dengan ciri HEAD dan TAIL :  */
// type Queue : < HEAD : addressQ, /*  alamat penghapusan  */
// TAIL : addressQ /*  alamat penambahan  */ >

typedef struct
{
	addressQ Head;
	addressQ Tail;
}Queue;

#define Head(Q) (Q).Head
#define Tail(Q) (Q).Tail

/*  *** Prototype manajemen memori ***  */

// procedure Alokasi (output P : addressQ, input X : infotype)
/*  I.S. P sembarang, X terdefinisi  */
/*  F.S. Alamat P dialokasi, jika berhasil maka Info(P) = X dan Next(P) = Nil  */
/*  P = Nil jika alokasi gagal  */
void AlokasiQ (addressQ *P, infotype X);

// procedure Dealokasi (input/output P : addressQ)
/*  I.S. P adalah hasil alokasi, P <> Nil  */
/*  F.S. Alamat P didealokasi, dikembalikan ke sistem  */
void DealokasiQ (addressQ *P);

/*  *** Predikat Pemeriksaan Kondisi Queue ***  */

// function IsEmpty (Q : Queue) => boolean
/*  Mengirim true jika Q kosong: HEAD(Q) = Nil and TAIL(Q) = Nil  */
bool IsEmptyQ (Queue Q);

// function NBElmt (Q : Queue) => integer
/*  Mengirimkan banyaknya elemen queue. Mengirimkan 0 jika Q kosong.  */
/*  *** Konstruktor ***  */
int NBElmtQ (Queue Q);

// procedure CreateEmpty (input/output Q : Queue)
/*  I.S. sembarang  */
/*  F.S. Sebuah Q kosong terbentuk  */
/*  *** Primitif Add/Delete ***  */
void CreateEmptyQ (Queue *Q);

// procedure Add (input/output Q : Queue, input X : infotype)
/*  Proses : Mengalokasi X dan menambahkan X pada bagian TAIL dari Q jika alokasi
berhasil; jika alokasi gagal Q tetap  */
/*  I.S. Q mungkin kosong  */
/*  F.S. X menjadi TAIL, TAIL "maju"  */
void AddQ (Queue *Q, infotype X);

// procedure Del (input/output Q : Queue, output X : infotype)
/*  Proses : Menghapus X pada bagian HEAD dari Q dan mendealokasi elemen HEAD  */
/*  I.S. Q tidak mungkin kosong  */
/*  F.S. X = nilai elemen HEAD pd I.S., HEAD "mundur"  */
void DelQ (Queue *Q, infotype *X);

#endif
