#include <vector>
#include <iostream>
#include <iomanip>
#include <typeinfo>
using namespace std;

bool isValid(const string&);
int doubleEvens(string);
int addOdds(string);

int main()
{
	//
	// PLEASE DO NOT CHANGE function main
	//
	vector<string> cardnumbers = {
			"371449635398431", "4444444444444448", "4444424444444440", "4110144110144115",
			"4114360123456785", "4061724061724061", "5500005555555559", "5115915115915118",
			"5555555555555557", "6011016011016011", "372449635398431", "4444544444444448",
			"4444434444444440", "4110145110144115", "4124360123456785", "4062724061724061",
			"5501005555555559", "5125915115915118", "5556555555555557", "6011116011016011",
			"372449635397431", "4444544444444448", "4444434444544440", "4110145110184115",
			"4124360123457785", "4062724061724061", "5541005555555559", "5125115115915118",
			"5556551555555557", "6011316011016011"};

	int i;
	vector<string>::iterator itr;

	for (i = 1, itr = cardnumbers.begin(); itr != cardnumbers.end(); ++itr, i++) {
		cout << setw(2)  << i << " "
			 << setw(17) << *itr
			 << ((isValid(*itr)) ? " is valid" : " is not valid") << endl;
	}

	return 0;
}

// checks if a CC number is valid
bool isValid(const string& cNum){
	int evens = doubleEvens(cNum);
	int odds = addOdds(cNum);

    // standard check for CC's
	if ((evens + odds) % 10 == 0) {
		return true;
	}
	return false;
};

// Double every second digit from right to left. If doubling of a digit results
// in a two-digit number, add the two digits to get a single digit number.
// return the total amount
int doubleEvens(string cNum) {
	int total = 0;
    // iteract over all even numbered digits starting from the right. (starting at the second from the right)
	for (int i = (int)cNum.length(); i > 1; i -= 2) {
		char tempChar = cNum[i - 2];
        // convert the char into its corresponding interger value, then multiply by 2
		int temp = (tempChar - '0') * 2;
        // check for double digit
		if (temp >= 10) {
			int secondDigit = temp - 10;
            // add each digit together. Will never be over 18, so we know first digit is always 1
			temp = 1 + secondDigit;
		}
		total = total + temp;
	}
	return total;
}

// takes CC number and adds up all the odd placed digits from right to left
int addOdds(string cNum) {
    int total = 0;
    // iterate over odd placed digits (starting at first digit from the right)
    for (int i = (int)cNum.length(); i >= 1; i -= 2) {
        char tempChar = cNum[i - 1];
        // convert char into corresponding int
        int temp = (tempChar - '0');
        total = total + temp;
    }
    return total;
}
