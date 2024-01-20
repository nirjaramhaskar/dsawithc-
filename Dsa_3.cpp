#include <iostream>

using namespace std;

class node
{
    public:

    int val;
    node *left;
    node *right;

    node()
    {
        left = NULL;
        right = NULL;
    }

    node(int val)
    {
        this->val = val;
        this->left = NULL;
        this->right = NULL;
    }
    
};

class BST
{
    node *root;
    public:
    
    BST()
    {
        root = NULL;
    }
    
    void insert();
    void insertlogic(node *n,node *r,int data);
    void display();
    void traverse(node *temp);
    void getnodes();
    int longestpath_logic(node *r);
    void getmin();
    int minlogic(node *r);
    // void change();
    void search();
    void searchlogic(int,node *r);

};

void BST::insert()
{
    cout<<endl;
    cout<<"Insertion of a node :- "<<endl;
    int v,opt;
    int stop_flag = 0;
    
    while(stop_flag == 0)
    {
    cout<<"1] Insert a node"<<endl;
    cout<<"2] Exit"<<endl;
    cout<<"ans: ";
    cin>>opt;
    
    if(opt == 1)
    {
    cout<<"enter value of the node : ";
    cin>>v;

    node *newnode = new node(v);
    if(root == NULL)
    {
        root = newnode;
        cout<<endl<<"Insertion succesfull!!"<<endl;
        cout<<endl;
    }
    else
    {
        insertlogic(newnode,root,v);
        cout<<endl<<"Insertion succesfull!!"<<endl;
        cout<<endl;
    }
    }
    else if(opt == 2)
    {
        stop_flag = 1;
    }
    else
    {
        cout<<"OOPS!!! you typed invalid option"<<endl;
    }

    }
}

void BST::insertlogic(node *n,node *r,int data)
{
    if(data <= r->val)
    {
        if(r->left != NULL)
        {
            insertlogic(n,r->left,data);
        }
        else
        {
            r->left = n;
        }
    }
    else
    {
        if(r->right != NULL)
        {
            insertlogic(n,r->right,data);
        }
        else
        {
            r->right = n;
        }
    }
}

void BST::display()
{
    if(root == NULL)
    {
        cout<<endl<<"Tree is empty!!"<<endl;
    }
    else
    {
        cout<<endl;
        cout<<"Binary Search Tree"<<endl;
        traverse(root);
        cout<<endl;
    }

    cout<<endl;
}

void BST::traverse(node *temp)
{
    if(temp != NULL)
    {
        traverse(temp->left);
        cout<<temp->val<<" - ";
        traverse(temp->right);
    }
}

void BST::search()
{
    cout<<endl<<"Search =>"<<endl;
    int opt,key;
    int stop_flag = 0;
    while(stop_flag == 0)
    {
    cout<<endl<<"1] Search node in the binary search tree"<<endl;
    cout<<"2] Exit"<<endl;
    cout<<"ans: ";
    cin>>opt;

    switch(opt)
    {
        case 1:
            cout<<endl<<"Enter value of the node to search: ";
            cin>>key;
            if(root == NULL)
            {
                cout<<"Tree is empty!!"<<endl;
                return;
            }
            searchlogic(key,root);
            break;
        case 2:
            stop_flag = 1;
            break;
        default: 
            cout<<"OOPS!!! you typed invalid option"<<endl;
            break;
    }
    }
}

void BST::searchlogic(int k,node *r)
{
    if(r != NULL)
    {
    if(k < r->val)
    {
        searchlogic(k,r->left);
    }
    else if(k > r->val)
    {
        searchlogic(k,r->right);
    }
    else
    {
        cout<<endl<<"Node found!!"<<endl;
        cout<<"Node address :- "<<r<<endl;
    }
    }
    else
    {
        cout<<"The node is not present in the tree :("<<endl;
    }
}

void BST::getmin()
{
    if(root == NULL)
    {
        cout<<"Tree is empty"<<endl;
        return;
    }

    int min = minlogic(root);
    cout<<"Minimum value in the tree is "<<min<<endl;
}

int BST::minlogic(node *r)
{
    if(r->left != NULL)
    {
        minlogic(r->left);
    }
    else
    {
        return r->val;
    }
}

void BST::getnodes()
{
    int n;
    n = longestpath_logic(root);

    cout<<"Number of nodes in longest path from the root = "<<n<<endl;
}

int BST::longestpath_logic(node *r)
{
    if(r == NULL)
    {
        return 0;
    }

    int left_path = longestpath_logic(r->left);
    int right_path = longestpath_logic(r->right);

    return max(left_path,right_path) + 1;

}

int main()
{
    BST tree;
    int opt;
    bool stop = false;

    while (stop == false)
    {
        cout<<"------------------MENU------------------"<<endl;
        cout<<"1] Insert new node"<<endl;
        cout<<"2] Find number of nodes in the longest path from root"<<endl;
        cout<<"3] Minimum data value in the tree"<<endl;
        cout<<"4] Change the tree to swap left and right pointer roles"<<endl;
        cout<<"5] Search value"<<endl;
        cout<<"6] Display binary search tree"<<endl;
        cout<<"7] Exit"<<endl;
        cout<<"ans: ";
        cin>>opt;
        switch (opt)
        {
        case 1:
            tree.insert();
            break;
        case 2:
            tree.getnodes();
            break;
        case 3:
            tree.getmin();
            break;
        // case 4:
        //     tree.change();
        //     break;
        case 5:
            tree.search();
            break;
        case 6:
            tree.display();
            break;
        case 7:
            stop = true;
            break;
        default:
            cout<<"OOPS!!! you typed invalid option"<<endl;
            break;
        }
    }
    
    return 0;
}