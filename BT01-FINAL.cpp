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


void nhap(NhanVien dsNV[], int n) {
    for (int i = 0; i < n; i++) {
        printf("\n--- Nhap thong tin nhan vien thu %d ---\n", i + 1);

        printf("Ma nhan vien: ");
        scanf("%9s", dsNV[i].maNV);

        printf("Ten nhan vien: ");
        scanf(" "); 
        fgets(dsNV[i].tenNV, sizeof(dsNV[i].tenNV), stdin);
       
        dsNV[i].tenNV[strcspn(dsNV[i].tenNV, "\n")] = '\0';

        printf("Luong co ban: ");
        scanf("%f", &dsNV[i].luongCoBan);

        printf("He so: ");
        scanf("%f", &dsNV[i].heSo);
    }
}

float tinhLuongThucNhan(NhanVien nv) {
    return nv.luongCoBan * nv.heSo;
}

void xuat(NhanVien dsNV[], int n) {
    printf("\n%-10s%-20s%-15s%-10s%-15s\n",
           "Ma NV", "Ten NV", "Luong CB", "He so", "Thuc nhan");
    printf("--------------------------------------------------------------\n");
    for (int i = 0; i < n; i++) {
        printf("%-10s%-20s%-15.2f%-10.2f%-15.2f\n",
               dsNV[i].maNV,
               dsNV[i].tenNV,
               dsNV[i].luongCoBan,
               dsNV[i].heSo,
               tinhLuongThucNhan(dsNV[i]));
    }
}

int main() {
    NhanVien dsNV[MAX];
    int n;

    printf("Nhap so luong nhan vien: ");
    scanf("%d", &n);

    if (n <= 0 || n > MAX) {
        printf("So luong nhan vien khong hop le!\n");
        return 1;
    }

    nhap(dsNV, n);
    xuat(dsNV, n);

    return 0;
}
