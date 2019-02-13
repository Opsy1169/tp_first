#include "pch.h"
#include <iostream>
#include <vector>
#include <string>
#include "Dll1.h"



const char EOLN = '\n';
const char YES_CHAR = 'Y';
const char NO_CHAR = 'N';
const int LEFT_BOUND = -1000000000;
const int RIGHT_BOUND = +1000000000;
const int LEFT_BOUND_SIZE = 1;
const int RIGHT_BOUND_SIZE = 1000;
const std::string ABOUT_MESSAGE = "A+B";
const std::string CONTINUE_MESSAGE =
"Continue? (Y/N)>";
const std::string INCORRECT_MESSAGE =
"Input is incorrect. Try again>";
const std::string INPUT_MESSAGE = "Input an integer>";
const std::string OUT_OF_BOUNDS_MESSAGE =
"This number is out of bounds";
const std::string OUTPUT_MESSAGE = "Result: ";
const std::string SKIP_CHARACTERS = " ";


void ClearInputStream(std::istream &in)
{
	std::cout << "clear" << std::endl;
	in.clear();
	while (in.peek() != EOLN && in.peek() != EOF)
	{
		in.get();
	}
}


int Seek(std::istream &in)
{
	std::cout << "skip" << std::endl;
	while (in.peek() != EOLN &&
		SKIP_CHARACTERS.find((char)in.peek()) !=
		std::string::npos)
	{
		in.get();
	}
	return in.peek();
}


bool CheckBounds(int n)
{
	bool ok = (LEFT_BOUND <= n && n <= RIGHT_BOUND);
	if (!ok)
	{
		std::cout << OUT_OF_BOUNDS_MESSAGE << " ["
			<< LEFT_BOUND << ", " << RIGHT_BOUND << "]" <<
			std::endl;
	}
	return ok;
}

bool CheckSizeBounds(int n)
{
	bool ok = (1 <= n && n <= 1000);
	if (!ok)
	{
		std::cout << OUT_OF_BOUNDS_MESSAGE << " ["
			<< LEFT_BOUND_SIZE << ", " << RIGHT_BOUND_SIZE << "]" <<
			std::endl;
	}
	return ok;
}


int ReadInt(std::istream &in, bool isLength)
{
	std::cout << INPUT_MESSAGE;
	int ans;
	in >> ans;
	if (!isLength) {
		while (!in || Seek(in) != EOLN || !CheckBounds(ans))
		{
			ClearInputStream(in);
			std::cout << INCORRECT_MESSAGE;
			in >> ans;
		}
	}
	else {
		while (!in || Seek(in) != EOLN || !CheckSizeBounds(ans))
		{
			ClearInputStream(in);
			std::cout << INCORRECT_MESSAGE;
			in >> ans;
		}
	}
	return ans;
}

bool NeedContinue(std::istream &in)
{
	std::cout << CONTINUE_MESSAGE;
	char ans;
	in >> ans;
	while (!in || Seek(in) != EOLN || ans != YES_CHAR
		&& ans != NO_CHAR)
	{
		ClearInputStream(in);
		std::cout << INCORRECT_MESSAGE;
		in >> ans;
	}
	return ans == YES_CHAR;
}

int main() {
	int a;
	std::cout<< "Hello, World!" << std::endl;
	std::vector<int> mass;
	int ss;
	std::cout << "Enter sequence size" << std::endl;
	ss = ReadInt(std::cin, true);
	//std::cin >> ss;
	std::cout << "enter " << ss << "integers" << std::endl;
	for (int i = 0; i < ss; ++i) {
		int tmp;
		tmp = ReadInt(std::cin, false);
		mass.push_back(tmp);
	}
	int result = moreNumber(mass);
	std::cout<< result << std::endl;
	return 0;
}

/*int main()
{
	std::cout << ABOUT_MESSAGE << std::endl;
	bool cont = true;
	while (cont)
	{
		int a = ReadInt(std::cin);
		int b = ReadInt(std::cin);
		std::cout << OUTPUT_MESSAGE << (a, b)
			<< std::endl;
		cont = NeedContinue(std::cin);
	}
	return 0;
	*/