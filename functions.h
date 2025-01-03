#include"Datatypes.h"


//hàm
int adAccout(login admin[1]);
void initializeAdmin(login admin[1]);
void MENUadmin();
void MENUused();
void InPutInformation( User information[100] , int *length , int *curentlength);
void gender();
void OutPutInformation(User information[100], int *curentlength);
void addToFile(User information[100], AccountInfo account[100], int *curentlength);
void readFromFile(User information[100], AccountInfo account[100], int *curentlength);
void searchInfo(User information[100], int *curentlength);
void zprintfRole();
int TCheckValidity(User information[100],int check,int i,int *curentlength);
void clearScreen();
void lockUnlock(User information[100], int *curentlength);
void sortinfoname(User information[100],int *curentlength);
void sortinfoID(User information[100],int *curentlength);
void deleteAllUsers(User information[100], AccountInfo account[100], int *curentlength);
int isNumeric(const char *str);
void banking();
void Editinformation(User information[100],int *curentlength,int i);


