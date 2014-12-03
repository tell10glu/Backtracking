#include <stdio.h>
#include <stdlib.h>
#define TRUE 1
#define FALSE 0
#define VEZIRVAR 1
#define VEZIRYOK 0
void matrisiyazdir(int*,int);
int BackTracking(int n,int ** mtr, int row,int* yazdir,int indis);
int tahtayakoyulabilirmi(int row,int column,int** mtr,int n);
int main(){
	int n;
	printf("Kac Satirlik Bir tahta olusturulsun");
	scanf("%d",&n);
	int ** matris = (int**)malloc(sizeof(int*)*n);
	int i;
	for(i=0;i<n;i++){
		matris[i] = (int*)malloc(sizeof(int)*n);
	}
	int * liste = (int*)malloc(sizeof(int)*n);
	int sonuc = BackTracking(n,matris,0,liste,0);
	if(sonuc==TRUE)
	matrisiyazdir(liste,n);
	else
		printf("Sonuc Bulunamadi");
	
	free(liste);
	for(i=0;i<n;i++){
		free(matris[i]);
	}
	free(matris);
	return 0;
}
int BackTracking(int n,int ** mtr, int row,int *yazdir,int indis){
	if(row<n){
		int i;
		for(i=0;i<n;i++){
			yazdir[indis]=i;
			//printf("%d.row %d.kolon matris[x][y]=%d\n******\n",row,i,mtr[row][i]);
			if(tahtayakoyulabilirmi(row,i,mtr,n)){
				//printf("Tahtaya Koyuldu %d.row,%d.kolon\n",row,i);
				mtr[row][i]=VEZIRVAR;
				int val;
				val = BackTracking(n,mtr,row+1,yazdir,indis+1);
				if(val==TRUE)
					return val;
				else{
					mtr[row][i]=VEZIRYOK;
				}
			}
			
			
		}
		return FALSE;
	}else
		return TRUE;
	
}
int tahtayakoyulabilirmi(int row,int column,int** matris,int n){
	int i =0;
	int x=row;
	int y=column;
        x--;
        y++;
        while(x>=0 && y<n){//sag yukarı
             if(matris[x][y]==VEZIRVAR){
		     return FALSE;
                }
                x--;
                y++;
        }
	/*x=row;
	y=column;
        x++;
        y++;
        while(x<n && y<n){//sag asagi
             if(matris[x][y]==VEZIRVAR){
		     return FALSE;
                }
                x++;
                y++;
        }*/
	x=row;
	y=column;
        x--;
        y--;
        while(x>=0 && y>=0){// sol yukarı
             if(matris[x][y]==VEZIRVAR){
		     return FALSE;
                }
                x--;
                y--;
        }
	/*
	x=row;
	y=column;
        x++;
        y--;
        while(x<n && y>=0){//sol asagi
             if(matris[x][y]==VEZIRVAR){
		     return FALSE;
                }
                x++;
                y--;
        }*/
	x = row;
	y = column;
	x--;
        while(x>=0){//yukari
		//printf("X : %d,Y:%d matris[x][y]=%d\n",x,y,matris[x][y]);
             if(matris[x][y]==VEZIRVAR){
		     return FALSE;
             }
                x--;
        }
	return TRUE;
	
}
void matrisiyazdir(int* liste,int n){
	int i,j;
	for(i=0;i<n;i++){
		for(int j=0;j<liste[i];j++)
			printf("( )");
		printf("(V)");
		for(int j =liste[i]+1;j<n;j++)
			printf("( )");
		printf("\n");
	}
}
