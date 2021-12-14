#include <iostream>
using namespace std;
// node is basic unit of tree which will be responsible to hold data and two children
class node
{
public:
  node * left;
  node *right;
//varible type can be altered as per requirement
  int data;			//customize
};
class Btree
{
public:
  int size;
  node *root;
  // storing inorder,preorder as array to rebuild tree
  int *inarr, *prearr;
  Btree();
  ~Btree();
  // buildtree will be accessed by the user
  void buildtree (int num);
  //insert will be used internally
  static void insert (node ** sr, int num);
  // display will show result of
  // -  inorder 
  // - preorder
  // -postorder
  void display ();
  static void inorder (node * sr, int &v, int *inarr);
  static void preorder (node * sr, int &v, int *prearr);
  static void postorder(node *sr);
  void deltree();
  static void del(node *sr);
  void rebuild();
  static node *recons(int *pre,int *in,int nodes,int& size);//nodes represent size;
};
void Btree::rebuild(){
    
    root=recons(prearr,inarr,size,size);
}
node* Btree::recons(int *pre,int* in,int nodes,int& size){
    if (nodes==0)
    return NULL;
    node* temp;
    temp=new node;
    temp->data=pre[0];
    temp->right=NULL;
    temp->left=NULL;
    if(nodes==1){
        return temp;
    }
    int i,j,tempin[size],temppre[size];
    for(i=0;in[i]!=pre[0];)
    i++;
    
    if(i>0){
       for(j=0;j<i;j++){
           tempin[j]=in[j];
           temppre[j]=pre[j+1];
       } 
    }
    temp->left=recons(temppre,tempin,i,size);
    if(i<nodes-1)
    {
        for(j=i;j<nodes-1;j++){
            tempin[j-i]=in[j+1];
            temppre[j-i]=pre[j+1];
        }
    }
    temp->right=recons(temppre,tempin,nodes-i-1,size);
    return temp;
}
Btree::~Btree(){
    deltree();
}
void Btree::deltree(){
    del(root);
    root=NULL;
}
void Btree::del(node *sr){
    if (sr!=NULL){
        del(sr->left);
        del(sr->right);
    }delete sr;
}
Btree::Btree(){
    size=0;
    root=NULL;
}
void Btree::postorder (node * sr )
{
  if (sr != NULL)
    {
      postorder (sr->left );
      postorder (sr->right);
      cout << sr->data << "\t";
    }
}

void Btree::preorder (node * sr, int &v, int* prearr )
{
  if (sr != NULL)
    {
    cout << sr->data << "\t";
    prearr[v++]= sr->data;
      preorder (sr->left, v, prearr);
      preorder (sr->right, v, prearr);
      
    }
}
void Btree::inorder (node * sr, int &v, int* arrin )
{
  if (sr != NULL)
    {
      inorder (sr->left, v, arrin);
      cout << sr->data << "\t";
      arrin[v++]= sr->data;
      inorder (sr->right, v, arrin);
    }
}

 void Btree::buildtree (int num)
{
  size++;
  insert (&root, num);
}

void Btree::insert (node **sr, int num)
{
  if ((*sr) == NULL)
    {
      (*sr) = new node;
      (*sr)->data = num;
      (*sr)->left =NULL; (*sr)->right = NULL;
    }
  else
    {
      if (((*sr)->data) > num)
	insert (&((*sr)->left), num);
      else
	insert (&((*sr)->right), num);
    }
}

void Btree::display ()
{
  int n = size;
   inarr=new int[n];
   prearr=new int[n];
  int v = 0;
  cout << "\nInorder display" << endl;
  inorder (root, v, inarr);
  cout<<"\nPreorder display\n";
  v=0;
  preorder(root,v,prearr);
  cout<<"\nPostorder display\n";
  postorder(root);
  
}

int
main ()
{
  
  Btree bt;
 
  cout<<"Enter y if you wish to run trial version, else enter n for custom input \n";
  int n;
  char ch;
  cin>>ch;
  if(ch=='n'){
      cout<<"enter number of elements you like to insert\n";
      cin>>n;
       
      for(int i=0,j=0;i<n;i++){
          cout<<"enter "<<i+1<<" :";
          cin>>j;
          bt.buildtree(j);
      }
  }
  else{
  
   int arr[]={5,8,3,4,6,9};
  cout<<"inserting elements\n";
  for(auto i: arr)
  {bt.buildtree (i);cout<<i<<"\t";}
  cout<<"\n";}
  cout<<"displaying tree"<<endl;
  bt.display ();
  bt.deltree();
  
  
  bt.rebuild();
  cout<<"\nTree after rebuild\n";
  bt.display();
  
  
 
  return 0;
}
