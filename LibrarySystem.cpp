#include "LibrarySystem.h"
#include <iostream>
#include <utility>

PriorityQueue::PriorityQueue() : front(nullptr), rear(nullptr), count(0) {}
void PriorityQueue::Add(BookRequestNode* request) {
    if (!request) return; request->next=nullptr;
    if (!front) front=rear=request;
    else if (request->priority < front->priority) { request->next=front; front=request; }
    else { BookRequestNode* current=front; while(current->next && current->next->priority<=request->priority) current=current->next;
        request->next=current->next; current->next=request; if(!request->next) rear=request; }
    ++count;
}
BookRequestNode* PriorityQueue::Remove() {
    if(!front) return nullptr; BookRequestNode* item=front; front=front->next;
    if(!front) rear=nullptr; item->next=nullptr; --count; return item;
}
bool PriorityQueue::IsEmpty() const { return front==nullptr; }
bool PriorityQueue::IsNotEmpty() const { return front!=nullptr; }
void PriorityQueue::PrintQueue() const {
    if(IsEmpty()){ std::cout<<"No pending book requests.\n"; return; }
    for(BookRequestNode* p=front;p;p=p->next) std::cout<<"\nStudent ID: "<<p->studentID<<"\nStudent Name: "<<p->studentName<<"\nBook ID: "<<p->bookID<<"\nBook Title: "<<p->bookTitle<<"\nPriority: "<<p->priority<<"\n-----------------------------\n";
}
PriorityQueue::~PriorityQueue(){ while(front){BookRequestNode* t=front;front=front->next;delete t;} rear=nullptr; }

LinkedList::LinkedList():head(nullptr),count(0){}
BookNode* LinkedList::GetNodeAt(int index) const { if(index<0||index>=count)return nullptr; BookNode* p=head;while(index--)p=p->next;return p; }
void LinkedList::Clear(){while(head){BookNode* t=head;head=head->next;delete t;}count=0;}
LinkedList::LinkedList(const LinkedList& other):head(nullptr),count(0){for(BookNode*p=other.head;p;p=p->next)InsertAt(CreateBook(p->bookID,p->title),count);}
LinkedList& LinkedList::operator=(const LinkedList& other){if(this==&other)return *this;Clear();for(BookNode*p=other.head;p;p=p->next)InsertAt(CreateBook(p->bookID,p->title),count);return *this;}
LinkedList::~LinkedList(){Clear();}
void LinkedList::Insert(BookNode* book){if(!book)return;book->next=head;head=book;++count;}
BookNode* LinkedList::Remove(){if(!head)return nullptr;BookNode*t=head;head=head->next;t->next=nullptr;--count;return t;}
void LinkedList::InsertAt(BookNode* book,int index){if(!book)return;if(index<0)index=0;if(index>count)index=count;if(index==0){Insert(book);return;}BookNode*p=GetNodeAt(index-1);book->next=p->next;p->next=book;++count;}
BookNode* LinkedList::RemoveAt(int index){if(index<0||index>=count)return nullptr;if(index==0)return Remove();BookNode*p=GetNodeAt(index-1);BookNode*t=p->next;p->next=t->next;t->next=nullptr;--count;return t;}
bool LinkedList::Swap(int a,int b){if(a<0||a>=count||b<0||b>=count)return false;if(a==b)return true;BookNode*x=GetNodeAt(a),*y=GetNodeAt(b);std::swap(x->bookID,y->bookID);std::swap(x->title,y->title);return true;}
void LinkedList::Sort(){for(BookNode*i=head;i;i=i->next)for(BookNode*j=i->next;j;j=j->next)if(i->bookID>j->bookID){std::swap(i->bookID,j->bookID);std::swap(i->title,j->title);}}
void LinkedList::Reverse(){BookNode*prev=nullptr,*cur=head;while(cur){BookNode*n=cur->next;cur->next=prev;prev=cur;cur=n;}head=prev;}
void LinkedList::Print() const {if(IsEmpty()){std::cout<<"\nBook collection is empty.\n";return;}std::cout<<"\nIndex\tBook ID\tTitle\n-----------------------------------\n";int i=0;for(BookNode*p=head;p;p=p->next)std::cout<<i++<<"\t"<<p->bookID<<"\t"<<p->title<<'\n';std::cout<<"Total books: "<<count<<'\n';}
bool LinkedList::IsEmpty() const{return head==nullptr;} bool LinkedList::IsNotEmpty() const{return head!=nullptr;} int LinkedList::Size() const{return count;}
BookNode* CreateBook(int id,const std::string& title){return new BookNode{id,title,nullptr};}
