//============================================================================
// Name        : CS_2250 Project_5.cpp
// Author      : Warren Truong
// Description : This project is for testing the use and understanding of
// binary tree and display frequency of characters in string
//============================================================================

#include <iostream>
#include <fstream>

#include "BinaryTree.hpp"
using namespace std;

int main() {

	ifstream inputFile;
	inputFile.open("src/Text.txt");
	if(inputFile.fail()) {
	    cout << "The file does not exist." << endl;
	}

	string a, s;
	while (!inputFile.eof())
	   {
	      inputFile >> a;
	      s +=a;
	   }

//Remove white space optional
//	 s.erase(remove_if(s.begin(), s.end(), ::isspace), s.end());


	BinaryTree tree;
	cout << "The string is: \n"
			<< s << endl;
	cout << "------------------" << endl;
	int num_character = 0;
	cout << "Enter the numbers of consecutive characters you want\n"
			<< "to count up to: ";
	cin >> num_character;
	for (int  j = 1;  j <= num_character; j++) {
	   for (int i = 0; i + j < s.size() + 1; i++){
	            tree.insertNode(s.substr(i,j));
	   }
	}

	tree.displayInOrder();
	inputFile.close();
	return 0;
}
