#include<stdio.h>
#include<time.h>				//�ɤJ�ɶ���� 
int main(void)
{ 
	int i,j,num=0; 				//�ŧi�ܼ� 
	clock_t start,end;			//�ŧi�ɶ��ܼ� 
	double time;				//�ŧi�����B�I�ܼ� 

	printf("��J���N��}�l�p��:\n");	//��J���N��}�l�]�{���X 
	scanf("%d",&num);					//��J���N��}�l�]�{���X	
	start=clock();						//start�s�J�}�l�ɶ� 
	for(i=2;; i++){ 					//�q2�}�l�j�M��� 
		for(j=2; j<=i; j++){ 			//�q��ۤv�p���ƶ}�l�� 
			if(i%j==0)					//��X�O�_��Q��ۤv�p���ƾ㰣 
			break;}						//�Y���󦨥߫h�D���break�X�ӴM��U�@���		 
			if(i==j){ 					//�Y�]�쥻�����ƥN��S���i�㰣���ơA�h����� 
				printf("%d\n",i);		//�L�X��ƭ� 
				end =clock();			//end�s�J�����ɶ� 
				time=(double)(end - start) / CLOCKS_PER_SEC;}	//time�s�J�`�@�g�L�h�[�A���ഫ���� 
				if(time>=10){			//�Y�ɶ��g�L10��hbreak���X�Ҧ��j�� 
					break;				//�Y�ɶ��g�L10��hbreak���X�Ҧ��j��
							}			//�Y�ɶ��g�L10��hbreak���X�Ҧ��j��
					}
	printf("�g�L�ɶ��� %f seconds\n�̫��Ƭ�%d\n",time,i);//��X�g�L�h�[�γ̫��Ƭ��h��  
	printf("\n"); 
	system("pause"); 
	return 0; 
} 

