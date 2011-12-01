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
	int i=0;
	while (kata1[i]!='\0')
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
		++i;
	}
	if ((kata1[i]==kata2[i]) && (kata1[i]=='\0'))
	{
		return 0;
	}
	return 0;
}

void copykata (char *kata1, char *kata2)
/*I.S. kata2 terdefinisi, kata1 sembarang
F.S. Kata2 disalin ke kata1*/
{
	int i=0;
	while (kata2[i]!='\0')
	{
		kata1[i]=kata2[i];
		++i;
	}
	kata1[i]='\0';
	kata1[i+1]=kata2[i+1];
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
	return true;
}

bool bacakatafile (FILE *varfile, char *kata, char hingga, char alternatif)
/*I.S. varfile terdefinisi, kata terdefinisi
F.S. kata dibaca sampai bertemu hingga atau alternatif*/
{
	char c;
	bool salah=false;
	int i=0;
	int temp;
	temp=fscanf(varfile,"%c",&c);
	while ((c!=hingga)&&(c!=alternatif))
	{
		if ((temp==0)||(temp==EOF))
		{
			return false;
		}
		kata[i]=c;
		++i;
		if (i==250)
		{
			i=0;
			salah=true;
		}
		temp=fscanf(varfile,"%c",&c);
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
	return true;
}

void tuliskata (char *kata)
/*I.S. kata terdefinisi
F.S. menulis kata tersebut*/
{
	int i=0;
	while (kata[i]!='\0')
	{
		printf("%c",kata[i]);
		++i;
	}
}

void tuliskatafile (FILE *varfile, char*kata)
/*I.S. kata terdefinisi, varfile terdefinisi
F.S. menulis kata tersebut pada varfile*/
{
	int i=0;
	while (kata[i]!='\0')
	{
		fprintf(varfile,"%c",kata[i]);
		++i;
	}
}

void trim (char *kata, char ditrim)
/*Is: kata terdefinisi
Fs:	kata ditrim sehingga karakter ditrim semua dihilangkan dari kata tersebut*/
{
	int panjanghasil=0,i=0;
	char hasil[250];
	while (kata[i]!='\0')
	{
		if (kata[i]!=ditrim)
		{
			hasil[panjanghasil]=kata[i];
			++panjanghasil;
		}
		++i;
	}
	hasil[panjanghasil]='\0';
	hasil[panjanghasil+1]=kata[i+1];
	copykata(kata,hasil);
}

void lowcase (char *kata)
/* Is: kata terdefinisi
Fs: kata dibuat sehingga semuanya menjadi lower case */
{
	int i=0;
	while (kata[i]!='\0')
	{
		if ((kata[i]>=65)&&(kata[i]<=90))
		{
			kata[i]+=32;
		}
		++i;
	}
}

int searchkata (char *kata, char dicari)
// Mencari suatu karakter tertentu dalam kata dan mengembalikan posisinya
{
	int i=0;
	while (kata[i]!='\0')
	{
		if (kata[i]==dicari)
		{
			return i;
		}
		++i;
	}
	return -1;
}

int katatoint (char *kata)
// Mengembalikan hasil konversi dari kata menjadi int
{
	int i=0;
	int hasil=0;
	bool negatif=false;
	if (kata[0]=='-')
	{
		++i;
		negatif=true;
	}
	while (kata[i]!='\0')
	{
		if ((kata[i]>=48)&&(kata[i]<=57))
		{
			hasil*=10;
			hasil+=kata[i]-48;
		}
		else
		{
			return -1000;
		}
		++i;
	}
	if (negatif)
	{
		hasil*=-1;
	}
	return hasil;
}
