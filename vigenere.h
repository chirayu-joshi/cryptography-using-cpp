#pragma once

/*
	This method converts plain text into cipher text using vigenere cipher algorithm.
	After this text is converted into ciphere text, the cipher text is stored into "vigenere_encrypt.txt" file.
*/
void vigenere_cipher_encrypt(void);

/*
	This method reads "vigenere.txt" and then outputs it into the console.
*/
void print_vigenere_manual(void);

/*
	This method is used to encrypt plain text by using vigenere's encryption method.
*/
void vigenere_encrypt(void);

/*
	This method takes cipher text from "vigenere_encrypt.txt" file and converts it into plain text.
*/
void vigenere_cipher_decrypt(void);