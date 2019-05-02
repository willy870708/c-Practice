#include<stdio.h>
#include<time.h>				//導入時間函數 
int main(void)
{ 
	int i,j,num=0; 				//宣告變數 
	clock_t start,end;			//宣告時間變數 
	double time;				//宣告雙倍浮點變數 

	printf("輸入任意鍵開始計時:\n");	//輸入任意鍵開始跑程式碼 
	scanf("%d",&num);					//輸入任意鍵開始跑程式碼	
	start=clock();						//start存入開始時間 
	for(i=2;; i++){ 					//從2開始搜尋質數 
		for(j=2; j<=i; j++){ 			//從比自己小的數開始除 
			if(i%j==0)					//找出是否能被比自己小的數整除 
			break;}						//若條件成立則非質數break出來尋找下一位數		 
			if(i==j){ 					//若跑到本身的數代表沒有可整除的數，則為質數 
				printf("%d\n",i);		//印出質數值 
				end =clock();			//end存入結束時間 
				time=(double)(end - start) / CLOCKS_PER_SEC;}	//time存入總共經過多久，並轉換成秒 
				if(time>=10){			//若時間經過10秒則break跳出所有迴圈 
					break;				//若時間經過10秒則break跳出所有迴圈
							}			//若時間經過10秒則break跳出所有迴圈
					}
	printf("經過時間為 %f seconds\n最後質數為%d\n",time,i);//輸出經過多久及最後質數為多少  
	printf("\n"); 
	system("pause"); 
	return 0; 
} 

