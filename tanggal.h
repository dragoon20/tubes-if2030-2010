#ifndef __TANGGAL__
#define __TANGGAL__

#include "boolean.h"
/*Deklarasi tanggal*/
typedef struct
{
	int hari;
	int bulan;
	int tahun;
} tanggal;

tanggal buattanggal (int hari, int bulan, int tahun);

int bandingtanggal (tanggal t1, tanggal t2);

bool IsKabisat (int tahun);

int selisihtanggal (tanggal t1, tanggal t2, int param);

#endif
