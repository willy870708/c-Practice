    #include<stdio.h>
    #include<math.h>
    int main(){
       double ans=0,c,copy=0.0,input=0.0,x=0.0;   									//�ŧians copy �����B�I�� 
       int squart;      									//�ŧisquart input ����� 
       printf("�п�JX��(��������0~1)�G");									//��JX�� 
       scanf("%lf",&input);										//��JX��
       for(squart=1;;squart++){						//����}�l�]	
         if(squart%2==1){										//�_�Ʀ��趵�ۥ[ 
                ans=ans+(pow(input,squart))/squart;            //�_�Ʀ��趵�ۥ[
				}	       										//�_�Ʀ��趵�ۥ[
                        else if(squart%2==0){					//���Ʀ��趵�۴� 
                             ans=ans-(pow(input,squart))/squart;//���Ʀ��趵�۴�
                                             }                  //���Ʀ��趵�۴�
                        if(x==ans)    {                        //�Y���׻P�W�@�ӵ��פ@�ˤθ��X�j��ǥX���� 
										break;	              //�Y���׻P�W�@�ӵ��פ@�ˤθ��X�j��ǥX����  
												}             //�Y���׻P�W�@�ӵ��פ@�ˤθ��X�j��ǥX���� 
												x=ans;	      //�HX�s�J�e�@�ӵ��ת��� 
					}
					printf("���G�O%f\n",ans);		//�C�L�X�̫ᤧ��
					system("pause");
					}
					           
                    
                                
                      
