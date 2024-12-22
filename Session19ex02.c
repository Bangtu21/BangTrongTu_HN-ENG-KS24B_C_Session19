#include<stdio.h>
#include<string.h>
struct SinhVien{
	int id;
	char fullName[50];
	int age;
	char phoneNumber[20];
};
void sapXepSinhVien(struct SinhVien sinhVien[], int n);
void inDanhSach(struct SinhVien sinhVien[], int n);
int main(){
	int n=5;
	struct SinhVien sinhVien[5]={
		{01, "Bang Trong Tu", 19, "0943478560"},
		{02, "Bang De Nhat", 19, "0987654321"},
		{03, "Bang De Nhi", 19, "0123456789"},
		{04, "Bang De Tam", 19, "0567894321"},
		{05, "Bang De Tu", 19, "0432156789"}
	};
	printf("Danh sach ban dau:\n");
	inDanhSach(sinhVien, n);
	sapXepSinhVien(sinhVien, n);
	printf("\nDanh sach sau khi sap xep:\n");
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
//
void sapXepSinhVien(struct SinhVien sinhVien[], int n){
	struct SinhVien temp;
	for(int i=0; i<n-1; i++){
		for(int j=i+1; j<n; j++){
			if(strcmp(sinhVien[i].fullName, sinhVien[j].fullName)>0){
				temp=sinhVien[i];
				sinhVien[i]=sinhVien[j];
				sinhVien[j]=temp;
			}
		}
	}
}

