#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100
typedef struct {
    char maNV[10];
    char tenNV[50];
    float luongCoBan;
    float heSo;
} NhanVien;
int main() {
    NhanVien dsNV[MAX];
    int n;
    printf("Nhap so luong nhan vien: ");
    scanf("%d", &n);
    return 0;
}
