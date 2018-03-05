#include <iostream>
#include<conio.h>
#include<string>
#include<fstream>
#include<iostream>
#include <fcntl.h>
#include <io.h>
#include"MyClass.h"



using namespace std;

inline void input_num(int &num) {

	ifstream my_cin("CON");

	do {

		while (!(my_cin >> num))
		{
			wcout << L"\nInput Error! Repeat one more time...";
			my_cin.clear();

			while (my_cin.get() != '\n')
				continue;
		}

		if (num > 2 || num<1) {
			wcout << L"Invalid value, please try again ...";
			continue;
		}
		else break;

	} while (true);
}

int main() {
	_setmode(_fileno(stdout), _O_U16TEXT);
	_setmode(_fileno(stdin), _O_U16TEXT);
	const int Esc = 27;
	unsigned int CountTest = 0;	

	do
	{int s;
		wcout << L"Test #" << ++CountTest << endl;
		
		wcout << L"\nPress the key to select the type of input: \n \t 1 - Check in the input process \n \t 2 - Check during the calculation \n\n";
		
		input_num(s);
		my_class a(s);

		const wstring result = a.conversion();
		wcout << L"\nThe resulting string: \n" << result;
		wcout << L"\nPress any key to continue, or ESC to exit\n";
	} while (_getch() != Esc);

	return 0;
}