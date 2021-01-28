#pragma once

#include <string>
#include <vector>
#include <optional>

using namespace std;

class Book
{
public:
	string name;
	string author;
	int remain = 0;
};

class Library
{
	vector<Book> books;
	 
	optional<Book> query(const string& name);

public:

	void save();
	void load();
	
	void searchBook();
	void borrowBook();
	void returnBook();
	void listBook();
	void addBook();
};

