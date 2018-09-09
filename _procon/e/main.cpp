#include <string>
#include <iostream>
typedef long long ll;

using namespace std;

struct node{
	node *parent;
	vector<node> nodes;
	int num;
}

string str;
int cursor = 0;

ll expr(node &node) {
	if(nodes.size()==0) return num;
	ll expr_sum = nodes[i].expr();
	for(int i = 0; i < nodes.size(); i++) {
		if(num==-1) expr_sum += nodes[i].expr();
		if(num==-2) expr_sum *= nodes[i].expr();
		expr_sum %= 1000000007;
	}
	return expr_sum;
}

&node parse() {
	node add_node;
	node mul_node;
	node start_node;
	node *now_node = &start_node;
	LOOP: while(true) {
		if(cursor>=str.length()) break;
		switch(str[cursor]) {
			case '+':
				add_node.nodes.push_back(*now_node);
				break;
			case '-':
				add_node.nodes.push_back(*now_node);
				break;
			case '*':
				add_node.nodes.push_back(*now_node);
				break;
			case '(':
				node new_node = parse();
				*now_node.nodes.push_back(new_node);
				break;
			case ')':
				cursor++;
				break LOOP;
		}
		cursor++;
	}
}

int main() {
	cin >> str;
	node first = parse();
}
