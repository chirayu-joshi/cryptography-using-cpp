#pragma once

/*
	This method checks weather there is space inbetween a string or not.
*/
bool check_space(char);

/*
	This method checks weather the username already exists or not.
*/
bool user_exist(char);

/*
	This method is used to select "login" or "sign up".
*/
void login_page(void);

/*
	This method allows existing user to login in only.
	This method uses files named "user_name" and "password" to validate user input.
*/
void login(void);

/*
	This method allows new user to create new account.
	This method uses files named "user_name" and "password" to create new account.
*/
void sign_up(void);
