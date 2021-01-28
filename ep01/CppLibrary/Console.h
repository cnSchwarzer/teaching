#pragma once
#include <iostream>
#include <string> 

class Console
{
public:
	static void write(const std::string& str)
	{
		std::cout << str;
	}
	
	static void writeLine(const std::string& str)
	{
		write(str);
		write("\r\n");
	}

	static std::string readLine()
	{
		std::string str;
		(std::cin >> str).get();
		return str;
	}

	static std::string readLine(const std::string& hint)
	{
		write(hint);
		return readLine();
	}

	static void printMainMenu()
	{
		writeLine("欢迎进入图书管理系统");
		writeLine("s  查阅");
		writeLine("b  借书");
		writeLine("r  还书");
		writeLine("l  浏览");
		writeLine("m  管理");
		writeLine("q  退出"); 
	}

	static void printBook(const Book& book)
	{
		writeLine("书名：" + book.name);
		writeLine("作者：" + book.author);
		writeLine("剩余数量：" + std::to_string(book.remain));
	}
};