#include<iostream>
using namespace std;

class history
{
    public:
    int top1=-1,top2=-1;
    string s1[10];
    string s2[10];

    void push(string a)
    {
        if(top1 >= 9)
        {
            cout<<"Stack is full"<<endl;
        }
        else
        {
            top1++;
            s1[top1]=a;
        }
    }

    void peek()
    {
        if(top1==-1)
        {
            cout<<"No current page."<<endl;
        }
        else
        {
            cout<<"Current page is: "<<s1[top1]<<endl;
        }
    }

    void n_back()
    {
        cout<<top1;
        if(top1 == -1)
        {
            cout<<"No history => Can't Navigate back."<<endl;
        }
        else
        {
            top2++;
            s2[top2] = s1[top1];
            top1--; 
        } 
    }

    void isempty()
    {
        if(top1 == -1)
        {
            cout<<"No history."<<endl;
        }
        else
        {
            cout<<"History Available."<<endl;
        }
    }

    void v_history()
    {
        if(top1 == -1)
        {
            cout<<"No history"<<endl;
        }
        else
        {
            cout<<"History: "<<endl;
            for(int i=top1-1;i>=0;i--)
            {
                cout<<s1[i]<<endl;
            }
        }
    }
    void delete_h()
    {
        if(top1 == -1)
        {
            cout<<"No History to delete."<<endl;
        }
        else
        {
            top1 = -1;
            top2=-1;
            cout<<"History deleted successfully."<<endl;
        }
    }
};

int main()
{
    history h;
    int m;
    string ch,x;
    do
    {
        cout<<"\n1.To add visited pages \n2.To Navigate back \n3.To View Current Page \n4.To check if History is empty \n5.To View History \n6.To delete history"<<endl;
        cout<<"Enter respective no. to proceed: ";
        cin>>m;
        switch(m)
        {
            case 1:cout<<"Enter url to add: ";
                    cin>>x;
                    h.push(x);
                    cout<<"Element Added."<<endl;
                    break;
            case 2: h.n_back();
                    h.peek();
                    break;
            case 3: h.peek();
                    break;
            case 4: h.isempty();
                    break;
            case 5: h.v_history();
                    break;
            case 6: h.delete_h();
                    break;
            default: cout<<"To continue enter y: ";
                    cin>>ch;
        }
        cout<<"To continue enter y: ";
        cin>>ch;
    } while (ch=="y" || ch=="y");
    return 0;
}