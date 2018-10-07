#include <stdio.h>
#include <curses.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>
#include "err_exit.h"
void BubbleSort(int buf[],int n){
}
void SimpleSelection(int buf[],int n){
}
void StraightInsertion(int buf[],int n){
}
void SequentialSearch(int a,int buf[],int n){
}
void BinarySearch(int a,int buf[],int n){
}
int main()
{
	srand((unsigned int)(time(NULL)));
    	printf("This is an algorithm for finding and sorting.\nDo you want to continue?[Y/n]");//这是一个查找和排序的程序，你想继续下去吗
    	char s;
    	char a;
    	int b;
    	int t,n;
    	scanf("%c",&s);
    	getchar();
    	if(s=='Y'){
    	}else{
       		exit(1);
    	}
    	int m[40];
    	FILE* pf= fopen("test_file","r");
    	int i=0;
    	while(!feof(pf))
    	{
	 	fscanf(pf,"%d",&m[i]);
	 	i++;
    	} 
     	fclose(pf);
    	printf("Do you want to Find or Sort?\nPrompting for other charcters will exit the program.[F/S]");//你想查找还是排序，请输入F或S，输入其他字符将会退出程序
    	scanf("%c",&a);
    	getchar();
    	if(a=='F'){
	   	printf("Which one do you want to find?");     //你想查找那个数字
	   	scanf("%d",&b);
	   	getchar();
	   	n=rand() % 2;
	   	if(n==0){
			SequentialSearch(b,m,i-2);
       		}else{
			BinarySearch(b,m,i-2);
       		}
    	}else if(a=='S'){
		t=rand() % 3;
		if(t==0){
			BubbleSort(m,i-2);
		}else if(t==1){
			SimpleSelection(m,i-2);
		}else{
			StraightInsertion(m,i-2);
		}
    	}else{
		exit(1);//退出程序
	}
    	return 0;
}

