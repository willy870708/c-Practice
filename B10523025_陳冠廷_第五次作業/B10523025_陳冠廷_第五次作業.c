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
 

int height(struct Node *N)   //��X�𪺰��� 
{
    if (N == NULL)
        return 0;
    return N->height;
}
 

int max(int a, int b)		//��X���ӭȤj 
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
 

struct Node *rightRotate(struct Node *y)		//�𩹥k���� 
{
    struct Node *x = y->left;
    struct Node *T2 = x->right;
 
    // �������
    x->right = y;
    y->left = T2;
 
    // ���s�p��𪺰��� 
    y->height = max(height(y->left), height(y->right))+1;
    x->height = max(height(x->left), height(x->right))+1;
 
    // �Ǧ^�s�����
    return x;
}
 
struct Node *leftRotate(struct Node *x)			//�𩹥����� 
{
    struct Node *y = x->right;
    struct Node *T2 = y->left;
 
    // �������
    y->left = x;
    x->right = T2;
 
    //  ���s�p��𪺰��� 
    x->height = max(height(x->left), height(x->right))+1;
    y->height = max(height(y->left), height(y->right))+1;
 
    // �Ǧ^�s�����
    return y;
}
 

int getBalance(struct Node *N)		//��X�`�I�����Ŧ]�l 
{
    if (N == NULL)
        return 0;
    return height(N->left) - height(N->right);	//���l���k�l�� 
}
 
struct Node* insert(struct Node* node, int key)	//���J�`�I 
{
        if (node == NULL)
        return(newNode(key));
 
    if (key < node->key) 					//�Y��J���Ȥp��`�I�̪��ȡA�h��ȩ�b�𪺥��� 
        node->left  = insert(node->left, key);
    else if (key > node->key)				//�Y��J���Ȥj��`�I�̪��ȡA�h��ȩ�b�𪺥k��
        node->right = insert(node->right, key);
    else 									//�Y��J���ȵ���`�I�̪��ȡA�h�Ǧ^�`�I�̪��� 
        return node;
        
    node->height = 1 + max(height(node->left),height(node->right));//���s�p��𪺰��� 
    int balance = getBalance(node);								 
 
    //�Y��S�����šA�h�|���H�U4�ت��p�n�վ�
    if (balance > 1 && key < node->left->key)// LL�� 
        return rightRotate(node);
    if (balance < -1 && key > node->right->key)//	RR�� 
        return leftRotate(node);
    if (balance > 1 && key > node->left->key)//	LR�� 
    {
        node->left =  leftRotate(node->left);
        return rightRotate(node);
    }
    if (balance < -1 && key < node->right->key)// RL�� 
    {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    } 
    return node;
}
 

struct Node * minValueNode(struct Node* node)	//��X�̤p��node�� 
{
    struct Node* current = node; 
    while (current->left != NULL)
        current = current->left;
 
    return current;
}
 
struct Node* deleteNode(struct Node* root, int key)	//�λ��j���覡�R���`�I 
{
    if (root == NULL)
        return root; 
    
    if ( key < root->key )			// �p�G�Q�R�����Ȥ�`�I�̪��Ȥp�A�h�Q�R�����Ȧb�𪺥���
        root->left = deleteNode(root->left, key);
    else if( key > root->key )		// �p�G�Q�R�����Ȥ�`�I�̪��Ȥj�A�h�Q�R�����Ȧb�𪺥k��
        root->right = deleteNode(root->right, key);
    else							// �p�G�Q�R�����ȵ���`�I�̪��ȡA�h�R���`�I���� 
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

    root->height = 1 + max(height(root->left),height(root->right)); //���s�p��𪺰���
 
    int balance = getBalance(root);		//��X�`�I�����Ŧ]�l
 
     //�Y��S�����šA�h�|���H�U4�ت��p�n�վ�
    if (balance > 1 && getBalance(root->left) >= 0)	// LL�� 
        return rightRotate(root);
    if (balance > 1 && getBalance(root->left) < 0)	// LR�� 
    {
        root->left =  leftRotate(root->left);
        return rightRotate(root);
    }
    if (balance < -1 && getBalance(root->right) <= 0)	// RR�� 
        return leftRotate(root);

    if (balance < -1 && getBalance(root->right) > 0)	// RL�� 
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
  printf("�п�Ji(�s�W�`�I)�A�ÿ�J�@�ӼƦr�A��J!������\n");
  scanf(" %c",&deter);
	while(deter!='!'){
		scanf(" %d",&i);
	switch(deter){
		case 'i' :
			root = insert(root, i);
			printf("�ثe�𪺪��A:(���L���l��A�L�k�l��)�G\n");
			 print(root);
			 printf("\n");
		    break;
		case 'd' :
			root = deleteNode(root, i);
			printf("�ثe�𪺪��A:(���L���l��A�L�k�l��)�G\n");
			 print(root);
			 printf("\n");
			break;
		case '!' :
			print(root);
			printf("�ثe�𪺪��A:(���L���l��A�L�k�l��)�G\n");
			break;
			default:
				printf("�п�J���T i �� d\n");
	}	
	printf("��Jd(�R���`�I)��i(�s�W�`�I)�A�ÿ�J�@�ӼƦr�A��J!������\n");
    scanf(" %c",&deter);
	}
    
 
    printf("\n��J�����A�𪺪��A���G \n");
    print(root);
 
    return 0;
}
