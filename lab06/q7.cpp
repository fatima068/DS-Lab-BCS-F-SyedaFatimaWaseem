#include <iostream>
using namespace std;

struct Job {
    int id;
    int priority;
    Job* next;
    Job(int i,int p) : id(i),priority(p), next(nullptr){}
};

class JobQueue{
private:
    Job* front;
    Job* rear;
public:
    JobQueue() : front(nullptr), rear(nullptr) {}
    void addJob(int id, int priority){
        Job* newJob=new Job(id, priority);
        if (rear== nullptr) {
            front= rear= newJob;
        } else {
            rear->next =newJob;
            rear =newJob;
        }
        cout << "Job " << id << " with priority " << priority << " added to queue" <<endl;
    }
    bool isEmpty() {
        return front==nullptr;
    }
    
    Job* getNextJob() {
        if (isEmpty()) return nullptr;
        Job* temp = front;
        front = front->next;
        if (front == nullptr) rear = nullptr;     
        temp->next = nullptr;
        return temp;
    }
    
    void showQueue() {
        if (isEmpty()) {
            cout << "Queue is empty";
            return;
        }
        
        Job* current= front;
        cout << "Jobs in queue: ";
        while (current != nullptr) {
            cout << "J" << current->id << "(P" << current->priority << ") ";
            current = current->next;
        }
        cout << endl;
    }
};

class JobStack {
private:
    Job* top;
public:
    JobStack() : top(nullptr) {}
    
    void push(Job* job) {
        if (job == nullptr) return;
        
        // highest priority at top
        if (top== nullptr ||job->priority >top->priority) {
            job->next= top;
            top = job;
        } else{
            Job* current= top;
            while (current->next!= nullptr &&current->next->priority>=job->priority) {
                current = current->next;
            }
            job->next =current->next;
            current->next=job;
        }
        cout << "Job " << job->id << " pushed to stack\n";
    }
    
    Job* pop() {
        if (top == nullptr) return nullptr;        
        Job* temp = top;
        top = top->next;
        temp->next = nullptr;
        return temp;
    }
    
    bool isEmpty() { return top == nullptr; }
    
    void showStack(){
        if (isEmpty()){
            cout << "Stack empty" <<endl;
            return;
        }
        
        Job* current = top;
        cout << "Jobs in stack (execution order): ";
        while (current != nullptr) {
            cout << "J"<<current->id << "(P" << current->priority << ") ";
            current =current->next;
        }
        cout<< endl;
    }
};
class Scheduler {
private:
    JobQueue arrivalQueue;
    JobStack executionStack;
    
public:
    void newJobArrives(int id, int priority) {
        arrivalQueue.addJob(id, priority);
    }
    
    void moveJobsToStack() {
        cout << "moving jobs from queue to stack " <<endl;
        while (!arrivalQueue.isEmpty()) {
            Job* job = arrivalQueue.getNextJob();
            executionStack.push(job);
        }
    }
    
    void executeJobs() {
        cout <<"\nExecuting jobs from stack...\n";
        while (!executionStack.isEmpty()) {
            Job* job = executionStack.pop();
            cout<< "EXECUTING: Job " << job->id << " with priority " << job->priority << endl;
            delete job;
        }
    }
    
    void showStatus() {
        cout << "current status: " <<endl;
        arrivalQueue.showQueue();
        executionStack.showStack();
      cout << endl ;
    }
};

int main() {
    Scheduler myScheduler;    
    myScheduler.newJobArrives(101, 2);
    myScheduler.newJobArrives(102, 1);
    myScheduler.newJobArrives(103, 3);
    myScheduler.newJobArrives(104, 2);
    myScheduler.showStatus();

    // Move jobs from queue to stack
    myScheduler.moveJobsToStack();
    myScheduler.showStatus();
    // Execute jobs from stack
    myScheduler.executeJobs();
    myScheduler.showStatus();
    
    cout << "more new jobs coming: " << endl;
    myScheduler.newJobArrives(201, 5);
    myScheduler.newJobArrives(202, 1);
    myScheduler.newJobArrives(203, 4);
    
    myScheduler.showStatus();
    myScheduler.moveJobsToStack();
    myScheduler.showStatus();
    myScheduler.executeJobs();}
