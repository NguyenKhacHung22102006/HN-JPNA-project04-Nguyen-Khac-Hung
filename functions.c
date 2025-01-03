#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
#include"functions.h"
void Editinformation(User information[100], int *curentlength, int i) {
    printf("Chinh sua thong tin nguoi dung.\n");
    int check;
    int choice;

    // Ch?nh s?a tên
    printf("Ban co muon sua ten khong? (1: Co, 2: Khong): ");
    scanf("%d", &choice);
    getchar(); // Xóa ký t? xu?ng dòng th?a
    if (choice == 1) {
        printf("Nhap ten moi (toi da 19 ky tu): ");
        fgets(information[i].name, sizeof(information[i].name), stdin);
        information[i].name[strcspn(information[i].name, "\n")] = '\0';
        if (strlen(information[i].name) > 0 && strlen(information[i].name) <= 19) {
            // Ki?m tra tính h?p l? c?a tên
            check = 2;
            while (check != 0) {
                check = TCheckValidity(information, check, i, curentlength);
            }
        } else {
            printf("Ten khong hop le.\n");
        }
    }

    // Ch?nh s?a ngày sinh
    printf("Ban co muon sua ngay sinh khong? (1: Co, 2: Khong): ");
    scanf("%d", &choice);
    getchar(); // Xóa ký t? xu?ng dòng th?a
    if (choice == 1) {
        printf("Nhap ngay sinh moi (dd mm yyyy): ");
        check = 3;
        while(check != 0) {
            scanf("%d %d %d", &information[i].dateOfBirth->day, &information[i].dateOfBirth->month, &information[i].dateOfBirth->year);
            getchar();
            check = TCheckValidity(information, check, i, curentlength);
        }
        getchar();  // Xóa ký t? xu?ng dòng th?a
    }

    // Ch?nh s?a gi?i tính
    printf("Ban co muon sua gioi tinh khong? (1: Co, 2: Khong): ");
    scanf("%d", &choice);
    getchar(); // Xóa ký t? xu?ng dòng th?a
    if (choice == 1) {
        printf("Nhap gioi tinh moi (1: Nam, 2: Nu): ");
        int gender;
        if (scanf("%d", &gender) == 1) {
            if (gender == 1) {
                information[i].gender = true;  // Nam
            } else if (gender == 2) {
                information[i].gender = false;  // N?
            }
        }
        getchar();  // Xóa ký t? xu?ng dòng th?a
    }

    // Ch?nh s?a s? di?n tho?i
    printf("Ban co muon sua so dien thoai khong? (1: Co, 2: Khong): ");
    scanf("%d", &choice);
    getchar(); // Xóa ký t? xu?ng dòng th?a
    if (choice == 1) {
        printf("Nhap so dien thoai moi: ");
        fgets(information[i].phone, sizeof(information[i].phone), stdin);
        information[i].phone[strcspn(information[i].phone, "\n")] = '\0';
        if (strlen(information[i].phone) > 0) {
            // Ki?m tra tính h?p l? c?a s? di?n tho?i
            check = 4;
            while (check != 0) {
                check = TCheckValidity(information, check, i, curentlength);
            }
        }
    }

    // Ch?nh s?a email
    printf("Ban co muon sua dia chi email khong? (1: Co, 2: Khong): ");
    scanf("%d", &choice);
    getchar(); // Xóa ký t? xu?ng dòng th?a
    if (choice == 1) {
        printf("Nhap dia chi email moi: ");
        fgets(information[i].email, sizeof(information[i].email), stdin);
        information[i].email[strcspn(information[i].email, "\n")] = '\0';
        if (strlen(information[i].email) > 0) {
            // Ki?m tra tính h?p l? c?a email
            check = 5;
            while (check != 0) {
                check = TCheckValidity(information, check, i, curentlength);
            }
        }
    }

    printf("Thong tin da duoc chinh sua thanh cong.\n");
}




int adAccount(login admin[1]) {
    char email[50];
    char password[20];
    printf("Nhap email: ");
    fgets(email, sizeof(email), stdin);
    email[strcspn(email, "\n")] = '\0';
    printf("Nhap mat khau: ");
    fgets(password, sizeof(password), stdin);
    password[strcspn(password, "\n")] = '\0';
    if (strcmp(admin[0].email,email) == 0 && strcmp(admin[0].password, password) == 0) {
        return 1;
    } else {
        return 0;
    }
}

void initializeAdmin(login admin[1]) {
    strcpy(admin[0].email, "1");
    strcpy(admin[0].password, "1");
}

int isNumeric(const char *str) {
	int i;
    for ( i = 0; str[i] != '\0'; i++) {
        if (!isdigit(str[i])) {
            return 0;
        }
    }
    return 1;
}

void InPutInformation(User information[100], int *length, int *curentlength) {
    printf("So tai khoan can them: ");
    scanf("%d", length);
    getchar();
    int gender, check,id;
    int i;
    for ( i = *curentlength; i < *length + *curentlength; i++) {
        printf("\nNhap thong tin tai khoan thu %d:\n", i + 1);
        printf("Ma nguoi dung (5 chu so: vd 12345): ");
        check = 1;
        while(check != 0) {
            fgets(information[i].userID, sizeof(information[i].userID), stdin);
            information[i].userID[strcspn(information[i].userID, "\n")] = '\0';
            id=isNumeric(information[i].userID);
            if(id==1){
            check = TCheckValidity(information, check, i, curentlength);
            }else{
                printf("phai la so.\n");
            }
        }
        printf("Ho va ten (toi da 19 ky tu): ");
        check = 2;
        while (check != 0) {
            fgets(information[i].name, sizeof(information[i].name), stdin);
            information[i].name[strcspn(information[i].name, "\n")] = '\0';

            // Ki?m tra d? dài tên
            if (strlen(information[i].name) > 19) {
                printf("Ten qua dai, vui long nhap toi da 19 ky tu.\n");
                continue; // Yêu c?u ngu?i dùng nh?p l?i.
            }
            check = TCheckValidity(information, check, i, curentlength);
        }

        printf("Ngay sinh (dd mm yyyy): ");
        check = 3;
        while(check != 0) {
            scanf("%d %d %d", &information[i].dateOfBirth->day, &information[i].dateOfBirth->month, &information[i].dateOfBirth->year);
            getchar();
            check = TCheckValidity(information, check, i, curentlength);
        }
        printf("Gioi tinh (1: Nam, 2: Nu): ");
        while (1) {
            scanf("%d", &gender);
            getchar();
            if (gender == 1) {
                information[i].gender = true; // Nam
                break;
            } else if (gender == 2) {
                information[i].gender = false; // N?
                break;
            } else {
                printf("Lua chon khong hop le. Vui long chon lai (1: Nam, 2: Nu): ");
            }
        }
        printf("So dien thoai: ");
        check = 4;
        while(check != 0) {
            fgets(information[i].phone, sizeof(information[i].phone), stdin);
            information[i].phone[strcspn(information[i].phone, "\n")] = '\0';
            check = TCheckValidity(information, check, i, curentlength);
        }
        getchar();
        printf("Email: "); check =5;
        while(check!=0){
            fgets(information[i].email, sizeof(information[i].email), stdin);
            information[i].email[strcspn(information[i].email, "\n")] = '\0';
            check = TCheckValidity(information, check, i, curentlength);
        }
        printf("\nDa nhap xong tai khoan thu %d.\n", i + 1);
    }
    *curentlength += *length;
}

void OutPutInformation(User information[100], int *curentlength) {
    printf("|=======================================================================================================|\n");
    printf("                                  Thong tin Nguoi Dung\n");
    printf("|=======================================================================================================|\n");
    printf("+------------+--------------------+------------+---------+------------+--------------------+------------+\n");
    printf("| User ID    | Name               | Ngay Sinh  | Gender  | Phone      | Email              | Status     |\n");
    printf("+------------+--------------------+------------+---------+------------+--------------------+------------+\n");
    int i;
	for ( i = 0; i < *curentlength; i++) {
        printf("| %-10s | %-18s | %02d/%02d/%04d | %-7s | %-10s | %-18s | %-10s |\n",
                information[i].userID, information[i].name,
                information[i].dateOfBirth->day, information[i].dateOfBirth->month, information[i].dateOfBirth->year,
                information[i].gender ? "nam" : "nu",
                information[i].phone, information[i].email,
                information[i].status ? "Active" : "Locked");
    }
    printf("+------------+--------------------+------------+---------+------------+--------------------+------------+\n");
    printf("\n");
}

void addToFile(User information[100], AccountInfo account[100], int *curentlength) {
    FILE *fptr = fopen("projectnew.dat", "wb");
    if (fptr == NULL) {
        printf("Khong the mo tep de ghi.\n");
        return;
    }
    fwrite(curentlength, sizeof(int), 1, fptr);
    fwrite(information, sizeof(User), *curentlength, fptr);
    fclose(fptr);
    printf("Da luu du lieu vao tep.\n");
}

void readFromFile(User information[100], AccountInfo account[100], int *curentlength) {
    FILE *fptr = fopen("projectnew.dat", "rb+");
    if (fptr == NULL) {
        printf("Khong the mo tep de doc. File co the chua duoc tao.\n");
        *curentlength = 0;
        return;
    }
    fread(curentlength, sizeof(int), 1, fptr);
    fread(information, sizeof(User), *curentlength, fptr);
    fclose(fptr);
    printf("Da doc du lieu tu tep.\n");
}

void searchInfo(User information[100], int *curentlength) {
    int choice;
    printf("Lua chon kieu tim kiem:\n1. Tim theo ten\n2. Tim theo ID\nLua chon cua ban: ");
    scanf("%d", &choice);
    getchar();

    if (choice == 1) {
        char nametest[20];
        printf("Nhap ten nguoi dung muon tim kiem: ");
        fgets(nametest, sizeof(nametest), stdin);
        nametest[strcspn(nametest, "\n")] = '\0';
        int i;
        for ( i = 0; i < *curentlength; i++) {
            if (strcmp(information[i].name, nametest) == 0) {
                printf("|=======================================================================================================|\n");
                printf("                                  Thong tin Nguoi Dung\n");
                printf("|=======================================================================================================|\n");
                printf("+------------+--------------------+------------+---------+------------+--------------------+------------+\n");
                printf("| User ID    | Name               | Ngay Sinh  | Gender  | Phone      | Email              | Status     |\n");
                printf("+------------+--------------------+------------+---------+------------+--------------------+------------+\n");
                printf("| %-10s | %-18s | %02d/%02d/%04d | %-7s | %-10s | %-18s | %-10s |\n",
                    information[i].userID, information[i].name,
                    information[i].dateOfBirth->day, information[i].dateOfBirth->month, information[i].dateOfBirth->year,
                    information[i].gender ? "nam" : "nu",
                    information[i].phone, information[i].email,
                    information[i].status ? "Active" : "Locked");
                printf("+------------+--------------------+------------+---------+------------+--------------------+------------+\n");
                printf("\n");
                return;
            }
        }
        printf("Khong tim thay nguoi dung.\n");
    } else if (choice == 2) {
        char idtest[10];
        printf("Nhap ID nguoi dung muon tim kiem: ");
        fgets(idtest, sizeof(idtest), stdin);
        idtest[strcspn(idtest, "\n")] = '\0';
        int i;
        for (i = 0; i < *curentlength; i++) {
            if (strcmp(information[i].userID, idtest) == 0) {
                printf("|=======================================================================================================|\n");
                printf("                                  Thong tin Nguoi Dung\n");
                printf("|=======================================================================================================|\n");
                printf("+------------+--------------------+------------+---------+------------+--------------------+------------+\n");
                printf("| User ID    | Name               | Ngay Sinh  | Gender  | Phone      | Email              | Status     |\n");
                printf("+------------+--------------------+------------+---------+------------+--------------------+------------+\n");
                printf("| %-10s | %-18s | %02d/%02d/%04d | %-7s | %-10s | %-18s | %-10s |\n",
                    information[i].userID, information[i].name,
                    information[i].dateOfBirth->day, information[i].dateOfBirth->month, information[i].dateOfBirth->year,
                    information[i].gender ? "nam" : "nu",
                    information[i].phone, information[i].email,
                    information[i].status ? "Active" : "Locked");
                printf("+------------+--------------------+------------+---------+------------+--------------------+------------+\n");
                printf("\n");
                return;
            }
        }
        printf("Khong tim thay nguoi dung.\n");
    } else {
        printf("Lua chon khong hop le.\n");
    }
}

void MENUadmin() {
    printf("|=================================|\n");
    printf("       Quan Li Nguoi Dung\n");
    printf("|=================================|\n");
    printf(" 1.Them nguoi dung.\n");
    printf(" 2.Hien thi danh sach nguoi dung.\n");
    printf(" 3.khoa/Mo khoa tai khoan.\n");
    printf(" 4.Tim kiem nguoi dung theo ten.\n");
    printf(" 5.sap sep nguoi dung(ten or id).\n");
    printf(" 6.xoa toan bo.\n");
    printf(" 0.Thoat.\n");
    printf("|=================================|\n");
    printf("LUA CHON CUA BAN: ");
}

void MENUused() {
    printf("|=================================|\n");
    printf("       Dich Vu Cua Ngan Hang\n");
    printf("|=================================|\n");
    printf(" 1.chuyen tien.\n");
    printf(" 2.rut tien.\n");
    printf(" 3.lich su giao dich.\n");
    printf(" 4.thong tin tai khoan.\n");
    printf(" 5.sua thong tin.\n");
    printf(" 6.thoat.\n");
    printf("|=================================|\n");
    printf("LUA CHON CUA BAN: ");
}

int TCheckValidity(User information[100], int check, int i, int *curentlength) {
    int day = information[i].dateOfBirth->day;
    int month = information[i].dateOfBirth->month;
    int year = information[i].dateOfBirth->year;
    int namnhuan,dai;
    int j;
    switch (check) {
        case 1:
            for ( j = 0; j < *curentlength; j++) {
                if (strcmp(information[j].userID, information[i].userID) == 0) {
                    printf("ID da ton tai.\n");
                    return 1;
                }
            }
            if (strlen(information[i].userID) == 5) {
                return 0;
            } else {
                printf("User ID khong hop le, phai chinh sac 5 chu so.\n");
                return 1;
            }
        case 2:  // Ki?m tra d? dài Tên
            for ( j = 0; j < *curentlength; j++) {
                if (strcmp(information[j].name, information[i].name) == 0) {
                    printf("ten da ton tai.\n");
                    return 2;
                }
            }
            return 0;
        case 3:  // Ki?m tra ngày sinh
            if (year % 100 != 0 && year % 4 == 0 || year % 400 == 0) {
                namnhuan = 0;  // Nam nhu?n
            } else {
                namnhuan = 1;  // Không ph?i nam nhu?n
            }
            if (year <= 2024 && month <= 12 && day <= 31) {
                if (month == 2) {
                    if ((namnhuan == 0 && day <= 29) || (namnhuan == 1 && day <= 28)) {
                        return 0;
                    } else {
                        printf("ngay sinh khong hop le cho thang 2.\n");
                        return 3;
                    }
                } else if (month == 4 || month == 6 || month == 9 || month == 11) {
                    if (day <= 30) {
                        return 0;
                    } else {
                        printf("ngay sinh khong hop le voi thang %d\n",information[i].dateOfBirth->month);
                        return 3;
                    }
                } else if (1 <= month && month <= 12) {
                    if (day <= 31) {
                        return 0;
                    } else {
                        printf("ngay sinh khong hop le voi thang %d\n",information[i].dateOfBirth->month);
                        return 3;
                    }
                }
            } else {
                printf("ngay thang nam sinh khong hop le.\n");
                return -1;
            }
        case 4://kiem tra s? di?n tho?i.
            for( j=0; j<*curentlength; j++){
                if(strcmp(information[j].phone,information[i].phone)==0){
                    printf("sdt nguoi dung da ton tai.\n");
                    return 4;
                }
            }
            if(strlen(information[i].phone)==10){
                return 0;
            }else{
                printf("khong hop le. dung 10 so.\n");
                return 4;
            }
        case 5:
            for( j=0; j<*curentlength; j++){
                if(strcmp(information[j].email,information[i].email)==0){
                    printf("email nguoi dung da ton tai.\n");
                    return 5;
                }
            }
            return 0;
    }
}

void clearScreen() {
#ifdef _WIN32
    system("cls"); // L?nh xóa màn hình trên Windows
#else
    system("clear"); // L?nh xóa màn hình trên Linux/MacOS
#endif
}

void lockUnlock(User information[100], int *curentlength) {
    char testid[10];
    int choice;
    int i;
    printf("Nhap ID tai khoan muon khoa/mo khoa: ");
    fgets(testid, sizeof(testid), stdin);
    testid[strcspn(testid, "\n")] = '\0';
    for ( i = 0; i < *curentlength; i++) {
        if (strcmp(information[i].userID, testid) == 0) {
            if (information[i].status == false) {
                printf("Tai khoan dang bi khoa.\n1. Mo khoa.\n0. Thoat.\n");
                scanf("%d", &choice);
                getchar();
                if (choice == 1) {
                    information[i].status = true;
                    printf("Tai khoan da duoc mo khoa.\n");
                } else if (choice == 0) {
                    return;
                } else {
                    printf("Lua chon khong hop le.\n");
                }
            } else {
                printf("Tai khoan dang hoat dong binh thuong.\n1. Khoa.\n0. Thoat.\n");
                scanf("%d", &choice);
                getchar();
                if (choice == 1) {
                    information[i].status = false;
                    printf("Tai khoan da bi khoa.\n");
                } else if (choice == 0) {
                    return;
                } else {
                    printf("Lua chon khong hop le.\n");
                }
            }
            return;
        }
    }
    printf("Khong tim thay tai khoan.\n");
}

void zprintfRole(){
	printf("***Bank Managemet System Using C***\n");
	printf("\n");
	printf("    VAI TRO CUA BAN \n");
	printf("==========================\n");
	printf("[1] Admin.\n");
	printf("[2] User.\n");
	printf("[0] Exit the Program.\n");
	printf("==========================\n");
	printf("LUA CHON CUA BAN: ");
}

void deleteAllUsers(User information[100], AccountInfo account[100], int *curentlength) {
    *curentlength = 0;
    addToFile(information, account, curentlength);
    printf("Da xoa het tat ca cac nguoi dung.\n");
}

void sortinfoname(User information[100], int *curentlength) {
	int i,j;
    for ( i = 0; i < *curentlength - 1; i++) {
        for ( j = 0; j < *curentlength - 1 - i; j++) {
            if (strcmp(information[j].name, information[j + 1].name) > 0) {
                User temp = information[j];
                information[j] = information[j + 1];
                information[j + 1] = temp;
            }
        }
    }
    printf("|=======================================================================================================|\n");
    printf("                                  Thong tin Nguoi Dung\n");
    printf("|=======================================================================================================|\n");
    printf("+------------+--------------------+------------+---------+------------+--------------------+------------+\n");
    printf("| User ID    | Name               | Ngay Sinh  | Gender  | Phone      | Email              | Status     |\n");
    printf("+------------+--------------------+------------+---------+------------+--------------------+------------+\n");
    for (i = 0; i < *curentlength; i++) {
        printf("| %-10s | %-18s | %02d/%02d/%04d | %-7s | %-10s | %-18s | %-10s |\n",
                information[i].userID, information[i].name,
                information[i].dateOfBirth->day, information[i].dateOfBirth->month, information[i].dateOfBirth->year,
                information[i].gender ? "nam" : "nu",
                information[i].phone, information[i].email,
                information[i].status ? "Active" : "Locked");
    }
    printf("+------------+--------------------+------------+---------+------------+--------------------+------------+\n");
    printf("\n");
}

void sortinfoID(User information[100], int *curentlength) {
	int i,j;
    for ( i = 0; i < *curentlength - 1; i++) {
        for (j = 0; j < *curentlength - 1 - i; j++) {
            if (strcmp(information[j].userID, information[j + 1].userID) > 0) {
                User temp = information[j];
                information[j] = information[j + 1];
                information[j + 1] = temp;
            }
        }
    }
    printf("|=======================================================================================================|\n");
    printf("                                  Thong tin Nguoi Dung\n");
    printf("|=======================================================================================================|\n");
    printf("+------------+--------------------+------------+---------+------------+--------------------+------------+\n");
    printf("| User ID    | Name               | Ngay Sinh  | Gender  | Phone      | Email              | Status     |\n");
    printf("+------------+--------------------+------------+---------+------------+--------------------+------------+\n");
    for (i = 0; i < *curentlength; i++) {
        printf("| %-10s | %-18s | %02d/%02d/%04d | %-7s | %-10s | %-18s | %-10s |\n",
                information[i].userID, information[i].name,
                information[i].dateOfBirth->day, information[i].dateOfBirth->month, information[i].dateOfBirth->year,
                information[i].gender ? "nam" : "nu",
                information[i].phone, information[i].email,
                information[i].status ? "Active" : "Locked");
    }
    printf("+------------+--------------------+------------+---------+------------+--------------------+------------+\n");
    printf("\n");
}

    
