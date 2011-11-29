#include "listpertemanan.h"
#include "priorqueue.h"
#include "kata.h"
#include "boolean.h"
#include <stdio.h>

const address Nil=NULL;
const addressf Nilf=NULL;
const addressPQ NilPQ=NULL;

int main()
{
	char perintahadmin[10][50];
	char perintahuser[8][50];
	char input[250];
	char input2[250];
	char input3[250];
	char kata[250];
	char temp;
	int perintah,i;
	bool cek,end;
	List L;
	
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
						printf("- namafile\tSebuah file yang berisi data user dan hubungan pertemanannya.\n");
					}
					else
					{
						bacakata(input2,'#','#');
						trim(input2,' ');
						trim(input2,'\n');
						if (!bandingkata(input2,""))
						{
							printf("Load sebuah file yang berisi data user dan hubungan pertemanannya.\n\n");
							printf("load {namafile}\n\n");
							printf("- namafile\tSebuah file yang berisi data user dan hubungan pertemanannya.\n");
							end=true;
						}
						else
						{
							//di sini bagian loadnya
							copykata(kata,input2);
							FILE *x;
							x=fopen(kata,"r");
							Load (&L, x);
							fclose(x);
							printf("Loading file %s sukses.\n",kata);
						}
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
						printf("- user-id\tEmail yang digunakan sebagai user-id yang ingin digunakan.\n");
					}
					else
					{
						bacakata(input2,'#','#');
						trim(input2,' ');
						trim(input2,'\n');
						if (!bandingkata(input2,""))
						{
							printf("Login sebagai user.\n\n");
							printf("user {user-id}\n\n");
							printf("- user-id\tEmail yang digunakan sebagai user-id yang ingin digunakan.\n");
						}
						else
						{
							// validasi email
							
							if (1)
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
													bacakata(input3,'#','#');
													trim(input3,' ');
													trim(input3,'\n');
													if (!bandingkata(input3,""))
													{
														printf("Menampilkan list 1st friend, 2nd friend, dan 3rd friend dari user yang berasal dari sekolah atau asal daerah yang sama.\n\n");
														printf("same [school|hometown]\n\n");
														end=true;
													}
													else
													{
														//di sini bagian samenya
													}
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
												infotype m,n;
												address p;
												addressf b;
												if (end)
												{
													// sudah sampai #
													p = First(L);
													while (!bandingkata(input2,Info(p).email))
													{
														p = Next(p);
													}
													b = FList(p);
													printf("ID");
													printf("                ");
													printf("Name");
													printf("                ");
													printf("Birthday");
													printf("                ");
													printf("Hometown");
													printf("                ");
													printf("University");
													printf("                ");
													printf("Highschool");
													printf("\n");
													while (b != Nil)
													{
														tuliskata(Info(Friend(b)).email);
														printf("                ");
														tuliskata(Info(Friend(b)).nama);
														printf("                ");
														printf("%d-%d-%d",Info(Friend(b)).tgllahir.hari,Info(Friend(b)).tgllahir.bulan,Info(Friend(b)).tgllahir.tahun);
														printf("                ");
														tuliskata(Info(Friend(b)).kotaasal);
														printf("                ");
														tuliskata(Info(Friend(b)).universitas);
														printf("                ");
														tuliskata(Info(Friend(b)).smu);
														printf("\n");
														b = Next(b);
													}
												}
												else
												{
													if (!bandingkata(input3,""))
													{
														// sudah sampai # juga
														p = First(L);
														while (!bandingkata(input2,Info(p).email))
														{
															p = Next(p);
														}
														b = FList(p);
														printf("ID");
														printf("                ");
														printf("Name");
														printf("                ");
														printf("Birthday");
														printf("                ");
														printf("Hometown");
														printf("                ");
														printf("University");
														printf("                ");
														printf("Highschool");
														printf("\n");
														while (b != Nil)
														{
															tuliskata(Info(Friend(b)).email);
															printf("                ");
															tuliskata(Info(Friend(b)).nama);
															printf("                ");
															printf("%d-%d-%d",Info(Friend(b)).tgllahir.hari,Info(Friend(b)).tgllahir.bulan,Info(Friend(b)).tgllahir.tahun);
															printf("                ");
															tuliskata(Info(Friend(b)).kotaasal);
															printf("                ");
															tuliskata(Info(Friend(b)).universitas);
															printf("                ");
															tuliskata(Info(Friend(b)).smu);
															printf("\n");
															b = Next(b);
														}
														end=true;
													}
													else
													{
														p = First(L);
														while (!bandingkata(input2,Info(p).email))
														{
															p = Next(p);
														}
														copykata (&m.email, &Info(p).email);
														bacakata(input3,'#','#');
														trim(input3,' ');
														trim(input3,'\n');
														copykata (&n.email, &input3);
														AddFriend (&L, m, n);
														tuliskata(input2);
														printf(">> ");
														printf("friend ");
														tuliskata(input3);
														printf("Penambahan hubungan friend sukses");
													}
												}
												break;
											}
										//unfriend
										case 4:
											{
												infotype m,n;
												address p;
												addressf b;
												bool c;
												if (end)
												{
													// sudah sampai #
													printf("Mendelete 1st friend yang memiliki id tertentu.\n\n");
													printf("unfriend [<user-id>] \n\n");
												}
												else
												{
													bacakata(input3,'#','#');
													trim(input3,' ');
													trim(input3,'\n');
													if (!bandingkata(input3,""))
													{
														// sudah sampai # juga
														printf("Mendelete 1st friend yang memiliki id tertentu.\n\n");
														printf("unfriend [<user-id>] \n\n");
														end=true;
													}
													else
													{
														p = First(L);
														c = false;
														while (!bandingkata(input2,Info(p).email))
														{
															p = Next(p);
														}
														copykata (&m.email, &Info(p).email);
														bacakata(input3,'#','#');
														trim(input3,' ');
														trim(input3,'\n');
														copykata (&n.email, &input3);
														b = FList(p);
														while ((!c)&&(b!=Nil))
														{
															if (bandingkata(input3,Info(Friend(b)).email))
															{
																c = true;
															}
															b = Next(b);
														}
														if (c)
														{
															DeleteFriend(&L, m, n);
															tuliskata(input2);
															printf(">> ");
															printf("unfriend ");
															tuliskata(input3);
															printf("Penghapusan hubungan friend dengan ");
															tuliskata(input3);
															printf(" sukses");
														}
														else
														{
															printf("User bukan 1st friend anda");
														}
														
													}
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
					break;
				}
			//adduser
			case 2:
				{
					if (end)
					{
						// sudah sampai #
						printf("Menambah user.\n\n");
						printf("adduser {email | nama | tgl-lahir | kota-asal | universitas | SMU}\n\n");
						printf("- email\t\tEmail dari user yang akan digunakan sebagai user-id.\n");
						printf("- nama\t\tNama dari user.\n");
						printf("- tgl-lahir\tTanggal lahir dari user (hari-bulan-tahun).\n");
						printf("- kota-asal\tKota asal dari user.\n");
						printf("- universitas\tUniversitas tempat user kuliah.\n");
						printf("- SMU\t\tAsal SMU user.\n");
					}
					else
					{
						bacakata(input2,'#','#');
						trim(input2,' ');
						trim(input2,'\n');
						if (!bandingkata(input2,""))
						{
							// sudah sampai # juga
							printf("Menambah user.\n\n");
							printf("adduser {email | nama | tgl-lahir | kota-asal | universitas | SMU}\n\n");
							printf("- email\t\tEmail dari user yang akan digunakan sebagai user-id.\n");
							printf("- nama\t\tNama dari user.\n");
							printf("- tgl-lahir\tTanggal lahir dari user (hari-bulan-tahun).\n");
							printf("- kota-asal\tKota asal dari user.\n");
							printf("- universitas\tUniversitas tempat user kuliah.\n");
							printf("- SMU\t\tAsal SMU user.\n");
							end=true;
						}
						else
						{
							// addusernya di sini
						}
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
						printf("- user-id\tEmail yang digunakan sebagai user-id yang ingin digunakan.\n");
					}
					else
					{	
						address p;
						infotype a,b;
						bacakata(a.email,'#','#');
						trim(a.email,' ');
						trim(a.email,'\n');
						lowcase(a.email);
						if (!bandingkata(a.email,""))
						{
							// sudah sampai #
							printf("Mengubah data user.\n\n");
							printf("modifyuser {user-id}\n\n");
							printf("- user-id\tEmail yang digunakan sebagai user-id yang ingin digunakan.\n");
						}
						else
						{	
							copykata(b.email,a.email);
							p = First(L);
							while (bandingkata(b.email,Info(p).email))
								{
										p = Next(p); //mencari address yang ingin dimodify
								}
							if (p != Nil)
							{
									printf("Nama Lengkap (blank jika tetap) :");
									bacakata(a.nama,"#","#");
									if (bandingkata(a.nama,""))
									{
										copykata(b.nama,a.nama);
									}
									printf("\nTanggal Lahir (dd-mm-yyyy dan blank jika tetap) :");
									printf("\nKota Asal (blank jika tetap) :");
									bacakata(a.kotaasal,"#","#");
									if (bandingkata(a.kotaasal,""))
									{
										copykata(b.kotaasal,a.kotaasal);
									}
									printf("\nUniversitas (blank jika tetap) :");
									bacakata(a.universitas,"#","#");
									if (bandingkata(a.universitas,""))
									{
										copykata(b.universitas,a.universitas);
									}
									printf("\nSMU (blank jika tetap) :");
									bacakata(a.smu,"#","#");
									if (bandingkata(a.smu,""))
									{
										copykata(b.smu,a.smu);
									}
									ModifyUser(&L,b);
									p = First(L);
									while (bandingkata(b.email,Info(p).email))
										{
												p = Next(p); //mencari address baru yang telah dimodify
										}
									printf("\nPerubahan data pribadi ");
									tuliskata(Info(p).email);
									printf(" sukses");
									printf("Nama Lengkap (blank jika tetap) : ");
									tuliskata(Info(p).nama);;
									printf("\nTanggal Lahir (dd-mm-yyyy dan blank jika tetap) : ");
									printf("\nKota Asal (blank jika tetap) : ");
									tuliskata(Info(p).kotaasal);
									printf("\nUniversitas (blank jika tetap) : ");
									tuliskata(Info(p).universitas);
									printf("\nSMU (blank jika tetap) : ");
									tuliskata(Info(p).smu);
							}
							else
							{
								printf("Tidak ada ID user dengan email ");
								tuliskata(b.email);
								printf(".");
							}
						}
						
					
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
						printf("- user-id\tEmail yang digunakan sebagai user-id yang ingin digunakan.\n");
					}
					else
					{
						address p;
						infotype a,b;
						bacakata(a.email,'#','#');
						trim(a.email,' ');
						trim(a.email,'\n');
						lowcase(a.email);
						if (!bandingkata(a.email,""))
						{
							// sudah sampai #
							printf("Menghapus user.\n\n");
							printf("deluser {user-id}\n\n");
							printf("- user-id\tEmail yang digunakan sebagai user-id yang ingin digunakan.\n");
						}
						else
						{
							p = First(L);
							while (bandingkata(a.email,Info(p).email))
								{
										p = Next(p); //mencari address yang ingin dimodify
								}
							if (p != Nil)
							{
								RemoveUser(&L,a);
								printf("\nUser dengan alamat email ");
								tuliskata(a.email);
								printf(" telah berhasil dihapus.");
							}
							else
							{
								printf("Tidak ada ID user dengan email ");
								tuliskata(a.email);
								printf(".");
							}
							
						}
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
						FILE *x;
						x=fopen(kata,"r");
						Load (&L, x);
						fclose(x);
						printf("Reload data sesuai %s sukses.\n",kata);
					}
					else
					{
						bacakata(input2,'#','#');
						trim(input2,' ');
						trim(input2,'\n');
						if (!bandingkata(input2,""))
						{
							FILE *x;
							x=fopen(kata,"r");
							Load (&L, x);
							fclose(x);
							printf("Reload data sesuai %s sukses.\n",kata);
							end=true;
						}
						else
						{
							printf("Format penulisan reload tidak membutuhkan parameter tambahan.\n");
						}
					}
					break;
				}
			//save
			case 7:
				{
					if (end)
					{
						// sudah sampai #
						FILE *x;
						x=fopen(kata,"w");
						Save (L, x);
						fclose(x);
						printf("Save data sesuai %s sukses.",kata);
					}
					else
					{
						bacakata(input2,'#','#');
						trim(input2,' ');
						trim(input2,'\n');
						if (!bandingkata(input2,""))
						{
							FILE *x;
							x=fopen(kata,"w");
							Save (L, x);
							fclose(x);
							printf("Save data sesuai %s sukses.",kata);
						}
						else
						{
							copykata(kata,input2);
							FILE *x;
							x=fopen(kata,"w");
							Save (L, x);
							fclose(x);
							printf("Save data sesuai %s sukses.",kata);
						}
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
					printf("\nPerintah-perintah yang dapat digunakan:\n");
					printf("- load\t\tMembaca data user dan pertemanan dari file.\n");
					printf("- user\t\tLogin sebagai user.\n");
					printf("- adduser\tMenambah user.\n");
					printf("- modifyuser\tMengubah data user.\n");
					printf("- deluser\tMenghapus user.\n");
					printf("- list\t\tMenampilkan list dari data user tertentu.\n");
					printf("- reload\tMembaca ulang data.\n");
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
	} while (perintah!=8);
	if (!end)
	{
		bacakata(input,'#','#');
	}
	printf("Program selesai.\n");
	return 0;
}
