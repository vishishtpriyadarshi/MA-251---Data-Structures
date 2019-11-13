//
// Created by Vishisht Priyadarshi on 06-11-2019.
//

#include <bits/stdc++.h>
#include <stdio.h>
#define COUNT 10

using namespace std;

struct node
{
    int key;
    node *right;
    node *left;
    node *parent;
};


int *a = new int[10];
// ========================
// Creates a Node
// ========================
node *create()
{
    node *n = new node;
    n->key = -1;
    n->right = NULL;
    n->left = NULL;
    n->parent = NULL;

    return n;
}




// ============================
// Finds the node
// ============================
node* n = create();                 // A variable to store the nodes found corresponding to find() function
node* find(node *root, int key)     // If key is not available, it returns the last visited node
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




// ===============================
// Insertion of Nodes in BST
// ===============================
node* add(node *root, int key)
{
    if(root != NULL)
    {
        node *par = find(root, key);

        if(par->key > key)
        {
            par->left = create();
            par->left->key = key;
            par->left->parent = par;
            return par->left;
        }
        else if(par->key < key)
        {
            par->right = create();
            par->right->key = key;
            par->right->parent = par;
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




// ======================
// Inorder Traversal
// ======================
int i = 0;
void inorder(node *root)
{
    if(root != NULL)
    {
        inorder(root->left);
        cout << root->key << " ";
        a[i] = root->key;
        i++;
        inorder(root->right);

    }
}



// ============================================
// 2D Printing of a BST
// ============================================
void print2DUtil(node *root, int space)
{
    if (root == NULL)
        return;
    space += COUNT;

    print2DUtil(root->right, space);
    cout << endl;
    for (int i = COUNT; i < space; i++)
        cout << " ";
    cout << root->key << "\n";

    print2DUtil(root->left, space);
}


void printBST(node *root)
{
    print2DUtil(root, 0);
}




// =====================================
// MAIN METHOD
// =====================================
int main()
{
    node *root = create();
    int n;
    cin >> n;
    node *newNode;
    for(int i = 0; i < n; i++)
    {
      int lc, key, rc;
      cin >> lc >> key >> rc;
      
      if(i == 0)
      {  
        root->key = key;
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
        
        if(lc != -1)
        {
          newNode->left = create();
          newNode->right = create();
          newNode->left->key = lc;
          newNode->left->parent = newNode;
          newNode->right->key = rc;
          newNode->right->parent = newNode;
        }
        
      }
    }
    
    cout << "BST in 2D:\n\n";
    printBST(root);
    cout << "\n\n\nINORDER TRAVERSAL\n\n";
    inorder(root);
    int f = 0;
    for(int i = 1; i <n; i++)
    {
      if(a[i] < a[i-1])
      {
        cout << "\n\n\nRESULT: INCORRECT\n";
        f = 1;
        break;
      }
    }
    
    if(f == 0)
      cout << "\n\n\nRESULT: CORRECT\n";
    return 0;
}

