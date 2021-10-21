// ConsoleApplication2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>

using namespace std;


int main()
{
	string line;

	vector<string> words;
	words.push_back("xxxx123");
	words.push_back("Abracadabra");
	words.push_back("recede");
	words.push_back("din");
	words.push_back("Success");
	words.push_back("(( @");

	unsigned int vector_size = words.size();

	for (int i = 0; i < vector_size; i++) {
		string s = words[i];
		int n = s.length();

		struct ci_less //честно стыренный код для case-insensitivity в словаре
		{
			// case-independent (ci) compare_less binary function
			struct nocase_compare
			{
				bool operator() (const unsigned char& c1, const unsigned char& c2) const {
					return tolower(c1) < tolower(c2);
				}
			};
			bool operator() (const std::string& s1, const std::string& s2) const {
				return std::lexicographical_compare
				(s1.begin(), s1.end(),   // source range
					s2.begin(), s2.end(),   // dest range
					nocase_compare());  // comparison
			}
		};

		//Словарь для запоминания кол-ва букв (избегания повторений)
		map<string, int, ci_less> xxx;
		
		for (int i = 0; i < n; i++) {
			string temp(1, s[i]);
			if (xxx.find(temp) == xxx.end()) {
				xxx[temp] = 1;
			}
			else {
				xxx[temp] = 2;
			}
		}

		for (int i = 0; i < n; i++) {
			string temp(1, s[i]);
			if (xxx[temp] > 1) {
				s.replace(i, 1, ")");
			}
			else {
				s.replace(i, 1, "(");
			}
		}

		cout << words[i] << " => " << s << endl;
	}

	return 0;
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
