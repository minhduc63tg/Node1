#include<cstdio>
#include<iostream>

using namespace std;
struct Node {
	int data;
	Node *link;
};

struct List{
	Node *first, *last;
};

void init(List &L){
	L.first=L.last=NULL;
}
Node *GetNode(int x){
	Node *p;
	p= new Node;
	if(p==NULL) return NULL;
	p->data=x;
	p->link=NULL;
	return p;
}

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

// ham kiem tra trung lap
int isDuplicate(List L, int x) {
    Node* current = L.first;
    while (current != NULL) {
        if (current->data == x) {
            return 1; 
        }
        current = current->link;
    }
    return 0; 
}

void InsertFirst(List &L, int x){
	if(isDuplicate(L,x)){
		printf("co phan tu trung lap");
		return;
	}
	
	Node * new_ele= GetNode(x);
	if(new_ele==NULL){
		return;
	}
	addFirst(L,new_ele);
}

void CreateListFirst(List &L){
	int x;
	printf("\nNhap danh sach cac so nguyen, Nhap -1 de ket thuc: \n");
	do{
		scanf("%d",&x);
		if(x==-1){
			break;
		}
		InsertFirst(L,x);
		
	}while(x!=-1);
	printf("\nDa nhap du lieu xong\n");
}

void printList(List L){
	for(Node *p= L.first;p !=NULL;p=p->link){
		printf("%10d ",p->data);
		//printf("%10d ",p->link);
	}
	printf("\n");
}

void Separating_List(List &L, List &L1, List &L2, int x){
	init(L1);
	init(L2);
	for(Node *p=L.first;p!=NULL;p=p->link){
		if(p->data > x){
			InsertFirst(L1, p->data);
		}
		else{
			InsertFirst(L2, p->data);
		}
	}
}

int main(){
	
	List L;
	init(L);
	CreateListFirst(L);
	List L1,L2;
	
	printList(L);
	int x=5;
	Separating_List(L,L1,L2,x);
	printf("Danh sach L1(cac so lon hon x): \n");
	printList(L1);
	printf("Danh sach L2: (cac so con lai)\n");
	printList(L2);
	return 0;
}

