
#include <cstdint>
#include <iostream>
#include <cstdio>
#include <map>
#include <vector>
#include <string>
#include <list>
#include <cmath>
#include <cstdlib>
#include <algorithm>
#include <vector>

using namespace std;

struct char_input {
	char character = '\0';
	int index = 0;
	char_input(char _character, int _index) :
		character(_character), index(_index) {}
};

string string_manipulation(const string& input) {

	if (input.empty()) return "";

	string ret = "";

	list<char_input> stack;

	int index = 0;
	for (const auto& character : input) {
		if (!(character == '(' || character == ')')) {
			index++;
			continue;
		}
		
		if (character == '(') {
			stack.push_back(char_input(character, index));
		}
		else {
			stack.push_back(char_input(character, index));
		}
		index++;
		
	}

	/* stack is like ()(())
	*  ) - 4 - count closing
	*  ) - 3
	*  ( - 2
	*  ( - 1
	*  ) - 4
	*  (  */

	list<char_input> temp_stack;

	while (!(stack.empty())) {
		char_input top = stack.back();
		stack.pop_back();

		if (temp_stack.empty()) {
			temp_stack.push_back(top);
			continue;
		}

		char_input temp_top = temp_stack.back();

		if (temp_top.character == ')' && top.character == '(') {
			temp_stack.pop_back();
		}
		else {
			temp_stack.push_back(top);
		}
	}

	if (temp_stack.empty()) return input;

	// the contents of temp stack are to be removed 
	// from original string. Its index are in 
	// increasing order now. 

	index = 0;
	for (const auto& character : input) {
		char_input top = temp_stack.back();
		if (index == top.index) {
			temp_stack.pop_back();
			index++;
			continue;
		}
		ret.push_back(input[index]);
		index++;
	}

	return ret;
}

int main() {
	const string input = "))a((";
	string ret = string_manipulation(input);

	cout << ret;

	cin.get();
}