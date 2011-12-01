#ifndef __LIST__
#define __LIST__

#include "definisi.h"
#include <stdlib.h>
#include "boolean.h"
#include "kata.h"

/* ********* Prototype ********* */

void CreateEmpty(List *L);

void MakeEmpty(List *L);

bool IsEmpty(List L);

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
/* F.S. Alamat P dialokasi, jika berhasil maka Friend(P)=X dan
Next(P)=Nil */

void Dealokasi (address *P, infotype *X);
/* I.S. P adalah hasil alokasi, P <> Nil */
/* F.S. Alamat P didealokasi, dikembalikan ke sistem */

void DealokasiF (addressf *P, address *X);
/* I.S. P adalah hasil alokasi, P <> Nil */
/* F.S. Alamat P didealokasi, dikembalikan ke sistem */

bool AddFriend (List *L, infotype X, infotype added);
/*I.S. infotype X ada didalam list L
F.S. Added ditambahakan sebagai teman X dalam list L*/

bool DeleteFriend (List *L, address X, infotype deleted);
/*I.S. Infotype X terdapat didalam List L
F.S. Deleted dihapuskan dari teman X dalam list L*/

void AddUser (List *L, infotype X);
/*I.S. List L terdefinisi dengan X bukan anggota L
F.S X menjadi anggota List L*/

void RemoveUser (List *L, infotype X);
/*I.S. List dengan info X ada
F.S. X dihapus dari list*/

void ModifyUser (List *L, infotype X);
/*I.S. List  */

void Save (List L, FILE* namafile);
/*I.S List terdefinisi
F.S. Data pada List L disimpan dalam namafile*/

bool Load (List *L, FILE* namafile);
/*I.S. List terdefinisi
F.S. Data List pada namafile di baca sebagai input List L*/

int IsTeman (List L, address X, infotype temanX);
/*Predikat untuk mengecek apakah temanX adalah teman dari X. Jika temanX adalah teman tingkat 1 maka menghasilkan 1, jika teman dari teman (teman tingkat 2) menghasilkan 2*/

bool IsSame (infotype X, infotype temanX, int parameter);
/*Predikat untuk mengecek apakah data yang diminta sesuai dengan data yang pada teman, parameter untuk menunjukkan data apa yang dibandingkan
jika 1, berarti yang dibandingkan data tanggal lahir, 2 berarti kota asal, 3 berarti universitas, 4 berarti asal sma*/

#endif
