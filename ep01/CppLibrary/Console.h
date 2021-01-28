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
		writeLine("��ӭ����ͼ�����ϵͳ");
		writeLine("s  ����");
		writeLine("b  ����");
		writeLine("r  ����");
		writeLine("l  ���");
		writeLine("m  ����");
		writeLine("q  �˳�"); 
	}

	static void printBook(const Book& book)
	{
		writeLine("������" + book.name);
		writeLine("���ߣ�" + book.author);
		writeLine("ʣ��������" + std::to_string(book.remain));
	}
};