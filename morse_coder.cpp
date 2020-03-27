#include <iostream>
#include <string>
#include <map>
#include <fstream>
#include <algorithm>
#include <cmath>
#include <fstream>
#include <iostream>

using namespace std;



int main(int argc, const char* argv[]) {
	fstream text;
	//define morse codes standard
	map<string, string> coder;
	coder = {
		{ "A",".-"},
		{ "B","-..." },
		{ "C","-.-." },
		{ "D","-.." },
		{ "E","." },
		{ "F","..-." },
		{ "G","--."},
		{ "H","...." },
		{ "I",".." },
		{ "J",".---" },
		{ "K","-.-" },
		{ "L",".-.." },
		{ "M","--" },
		{ "N","-." },
		{ "O","---" },
		{ "P",".--." },
		{ "Q","--.-" },
		{ "R",".-." },
		{ "S","..." },
		{ "T","-" },
		{ "U","..-" },
		{ "V","...-" },
		{ "W",".--" },
		{ "X","-..-" },
		{ "Y","-.--" },
		{ "Z","--.." },
		{ "1",".----" },
		{ "2","..---" },
		{ "3","...--" },
		{ "4","....-" },
		{ "5","....." },
		{ "6","-...." },
		{ "7","--..." },
		{ "8","---.." },
		{ "9","----." },
		{ "0","-----" },
		{ " ","   " },
	};

	//get filename from shell to read text from
	string infilename;
	if(argc > 1)
		infilename = argv[1];
	else
		infilename = "text.txt";

	//get filename from shell to write code to
	string outfilename;
	if(argc > 2)
		outfilename = argv[2];
	else
		outfilename = "code.txt";


	//read text from input file
	string stext;
	text.open(infilename);
	//check if file openes successfully
	if(!text)
		return -1;
	getline(text, stext);
	text.close();
	cout << stext << endl;

	// convert string to upper case
	for(auto & c: stext)
		c = toupper(c);

	cout << stext << endl;

	//coder
	string coded = "";
	string temp;
	for (auto & k : stext) {
		temp = k;
		coded += coder.find(temp)->second;
		coded += " ";
	}

	cout << coded << endl;
	
	//write coded to a file 
	text.open(outfilename, ios::out);
	text << coded;
	text.close();
	
	return 0;
}