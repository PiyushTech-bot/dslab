#include <iostream>
#include <string>

using namespace std;

struct PrintNode{
    string docName;
    int pages;
    PrintNode* next;

    PrintNode(string name, int p){
        docName = name;
        pages = p;
        next = nullptr;
    }
};

class PrintSpooler{
private:
    PrintNode* head;
    PrintNode* tail;
    int pendingCount;

public:
    PrintSpooler(){
        head = nullptr;
        tail = nullptr;
        pendingCount = 0;
    }

    //enqueues a print job at the tail in O(1) time 
    void addJob(string docName, int pages){
        PrintNode* newNode = new PrintNode(docName, pages);
        if(tail == nullptr){
            head = tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
        pendingCount++;
    }

    // Dequeues and processes the job from the head in O(1) time
    void processJob(){
        if(head == nullptr){
            cout << "Buffer Empty" << endl;
            return;
        }
        cout << "Printed: \"" << head->docName << "\" (" << head->pages << " pages)" << endl;
        PrintNode* temp = head;
        head = head->next;
        delete temp; // free memory of the processed job

        if(head == nullptr){
            tail = nullptr; // list is now empty, reset tail as well

        }
        pendingCount--;
    }

    int getPendingCount(){
        return pendingCount;
    }

    ~PrintSpooler(){
        while(head != nullptr){
            PrintNode* temp = head;
            head = head->next;
            delete temp;
        }
    }
};

int main(){
    PrintSpooler spooler;

    // input
    spooler.addJob("Lab_Report.pdf", 5);
    spooler.addJob("Notes.pdf", 2);

    // processing jobs in FIFO order
    spooler.processJob();
    spooler.processJob();

    // additional processing call to demonstrate "buffer empty" message
    spooler.processJob();

    return 0;
    
}