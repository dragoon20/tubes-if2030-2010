#include "kata.h"

int panjangkata (char *kata)
{
	int hitung=0;
	while (kata[hitung]!='\0')
	{
		++hitung;
	}
	return hitung;
}

int bandingkata (char *kata1, char *kata2)
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
{
	int panjang=panjangkata(kata2);
	int i;
	for (i=0;i<panjang;++i)
	{
		kata1[i]=kata2[i];
	}
	kata1[panjang]='\0';
}

void bacakata (char *kata, char hingga)
{
	char c;
	int i=0;
	scanf("%c",&c);
	while (c!=hingga)
	{
		kata[i]=c;
		++i;
		scanf("%c",&c);
	}
	kata[i]='\0';
}

void bacakatafile (FILE *varfile, char *kata, char hingga)
{
	char c;
	int i=0;
	fscanf(varfile,"%c",&c);
	while (c!=hingga)
	{
		kata[i]=c;
		++i;
		fscanf(varfile,"%c",&c);
	}
	kata[i]='\0';
}

void tuliskata (char *kata)
{
	int panjang=panjangkata(kata);
	int i;
	for (i=0;i<panjang;++i)
	{
		printf("%c",kata[i]);
	}
}

void tuliskatafile (FILE *varfile, char*kata)
{
	int panjang=panjangkata(kata);
	int i;
	for (i=0;i<panjang;++i)
	{
		fprintf(varfile,"%c",kata[i]);
	}
}
