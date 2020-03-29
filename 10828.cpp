#include<iostream>
using namespace std;
#include<vector>
#include<string>

int main() {
	int N;
	cin >> N;
	vector<int> stack;
	vector<string> order;
	int count = 0;
	for (int i = 0; i < N; i++) {
		string s,s2;
		cin >> s;order.push_back(s);
		if (s == "push") {
			cin >> s2;
			order.push_back(s2);
		}
		
		
	}

	for (int i = 0; i < order.size();i++) {
		if (order[i] == "pop") {
			if (stack.empty()) {
				cout << -1 << endl;
				continue;
			}
			cout << stack[stack.size()-1]<<endl;
			stack.pop_back();
		}
		else if (order[i] == "size") {
			cout << stack.size()<<endl;
		}
		else if (order[i] == "empty") {
			cout << stack.empty()<<endl;
		}
		else if (order[i] == "top") {
			if (stack.empty()) {
				cout << -1<<endl;
				continue;
			}
			cout << stack[stack.size() - 1] <<endl;
		}
		else if(order[i] =="push"){
			stack.push_back(stoi(order[i+1]));
			
		}
		else {
			continue;
		}
	}
}