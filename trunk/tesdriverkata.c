#include "kata.h"
#include <stdio.h>

int main()
{
	char kata1[50],kata2[50];
	char kata[100];
	FILE *x;
	
	x=fopen("testul.txt","w");
	tuliskatafile(x,"apa#");
	fclose(x);
	x=fopen("testul.txt","r");
	bacakatafile(x,kata,'#','#');
	fclose(x);
	tuliskata(kata);
	printf("\n");
	bacakata(kata1,' ','\n');
	tuliskata(kata1);
	printf("\n");
	copykata(kata2,"apa ");
	trim(kata2,' ');
	printf("%d\n",searchkata(kata,'a'));
	copykata(kata2,"120");
	printf("%d\n",katatoint(kata2));
	tuliskata(kata1);
	printf("\n");
	tuliskata(kata2);
	printf("\n");
	if (bandingkata(kata1,kata2))
	{
		printf("%d\n",panjangkata(kata1));
	}
	return 0;
}
