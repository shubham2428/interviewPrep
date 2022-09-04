#include<bits/stdc++.h>
using namespace std;


int main(){

    priority_queue<int> pq;  // this is also called as max heap
    pq.push(3);
    pq.push(7);
    pq.push(9);

    // if we want to print the highest element which is at top

    pq.top(); // it will print 9


    /// if we want to create min heap

    priority_queue<int, vector<int> , greater<int> > pq2; // this is syntx for creating min heap
    pq2.push(3);
    pq2.push(7);
    pq2.push(9);

    pq.top() // it will print the smallest element


}