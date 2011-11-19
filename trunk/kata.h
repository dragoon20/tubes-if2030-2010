#ifndef __kata__
#define __kata__

#include "boolean.h"
#include <stdlib.h>
#include <stdio.h>

int panjangkata (char *kata);
/*Is: kata terdefinisi
Fs:	Jumlah sebuah kata*/

int bandingkata (char *kata1, char *kata2); 
/*I.S. 2 kata yang ingin dibandingkan
F.S. jika kata1 > dari kata2 maka menghasilkan 1 (a>b)
	jika kata1<kata2 menghasilkan -1(b<a)
	jika kedua kata sama menghasilkan 0*/
void copykata (char *kata1, char *kata2);
/*I.S. kata2 terdefinisi, kata1 sembarang
F.S. Kata2 disalin ke kata1*/
void bacakata (char *kata, char hingga);
/*I.S. kata terdefinisi
F.S. kata dibaca sampai bertemu hingga*/
void tuliskata (char *kata);
/*I.S. kata terdefinisi
F.S. menulis kata tersebut*/
void bacakatafile (FILE *varfile, char *kata, char hingga);
/*I.S. varfile terdefinisi, kata ter*/

#endif
