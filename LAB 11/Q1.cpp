//
// Created by Vishisht Priyadarshi on 13-11-2019.
//

#include <bits/stdc++.h>
#include <stdio.h>
#define COUNT 10


#define RED		1
#define BLACK	2                                                


using namespace std;

struct node
{
  int key;
  node *right;
  node *left;
  node *parent;
  int color;
};


int *a = new int[10];

node *create()
{
  node *n = new node;
  n->key = -1;
  n->right = NULL;
  n->left = NULL;
  n->parent = NULL;
  n->color = -1;
  
  return n;
}




node* n = create();                 
node* find(node *root, int key)     
{
  if(root != NULL)
  {
    n = root;
    if(root->key < key)
      find(root->right, key);
    else if(root->key > key)
      find(root->left, key);
  }
  
  return n;
}



node* add(node *root, int key, char col)
{
  if(root != NULL)
  {
    node *par = find(root, key);
    
    if(par->key > key)
    {
      par->left = create();
      par->left->key = key;
      par->left->parent = par;
      if(col == 'r')
        par->left->color = 1;
      else
        par->left->color = 2;
      return par->left;
    }
    else if(par->key < key)
    {
      par->right = create();
      par->right->key = key;
      par->right->parent = par;
      if(col == 'r')
        par->left->color = 1;
      else
        par->left->color = 2;
      return par->right;
    }
  }
  else
  {
    root = create();
    root->key = key;
    root->parent = root;
    //cout << "HI";
    
    return root;
  }
}




int i = 0;
void inorder(node *root)
{
  if(root != NULL)
  {
    inorder(root->left);
    cout << root->key << " ";
    if(root->color == 1)
      cout << " (Red)   ";
    else if(root->color == 2)
      cout << " (Black)  ";
    else
      cout << " (Unkonown)  ";
    a[i] = root->key;
    i++;
    inorder(root->right);
    
  }
}




void print2DUtil(node *root, int space)
{
  if (root == NULL)
    return;
  space += COUNT;
  
  print2DUtil(root->right, space);
  cout << endl;
  for (int i = COUNT; i < space; i++)
    cout << " ";
  cout << root->key << "->";
  
  if(root->color == 1)
    cout << "Red\n";
  else if(root->color == 2)
    cout << " (Black)  ";
  else
    cout << " (Unkonown)  ";
  
  print2DUtil(root->left, space);
}


void printBST(node *root)
{
  print2DUtil(root, 0);
}

int flag = 0;

void RBTHelper(node *root)
{
  if(root != NULL)
  {
    RBTHelper(root->left);
    if(root->parent != NULL)
    {
      if(root->color == 1 && root->parent->color == 1)
      {
        flag = 1;
        cout << "**************************\n**************************\n\nError at Node " << root->key << "\n";
        return;
      }
    }
   
   RBTHelper(root->right);
    
  }
}


int computeBH(node *curr)
{
  if(curr == NULL)
    return 0;
  
  int leftHt = computeBH(curr->left);
  int righttHt = computeBH(curr->right);
  
  int add = curr->color;
  if(add == 2)
    add = 1;
  else
    add = 0;
  
  if(leftHt == -1 || righttHt == -1 || leftHt != righttHt)
    return -1;
  else
    return leftHt + add;
}
bool checkBlackHeight(node *root)
{
    return computeBH(root) != -1;
}


int checkRBT(node *root)
{
  
  if(root->color == 1)
  {
    flag = 1;
  }
  else
    RBTHelper(root);
  
  if(flag == 0)
  {
    if(checkBlackHeight(root) == 0)
      flag = 1;
  }
  return flag;
  
}




int main()
{
  node *root = create();
  int n;
  cin >> n;
  node *newNode;
  for(int i = 0; i < n; i++)
  {
    int lc, key, rc;
    char col;
    cin >> lc >> key >> rc >> col;
    
    if(i == 0)
    {  
      root->key = key;
      if(col == 'r')
        root->color = 1;
      else
        root->color = 2;
      
      root->parent = NULL;
      root->left = create();
      root->right = create();
      
      
      root->left->key = lc;
      root->left->parent = root;
      root->right->key = rc;
      root->left->parent = root;
    }
    else
    {
      newNode  = find(root, key);
      
      if(lc != -1 && rc != -1)
      {
        newNode->left = create();
        newNode->right = create();
        newNode->left->key = lc;
        newNode->left->parent = newNode;
        newNode->right->key = rc;
        newNode->right->parent = newNode;
      }
      else if(lc == -1 && rc != -1)
      {
      
        newNode->right = create();
        newNode->right->key = rc;
        newNode->right->parent = newNode;
      }
      else if(lc != -1 && rc == -1)
      {
        newNode->left = create();
        newNode->left->key = lc;
        newNode->left->parent = newNode;
      }
      if(col == 'r')
        newNode->color = 1;
      else
        newNode->color = 2;
    }
  }
  
  cout << "BST in 2D:\n\n";
  printBST(root);
  cout << "\n\n\nINORDER TRAVERSAL\n\n";
  inorder(root);
 
  // Determine if it is RBT
  
 cout << "\n\n";
 int op = checkRBT(root);
  
  if(op == 0)
    cout << "\nValid Red Black Tree\n\n";
  else
    cout << "\nInvalid Red Black Tree\n\n";
    
  return 0;
}

