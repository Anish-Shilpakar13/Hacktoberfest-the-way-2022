// C program to multiply two polynomials using linked list

#include<stdio.h>
#include<stdlib.h>

struct node{

	int co, po;
	struct node *addr;
};

struct node *insertend(struct node *start, int co, int po){

	struct node *temp, *cur;
	temp = (struct node*)malloc(sizeof(struct node));
	temp->co = co;
	temp->po = po;
	temp->addr = NULL;
	if(start == NULL)
		return temp;
	cur = start;
	while(cur->addr != NULL)
	 	cur = cur->addr;
	cur->addr = temp;
	return start;
}

void display(struct node* start){

	struct node* temp;
	if(start == NULL)
		printf("\npolynomial is empty");
	else{
	
		temp = start;
		while(temp->addr != NULL){
		
			printf("%dx^%d + ", temp->co, temp->po);
			temp=temp->addr;
		}
		printf("%dx^%d", temp->co, temp->po);
			
	}
}

 
struct node *addterm(struct node* res, int co, int po){

	struct node *temp, *cur;
	int flag = 0;
	temp = (struct node *)malloc(sizeof(struct node));
	temp->co = co;
	temp->po = po;
	temp->addr = NULL;
	if(res == NULL)//when first term of first pol is multiplied with first term of sec pol
		return temp;
	cur = res;
	while(cur!=NULL){
	
		if(cur -> po == po){
		
			cur->co = cur->co + co;
			flag = 1;	
		}
		cur = cur->addr;
	}
	if(flag == 0){
	
		cur = res;
		while(cur->addr!=NULL)
			cur = cur->addr;
		cur->addr = temp;
	}
	return res;
	
	
	
}
struct node* multiplypoly(struct node *poly1, struct node *poly2){

	struct node *first,*second,*res = NULL;
	for(first = poly1; first != NULL; first = first->addr){
	
		for(second = poly2;second!=NULL; second = second->addr){
		
			res = addterm(res, first->co*second->co, first->po + second->po);
			
		}
	}
	return res;
	
}

void main(){

	struct node* poly1, *poly2, *res;
	int i, n, co, po;
	printf("\nRead no of terms of first polynomial");
	scanf("%d",&n);
	for(i = 1; i <= n; i++){
	
		printf("\nRead co and no of terms of first polynomial");
		scanf("%d%d",&co, &po);
		poly1 = insertend(poly1, co, po);
	}
	printf("\nThe first polynomial is \n");
	display(poly1);
	printf("\nRead no of terms of second polynomial");
	scanf("%d",&n);
	for(i = 1; i <= n; i++){
	
		printf("\nRead co and no of terms of second polynomial");
		scanf("%d%d",&co, &po);
		poly2 = insertend(poly2, co, po);
	}
	printf("\nThe second polynomial is \n");
	display(poly2);
	res = multiplypoly(poly1, poly2);
	printf("\nThe resultant polynomial is\n");
	display(res);
	
	
	
	
}



