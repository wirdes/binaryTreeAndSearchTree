#include <stdio.h>
#include <stdlib.h>

typedef struct tree{
    int data;
    struct tree *left;
    struct tree *right;
}binaryTree;
typedef struct st{
	int index;
	int note;
	int number;
	struct  st *right;
	struct  st *left;
}students;
typedef struct que{

	binaryTree * node;
	struct que * next;	
	
}que;

que * pop(que * head){
	if(head -> next  == NULL){
		head = NULL;
		return head;
	}
	que* tmp = head;
    head = head -> next;
    free(tmp);
    return head;
}
que* push(que * head,binaryTree* node){
    
    if(head == NULL)
    {
    	que* r = (que*)malloc(sizeof(que));
    	r -> node = node;
    	r -> next = NULL;
    	return r;
    }
    que * iter = head;
    while(iter->next != NULL){
    	iter = iter->next;
	}
	que* temp = (que*)malloc(sizeof(que));
    temp ->node = node;
    temp -> next = NULL;
    iter->next = temp;
    return head;
}

binaryTree * addRight(binaryTree *r , int data){
	if (r  == NULL ){
		r = ( binaryTree* )malloc(sizeof( binaryTree));
		r -> data = data;
		r -> right = NULL;
		r -> left = NULL;
		return r;
	}
	binaryTree* temp = ( binaryTree* )malloc(sizeof(  binaryTree));
	temp -> right = r -> right;
	temp -> data = data ;
	temp -> left = NULL;
	r -> right = temp;
	return r;		
}		
binaryTree * addLeft(binaryTree *r , int data){	
	if (r  == NULL )
	{
		r = ( binaryTree* )malloc(sizeof(  binaryTree));
		r -> data = data;
		r -> right = NULL;
		r -> left = NULL;
		return r;
	}
	binaryTree* temp = ( binaryTree* )malloc(sizeof(  binaryTree));
	temp -> left = r -> left;
	temp -> data = data ;
	temp -> right = NULL;
	r -> left = temp;
	return r;	
	
}
void postOr(binaryTree *r){
   
        if (r->left)
        {
            postOr(r->left);
        }
        if (r->right)
        {
            postOr(r->right);
        }
        printf("%d ", r->data);
    
}
void inOr(binaryTree *r){
        if (r->left !=NULL) 
		inOr(r->left);
        
        printf("%d ", r->data);
        if (r->right !=NULL)
		 inOr(r->right);
     

}
void bfs(binaryTree *r,que * que){
	if(que == NULL) que= push(que,r);
	 if(r !=NULL){
	     	if(r ->left) que = push(que,r ->left);	
     		if(r ->right)que = push(que, r ->right);	
			printf("%d ",que->node->data);
			que = pop(que);			 
     		if(que !=NULL)bfs(que->node,que);	 		
		 }

	 }


void preOr(binaryTree * r){
	printf("%d ",r->data);
	 if (r->left !=NULL) preOr(r -> left);

	if (r->right !=NULL) preOr(r -> right);		

}
void binaryTreePrint(binaryTree * root,que * que){
	printf("\n------------------TREE------------------\n");
	printf("|                                      |\n");
	printf("|                  ---                 |\n");
	printf("|                  |%d|                 |\n",root->data);
	printf("|                  ---                 |\n");
	printf("|                 /   %c                |\n",92);		
	printf("|              ---     ---             |\n");
	printf("|              |%d|     |%d|             |\n",root->left->data,root->right->data);
	printf("|              ---     ---             |\n");
	printf("|             /   %c   /   %c            |\n",92,92);
	printf("|            --- --- --- ---           |\n");
	printf("|            |%d| |%d| |%d| |%d|           |\n",root->left->left->data,root->left->right->data,root->right->left->data,root->right->right->data);
	printf("|            --- --- --- ---           |\n");	
	printf("|                                      |\n");
	printf("----------------------------------------\n");
	printf("\n------------------DFS-------------------\n");
	printf("|                                      |\n");
	printf("|      Postorder : ");
	postOr(root);
	printf("      |\n");
	printf("|      Preorder  : ");
	preOr(root);
	printf("      |\n");
	printf("|      Inorder   : ");
	inOr(root);
	printf("      |\n");
	printf("|                                      |\n");
	printf("----------------------------------------\n");
	printf("\n------------------BFS-------------------\n");
	printf("|                                      |\n");
	printf("|            ");
	bfs(root,que);
	printf("            |\n");
	printf("|                                      |\n");
	printf("----------------------------------------\n");
	
}

students * node(int number, int note,int index){
	students * i = (students *) malloc(sizeof(students));
	i -> number = number;
	i -> note = note;
	i -> index = index;
	i -> right = NULL;
	i -> left = NULL;
	return i;
}
students * addSt(students* r,int number,int note,int index){
	if(r == NULL){
		return node(number,note,index);
	}else if(note > r -> note){
		r -> right = addSt(r->right,number,note,index);
		
	}else if(note < r -> note)
		r -> left = addSt(r->left,number,note,index);
	else if (note == r -> note){
		if (number < r -> number){
			r -> right = addSt(r->right,number,note,index);
		}else{
				r -> left = addSt(r->left,number,note,index);	
		}
		return r;	
	}	
				
	
}


students* findMax(students *root){
    if(root == NULL)
        return NULL;
    else if(root->left != NULL) 
        return findMax(root->left); 
    return root;
}



void conditionalPrint(students *root,int note){	
    if(root!=NULL) 
    {
	
	    conditionalPrint(root->right,note);
	    if(note < root ->note)
		printf("|       Num:%8d - Note:%3d        |\n", root->number,root->note,root->index);
		conditionalPrint(root->left,note); 
 }
         
}

students* delete(students *root, int number,int note){
    if(root==NULL){
    	        return NULL;
	}

    if (note > root->note){

        root->right = delete(root->right, number,note);
	} else if(note<root->note){

        	root->left = delete(root->left, number,note);
    	
	} else if(note == root -> note){
    		if(number < root ->number  ){

    			root->right = delete(root->right, number,note);
			}else if(number > root ->number  ){

    			root->left = delete(root->left, number,note);    				
				}else if( number == root -> number){

        
        if(root->left==NULL && root->right==NULL)
        {
            free(root);
            return NULL;
        }

        else if(root->left==NULL || root->right==NULL)
        {
            students *temp;
            if(root->left==NULL)
                temp = root->right;
            else
                temp = root->left;
            free(root);
            return temp;
        }

        
        else
        {
            students *temp = findMax(root->right);
            root->number = temp->number;
            root -> note = temp -> note;
			root -> index = temp -> index;
            root->right = delete(root->right, temp->number, note);
        }
    }
    	
          return root;
	}
 
 
}

int main(){	

	binaryTree * tree;
	tree = NULL;
	tree = addRight(tree,1);
	addRight(tree,7);
 	addLeft(tree,3);
 	addLeft(tree,2);
 	addRight(tree->left,4);
	addRight(tree,5);
	addLeft(tree->right,6); 
	students * student;
	student = NULL;
	student = node(18060311,40,0);
	addSt(student,20060045,50,1);
	addSt(student,19061091,75,2);
	addSt(student,20060134,90,3);
	addSt(student,20060678,40,4);
	addSt(student,18061086,75,5);
	addSt(student,20060032,50,6);
	addSt(student,20060067,60,7);
	addSt(student,19060456,60,8);
	addSt(student,18060245,75,9);
	addSt(student,20060110,40,10);
	addSt(student,20060234,90,11);
	addSt(student,20060141,60,12);
	addSt(student,20060011,50,13);
	addSt(student,20060012,60,14);
	que * list = NULL;
	int no,number,selection;
	int ch;
					
	 while(selection!=6)
	 
    {
    	printf("\n\nBinary Search tree ;\nIf u add press: 1\nIf u delete press: 2\nIf u change: 3\nIf u want see table: 4\nFor Binary Tree  : 5");
  	printf("\nSelection:");
		scanf("%d",&selection);
		switch (selection){
    	case 1:
    		
    		printf("Enter the student number:");
    		scanf("%d",&no);
    		printf("Enter the note:");
    		scanf("%d",&number);
    		addSt(student,no,number,-1);
      	break;

    	case 2:
    		printf("Enter the student number of u want to delete:");
    		scanf("%d",&number);
    		printf("Enter the student note:");
    		scanf("%d",&no);
    		student = delete(student,number,no);
      	break;
      	
      	case 3:
    	 	printf("Enter the student number of u want to change:");
    		scanf("%d",&number);
    		printf("Enter the student note:");
    		scanf("%d",&no);
    		student = delete(student,number,no);
    		addSt(student,number,no,-1);
      	break;
      	case 4:
      		printf("Enter the student number:");
    		scanf("%d",&no);
      		printf("\n           Binary Search Tree \n");
			printf("      Students with a grade above %d\n ",no);
			printf("----------------------------------------\n");
			printf("|                                      |\n");
    	 	conditionalPrint(student,no);
			printf("|                                      |\n");
			printf("----------------------------------------\n");    	 	
      	break;
      	
      	case 5:
      		
    	 	binaryTreePrint(tree,list);
      	break; 
      	case 6:
      		
      	break;
  
   	    default:
   	    	
      		printf("Invalid transaction");
      		
			}	
    }
    printf("Exiting the App\n");
	
	    return 0;
}
 
