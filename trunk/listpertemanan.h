#ifndef __LIST__
#define __LIST__

#include "boolean.h"
#include "kata.h"

typedef struct
{
	int hari;
	int bulan;
	int tahun;
} tanggal;

typedef struct
{
	char email[50];
	char nama[50];
	tanggal tgllahir;
	char kotaasal[50];
	char universitas[50];
	char smu[50];
} infotype;

typedef struct tElmtlist *address;

typedef struct tFriendList *addressf;

typedef struct tFriendList
{
	address Friend;
	addressf Next;
}FriendList;

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

#define Info(X) (*X).Info
#define FList(X) (*X).FList
#define Next(X) (*X).Next
#define Friend(X) (*X).Friend
#define First(L) L.First

int NUser (List L);

int NFriend (List L, infotype X);

void Alokasi (address *P, infotype X);

void AlokasiF (addressf *P, address X);

void Dealokasi (address *P, infotype *X);

void DealokasiF (addressf *P, address *X);

void AddFriend (List L, infotype X, infotype added);

void DeleteFriend (List L, infotype X, infotype deleted);

void AddUser (List L, infotype X);

void RemoveUser (List L, infotype X);

void ModifyUser (List L, infotype X);

void Save (List L, char namafile[50]);

void Load (List *L, char namafile[50]);

void SortAsc ();

void SortDesc ();

int IsTeman (List L, infotype X, infotype temanX);

bool IsSame (List L, infotype X, infotype temanX, int parameter);

#endif
