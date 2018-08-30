#include<bits/stdc++.h>
using namespace std;

struct node
{   time_t now ;
    int node_number;
    string nodeId;
    struct node *Parent_reference;
    vector<node *>Child_reference;
    struct node *genesisRefernceNodeId;
    struct owner *on;
    //static int count=0;
    vector<node*>hv;
};

struct owner
{
    int owner_id;
    float Owner_value;
    string Owner_name;

};


struct node *newNode2(struct node *root,struct node * t1,struct owner *temp,int count)
{
    struct node *temp2 =  (struct node *)malloc(sizeof(struct node));
    temp2->now=time(0);
    temp2->nodeId =time(0)+"_"+temp2->on->Owner_name;
    temp2->node_number=count;
    temp2->on = temp;
    temp2->genesisRefernceNodeId=root;
    temp2->Parent_reference=t1;

    temp2->hv.push_back(temp2);
    return temp2;
};

struct owner *newNode(int id,float value,string name)
{
    struct owner *temp =  (struct owner *)malloc(sizeof(struct owner));
    temp->owner_id  = id;
    temp->Owner_value = value;
    temp->Owner_name = name;
    return(temp);
}


void insert(struct node *root,struct node* node, int id,int value,string key,int count)
{


    int sum=0;

    if(node->Child_reference.size()==0)
    {
            return;
    }

    for(int i=0;i<node->Child_reference.size();i++)
    {

        sum+=node->Child_reference[i]->on->Owner_value;
    }
    if(sum - node->on->Owner_value> value)
    {

        struct owner* temp = newNode(id,value,key);
        node->Child_reference.push_back(newNode2(root,node,temp,count));
    }
    else
    {

    for(int i=0;i<node->Child_reference.size();i++)
    {

    insert(root,node->Child_reference[i], id,value,key,count);

    }

    }
}


int diameter(node* root)
{

    if(root==NULL)
        return 0;

    int sum=0;
    vector<int>y;
   for(int i =0; i < root->Child_reference.size();i++)
   {
       sum = diameter( root->Child_reference[i]);
        y.push_back(sum);
   }
    int m=y[0];
    for(int i=1;i<y.size();i++)
    {
        if(y[i]>m)
            m=y[i];
    }

    return m;
}
int main()
{
    struct node *root = NULL;
    struct node *child;
    int count=0;
    string name;
    int id;
    float value;
    cout<<"Enter Owner id"<<endl;
    cin>>id;
    cout<<"Enter Owner value"<<endl;
    cin>>value;
    cout<<"Enter Owner name"<<endl;
    cin>>name;

    struct owner *root1 = newNode( id, value, name);
  root = newNode2(root,NULL,root1, count);
    bool h = true;
    while(h)
    {
    string a;
    cout<<"DO you want to insert more values press YES else NO";
    cin>>a;
    if(a=="YES")
    {
       cout<<"Enter Owner id"<<endl;
    cin>>id;
    cout<<"Enter Owner value"<<endl;
    cin>>value;
    cout<<"Enter Owner name"<<endl;
    cin>>name;
    count++;
    insert(root,root, id,value,name,count);
    }
    else
    {
        h =false;
    }

    }

    cout<<"Longest chain from root"<<endl;
    int Longest_chain =diameter(root);
    cout<<Longest_chain<<endl;

}
