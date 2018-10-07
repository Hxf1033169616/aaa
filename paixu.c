#include <stdio.h>
#include <curses.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>
#include "err_exit.h"
void BubbleSort(int buf[],int n){//冒泡排序        
        initscr();//创建一个图形窗口
        refresh();//刷新图形窗口
        move(2, 5);//将光标移到(5,2）的位置
        for(int q=0;q<=n;q++){
            printw("%d", buf[q]);//在图形窗口输出字符串
            printw(" ");
        }        
        refresh();//刷新
        sleep(1); //睡眠        
        int m = n-1;
        int flag = 1;                
        while ((m > 0) && flag == 1){
		flag = 0;
		int j = 0;
		while (j <= m){
			if (buf[j] > buf[j + 1]){
				flag = 1;
				clear();//清除屏幕
				move(2, 5);
				int i=0;
				while(i<j){
					printw("%d",buf[i]);
					printw(" ");
					i++;
				}
				attron(A_UNDERLINE);//开启下划
				printw("%d", buf[j]);
				attroff(A_UNDERLINE);//关闭下划线                        
                                printw(" ");
                                attron(A_UNDERLINE);//开启下划线
                                printw("%d", buf[j+1]);
                                attroff(A_UNDERLINE);//关闭下划线
				printw(" ");
                                int k=j+2;
                                while(k<=n){
					printw("%d",buf[k]);
					printw(" ");
					k++;
				}
				refresh();
				sleep(1);
				int t = buf[j];
				buf[j] = buf[j + 1];
				buf[j + 1] = t;
				clear();//清除屏幕
				move(2, 5);                            
                                for(int a=0;a<=n;a++){
					printw("%d", buf[a]);//在图形窗口输出字符串
					printw(" ");
				}      
                                refresh();
                                sleep(1);
			}
			j+=1;
		}
		--m;
	}
	move(2, 5);
	for(int b=0;b<=n;b++){
		printw("%d", buf[b]);//在图形窗口输出字符串
		printw(" ");
	}
	refresh();
	sleep(1);
	move(5,5);
	printw( "BubbleSort, Sort success\n");//查找成功
	refresh();
	sleep(10);
	endwin();//关闭图形窗口            
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

