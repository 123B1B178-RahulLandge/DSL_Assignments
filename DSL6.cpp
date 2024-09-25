/*Polynomial Addition using linked-list*/
#include<iostream>
using namespace std;

class node
{
    public:
    int coeff,pow;
    node *next;
    node()
    {
        coeff=0;
        pow=0;
        next = NULL;
    }
};

class LL
{
    public:
    node *head;

    LL()
    {
        head=0;
    }

    void create(int x,int y)
    {
        node *nn = new node();
        nn->coeff = x;
        nn->pow = y;
        if(head == NULL)
        {
            head = nn;
            return;
        }
        else
        {
            node *temp = new node();
            temp = head;
            while(temp->next != NULL)
            {
                temp = temp->next;
            }
            temp->next = nn;
        }
    }

    void polyadd(LL l1,LL l2)
    {
        node *temp = new node();
        temp = l1.head;
        node *temp1 = new node();
        temp1 = l2.head;
        
        while(temp != NULL && temp1 != NULL)
        {
            if(temp->pow > temp1->pow)
            {
                node *nn1 =new node();
                nn1->coeff = temp->coeff;
                nn1->pow = temp->pow;
                if(head == NULL)
                {
                    head=nn1;
                }
                else
                {
                    node *t = new node();
                    t = this->head;
                    while(t->next != NULL)
                    {
                        t=t->next;
                    }
                    t->next = nn1;
                }
                temp=temp->next;
            }
            else if(temp1->pow > temp->pow)
            {
                node *nn1 =new node();
                nn1->coeff = temp1->coeff;
                nn1->pow = temp1->pow;
                if(head == NULL)
                {
                    head=nn1;
                }
                else
                {
                    node *t = new node();
                    t = this->head;
                    while(t->next != NULL)
                    {
                        t=t->next;
                    }
                    t->next = nn1;
                }
                temp1 = temp1->next;
            }
            else if(temp->pow == temp1->pow)
            {
                node *nn1 =new node();                              
                nn1->coeff = temp->coeff + temp1->coeff;
                nn1->pow=temp1->pow;
                if(head == NULL)
                {
                    head=nn1;
                }
                else
                {
                    node *t = new node();
                    t = this->head;
                    while(t->next != NULL)
                    {
                        t=t->next;
                    }
                    t->next = nn1;
                }
                temp = temp->next;
                temp1 = temp1->next;
            }
        }
    }

    void print()
    {
        node *temp3=new node();
        temp3=head;
        while(temp3->next !=NULL)
        {
            cout<<temp3->coeff<<"x^"<<temp3->pow<<"+";
            temp3=temp3->next;
        }
        cout<<temp3->coeff<<"x^"<<temp3->pow;
    }
};

int main()
{
    LL l1,l2,l3;
    l1.create(5,7);
    l1.create(3,5);
    l1.create(2,1);
    l2.create(1,8);
    l2.create(6,7);
    l2.create(3,1);
    l3.polyadd(l1,l2);
    cout<<"\nPolynomial 1 : ";
    l1.print();
    cout<<"\nPolynomial 2 : ";
    l2.print();
    cout<<"\nAddition : ";
    l3.print();
    return 0;
}