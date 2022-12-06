#include "myprorityqueue.h"

int main(){
    MyPriorityQueue<int> pq;
    pq.push(1);
    pq.push(11);
    pq.push(3);
    pq.push(4);
    pq.display();
    return 0;
}