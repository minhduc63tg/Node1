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
void addLast(List &L, Node *new_ele){
	if(L.first==NULL){
		L.first=L.last= new_ele;
	}
	
	L.last->link= new_ele;
	L.last= new_ele;
}

void InsertLast (List &L, int x){
	Node *p= GetNode(x);
	if(p==NULL){
		return;
	}
	addLast(L,p);
}

void CreateListLast(List &L, int n){
	printf("Nhap %d so nguyen vao danh sach: \n",n);
	for(int i=0;i<n;i++){
		int x;
		scanf("%d",&x);
		InsertLast(L,x);
	}
	printf("\nDa nhap du lieu xong\n");
}
void printList(List L){
	for(Node *p= L.first;p !=NULL;p=p->link){
		printf("%10d ",p->data);
		//printf("%10d ",p->link);
	}
}
int main(){
	List L;
	init(L);
	int n=7;
	CreateListLast(L,n);
	printList(L);
	return 0;
	
}

