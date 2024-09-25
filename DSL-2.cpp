#include<iostream>
using namespace std;

class employee
{
    private:
    string emp_name;
    int emp_id;
    float emp_salary;
    public:
    void input();
    void display();
    void qs(employee e[],int f,int l);
    void merge_sort(employee e[],int l,int r);
    void merge(employee e[],int l,int m,int r);
};
void employee :: input()
    {
        cout<<"Enter name: ";
        cin>>emp_name;
        cout<<"Enter Employee ID: ";
        cin>>emp_id;
        cout<<"Enter salary: ";
        cin>>emp_salary;
    }
void employee :: display()
    {
        cout<<"Employee ID: "<<emp_id<<endl;
        cout<<"Employee Name: "<<emp_name<<endl;
        cout<<"Employee Salary: "<<emp_salary<<endl;
    }
void employee :: qs(employee e[],int f,int l)
    {
        if(f<l)
        {
            int pivot=f;
            int i=f+1;
            int j=l;
            while(i<j)
            {
                while(e[i].emp_id < e[pivot].emp_id)
                {i++;}
                while(e[j].emp_id > e[pivot].emp_id)
                {j--;}
                if(i<j)
                {
                    employee temp=e[i];
                    e[i]=e[j];
                    e[j]=temp;
                }
                else{
                    break;
                }
            }
            employee t;
            t=e[j];
            e[j]=e[pivot];
            e[pivot]=t;

            qs(e,f,j-1);
            qs(e,j+1,l);
        }
    }
void employee ::merge(employee e[],int l,int m,int r)
{
    int n1=m-l+1 , n2=r-m;
    employee L[n1],R[n2];

    for(int i=0;i<n1;i++)
    {
        L[i]=e[l+i];
    }

    for(int j=0;j<n2;j++)
    {
        R[j]=e[m+1+j];
    }

    int x=0,y=0,k=l;
    while(x<n1 && y<n2)
    {
        if(L[x].emp_name<R[y].emp_name){
            e[k]=L[x];
            x++;
        }
        else{
            e[k]=R[y];
            y++;
        }
        k++;
    }

    while(x<n1){
        e[k]=L[x];
        x++;
        k++;
    }
    while(y<n2){
        e[k]=R[y];
        y++;
        k++;
    }
}

void employee :: merge_sort(employee e[],int l,int r)
{
    if(l<r)
    {
        int mid= (l+r)/2;
        merge_sort(e,l,mid);
        merge_sort(e,mid+1,r);
        merge(e,l,mid,r);
    }
    else
        return;
}
int main()
{
    employee e[20],x;
    int n,f=0,m;
    cout<<"Enter no. of employee: ";
    cin>>n;
    int l=0,r=n-1;
    cout<<"\n1.Add employee \n2.Display Data \n3.Sort acc. to emp-id \n4.Sort acc. to names \n5.Exit \n";
    cout<<'\n';
    while(1)
    {
        cout<<"Enter respective no. to proceed : ";
        cin>>m;
        switch(m)
        {
            case 1: for(int i=0;i<n;i++)
                    {
                        e[i].input();
                    }
                    cout<<'\n';
                    break;
            case 2: for(int i=0;i<n;i++)
                    {
                        cout<<i+1<<")"<<endl;
                        e[i].display();
                    }
                    cout<<'\n';
                    break;
            case 3:x.qs(e,f,n-1);
                    cout<<'\n';
                    break;
            case 4: x.merge_sort(e,l,r);
                    break;
            case 5: return 0;
            default : cout<<"Thank you !";
                    break;
        }
    }
     return 0;
}