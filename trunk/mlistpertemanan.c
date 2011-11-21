#include "listpertemanan.h"
#include "kata.h"
#include "boolean.h"
#include <stdio.h>

const address Nil=NULL;

int main()
{
	char perintahadmin[10][50];
	char perintahuser[8][50];
	char input[250];
	char input2[250];
	char input3[250];
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
	copykata(perintahadmin[9],"help");
	
	copykata(perintahuser[0],"birthday");
	copykata(perintahuser[1],"same");
	copykata(perintahuser[2],"notfriendyet");
	copykata(perintahuser[3],"friend");
	copykata(perintahuser[4],"unfriend");
	copykata(perintahuser[5],"updatedata");
	copykata(perintahuser[6],"close");
	copykata(perintahuser[7],"help");
	
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
		lowcase(input);
		if (input[panjangkata(input)+1]='#')
		{
			end=true;
		}
		
		//pengecekan input
		i=-1;
		cek=true;
		while ((i<=9)&&(cek))
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
						printf("Load sebuah file yang berisi data user dan hubungan pertemanannya.\n\n");
						printf("load {namafile}\n\n");
						printf("\tnamafile\tSebuah file yang berisi data user dan hubungan pertemanannya.\n");
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
						printf("Login sebagai user.\n\n");
						printf("user {user-id}\n\n");
						printf("\tuser-id\tEmail yang digunakan sebagai user-id yang ingin digunakan.\n");
					}
					else
					{
						bacakata(input2,'#','#');
						lowcase(input2);
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
								while ((i<=7)&&(cek))
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
												printf("Menampilkan list 1st friend, 2nd friend, dan 3rd friend dari user yang berasal dari sekolah atau asal daerah yang sama.\n\n");
												printf("same [school|hometown]\n\n");
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
												end=true;
											}
											
											break;
										}
									//friend
									case 3:
										{
											if (end)
											{
												// sudah sampai #
											}
											else
											{
												
											}
											break;
										}
									//unfriend
									case 4:
										{
											if (end)
											{
												// sudah sampai #
											}
											else
											{
											}
											break;
										}
									//updatedata
									case 5:
										{
											// untuk membaca #nya juga
											if (!end)
											{
												bacakata(input3,'#','#');
												end=true;
											}
											
											break;
										}
									case 7:
										{
											if (!end)
											{
												bacakata(input3,'#','#');
												end=true;
											}
											printf("Perintah-perintah yang dapat digunakan:\n");
											printf("-birthday\t\tMengecek ulang tahun teman yang dekat dengan hari ini.\n");
											printf("-same\t\tMenampilkan list teman-teman yang memiliki kesamaan asal sekolah atau universitas.\n");
											printf("-notfriendyet\t\tMenampilkan list teman dari teman kita yang masih belum menjadi teman kita.\n");
											printf("-friend\t\tMenampilkan list teman kita atau berteman dengan suatu user-id.\n");
											printf("-unfriend\t\tMenghilangkan hubungan pertemanan dengan suatu user-id.\n");
											printf("-updatedata\t\tMengubah data diri.\n");
											printf("-close\t\tKeluar dari menu user.\n\n");
											printf("Setiap perintah diakhiri dengan '#'.\n");
											break;
										}
									//tidak termasuk dalam perintah
									default:
										{
											printf("Perintah ");
											tuliskata(input);
											printf("tidak ada.\n\n");
											printf("Ketik \"help#\" untuk bantuan.\n");
											
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
					if (end)
					{
						// sudah sampai #
						printf("Menambah user.\n\n");
						printf("adduser {email | nama | tgl-lahir | kota-asal | universitas | SMU}\n\n");
						printf("\temail\tEmail dari user yang akan digunakan sebagai user-id.\n");
						printf("\tnama\tNama dari user.\n");
						printf("\ttgl-lahir\tTanggal lahir dari user (hari-bulan-tahun).\n");
						printf("\tkota-asal\tKota asal dari user.\n");
						printf("\tuniversitas\tUniversitas tempat user kuliah.\n");
						printf("\tSMU\tAsal SMU user.\n");
					}
					else
					{
						
					}
					break;
				}
			//modifyuser
			case 3:
				{
					if (end)
					{
						// sudah sampai #
						printf("Mengubah data user.\n\n");
						printf("modifyuser {user-id}\n\n");
						printf("\tuser-id\tEmail yang digunakan sebagai user-id yang ingin digunakan.\n");
					}
					else
					{
					
					}
					break;
				}
			//deluser
			case 4:
				{
					if (end)
					{
						// sudah sampai #
						printf("Menghapus user.\n\n");
						printf("deluser {user-id}\n\n");
						printf("\tuser-id\tEmail yang digunakan sebagai user-id yang ingin digunakan.\n");
					}
					else
					{
					
					}
					break;
				}
			//list
			case 5:
				{
					if (end)
					{
						// sudah sampai #
					}
					else
					{
					}
					break;
				}
			//reload
			case 6:
				{
					if (end)
					{
						// sudah sampai #
					}
					else
					{
						
					}
					break;
				}
			//save
			case 7:
				{
					if (end)
					{
						// sudah sampai #
					}
					else
					{
					
					}
					break;
				}
			//help
			case 9:
				{
					if (!end)
					{
						bacakata(input2,'#','#');
						end=true;
					}
					printf("Perintah-perintah yang dapat digunakan:\n");
					printf("- load\t\tMembaca data user dan pertemanan dari file.\n");
					printf("- user\t\tLogin sebagai user.\n");
					printf("- adduser\t\tMenambah user.\n");
					printf("- modifyuser\t\tMengubah data user.\n");
					printf("- deluser\t\tMenghapus user.\n");
					printf("- list\t\t\n");
					printf("- reload\t\tMembaca ulang data.\n");
					printf("- save\t\tMenyimpan data yang ada ke dalam file.\n");
					printf("- exit\t\tKeluar dari program.\n\n");
					printf("Setiap perintah diakhiri dengan '#'.\n");
					break;
				}
			//tidak termasuk dalam perintah
			default:
				{
					if (!end)
					{
						bacakata(input2,'#','#');
						end=true;
					}
					printf("Perintah \"");
					tuliskata(input);
					printf("\" tidak ada.\n\n");
					printf("Ketik \"help#\" untuk bantuan.\n");
					break;
				}
		}
		printf("\n");
	} while (perintah!=8)
	if (!end)
	{
		bacakata(input,'#','#');
	}
	printf("Program selesai.\n");
	return 0;
}
