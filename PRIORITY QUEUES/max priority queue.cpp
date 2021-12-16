/*
Code : Max Priority Queue
Send Feedback
Implement the class for Max Priority Queue which includes following functions -
1. getSize -
Return the size of priority queue i.e. number of elements present in the priority queue.
2. isEmpty -
Check if priority queue is empty or not. Return true or false accordingly.
3. insert -
Given an element, insert that element in the priority queue at the correct position.
4. getMax -
Return the maximum element present in the priority queue without deleting. Return -Infinity if priority queue is empty.
5. removeMax -
Delete and return the maximum element present in the priority queue. Return -Infinity if priority queue is empty.
Note : main function is given for your reference which we are using internally to test the class.
*/
#include <vector>
#include<climits>
class PriorityQueue {
    // Complete this class
    vector <int> pq;
    
    public:
    int getSize(){
        return pq.size();
    }
    bool isEmpty(){
        return getSize()==0;
    }
    int getMax()
    {
        if(pq.size()==0) return INT_MIN;
        
        return pq[0];
    }
    void insert(int element)
    {
        pq.push_back(element);
        int ci=pq.size()-1;
        int pi=(ci-1)/2;
        
        while(pi>=0 && pq[pi]<pq[ci])
        {
           // swap
            int temp=pq[ci];
            pq[ci]=pq[pi];
            pq[pi]=temp;
            
            ci=pi;
            pi=(ci-1)/2;
        }
            
    }
    int removeMax()
    {
        if(isEmpty()) return INT_MIN;
        
        int ans = pq[0];
        
        pq[0]=pq[pq.size()-1];
        
        pq.pop_back();
        
        int i=0;
        while (i<pq.size())
        {
            if(2*i+1 >= pq.size()) break; //absence of left child
            else
            {
                if(2*i+2 >= pq.size()) //no right chiid
                {
                    if(pq[i]<pq[2*i+1])
                    {
                        int temp =pq[i];
                        pq[i]=pq[2*i+1];
                        pq[i]=temp;
                        i=2*i+1;
                    }
                    else break;
                }
                else
                {
                    if(pq[2*i+1]>pq[2*i+2]) //left child is max
                    {
                        int temp =pq[i];
                        pq[i]=pq[2*i+1];
                        pq[2*i+1]=temp;
                        i=2*i+1;
                    }
                    else  //right child is max
                    {
                       int temp =pq[i];
                        pq[i]=pq[2*i+2];
                        pq[2*i+2]=temp;
                        i=2*i+2; 
                    }
                }
            }
        }
        
        
        
        return ans;
    }
};
