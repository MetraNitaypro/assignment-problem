#include"Header.h"
void rad1(int a, int b, int c, int d, int f, int g, int h, int k, int l, int z, int x, int v);
void rad(char a, int b);
int main() {
 	rabota a(7);
	ifstream f;
	ofstream f1("file1.txt");
	ofstream f2("file2.txt");
	f.open("file.txt");
	f >> a;
	a.Serb(); // Венгерский алгоритм
	f1<< a;
	a.foo1(); // Жадный алгоритм
	f1 << a;
	a.foo(); // Полный перебор
	f2 << a;
	clock_t t1 = clock();
	a.foo();
	clock_t t2 = clock();
	cout << t2 - t1 << endl;
	f1 << a;
	t1 = clock();
	a.foo1();
	t2 = clock();
	cout << t2 - t1 << endl;
	f2 << a;
	unsigned size = -1;
	int g = 1;
	char fff = 5;
	rad(fff,g);
	rad1(g,g,g,g,g,g,g,g,g,g,g,g);
	return 0;
}
void rad(char a, int b) {

}
void rad1(int a, int b, int c, int d, int f, int g, int h, int k, int l, int z, int x, int v) {

}