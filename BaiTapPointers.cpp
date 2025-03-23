#include <iostream>

using namespace std;

int length(char str[]) {
	int count = 0;
	for (int i = 0; str[i] != '\0'; ++i) {
		++count;
	}
	return count;
}

char* reverse(char a[]) {
	int len = length(a);
	char* rev = new char[len + 1];

	for (int i = 0; i < len; ++i) {
		rev[i] = a[len - i - 1];
	}
	rev[len] = '\0';
	return rev;
}

char* delete_char(char a[], char c) {
	int len = length(a);
	int j = 0;
	char* del = new char[len + 1];

	for (int i = 0; i < len; ++i) {
		if (a[i] != c) {
			del[j] = a[i];
			++j;
		}
	}

	del[j] = '\0';
	return del;
}

char* pad_left(char a[], int n) {
	int len = length(a);
	if (n <= len) return a;
	char* lf = new char[n + 1];

	for (int i = 0; i < n - len; ++i) {
		lf[i] = ' ';
	}
	int j = 0;
	for (int i = n - len; i < n; ++i) {
		lf[i] = a[j];
		j++;
	}

	lf[n] = '\0';
	return lf;
}

char* pad_right(char a[], int n) {
	int len = length(a);
	if (n <= len) return a;
	char* rg = new char[n + 1];

	for (int i = 0; i < n; ++i) {
		if(i < len){
			rg[i] = a[i];
		}
		else {
			rg[i] = ' ';
		}
	}
	rg[n] = '\0';
	return rg;
}

char* truncate(char a[], int n) {
	int len = length(a);
	if (len <= n) return a;
	char* trun = new char[n + 1];

	for (int i = 0; i < n; ++i) {
		trun[i] = a[i];
	}
	trun[n] = '\0';
	return trun;
}

bool is_palindrome(char a[]) {
	int len = length(a);
	char* pali = reverse(a);

	for (int i = 0; i < len; ++i) {
		if (a[i] != pali[i]) {
			delete[] pali;
			return false;
		}
	}
	delete[] pali;
	return true;
}

char* trim_left(char a[]) {
	int len = length(a);
	if (a[0] != ' ') return a;
	int p1 = 0;
	int p2 = 1;
	int cut = 1;

	while (a[p1] == ' ' && a[p2] == ' ') {
		++cut;
		++p1;
		++p2;
	}
	char* trim = new char[len - cut + 1];
	for (int i = 0; i < (len - cut); ++i) {
		trim[i] = a[i + cut];
	}
	trim[len - cut] = '\0';
	return trim;
}

char* trim_right(char a[]) {
	int len = length(a);
	if (a[len - 1] != ' ') return a;
	int p1 = len - 1;
	int p2 = len - 2;
	int cut = 1;
	while (a[p1] == ' ' && a[p2] == ' ') {
		++cut;
		--p1;
		--p2;
	}
	char* trim = new char[len - cut + 1];
	for (int i = 0; i < len - cut; ++i) {
		trim[i] = a[i];
	}
	trim[len - cut] = '\0';
	return trim;
}


int main() {
	char c[1000];
	char del_char;
	int right_walk, left_walk;
	char palindrome[] = "racecar";

	cin.get(c, 100);
	length(c);
	cin >> del_char;
	cin >> right_walk >> left_walk;


	cout << reverse(c) << endl;
	cout << delete_char(c, del_char) << endl;
	cout << pad_left(c, left_walk) << endl;
	cout << pad_right(c, right_walk) << "ending" << endl;
	cout << truncate(c, 9) << endl;
	cout << is_palindrome(c) << endl;
	cout << trim_left(pad_left(c, left_walk)) << endl;
	cout << trim_right(pad_right(c, right_walk)) << "ending" << endl;
	
	return 0;

}