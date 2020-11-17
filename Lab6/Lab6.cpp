/*
Aiden Trimble
C++ Fall 2020
Due: November 16th, 2020
To convert binary code from an inputted file into decimal form outputted on screen
*/

#include <fstream>
#include <iostream>


using namespace std;

void conversion(char& inputbinary, int& countdigit, bool& valid, ifstream& inputFile, unsigned int& decimalconv);
/*Preconditions: File must be read without errors.
Postconditions: Values in the file were read and converted into decimal form. */

void oFile(ifstream& inputFile, ifstream& inputFile2);
/*Preconditions: File must exist and be located where it was specified.
Postconditions: inputFile and inputFile2 were opened. */

void output(bool valid, ifstream& inputFile2, char& inputbinary2, int countdigit, unsigned int decimalconv);
/*Preconditions: Valid either needs to be true or false for the if-statements and the binary & decimaloutput functions need to work properly.
Postconditions: Outputs the inputted binary and the converted decimal and a bad digit message if valid was false. */

void binary(int countdigit);
/*Preconditions: Needs to pass beginning of output function and countdigit needs to have a value.
Postconditions: Outputs the number of spaces for the binary numbers to be centered with other numbers. */

void decimaloutput(unsigned int decimalconv);
/*Preconditions: Needs to pass beginning of output function and decimalconv needs to have a value.
Postconditions: Outputs the number of spaces for the converted decimal numbers to be centered. */



int main()
{
	//Outputs the categories for the binary and decimal numbers
	cout << "--------------------------------------------------------" << endl;
	cout << "     Inputted Binary Number:\tDecimal Conversion:" << endl;
	cout << "--------------------------------------------------------" << endl;

	//Gives the input character values.
	char inputbinary;
	char inputbinary2;

	//Gives the given input files names.
	ifstream inputFile;
	ifstream inputFile2;

	//The open file function is called.
	oFile(inputFile, inputFile2);
	//Reads the characters in the file.
	inputFile >> inputbinary;

	//Loop that runs the main functions.
	while (inputFile)
	{
		//variables that are redefined here at the beginning of every loop .
		int countdigit = 0;
		bool valid = true;
		unsigned int decimalconv = 0;
		
		//Conversion function being called to convert the characters into decimal form.
		conversion(inputbinary, countdigit, valid, inputFile, decimalconv);

		//Output function being called to output to the screen the binary numbers, decimal numbers and spaces.
		output(valid, inputFile2, inputbinary2, countdigit, decimalconv);

		//Reads what is next in the file.
		inputFile >> inputbinary;
		
	}

	return 0;

}

//Conversion function that converts the characters from the file into decimal form.
void conversion(char& inputbinary, int& countdigit, bool& valid, ifstream& inputFile, unsigned int& decimalconv)
{
	//While loop that makes sure there are only ones and zeros, if otehr characters are there it sets valid to false.
	while (inputFile && inputbinary != '1')
	{
		if (inputbinary != '0')
		{
			valid = false;
			break;
		}

		inputFile >> inputbinary;
	}

	//While loop that calculates the converted decimal number and reads until reads \n.
	while (inputFile && inputbinary != '\n')
	{
		
		//Switch statement that tells what to do if character is 0 or 1.
		switch (inputbinary)
		{
		case '0': decimalconv = (decimalconv * 2) + 0;
			break;
		case '1': decimalconv = (decimalconv * 2) + 1;
			break;
		default: valid = false;
			break;
		}

		//Reads the next character after the loop.
		inputFile.get(inputbinary);
		//Adds one to countdigit every time loop runs for the spaces later.
		countdigit++;

	}


}

//Open file function that opens the inputted files.
void oFile(ifstream& inputFile, ifstream& inputFile2)
{
	//Defines where the file is located and names it inputfilename.
	string inputfilename = "C:/Users/adtri/Desktop/C++ Saves/Lab6/Lab6/Lab6/BinaryIn.dat";

	//Opens the file
	inputFile.open(inputfilename);
	//Checks to make sure the file exists.
	if (!inputFile)
	{
		cout << "Failed to Read File";
	}
	//Opens the file again for binary output later.
	inputFile2.open(inputfilename);

}

//Output function that outputs to the screen the binary numbers, decimal numbers and spaces if they are valid.
void output(bool valid, ifstream& inputFile2, char& inputbinary2, int countdigit, unsigned int decimalconv)
{
	//Runs this if statement if valid is true.
	if (valid)
	{
		//Binary output function is called.
		binary(countdigit);
		
		//Reads the input file again.
		inputFile2 >> inputbinary2;

		//While loop that reads until reads a one.
		while (inputFile2 && inputbinary2 != '1')
		{
			inputFile2 >> inputbinary2;
		}

		//While loops that reads and outputs the one or zero until reads \n. 
		while (inputFile2 && inputbinary2 != '\n')
		{
			switch (inputbinary2)
			{
			case '0': cout << "0"; break;
			case '1': cout << "1"; break;
			}
			//Reads the next character.
			inputFile2.get(inputbinary2);
		}

		//If statement that outputs the number of spaces after the outputted binary numbers if the remainder is 0.
		if (countdigit % 2 == 0)
		{
			binary(countdigit);
		}
		//Outputs an extra space if it is odd.
		else
		{
			binary(countdigit);
			cout << " ";
		}

		cout << "\t";
		//Decimal function being called that displays the number of spaces needed to center the decimal numbers.
		decimaloutput(decimalconv);
		//Outputs the converted decimal number
		cout << decimalconv << endl;

	}
	//Else statement that runs if valid is false.
	else
	{
		//Reads file again to output a bad digit message.
		inputFile2 >> inputbinary2;
		while (inputFile2 && inputbinary2 != '\n')
		{
			inputFile2.get(inputbinary2);
		}
		
		cout << "       Bad Digit on Input" << endl;
	}


}

//Binary output function that calculates then displays the number of spaces to put before the binary numbers.
void binary(int countdigit)
{
	//calulates the number of spaces on the side.
	int bin_spaces = (30 - countdigit) / 2;
	//For loop that outputs the spaces.
	for (int number = 1; number <= bin_spaces; number++)
	{
		cout << " ";
	}

}

//Decimal output function that calculates then displays the number of spaces to put before the decimal numbers
void decimaloutput(unsigned int decimalconv)
{
	//Integer for amount of digits in decimalconv
	int dec_digits = 1;
	
	//for loops that calculates the number of digits in decimalconv
	for (decimalconv; decimalconv > 10; decimalconv /= 10)
	{
		dec_digits++;
	}

	//calculates the number fo spaces beside the number
	int dec_spaces = (15 - dec_digits) / 2;

	//For loop that outputs the spaces
	for (int number2 = 1; number2 <= dec_spaces; number2++)
	{
		cout << " ";
	}

}