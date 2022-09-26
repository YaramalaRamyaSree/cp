/*
leetcode link - https://leetcode.com/problems/design-circular-queue/
*/

class MyCircularQueue {
    int front;
    vector<int>v;
    int head=0,tail=0,n,size=0;
public:
    MyCircularQueue(int k) {
        v.resize(k);
        n=k;
    }
    
    bool enQueue(int value) {
        if(isFull()) return false;
        if(isEmpty()){
            head=tail=0;
            v[tail]=value;
            size++;
            return true;
        }
        tail++;
        tail=tail%n;
        v[tail]=value;
        size++;
        return true;
    }
    
    bool deQueue() {
        if(isEmpty()) return false;
        head++;
        head=head%n;
        size--;
        return true;
    }
    
    int Front() {
       return  isEmpty()?-1:v[head];
    }
    
    int Rear() {
        return  isEmpty()?-1:v[tail];
    }
    
    bool isEmpty() {
        return size==0;
    }
    
    bool isFull() {
        return size==n;
    }
};
