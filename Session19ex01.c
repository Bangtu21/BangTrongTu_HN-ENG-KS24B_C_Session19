#include<stdio.h>
struct SinhVien{
	int id;
	char fullName[50];
	int age;
	char phoneNumber[20];
};
void inDanhSach(struct SinhVien sinhVien[], int n);
void deleteSinhVien(struct SinhVien sinhVien[], int *n, int id);
int main(){
	int n=5;
	int deleteStudent;
	struct SinhVien sinhVien[5]={
		{01, "Bang Trong Tu", 19, "0943478560"},
		{02, "Bang De Nhat", 19, "0987654321"},
		{03, "Bang De Nhi", 19, "0123456789"},
		{04, "Bang De Tam", 19, "0567894321"},
		{05, "Bang De Tu", 19, "0432156789"}
	};
	inDanhSach(sinhVien, n);
	printf("\nBan hay nhap id can xoa: ");
	scanf("%d", &deleteStudent);
	deleteSinhVien(sinhVien, &n, deleteStudent);
	inDanhSach(sinhVien, n);
}
//
//
void inDanhSach(struct SinhVien sinhVien[], int n){
	printf("Danh sach sinh vien:\n");
	for(int i=0; i<n; i++){
		printf("\nId: %d\nHo va ten: %s\nTuoi: %d\nSo dien thoai: %s\n", sinhVien[i].id, sinhVien[i].fullName, sinhVien[i].age, sinhVien[i].phoneNumber);
	}
}
void deleteSinhVien(struct SinhVien sinhVien[], int *n, int id){
	int count=0;
	for(int i=0; i<*n; i++){
		if(sinhVien[i].id==id){
			count=1;
			for(int j=i; j<*n-1; j++){
				sinhVien[j]=sinhVien[j+1];
			}
			(*n)--;
		}
	}
	if(count==0){
		printf("Id sinh vien can xoa khong ton tai\n");
	}
}
