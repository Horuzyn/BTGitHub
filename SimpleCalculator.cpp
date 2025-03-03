#include <iostream>
#include <math.h>

using namespace std;

void arithmetic(int num1, char op, int num2) {
	switch (op)
	{
	case '+':
		cout << num1 + num2 << endl;
		break;
	case '-':
		cout << num1 - num2 << endl;
		break;
	case 'x':
		cout << num1 * num2 << endl;
		break;
	case '/':
		if (num2 == 0) {
			cout << "Invalid" << endl;
			exit(1);
		}
		else {
			cout << num1 / num2 << endl;
		}
		break;
	case '%':
		if (num2 == 0) {
			cout << "Invalid" << endl;
			exit(1);
		}
		else {
			cout << num1 % num2 << endl;
		}
		break;
	default:
		cout << "Invalid Operator!" << endl;
	}
}

int main() {
	int num1, num2;
	char op;

	cout << "Nhap bieu thuc de tinh toan : ";
	cin >> num1 >> op >> num2;

	arithmetic(num1, op, num2);

	return 0;
}