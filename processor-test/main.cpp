#include <iostream>
#include <string>
#include "Request.h"

int main()
{
	using namespace std;

	Request::Request();
	cout << "Waiting enter key press to close window" << endl;
	cin.get();

	return 0;
}