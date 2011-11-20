#include "listpertemanan.h"
#include "kata.h"
#include "boolean.h"
#include <stdio.h>

const address Nil=NULL;

int main()
{
	char perintahadmin[9][50];
	char perintahuser[7][50];
	char input[50];
	char input2[50];
	char input3[50];
	char temp;
	int perintah,i;
	bool cek,end;
	
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
		//inisialisasi
		end=false;
		perintah=-1;
		printf("> ");
		
		//baca input dan ditrim
		bacakata(input,' ','#');
		trim(input,' ');
		trim(input,'\n');
		if (input[panjangkata(input)+1]='#')
		{
			end=true;
		}
		
		//pengecekan input
		i=-1;
		cek=true;
		while ((i<=8)&&(cek))
		{
			++i;
			if (!bandingkata(input,perintahadmin[i]))
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
					if (end)
					{
						//tanpa nama file sudah #
						printf("Nama file belum dimasukkan.\n");
					}
					else
					{
						
					}
					break;
				}
			//user
			case 1:
				{
					if (end)
					{
						//tanpa email user sudah #
						printf("Email user belum dimasukkan.\n");
					}
					else
					{
						bacakata(input2,'#','#');
						/*scanf("%c",&temp);
						cek=(temp=='#');
						scanf("%c",&temp);*/
						
						// validasi email
						
						if ()
						{
							// email benar
							do
							{
								// inisiasi
								end=false;
								tuliskata(input2);
								printf(">> ");
								
								// baca input dan ditrim
								bacakata(input,' ','#');
								trim(input,' ');
								trim(input,'\n');
								if (input[panjangkata(input)+1]='#')
								{
									end=true;
								}
								
								// pengecekan input
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
									//birthday
									case 0:
										{
											if (end)
											{
												// tanpa input kedua (7 hari)
											}
											else
											{
												// dengan input kedua
											}
											break;
										}
									//same
									case 1:
										{
											if (end)
											{
												//tanpa nama file sudah #
												printf("Parameter yang ingin dicari belum dimasukkan.\n");
											}
											else
											{
												
											}
											break;
										}
									//notfriendyet
									case 2:
										{
											// untuk membaca #nya juga
											if (!end)
											{
												bacakata(input3,'#','#');
											}
											
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
							//close
							perintah=1;
							break;
						}
						else
						{
							// email salah
							printf("Format email yang dimasukkan salah.\n");
						}
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
			//tidak termasuk dalam perintah
			default:
				{
					if (!end)
					{
						bacakata(input2,'#','#');
					}
					printf("Perintah \"");
					tuliskata(input);
					printf("\" tidak ada.\n");
					break;
				}
		}
	} while (perintah!=8)
	printf("Program selesai.\n");
	return 0;
}
