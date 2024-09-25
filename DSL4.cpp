#include <iostream>
#include <string>
using namespace std;

class Node {
public:
    string text;
    Node* prev;
    Node* next;

    Node()
    {
        text = "None";
        prev = NULL;
        next = NULL;
    }
    Node(string txt) {
        text = txt;
        prev = NULL;
        next = NULL;
    }
};

class TextEditor {
private:
    Node* head;

public:
    TextEditor() {
        head = NULL;
    }

    void insert_end(string txt) {
        Node* newNode = new Node(txt);
        if (head == NULL) {
            head  = newNode;
        }
        else {
            Node *temp = new Node();
            temp = head;
            while(temp->next != NULL)
            {
                temp = temp->next;
            }
            temp->next = newNode;
            newNode->prev = temp;
        }
    }

    void delete_f(string txt) {
        if(head == NULL)
        {
            cout<<"Text buffer is empty.";
        }
        else
        {
            Node *temp= new Node();
            temp=head;
            if(head->text == txt)
            {
                head = head->next;
                cout<<"Text Deleted";
            }
            while(temp->next != NULL)
            {
                if(temp->text == txt)
                {
                    temp->prev->next = temp->next;
                    temp->next->prev = temp->prev;
                    cout<<"Text Deleted";
                    break;
                }
                else{
                    temp=temp->next;
                }
            }
            if(temp->text == txt)
            {
                temp->prev = NULL;
                cout<<"Text Deleted";
            }
            
        }
    }

    void displayText() {
        cout<<"Displaying TextBuffer:"<<endl;
        Node *temp=new Node();
        temp=head;
        while(temp!=NULL)
        {
            cout<<temp->text<<" ";
            temp=temp->next;
        }
    }

    void searchText(string txt) {
        Node* temp = head;
        int pos = 1;
        while (temp != NULL) {
            if (temp->text == txt) {
                cout << "Text found at position: " << pos << endl;
                return;
            }
            temp = temp->next;
            pos++;
        }
        cout << "Text not found." << endl;
    }

    void printReverse() {
        Node *temp=new Node();
        temp=head;
        while(temp->next!=NULL)
        {
            temp=temp->next;
        }
        Node *temp1=new Node();
        temp1=temp;
        while(temp1->prev != NULL)
        {
            cout<<temp->text<<" ";
            temp=temp->prev;
        }
        cout<<temp->text;
    }
};

int main() {
    TextEditor e;
    int choice;
    string text;

    do {
        cout << "\nText Editor Menu:\n";
        cout << "1. Insert text\n";
        cout << "2. Delete text\n";
        cout << "3. Display text\n";
        cout << "4. Search text\n";
        cout << "5. Print text in reverse\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice) {
        case 1:
            cout << "Enter text to insert: ";
            cin>>text;
            e.insert_end(text);
            break;
        case 2:
            cout << "Enter text to delete: ";
            cin>>text;
            e.delete_f(text);
            break;
        case 3:
            cout << "temp text buffer: ";
            e.displayText();
            break;
        case 4:
            cout << "Enter text to search: ";
            cin>>text;
            e.searchText(text);
            break;
        case 5:
            cout << "Text in reverse: ";
            e.printReverse();
            break;
        case 6:
            cout << "Exiting..." << endl;
            break;
        default:
            cout << "Invalid choice." << endl;
        }
    } while (choice != 6);
    return 0;
}
