//
// Created by Vishisht Priyadarshi on 06-11-2019.
//

#include <bits/stdc++.h>
#include <stdio.h>
#include <string.h>
#define COUNT 10

using namespace std;

struct node
{
    int key;
    string s;
    node *right;
    node *left;
    node *parent;
};



// ========================
// Creates a Node
// ========================
node *create()
{
    node *n = new node;
    n->key = -1;
    n->s = "";
    n->right = NULL;
    n->left = NULL;
    n->parent = NULL;

    return n;
}

node *root = create();
// ==========================
// Converts string to no
// ==========================

int convert(string str)
{
  int n = 0;
  for(int i = 0; i < str.length(); i++)
  {
    if(str[i] > 90)
      n += (str[i] - 32);
    else
      n += str[i];
  }
  
  return n;
}

// ============================
// Finds the node
// ============================
node* n = create();                 // A variable to store the nodes found corresponding to find() function
node* find(node *root, string str)     // If key is not available, it returns the last visited node
{
    string temp = str;
    //transform(str.begin(), str.end(), str.begin(), ::tolower);
    if(root != NULL)
    {
        n = root;
        if(root->s < str)
            find(root->right, temp);
        else if(root->s > str)
            find(root->left, temp);
    }

    return n;
}





// ===============================
// Inserrtion of Nodes in BST
// ===============================
void add(node *root, int key, string str)
{
    if(root != NULL)
    {
        node *par = find(root, str);
        string temp = str; 
        //transform(str.begin(), str.end(), str.begin(), ::tolower);
        
        if(str.compare(par->s) < 0)
        {
            par->left = create();
            par->left->key = key;
            par->left->s = temp;
            par->left->parent = par;
        }
        else if(str.compare(par->s) > 0)
        {
            par->right = create();
            par->right->key = key;
            par->right->s = temp;
            par->right->parent = par;
        }
    }
    else
    {
        root = create();
        root->key = key;
        root->s = str;
        root->parent = root;
        //cout << "HI";
    }
}




// ======================
// Inorder Traversal
// ======================
void inorder(node *root)
{
    if(root != NULL)
    {
        inorder(root->left);
        cout << root->s << " ";
        inorder(root->right);

    }
}



// ================================
// Minimum & Maximum keys in BST
// ================================
node* minimum(node *root)
{
    while(root->left != NULL)
    {
        root = root->left;
    }

    return root;
}


node* maximum(node *root)
{
    while(root->right != NULL)
    {
        root = root->right;
    }

    return root;
}





// ===========================================
// Successor and Predecessor of a Given Node
// ===========================================
node *successor(node *root)
{
    if(root->right != NULL)
        return minimum(root->right);
    else
    {
        if(root == root->parent->left)
          return root->parent;
        else
        {
          while(1)
          {
            root = root->parent;
            if(root->parent != NULL)
            {
              if(root == root->parent->left)
                return root->parent;                // Current node is the left child
            }
            else
              break;
          
          }
        }
        return root;
    }
}

node *predecessor(node *root)
{
    if(root->left != NULL)
        return maximum(root->left);
    else
    {
       if(root == root->parent->right)
         return root->parent;
       else
       {
         while(1)
         {
           root = root->parent;
           if(root->parent != NULL)
           {
             if(root == root->parent->right)
               return root->parent;                // Current node is the left child
           }
           else
             break;
         }
       }
       return root;
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
    cout << root->s << "\n";

    print2DUtil(root->left, space);
}


void printBST(node *root)
{
    print2DUtil(root, 0);
}




// ===========================================================================
// Exchanges the initial and final nodes but their child nodes aren't handled
// ===========================================================================
void Transplant(node *root, node *initial, node *final)
{
    if(final->parent->left == final)
        final->parent->left = NULL;
    else
        final->parent->right = NULL;


    if(initial->parent == NULL) {                           // If Node to be deleted is the Root Node
        root->key = final->key;
        root->s = final->s;
        final->left = initial->left;
        root->right = final->right;

    }
    else if(initial == initial->parent->left)
        initial->parent->left = final;
    else if(initial == initial->parent->right)
        initial->parent->right = final;

}



// ==============================================
// Node Deletion
// ==============================================
void deleteNode(node *root, node *delNode)
{
    if(delNode->left == NULL && delNode->right == NULL)         // CASE 1: delNode has no children
    {
        if(delNode->parent->left == delNode)
            delNode->parent->left = NULL;
        else
            delNode->parent->right = NULL;
    }
    else if(delNode->left == NULL || delNode->right == NULL)    // CASE 2: delNode has 1 child only
    {
        if(delNode->parent != NULL)
        {
          if(delNode->left != NULL)                               // Point parent of delNode to child of delNode and vice-versa
          {
            if(delNode->parent->left == delNode)
              delNode->parent->left = delNode->left;
            else
              delNode->parent->right = delNode->left;
          }
          else
          {
            if(delNode->parent->left == delNode)
              delNode->parent->left = delNode->right;
            else
              delNode->parent->right = delNode->right;
          }
        }
        else
        {
          cout << "HI";
          if(root->s == delNode->s)
          {
            if(delNode->left != NULL)
            {
              root = delNode->left;
              root->parent = NULL;
              cout << "****" << root->s << "***\n";
            }
            else
            {
              root = delNode->right;
              delNode->right->parent = NULL;
              cout << "F";
            }
          }
        }
       
    }
    else                                                       // CASE 3: delNode has both children
    {
        node *y = successor(delNode);
        //cout << "\n\n" << y-> key << "\n\n";
        if(y->left == NULL && y->right == NULL)                // CASE 3.(a) : Successsor has no child
        {
            Transplant(root, delNode, y);
            y->right = delNode->right;
            y->left = delNode->left;
        }
        else                                                   // CASE 3.(b) : Successor has 1 child (THESE ARE THE ONLY CASES
        {                                                      //                2 Children of successor isn't possible)
            node *temp = delNode;
            Transplant(root, delNode, y);           // Replaces the node to be deleted with its successor
            y->left = delNode->left;                // As Successor will always be in right subtree and left one needs to be joined to it
        }
    }
}



// =====================================
// MAIN METHOD
// =====================================
int main()
{
    
    cout << "********** MENU **********:\n\n";
    cout << "1.     ADD x           -> Inserts node with value = x\n";
    cout << "2.     DEL x           -> Deletes node with value = x\n";
    cout << "3.     INORDER         -> Prints Inorder Traversal\n";
    cout << "4.     PRINT2D         -> Prints BST in 2D Form\n";
    cout << "5.     EXISTS x        -> Checks if x exists in BST\n";
    cout << "6.    MENU            -> Prints Menu\n";
    cout << "7.    EXIT            -> Exits the MENU\n\n";

    string str;
    cin >> str;

    int i = 0;
    while(str != "EXIT")
    {
        if(str == "ADD")
        {
            int x;
            string str;
            getline(cin , str);
            //transform(str.begin(), str.end(), str.begin(), ::tolower);
            x  = convert(str);
            if(i == 0) {
                root->key = x;
                root->s = str;
                root->parent = NULL;
                i++;
            }
            else
                add(root, x, str);
        }
        else if(str == "DEL")
        {
            int x;
            string str;
            cin >> str;
            x = convert(str);
            //transform(str.begin(), str.end(), str.begin(), ::tolower);
            
            if(str == find(root, str)->s)
                deleteNode(root, find(root,str));
            else
                cout << "\nValue doesn't exist in the BST\n";
        }
        else if(str == "INORDER") {
            inorder(root);
            cout << "\n\n";
        }
        else if(str == "PRINT2D")
            printBST(root);
        else if(str == "MENU")
        {
            cout << "********** MENU **********:\n\n";
            cout << "1.     ADD x           -> Inserts node with value = x\n";
            cout << "2.     DEL x           -> Deletes node with value = x\n";
            cout << "3.     SUCCESSOR x     -> Finds successor of x\n";
            cout << "4.     PREDECESSOR x   -> Finds predecessor of x\n";
            cout << "5.     MAX             -> Finds maximum value in BST\n";
            cout << "6.     MIN             -> Finds minimum valur in BST\n";
            cout << "7.     INORDER         -> Prints Inorder Traversal\n";
            cout << "8.     PRINT2D         -> Prints BST in 2D Form\n";
            cout << "9.     EXISTS x        -> Checks if x exists in BST\n";
            cout << "10.    MENU            -> Prints Menu\n";
            cout << "11.    EXIT            -> Exits the MENU\n\n";
        }
        else if(str == "EXISTS")
        {
            int x;
            string str;
            getline(cin , str);
            x = convert(str);
            //transform(str.begin(), str.end(), str.begin(), ::tolower);
            if(str == find(root, str)->s)
                cout << "\nValue exists in BST\n";
            else
                cout << "\nValue doesn't exist in BST\n";
        }
        else
        {
            cout << "\nWrong INPUT\n\n";
            cout << "********** MENU **********:\n\n";
            cout << "1.     ADD x           -> Inserts node with value = x\n";
            cout << "2.     DEL x           -> Deletes node with value = x\n";
            cout << "3.     SUCCESSOR x     -> Finds successor of x\n";
            cout << "4.     PREDECESSOR x   -> Finds predecessor of x\n";
            cout << "5.     MAX             -> Finds maximum value in BST\n";
            cout << "6.     MIN             -> Finds minimum valur in BST\n";
            cout << "7.     INORDER         -> Prints Inorder Traversal\n";
            cout << "8.     PRINT2D         -> Prints BST in 2D Form\n";
            cout << "9.     EXISTS x        -> Checks if x exists in BST\n";
            cout << "10.    MENU            -> Prints Menu\n";
            cout << "11.    EXIT            -> Exits the MENU\n\n";
        }
        cin >> str;
    }
    
    return 0;
}

