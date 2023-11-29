#include<iostream>
#include<conio.h>
#include <stack>
#include<string.h>
#include <stdlib.h>

using namespace std;

class StringBalance {
private:
	char openCharacter[4] = { '(','[','<','{' };
	char closeCharacter[4] = { ')',']','>','}' };
public:
	//Checking the correctness of the expression
	bool isBalance(string inputStr) {
		bool flag = true;

		stack<char> stack;
		for (int i = 0; i < inputStr.length(); i++) {
			if (Contains(inputStr[i], openCharacter)) {
				stack.push(inputStr[i]);h
			}
			if (Contains(inputStr[i], closeCharacter)) {
				if (stack.empty()) {
					int closeIndex = indexOf(inputStr[i], closeCharacter);
					inputStr[i] = openCharacter[closeIndex];
					stack.push(inputStr[i]);
					flag = false;
					continue;
				}
				char top = stack.top();

				int openIndex = indexOf(top, openCharacter);
				int closeIndex = indexOf(inputStr[i], closeCharacter);

				if (openIndex != closeIndex) {
					flag = false;
					inputStr[i] = closeCharacter[openIndex];
				}
				stack.pop();
			}
		}
		if (stack.empty() && flag)
			return true;
		else {
			cout << endl << "Did you mean this?  " << inputStr << "\n";
			return false;
		}

	}

private:
	//Has character in array
	bool Contains(char ch, char arr[]) {
		for (int i = 0; i < 4; i++)
			if (ch == *(arr + i))return true;
		return false;
	}

	//Index character in array
	int indexOf(char ch, char arr[]) {
		for (int i = 0; i < 4; i++) {
			if (arr[i] == ch)
				return i;
		}
		return -1;
	}
};
int main() {
	cout << "enter str: ";
	string strInput;
	cin >> strInput;

	StringBalance stringBalance;
	bool res = stringBalance.isBalance(strInput);
	if (res)
	{
		system("Color 2");
		cout << endl << "result: it is true" << endl;
	}
	else
	{
		system("Color 4");
		cout << "result: it is flase" << endl;
	}
	return 0;
}

