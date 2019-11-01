#include <iostream>

using namespace std;

struct node{
string word;
int count;
struct node*prev;
struct node*next;
};

struct node* sentinal = new struct node;
struct node*tail;

struct node* initialize(){
if(sentinal->next==NULL){
struct node*new_node=new struct node;
sentinal->next=new_node;
new_node->next=sentinal;
sentinal->prev=new_node;
return new_node;
}
else{
struct node*new_node = new struct node;
sentinal->prev->next=new_node;
new_node->next=sentinal;
sentinal->prev=new_node;
return new_node;
}

}


void push_back(string key){
struct node* new_node = initialize();
new_node->word=key;
new_node->count=1;
}

void pop_front(){
cout<<sentinal->next->word<<" - "<<sentinal->next->count-1<<endl;
if(sentinal->next->count==1){
sentinal->next=sentinal->next->next;
}
else{
sentinal->next->count-=1;
}
}

void pop_back(){
cout<<sentinal->prev->word<<" - "<<sentinal->prev->count-1<<endl;
if(sentinal->prev->count==1){
struct node*k= sentinal->prev;
sentinal->prev=k->prev;
k->prev->next=sentinal;
delete(k);
}
else{
sentinal->prev->count-=1;
}
}


int search(string key){

struct node*n = sentinal->next;
while(n!=sentinal){
int cmp=key.compare(n->word);
if(cmp==0) return 1;
else if(cmp>0) return 2;
else return 0;
n=n->next;
}
return -1;
}

void add(string key){
struct node*n = sentinal->next;
if(sentinal->next==NULL){
struct node* new_node = new struct node;
new_node->word=key;
new_node->next=sentinal;
new_node->prev=sentinal;
sentinal->next=new_node;
sentinal->prev=new_node;
new_node->count=1;
return;
}
while(n->next!=sentinal){
if(n->word==key){
n->count++;
return;
}
else if(key.compare(n->word)<0){
struct node* new_node=new struct node;
new_node->next=n;
new_node->prev=n->prev;
n->prev->next=new_node;
n->prev=new_node;
new_node->word=key;
new_node->count=1;
return;
}
else{
n=n->next;
}
}
if(n->word==key){
n->count++;
return;
}
else if(key.compare(n->word)<0){
struct node* new_node=new struct node;
new_node->next=n;
new_node->prev=n->prev;
n->prev->next=new_node;
n->prev=new_node;
new_node->word=key;
new_node->count=1;
return;
}
else{
struct node*new_node=new struct node;
new_node->next=sentinal;
new_node->prev=n;
n->next=new_node;
sentinal->prev=new_node;
new_node->count=1;
return;
}
}


int main()
{
int n=10;
cout<<"1: add key\n2 : pop front\n3: pop from back\n4: search a key\n0: Terminate"<<endl;
while(n!=0){
cin>>n;
string k;
if(n==1){
cin>>k;
add(k);
}
else if(n==2){
pop_front();
}
else if(n==3){
pop_back();
}
else if(n==4){
cin>>k;
search(k);
}
}
}
