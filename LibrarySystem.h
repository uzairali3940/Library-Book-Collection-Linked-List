#ifndef LIBRARY_SYSTEM_H
#define LIBRARY_SYSTEM_H
#include <string>

// Original Lab 3/4-style library request data and priority queue are retained.
struct BookRequestNode {
    int studentID; std::string studentName; int bookID; std::string bookTitle; int priority;
    BookRequestNode* next;
};
class PriorityQueue {
private: BookRequestNode* front; BookRequestNode* rear; int count;
public:
    PriorityQueue(); void Add(BookRequestNode* request); BookRequestNode* Remove();
    bool IsEmpty() const; bool IsNotEmpty() const; void PrintQueue() const; ~PriorityQueue();
};

// Lab 5 addition: general-purpose singly linked list for the library's book collection.
struct BookNode { int bookID; std::string title; BookNode* next; };
class LinkedList {
private:
    BookNode* head; int count; BookNode* GetNodeAt(int index) const; void Clear();
public:
    LinkedList(); LinkedList(const LinkedList& other); LinkedList& operator=(const LinkedList& other); ~LinkedList();
    void Insert(BookNode* book); BookNode* Remove(); void InsertAt(BookNode* book, int index); BookNode* RemoveAt(int index);
    bool Swap(int index1, int index2); void Sort(); void Reverse(); void Print() const;
    bool IsEmpty() const; bool IsNotEmpty() const; int Size() const;
};
BookNode* CreateBook(int id, const std::string& title);
#endif
