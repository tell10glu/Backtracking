#include <stdio.h>
#include <stdlib.h>
#define TRUE 1
#define FALSE 0
typedef struct{
	int x;
	int y;
}Point;
typedef struct{
	Point * list;
	int top;
	int capacity;
}Stack;
void push(Point ,Stack*);
Stack* init(int);
int isEmpty(Stack*);
int isFull(Stack*);
void printStack(Stack *s);
Point pop(Stack*);
void clearStack(Stack *);
void PrintMatrix(int*,int);
int BackTracking(int,int*,Stack*);
int isAllowed(int* mtr,int n,int row,int column);
int main(){
	int n;
	printf("Please Enter N*N Of Table :");
	scanf("%d",&n);
	if(n<=0){
		printf("n must be bigger than 0 \n");
		exit(-1);
	}
	int * matris = (int*)malloc(sizeof(int)*n);
	int i ;
	for(i=0;i<n;i++){
		matris[i]=-1;
	}
	Stack * stack = init(200);
	int result = BackTracking(n,matris,stack);
	if(result != TRUE)
		printf("No Result!!!!\n");
	free(matris);
	clearStack(stack);
	return 0;
}
int BackTracking(int n,int * mtr,Stack* stack){
	int count = 0;
	do{
		Point pnt ;
		pnt.x = count;
		pnt.y = 0;
		push(pnt,stack);
		count++;
		if(!isAllowed(mtr,n,pnt.x,pnt.y) && !isEmpty(stack)){
			int isAdded = FALSE;
			while(!isAdded && !isEmpty(stack)){
				Point pnt2 = pop(stack);
				count --;
				pnt2.y++;
				while(pnt2.y<n &&!isAllowed(mtr,n,pnt2.x,pnt2.y)){
					pnt2.y++;
				}
				if(pnt2.y!=n){
					push(pnt2,stack);
					mtr[pnt2.x] = pnt2.y;
					count++;
					isAdded = TRUE;
				}else{
					mtr[pnt2.x] = -1;
				}
			}
		}else{
			mtr[pnt.x] = pnt.y;
		}
		PrintMatrix(mtr,n);
		printStack(stack);
	}while(count<n &&!isEmpty(stack));
	if(isEmpty(stack)){
		return FALSE;
	}
	return TRUE;
}
int isAllowed(int* matris,int n,int row,int column){
	int i =0;
	int x=row;
	int y=column;
   x--;
   y++;
   while(x>=0 && y<n){//sag yukarı
             if(matris[x]==y){
		    			return FALSE;
              }
        x--;
        y++;
   }
	x=row;
	y=column;
   x--;
   y--;
        while(x>=0 && y>=0){// sol yukarı
             if(matris[x]==y){
		     return FALSE;
          }
                x--;
                y--;
        }
	x = row;
	y = column;
	x--;
   while(x>=0){//yukari
         if(matris[x]==y){
		     return FALSE;
             }
                x--;
        }
	return TRUE;
	
}
void PrintMatrix(int* liste,int n){
	int i,j;
	for(i=0;i<n;i++){
		for(int j=0;j<liste[i];j++)
			printf("( )");
		if(liste[i]!=-1)
		printf("(V)");
		
		for(int j =liste[i]+1;j<n;j++)
			printf("( )");
		printf("\n");
	}
}
void push(Point val,Stack* s){
	if(!isFull(s)){
		s->list[++s->top] = val;
	}
}
Stack* init(int capacity){
	Stack * stack = (Stack*)malloc(sizeof(Stack));
	stack->top = -1;
	stack->capacity = capacity;
	stack->list = (Point*)calloc(sizeof(Point),stack->capacity);
	return stack;
}
int isEmpty(Stack* s){
	if(s->top==-1)
		return TRUE;
	return FALSE;
}
int isFull(Stack* s){
	if(s->top ==s->capacity)
		return TRUE;
	return FALSE;
}
Point pop(Stack *s){
	if(!isEmpty(s)){
		return s->list[s->top--];
	}
	Point pnt;
	pnt .x = -1;
	pnt.y = -1;
	return pnt;
}
void printStack(Stack *s){
	int i =0;
	printf("Stack:|");
	while(i<=s->top){
		printf("%d,%d|",s->list[i].x,s->list[i].y);
		i++;
	}
	printf("\n");
}
void clearStack(Stack *s){
	while(!isEmpty(s)){
		pop(s);
	}
}
