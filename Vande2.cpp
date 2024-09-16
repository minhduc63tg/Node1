#include<cstdio>
#include<iostream>

using namespace std;
// dinh ngia cau truc Node va List
struct Node {
	int data;
	Node *link;
};

struct List{
	Node *first, *last;
};
// Ham tao danh sach rong
void init(List &L){
	L.first=L.last=NULL;
}
// Tao mot Node moi voi du lieu la x
Node *GetNode(int x){
	Node *p;
	p= new Node;
	if(p==NULL) return NULL;
	p->data=x;
	p->link=NULL;
	return p;
}
// them mot Node vao dau danh sach
void addFirst(List &L, Node* new_ele){
	if(L.first==NULL){
		L.first= new_ele;
		L.last= L.first;
	}
	
	else{
		new_ele->link= L.first;
		L.first= new_ele;
	}
}
// them mot Node chua du lieu x vao dau danh sach
void InsertFirst(List &L, int x){
	Node * new_ele= GetNode(x);
	if(new_ele==NULL){
		return;
	}
	addFirst(L,new_ele);
}
// tao danh sach bang cach them vao dau danh sach
void CreateListFirst(List &L){
	int x;
	do{
		printf("\nNhap danh sach cac so nguyen, Nhap -1 de ket thuc: \n");
		
		scanf("%d",&x);
		if(x==-1){
			break;
		}
		InsertFirst(L,x);
		
	}while(x!=-1);
	printf("\nDa nhap du lieu xong\n");
}
//  xuat danh sach 
void printList(List L){
	for(Node *p= L.first;p !=NULL;p=p->link){
		printf("%10d ",p->data);
		
		//printf("%d ", p);
	}
}
// ham tra ve tong cac phan tu la so chan
int SumEven(List L){
	int sum=0;
	for(Node *p= L.first;p !=NULL;p=p->link){
		if(p->data %2==0){
			sum+=p->data;
		}
	}
	return sum;
}
// ham tim kiem phan tu x trong danh sach
Node *Search(List L,int x){
	for(Node *p= L.first;p !=NULL;p=p->link){
		if(p->data== x){
			return p;
		}
	}
	return NULL;
}
int main(){
	List L;
	init(L);
	CreateListFirst(L);
	printList(L);
	
	int k;
	printf("\nNhap gia tri can tim: ");
	scanf("%d",&k);
	Node *p= Search(L,k);
	if(p!=NULL){
		printf("\nTim thay gia tri %d",k);
	}
	else{
		printf("\nKhong tim thay gia tri %d",k);
	}

	return 0;
}















