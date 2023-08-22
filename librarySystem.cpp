#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
class Book {
private:
	vector <string> name;
	vector <int> id;
	vector <int> quantity;
	vector <int> borrowed;

public:
	Book(){}

	bool add_book() {
			while (true) {
				cout << "Name[without spaces]: ";
				string _name_; cin >> _name_;
				if (cin.fail()) {
					cin.clear();
					cin.ignore(10000, '\n');
					cout << "please write a string." << endl;
				}
				else if (cin.good()) { 
					name.push_back(_name_);
					break; 
				}
			}
			while (true) {
				cout << "ID: ";
				int _id_; cin >> _id_;
				if (cin.fail()) {
					cin.clear();
					cin.ignore(10000, '\n');
					cout << "please write an Integer number." << endl;
				}
				else if (cin.good()) { 
					id.push_back(_id_);
					break;
				}
			}
			while (true) {
				cout << "Quantity: ";
				int _quantity_; cin >> _quantity_;
				if (cin.fail()) {
					cin.clear();
					cin.ignore(10000, '\n');
					cout << "please write an Integer number." << endl;
				}
				else if (cin.good()) { 
					quantity.push_back(_quantity_);
					break; 
				}
			}
			while (true) {
				cout << "Borrowed: ";
				int _borrowed_; cin >> _borrowed_;
				if (cin.fail()) {
					cin.clear();
					cin.ignore(10000, '\n');
					cout << "please write an Integer number." << endl;
				}
				else if (cin.good()) {
					borrowed.push_back(_borrowed_);
					break;
				}
			}
			return true;
	}

	void print_book_by_prefix() {
		cout << "Enter the prefix: ";
		string prefix; cin >> prefix;
		vector <string> words;
		for (string i : name) {
			bool search = mismatch(prefix.begin() , prefix.end() , i.begin(), i.end()).first == prefix.end();
			if (search) {
				words.push_back(i);
				cout << i << endl;
			}
			else continue;
		}
		if (words.empty()) cout << "No Book With Such Prefix" << endl;
	}

	void sorted_by_id() {
		vector<pair<int, pair<string, pair<int, int>>>> vec;
		for (int i = 0; i < name.size(); i++) {
			int _id_ = id.at(i);
			string _name_ = name.at(i);
			int _quantity_ = quantity.at(i);
			int _borrowed_ = borrowed.at(i);
			pair <int, pair<string, pair<int, int>>> p;
			p.first = _id_; p.second.first = _name_; p.second.second.first = _quantity_;
			p.second.second.second = _borrowed_;
			vec.push_back(p);
		}
		sort(vec.begin(), vec.end());
		for (pair<int, pair<string, pair<int, int>>> p : vec) {
			cout << "id: " << p.first << \
				" , name: " << p.second.first << \
				" , Quantity: " << p.second.second.first << \
				" , Borrowed: " << p.second.second.second << endl;
		}
	}

	void sorted_by_name() {
		vector<pair<string, pair<int, pair<int, int>>>> vec;
		for (int i = 0; i < name.size(); i++) {
			int _id_ = id.at(i);
			string _name_ = name.at(i);
			int _quantity_ = quantity.at(i);
			int _borrowed_ = borrowed.at(i);
			pair <string, pair<int, pair<int, int>>> p;
			p.first = _name_; p.second.first = _id_; p.second.second.first = _quantity_;
			p.second.second.second = _borrowed_;
			vec.push_back(p);
		}
		sort(vec.begin(), vec.end());
		for (pair<string, pair<int, pair<int, int>>> p : vec) {
			cout << "name: " << p.first << \
				" , ID: " << p.second.first << \
				" , Quantity: " << p.second.second.first << \
				" , Borrowed: " << p.second.second.second << endl;
		}
	}

	vector <string> getBooksNames() {
		return this->name;
	}

	vector <int> getBorrowed() {
		return this->borrowed;
	}

	vector <int> getQuantity() {
		return this->quantity;
	}

	int getBookID(int index) {
		return this->id.at(index);
	}

	void increaseBorrowed(int indexBook) {
		this->borrowed.at(indexBook)++;
	}

	void decreaseQuantity(int indexBook) {
		this->quantity.at(indexBook)--;
	}

	void decreaseBorrowed(int indexBook) {
		this->borrowed.at(indexBook)--;
	}

	void increaseQuantity(int indexBook) {
		this->quantity.at(indexBook)++;
	}
};
//===================================================================================================================
class User {
private:
	vector <string> name;
	vector <int> national_id;
	vector <vector <int>> userBooks;
	Book BOOKS;

public:
	void add_user() {
		string __name__;
		while (true) {
			cout << "Name: ";
			cin >> __name__;
			if (cin.fail()) {
				cin.clear();
				cin.ignore(10000, '\n');
				cout << "Invalid Input" << endl;
			}
			else if (cin.good()) {
				name.push_back(__name__);
				break;
			}
		}
		int nationalID;
		while (true) {
			cout << "National ID: ";
			cin >> nationalID;
			if (cin.fail()) {
				cin.clear();
				cin.ignore(10000, '\n');
				cout << "Invalid Input , only integer allowed" << endl;
			}
			else if (cin.good()) {
				national_id.push_back(nationalID);
				break;
			}
		}
		vector <int> Borrows;
		userBooks.push_back(Borrows);
	}

	vector <string> getUsers() {
		return this->name;
	}

	vector <vector<int>> getUserBorrowed() {
		return this->userBooks;
	}

	vector <int> getUserBooks(int index) {
		return userBooks.at(index);
	}

	vector <int> getID() {
		return this->national_id;
	}

	void setBorrowBook(int bookID , int indexUser) {
		this->userBooks.at(indexUser).push_back(bookID);
	}

	void setnewVector(vector<int> x, int userIndex) {
		this->userBooks.at(userIndex) = x;
	}

};
//===================================================================================================================
class Library {
private:
	User _USERS_;
	Book _BOOKS_;
public:
	int menu() {
		int choice = -1;
		while (true) {
			cout << "===============================\n";
			cout << "Library menu:" << endl;
			cout << "1) Add Book" << endl; // true
			cout << "2) Search Book By Prefix" << endl; // true
			cout << "3) Print Who Borrowed Book By Name" << endl;
			cout << "4) Print Library By ID" << endl; // true
			cout << "5) Print Library By Name" << endl; // true
			cout << "6) Add User" << endl; // true
			cout << "7) User Borrow Book" << endl; // true
			cout << "8) User Return Book" << endl; // true
			cout << "9) Print Users" << endl; // true
			cout << "10) Exit" << endl; // true
			cout << "===============================\n";
			cout << "Enter Your Choice in Range [1 - 10]: ";
			while (true) {
				cin >> choice;
				if (cin.fail()) {
					cin.clear();
					cin.ignore(10000, '\n');
					cout << "invalid , you should enter an integer number not string." << endl;
					cout << ": ";
				}
				else if (cin.good()) {
					break;
				}
			}
			if (choice >= 1 && choice <= 10) { return choice;}
			else {
				cout << "Invalid choice , Try again." << endl;
				choice = -1;
			}
		}
	
	}

	void print_who_borrowed_book_by_name() {
		string bookName;
		size_t len = _USERS_.getUsers().size();
		vector <string> vec = _BOOKS_.getBooksNames();
		int bookIndex;
		while (true) {
			cout << "Enter Book Name: "; cin >> bookName;
			if (cin.fail()) {
				cin.clear();
				cin.ignore(10000, '\n');
				cout << "Invalid input." << endl;
			}
			else if (cin.good()) {
				vector <string>::iterator itr2 = find(vec.begin(), vec.end(), bookName);
				if (itr2 != vec.end()) {
					bookIndex = distance(vec.begin(), itr2);
					break;
				}
				else {
					cout << "Book Name Not Found." << endl;
				}
			}
		}
		for (int i = 0; i < len; i++) {
			for (int j = 0; j < _USERS_.getUserBorrowed().at(i).size(); j++) {
				if (_USERS_.getUserBorrowed().at(i).at(j) == _BOOKS_.getBookID(bookIndex)) {
					cout << _USERS_.getUsers().at(i) << endl;
					break;
				}
			}
		}
	}

	void borrow_book() {
		string userName;
		__int64 userIndex;
		string bookName;
		__int64 bookIndex;
		vector <string> vec1 = _USERS_.getUsers();
		vector <string> vec = _BOOKS_.getBooksNames();
		while (true) {
			cout << "User Name: "; cin >> userName;
			if (cin.fail()) {
				cin.clear();
				cin.ignore(10000, '\n');
				cout << "Invalid input." << endl;
			}
			else if (cin.good()) {
				vector <string>::iterator itr1 = find(vec1.begin(), vec1.end(), userName);
				if (itr1 != vec1.end()) {
					userIndex = distance(vec1.begin(), itr1);
					break;
				}
				else {
					cout << "User Name Not Found." << endl;
				}
			}
		}
		if (_USERS_.getUserBorrowed().at(userIndex).size() > 100) {
			cout << "The Max Amount For Borrowing Books Is 100 Books only" << endl;
			return;
		}
		while (true) {
			cout << "Book Name: "; cin >> bookName;
			if (cin.fail()) {
				cin.clear();
				cin.ignore(10000, '\n');
				cout << "Invalid input." << endl;
			}
			else if (cin.good()) {
				vector <string>::iterator itr2 = find(vec.begin(), vec.end(), bookName);
				if (itr2 != vec.end()) {
					bookIndex = distance(vec.begin(), itr2);
					break;
				}
				else {
					cout << "Book Name Not Found." << endl;
				}
			}
		}
		vector <int> q = _BOOKS_.getQuantity();
		if (q.at(bookIndex) == 0) {
			cout << "*********************************" << endl;
			cout << "*this books os not available now*" << endl;
			cout << "*********************************" << endl;
			return;
		}
		else {
			_BOOKS_.decreaseQuantity(bookIndex);
			_BOOKS_.increaseBorrowed(bookIndex);
		}
		_USERS_.setBorrowBook(_BOOKS_.getBookID(bookIndex) , userIndex);
		cout << "**********************" << endl;
		cout << "*Borrowed successfuly*" << endl;
		cout << "**********************" << endl;
	}

	void return_book() {
		string userName;
		__int64 userIndex;
		string bookName;
		int bookIndex;
		vector <string> vec1 = _USERS_.getUsers();
		vector <string> vec = _BOOKS_.getBooksNames();
		while (true) {
			cout << "User Name: "; cin >> userName;
			if (cin.fail()) {
				cin.clear();
				cin.ignore(10000, '\n');
				cout << "Invalid input." << endl;
			}
			else if (cin.good()) {
				vector <string>::iterator itr1 = find(vec1.begin(), vec1.end(), userName);
				if (itr1 != vec1.end()) {
					userIndex = distance(vec1.begin(), itr1);
					break;
				}
				else {
					cout << "User Name Not Found." << endl;
				}
			}
		}
		if (_USERS_.getUserBorrowed().at(userIndex).size() == 0) {
			cout << "******************************************" << endl;
			cout << "*Sorry But You Have Not Any Borrwed Books*" << endl;
			cout << "******************************************" << endl;
			return;
		}
		while (true) {
			cout << "Book Name: "; cin >> bookName;
			if (cin.fail()) {
				cin.clear();
				cin.ignore(10000, '\n');
				cout << "Invalid input." << endl;
			}
			else if (cin.good()) {
				vector <string>::iterator itr2 = find(vec.begin(), vec.end(), bookName);
				if (itr2 != vec.end()) {
					bookIndex = distance(vec.begin(), itr2);
					break;
				}
				else {
					cout << "Book Name Not Found." << endl;
				}
			}
		}
		_BOOKS_.increaseQuantity(bookIndex);
		_BOOKS_.decreaseBorrowed(bookIndex);
		int __ID__ = _BOOKS_.getBookID(bookIndex);
		vector <int> vec4 = _USERS_.getUserBorrowed().at(userIndex);
		vec4.erase(find(vec4.begin() , vec4.end() , __ID__));
		_USERS_.setnewVector(vec4 , userIndex);
		cout << "**********************" << endl;
		cout << "*Returned successfuly*" << endl;
		cout << "**********************" << endl;
	}

	void print_users() {
		size_t len = _USERS_.getUsers().size();
		for (int i = 0; i < len; i++) {
			cout << "User: " << _USERS_.getUsers().at(i) << " , ID: " << _USERS_.getID().at(i) << " , Borrowed Books: ";
			for (int j = 0; j < _USERS_.getUserBorrowed().at(i).size(); j++) {
				if (_USERS_.getUserBorrowed().at(i).at(j) == 0) break;
				cout << _USERS_.getUserBorrowed().at(i).at(j) << " ";
			}
			cout << "\n";
		}
		cout << "\n";
	
	}

	void run() {
		while (true) {
			int choice = menu();

			if (choice == 1) {
				_BOOKS_.add_book();
			}
			else if (choice == 2) {
				_BOOKS_.print_book_by_prefix();
			}

			else if (choice == 3) {
				print_who_borrowed_book_by_name();
			}

			else if (choice == 4) {
				_BOOKS_.sorted_by_id();
			}

			else if (choice == 5) {
				_BOOKS_.sorted_by_name();
			}

			else if (choice == 6) {
				_USERS_.add_user();
			}

			else if (choice == 7) {
				borrow_book();
			}

			else if (choice == 8) {
				return_book();
			}

			else if (choice == 9) {
				print_users();
			}

			else if (choice == 10) {
				break;
			}
		}
	}
};
int main(void){
	Library lp;
	lp.run();
	return 0;
}