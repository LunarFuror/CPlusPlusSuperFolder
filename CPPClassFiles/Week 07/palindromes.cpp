/*
 * palindromes.cpp
 *  7.28: Week 7
 *   Created on: Feb 28, 2014
 *      Author: lunarfuror
 */
#include<string>
#include<iostream>

bool testPalindrome(std::string word){
	char a = word[0];
	char b = word[word.size() -1];
	bool test = false;
	if(a == b){
		if(word.size() < 3){
			return true;
		}
		else{
			test = testPalindrome(word.substr(1,word.size() -2));
		}
	}
	else{
		return test;
	}
	return test;
}

int main(){

	std::cout << std::boolalpha;
	std::cout << "Is \"radar\" a palindrome? ";
	std::cout << testPalindrome("radar") << std::endl;
	std::cout << "Is \"Grandma's cookies\" a palindrome? ";
	std::cout << testPalindrome("Grandma's cookies") << std::endl;

	return 0;
}



