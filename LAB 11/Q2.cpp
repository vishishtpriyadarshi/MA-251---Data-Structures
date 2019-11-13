#include <bits/stdc++.h>
#include <stdio.h>
#define COUNT

#define RED		1
#define BLACK	2                                                


using namespace std;

struct node
{
  int key;
  node *left;
  node *right;
  node *p;
  int color;
};

typedef struct node *Node;
node NIL;
Node NILPTR = &NIL;

void inorder(Node x) 
{
  if (x != NILPTR)
  {
    inorder(x->left);
    
    cout << x->key;
    if(x->color == 1)
      cout << " (Red)   ";
    else if(x->color == 2)
      cout << " (Black)  ";
    
    inorder(x->right);
  }
}


void printlevel(Node root, int level)
{
  if(root == NILPTR)
    return;
  if(level == 1)
    cout << root->key << " ( " << root->color << " )    ";
  else if(level > 1)
  {
    printlevel(root->left, level-1);
    printlevel(root->right, level-1);
    
  }
}


int height(Node n)
{
  if(n == NILPTR)
    return 0;
  else
  {
    int lh = height(n->left);
    int rh = height(n->right);
    
    if(lh > rh)
      return lh + 1;
    else
      return rh + 1;
  }
}


void levelOrder(Node root)
{
  int h = height(root);
  for(int i = 1 ; i <=h; i++)
    printlevel(root, i);
}


Node search(Node root, int k)
{
  if (root == NILPTR || root->key == k)
    return root;
  if (k < root->key)
    return search(root->left, k);
  else
    return search(root->right, k);
}



Node minimum(Node root)
{
  while (root->left != NILPTR)
    root = root->left;
  return root;
}



Node maximum(Node root)
{
  while (root->right != NILPTR)
    root = root->right;
  return root;
}



Node successor(Node root, int x)
{
  Node temp = search(root, x);
  if (temp == NILPTR) 
  {
    cout << x << " is not in tree\n";
    return temp;
  }
  if (temp->right != NILPTR)
    return minimum(temp->right);
  Node y = temp->p;
  while (y != NILPTR && temp == y->right)
  {
    temp = y;
    y = y->p;
  }
  return y;
}



Node predecessor(Node root, int x)
{
  Node temp = search(root, x);
  if (temp == NILPTR) 
  {
    cout << x << " is not in tree\n";
    return temp;
  }
  if (temp->left != NILPTR)
    return maximum(temp->left);
  Node y = temp->p;
  while (y != NILPTR && temp == y->left)
  {
    temp = y;
    y = y->p;
  }
  return y;
}



void leftRotate(Node *treeroot, Node x)
{
  Node y = x->right;
  x->right = y->left;
  if (y->left != NILPTR)
    y->left->p = x;
  y->p = x->p;
  if (x->p == NILPTR)
    *treeroot = y;
  else if (x->p->left == x)
    x->p->left = y;
  else
    x->p->right = y;
  y->left = x;
  x->p = y;
}



void rightRotate(Node *treeroot, Node y)
{
  Node x = y->left;
  y->left = x->right;
  if (x->right != NILPTR)
    x->right->p = y;
  x->p = y->p;
  if (y->p == NILPTR)
    *treeroot = x;
  else if (y->p->left == y)
    y->p->left = x;
  else
    y->p->right = x;
  x->right = y;
  y->p = x;
}



void RBInsertfixup(Node *treeroot, Node z)
{
  while (z->p->color == RED)
  {
    if (z->p == z->p->p->left)
    {
      Node y = z->p->p->right;
      if (y->color == RED)
      {
        z->p->color = BLACK;
        y->color = BLACK;
        z->p->p->color = RED;
        z = z->p->p;
      }
      else 
      {
        if (z == z->p->right)
        {
          z = z->p;
          leftRotate(treeroot,z);
        }
        z->p->color = BLACK;
        z->p->p->color = RED;
        rightRotate(treeroot,z->p->p);
      }
    }
    else 
    {
      Node y = z->p->p->left;
      if (y->color == RED)
      {
        z->p->color = BLACK;
        y->color = BLACK;
        z->p->p->color = RED;
        z = z->p->p;
      }
      else 
      {
        if (z == z->p->left)
        {
          z = z->p;
          rightRotate(treeroot,z);
        }
        z->p->color = BLACK;
        z->p->p->color = RED;
        leftRotate(treeroot,z->p->p);
      }
    }
  }
  (*treeroot)->color = BLACK;
}



void RBInsert(Node *treeroot, int z)
{
  Node Z = new node; 
  Z->key = z;
  Node y = NILPTR;
  Node x = *treeroot;
  while (x != NILPTR) {
    y = x;
    if (Z->key < x->key)
      x = x->left;
    else
      x = x->right;
  }
  Z->p = y;
  if (y == NILPTR)
    *treeroot = Z;
  else if (Z->key < y->key)
    y->left = Z;
  else
    y->right = Z;
  Z->left = NILPTR;
  Z->right = NILPTR;
  Z->color = RED;
  RBInsertfixup(treeroot,Z);
}



void RBTransplant(Node *treeroot, Node u, Node v)
{
  if (u->p == NILPTR)
    *treeroot = v;
  else if (u == u->p->left)
    u->p->left = v;
  else
    u->p->right = v;
  v->p = u->p;
}



void Menu()
{
  cout << "\n\n\n\n************* MENU **************\n";
  cout << "1. Insert\n";
  cout << "2. Print in 2D\n";
  cout << "3. Inorder\n";
  cout << "0. Exit\n\n";
}



void print2DUtil(Node root, int space)
{
  if (root == NILPTR)
    return;
  space += 10;
  
  print2DUtil(root->right, space);
  cout << endl;
  for (int i = 10; i < space; i++)
    cout << " ";
  cout << root -> key << "->";
  if(root->color == 1)
    cout << "Red\n";
  else
    cout << "Black\n";
  
  print2DUtil(root -> left, space);
}


void printRBT(Node root)
{
  print2DUtil(root, 0);
}

int find(int *a, int n, int key)
{
  for(int i = 0; i < n; i++)
  {
    if(a[i] == key)
      return 1;
  }
  
  return 0;
}


int main()
{
  NIL.left = NILPTR;
  NIL.right = NILPTR;
  NIL.p = NILPTR;
  NIL.color = BLACK;
  Node tree = NILPTR;
  
  
  
  int n;
  cin >> n;
  int *a = new int[n];
  for(int i = 0;i < n; i++)
    a[i] = -1;
  
  int ct = 0;
  for(int i = 0; i < n; i++)
  {
    int lc, key, rc;
    char col;
    cin >> lc >> key >> rc >> col;
    
    if(find(a, n, key) == 0)
    {
      a[ct] = key;
      ct++;
    }
    if(lc != -1 && find(a, n, lc) == 0)
    {
      a[ct] = lc;
      ct++;
    }
    if(rc != -1 && find(a, n, rc) == 0)
    {
      a[ct] = rc;
      ct++;
    }
  }
  
  for(int i = 0; i < n; i++)
    RBInsert(&tree, a[i]);
  
  printRBT(tree);
  cout << "\n\n*****************************\n\n";
  inorder(tree);
  cout << "\n\n*****************************\n\n";
    
  Menu();
  int choice = 1;
  while(choice != 0)
  {
    cin >> choice;
    switch(choice)
    {
    case 1: int val;
            cin >> val;
            RBInsert(&tree, val);
            break;
    case 2: printRBT(tree);
            break;
    case 3: inorder(tree);
            cout << "\n\n";break;
    case 0: break;
    }
  }
  
  return 0;
}
