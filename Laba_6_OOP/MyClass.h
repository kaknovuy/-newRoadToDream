#pragma once

#include<string>
#include<vector>

using namespace std;


class my_class
{
public:
	my_class();
	my_class(int);
	wstring conversion();
	~my_class();
	
private:
	wstring* stringPointer_;
	vector<wstring> arrayOfWords_;
	wstring dynamic_input();	
	wstring normal_input();	
	wstring check_v();
		
	void split(wchar_t );
};

