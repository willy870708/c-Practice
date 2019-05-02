#include <stdio.h>
#include <stdlib.h>

typedef struct linklist{
    int val;                         //暫存0和1，0=船上 1=下船
    char str;                        //存入o和x之值 
    struct linklist *next;				
    struct linklist *pre;
}node;

node *get_node(node *headp,char data);
int findO(node *headp);
void reset(node *headp);
void printlist(node *headp);


node *get_node(node *headp,char data){
    node *new = (node *)malloc(sizeof(node)); //創一個new的指標記憶體空間 
    new->str = data;
    new->val = 0;
    new->next = NULL;
    new->pre = NULL;
    if(headp == NULL){						//若頭節點為NULL  
        headp = new;						//new指標存入頭節點 
        headp->next = NULL;
		headp->pre = NULL;					//頭節點指向下一個節點為NULL 
    }else{									//若頭節點沒指向NULL 
        node * p = headp;					//設另一個指標p並把頭節點存入 
        while (p->next != NULL){			//當指標p指向一個節點不為NULL 
            p = p->next;					//指標p指向下一個節點
            
        }
        new ->pre=p;						//新的節點往前指到前一個節點 
        p->next = new;						//鏈接新的節點
    }
    return headp;
}

int findO(node *headp)                    //判斷是否還有任何o在船上，有則true
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
        if(p->str == 'o' || p->str =='O')            //所有o的val = 0,即上船
        {
            p->val = 0;
        }
        p = p->next;
    }
    p->val = 0;
}
int getrear(node *headp){							//取得尾節點 
	 node * a=headp;
	 while(a->next!=NULL){
	 a=a->next;
	 }
	 return a;
}
int main(void){
    node *headp = NULL;//頭節點
    char input[1000];
    int MagicNum = 1,i;
    int side = 1;
    printf("請輸入好人o壞人x:\n");
    scanf("%[^\n]",input);
    char *str = input;
    while(*str != 32 ? headp = get_node(headp, *str) : NULL ,str++,*str!='\0');    //輸入換行符號則結束迴圈
    node *p = headp;
    node *r = getrear(headp);  						//取得尾節點 
    while (findO(headp))							//若字串中還有o好人則持續跑迴圈 
    {
        for (i = 0; i < MagicNum; i++)				 
        {
            if(side){								 
			p = p->next;							//鏈結往尾節點方向走 
            if(p == NULL)							//若指到NULL 
                p = headp;							//則回到頭節點 
            if (p->val == 1)						 
                i--;
			}
			else{									 
			p = p->pre;								//鏈結往頭節點方向走
            if(p == NULL)							//若指到NULL 
                p = r;								//則回到尾節點 
            if (p->val == 1)
                i--;	
			}
        }
        if(p->str == 'o' || p->str == 'O'  )		//若找到o好人則鏈結往反方向走
        {
            p->val=1;
            if(side){
            side= 0;
			}
			else{
			side= 1;
			}
        }else                            //若非o好人重頭再跑一次，MagicNum累加
        {
            reset(headp);
            MagicNum++;
            p = headp;
        }
    }
    printf("神奇數字:%d\n",MagicNum);
    system("pause");
    return 0;
}
