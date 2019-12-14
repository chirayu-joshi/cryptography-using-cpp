/*
	DESCRIPTION  :   This is a program which implements cryptography and converts plain text
					 into cipher text. This cipher text is sent to receiver through email.
					 After that this same program is used to decrypt the cipher text
					 and convert it into plain text.

	STARTING DATE:  10/03/2019.

	@version 1.0

	@author Chirayu Joshi (18IT042), Shyamkumar Aghera (18IT001)
*/

#include "pch.h"
#include "login_signup.h"
#include "caesar.h"
#include "vigenere.h"
#include <iostream>
#include <cstdlib>
#include <conio.h>

using namespace std;

/*
	This method prints welcome message.
*/
void display_welcome_message(void);

/*
	This method is used to convert plain text into cipher text.
	This method also creates additional files in which cipher text is stored.
*/
void plain_to_cipher(void);

/*
	This method is used to convert cipher text into plain text.
	This method recieves data from a file which was created by any method of "plain_to_cipher".
	This method also creates additional files of plain
*/
void cipher_to_plain(void);

// execution of program starts from here.
int main() {
	short int choice;

	login_page();
	display_welcome_message();
	cout << "1. Plain text to Cipher text" << endl
		<< "2. Cipher text to Plain text" << endl
		<< "0. Exit" << endl
		<< "Enter your choice: ";
	cin >> choice;
	while (choice < 0 || choice > 2) {
		cout << endl << "Wrong input. Please try again..!!" << endl
			<< "Enter your choice: ";
		cin >> choice;
	}

	if (choice == 1)
		plain_to_cipher();
	else if (choice == 2)
		cipher_to_plain();
	else
		return 0;
	return 0;
}

void display_welcome_message() {
	system("cls");
	cout << endl << endl << endl << endl << endl
		<< endl << endl << endl << endl << endl;
	print_horizontal_row('=');
	cout << "\t\t\t\t\t\tWELCOME TO CRYPTOGRAPHY APP" << endl;
	print_horizontal_row('=');
	_getch();
	system("cls");          // used to clear the screen (present in conio.h lib)
}

void plain_to_cipher() {
	short int choice;

	system("cls");
	cout << "1. Caesar Cipher." << endl
		<< "2. Vigenere Cipher." << endl
		<< "3. Hill Cipher." << endl
		<< "4. Transposition Cipher." << endl
		<< "5. XOR + AND + OR Cipher." << endl
		<< "0. Exit" << endl
		<< "Enter your choice: ";
	cin >> choice;
	while (choice < 0 || choice > 5) {
		cout << endl << "Wrong input. Please try again..!!" << endl
			<< "Enter your choice: ";
		cin >> choice;
	}
	switch(choice) {
	case 1:
		caesar_cipher_encrypt();
		break;
	case 2:
		vigenere_cipher_encrypt();
		break;
	/*case 3:
		hill_cipher_encrypt();
		break;
	case 4:
		transposition_cipher_encrypt();
		break;
	case 5:
		xor_and_or_encrypt();
		break;*/
	default:
		exit(0);
	}
}

void cipher_to_plain() {
	short int choice;
	system("cls");
	cout << "1. Caesar Cipher." << endl
		<< "2. Vigenere Cipher." << endl
		<< "3. Hill Cipher." << endl
		<< "4. Transposition Cipher." << endl
		<< "5. XOR + AND + OR Cipher." << endl
		<< "0. Exit" << endl
		<< "Enter your choice: ";
	cin >> choice;
	while (choice < 0 || choice > 5) {
		cout << endl << "Wrong input. Please try again..!!" << endl
			<< "Enter your choice: ";
		cin >> choice;
	}
	switch (choice) {
	case 1:
		caesar_cipher_decrypt();
		break;
	case 2:
		vigenere_cipher_decrypt();
		break;
	/*case 3:
		hill_cipher_decrypt();
		break;
	case 4:
		transposition_cipher_decrypt();
		break;
	case 5:
		xor_and_or_decrypt();
		break;*/
	default:
		exit(0);
	}
}
