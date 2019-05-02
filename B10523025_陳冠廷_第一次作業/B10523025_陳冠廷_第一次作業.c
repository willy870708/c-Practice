    #include<stdio.h>
    #include<math.h>
    int main(){
       double ans=0,c,copy=0.0,input=0.0,x=0.0;   									//宣告ans copy 為雙浮點數 
       int squart;      									//宣告squart input 為整數 
       printf("請輸入X值(必須介於0~1)：");									//輸入X值 
       scanf("%lf",&input);										//輸入X值
       for(squart=1;;squart++){						//次方開始跑	
         if(squart%2==1){										//奇數次方項相加 
                ans=ans+(pow(input,squart))/squart;            //奇數次方項相加
				}	       										//奇數次方項相加
                        else if(squart%2==0){					//偶數次方項相減 
                             ans=ans-(pow(input,squart))/squart;//偶數次方項相減
                                             }                  //偶數次方項相減
                        if(x==ans)    {                        //若答案與上一個答案一樣及跳出迴圈傳出答案 
										break;	              //若答案與上一個答案一樣及跳出迴圈傳出答案  
												}             //若答案與上一個答案一樣及跳出迴圈傳出答案 
												x=ans;	      //以X存入前一個答案的值 
					}
					printf("結果是%f\n",ans);		//列印出最後之值
					system("pause");
					}
					           
                    
                                
                      
