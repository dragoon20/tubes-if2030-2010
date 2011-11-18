#ifndef __LIST__
#define __LIST__

#include "boolean.h"
#include "kata.h"
/*Deklarasi tanggal*/
typedef struct
{
	int hari;
	int bulan;
	int tahun;
} tanggal;
/* Deklarasi infotype */
typedef struct
{
	char email[50];
	char nama[50];
	tanggal tgllahir;
	char kotaasal[50];
	char universitas[50];
	char smu[50];
} infotype;
 /* *** Definisi List Friend *** */ 
typedef struct tElmtlist *address;

typedef struct tFriendList *addressf;
/*list friend dari user*/
typedef struct tFriendList
{
	address Friend;
	addressf Next;
}FriendList;
/*List user*/
typedef struct tElmtlist
{
	infotype Info;
	addressf FriendList;
	address Next;
}ElmtList;

typedef struct
{
	address First;
}List;
/*Selektor*/
#define Info(X) (*X).Info
#define FList(X) (*X).FList
#define Next(X) (*X).Next
#define Friend(X) (*X).Friend
#define First(L) L.First

/* ********* Prototype ********* */
int NUser (List L);
/*Mengirimkan jumlah user*/
int NFriend (List L, infotype X);
/*Mengirimkan jumlah teman dari user*/
void Alokasi (address *P, infotype X);
/* I.S. Sembarang */
/* F.S. Alamat P dialokasi, jika berhasil maka Info(P)=X dan
Next(P)=Nil */
void AlokasiF (addressf *P, address X);
/* I.S. Sembarang */
/* F.S. Alamat P dialokasi, jika berhasil maka Info(P)=X dan
Next(P)=Nil */
void Dealokasi (address *P, infotype *X);
/* I.S. P adalah hasil alokasi, P <> Nil */
/* F.S. Alamat P didealokasi, dikembalikan ke sistem */
void DealokasiF (addressf *P, address *X);
/* I.S. P adalah hasil alokasi, P <> Nil */
/* F.S. Alamat P didealokasi, dikembalikan ke sistem */
/*Mengirimkan jumlah teman dari user*/
void AddFriend (List L, infotype X, infotype added);
/*I.S. infotype X ada didalam list L
F.S. Added ditambahakan sebagai teman X dalam list L*/
void DeleteFriend (List L, infotype X, infotype deleted);
/*I.S. Infotype X terdapat didalam List L
F.S. Deleted dihapuskan dari teman X dalam list L*/
void AddUser (List L, infotype X);
/*I.S. List L terdefinisi dengan X bukan anggota L
F.S X menjadi anggota List L*/
void RemoveUser (List L, infotype X);
/*I.S. List dengan info X ada
F.S. X dihapus dari list*/
void ModifyUser (List L, infotype X);
/*I.S. List  */
void Save (List L, char namafile[50]);
/*I.S List terdefinisi
F.S. Data pada List L disimpan dalam namafile*/
void Load (List L, char namafile[50]);
/*I.S. List terdefinisi
F.S. Data List pada namafile di baca sebagai input List L*/
void SortAsc ();
/*I.S.List terdefinisi
F.S. List terurut membesar (A-Z)*/
void SortDesc ();
/*I.S List terdefinisi
F.S List terurut mengecil (Z-A)*/
int IsTeman (List L, infotype X, infotype temanX);
/*Predikat untuk mengecek apakah temanX adalah teman dari X. Jika temanX adalah teman tingkat 1 maka menghasilkan 1, jika teman dari teman (teman tingkat 2) menghasilkan 2*/
bool IsSame (List L, infotype X, infotype temanX, int parameter);
/*Predikat untuk mengecek apakah data yang diminta sesuai dengan data yang pada teman, parameter untuk menunjukkan data apa yang dibandingkan
jika 1, berarti yang dibandingkan data tanggal lahir, 2 berarti kota asal, 3 berarti universitas, 4 berarti asal sma*/
#endif
