#include <bits/stdc++.h>

using namespace std;

double solve_rpn(string& token) {
	stack<double> operands;
	set<string> operators{"+", "-", "*", "/", "sqrt", "avg"};

	for (int i = 0; i < token.size(); ++i) {
		string tmp{""};
		while (token[i] != ' ' && i < token.size()) {
			tmp += token[i++];
		}
		if (!operators.count(tmp)) {
			operands.push(stod(tmp));
		} else if (tmp == "avg") {
			double arg_number = operands.top();
			double tmp = arg_number;
			double sum{0};

			operands.pop();
			while (tmp--) {
				sum += operands.top();
				operands.pop();
			}
			operands.push(sum / arg_number);
		} else {
			double rhs = operands.top();
			operands.pop();
			if (tmp == "sqrt") {
				operands.push(sqrt(rhs));
				continue;
			}
			double lhs = operands.top();
			operands.pop();

			if (tmp == "+") operands.push(lhs + rhs);
			else if (tmp == "-") operands.push(lhs - rhs);
			else if (tmp == "*") operands.push(lhs * rhs);
			else operands.push(lhs / rhs);
		}
	}
	return operands.top();
}

int main(void) {
	string token{"1 1 + 2 3 4 3 avg + 2 2 + 5 6 7 8 5 avg +"};

	cout << solve_rpn(token) << endl;
	return 0;
}