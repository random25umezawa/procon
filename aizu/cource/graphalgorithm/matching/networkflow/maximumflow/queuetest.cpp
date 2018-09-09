#include <iostream>
#include <queue>

using namespace std;

struct node{
	int index, cost;
};

bool operator<(const node &n1, const node &n2) {
	return n1.cost < n2.cost;
}

int main() {
	priority_queue<node> q;
	node n1{1,5}, n2{2,1}, n3{3,2};
	q.push(n1);
	node *np1 = &(q.top());
	q.push(n2);
	node *np2 = &(q.top());
	q.push(n3);
	node *np3 = &(q.top());
	np1->cost = 0;
	cout << np1 << "," << &(q.top()).cost << endl;
	cout << q.top().index << "," << q.top().cost << endl;
	q.pop();
	cout << q.top().index << "," << q.top().cost << endl;
	q.pop();
	cout << q.top().index << "," << q.top().cost << endl;
	q.pop();
	return 0;
}
