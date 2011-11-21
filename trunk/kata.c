#include "kata.h"

int panjangkata (char *kata)
/*Is: kata terdefinisi
mengembalikan jumlah sebuah kata*/
{
	int hitung=0;
	while (kata[hitung]!='\0')
	{
		++hitung;
	}
	return hitung;
}

int bandingkata (char *kata1, char *kata2)
/*I.S. 2 kata yang ingin dibandingkan
    jika kata1 > dari kata2 maka menghasilkan 1 (a>b)
	jika kata1<kata2 menghasilkan -1(b<a)
	jika kedua kata sama menghasilkan 0*/
{
	bool cek=true;
	int i=0;
	while (cek)
	{
		if (kata1[i]!=kata2[i])
		{
			if (kata1[i]>kata2[i])
			{
				return 1;
			}
			else
			{
				return -1;
			}
		}
		if ((kata1[i]==kata2[i]) && (kata1[i]=='\0'))
		{
			return 0;
		}
		++i;
	}
}

void copykata (char *kata1, char *kata2)
/*I.S. kata2 terdefinisi, kata1 sembarang
F.S. Kata2 disalin ke kata1*/
{
	int panjang=panjangkata(kata2);
	int i;
	for (i=0;i<panjang;++i)
	{
		kata1[i]=kata2[i];
	}
	kata1[panjang]='\0';
	kata1[panjang+1]=kata2[panjang+1];
}

bool bacakata (char *kata, char hingga, char alternatif)
/*I.S. kata terdefinisi
F.S. kata dibaca sampai bertemu hingga atau alternatif
Jika kata lebih panjang dari 250 maka kata tidak dibaca*/
{
	char c;
	bool salah;
	int i=0;
	scanf("%c",&c);
	while ((c!=hingga)&&(c!=alternatif))
	{
		kata[i]=c;
		++i;
		if (i==250)
		{
			i=0;
			salah=true;
		}
		scanf("%c",&c);
	}
	kata[i]='\0';
	if (c==hingga)
	{
		kata[i+1]=hingga;
	}
	else
	{
		kata[i+1]=alternatif;
	}
	if (salah)
	{
		return false;
	}
}

void bacakatafile (FILE *varfile, char *kata, char hingga, char alternatif)
/*I.S. varfile terdefinisi, kata terdefinisi
F.S. kata dibaca sampai bertemu hingga atau alternatif*/
{
	char c;
	int i=0;
	fscanf(varfile,"%c",&c);
	while ((c!=hingga)&&(c!=alternatif))
	{
		kata[i]=c;
		++i;
		fscanf(varfile,"%c",&c);
	}
	kata[i]='\0';
	if (c==hingga)
	{
		kata[i+1]=hingga;
	}
	else
	{
		kata[i+1]=alternatif;
	}
}

void tuliskata (char *kata)
/*I.S. kata terdefinisi
F.S. menulis kata tersebut*/
{
	int panjang=panjangkata(kata);
	int i;
	for (i=0;i<panjang;++i)
	{
		printf("%c",kata[i]);
	}
}

void tuliskatafile (FILE *varfile, char*kata)
/*I.S. kata terdefinisi, varfile terdefinisi
F.S. menulis kata tersebut pada varfile*/
{
	int panjang=panjangkata(kata);
	int i;
	for (i=0;i<panjang;++i)
	{
		fprintf(varfile,"%c",kata[i]);
	}
}

void trim (char *kata, char ditrim)
/*Is: kata terdefinisi
Fs:	kata ditrim sehingga karakter ditrim semua dihilangkan dari kata tersebut*/
{
	int panjang=panjangkata(kata);
	int panjanghasil=0,i;
	char hasil[panjang];
	for (i=0;i<panjang;++i)
	{
		if (kata[i]!=ditrim)
		{
			hasil[panjanghasil]=kata[i];
			++panjanghasil;
		}
	}
	hasil[panjanghasil]='\0';
	hasil[panjanghasil+1]=kata[panjang+1];
	copykata(kata,hasil);
}

void lowcase (char *kata)
{
	int panjang=panjangkata(kata);
	int i;
	for (i=0;i<panjang;++i)
	{
		if ((kata[i]>=65)&&(kata[i]<=90))
		{
			kata[i]+=32;
		}
	}
}
