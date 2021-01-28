#include "Library.h" 
#include "Console.h"
#include <nlohmann/json.hpp>
#include <fstream>
#include <filesystem>

optional<Book> Library::query(const string& name)
{
	for(auto& book : books)
	{
		if(book.name == name)
		{
			return book;
		}
	}
	return optional<Book>();
}

void Library::save()
{
	nlohmann::json root;
	for(auto& book : books)
	{
		nlohmann::json b;
		b["name"] = book.name;
		b["author"] = book.author;
		b["remain"] = book.remain;
		root.push_back(b);
	}

	ofstream fout("./books.txt");
	fout << root;
	fout.close();
}

void Library::load()
{
	if(!std::filesystem::exists("./books.txt"))
		return;
	
	ifstream fin("./books.txt");
	nlohmann::json root;
	fin >> root;
	fin.close();

	books.clear();
	for(auto& b : root)
	{
		Book book;
		book.name = b["name"];
		book.author = b["author"];
		book.remain = b["remain"];
		books.push_back(book);
	}
}

void Library::searchBook()
{
	string name = Console::readLine("����������");
	auto optBook = query(name);
	if(optBook.has_value())
	{
		auto book = optBook.value();
		Console::printBook(book);
	}
	else
	{
		Console::writeLine("���޴���");
	}
}

void Library::borrowBook()
{
	string name = Console::readLine("����������");
	auto book = query(name);
	if (book.has_value())
	{
		auto b = book.value();
		if (b.remain > 0)
		{
			b.remain--;
			Console::writeLine("���ĳɹ�");
			save();
		}
		else
		{
			Console::writeLine("��ȫ�����");
		}
	}
	else
	{
		Console::writeLine("���޴���");
	}
}

void Library::returnBook()
{
	string name = Console::readLine("����������");
	auto book = query(name);
	if (book.has_value())
	{
		auto b = book.value();
		b.remain++;
		Console::writeLine("�黹�ɹ�");
		save();
	}
	else
	{
		Console::writeLine("���޴���");
	}
}

void Library::listBook()
{
	//foreach
	for (auto book : books)
	{
		Console::printBook(book);
	} 
}

void Library::addBook()
{
	string password = Console::readLine("���������룺");
	if(password != "abcdef")
		return;

	Book newBook;
	newBook.name = Console::readLine("����������");
	newBook.author = Console::readLine("�������ߣ�");
	newBook.remain = std::stoi(Console::readLine("����������"));
	books.push_back(newBook);
	save(); 
	
	Console::writeLine("��ӳɹ�");
}
