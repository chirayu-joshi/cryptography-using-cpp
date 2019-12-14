#include "pch.h"
#include "login_signup.h"
#include "caesar.h"
#include <iostream>
#include <string>
#include <conio.h>
#include <fstream>

using namespace std;

int user_position = 0, password_position = 0;

bool check_space(string str) {
	for (int i = 0; str[i] != '\0'; i++) {
		if (str[i] == ' ')
			return true;
	}
	return false;
}

bool user_exist(string user_name) {
	string str;

	fstream in;
	in.open("user_name.txt");
	while (!in.eof()) {
		in >> str;
		if (str == user_name)
			return true;
	}
	in.close();
	return false;
}

void login_page() {
	short int choice;

	print_horizontal_row('=');
	cout << "1. Login" << endl
		<< "2. Sign up" << endl
		<< "0. Exit" << endl;
	print_horizontal_row('=');
	cout << "Enter your choice: ";
	cin >> choice;
	while (choice < 0 || choice > 2) {
		cout << endl << "Wrong input. Please try again..!!" << endl
			<< "Enter your choice: ";
		cin >> choice;
	}
	getchar();
	if (choice == 1)
		login();
	else if (choice == 2)
		sign_up();
	else
		exit(0);
}

void login() {
	string user_name, str;
	bool user_name_condition = false, password_condition = false;
	char ch;

	system("cls");
	cout << "Enter user name: ";
	getline(cin, user_name);
	fstream in;
	in.open("user_name.txt");
	while (!in.eof()) {
		in >> str;
		if (user_name == str) {
			string password = "\0";

			user_name_condition = true;

		try_password_again:
			system("cls");
			password = "\0";
			cout << "Enter password: ";
			while ((ch = _getch()) != 13) {
				password += ch;
				cout << "*";
			}
			in.close();
			in.open("password.txt");
			while (!in.eof()) {
				in >> str;
				if (password == str) {
					password_condition = true;
					system("cls");
					cout << endl << endl << endl << endl << endl
						<< endl << endl << endl << endl << endl;
					print_horizontal_row('=');
					cout << "\t\t\t\t\t\tLogin successful" << endl;
					print_horizontal_row('=');
				}
			}
			if (!password_condition) {
				char input;

				cout << endl << endl << "Incorrect password." << endl;
				print_horizontal_row('=');
				cout << "1. Back" << endl
					<< "0. Exit" << endl
					<< "Press any key except 0 to try again..." << endl;
				print_horizontal_row('=');
				input = _getch();
				if (input == '1')
					login();
				else if (input == '0')
					exit(0);
				else
					goto try_password_again;
			}
		}
	}
	if (!user_name_condition) {
		char input;

		in.close();
		cout << "User name is incorrect." << endl;
		print_horizontal_row('*');
		cout << "0. Exit" << endl
			<< "Press any key except 0 to try again..." << endl;
		print_horizontal_row('*');
		input = _getch();
		if (input == '0')
			exit(0);
		else
			login();
	}
	in.close();
	_getch();
}

void sign_up() {
	string user_name, password;
	char choice;

sign_up_user_name:
	system("cls");
	print_horizontal_row('=');
	cout << "Username and password must fulfill following conditions: " << endl
		<< "==> No space is allowed." << endl
		<< "Symbols like ( _ , - , @ , & , ...) are allowed." << endl;
	print_horizontal_row('=');
	cout << "Enter username: ";
	getline(cin, user_name);
	if (user_exist(user_name)) {
		cout << "User name already exist. Try another user name. " << endl
			<< "Press any key to continue..." << endl;
		_getch();
		goto sign_up_user_name;
	}
	while (user_name == "\0" || check_space(user_name)) {
		print_horizontal_row('*');
		cout << "Wrong input. Please try again..!!" << endl
			<< "0. Exit" << endl
			<< "Press any key to continue... " << endl;
		print_horizontal_row('*');
		choice = _getch();
		if (choice == '0')
			exit(0);
		else 
			goto sign_up_user_name;
	}

	fstream out;
	out.open("user_name.txt", ios::app);
	out << "\n" << user_name;
	out.close();

sign_up_password:
	cout << "Enter password: ";
	getline(cin, password);
	while (password == "\0" || check_space(password)) {
		print_horizontal_row('*');
		cout << "Wrong input. Please try again..!!" << endl
			<< "0. Exit" << endl
			<< "Press any key to try again... " << endl;
		print_horizontal_row('*');
		choice = _getch();
		if (choice == '0')
			exit(0);
		else {
			cout << endl << endl;
			goto sign_up_password;
		}
	}

	out.open("password.txt", ios::app);
	out << "\n" << password;
	out.close();
}
