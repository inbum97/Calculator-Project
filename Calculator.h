#ifndef CALCULATOR_
#define CALCULATOR_
using namespace std;

class Calculator
{
private:
	LinkedStack<char> *stack;
	LinkedStack<int> *evalStack;

	string expressionOutput;

public:
	Calculator();

	string infixToPrefixExpression(string);
	string infixToPostfixExpression(string);
	bool ifTopStackHasGreaterOrEqualExp(char);
	string reverseString(string);
	int postfixEvaluation(string);
	int prefixEvaluation(string);
	int calculation(char, int, int);

	bool isSymbol(char);
	bool isNumber(char);
};

Calculator::Calculator()
{
	stack = new LinkedStack<char>();

	expressionOutput = "";
	evalStack = new LinkedStack<int>();
}

//****************************************************
//					postfixEvaluation 
//	The function retuns postfix calculation result
//****************************************************
int Calculator::postfixEvaluation(string postStr) {
	string tempNum = "";
	for (int i = 0; i < postStr.size(); i++) {
		char a = postStr[i];

		//if char = number
		if (isNumber(a))
		{
			tempNum += a;
			//if at end of deck or next not equal to number
			if (i == postStr.size() - 1 || !isNumber(postStr[i + 1]))
			{
				//push full number(int) to stack
				evalStack->push(stoi(tempNum));
				tempNum = "";
			}
		}

		//else if char = symbol
		else if (isSymbol(a))
		{

			tempNum = "";

			//push the top two items in evalStack, first to B, secodn to A
			int numB = evalStack->pop()->getItem();
			int numA = evalStack->pop()->getItem();
			//call calculation and pass two items in order
			int tempResult = calculation(a, numA, numB);

			//push result back into evalStack
			evalStack->push(tempResult);
		}

		//else blank or other char
		else
		{
			tempNum = "";
			continue;
		}
	}
	return evalStack->pop()->getItem();
}

//****************************************************
//					prefixEvaluation 
//	The function retuns prefix calculation result
//****************************************************
int Calculator::prefixEvaluation(string preStr)
{
	string tempNum = "";
	// looping from backward
	for (int i = preStr.size() - 1; i >= 0; i--)
	{
		char a = preStr[i];

		//if char = number
		if (isNumber(a))
		{
			tempNum += a;
			//if at start of deck or next not equal to number
			if (i == 0 || !isNumber(preStr[i - 1]))
			{
				//push full number(int) to stack
				tempNum = reverseString(tempNum);
				evalStack->push(stoi(tempNum));
				tempNum = "";
			}
		}

		//else if char = symbol
		else if (isSymbol(a))
		{
			tempNum = "";

			// push the top two items in evalStack, 
			// first to B, secodn to A
			int numA = evalStack->pop()->getItem();
			int numB = evalStack->pop()->getItem();
			// call calculation and pass two items in order
			int tempResult = calculation(a, numA, numB);
			//push result back into evalStack
			evalStack->push(tempResult);
		}

		//else blank or other char
		else
		{
			tempNum = "";
			continue;
		}
	}
	return evalStack->pop()->getItem();
}

//****************************************************
//					reverseString 
//	The function takes string as args and returns
//  reversed strings
//****************************************************
string Calculator::reverseString(string input)
{
	string result = "";
	char a;
	// Swap character starting from two corners 
	for (int i = input.length() - 1; i >= 0; i--)
	{
		if (input[i] == ')')
			a = '(';
		else if (input[i] == '(')
			a = ')';
		else
			a = input[i];
		result += a;
	}
	return result;
}

//****************************************************
//					infixToPrefixExpression 
//	The function retuns prefix expression in string
//****************************************************
string Calculator::infixToPrefixExpression(string input)
{
	input = reverseString(input);
	string output = infixToPostfixExpression(input);
	return reverseString(output);
}

//****************************************************
//					infixToPostfixExpression 
//	The function retuns postfix expression in string
//****************************************************
string Calculator::infixToPostfixExpression(string input)
{
	expressionOutput = "";
	string tempNum = "";

	for (int i = 0; i < input.size(); i++)
	{
		char a = input[i];

		//if char = number
		if (isNumber(a))
		{
			tempNum += a;
			//if at end of deck or next not equal to number
			if (i == input.size() - 1 || !isNumber(input[i + 1]))
			{
				//push to queue
				expressionOutput += " ";
				expressionOutput += tempNum;

				tempNum = "";
			}
		}

		//else if char = symbol
		else if (isSymbol(a))
		{
			tempNum = "";
			if (a == ')')
			{
				//pop stack until ')'
				while (stack->peek()->getItem() != '(')
				{
					char c = stack->pop()->getItem();
					expressionOutput += " ";
					expressionOutput += c;
				}
				char c = stack->pop()->getItem();

			}
			else if (a == '(')
			{
				//push to stack
				stack->push(a);
			}
			else
			{
				//check top stack see if pop or not
				while (ifTopStackHasGreaterOrEqualExp(a)) {
					char c = stack->pop()->getItem();
					expressionOutput += " ";
					expressionOutput += c;
				}
				stack->push(a);
			}
		}

		//else blank or other char
		else
		{
			tempNum = "";
		}
	}

	//pop eveything in stack till it's empty
	while (!stack->isEmpty())
	{
		char c = stack->pop()->getItem();
		expressionOutput += " ";
		expressionOutput += c;
	}
	return expressionOutput;
}

//****************************************************
//					ifTopStackHasGreaterOrEqualExp 
//	The function checks the operands level
//****************************************************
bool Calculator::ifTopStackHasGreaterOrEqualExp(char a)
{
	if (stack->getStackSize() == 0)
	{
		return false;
	}
	char peek = stack->peek()->getItem();
	if (peek == '(' || peek == ')')
	{
		return false;
	}
	else if ((peek == '+' || peek == '-') && (a == '/' || a == '*' || a == '%'))
	{
		return false;
	}
	return true;
}

//****************************************************
//					  isSymbol 
//	The function check if input is arithmetic expressions 
//****************************************************
bool Calculator::isSymbol(char mathStr) {
	bool isSym;
	switch (mathStr) {
	case '+':
		isSym = true;
		break;
	case '-':
		isSym = true;
		break;
	case '*':
		isSym = true;
		break;
	case '/':
		isSym = true;
		break;
	case '(':
		isSym = true;
		break;
	case ')':
		isSym = true;
		break;
	case '%':
		isSym = true;
		break;
	default:
		isSym = false;
	}
	return isSym;
}

//****************************************************
//					calculation 
//	The function does the calculation and returns result
//****************************************************
int Calculator::calculation(char symbol, int num1, int num2)
{
	int result = 0;
	switch (symbol)
	{
	case '+':
		result = num1 + num2;
		break;
	case '-':
		result = num1 - num2;
		break;
	case '*':
		result = num1 * num2;
		break;
	case '/':
		result = num1 / num2;
		break;
	case '%':
		result = num1 % num2;
		break;
	default:
		result = 0;
	}
	return result;
}

//****************************************************
//					isNumber 
//	The function check if input is number
//****************************************************
bool Calculator::isNumber(char mathStr) {
	if (mathStr >= 48 && mathStr <= 57)
	{
		return true;
	}
	else
		return false;
}

#endif
