#include<iostream>
using namespace std;

class songs
{
    public:
    string title;
    songs *next;

    songs()
    {
        title="None";
        next=NULL;
    }

    songs(string a)
    {
        title=a;
        next=NULL;
    }
};

class playlist
{
    private:
    songs *head;

    public:
    playlist()
    {
        head=0;
    }

    void insert_start(string a)
    {
        songs *nn = new songs(a);
        if(head  == NULL)
        {
            //cout<<"List is empty";
            head=nn;
            return;
        }
        else
        {
            nn->next = head;
            head = nn;
        }
    }

    void insert_end(string a)
    {
            songs *temp = new songs();
            temp = head;

            while(temp->next != NULL)
            {
                temp = temp->next;
            }
            songs *nn = new songs(a);
            temp->next = nn;
    }

    void insert_mid(string a,string key)
    {
        songs *nn=new songs(a);
        songs *temp=new songs();
        temp=head;
        if(temp->next ==NULL)
        {
            cout<<"LL has no member ahead.";

        }
        else
        {
            while(temp->title != key)
            {
                temp=temp->next;
            }
            nn->next=temp->next;
            temp->next= nn;
        }
    }

    void print()
    {
        cout<<"Displaying LL:"<<endl;
        songs *temp=new songs();
        temp = head;
        if(head == NULL)
        {
            cout<<"LL is empty";
            return ;
        }
        else
        {
            while(temp != NULL)
            {
                cout<<temp->title<<" ";
                temp=temp->next;
            }
        }
        
    }

    void search(string key)
    {
        songs *temp = new songs();
        temp = head;
        int count=0;
        while(temp != NULL)
        {
            if(temp->title == key)
            {
                cout<<"\nSong found.";
                cout<<"\nPlaying the song.";
                count++;
                break;
            }
            else{
                temp=temp->next;
            }

        }
        if(count == 0){
            cout<<"\nSong not found";
        }
        
    }

    void delete_start()
    {
        if(head == NULL)
        {
            cout<<"LL is empty";
        }
        else{
            head = head->next;
        }
    }

    void delete_end()
    {
        if(head == NULL)
        {
            cout<<"LL is empty.";
        }
        else{
            songs *temp= new songs();
            songs *temp1= new songs();
            temp= head;
            while(temp->next != NULL)
            {
                temp1 = temp;
                temp = temp->next;
            }
            temp1->next = NULL;
        }
    }

    void delete_mid(string key)
    {
        if(head == NULL)
        {
            cout<<"LL is empty.";
        }
        else
        {
            songs *temp= new songs();
            songs *temp1=new songs();
            temp=head;
            while(temp->title != key)
            {
                temp1=temp;
                temp = temp->next;
            }
            temp1->next = temp->next;
        }
    }
};

int main()
{
    playlist p;
    string song,ch,key;
    int n;
    do
   {
        cout<<"\n1.Insert song at start \n2.Insert song at the end \n3.To print playlist \n4.To search song \n5.To add song in between \n6.Delete song at start \n7.Delete song at mid \n8.Delete song at end \n";
        cin>>n;
        switch(n)
        {
            case 1:cout<<"Enter data : ";
                    cin>>song;
                    p.insert_start(song);
                    break;
            case 2:cout<<"Enter data : ";
                    cin>>song;
                    p.insert_end(song);
                    break;
            case 3:p.print();
                    break;
            case 4:cout<<"Enter the song-title search";
                    cin>>key;
                    p.search(key);
                    break; 
            case 5:cout<<"Enter the value to add node after";
                    cin>>key;
                    cout<<"Enter data : ";
                    cin>>song;
                    p.insert_mid(song,key);
                    break;
            case 6:p.delete_start();
                    break;
            case 7:cout<<"Enter song-title to delete.";
                    cin>>key;
                    p.delete_mid(key);
                    break;
            case 8:p.delete_end();
                    break;
            default : break;
        }
        cout<<"\nEnter y to continue : ";
        cin>>ch;
   }while(ch == "y"||ch == "Y");
    return 0;
}