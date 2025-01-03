
      
#include <stdbool.h>


//d?i tu?ng
 typedef struct {
    int month,day,year;
}Date;

 typedef struct {
    char transferID[10];//M� giao d?ch chuy?n ti?n
    char receivingID[10];//M� nh?n ti?n
    double amount;//S? ti?n
    char type[10];//Lo?i giao d?ch (V� d?: "chuy?n kho?n", "r�t ti?n")
    char message[50];//Tin nh?n k�m theo giao d?ch
    //struct Date transactionDate;//Ng�y giao d?ch (s? d?ng c?u tr�c Date)
}Transaction;//Luu tr? chi ti?t giao d?ch t�i ch�nh: C?u tr�c n�y luu tr? th�ng tin v? c�c giao d?ch t�i ch�nh

 typedef struct {
    char userID[20];//M� ngu?i d�ng
    float balance;//S? du t�i kho?n
    bool status;//Tr?ng th�i t�i kho?n (c� th? l� true/false ho?c ho?t d?ng/kh�a)
    //struct Transaction transactionHistory[];//L?ch s? giao d?ch (m?ng c�c giao d?ch, s? d?ng c?u tr�c Transaction)
    char username[10];
    char passwork[10];
}AccountInfo;//Qu?n l� th�ng tin t�i kho?n ngu?i d�ng: C?u tr�c n�y luu tr? th�ng tin t�i kho?n c?a ngu?i d�ng

 typedef struct {
    bool status;
    char userID[10];//M� ngu?i d�ng
    char name[100];//T�n ngu?i d�ng
    Date dateOfBirth[50];//Ng�y sinh (s? d?ng c?u tr�c Date)
    bool gender;//Gi?i t�nh
    char phone[11];//S? di?n tho?i
    char email[20];//�?a ch? email
}User;//Qu?n l� th�ng tin c� nh�n ngu?i d�ng: C?u tr�c n�y luu tr? th�ng tin c� nh�n c?a ngu?i d�ng

 typedef struct {
    char email[50];
    char password[10];
}login;
