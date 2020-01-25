#include<stdio.h>
struct node
{
  struct node *left;
  int data;
  struct node *right;
};
struct node * insert (struct node *root, int val);
void inorder(struct node * root);
struct node * delete_key (struct node *root, int val);
struct node * find_min(struct node * root);
struct node *search(struct node *root, int data);
int main(void)
{
  struct node *root=NULL,*node=NULL;
  int n, val,ch,i;
  do{
  printf("\n***BST OPERATIONS*****");
  printf("\n1.Create");
  printf("\n2.Inorder");
  printf("\n3.Delete");
  printf("\n4.Search");
  printf("\n5.Exit");
  printf("\nEnter ur choice = ");
  scanf("%d",&ch);
  switch(ch)
  {
    case 1:
    printf("\nEnter no of nodes = ");
    scanf("%d",&n);
    printf("\nEnter tree values");
    for(i=0;i<n;i++)
    {
      scanf("%d",&val);
      root = insert(root,val);
    }
    break;
    case 2:
    inorder(root);
    break;
    case 3:
    printf("Enter key to be deleted ");
    scanf("%d",&val);
    delete_key(root, val);
    break;
    case 4:
    printf("Enter key to be searched ");
    scanf("%d",&val);
    node = search(root, val);
    if(node!=NULL)
      printf("\n Key found = %d", node->data);
    else
      printf("\nKey not found");
    break;
    case 5:
    printf("\n\n Exit\n\n");
      break;

  }
  }while(ch!=5);
  return 0;
}
struct node * insert(struct node * root,int data)
{
  if(root==NULL)
  {
    struct node *newnode;
    newnode = (struct node *)malloc(sizeof(struct node));
    newnode -> data = data;
    newnode -> left = newnode -> right = NULL;
    return newnode;
  }
  if(data >(root->data))
  {
    root->right = insert(root->right,data);
  }
  else if(data < (root->data))
  {
    root->left = insert(root->left,data);
  }

}
struct node *search(struct node *root, int data)
{
  while(root!=NULL)
  {
    if (data == root->data)
      return root;
    else
    {
      if(data < root->data)
        root = root->left;
      else
        root = root->right;
    }
  }
  return NULL;
}
void inorder(struct node * root)
{
  if(root!= NULL)
  {
    inorder(root->left);
    printf("\t%d",root->data);
    inorder(root->right);
  }
}
struct node * find_min(struct node * root)
{
  while(root->left!=NULL)
    root = root->left;
  return root;
}
struct node * delete_key (struct node *root, int data)
{
  struct node *temp;
  // base case
  if(root == NULL)
  {
    printf("element not found");
  }
  else
  {
  if(data < root->data)
  {
    root->left = delete_key(root->left, data);
  }
  else if(data > root->data)
  {
    root->right = delete_key(root->right, data);
  }
  else
  {
    // node with only one child or no child
    if (root->left == NULL)
    {
      temp =root;
      root = root->right;
      free (temp);
      return root;
    }
    else if (root->right == NULL)
    {
      temp = root;
      root = root->left;
      free (temp);
      return root;
    }
    // node with two children: Get the inorder successor (smallest
  // in the right subtree)
    temp = find_min(root->right);

    // Copy the inorder successor's content to this node
    root->data = temp->data;

    // Delete the inorder successor
     root->right = delete_key(root->right, temp->data);
  }
  }
  return root;
}