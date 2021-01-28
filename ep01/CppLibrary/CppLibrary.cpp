#include <iostream>
#include "Library.h"
#include "Console.h" 
#include <boost/algorithm/string.hpp>

int main()
{
	Library lib;
	lib.load();

	while(true)
	{
		Console::printMainMenu();
		string op = Console::readLine("请输入操作：");
		boost::to_lower(op);

		if(op == "s") 
			lib.searchBook();
		else if(op == "b")
			lib.borrowBook();
		else if(op == "r")
			lib.returnBook();
		else if(op == "l")
			lib.listBook();
		else if(op == "m")
			lib.addBook();
		else if(op == "q")
			break;
	}
}
 