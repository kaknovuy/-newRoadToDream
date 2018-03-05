#include"MyClass.h"
#include <iostream>
#include <conio.h>


my_class::my_class()
{
}

my_class::my_class(int num)
{
	wcout << L"\nTo enter is allowed from 2 to 50 words, in each of them from 2 to 8 capital (large) Latin letters; \nbetween adjacent words - a space, after the last word - a period.\n\n\n";
	if (num == 1) {
		stringPointer_ = new wstring(dynamic_input());
	}
	else {
		stringPointer_ = new wstring(normal_input());
	}
}

my_class::~my_class()
{
	delete stringPointer_;
}

wstring my_class::dynamic_input()
{
	wstring text;
	wchar_t el;
	int i = 0, j = 0;
	while (true)
	{
		el = _getch();

		if (el >= L'a'&&el <= L'z'&& j < 8) {
			wcout << el;
			text += el;
			j++;
		}

		else if (el == L' '&& j > 0 && i < 49) {
			wcout << el;
			text += el;
			j = 0;
			i++;
		}

		else if (el == L'.'&& j > 0 && i >= 1 && text.back() != L' ') {
			wcout << el;
			text += el;
			return text;
		}

		else if (el == 8 && (!(text.empty()))) {
			if (j > 0) {
				j--;
				text.resize(text.size() - 1);
				wcout << L"\b \b";
			}
		}
	}
}

wstring my_class::normal_input()
{
	wcout << L"\nThe data after the point will be deleted!\n";
	wstring text, text2;

	int count = 0;

	do
	{
		wcin >> text2;
		text += text2 + L' ';
		if (count++ > 0)wcout << L"Input Error! Try again...\n";

		if (text.find_first_of(L'.') != -1)
			text.resize(text.find_first_of(L'.') + 1);

		int i = 0, j = 0;

		for each (wchar_t el in text)
		{
			if (el >= L'a'&&el <= L'z') {
				j++;

				if (j > 8)
					break;
			}
			else if (el == L' ') {
				j = 0;

				i++;
				if (i > 50)
					break;

			}
			else if (el == L'.') {
				if (j < 1 || text.back() == L' ')
					break;

				else
				{
					return text;
				}
			}
			else break;
		}
	} while (true);
}



wstring my_class::check_v()
{
	wstring resultString_;

	for (int i = 0; i < arrayOfWords_.size(); i++)
	{
		bool flag = true;
		for (int j = 0; j < arrayOfWords_[i].size() ; j++)
		{
			if (flag == false  && j== arrayOfWords_[i].size()-1)
				break;
			for (int k = 0; k < arrayOfWords_[i].size() ; k++)
			{
				if (arrayOfWords_[i][j] == arrayOfWords_[i][k] && j != k)
				{
					flag = true;
					break;
				}
				if((arrayOfWords_[i][j] != arrayOfWords_[i][k] && j != k))
					flag = false;
			}

		}
		if (arrayOfWords_[i] == arrayOfWords_[0] && i>0)continue;
			if (flag == true)
				resultString_ += arrayOfWords_[i] + L' ';		
	}
	resultString_.resize(resultString_.size() - 1);
	resultString_ += L'.';
	return	resultString_;
}


wstring my_class::conversion()
{
	wcout << L"\nInput string: " << *stringPointer_ << endl;	
	split(L' ');
	stringPointer_ = new wstring(check_v());

	return *stringPointer_;
}


void my_class::split(const wchar_t separator1)
{
	wstring word;
	for (wchar_t element : *stringPointer_)
	{
		if (element == separator1 || element == L'.')
		{
			arrayOfWords_.push_back(word);
			word.clear();
		}
		else word += element;

	}
}
