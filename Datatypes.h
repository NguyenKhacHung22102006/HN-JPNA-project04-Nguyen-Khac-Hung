
      
#include <stdbool.h>


//d?i tu?ng
 typedef struct {
    int month,day,year;
}Date;

 typedef struct {
    char transferID[10];//Mã giao d?ch chuy?n ti?n
    char receivingID[10];//Mã nh?n ti?n
    double amount;//S? ti?n
    char type[10];//Lo?i giao d?ch (Ví d?: "chuy?n kho?n", "rút ti?n")
    char message[50];//Tin nh?n kèm theo giao d?ch
    //struct Date transactionDate;//Ngày giao d?ch (s? d?ng c?u trúc Date)
}Transaction;//Luu tr? chi ti?t giao d?ch tài chính: C?u trúc này luu tr? thông tin v? các giao d?ch tài chính

 typedef struct {
    char userID[20];//Mã ngu?i dùng
    float balance;//S? du tài kho?n
    bool status;//Tr?ng thái tài kho?n (có th? là true/false ho?c ho?t d?ng/khóa)
    //struct Transaction transactionHistory[];//L?ch s? giao d?ch (m?ng các giao d?ch, s? d?ng c?u trúc Transaction)
    char username[10];
    char passwork[10];
}AccountInfo;//Qu?n lý thông tin tài kho?n ngu?i dùng: C?u trúc này luu tr? thông tin tài kho?n c?a ngu?i dùng

 typedef struct {
    bool status;
    char userID[10];//Mã ngu?i dùng
    char name[100];//Tên ngu?i dùng
    Date dateOfBirth[50];//Ngày sinh (s? d?ng c?u trúc Date)
    bool gender;//Gi?i tính
    char phone[11];//S? di?n tho?i
    char email[20];//Ð?a ch? email
}User;//Qu?n lý thông tin cá nhân ngu?i dùng: C?u trúc này luu tr? thông tin cá nhân c?a ngu?i dùng

 typedef struct {
    char email[50];
    char password[10];
}login;
