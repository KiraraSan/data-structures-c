#include "header.h"
#include "headerLinkedList.h"


int main(int argc, char *argv[]) {
	
	Multilist l;
	List list;
	address temp;
	AddressParent tempParent;
	AddressChild tempChild;
	createEmpty(&l);
	createEmptyList(&list);
	
	int menu, submenu, pil;
	string username, password;
	
	string nama, tanggalBergabung;
	int id;
	
	string jenisHewan, jenisKelamin, tanggalLahir, diagnosis, obat, tanggalPeriksa;
	int idPeriksa, idHewan;
	
	do{
		system("cls");
		printf("\n\t\t==============================");
		printf("\n\t\t||                          ||");
		printf("\n\t\t|| KLINIK HEWAN CINTA SATWA ||");
		printf("\n\t\t||                          ||");
		printf("\n\t\t==============================\n");
		
		printf("\n\t\t\t    LOGIN:\n");
		printf("\t\t[1] ADMIN\n");
		printf("\t\t[2] Dokter\n");
		printf("\t\t[0] Keluar\n");
		printf("\t\t>>> "); scanf("%d", &menu);
		
		switch(menu){
			
			default:
				printf("\n\n\n\t\t[!] Menu Tidak Tersedia");
				break;
				
			case 0:
				printf("\n\n\n\t\t[!] Keluar Sistem");
				break;
				
			case 1:
				printf("\n\n\t\t[+] Username: "); fflush(stdin); gets(username);
				printf("\t\t[+] Password: "); fflush(stdin); gets(password);
				
				if(strcmpi(username, "admincintasatwa") != 0 || strcmp(password, "admincintasatwa") != 0){
					printf("\n\n\n\t\t[!] Username/Password Salah");
					break;
				}else{
					printf("\n\n\n\t\t[*] Berhasil Login Sebagai Admin");
					getch();
				}
				
				do{
					system("cls");
					printf("\n\t\t==============================");
					printf("\n\t\t||                          ||");
					printf("\n\t\t|| KLINIK HEWAN CINTA SATWA ||");
					printf("\n\t\t||                          ||");
					printf("\n\t\t==============================\n");
					printf("\t\t\t    ADMIN\n");
					
					printf("\n\t\t[1] Kelola Data Dokter");
					printf("\n\t\t[2] Pendaftaran Periksa Hewan");
					printf("\n\t\t[3] Hapus Data Hewan");
					printf("\n\t\t[4] Tampilkan Laporan");
					printf("\n\t\t[0] Logout");
					printf("\n\t\t>>> "); scanf("%d", &submenu);
					
					switch(submenu){
						
						default:
							printf("\n\n\n\t\t[!] Menu Tidak Tersedia");
							getch();
							break;
							
						case 0:
							printf("\n\n\n\t\t[!] LOGOUT");
							break;
							
						case 1:
							printf("\n\t\t\t--- Kelola Data Dokter ---");
							printf("\n\t\t\t[1] Tambah Data Dokter");
							printf("\n\t\t\t[2] Tampil Data Dokter");
							printf("\n\t\t\t[3] Cari Data Dokter");
							printf("\n\t\t\t[4] Ubah Data Dokter");
							printf("\n\t\t\t[5] Hapus Data Dokter");
							printf("\n\t\t\t>>> "); scanf("%d", &pil);
							
							
							switch(pil){
								
								default:
									printf("\n\n\n\t\t\t[!] Pilihan Tidak Tersedia");
									getch();
									continue;
									
								case 1:
									printf("\n\t\t\t--- Tambah Data Dokter ---\n");
									do{
										fflush(stdin);
										id = 0;
										printf("\n\t\t\t[+] ID Dokter		: "); scanf("%d", &id);
										if(id <= 0 || !isParentUnik(l,  id))
										printf("\t\t\t[!] ID Harus Unik dan Harus Angka > 0\n");
										else
										break;
									}while(true);
									do{
										printf("\t\t\t[+] Nama Dokter		: "); fflush(stdin); gets(nama);
										if(strlen(nama)<=0)
										printf("\t\t\t[!] Nama Dokter Tidak Boleh Kosong\n\n");
										else
										break;
									}while(true);
									do{
										printf("\t\t\t[+] Tanggal Bergabung [DD-MM-YYYY] : "); fflush(stdin); gets(tanggalBergabung);
										if(strlen(tanggalBergabung) != 10 || tanggalBergabung[2] != '-' || tanggalBergabung[5] != '-')
										printf("\t\t\t[!] Tanggal Tidak Sesuai\n\n");
										else
										break;
									}while(true);
									do{
										printf("\t\t\t[+] Username		: "); fflush(stdin); gets(username);
										if(strlen(username)<=0 || !isUsernameUnik(l, username))
										printf("\t\t\t[!] Username Harus Unik dan Tidak Boleh Kosong\n\n");
										else
										break;
									}while(true);
									do{
										printf("\t\t\t[+] Password		: "); fflush(stdin); gets(password);
										if(strlen(password)<=0)
										printf("\t\t\t[!] Password Tidak Boleh Kosong\n\n");
										else
										break;
									}while(true);
									
									insertLastParent(&l, makeDataParent(username, password, id, nama, tanggalBergabung));
									printf("\n\n\n\t\t\t[*] Berhasil Tambah Data Dokter");
									getch();
									continue;
									
								case 2:
									printf("\n\t\t\t--- Tampil Data Dokter ---\n");
									if(!isEmpty(l)){
										printAllParent(l);
									}else{
										printf("\n\n\n\t\t\t[!] Data Dokter Masih Kosong");
									}
									getch();
									continue;
									
								case 3:
									if(!isEmpty(l)){
										printf("\n\t\t\t--- Cari Data Dokter ---\n");
										printf("\n\t\t\t[+] Cari ID Dokter	: "); scanf("%d", &id);
										tempParent = findParent(l, id);
										
										if(tempParent != NULL){
											printParent(tempParent);
										}else{
											printf("\n\n\n\t\t\t[!] Data Dokter Tidak Ditemukan");
										}
									}else
									printf("\n\n\n\t\t\t[!] Data Dokter Masih Kosong");
									
									getch();
									continue;
									
								case 4:
									if(!isEmpty(l)){
										printf("\n\t\t\t--- Ubah Data Dokter ---\n");
	                                    printf("\n\t\t\tInput ID Dokter : "); scanf("%d", &id);
	
	                                    tempParent = findParent(l, id);
	                                    if (tempParent != NULL) {
	                                        do{
												printf("\n\t\t\t[+] Nama Dokter		: "); fflush(stdin); gets(nama);
												if(strlen(nama)<=0)
												printf("\t\t\t[!] Nama Dokter Tidak Boleh Kosong\n");
												else
												break;
											}while(true);
											do{
												printf("\t\t\t[+] Tanggal Bergabung [DD-MM-YYYY] : "); fflush(stdin); gets(tanggalBergabung);
												if(strlen(tanggalBergabung)<10 || tanggalBergabung[2] != '-' || tanggalBergabung[5] != '-')
												printf("\t\t\t[!] Tanggal Tidak Sesuai\n\n");
												else
												break;
											}while(true);
											do{
												printf("\t\t\t[+] Username		: "); fflush(stdin); gets(username);
												if(strlen(username)<=0 || !isUsernameUnik(l, username))
												printf("\t\t\t[!] Username Tidak Boleh Kosong\n\n");
												else
												break;
											}while(true);
											do{
												printf("\t\t\t[+] Password		: "); fflush(stdin); gets(password);
												if(strlen(password)<=0)
												printf("\t\t\t[!] Password Tidak Boleh Kosong\n\n");
												else
												break;
											}while(true);
	
	                                        tempParent->dataParent = makeDataParent(username, password, tempParent->dataParent.idDokter, nama, tanggalBergabung);
	                                        printf("\n\n\n\t\t\t[*] Berhasil Ubah Data Dokter");
	                                    } else {
	                                        printf("\n\n\n\t\t\t[!] Data Dokter Tidak Ditemukan");
	                                    }
									}else
									printf("\n\n\n\t\t\t[!] Data Dokter Masih Kosong");
                                    
                                    getch();
									continue;

                                case 5:
                                	if(!isEmpty(l)){
                                		printf("\n\t\t\t--- Hapus Data Dokter ---\n");
	                                    printf("\n\t\tInput ID Dokter : "); scanf("%d", &id);
	
	                                    tempParent = findParent(l, id);
	                                    if (tempParent != NULL) {
	                                        deleteAtParent(&l, tempParent->dataParent.idDokter);
	                                        deleteAllChild(tempParent);
	                                        printf("\n\n\n\t\t\t[*] Berhasil Hapus Data Dokter");
	                                    } else {
	                                        printf("\n\n\n\t\t\t[!] Data Dokter Tidak Ditemukan");
	                                    }
									}else
									printf("\n\n\n\t\t\t[!] Data Dokter Masih Kosong");
                                    
                                    getch();
									continue;
									
							}
							getch();
							
						case 2:
							if(!isEmpty(l)){
								printf("\n\t\t\t--- Pendaftaran Periksa Hewan ---");
								do{
									fflush(stdin);
									idHewan = 0;
									printf("\n\t\t\t[+] ID Hewan		: "); scanf("%d", &idHewan);
									if(idHewan <= 0 || !isUnik(list, idHewan))
									printf("\t\t\t[!] ID Harus Unik dan Harus Angka > 0\n");
									else
									break;
								}while(true);
								do{
									printf("\t\t\t[+] Nama Hewan		: "); fflush(stdin); gets(nama);
									if(strlen(nama)<=0)
									printf("\t\t\t[!] Nama Hewan Tidak Boleh Kosong\n\n");
									else
									break;
								}while(true);
								do{
									printf("\t\t\t[+] Tanggal Lahir [DD-MM-YYYY] : "); fflush(stdin); gets(tanggalLahir);
									if(strlen(tanggalLahir) != 10 || tanggalLahir[2] != '-' || tanggalLahir[5] != '-')
									printf("\t\t\t[!] Tanggal Tidak Sesuai\n\n");
									else
									break;
								}while(true);
								do{
									printf("\t\t\t[+] Jenis Hewan [Anjing/Burung/Kucing] : "); fflush(stdin); gets(jenisHewan);
									if(strlen(jenisHewan) <= 0 || (strcmpi(jenisHewan, "Anjing") != 0 && strcmpi(jenisHewan, "Burung") != 0 && strcmpi(jenisHewan, "Kucing") != 0))
									printf("\t\t\t[!] Jenis Hewan Tidak Sesuai\n\n");
									else
									break;
								}while(true);
								do{
									printf("\t\t\t[+] Jenis Kelamin (L/P)	: "); fflush(stdin); gets(jenisKelamin);
									if(strlen(jenisKelamin) <= 0 || (strcmpi(jenisKelamin, "L") != 0 && strcmpi(jenisKelamin, "P") != 0))
									printf("\t\t\t[!] Jenis Hewan Tidak Sesuai\n\n");
									else
									break;
								}while(true);
								do{
									fflush(stdin);
									idPeriksa = 0;
									printf("\t\t\t\t[+] ID Periksa		: "); scanf("%d", &idPeriksa);
									if(idPeriksa <= 0 || !isChildUnik(l,  idPeriksa))
									printf("\t\t\t\t[!] ID Harus Unik dan Harus Angka > 0\n\n");
									else
									break;
								}while(true);
								do{
									printf("\t\t\t\t[+] ID Dokter		: "); scanf("%d", &id);
									tempParent = findParent(l, id);
									if(tempParent == NULL)
									printf("\t\t\t\t[!] ID Dokter Tidak Ditemukan\n\n");
									else
									break;
								}while(true);
								do{
									printf("\t\t\t\t[+] Tanggal Periksa [DD-MM-YYYY] : "); fflush(stdin); gets(tanggalPeriksa);
									if(strlen(tanggalPeriksa) != 10 || tanggalPeriksa[2] != '-' || tanggalPeriksa[5] != '-')
									printf("\t\t\t\t[!] Tanggal Tidak Sesuai\n\n");
									else
									break;
								}while(true);
								
								if(strcmpi(jenisHewan, "Anjing") == 0){
									insertFirst(&list, makeData(idHewan, nama, tanggalLahir, jenisHewan, jenisKelamin, idPeriksa, id, tanggalPeriksa, "-", "-"));
									
								}else if(strcmpi(jenisHewan, "Kucing") == 0){
									insertLast(&list, makeData(idHewan, nama, tanggalLahir, jenisHewan, jenisKelamin, idPeriksa, id, tanggalPeriksa, "-", "-"));
									
								}else{
									insertAt(&list, makeData(idHewan, nama, tanggalLahir, jenisHewan, jenisKelamin, idPeriksa, id, tanggalPeriksa, "-", "-"), jenisHewan);
								}
								insertFirstChild(l, tempParent, makeDataChild(idHewan, nama, tanggalLahir, jenisHewan, jenisKelamin, idPeriksa, id, tanggalPeriksa, "-", "-"));
								printf("\n\n\n\t\t\t[*] Berhasil Tambah Data Hewan");
								
							}else
							printf("\n\n\n\t\t[!] Sedang Tidak Ada Dokter yang Bertugas");
							
							getch();
							break;
							
						case 3:
							if(!isEmptyList(list)){
								printf("\n\t\t\t--- Hapus Data Hewan ---");
								printf("\n\t\t\t[+] ID Hewan yang Ingin Dihapus	: "); scanf("%d", &idHewan);
								temp = cariHewan(list, idHewan);
								if(temp != NULL){
									tempParent = findParent(l, temp->P.idDokterBertugas);
									deleteAtChild(tempParent, idHewan);
									deleteAt(&list, temp);
									printf("\n\n\n\t\t\t[*] Berhasil Hapus Data Hewan");
								}else{
									printf("\n\n\n\t\t\t[!] Data Hewan Tidak Ditemukan");
								}
							}else
							printf("\n\n\n\t\t[!] Data Hewan Masih Kosong");
							
							getch();
							break;
							
						case 4:
							printf("\n\t\t\t--- Tampilkan Laporan ---\n");
							print(list);
							getch();
							break;
							
							
						
					}
					
				}while(submenu != 0);
				
				break;
				
			
			case 2:
				printf("\n\n\t\t[+] Username: "); fflush(stdin); gets(username);
				printf("\t\t[+] Password: "); fflush(stdin); gets(password);
				
				tempParent = cekUserDokter(l, username, password);
				
				if(tempParent != NULL){
					printf("\n\n\n\t\t[*] Berhasil Login Sebagai Dokter %s", tempParent->dataParent.namaDokter);
					getch();
					do{
						system("cls");
						printf("\n\t\t==============================");
						printf("\n\t\t||                          ||");
						printf("\n\t\t|| KLINIK HEWAN CINTA SATWA ||");
						printf("\n\t\t||                          ||");
						printf("\n\t\t==============================\n");
						printf("\t\t\tDokter %s\n", tempParent->dataParent.namaDokter);
						
						printf("\n\t\t[1] Cek Daftar Periksa Hewan");
						printf("\n\t\t[2] Periksa Hewan");
						printf("\n\t\t[3] Tampilkan Laporan");
						printf("\n\t\t[0] Logout");
						printf("\n\t\t>>> "); scanf("%d", &submenu);
						
						switch(submenu){
							
							default:
								printf("\n\n\n\t\t[!] Menu Tidak Tersedia");
								getch();
								break;
								
							case 0:
								printf("\n\n\n\t\t[!] LOGOUT");
								break;
								
							case 1:
								if(!isEmptyList(list)){
									printf("\n\t\t\t---- Data Periksa Hewan ----\n");
									cekPeriksaHewan(tempParent);
								}else{
									printf("\n\n\n\t\t\t[!] Data Hewan Masih Kosong");
								}
								getch();
								break;
								
							case 2:
								if(!isEmptyList(list)){
									printf("\n\t\t\t--- Periksa Hewan ---\n");
									printf("\n\n\t\t\t[+] ID Hewan yang Ingin Diperiksa	: "); scanf("%d", &idPeriksa);
									tempChild = findChild(l, tempParent, idPeriksa);
									
									if(tempChild != NULL){
										printChild(tempChild);
										do{
											printf("\n\t\t\t\t[+] Diagnosis	: "); fflush(stdin); gets(diagnosis);
											if(strlen(diagnosis) <= 0)
											printf("\t\t\t\t[!] Diagnosis Tidak Boleh Kosong\n");
											else
											break;
										}while(true);
										do{
											printf("\t\t\t\t[+] Obat - Obat	: "); fflush(stdin); gets(obat);
											if(strlen(obat) <= 0)
											printf("\t\t\t\t[!] Obat Tidak Boleh Kosong\n\n");
											else
											break;
										}while(true);
										
										// Update Data Child
										strcpy(tempChild->dataChild.diagnosis, diagnosis);
										strcpy(tempChild->dataChild.obat, obat);
										
										// Update List Data Hewan
										temp = cariHewan(list, tempChild->dataChild.idHewan);
										strcpy(temp->P.diagnosis, diagnosis);
										strcpy(temp->P.obat, obat);
										
										printf("\n\n\n\t\t\t[*] Berhasil Periksa Hewan");;
									}else{
										printf("\n\n\n\t\t\t[!] Data Periksa Tidak Ditemukan");
									}
								}
								getch();
								break;
								
							case 3:
								printf("\n\t\t\t--- Tampilkan Laporan ---\n");
								if(!isEmptyList(list)){
									printAllChild(tempParent);
								}
								getch();
								break;
								
								
							
						}
						
					}while(submenu != 0);
					
				}else{
					printf("\n\n\n\t\t[!] Username/Password Salah");
				}
				break;
				
				
				
			
		}
		getch();
		
		
	}while(menu != 0);
	
	return 0;
}
