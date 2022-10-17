#include <iostream>
using namespace std;
const int INPUT_SIZE = 151;

//finding the size of given string
int sizeOfStr(const char* str) {
	int i = 0;
	while (str[i] != '\0') {// adding to i until we meeat \0
		i++;
	}
	return i;
}

//copies the characters "from" to "to"
void strcopy(char* to, const int& size, const char* from) {
	for (int i = 0; i < size; i++) {
		to[i] = from[i];
	}
	//adding turminating null at the end
	to[size] = '\0';
}

//converting from upper to lowercase
void charToLower(char& ch) {
	if (ch <= 'Z' && ch >= 'A') {
		ch -= ('Z' - 'z');
	}
}

//converting string from lower to uppercase
void stringToLower(char* string) {
	int size = sizeOfStr(string);
	for (int i = 0; i < size; i++) {
		charToLower(string[i]);
	}
}


//checks are there different characters than letters
bool differentCharacters(const char* str) {
	int size = sizeOfStr(str);
	for (int i = 0; i < size; i++) {
		//comparing ascii numbers
		if ((int)str[i] < 97 || (int)str[i]>122) {
			return true;
		}
	}
	
	return false;
}

//alorithm for making a rtl string
char* RTL(char* input, const int& size) {

	//here we will store the sting that is rtl for now
	char* rtlString_fornow = new char[INPUT_SIZE];

	//size of the final rtl string and numbers of the times a given character is met
	int size_rtl = 0, timesMetCharacter=0;

	//memory allocation validation
	if (rtlString_fornow == nullptr) {
		cout << "Unssuccsesful memory allocation";
		delete[] rtlString_fornow;
		return nullptr;
	}


	char currentSymbol = input[0];


	for (int i = 0; i < size; i++) {

		//if a character is met then the times it gets met raises
		if (currentSymbol == input[i]) {
			timesMetCharacter++;
		}

		//if the upcoming characters is different starts to input to rtlString_fornow
		if (currentSymbol != input[i+1]) {
			
			//if the times MetCharacter is high than 100
			if (timesMetCharacter >= 100) {

				//storing the character
				rtlString_fornow[size_rtl] = currentSymbol;
				size_rtl++;
				//storing the digit on the left of timesMetCharacter
				rtlString_fornow[size_rtl] = (timesMetCharacter / 100) + '0';
				size_rtl++;
				//storing the middle digit of timesMetCharacter
				rtlString_fornow[size_rtl] = ((timesMetCharacter / 10) % 10) + '0';
				size_rtl++;
				//storing the digit on the right of timesMetCharacter
				timesMetCharacter %= 10;
				timesMetCharacter %= 10;
				rtlString_fornow[size_rtl] = timesMetCharacter + '0';
				size_rtl++;

				//reseting timesMetCharacter
				timesMetCharacter = 0;
			}

			//if the timesMetCharacter is higher than 10
			if (timesMetCharacter >= 10) {
				
				//storing the character
				rtlString_fornow[size_rtl] = currentSymbol;
				size_rtl++;
				//storing the digit on the left of timesMetCharacter
				rtlString_fornow[size_rtl] = timesMetCharacter / 10 + '0';
				size_rtl++;
				//storing the digit on the right of timesMetCharacter
				rtlString_fornow[size_rtl] = timesMetCharacter % 10 + '0';
				size_rtl++;

				//reseting timesMetCharacter
				timesMetCharacter = 0;
			}


			//if the times is met is higher than 1 then stores the characters and its number
			if (timesMetCharacter > 1) {

				//storing the character
				rtlString_fornow[size_rtl] = currentSymbol;
				size_rtl++;
				//storing the number of timesMetCharacter
				rtlString_fornow[size_rtl] = timesMetCharacter+'0';
				size_rtl++;

				//resseting timesMetCharacter
				timesMetCharacter = 0;
			}

			//if the times is met is 1 then stores only the currentSymbol
			if (timesMetCharacter == 1) {

				//storring the character
				rtlString_fornow[size_rtl] = currentSymbol;
				size_rtl++;
				timesMetCharacter = 0;
			}

			//changes to the next symbol
			currentSymbol = input[i+1];
		}
	}

    //storing the rtlString with accurate size
	char* rtlString = new char[size_rtl+1];

	//memory allocation validation
	if (rtlString == nullptr) {
		cout << "Unssuccsesful memory allocation";
		delete[] rtlString_fornow;
		delete[] rtlString;
		return nullptr;
	}

	//coping the characters from rltString_fornow to rtlString
	strcopy(rtlString, size_rtl, rtlString_fornow);
	delete[] rtlString_fornow;
	return rtlString;


}
int main() {

	char* input = new char[INPUT_SIZE];

	//memory allocation validation
	if (input == nullptr) {
		cout << "Unssuccssesful allocation of memory!";
		return -1;
	}
	cin >> input;

	//making all characters to be lowercase
	stringToLower(input);

	//if there is different character from the letters the program ends
	if (differentCharacters(input)) {
		cout << "Your input contains invalid characters!";
		delete[] input;
		return -2;
	}

	//getting the size of the input
	int size_input = sizeOfStr(input);

	char* p_rtl = RTL(input, size_input);

	//memory allocation validation
	if (p_rtl == nullptr) {
		cout << "Unssucsesful memory allocation";
		delete[] input;
		delete p_rtl;
		return -3;
	}
	cout << endl;
	cout << p_rtl;

	delete[] p_rtl;
	delete[] input;

	return 0;
}