#include <iostream>
#include <string>

using namespace std;

int main()
{
	setlocale(LC_ALL, "rus");
	int a, b, c, d, m, n, s, i, j, count, res;


	cout << "\n\tПечатаем фамилию в цикле\n";
	string fam, name;
	fam = name = "";
	cout << "Введите вашу фамилию: ";
	cin >> fam;
	cout << "\nВведите ваше имя: ";
	cin >> name;

	for (i = 0; i <10; i++) {
		cout << "\t" << (i + 1) << ") " << fam << " " << name;
	}

	cout << endl << endl << "\t";
	system("pause");
	return 0;
}
