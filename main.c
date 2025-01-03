#include <stdio.h>
#include <stdlib.h>
#include "functions.h"
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
int check;

int main() {
    char accountused[50];
    char passused[20];
    int options, length, curentlength = 0;
    bool flagexit=false;
    User information[100];
    AccountInfo account[100];
    login admin[1];
    initializeAdmin(admin);
    readFromFile(information, account, &curentlength);
    while (1) {
        zprintfRole();
        scanf("%d", &options);
        getchar();
        switch (options) {
            case 1:
                clearScreen();
                if (adAccount(admin) == 1) {
                    while (1) {
                        MENUadmin();
                        scanf("%d", &options);
                        getchar();
                        if (options == 0) {
                            clearScreen();
                            break;
                        } else {
                            switch (options) {
                                case 1:
                                    clearScreen();
                                    printf("Them nguoi dung.\n");
                                    InPutInformation(information, &length, &curentlength);
                                    addToFile(information, account, &curentlength);
                                    break;
                                case 2:
                                    clearScreen();
                                    printf("Hien thi danh sach nguoi dung.\n");
                                    OutPutInformation(information, &curentlength);
                                    break;
                                case 3:
                                    clearScreen();
                                    printf("Khoa/Mo khoa tai khoan.\n");
                                    lockUnlock(information, &curentlength);
                                    addToFile(information, account, &curentlength);
                                    break;
                                case 4:
                                    clearScreen();
                                    printf("Tim kiem nguoi dung theo ten.\n");
                                    searchInfo(information, &curentlength);
                                    break;
                                case 5:
                                    clearScreen();
                                    printf("Lua chon kieu sap xep:\n1. Sap xep theo ten\n2. Sap xep theo ID\nLua chon cua ban: ");
                                    int sortOption;
                                    scanf("%d", &sortOption);
                                    getchar();
                                    if (sortOption == 1) {
                                        printf("Sap xep danh sach nguoi dung theo ten.\n");
                                        sortinfoname(information, &curentlength);
                                    } else if (sortOption == 2) {
                                        printf("Sap xep danh sach nguoi dung theo ID.\n");
                                        sortinfoID(information, &curentlength);
                                    } else {
                                        printf("Lua chon khong hop le.\n");
                                    }
                                    break;
                                case 6:
                                    clearScreen();
                                    deleteAllUsers(information, account, &curentlength);
                                    break;
                                default:
                                    clearScreen();
                                    printf("Khong dung dinh dang.\n");
                                    break;
                            }
                        }
                    }
                } else {
                    printf("Thong tin khong chinh xac.\n");
                }
                break;
            case 2:
                clearScreen();
                printf("nhap thong tin tai khoan.\n");
                printf("email: ");
                fgets(accountused,sizeof(accountused),stdin);
                accountused[strcspn(accountused,"\n")]='\0';
                printf("mat khau(sdt): ");
                fgets(passused,sizeof(passused),stdin);
                passused[strcspn(passused,"\n")]='\0';
                int i;
                for( i=0; !flagexit; i++){
                    if(strcmp(information[i].email,accountused)==0 && strcmp(information[i].phone,passused)==0 && information[i].status==true){
                        flagexit=true;
                        while(1){
                            MENUused();
                            scanf("%d",&options);
                            if(options==6)  break;
                            switch(options){
                                case 1:
                                    clearScreen();
                                    break;
                                case 2:
                                    clearScreen();
                                    break;
                                case 3:
                                    clearScreen();
                                    break;
                                case 4:
                                    clearScreen();
                                    break;
                                case 5:
                                    clearScreen();
                                    break;
                                default :
                                    break;
                            }
                        }
                    }else if(information[i].status==false){
                        printf("tai khoan bi vo hieu hoa.\n");
                        return 0;
                    }
                }
                printf("khong ton tai nguoi dung.\n");
                break;
            case 0:
                clearScreen();
                printf("Hen gap lai.\n");
                return 0;
            default:
                printf("Lua chon khong hop le. Vui long chon lai.\n");
                break;
        }
    }
    return 0;
}



