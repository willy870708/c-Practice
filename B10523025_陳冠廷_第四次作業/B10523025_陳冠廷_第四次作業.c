#include <stdio.h>
#include <stdlib.h>

typedef struct linklist{
    int val;                         //�Ȧs0�M1�A0=��W 1=�U��
    char str;                        //�s�Jo�Mx���� 
    struct linklist *next;				
    struct linklist *pre;
}node;

node *get_node(node *headp,char data);
int findO(node *headp);
void reset(node *headp);
void printlist(node *headp);


node *get_node(node *headp,char data){
    node *new = (node *)malloc(sizeof(node)); //�Ф@��new�����аO����Ŷ� 
    new->str = data;
    new->val = 0;
    new->next = NULL;
    new->pre = NULL;
    if(headp == NULL){						//�Y�Y�`�I��NULL  
        headp = new;						//new���Цs�J�Y�`�I 
        headp->next = NULL;
		headp->pre = NULL;					//�Y�`�I���V�U�@�Ӹ`�I��NULL 
    }else{									//�Y�Y�`�I�S���VNULL 
        node * p = headp;					//�]�t�@�ӫ���p�ç��Y�`�I�s�J 
        while (p->next != NULL){			//�����p���V�@�Ӹ`�I����NULL 
            p = p->next;					//����p���V�U�@�Ӹ`�I
            
        }
        new ->pre=p;						//�s���`�I���e����e�@�Ӹ`�I 
        p->next = new;						//�챵�s���`�I
    }
    return headp;
}

int findO(node *headp)                    //�P�_�O�_�٦�����o�b��W�A���htrue
{
    node *tmp = headp;
    while(tmp->next != NULL)
    {
        if((tmp->str == 'o' || tmp->str == 'O' )&& tmp->val != 1)
            return 1;
        tmp = tmp->next;
    }
    if((tmp->str == 'o' || tmp->str == 'O' )&& tmp->val != 1)
            return 1;
    return 0;
}

void reset(node *headp)
{
    node *p = headp;
    while(p->next !=NULL)
    {
        if(p->str == 'o' || p->str =='O')            //�Ҧ�o��val = 0,�Y�W��
        {
            p->val = 0;
        }
        p = p->next;
    }
    p->val = 0;
}
int getrear(node *headp){							//���o���`�I 
	 node * a=headp;
	 while(a->next!=NULL){
	 a=a->next;
	 }
	 return a;
}
int main(void){
    node *headp = NULL;//�Y�`�I
    char input[1000];
    int MagicNum = 1,i;
    int side = 1;
    printf("�п�J�n�Ho�a�Hx:\n");
    scanf("%[^\n]",input);
    char *str = input;
    while(*str != 32 ? headp = get_node(headp, *str) : NULL ,str++,*str!='\0');    //��J����Ÿ��h�����j��
    node *p = headp;
    node *r = getrear(headp);  						//���o���`�I 
    while (findO(headp))							//�Y�r�ꤤ�٦�o�n�H�h����]�j�� 
    {
        for (i = 0; i < MagicNum; i++)				 
        {
            if(side){								 
			p = p->next;							//�쵲�����`�I��V�� 
            if(p == NULL)							//�Y����NULL 
                p = headp;							//�h�^���Y�`�I 
            if (p->val == 1)						 
                i--;
			}
			else{									 
			p = p->pre;								//�쵲���Y�`�I��V��
            if(p == NULL)							//�Y����NULL 
                p = r;								//�h�^����`�I 
            if (p->val == 1)
                i--;	
			}
        }
        if(p->str == 'o' || p->str == 'O'  )		//�Y���o�n�H�h�쵲���Ϥ�V��
        {
            p->val=1;
            if(side){
            side= 0;
			}
			else{
			side= 1;
			}
        }else                            //�Y�Do�n�H���Y�A�]�@���AMagicNum�֥[
        {
            reset(headp);
            MagicNum++;
            p = headp;
        }
    }
    printf("���_�Ʀr:%d\n",MagicNum);
    system("pause");
    return 0;
}
