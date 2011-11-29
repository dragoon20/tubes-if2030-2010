
#ifndef __DEFINISI__
#define __DEFINISI__

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
#define FList(X) (*X).FriendList
#define Next(X) (*X).Next
#define Friend(X) (*X).Friend
#define First(L) (L).First

#endif
