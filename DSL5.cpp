#include<iostream>
using namespace std;

class node{
    public:
    string route;
    node *next;
    node *prev;
    public:
    node() 
    {
        route="None";
        next = NULL;
        prev = NULL;
    }
    node(string d)
    {
        route=d;
        next = NULL;
        prev = NULL;
    }
};

class dLL
{
    private:
    node *head;

    public:

    dLL()
    {
        head=0;
    }

    void insert_start(string d)
    {
        node *nn =new node(d);
        if(head == NULL)
        {
            head = nn;
            return;
        }
        else
        {
            node *temp = new node();
            temp = head;
            while(temp->next != head && temp->next != NULL)
            {
                temp=temp->next;
            }
            head->prev=nn;
            nn->next = head;
            nn->prev = temp;
            temp->next = nn;
            head = nn; 
        }
    }

    void insert_mid(string d,string key)
    {
        node *nn =new node(d);
        if(head == NULL)
        {
            head = nn;
            return;
        }
        else
        {
            node *temp = new node();
            node *temp1 = new node();
            temp = head;
            while(temp->route != key)
            {
                temp=temp->next;
            }
            temp1 = temp->next;
            nn->next = temp->next;
            nn->prev = temp;
            temp->next = nn;
            temp1->prev = nn;
        }
    }

    void insert_end(string d)
    {
        node *nn =new node(d);
        if(head==NULL)
        {
            head = nn;
            return;
        }
        else{
            node *temp = new node();
            temp = head;
            while(temp->next != head && temp->next !=NULL)
            {
                temp = temp->next;
            }
            temp->next = nn;
            head->prev = nn;
            nn->prev = temp;
            nn->next = head;
        }
    }

    void print_reverse()
    {
        cout<<"Displaying reverse LL:"<<endl;
        node *temp=new node();
        node *temp1=new node();
        temp=head;
        while(temp->next != head && temp->next != NULL)
        {
            temp=temp->next;
        }
        temp1 = temp;
        while(temp->prev != temp1 && temp->prev != NULL)
        {
            cout<<temp->route<<" ";
            temp = temp->prev;
        }
        cout<<temp->route<<" ";
    }
    void print()
    {
        cout<<"Displaying LL:"<<endl;
        node *temp=new node();
        temp=head;
        while(temp->next != head && temp->next != NULL)
        {
            cout<<temp->route<<" ";
            temp=temp->next;
        }
        cout<<temp->route<<" ";
    }

    void delete_start()
    {
        if(head==NULL)
        {
            cout<<"Route not present.";
        }
        else
        {
            node *temp = new node();
            temp = head;
            while(temp->next != head && temp->next !=NULL)
            {
                temp = temp->next;
            }
            head = head->next;
            head->prev = temp;
            temp->next = head;
        }
    }
    void delete_mid(string k)
    {
        if(head==NULL)
        {
            cout<<"Route not present.";
        }
        else
        {
            node *temp = new node();
            temp = head;
            while(temp->route != k)
            {
                temp=temp->next;
            }
            temp->prev->next = temp->next;
            temp->next->prev = temp->prev;
        }
    }
    void delete_end()
    {
        if(head == NULL)
        {
            cout<<"LL is empty";
            return;
        }
        else{
            node *temp = new node();
            temp = head;
            while(temp->next != head)
            {
                temp = temp->next;
            }
            temp->prev->next = head;
        }
    }
};

int main()
{
    dLL l;
    string r,key,ch;
    int n;

    do
   {
        cout<<"\n1.Add route at start \n2.Add route at the end \n3.Add route in between \n4.To print route \n5.To print reverse route \n6.Delete route at start \n7.Delete route at mid \n8.Delete route at end \n";
        cin>>n;
        switch(n)
        {
            case 1:cout<<"Enter route : ";
                    cin>>r;
                    l.insert_start(r);
                    break;
            case 2:cout<<"Enter route : ";
                    cin>>r;
                    l.insert_end(r);
                    break;
            case 3:cout<<"Enter the route no. to add next route after";
                    cin>>key;
                    cout<<"Enter route : ";
                    cin>>r;
                    l.insert_mid(r,key);
                    break;
            case 4:l.print();
                    break;
            case 5:l.print_reverse();
                    break;
            case 6:l.delete_start();
                    break;
            case 7:cout<<"Enter route to delete.";
                    cin>>key;
                    l.delete_mid(key);
                    break;
            case 8:l.delete_end();
                    break;
            default : break;
        }
        cout<<"\nEnter y to continue : ";
        cin>>ch;
   }while(ch == "y"||ch == "Y");
    return 0;
}