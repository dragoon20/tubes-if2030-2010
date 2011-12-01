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
	//tuliskata(X.email);
	//printf(" 0\n");
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
					while (((Next(P)!=NilPQ)&&(Prio(Next(P))>=Pr))&&(cek))
					{
						P=Next(P);
						cek=(bandingkata(Info(P).email,Info(temp).email));
					}
					if (cek)
					{
						if (Next(P)!=NilPQ)
						{
							Next(temp)=Next(P);
							Next(P)=temp;
						}
						else
						{
							Next(P)=temp;
						}
					}
				}
			}
		}
	}
}

void AddPQ2 (PQueue *Q, infotype X, int Pr, int parameter, int gt)
{
	addressPQ P=Head(*Q),Qu=NilPQ;
	addressPQ temp;
	AlokasiPQ(&temp,X);
	bool cek,cek2,cek3,cek4;
	parameter++;
	//printf("%d",parameter);
	if (gt==0)
	{
		gt=-1;
	}
	gt*=-1;
	
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
					cek4=(bandingkata(Info(temp).email,Info(P).email)==gt);
					switch (parameter)
					{
						case 1:
							{
								cek2=(bandingkata(Info(temp).email,Info(P).email)==gt);
								cek3=(bandingkata(Info(temp).email,Info(P).email)==0);
								break;
							}
						case 2:
							{
								cek2=(bandingkata(Info(temp).nama,Info(P).nama)==gt);
								cek3=(bandingkata(Info(temp).nama,Info(P).nama)==0);
								break;
							}
						case 3:
							{
								cek2=(bandingtanggal(Info(temp).tgllahir,Info(P).tgllahir)==gt);
								cek3=(bandingtanggal(Info(temp).tgllahir,Info(P).tgllahir)==0);
								break;
							}
						case 4:
							{
								cek2=(bandingkata(Info(temp).kotaasal,Info(P).kotaasal)==gt);
								cek3=(bandingkata(Info(temp).kotaasal,Info(P).kotaasal)==0);
								break;
							}
						case 5:
							{
								cek2=(bandingkata(Info(temp).universitas,Info(P).universitas)==gt);
								cek3=(bandingkata(Info(temp).universitas,Info(P).universitas)==0);
								break;
							}
						case 6:
							{
								cek2=(bandingkata(Info(temp).smu,Info(P).smu)==gt);
								cek3=(bandingkata(Info(temp).smu,Info(P).smu)==0);
								break;
							}
						default:
							{
								break;
							}
					}
					while ((((cek2)&&(cek4))||(cek3))&&((Next(P)!=NilPQ)&&(cek)))
					{
						Qu=P;
						P=Next(P);
						cek=(bandingkata(Info(P).email,Info(temp).email));
						cek4=(bandingkata(Info(temp).email,Info(P).email)==gt);
						switch (parameter)
						{
							case 1:
								{
									cek2=(bandingkata(Info(temp).email,Info(P).email)==gt);
									cek3=(bandingkata(Info(temp).email,Info(P).email)==0);
									break;
								}
							case 2:
								{
									cek2=(bandingkata(Info(temp).nama,Info(P).nama)==gt);
									cek3=(bandingkata(Info(temp).nama,Info(P).nama)==0);
									break;
								}
							case 3:
								{
									cek2=(bandingtanggal(Info(temp).tgllahir,Info(P).tgllahir)==gt);
									cek3=(bandingtanggal(Info(temp).tgllahir,Info(P).tgllahir)==0);
									break;
								}
							case 4:
								{
									cek2=(bandingkata(Info(temp).kotaasal,Info(P).kotaasal)==gt);
									cek3=(bandingkata(Info(temp).kotaasal,Info(P).kotaasal)==0);
									break;
								}
							case 5:
								{
									cek2=(bandingkata(Info(temp).universitas,Info(P).universitas)==gt);
									cek3=(bandingkata(Info(temp).universitas,Info(P).universitas)==0);
									break;
								}
							case 6:
								{
									cek2=(bandingkata(Info(temp).smu,Info(P).smu)==gt);
									cek3=(bandingkata(Info(temp).smu,Info(P).smu)==0);
									break;
								}
							default:
								{
									break;
								}
						}
					}
					// tuliskata(Info(P).email);
					// printf(" %d %d\n",cek2,cek3);
					// tuliskata(Info(temp).email);
					// printf("\n");
					if (cek)
					{
						if (((!cek2)&&(!cek3))&&(P==Head(*Q)))
						{
							Head(*Q)=temp;
							Next(temp)=P;
						}
						else if ((!cek2)&&(!cek3))
						{
							Next(temp)=P;
							Next(Qu)=temp;
						}
						else
						{
							//printf("%d",gt);
							Next(temp)=Next(P);
							Next(P)=temp;
						}
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

