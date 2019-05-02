#include <stdio.h>
#include <stdlib.h>

typedef struct linklist{
    int val;                         //�Ȧs0�M1�A0=��W 1=�U��
    char str;                        //�s�Jo�Mx���� 
    struct linklist *next;
}node;

node *get_node(node *headp,char data);
int findO(node *headp);
void reset(node *headp);
void printlist(node *headp);

node *get_node(node *headp,char data )
{
    node *new = (node *)malloc(sizeof(node)); //�Ф@��new�����аO����Ŷ� 
    new->str = data;
    new->val = 0;
    new->next = NULL;
    if(headp == NULL){						//�Y�Y�`�I��NULL 
        headp = new;						//new���Цs�J�Y�`�I 
        headp->next = NULL;					//�Y�`�I���V�U�@�Ӹ`�I��NULL 
    }else{									//�Y�Y�`�I�S���VNULL 
        node * p = headp;					//�]�t�@�ӫ���p�ç��Y�`�I�s�J 
        while (p->next != NULL){			//�����p���V�@�Ӹ`�I����NULL 
            p = p->next;					//����p���V�U�@�Ӹ`�I 
        }
        p->next = new;						//�챵�s���`�I
        new->next = NULL;					//�챵�s���`�I
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

int main(void){
    node *headp = NULL;//�Y�`�I
    char input;
    int MagicNum = 2,i;
    printf("�п�J�n�Ho�a�Hx (o x �����ݦ��ť��� Eg:o x o o o x x):\n");
    while(scanf("%c",&input),headp = get_node(headp, input),getchar()!='\n');    //��J����Ÿ��h�����j��
    node *p = headp;
    while (findO(headp))
    {
        for (i = 0; i < MagicNum; i++)
        {
            p = p->next;
            if(p == NULL)
                p = headp;
            if (p->val == 1)
                i--;

        }
        if(p->str == 'o' || p->str == 'O'  )
        {
            p->val=1;
        }else                            //���Y�A�]�@���AMagicNum�֥[
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
