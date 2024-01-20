#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

class Hash
{
    int l_roll[10];
    string l_name[10];
    int l_chain[10];
    int q_roll[10];
    string q_name[10];
    int q_chain[10];
    int count;

    public:

    Hash()
    {
        count = 0;
        for(int i = 0;i < 10;i++)
        {
            l_roll[i] = -1;
            l_chain[i] = -1;
            l_name[i] = "x";
            q_roll[i] = -1;
            q_chain[i] = -1;
            q_name[i] = "x";

        }
    }
    
    void chain_wo_replace(int,string);
    void chain_with_replace(int,string);
    void display();
    void insert();
    void find();
    void delete_key();
    void shifting(int);
    void findfunc(int r,int index,int roll[],int chain[],string name[]);

};

void Hash::insert()
{
    int r;
    string n;
    int flag = 1;
    int opt,index;

    while (flag == 1)
    {
        cout<<"Choose your option:- "<<endl;
        cout<<"1] Insert roll number and name of a student"<<endl;
        cout<<"2] Exit"<<endl;
        cout<<"ans: ";
        cin>>opt;

        switch (opt)
        {
        case 1:
            count++;
            if (count >= 11)
            {
                cout<<"You have used maximum space available in the hash table!!"<<endl;
                flag = 0;
                break;
            }
            cout<<"Enter roll number: ";
            cin>>r;
            cout<<"Enter name: ";
            cin>>n;
            chain_wo_replace(r,n);
            chain_with_replace(r,n);
            break;
        case 2:
            flag = 0;
            break;
        default:
            cout<<"OOPS!!! you typed invalid option"<<endl;
            break;
        }
    }
    
}

void Hash::display()
{
    int flag = 1;
    int opt;
    while (flag == 1)
    {
        cout<<"Choose your option:- "<<endl;
        cout<<"1] Chaining without replacement"<<endl;
        cout<<"2] Chaining with replacement"<<endl;
        cout<<"3] Exit"<<endl;
        cout<<"ans: ";
        cin>>opt;
        switch (opt)
        {
        case 1:
            cout<<"INDEX         ROLL              NAME           CHAIN"<<endl;
            for(int i = 0;i < 10;i++)
            {
                cout<<i<<"              "<<l_roll[i]<<"              "<<l_name[i]<<"              "<<l_chain[i]<<endl;
            }
            break;
        case 2:
            cout<<"INDEX         ROLL              NAME           CHAIN"<<endl;
            for(int i = 0;i < 10;i++)
            {
                cout<<i<<"              "<<q_roll[i]<<"              "<<q_name[i]<<"              "<<q_chain[i]<<endl;
            }
            break;
        case 3:
            flag = 0;
            break;
        default:
            cout<<"OOPS!!! you typed invalid option"<<endl;
            break;
        }
    }
    
}

void Hash::chain_wo_replace(int r,string n)
{
    int index,temp,flag = 1;
    int chain = -1;

    index = r%10;
    temp = index;
    while (l_roll[index] != -1)
    {
        flag = 0;
        index++;
        
        if(index == 10)
        {
            index = 0;
        }
    }
    
    while(flag == 0)
    {
        if(l_chain[temp] != -1)
        {
            temp = l_chain[temp];
        }
        else
        {
            chain = index;
            flag = 1;
        }
    }

    l_roll[index] = r;
    l_name[index] = n;
    l_chain[temp] = chain; 

}

void Hash::chain_with_replace(int r,string n)
{
    int index,temp = -1,flag = 1,temp2;
    int chain = -1;
    index = r%10;
    temp2 = index;

    if((q_roll[index] % 10) != (r%10) && q_roll[index] != -1)
    {
        temp = index;
    }

    while (q_roll[index] != -1)
    {
        flag = 0;
        index++;
        if(index == 10)
        {
            index = 0;
        }
    }

    while (flag == 0)
    {
        if(q_chain[temp2] != -1)
        {
            temp2 = q_chain[temp2];
        }
        else
        {
            chain = index;
            flag = 1;
        }
    }
    
    if(temp != -1)
    {
        q_roll[index] = q_roll[temp];
        q_name[index] = q_name[temp];
    
        q_roll[temp] = r;
        q_name[temp] = n;
        q_chain[temp] = index;
        
    }
    else
    {
        q_roll[index] = r;
        q_name[index] = n;
        q_chain[temp2] = chain;
    }
    

}

void Hash::find()
{
    int opt;
    int r,index;
    int stop_flag = 0,find_flag = 0;

    while(stop_flag == 0)
    {

    cout<<endl<<"1] Find data using roll number"<<endl;
    cout<<"2] Exit"<<endl;
    cout<<"ans: ";
    cin>>opt;

    switch (opt)
    {
    case 1:
        cout<<endl<<"Enter roll number of he student: ";
        cin>>r;
        index = r%10;
        findfunc(r,index,l_roll,l_chain,l_name);
        findfunc(r,index,q_roll,q_chain,q_name);
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

void Hash::delete_key()
{
    int r,opt;
    int stop_flag = 0,find_flag = 0;
    int q = -1;

    while (stop_flag == 0)
    {
    

    cout<<endl<<"1] Delete data from the hash table"<<endl;
    cout<<"2] Display Hash table"<<endl;
    cout<<"3] Exit"<<endl;
    cout<<"ans:";
    cin>>opt;

    switch(opt)
    {
        case 1:
            find_flag = 0;
            cout<<"enter roll number of the student to delete data:- ";
            cin>>r;
            for(int i = 0;i < 10;i++)
            {
                if(l_roll[i] == r)
                {
                    find_flag = 1;
                    if(l_chain[i] != -1)
                    {
                        shifting(i);
                    }
                    else
                    {
                        l_roll[i] = -1;
                        l_name[i] = "x";
                    }
                }
                if(q_roll[i] == r)
                {
                    find_flag = 1;
                    q_roll[i] = -1;
                    q_name[i] = "x";
                    q_chain[i] = -1;

                }

            }
            if(find_flag == 0)
            {
                cout<<"The roll number you entered is not present in the hash table!!"<<endl;
            }
            else
            {
                cout<<"The data of the student with roll number "<<r<<" has been deleted successfully!!"<<endl;
            }
            break;
        case 2:
            display();
            break;
        case 3:
            stop_flag = 1;
            break;
        default:
            cout<<"OOPS!!! you typed invalid option"<<endl;
            break;
    }

    }

}

void Hash::shifting(int i)
{
    int k = i;
    while(l_chain[k] != -1)
    {
        l_roll[k] = l_roll[l_chain[k]];
        l_name[k] = l_name[l_chain[k]]; 
        l_chain[k] = l_chain[l_chain[k]];
        k = l_chain[k];
    }

    l_roll[k] = -1;
    l_name[k] = "x";

}

void Hash::findfunc(int r,int index,int roll[],int chain[],string name[])
{
    if(roll[index] == r)
    {
        cout<<"Chaining without replacement =>"<<endl;
        cout<<"INDEX         ROLL              NAME           CHAIN"<<endl;
        cout<<index<<"              "<<roll[index]<<"              "<<name[index]<<"              "<<chain[index]<<endl;
    }
    else if(chain[index] != -1)
    {
        index = chain[index];
        findfunc(r,index,roll,chain,name);
    }
    else
    {
        cout<<"The roll number you entered is not present in the hash table!!"<<endl;
    }
    
}

int main()
{

    Hash h;
    bool stop = false;
    int opt;

    while (stop == false)
    {
    
    cout<<"-------------------MENU-------------------"<<endl;
    cout<<"1] Enter data"<<endl;
    cout<<"2] Display hash table"<<endl;
    cout<<"3] Find data"<<endl;
    cout<<"4] Delete data"<<endl;
    cout<<"5] Exit"<<endl;
    cout<<"ans: ";
    cin>>opt;

    switch (opt)
    {
    case 1:
        h.insert();
        break;
    case 2:
        h.display();
        break;
    case 3:
        h.find();
        break;
    case 4:
        h.delete_key();
        break;
    case 5:
        stop = true;
        break;
    default:
        cout<<"OOPS!!! you typed invalid option"<<endl;
        break;
    }

    }

    return 0;

}

