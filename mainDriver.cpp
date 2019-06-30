#include <iostream>
#include <algorithm>
#include <string>
#include <cstdlib>
#include "Node.h"
#include "Stack.h"
#include "Queue.h"
#include "Calculator.h"

using namespace std;

// a function to print out the output result
void printResult(string, string, string, int, int);

int main() {
	Calculator *cal = new Calculator();
	string input;
	string inputArg = "";

	cout << "Please input infix with empty space in between" << endl;
	cout << "for example: ( 125 * 10 - 3 % 4 ) + 15 / 28" << endl;
	while (cin >> input) {
		inputArg += input + " ";
		if (cin.get() == '\n') {
			break;
		}
	}
	string postOut = cal->infixToPostfixExpression(inputArg);
	int postNum = cal->postfixEvaluation(postOut);
	string preOut = cal->infixToPrefixExpression(inputArg);
	int preNum = cal->prefixEvaluation(preOut);
	printResult(inputArg, postOut, preOut, postNum, preNum);
	system("pause");
	return 0;
}

void printResult(string inp, string post, string pre, int postNum, int preNum)
{
	cout << "---------- infix   --------------" << endl << "-" << endl;
	cout << "- expr: " << inp << endl << "-" << endl;

	cout << "---------- postfix --------------" << endl << "-" << endl;
	cout << "- expr: " << post << endl << "-" << endl;

	cout << "---------- prefix  --------------" << endl << "-" << endl;
	cout << "- expr: " << pre << endl << "-" << endl;

	cout << "---------- postfix cal  ---------" << endl << "-" << endl;
	cout << "- eval: " << postNum << endl << "-" << endl;

	cout << "---------- prefix cal  ----------" << endl << "-" << endl;
	cout << "- eval: " << preNum << endl << "-" << endl;

	cout << "---------------------------------" << endl << "-" << endl;
}