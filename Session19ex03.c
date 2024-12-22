#include<stdio.h>
#include<string.h>
struct SinhVien{
	int id;
	char fullName[50];
	int age;
	char phoneNumber[20];
};
void inDanhSach(struct SinhVien sinhVien[], int *n);
//
void themSinhVien(struct SinhVien sinhVien[], int *n);
//
void suaSinhVien(struct SinhVien sinhVien[], int n);
//
void xoaSinhVien(struct SinhVien sinhVien[], int *n);
//
void timSinhVien(struct SinhVien sinhVien[], int n);
//
void sapXepDanhSach(struct SinhVien sinhVien[], int n);
//
int main(){
	struct SinhVien sinhVien[100]={
		{01, "Bang Trong Tu", 19, "0943478560"},
		{02, "Bang De Nhat", 19, "0987654321"},
		{03, "Bang De Nhi", 19, "0123456789"},
		{04, "Bang De Tam", 19, "0567894321"},
		{05, "Bang De Tu", 19, "0432156789"}
	};
	int choice;
	int n=5;
	do{
		printf("MENU\n");
		printf("1. Hien thi danh sach sinh vien\n");
		printf("2. Them sinh vien\n");
		printf("3. Sua thong tin sinh vien\n");
		printf("4. Xoa sinh vien\n");
		printf("5. Tim kiem sinh vien\n");
		printf("6. Sap xep danh sach sinh vien\n");
		printf("7. Thoat\n");
		printf("Lua chon cua ban: ");
		scanf("%d", &choice);
		switch(choice){
			case 1:
				inDanhSach(sinhVien, &n);
				break;
			case 2:
				themSinhVien(sinhVien, &n);
				break;
			case 3: 
				suaSinhVien(sinhVien, n);
				break;
			case 4:
				xoaSinhVien(sinhVien, &n);
				break;
			case 5:
				timSinhVien(sinhVien, n);
				break;
			case 6:
				sapXepDanhSach(sinhVien, n);
				break;
		}
	}while(choice!=7);
}
//
//
void inDanhSach(struct SinhVien sinhVien[], int *n){
	printf("Danh sach sinh vien:\n");
	for(int i=0; i<*n; i++){
		printf("\nId: %d\nHo va ten: %s\nTuoi: %d\nSo dien thoai: %s\n\n", sinhVien[i].id, sinhVien[i].fullName, sinhVien[i].age, sinhVien[i].phoneNumber);
	}
}
//
void themSinhVien(struct SinhVien sinhVien[], int *n){
	struct SinhVien sinhVienMoi; 
	printf("Ban hay nhap thong tin sinh vien moi:\n");
	printf("Id sinh vien moi: ");
	scanf("%d", &sinhVienMoi.id);
	fflush(stdin);
	
	printf("Ho va ten cua sinh vien moi: ");
	fgets(sinhVienMoi.fullName, sizeof(sinhVienMoi.fullName), stdin);
	
	printf("Tuoi cua sinh vien moi: ");
	scanf("%d", &sinhVienMoi.age);
	fflush(stdin);
	
	printf("So dien thoai cua sinh vien moi: ");
	fgets(sinhVienMoi.phoneNumber, sizeof(sinhVienMoi.phoneNumber), stdin);
	
	sinhVien[*n]=sinhVienMoi;
	(*n)++;
	printf("Danh sach sau khi them sinh vien moi:\n");
	for(int i=0; i<*n; i++){
		printf("\nId: %d\nHo va ten: %s\nTuoi: %d\nSo dien thoai: %s\n", sinhVien[i].id, sinhVien[i].fullName, sinhVien[i].age, sinhVien[i].phoneNumber);
	}
}
//
void suaSinhVien(struct SinhVien sinhVien[], int n){
	int sua;
	int count=0;
	printf("Nhap id sinh vien muon sua: ");
	scanf("%d", &sua);
	fflush(stdin);
	for(int i=0; i<n; i++){
		if(sinhVien[i].id==sua){
			count=1;
			printf("Nhap thong tin moi:\n");
			printf("Ho va ten: ");
			fgets(sinhVien[i].fullName, sizeof(sinhVien[i].fullName), stdin);
			
			printf("Tuoi: ");
			scanf("%d", &sinhVien[i].age);
			fflush(stdin);
			
			printf("So dien thoai: ");
			fgets(sinhVien[i].phoneNumber, sizeof(sinhVien[i].phoneNumber), stdin);
			printf("Danh sach sinh vien sau khi sua thong tin la:\n");
			for(int i=0; i<n; i++){
				printf("\nId: %d\nHo va ten: %s\nTuoi: %d\nSo dien thoai: %s\n", sinhVien[i].id, sinhVien[i].fullName, sinhVien[i].age, sinhVien[i].phoneNumber);
			}
		}
	}
	if(count==0){
		printf("Id khong ton tai\n");
	}
}
//
void xoaSinhVien(struct SinhVien sinhVien[], int *n){
	int xoa;
	int count=0;
	printf("Nhap id sinh vien muon xoa: ");
	scanf("%d", &xoa);
	for(int i=0; i<*n; i++){
		if(sinhVien[i].id==xoa){
			count=1;
			for(int j=i; j<*n-1; j++){
				sinhVien[j]=sinhVien[j+1];
			}
			(*n)--;
			printf("Danh sach sinh vien sau khi xoa:\n");
			for(int i=0; i<*n; i++){
				printf("\nId: %d\nHo va ten: %s\nTuoi: %d\nSo dien thoai: %s\n", sinhVien[i].id, sinhVien[i].fullName, sinhVien[i].age, sinhVien[i].phoneNumber);
			}
		}
	}
	if(count==0){
		printf("Id khong ton tai\n");
	}
}
//
void timSinhVien(struct SinhVien sinhVien[], int n){
	int search;
	int count=0;
	printf("Ban hay nhap id muon tim: ");
	scanf("%d", &search);
	for(int i=0; i<n; i++){
		if(sinhVien[i].id==search){
			count=1;
			printf("\nId: %d\nHo va ten: %s\nTuoi: %d\nSo dien thoai: %s\n", sinhVien[i].id, sinhVien[i].fullName, sinhVien[i].age, sinhVien[i].phoneNumber);
		}
	}
	if(count==0){
		printf("Khong tim thay sinh vien nao co id can tim\n");
	}
}
//
void sapXepDanhSach(struct SinhVien sinhVien[], int n){
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
	printf("Danh sach sau khi sap xep la:\n");
	for(int i=0; i<n; i++){
		printf("\nId: %d\nHo va ten: %s\nTuoi: %d\nSo dien thoai: %s\n", sinhVien[i].id, sinhVien[i].fullName, sinhVien[i].age, sinhVien[i].phoneNumber);
	}
}































