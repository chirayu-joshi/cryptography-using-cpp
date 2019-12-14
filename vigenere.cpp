#include "pch.h"
#include "vigenere.h"
#include "login_signup.h"
#include "caesar.h"
#include <iostream>
#include <cstdlib>
#include <fstream>
#include <conio.h>
#include <string>
#define SPACE 100

using namespace std;

void vigenere_cipher_encrypt() {
	char choice;

	system("cls");
	print_horizontal_row('=');
	cout << "1. Manual." << endl
		<< "2. Vigenere Encryption." << endl
		<< "0. Exit." << endl;
	print_horizontal_row('=');
	cout << "Enter your choice: ";
	cin >> choice;
	if (choice == '1')
		print_vigenere_manual();
	else if (choice == '2')
		vigenere_encrypt();
	else if (choice == '0')
		exit(0);
	else {
		cout << "Wrong input. Please try again..!!" << endl
			<< "Press any key to try again...";
		_getch();
		vigenere_cipher_encrypt();
	}
}

void print_vigenere_manual() {
	char ch;

	system("cls");
	fstream in("vigenere.txt", istream::in);
	while (in >> noskipws >> ch)
		cout << ch;
	cout << endl;
	in.close();
	cout << endl << "Press any key to continue...";
	_getch();
	system("cls");
	vigenere_cipher_encrypt();
}

void vigenere_encrypt() {
	int temp;
	string message, key, temp_str = "\0";

	system("cls");
	getchar();
	cout << "Enter a message which you want to encrypt: ";
	getline(cin, message);
	cout << "Now enter a key: ";
	getline(cin, key);
	for (int i = 0; i < message.length(); i++) {
		if (i < key.length() && key[i] > 96)
			key[i] -= 32;
		if (message[i] > 96)
			message[i] -= 32;
	}

	char *e_message = new char[message.size()];
	char *d_message = new char[message.size()];
	for (size_t i = 0, j = 0; j < key.size(), i < message.size(); i++, j++) {
		if (j > (key.size() - 1))
			j = 0;
		if (message[i] == ' ') temp = SPACE;
		else temp = ((message[i] + key[j]) % 26) + 65;
		if (temp == SPACE) e_message[i] = temp;
		else e_message[i] = temp;
		temp_str += (char)temp;
	}

	// temp_str is used because "cout << e_message" gives wrong output.
	cout << "Your encrypted text is \"" << temp_str << "\"." << endl	
		<< "Your encrypted text will be strored in \"vigenere_encrypt.txt\" file." << endl;

	fstream out;
	out.open("encrypt.txt", ios::out);
	for (size_t i = 0; i < message.size(); i++)
		out << e_message[i];
	out.close();

	delete e_message, d_message;
}

void vigenere_cipher_decrypt() {
	char ch, y_or_n;
	string key;

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
		vigenere_cipher_decrypt();
		exit(0);
	}

	cout << "Now, please enter a KEY: ";
	getchar();
	getline(cin, key);
	for (int i = 0; i < key.length(); i++) {
		if (key[i] > 96)
			key[i] -= 32;
	}
	cout << "Congratulations..!! Your message is: ";
	fstream in("encrypt.txt", istream::in);
	for (size_t i = 0; !in.eof(); i++) {
		if (i > (key.size() - 1))
			i = 0;
		in >> ch;
		if (ch == SPACE) cout << ' ';
		else {
			int temp = ((ch - key[i] + 26) % 26) + 65;
			cout << (char)temp;
		}
	}
	cout << "\b ";			// an extra character got printed every time.
	in.close();
	cout << endl << endl << "Press any key to continue...";
	_getch();
	system("cls");
}