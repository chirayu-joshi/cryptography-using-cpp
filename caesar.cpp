#include "pch.h"
#include "caesar.h"
#include "login_signup.h"
#include <iostream>
#include <cstdlib>
#include <fstream>
#include <conio.h>
#include <string>

using namespace std;

void print_horizontal_row(char symbol) {
	for (int i = 0; i < 119; i++)
		cout << symbol;
	cout << endl;
}

void caesar_cipher_encrypt() {
	short int choice;

	system("cls");
	print_horizontal_row('=');
	cout << "0. Manual" << endl
		<< "1. Substitution technique." << endl
		<< "2. Transposition technique." << endl
		<< "3. Exit." << endl;
	print_horizontal_row('=');
	cout << "Enter your choice: ";
	cin >> choice;
	if (choice == 0)
		print_caesar_manual();
	else if (choice == 1)
		substitution_tech_encrypt();
	else if (choice == 2)
		transportation_tech_encrypt();
	else if (choice == 3)
		exit(0);
	else
		caesar_cipher_encrypt();
}

void print_caesar_manual() {
	char ch;

	fstream in("caesar.txt", istream::in);
	while (in >> noskipws >> ch)
		cout << ch;
	cout << endl;
	in.close();
	cout << endl <<"Press any key to continue...";
	_getch();
	system("cls");
	caesar_cipher_encrypt();
}

void substitution_tech_encrypt() {
	string message;
	short int key;

	cout << "Enter a message which you want to encrypt: ";
	getchar();
	getline(cin, message);
	message += ' ';				
	/* 
		"   message += ' '   " is used in substitution_tech_decrypt 
	    so that last character (which is space) is printed twice
	*/
	cout << "Now enter a key: ";
	cin >> key;
	for (int i = 0; message[i]; i++) 
		message[i] += key;
	cout << "Your encrypted text is \"" << message << "\"." << endl
		<< "Your encrypted text will be strored in \"encrypt.txt\" file." << endl;

	fstream out("encrypt.txt", ostream::out);
	out << message;
	out.close();
}

void transportation_tech_encrypt() {
	string message;

	cout << "Enter a message which you want to encrypt: ";
	getchar();
	getline(cin, message);
	
	reverse(message.begin(), message.end());
	cout << "Your encrypted text is \"" << message << "\"." << endl
		<< "Your encrypted text will be strored in \"encrypt.txt\" file." << endl;

	fstream out("encrypt.txt", ostream::out);
	out << message;
	out.close();
}

void caesar_cipher_decrypt() {
	char choice;
	
	system("cls");
	print_horizontal_row('=');
	cout << "1. Substitution technique." << endl
		<< "2. Transposition technique." << endl
		<< "0. Exit." << endl;
	print_horizontal_row('=');
	cout << "Enter your choice: ";
	cin >> choice;
	if (choice == '1')
		substitution_tech_decrypt();
	else if (choice == '2')
		transportation_tech_decrypt();
	else if (choice == '0')
		exit(0);
	else
		caesar_cipher_decrypt();
}

void substitution_tech_decrypt() {
	char ch, y_or_n;
	int key;

	system("cls");
	print_horizontal_row('=');
	cout << "INSTRUCTIONS:" << endl
		<< "==> You will find a file named \"encrypt.txt\" in the folder where you are running \"Cryptography.exe\"." << endl
		<< "==> If you recieved email, you have to copy your encrypted text and paste it into \"encrypt.txt\" file." << endl
		<< "==> After completing above task, run this program again." << endl << endl
		<< "==> If you have already completed above tasks, then continue OR else exit the program and follow the instructions." << endl;
	print_horizontal_row('=');
	cout << "Do you want to continue?  (y/n)  : ";
	cin >> y_or_n;
	while (!(y_or_n == 'y' || y_or_n == 'Y' || y_or_n == 'n' || y_or_n == 'N')) {
		cout << "Wrong input. Please try again..!!" << endl
			<< "Do you want to continue?  (y/n)  : ";
		cin >> y_or_n;
	}
	if (y_or_n == 'n' || y_or_n == 'N') {
		caesar_cipher_decrypt();
		exit(0);
	}
	
	cout << "Now, please enter a KEY: ";
	cin >> key;
	cout << "Congratulations..!! Your message is: ";
	fstream in("encrypt.txt", istream::in);
	while (!in.fail()) {
		in >> ch;
		cout << (char)(ch - key);
	}
	in.close();
	cout << endl << endl << "Press any key to continue...";
	_getch();
	system("cls");
}

void transportation_tech_decrypt() {
	char y_or_n;
	string message, temp;

	system("cls");
	print_horizontal_row('=');
	cout << "INSTRUCTIONS:" << endl
		<< "==> You will find a file named \"encrypt.txt\" in the folder where you are running \"Cryptography.exe\"." << endl
		<< "==> If you recieved email, you have to copy your encrypted text and paste it into \"encrypt.txt\" file." << endl
		<< "==> After completing above task, run this program again." << endl << endl
		<< "==> If you have already completed above tasks, then continue OR else exit the program and follow the instructions." << endl;
	print_horizontal_row('=');
	cout << "Do you want to continue?  (y/n)  : ";
	cin >> y_or_n;
	while (!(y_or_n == 'y' || y_or_n == 'Y' || y_or_n == 'n' || y_or_n == 'N')) {
		cout << "Wrong input. Please try again..!!" << endl
			<< "Do you want to continue?  (y/n)  : ";
		cin >> y_or_n;
	}
	if (y_or_n == 'n' || y_or_n == 'N') {
		caesar_cipher_decrypt();
		exit(0);
	}

	cout << "Congratulations..!! Your message is: ";
	fstream in("encrypt.txt", istream::in);
	while (!in.eof()) {
		in >> temp;
		message = message + temp + ' ';
	}
	in.close();
	reverse(message.begin(), message.end());
	cout << message << endl;
	cout << endl << endl << "Press any key to continue...";
	_getch();
	system("cls");
}
