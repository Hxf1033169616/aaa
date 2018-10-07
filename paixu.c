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
void SimpleSelection(int buf[],int n){//简单选择排序
	initscr();
    	refresh();
    	move(2, 5);
    	for(int b=0;b<=n;b++){
    		printw("%d", buf[b]);//在图形窗口输出字符串
    		printw(" ");
    	}
    	refresh();
    	sleep(1);
	int i = 0;             
        while (i <= n ){
		int k = i;
		int j = i + 1;
      		while (j <= n ){
			if (buf[j] < buf[k]) k = j;
    			j+=2;
		}
		if (k != i){
    			clear();
    			move(2, 5);
    			int m=0;
    			int d=i+1;
    			int a=k+1;
    			while(m<i){
				printw("%d", buf[m]);
				printw(" ");
				m++;
    			}
    			attron(A_UNDERLINE);
    			printw("%d", buf[i]);
    			attroff(A_UNDERLINE);
    			printw(" ");
    			while(d<k){
				printw("%d", buf[d]);
				printw(" ");
				d++;
    			}
    			attron(A_UNDERLINE);
    			printw("%d", buf[k]);
    			attroff(A_UNDERLINE);
    			printw(" ");
    			while(a<=n){
				printw("%d", buf[a]);
				printw(" ");
				a++;
    			}
    			refresh();
    			sleep(1);
    			int t = buf[i];
    			buf[i] = buf[k];
    			buf[k] = t;
		}
		clear();             
                move(2, 5);
    		for(int s=0;s<=n;s++){
	 		printw("%d", buf[s]);//在图形窗口输出字符串
	 		printw(" ");
    		}
    		refresh();
    		sleep(1);
   		i++;
	}
    	move(2, 5);
    	for(int q=0;q<=n;q++){
    		printw("%d", buf[q]);//在图形窗口输出字符串
    		printw(" ");
    	}
    	refresh();
    	sleep(1);
	move(5,5);
    	printw(" Simple Selection Sort, Sort success\n");
	refresh();
    	sleep(2);
    	endwin();   
}
void StraightInsertion(int buf[],int n){//直接插入排序
	initscr();
    	refresh();
    	move(2, 5);
    	for(int b=0;b<=n;b++){
    		printw("%d", buf[b]);//在图形窗口输出字符串
    		printw(" ");
    	}
    	refresh();
    	sleep(1);
    	int i=1;  
        while(i<=n){
		if(buf[i]<buf[i-1]){
	    		int t;
	    		t=buf[i];
	    		buf[i]=buf[i-1];
	    		int j=i-2;
	    		while(t<buf[j]&&j>=0){
				buf[j+1]=buf[j]; 
				j--;
	    		}
	    		buf[j+1]=t;
		}
		clear();
		move(2, 5);
		int k=0;
		int m=i+1;
		while(k<i){
	    		printw("%d", buf[k]);
	    		printw(" ");
	    		k++;
		}
		
		attron(A_UNDERLINE);
        printw("%d", buf[i]);
		attroff(A_UNDERLINE);
		printw(" ");
		while(m<=n){
	    		printw("%d", buf[m]);
                printw(" ");
	    		m++;
		}
		refresh();
		sleep(1);
		i++;
    	}
    	move(2, 5);
    	for(int q=0;q<=n;q++){
    		printw("%d", buf[q]);//在图形窗口输出字符串
    		printw(" ");
    	}
    	refresh();
    	sleep(1);
    	move(5,5);
    	printw(" Straight Insertion Sort, Sort success\n"); 
    	refresh();
    	sleep(2);
    	endwin(); 
}
void SequentialSearch(int a,int buf[],int n){//顺序查找
	initscr();
	move(2, 5);
	for(int q=0;q<=n;q++){
    		printw("%d", buf[q]);//在图形窗口输出字符串    
		printw(" ");
    	}    
	refresh();
        sleep(1);
	int i = 0;
	int j=0;
        int t=5;
	while (i <= n){
		clear();
		move(2, 5);
		for(int b=0;b<=n;b++){
			printw("%d", buf[b]);//在图形窗口输出字符串
			printw(" ");
		}
		int k=0;
		int r=buf[i];
		while(r>0){
			r=r/10;
			k++;
		}
		if(i==0){
			move(1, 5);
			t=t+k+1;
		}else{
			move(1, t);
			t=t+k+1;
		}
		printw("%d", a);
		refresh();
		sleep(1);
		if (buf[i]==a){
			j=1;
			move(5, 5);
			printw( "Sequential Search,Find success\n");
			refresh();
			sleep(5);
			break;
		}
		i+=1;
	}
	if(j==0){
		move(5, 5);
		printw( "Sequential Search,Find failure\n");
		refresh();
		sleep(1);
	}       		
	sleep(2);
	endwin();   
}
void BinarySearch(int a,int buf[],int n){//折半查找
    printf("The following is a Binary Search,please confirm whether it has been orderd?[Y/n]");//这个数组是否已经排序，若没，请排序
    char s;
    scanf("%c", &s);
	getchar();
	if (s == 'Y'){

	}
	else{
		StraightInsertion(buf,n);
	}
	initscr();
	move(2, 5);
	for(int b=0;b<=n;b++){
    		printw("%d", buf[b]);//在图形窗口输出字符串
    		printw(" ");        
    }     
	refresh();
    sleep(1);	
	int low = 0;
	int high = n;
	int i=0;
	while (low <= high){
		int mid = (low + high) / 2;
		clear();
		move(2, 5);
		for(int q=0;q<=n;q++){
			printw("%d", buf[q]);//在图形窗口输出字符串
			printw(" ");
		}
		int d=0;
		int k;
		int c=5;
		while(d<mid){
			k=buf[d];
			while(k>0){
				k=k/10;
				c++;
			}
			c++;
			d++;
		}
		move(1,c);
		printw("%d", a);
		refresh();
		sleep(1);
		if (a == buf[mid]){
			i=1;
			move(5, 5);
			printw("Binary Search,Find success\n");
			refresh();
                        sleep(5);
			break;
		}
		else if (a < buf[mid]){
			high = mid-1;
		}
		else{
			low = mid+1;
		}
	}
	if(i==0){
		move(5, 5);
	        printw(" Binary Search, Find failure\n");
	     	refresh();	
                sleep(1);
	}
	sleep(2);
	endwin(); 	    
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

