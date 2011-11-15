#include "listpertemanan.h"
#include "kata.h"
#include "boolean.h"
#include <stdio.h>

const address Nil=NULL;

int main()
{
	char perintahadmin[10][50];
	char perintahuser[10][50];
	char input[50];
	char user[50];
	char temp;
	int perintah,i;
	bool cek;
	
	copykata(perintahadmin[0],"load");
	copykata(perintahadmin[1],"user");
	copykata(perintahadmin[2],"adduser");
	copykata(perintahadmin[3],"modifyuser");
	copykata(perintahadmin[4],"deluser");
	copykata(perintahadmin[5],"list");
	copykata(perintahadmin[6],"reload");
	copykata(perintahadmin[7],"save");
	copykata(perintahadmin[8],"exit");
	
	copykata(perintahuser[0],"birthday");
	copykata(perintahuser[1],"same");
	copykata(perintahuser[2],"notfriendyet");
	copykata(perintahuser[3],"friend");
	copykata(perintahuser[4],"unfriend");
	copykata(perintahuser[5],"updatedata");
	copykata(perintahuser[6],"close");
	
	do
	{
		printf("> ");
		perintah=-1;
		bacakata(input,' ');
		i=-1;
		cek=true;
		while ((i<=8)&&(cek))
		{
			++i;
			if (bandingkata(input,perintahadmin[i]))
			{
				cek=false;
			}
		}
		if (!cek)
		{
			perintah=i;
		}
		switch (perintah)
		{
			//load
			case 0:
				{
					break;
				}
			//user
			case 1:
				{
					bacakata(user,' ');
					scanf("%c",&temp);
					cek=(temp=='#')
					scanf("%c",&temp);
					if (cek)
					{
						do
						{
							tuliskata(user);
							printf(">> ");
							bacakata(input,' ');
							i=-1;
							cek=true;
							while ((i<=8)&&(cek))
							{
								++i;
								if (bandingkata(input,perintahuser[i]))
								{
									cek=false;
								}
							}
							if (!cek)
							{
								perintah=i;
							}
							switch (perintah)
							{
								//brithday
								case 0:
									{
										break;
									}
								//same
								case 1:
									{
										break;
									}
								//notfriendyet
								case 2:
									{
										break;
									}
								//friend
								case 3:
									{
										break;
									}
								//unfriend
								case 4:
									{
										break;
									}
								//updatedata
								case 5:
									{
										break;
									}
								//close
								case 6:
									{
										break;
									}
								//tidak termasuk dalam perintah
								default:
									{
										printf("Perintah ");
										tuliskata(input);
										printf("tidak ada.\n");
										break;
									}
							}
						} while (perintah!=6);
						perintah=1;
						break;
					}
					else
					{
						perintah=-1;
					}
				}
			//adduser
			case 2:
				{
					break;
				}
			//modifyuser
			case 3:
				{
					break;
				}
			//deluser
			case 4:
				{
					break;
				}
			//list
			case 5:
				{
					break;
				}
			//reload
			case 6:
				{
					break;
				}
			//save
			case 7:
				{
					break;
				}
			//exit
			case 8:
				{
					printf("Program selesai.\n");
					break;
				}
			//tidak termasuk dalam perintah
			default:
				{
					printf("Perintah ");
					tuliskata(input);
					printf("tidak ada.\n");
					break;
				}
		}
	} while (perintah!=8)
	
	return 0;
}
