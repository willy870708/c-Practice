#include<stdio.h>
#include<stdlib.h>
 
struct Node
{
    int key;
    struct Node *left;
    struct Node *right;
    int height;
};
 

int max(int a, int b);   
 

int height(struct Node *N)   //找出樹的高度 
{
    if (N == NULL)
        return 0;
    return N->height;
}
 

int max(int a, int b)		//找出哪個值大 
{
    return (a > b)? a : b;
}
 

struct Node* newNode(int key)
{
    struct Node* node = (struct Node*)
                        malloc(sizeof(struct Node));
    node->key   = key;
    node->left   = NULL;
    node->right  = NULL;
    node->height = 1;  
    return(node);
}
 

struct Node *rightRotate(struct Node *y)		//樹往右旋轉 
{
    struct Node *x = y->left;
    struct Node *T2 = x->right;
 
    // 執行旋轉
    x->right = y;
    y->left = T2;
 
    // 重新計算樹的高度 
    y->height = max(height(y->left), height(y->right))+1;
    x->height = max(height(x->left), height(x->right))+1;
 
    // 傳回新的樹根
    return x;
}
 
struct Node *leftRotate(struct Node *x)			//樹往左旋轉 
{
    struct Node *y = x->right;
    struct Node *T2 = y->left;
 
    // 執行旋轉
    y->left = x;
    x->right = T2;
 
    //  重新計算樹的高度 
    x->height = max(height(x->left), height(x->right))+1;
    y->height = max(height(y->left), height(y->right))+1;
 
    // 傳回新的樹根
    return y;
}
 

int getBalance(struct Node *N)		//算出節點的平衡因子 
{
    if (N == NULL)
        return 0;
    return height(N->left) - height(N->right);	//左子樹減掉右子樹 
}
 
struct Node* insert(struct Node* node, int key)	//插入節點 
{
        if (node == NULL)
        return(newNode(key));
 
    if (key < node->key) 					//若輸入的值小於節點裡的值，則把值放在樹的左邊 
        node->left  = insert(node->left, key);
    else if (key > node->key)				//若輸入的值大於節點裡的值，則把值放在樹的右邊
        node->right = insert(node->right, key);
    else 									//若輸入的值等於節點裡的值，則傳回節點裡的值 
        return node;
        
    node->height = 1 + max(height(node->left),height(node->right));//重新計算樹的高度 
    int balance = getBalance(node);								 
 
    //若樹沒有平衡，則會有以下4種狀況要調整
    if (balance > 1 && key < node->left->key)// LL型 
        return rightRotate(node);
    if (balance < -1 && key > node->right->key)//	RR型 
        return leftRotate(node);
    if (balance > 1 && key > node->left->key)//	LR型 
    {
        node->left =  leftRotate(node->left);
        return rightRotate(node);
    }
    if (balance < -1 && key < node->right->key)// RL型 
    {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    } 
    return node;
}
 

struct Node * minValueNode(struct Node* node)	//找出最小的node值 
{
    struct Node* current = node; 
    while (current->left != NULL)
        current = current->left;
 
    return current;
}
 
struct Node* deleteNode(struct Node* root, int key)	//用遞迴的方式刪除節點 
{
    if (root == NULL)
        return root; 
    
    if ( key < root->key )			// 如果被刪除的值比節點裡的值小，則被刪除的值在樹的左邊
        root->left = deleteNode(root->left, key);
    else if( key > root->key )		// 如果被刪除的值比節點裡的值大，則被刪除的值在樹的右邊
        root->right = deleteNode(root->right, key);
    else							// 如果被刪除的值等於節點裡的值，則刪除節點本身 
    {
        if( (root->left == NULL) || (root->right == NULL) )
        {
            struct Node *temp = root->left ? root->left:root->right;
            if (temp == NULL)
            {
                temp = root;
                root = NULL;
            }
            else 
             *root = *temp;
            free(temp);
        }
        else
        {
            struct Node* temp = minValueNode(root->right);

            root->key = temp->key;
            root->right = deleteNode(root->right, temp->key);
        }
    }

    if (root == NULL)
      return root;

    root->height = 1 + max(height(root->left),height(root->right)); //重新計算樹的高度
 
    int balance = getBalance(root);		//算出節點的平衡因子
 
     //若樹沒有平衡，則會有以下4種狀況要調整
    if (balance > 1 && getBalance(root->left) >= 0)	// LL型 
        return rightRotate(root);
    if (balance > 1 && getBalance(root->left) < 0)	// LR型 
    {
        root->left =  leftRotate(root->left);
        return rightRotate(root);
    }
    if (balance < -1 && getBalance(root->right) <= 0)	// RR型 
        return leftRotate(root);

    if (balance < -1 && getBalance(root->right) > 0)	// RL型 
    {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }
 
    return root;
}
 

void print(struct Node *root)
{
    if(root != NULL)
    {
        print(root->left);
        printf("%d ", root->key);
        print(root->right);
    }
    
}

int main()
{
  struct Node *root = NULL;
  char deter;
  int i;
  printf("請輸入i(新增節點)，並輸入一個數字，輸入!為停止\n");
  scanf(" %c",&deter);
	while(deter!='!'){
		scanf(" %d",&i);
	switch(deter){
		case 'i' :
			root = insert(root, i);
			printf("目前樹的狀態:(先印左子樹再印右子樹)：\n");
			 print(root);
			 printf("\n");
		    break;
		case 'd' :
			root = deleteNode(root, i);
			printf("目前樹的狀態:(先印左子樹再印右子樹)：\n");
			 print(root);
			 printf("\n");
			break;
		case '!' :
			print(root);
			printf("目前樹的狀態:(先印左子樹再印右子樹)：\n");
			break;
			default:
				printf("請輸入正確 i 或 d\n");
	}	
	printf("輸入d(刪除節點)或i(新增節點)，並輸入一個數字，輸入!為停止\n");
    scanf(" %c",&deter);
	}
    
 
    printf("\n輸入完畢，樹的狀態為： \n");
    print(root);
 
    return 0;
}
