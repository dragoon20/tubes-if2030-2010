#ifndef __kata__
#define __kata__

#include "boolean.h"

int panjangkata (char *kata);

int bandingkata (char *kata1, char *kata2);

void copykata (char *kata1, char *kata2);

void bacakata (char *kata, char hingga);

void bacakatafile (FILE *varfile, char *kata, char hingga);

void tuliskata (char *kata);

void tuliskatafile (FILE *varfile, char*kata);

#endif
