#pragma once

/*
	This method prints a row with the help of given symbol.
*/
void print_horizontal_row(char);

/*
	This method converts plain text into cipher text using caesar cipher algorithm.
	After the text is converted into cipher text, the cipher text is stored into "caesar_encrypt.txt" file.
*/
void caesar_cipher_encrypt(void);

/*
	This method reads "caesar.txt" and then outputs it into the console.
*/
void print_caesar_manual(void);

/*
	This method is used to encrypt plain text by using substitution technique.
*/
void substitution_tech_encrypt(void);

/*
	This method is used to encrypt plain text by using transportation technique.
*/
void transportation_tech_encrypt(void);

/*
	This method takes cipher text from "caesar_cipher_encrypt.txt" file and converts it into plain text.
*/
void caesar_cipher_decrypt(void);

/*
	This method is used to decrypt cipher text by using substitution technique.
*/
void substitution_tech_decrypt(void);

/*
	This method is used to decrypt cipher text by using transportation technique.
*/
void transportation_tech_decrypt(void);
