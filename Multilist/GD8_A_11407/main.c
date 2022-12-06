#include "header.h"

int main() {
    Multilist l;
    AddressParent tempParent;
    AddressChild tempChild;
    createEmpty(&l);

    string konfirmasi;

    int idParent;

    int menu;
    int id;
    int umur;
    string nama;

    int urut = 1;
    do {
        system("cls");

        printf("\n\t=== GUIDED ===");
        printf("\n\n\t=== Menu Parent ===");
        printf("\n[%d]\tInsert First Parent", urut++);
        printf("\n[%d]\tInsert After Parent", urut++);
        printf("\n[%d]\tInsert Last Parent", urut++);
        printf("\n[%d]\tDelete First Parent", urut++);
        printf("\n[%d]\tDelete At Parent", urut++);
        printf("\n[%d]\tDelete Last Parent", urut++);
        printf("\n[%d]\tFind Parent", urut++);
        printf("\n[%d]\tShow Parent", urut++);

        printf("\n\n\t=== Menu Child ===");
        printf("\n[%d]\tInsert First Child", urut++);
        printf("\n[%d]\tInsert Last Child", urut++);
        printf("\n[%d]\tDelete First Child", urut++);
        printf("\n[%d]\tDelete Last Child", urut++);
        printf("\n[%d]\tShow Child", urut++);

        printf("\n\n\t=== Show All ===");
        printf("\n[%d]\tShow All", urut++);
        printf("\n[0]\tExit");

        urut = 1;

        printf("\n\n>>>>> ");
        scanf("%d", &menu);

        switch (menu) {
            // insert first parent
            case 1:
                printf("\n\t\t--- Input First Parent ---\n");
                do {
                    printf("\t\tInput Id Tim : ");
                    scanf("%d", &id);

                    if (isUnik(l, id)) {
                        break;
                    } else {
                        printf("\t\t\t[!] ID Harus Unik\n\n");
                    }
                } while (true);

                do {
                    printf("\t\tInput Nama Tim : ");
                    fflush(stdin);
                    gets(nama);

                    if (strlen(nama) != 0) {
                        break;
                    } else {
                        printf("\t\t\t[!] Nama Tidak Boleh Kosong\n\n");
                    }
                } while (true);

                insertFirstParent(&l, makeDataParent(id, nama));
                printf("\n\t\t\t[*] Input First Berhasil");
                break;  // break case 1

            case 2:
                printf("\n\t\t--- Input At Parent --- \n");

                if (!isEmpty(l)) {
                    printf("\n\t Input Id Parent : ");
                    scanf("%d", &idParent);

                    tempParent = findParent(l, idParent);

                    if (tempParent == NULL) {
                        printf("\n\t\t[!] Parent Tidak Ditemukan!");
                    } else {
                        printf("\n");
                        do {
                            printf("\t\tInput Id Tim : ");
                            scanf("%d", &id);

                            if (isUnik(l, id)) {
                                break;
                            } else {
                                printf("\t\t\t[!] ID Harus Unik\n\n");
                            }
                        } while (true);

                        do {
                            printf("\t\tInput Nama Tim : ");
                            fflush(stdin);
                            gets(nama);

                            if (strlen(nama) != 0) {
                                break;
                            } else {
                                printf("\t\t\t[!] Nama Tidak Boleh Kosong\n\n");
                            }
                        } while (true);

                        insertAtParent(&l, idParent, makeDataParent(id, nama));
                        printf("\n\t\t[*] Berhasil Insert At!");
                    }

                } else {
                    printf("\n\t\t[!] List Masih Kosong!");
                }

                break;  // break case 2

            // input last parent
            case 3:

                printf("\n\t\t--- Input Last Parent ---\n");
                do {
                    printf("\t\tInput Id Tim : ");
                    scanf("%d", &id);

                    if (isUnik(l, id)) {
                        break;
                    } else {
                        printf("\t\t\t[!] ID Harus Unik\n\n");
                    }
                } while (true);

                do {
                    printf("\t\tInput Nama Tim : ");
                    fflush(stdin);
                    gets(nama);

                    if (strlen(nama) != 0) {
                        break;
                    } else {
                        printf("\t\t\t[!] Nama Tidak Boleh Kosong\n\n");
                    }
                } while (true);

                insertLastParent(&l, makeDataParent(id, nama));

                printf("\n\t\t\t[*] Input Last Berhasil");
                break;  // break case 3

            case 4:
                printf("\n\t\t=== Delete First Parent ===");

                if (!isEmpty(l)) {
                    printParent(l.firstParent);
                    printAllChild(l.firstParent);

                    printf("\n\n\tApakah Yakin ingin Menghapus Parent? [Y/N] : ");
                    fflush(stdin);
                    gets(konfirmasi);

                    if (!strcmpi(konfirmasi, "y")) {
                        deleteFirstParent(&l);
                        printf("\n\t\t\t[*] Delete First Berhasil");
                    } else if (!strcmpi(konfirmasi, "n")) {
                        printf("\n\t\t\t[!] Delete First Dibatalkan");
                    } else {
                        printf("\n\t\t\t[!] Inputan Invalid");
                    }
                } else {
                    printf("\n\t\t[!] List Masih Kosong");
                }

                break;  // break case 4;

            case 5:
                printf("\n\t\t=== Delete At Parent ===");

                if (!isEmpty(l)) {
                    printf("\n\n\tInput Id Parent : ");
                    scanf("%d", &idParent);

                    tempParent = findParent(l, idParent);

                    if (tempParent == NULL) {
                        printf("\n\t\t[!] Parent Tidak Ditemukan!");
                    } else {
                        printParent(tempParent);
                        printAllChild(tempParent);

                        printf("\n\n\tApakah Yakin ingin Menghapus Parent? [Y/N] : ");
                        fflush(stdin);
                        gets(konfirmasi);

                        if (!strcmpi(konfirmasi, "y")) {
                            deleteAtParent(&l, idParent);
                            printf("\n\t\t\t[*] Delete At Berhasil");
                        } else if (!strcmpi(konfirmasi, "n")) {
                            printf("\n\t\t\t[!] Delete At Dibatalkan");
                        } else {
                            printf("\n\t\t\t[!] Inputan Invalid");
                        }
                    }
                } else {
                    printf("\n\t\t[!] List Masih Kosong!");
                }
                break;  // break case 5

            case 6:
                printf("\n\t\t=== Delete Last Parent ===");

                if (!isEmpty(l)) {
                    tempParent = l.firstParent;

                    if (tempParent->next != NULL) {
                        while (tempParent->next != NULL) {
                            tempParent = tempParent->next;
                        }
                    }

                    printParent(tempParent);
                    printAllChild(tempParent);

                    printf("\n\n\tApakah Yakin ingin Menghapus Parent? [Y/N] : ");
                    fflush(stdin);
                    gets(konfirmasi);

                    if (!strcmpi(konfirmasi, "y")) {
                        deleteLastParent(&l);
                        printf("\n\t\t\t[*] Delete Last Berhasil");
                    } else if (!strcmpi(konfirmasi, "n")) {
                        printf("\n\t\t\t[!] Delete Last Dibatalkan");
                    } else {
                        printf("\n\t\t\t[!] Inputan Invalid");
                    }
                } else {
                    printf("\n\t\t[!] List Masih Kosong");
                }

                break;  // break case 6

            case 7:
                printf("\n\t\t=== Find Parent ===");
                printf("\n\n\tInput Id Parent : ");
                scanf("%d", &idParent);

                tempParent = findParent(l, idParent);

                if (tempParent == NULL) {
                    printf("\n\t\t\t[!] Parent Tidak Ditemukan!");
                } else {
                    printParent(tempParent);
                    printAllChild(tempParent);
                }

                break;  // break case 7;

            case 8:
                printf("\n\t\t=== Show Parent ===");
                if (!isEmpty(l)) {
                    printAllParent(l);
                } else {
                    printf("\n\t\t[!] List Masih Kosong");
                }

                break;  // break case 8

            case 9:
                printf("\n\t\t=== Input First Child ===");
                printf("\n\tInput Id Tim : ");
                scanf("%d", &idParent);

                tempParent = findParent(l, idParent);

                if (tempParent != NULL) {
                    printParent(tempParent);

                    printf("\n\t--------------------------------\n");
                    do {
                        printf("\n\tInput Nama : ");
                        fflush(stdin);
                        gets(nama);
                        if (strlen(nama) == 0) {
                            printf("\t\t[!] Nama Tidak Boleh Kosong\n");
                        } else {
                            break;
                        }

                    } while (true);

                    do {
                        printf("\tInput Umur : ");
                        scanf("%d", &umur);
                        if (umur <= 0) {
                            printf("\n\t\t[!] Umur Tidak Boleh <= 0\n");
                        } else {
                            break;
                        }
                    } while (true);

                    insertFirstChild(l, idParent, makeDataChild(nama, umur));
                    printf("\n\t\t\t[*] Input First Child Berhasil");

                } else {
                    printf("\n\t\t[!] Parent Tidak Ditemukan");
                }

                break;  // break case 9;

            case 10:
                printf("\n\t\t=== Input Last Child ===");

                printf("\n\tInput Id Tim : ");
                scanf("%d", &idParent);

                tempParent = findParent(l, idParent);

                if (tempParent != NULL) {
                    printParent(tempParent);

                    printf("\n\t--------------------------------\n");

                    do {
                        printf("\n\tInput Nama : ");
                        fflush(stdin);
                        gets(nama);
                        if (strlen(nama) == 0) {
                            printf("\t\t[!] Nama Tidak Boleh Kosong\n");
                        } else {
                            break;
                        }

                    } while (true);

                    do {
                        printf("\tInput Umur : ");
                        scanf("%d", &umur);
                        if (umur <= 0) {
                            printf("\n\t\t[!] Umur Tidak Boleh <= 0\n");
                        } else {
                            break;
                        }
                    } while (true);

                    insertLastChild(l, idParent, makeDataChild(nama, umur));

                    printf("\n\t\t\t[*] Input Last Child Berhasil");

                } else {
                    printf("\n\t\t[!] Parent Tidak Ditemukan");
                }

                break;  // break case 10;

            case 11:
                printf("\n\t\t=== Delete First Child ===");
                printf("\n\tInput Id Tim : ");
                scanf("%d", &idParent);

                tempParent = findParent(l, idParent);

                if (tempParent != NULL) {
                    printParent(tempParent);

                    if (haveChild(tempParent)) {
                        printChild(tempParent->firstChild);
                        printf("\n\tApakah Yakin Ingin Menghapus Child? [Y/N] : ");
                        fflush(stdin);
                        gets(konfirmasi);

                        if (!strcmpi(konfirmasi, "y")) {
                            printf("\n\t\t[*] Delete First Child Berhasil");
                            deleteFirstChild(l, idParent);
                        } else if (!strcmpi(konfirmasi, "n")) {
                            printf("\n\t\t[*] Delete First Child Dibatalkan");
                        } else {
                            printf("\n\t\t[!] Inputan Invalid");
                        }
                    } else {
                        printf("\n\n\t\t[*] Parent Tidak Memiliki Child");
                    }
                    printf("\n\t--------------------------------\n");
                } else {
                    printf("\n\t\t[!] Parent Tidak Ditemukan");
                }
                break;  // break case 11

            case 12:
                printf("\n\t\t=== Delete Last Child ===");
                printf("\n\tInput Id Tim : ");
                scanf("%d", &idParent);

                tempParent = findParent(l, idParent);

                if (tempParent != NULL) {
                    printParent(tempParent);

                    if (haveChild(tempParent)) {
                        tempChild = tempParent->firstChild;
                        while (tempChild->next != NULL) {
                            tempChild = tempChild->next;
                        }

                        printChild(tempChild);
                        printf("\n\tApakah Yakin Ingin Menghapus Child? [Y/N] : ");
                        fflush(stdin);
                        gets(konfirmasi);

                        if (!strcmpi(konfirmasi, "y")) {
                            deleteLastChild(l, idParent);
                            printf("\n\t\t[*] Delete Last Child Berhasil");
                        } else if (!strcmpi(konfirmasi, "n")) {
                            printf("\n\t\t[*] Delete Last Child Dibatalkan");
                        } else {
                            printf("\n\t\t[!] Inputan Invalid");
                        }
                    } else {
                        printf("\n\n\t\t[*] Parent Tidak Memiliki Child");
                    }
                    printf("\n\t--------------------------------\n");
                } else {
                    printf("\n\t\t[!] Parent Tidak Ditemukan");
                }

                break;  // break case 12

            case 13:
                printf("\n\t=== Show Child ===");

                printf("\n\tInput Id Tim : ");
                scanf("%d", &idParent);

                tempParent = findParent(l, idParent);

                if (tempParent != NULL) {
                    printAllChild(tempParent);
                } else {
                    printf("\n\t\t[!] Parent Tidak Ditemukan");
                }
                break;  // break case 13

            case 14:

                if (!isEmpty(l)) {
                    printAll(l);
                } else {
                    printf("\n\t\t[!] List Masih Kosong");
                }

                break;  // break case 14;

            case 0:
                printf("\n\t\t[*] Keluar Menu");
                break;

            default:
                printf("\n\t\t[!] Menu Tidak Ditemukan");
                break;  // break default;
        }

        getch();
    } while (menu != 0);

    return 0;
}

