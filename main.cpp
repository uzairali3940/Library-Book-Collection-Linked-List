#include "LibrarySystem.h"
#include <iostream>
#include <limits>
using namespace std;
int readInt(const string& prompt){int x;while(true){cout<<prompt;if(cin>>x)return x;cout<<"Invalid input. Enter a number.\n";cin.clear();cin.ignore(numeric_limits<streamsize>::max(),'\n');}}
void addBookToCollection(LinkedList& books){int id=readInt("Enter Book ID: ");string title;cout<<"Enter Book Title: ";getline(cin>>ws,title);int index=readInt("Enter index (0 to "+to_string(books.Size())+"): ");books.InsertAt(CreateBook(id,title),index);cout<<"Book added to collection.\n";}
int main(){
    PriorityQueue requests; LinkedList books; int choice;
    // Original priority-queue workflow retained; Lab 5 collection list added separately.
    books.InsertAt(CreateBook(103,"Operating Systems"),0);books.InsertAt(CreateBook(101,"Data Structures"),1);books.InsertAt(CreateBook(105,"Computer Networks"),2);books.InsertAt(CreateBook(102,"Database Systems"),3);books.InsertAt(CreateBook(104,"Software Engineering"),4);
    do{
        cout<<"\n===== Library System =====\n1. Add Book Request (original)\n2. Process Highest Priority Request (original)\n3. Display All Requests (original)\n4. Check Request Queue Status (original)\n5. Display Book Collection\n6. Insert Book at Head\n7. Remove Book from Head\n8. Insert Book at Index\n9. Remove Book at Index\n10. Swap Books\n11. Sort Books by ID\n12. Reverse Book Collection\n13. Check Collection Status\n14. Exit\n";
        choice=readInt("Enter your choice: ");
        switch(choice){
        case 1:{BookRequestNode*r=new BookRequestNode{};r->studentID=readInt("Enter Student ID: ");cout<<"Enter Student Name: ";getline(cin>>ws,r->studentName);r->bookID=readInt("Enter Book ID: ");cout<<"Enter Book Title: ";getline(cin>>ws,r->bookTitle);r->priority=readInt("Enter Priority (1=Urgent, 2=Assignment, 3=Normal): ");if(r->priority<1||r->priority>3){cout<<"Invalid priority; request not added.\n";delete r;}else{requests.Add(r);cout<<"Book request added successfully!\n";}break;}
        case 2:{BookRequestNode*r=requests.Remove();if(!r)cout<<"Queue is empty.\n";else{cout<<"Processed request: "<<r->studentName<<" - "<<r->bookTitle<<" (priority "<<r->priority<<")\n";delete r;}break;}
        case 3:requests.PrintQueue();break;
        case 4:cout<<(requests.IsEmpty()?"Request queue is empty.\n":"Request queue is not empty.\n");break;
        case 5:books.Print();break;
        case 6:{int id=readInt("Enter Book ID: ");string title;cout<<"Enter Book Title: ";getline(cin>>ws,title);books.Insert(CreateBook(id,title));cout<<"Book inserted at head.\n";break;}
        case 7:{BookNode*r=books.Remove();if(!r)cout<<"Collection is empty.\n";else{cout<<"Removed: "<<r->bookID<<" - "<<r->title<<'\n';delete r;}break;}
        case 8:addBookToCollection(books);break;
        case 9:{int i=readInt("Enter index to remove: ");BookNode*r=books.RemoveAt(i);if(!r)cout<<"Invalid index or empty collection.\n";else{cout<<"Removed: "<<r->bookID<<" - "<<r->title<<'\n';delete r;}break;}
        case 10:{int a=readInt("Enter first index: "),b=readInt("Enter second index: ");cout<<(books.Swap(a,b)?"Books swapped.\n":"Invalid index.\n");break;}
        case 11:books.Sort();cout<<"Books sorted by ID.\n";break;
        case 12:books.Reverse();cout<<"Collection reversed.\n";break;
        case 13:cout<<(books.IsEmpty()?"Collection is empty.\n":"Collection is not empty.\n");cout<<"Total books: "<<books.Size()<<'\n';break;
        case 14:cout<<"Exiting. Dynamically allocated memory will be released.\n";break;
        default:cout<<"Invalid choice. Select 1-14.\n";
        }
    }while(choice!=14);return 0;
}
