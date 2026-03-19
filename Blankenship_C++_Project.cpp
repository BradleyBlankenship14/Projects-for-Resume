// ****************************************
// Program Title: Menu
// Name: Bradley Blankenship
// Program Description: allows user to select from a menu to count the # of vowels
// or consonants and the number of lines in a specified input file.
// ****************************************
#include <iostream>
#include <fstream>
#include <iomanip>
#include <cctype>
#include <string>

using namespace std;

// function prototypes
void PrintMenu();
int GetAnInteger();
bool OpeninFile(ifstream &inFile, string &filename);
void ProcessVowels(ifstream &inFile);
void ProcessConsonants(ifstream &inFile);

int main()
{
	cout << endl;
	int choice;
	
	ifstream inFile;
	
	string filename;
	
	PrintMenu();
	choice = GetAnInteger(); // priming read
	
		while(choice != 0)
		{
			if(choice == 1 || choice == 2)
			{
				if(!OpeninFile(inFile, filename))
				{
					cout << string(14,'*') << "  File Open Error  " << string(14,'*') << endl;
					cout << "==> Input file failed to open properly!!" << endl;
					cout << "==> Attempted to open file: " << filename << endl;
					cout << "==> Selected operation has been canceled!!" << endl;
					cout << string(47,'*') << endl << endl;
				}
				else
				{
					if(choice == 1)
					{
						ProcessVowels(inFile);
					}
					else
					{
						ProcessConsonants(inFile);
					}
				}
			inFile.close();
			inFile.clear();
		}
		else
		{
			cout << endl;
			cout << string(13,'*') << "  Invalid Selection  " << string(13,'*') << endl;
			cout << "==> Invalid integer value entered!!" << endl;
			cout << "==> Please enter 0, 1 or 2!" << endl;
			cout << string(47,'*') << endl << endl;
		}
	
		PrintMenu();
		choice = GetAnInteger();
	}

	cout << endl << "Quit selected.  Terminating program now..." << endl << endl;
	
	return 0;
	}

	void PrintMenu()
	{
		cout << string(18,'*') << "  Options  " << string(18,'*') << endl;
		cout << "0. Exit Program" << endl;
		cout << "1. Count number of vowels" << endl;
		cout << "2. Count number of consonants" << endl;
		cout << string(47,'*') << endl << endl;
		
		cout << "Input your selection: ";
	}
	
	int GetAnInteger()
	{
		int value;
		cin >> value;
		
		while(cin.fail())
		{
			cin.clear();
			
			char ch;
			cin >> ch;
			cout << ch << endl;
			
			cin.ignore(1000, '\n');
			
			cout << endl;
			cout << string(13,'*') << "  Invalid Selection  " << string(13,'*') << endl;
			cout << "==> Invalid character entered!!" << endl;
			cout << "==> Please enter 0, 1 or 2" << endl;
			cout << string(47,'*') << endl << endl;
			
			PrintMenu();
			cin >> value;
		}
		
		cout << value << endl;
		cin.ignore(1000,'\n');
		
		return value;
	}
	
	bool OpeninFile(ifstream &inFile, string &filename)
	{
		cout << "Enter the name of the input file now: ";
		cin >> filename;
		cout << filename << endl << endl;
		
		inFile.open(filename);
		
		if(inFile.fail())
		{
			return false;
		}
		
		return true;
		
	}
	
	void ProcessVowels(ifstream &inFile)
	{
		char ch;
		int vowels = 0;
		int lines = 0;
		
		inFile.get(ch);
		
		if(inFile.fail())
		{
			cout << string(15,'*') << "  File Is Empty  " << string(15,'*') << endl;
			cout << "==> Input file is empty!" << endl;
			cout << "==> No information to process!" << endl;
			cout << string(47,'*') << endl << endl;
			return;
		}
		
		while(!inFile.fail())
		{
			char lower = tolower(ch);
			
			if(lower == 'a' || lower == 'e' || lower == 'i' || lower == 'o' || lower == 'u')
			{
				vowels++;
			}
			
			if(ch == '\n')
			{
				lines++;
			}
			
			inFile.get(ch);
		}
		
		double avg = (double)vowels / lines;
		
		cout << fixed << setprecision(3);
		
		cout << "Counting Number of Vowels" << endl;
		cout << string(25,'-') << endl;
		cout << "There are " << vowels << " vowels in the file" << endl;
		cout << "There are " << lines << " lines in the file" << endl;
		cout << "This is an average of " << avg << " vowels per line" << endl;
		cout << string(25,'-') << endl << endl;
	}
	
	void ProcessConsonants(ifstream &inFile)
	{
		char ch;
		int consonants = 0;
		int lines = 0;
		
		inFile.get(ch);
		
		if(inFile.fail())
		{
			cout << string(15,'*') << "  File Is Empty  " << string(15,'*') << endl;
			cout << "==> Input file is empty!" << endl;
			cout << "==> No information to process!" << endl;
			cout << string(47,'*') << endl << endl;
			return;
		}
		
		while(!inFile.fail())
		{
			char lower = tolower(ch);
			
			if(isalpha(lower) && !(lower == 'a' || lower == 'e' || lower == 'i' || lower == 'o' || lower == 'u'))
			{
				consonants++;
			}
			
			if(ch == '\n')
			{
				lines++;
			}
			
			inFile.get(ch);
			
		}
		
		double avg = (double)consonants / lines;
		
		cout << fixed << setprecision(3);
		
		cout << "Counting Number of Consonants" << endl;
		cout << string(29,'-') << endl;
		cout << "There are " << consonants << " consonants in the file" << endl;
		cout << "There are " << lines << " lines in the file" << endl;
		cout << "This is an average of " << avg << " consonants per line" << endl;
		cout << string(29,'-') << endl << endl;
	}
	
