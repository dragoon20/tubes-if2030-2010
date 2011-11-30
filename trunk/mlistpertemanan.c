#include "listpertemanan.h"
#include "priorqueue.h"
#include "kata.h"
#include "boolean.h"
#include <stdio.h>
#include <stdlib.h>

#ifndef _Windows
 #if defined(_WIN32)
  #define _Win32
  #define _Windows
 #elif defined(WIN32)
  #define _Win32
  #define _Windows
 #elif defined(__WIN32__)
  #define _Win32
  #define _Windows
 #elif defined(__Win32__)
  #define _Win32
  #define _Windows
 #elif defined(_WINDOWS)
  #define _Windows
 #elif defined(__INTEL__) && defined(__MWERKS__)
 // Metrowerks CodeWarrior doesn't build anything other than Win32 on INTEL, no DOS
  #define _Windows
  #define _Win32
 #endif
#else
 #if defined __Win32__ || defined _WIN32
  #ifndef _Win32
   #define _Win32
   #define _Windows
  #endif
 #endif
#endif

#ifndef _MSDOS
 #ifdef _Windows
  #define _MSDOS
 #elif defined(MSDOS)
  #define _MSDOS
 #elif defined(__MSDOS__)
  #define _MSDOS
 #endif
#endif

#ifdef _Windows
 #ifndef STRICT
// some Windows headers define STRICT. In Visual C++ at least having it defined
// affects how static member signatures are mangled, so we define it up front  
  #define STRICT
  #define _Windows
 #endif
#endif


// if not a DOS machine by now, may be Mac or Unix
// cope with Metrowerks and Symantec (and MPW?)
#ifndef _MSDOS
 #ifndef _Macintosh
  #define _Unix
 #endif
#endif

const address Nil=NULL;
const addressf Nilf=NULL;
const addressPQ NilPQ=NULL;

int main()
{
	char perintahadmin[12][50];
	char perintahuser[8][50];
	char input[250];
	char input2[250];
	char input3[250];
	char s[50];
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
	copykata(perintahadmin[10],"clear");
	copykata(perintahadmin[11],"time");
	
	copykata(perintahuser[0],"birthday");
	copykata(perintahuser[1],"same");
	copykata(perintahuser[2],"notfriendyet");
	copykata(perintahuser[3],"friend");
	copykata(perintahuser[4],"unfriend");
	copykata(perintahuser[5],"updatedata");
	copykata(perintahuser[6],"close");
	copykata(perintahuser[7],"help");
	
	#ifdef _Windows
		system("cls");
	#endif

	#ifdef _Unix
		system("clear");
	#endif
	
	printf("\n");
	
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
		if (input[panjangkata(input)+1]=='#')
		{
			end=true;
		}
		
		//pengecekan input
		i=-1;
		cek=true;
		while ((i<=11)&&(cek))
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
							if (x!=NULL)
							{
								Load (&L, x);
								fclose(x);
							}
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
							int y=searchkata(input2,'@');
							cek=false;
							address user=First(L);
							if ((y!=-1)&&(y!=panjangkata(input2)-1))
							{
								while ((user!=Nil)&&(bandingkata(Info(user).email,input2)))
								{
									user=Next(user);
								}
								if (user!=Nil)
								{
									cek=true;
								}
							}
							
							if (cek)
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
												system("date /t > date.txt");
												tanggal now;
												File *x;
												x=fopen("date.txt","r");
												if (x!=NULL)
												{
													bacakatafile(x,s,' ',' ');
													fscanf(x,"%d/%d/%d",&now.bulan,&now.hari,&now.tahun);
													if (end)
													{
														// tanpa input kedua (7 hari)
													}
													else
													{
														bacakata(input3,'#','#');
														trim(input3,' ');
														trim(input3,'\n');
														end=true;
														if (!bandingkata(input3,""))
														{
															// tanpa input kedua (7 hari)
														}
														else
														{
															// dengan input kedua
															int hari=katatoint(input3);
															if ((hari>=-365)&&(hari<=365))
															{
															}
															else if (hari==-1000)
															{
																printf("Format masukan hari salah.\n");
															}
															else
															{
																addressf P=FList(user);
																printf("ID\t\t\tName\t\t\tBirthday\tHometown\tUniversity\tHighschool\n");
																while (P!=Nilf)
																{
																	tuliskata(Info(Friend(P)).email);
																	printf("\t");
																	tuliskata(Info(Friend(P)).nama);
																	printf("\t");
																	if (IsTeman(L,Info(Friend(P)),Info(user))==1)
																	{
																		printf("%2d-%2d-%4d\t",Info(Friend(P)).tgllahir.hari,Info(Friend(P)).tgllahir.bulan,Info(Friend(P)).tgllahir.tahun);
																	}
																	else
																	{
																		printf("XX-XX-XXXX\t");
																	}
																	tuliskata(Info(Friend(P)).kotaasal);
																	printf("\t");
																	tuliskata(Info(Friend(P)).universitas);
																	printf("\t\t");
																	tuliskata(Info(Friend(P)).smu);
																	printf("\n");
																}
															}
														}
													}
												}
												else
												{
													printf("Tidak dapat mengakses tanggal saat ini.");
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
														if (hometown) {
																infotype m,n;
																address p;
																addressf b;
																
																p = First(L);
																while (!bandingkata(input2,Info(p).email))
																	  {p = Next(p);}
																/* p = address user */
																b = First(L);
																printf("1st Friend\n");
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
																{ if ((IsTeman(L,Info(p),Info(b)) == 1) && (IsSame(Info(p),Info(b),1))){
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
																		}
																   b = Next(b);
																		}
																b = First(L);
																printf("\n2nd Friend\n");
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
																{ if ((IsTeman(L,Info(p),Info(b)) == 2) && (IsSame(Info(p),Info(b),1))){
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
																		}
																   b = Next(b);
																		}
																b = First(L);
																printf("\n3rd Friend\n");
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
																{ if ((IsTeman(L,Info(p),Info(b)) == 3) && (IsSame(Info(p),Info(b),1))){
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
																		}
																   b = Next(b);
																		}
															}

															else /* school */  {
																infotype m,n;
																address p;
																addressf b;
																
																p = First(L);
																while (!bandingkata(input2,Info(p).email))
																	  {p = Next(p);}
																/* p = address user */
																b = First(L);
																printf("1st Friend\n");
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
																{ if ((IsTeman(L,Info(p),Info(b)) == 1) && ((IsSame(Info(p),Info(b),2)) || (IsSame(Info(p),Info(b),3))) ){
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
																		}
																   b = Next(b);
																		}
																b = First(L);
																printf("\n2nd Friend\n");
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
																{ if ((IsTeman(L,Info(p),Info(b)) == 2) && ((IsSame(Info(p),Info(b),2)) || (IsSame(Info(p),Info(b),3)))){
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
																		}
																   b = Next(b);
																		}
																b = First(L);
																printf("\n3rd Friend\n");
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
																{ if ((IsTeman(L,Info(p),Info(b)) == 3) && ((IsSame(Info(p),Info(b),2)) || (IsSame(Info(p),Info(b),3)))){
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
																		}
																   b = Next(b);
																		}
															}
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
												
												 {
														infotype m,n;
														address p;
														addressf b;
														
														p = First(L);
														while (!bandingkata(input2,Info(p).email))
															  {p = Next(p);}
														/* p = address user */
														b = First(L);
														printf("\n2nd Friend\n");
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
														{ if (IsTeman(L,Info(p),Info(b)) == 2){
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
																}
														   b = Next(b);
																}
														b = First(L);
														printf("\n3rd Friend\n");
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
														{ if (IsTeman(L,Info(p),Info(b)) == 3) {
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
																}
														   b = Next(b);
																}
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
													while (bandingkata(input2,Info(p).email))
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
													while (b != Nilf)
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
														while (bandingkata(input2,Info(p).email))
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
														while (b != Nilf)
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
														while (bandingkata(input2,Info(p).email))
														{
															p = Next(p);
														}
														copykata (m.email, Info(p).email);
														copykata (n.email, input3);
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
														while (bandingkata(input2,Info(p).email))
														{
															p = Next(p);
														}
														copykata (m.email, Info(p).email);
														copykata (n.email, input3);
														b = FList(p);
														while ((!c)&&(b!=Nilf))
														{
															if (!bandingkata(input3,Info(Friend(b)).email))
															{
																c = true;
															}
															b = Next(b);
														}
														if (c)
														{
															DeleteFriend(&L, m, n);
															printf("Penghapusan hubungan friend dengan ");
															tuliskata(input3);
															printf(" sukses");
														}
														else
														{
															printf("User ");
															tuliskata(input3);
															printf(" bukan 1st friend anda.\n");
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
								printf("Format email yang dimasukkan salah atau tidak ada.\n");
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
						copykata(kata,input2);
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
								int i,j;
								infotype m;
								char hari[2];
								char bulan[2];
								char tahun[4];
								
										i=0;
										j=0;
										while (kata[i]!=' ') {
										m.email[i]=kata[i];
										i++;
										}
										m.email[i]='\0';
										i=i+2;
										j=0;
										while (kata[i]!='"') {
										m.nama[j]=kata[i];
										i++;
										j++;
										}
										m.nama[j]='\0';
										i=i+2;
										j=0;
										while (kata[i]!='-') {
										hari[j]=kata[i];
										i++;
										j++;
										}
										m.tgllahir.hari=katatoint(hari);
										i=i+2;
										j=0;
										while (kata[i]!='-') {
										bulan[j]=kata[i];
										i++;
										j++;
										}
										m.tgllahir.bulan=katatoint(bulan);
										i=i+2;
										j=0;
										while (kata[i]!=' ') {
										tahun[j]=kata[i];
										i++;
										j++;
										}
										m.tgllahir.tahun=katatoint(tahun);
										i=i+2;
										j=0;
										while (kata[i]!='"') {
										m.kotaasal[j]=kata[i];
										i++;
										j++;
										}
										m.kotaasal[j]='\0';
										i=i+2;
										if(kata[i]!='"')
											{
											m.universitas[0]='N';
											m.universitas[1]='I';
											m.universitas[2]='L';
											m.universitas[3]='\0';
											i=i+2;
											}
										else
											{
											i=i+1;	
											j=0;
											while (kata[i]!='"') {
											m.universitas[j]=kata[i];
											i++;
											j++;
											}
										}
										m.universitas[j]='\0';
										i=i+2;
										if(kata!='"')
											{
											m.smu[0]='N';
											m.smu[1]='I';
											m.smu[2]='L';
											m.smu[3]='\0';
											i=i+2;
											}
										else
											{
											i=i+1;	
											j=0;
											while (kata[i]!='"') {
											m.smu[j]=kata[i];
											i++;
											j++;
											}
										}
										m.smu[j]='\0';
										Adduser(&L,m);
										printf("Penambahan user dengan id ");
										tuliskata(m.email);
										printf(" sukses.");
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
									bacakata(a.nama,'#','#');
									if (bandingkata(a.nama,""))
									{
										copykata(b.nama,a.nama);
									}
									printf("\nTanggal Lahir (dd-mm-yyyy dan blank jika tetap) :");
									printf("\nKota Asal (blank jika tetap) :");
									bacakata(a.kotaasal,'#','#');
									if (bandingkata(a.kotaasal,""))
									{
										copykata(b.kotaasal,a.kotaasal);
									}
									printf("\nUniversitas (blank jika tetap) :");
									bacakata(a.universitas,'#','#');
									if (bandingkata(a.universitas,""))
									{
										copykata(b.universitas,a.universitas);
									}
									printf("\nSMU (blank jika tetap) :");
									bacakata(a.smu,'#','#');
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
			//exit
			case 8:
				{
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
			//clear
			case 10:
				{
					if (!end)
					{
						bacakata(input2,'#','#');
						end=true;
					}
					#ifdef _Windows
						system("cls");
					#endif
					
					#ifdef _Unix
						system("clear");
					#endif
					break;
				}
			//time
			case 11:
				{
					if (!end)
					{
						bacakata(input2,'#','#');
						end=true;
					}
					system("date /t > date.txt");
					system("time /t > time.txt");
					FILE *x;
					int bulan=0, hari=0, tahun=0, jam, menit;
					
					x=fopen("time.txt","r");
					if (x!=NULL)
					{	
						fscanf(x,"%d:%d",&jam,&menit);
						bacakatafile(x,s,'\n','\n');
						fclose(x);
						printf("\n - %02d:%02d",jam,menit);
						tuliskata(s);
						printf("   ");
					}
					else
					{
						printf("Waktu gagal ditampilkan.\n");
					}
					
					x=fopen("date.txt","r");
					if (x!=NULL)
					{	
						bacakatafile(x,s,' ',' ');
						fscanf(x,"%d/%d/%d",&bulan,&hari,&tahun);
						fclose(x);
						tuliskata(s);
						printf(" %02d-%02d-%04d\n",hari,bulan,tahun);
					}
					else
					{
						printf("Tanggal gagal ditampilkan.\n");
					}

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
