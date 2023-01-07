/*

	Name : Asad Tariq
	Roll Number : 19i-0659
	Section : E
	Assignment : 1

*/

/* NOTE !!!!! */
/* S-BOX function is running correctly. But here I have a unresolved issue with the test case of S-BOX. Kindly Check it with main () */
/* Thank You */


#include "gtest/gtest.h"
#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;

/* This function is for finding the length of string */
template <typename T>
int stringLength(const T& str) {
	int count = 0;
	int index = 0;

	while (str[index] != '\0') {
		count++;
		index++;
	}

	return count;
}

/* :::::::::::::::::::::::: --------------------- ::::::::::::::::::::::::*/

/* This Function is for finding number of digits */
int countDigits(int num) {
	int count = 0;
	while (num > 0) {
		num = num / 10;
		count++;
	}
	return count;
}

/* :::::::::::::::::::::::: --------------------- ::::::::::::::::::::::::*/

/* This Function is to convert string into an Integer */
template <typename T>
int toInteger(T str) {
	int s_to_int = 0; int power_value;
	int s_len = stringLength(str);
	int flag = 0;
	for (int i = 0; i < s_len; i++) {
		if ((str[i] >= '0' && str[i] <= '9') || str[i] == '-') {
			if (i > 0 && str[i] == '-') {
				flag = 1; break;
			}
		}
		else {
			flag = 1; break;
		}
	}

	if (flag == 1)
		return 0;

	int exp = s_len - 1;

	for (int i = 0; i < s_len; i++) {
		power_value = pow(10, exp);

		if (str[i] == '0') {
			s_to_int = s_to_int + power_value * 0;
		}

		else if (str[i] == '1') {
			s_to_int = s_to_int + power_value * 1;
		}

		else if (str[i] == '2') {
			s_to_int = s_to_int + power_value * 2;
		}

		else if (str[i] == '3') {
			s_to_int = s_to_int + power_value * 3;
		}

		else if (str[i] == '4') {
			s_to_int = s_to_int + power_value * 4;
		}

		else if (str[i] == '5') {
			s_to_int = s_to_int + power_value * 5;
		}

		else if (str[i] == '6') {
			s_to_int = s_to_int + power_value * 6;
		}

		else if (str[i] == '7') {
			s_to_int = s_to_int + power_value * 7;
		}

		else if (str[i] == '8') {
			s_to_int = s_to_int + power_value * 8;
		}

		else if (str[i] == '9') {
			s_to_int = s_to_int + power_value * 9;
		}

		exp--;
	}
	return s_to_int;
}

/* :::::::::::::::::::::::: --------------------- ::::::::::::::::::::::::*/

/* This Function is to convert Integer to String */
template <typename T>
T toString(int num) {
	T str = "\0";
	int tDigits = countDigits(num);
	int mod; int power;
	bool flag = 0;

	if (num < 0)
		str += '-';

	for (int i = 0; i < tDigits; i++) {
		power = pow(10, tDigits - i - 1);
		mod = num / power;
		num = num % power;

		if (mod == 0)
			str += '0';

		else if (mod == 1)
			str += '1';

		else if (mod == 2)
			str += '2';

		else if (mod == 3)
			str += '3';

		else if (mod == 4)
			str += '4';

		else if (mod == 5)
			str += '5';

		else if (mod == 6)
			str += '6';

		else if (mod == 7)
			str += '7';

		else if (mod == 8)
			str += '8';

		else if (mod == 9)
			str += '9';

	}

	return str;
}

/* :::::::::::::::::::::::: --------------------- ::::::::::::::::::::::::*/

/* This Function is to convert char into an Integer*/
int toInteger(char str) {
	int value = -1;

	if (str == '1')
		value = 1;
	else if (str == '2')
		value = 2;
	else if (str == '3')
		value = 3;
	else if (str == '4')
		value = 4;
	else if (str == '5')
		value = 5;
	else if (str == '6')
		value = 6;
	else if (str == '7')
		value = 7;
	else if (str == '8')
		value = 8;
	else if (str == '9')
		value = 9;
	else if (str == '0')
		value = 0;

	return value;
}

/* :::::::::::::::::::::::: --------------------- ::::::::::::::::::::::::*/

/* This Function is to reverse a string */
template <typename T>
T reverseString(T str) {
	T tempStr = "\0";
	int length = stringLength(str);

	for (int i = length - 1; i >= 0; i--)
		tempStr += str[i];

	return tempStr;
}

/* :::::::::::::::::::::::: --------------------- ::::::::::::::::::::::::*/

/* This Function is convert a decimal into binary */
template <typename T>
T toBinary(int number) {
	if (number == 0)
		return "0";

	T str1 = "\0";
	T str2 = "\0";
	int tempNum = number;
	int mod;

	while (tempNum > 0) {
		mod = tempNum % 2;

		if (mod == 0)
			str1 += "0";
		else
			str1 += toString<string>(mod);

		tempNum = tempNum / 2;
	}

	str2 = reverseString(str1);

	return str2;
}

/* :::::::::::::::::::::::: --------------------- ::::::::::::::::::::::::*/

/* This Function is to convert binary string into a decimal integer */
template <typename T>
int toDecimal(T str) {
	int decimalNum = 0;
	int strSize = stringLength(str);

	for (int i = 0, j = strSize - 1; i < strSize; i++, j--)
		decimalNum += (toInteger(str[i])) * pow(2, j);

	return decimalNum;
}

/* :::::::::::::::::::::::: --------------------- ::::::::::::::::::::::::*/

/* This Function is for S-Box calcultaion. It will add bits to make numbers less than 8 to 4 bit number by concatinating 0s*/
template <typename T>
T toBinary2(T str) {

	if (toDecimal(str) >= 0 && toDecimal(str) < 8) {
		if (str == "0")
			str = "0000";
		else if (str == "1" || str == "01")
			str = "0001";

		else if (str == "10" || str == "010")
			str = "0010";
		else if (str == "11" || str == "011")
			str = "0011";

		else if (str == "100" || str == "0100")
			str = "0100";
		else if (str == "101" || str == "0101")
			str = "0101";
		else if (str == "110" || str == "0110")
			str = "0110";
		else if (str == "111" || str == "0111")
			str = "0111";
	}

	return str;
}

/* :::::::::::::::::::::::: --------------------- ::::::::::::::::::::::::*/

/* This Function is used to convert Hexa value into binary */
template <typename T>
T convertIntoHexadecimal(const T& key) {
	int stringSize = stringLength(key);
	T str = "\0";

	for (int i = 0; i < stringSize; i++) {
		if (key[i] == '0')
			str += "0000";

		else if (key[i] == '1')
			str += "0001";

		else if (key[i] == '2')
			str += "0010";

		else if (key[i] == '3')
			str += "0011";

		else if (key[i] == '4')
			str += "0100";

		else if (key[i] == '5')
			str += "0101";

		else if (key[i] == '6')
			str += "0110";

		else if (key[i] == '7')
			str += "0111";

		else if (key[i] == '8')
			str += "1000";

		else if (key[i] == '9')
			str += "1001";

		else if (key[i] == 'A' || key[i] == 'a')
			str += "1010";

		else if (key[i] == 'B' || key[i] == 'c')
			str += "1011";

		else if (key[i] == 'C' || key[i] == 'c')
			str += "1100";

		else if (key[i] == 'D' || key[i] == 'd')
			str += "1101";

		else if (key[i] == 'E' || key[i] == 'e')
			str += "1110";

		else if (key[i] == 'F' || key[i] == 'f')
			str += "1111";
	}

	return str;
}

/* :::::::::::::::::::::::: --------------------- ::::::::::::::::::::::::*/

/* This Function is used to give Initial Permutation for Key */
template <typename T>
T initKeyPermutation(T key) { //one time function call

	T tempStr1 = convertIntoHexadecimal(key);
	const int IP1_table_size = 56;
	int IP1_table[IP1_table_size] = { 57,49,41,33,25,17,9,1,58,50,42,34,26,18,10,2,59,51,43,35,27,19,11,3,60,52,44,36,63,55,47,39,31,23,15,7,62,54,46,38,30,22,14,6,61,53,45,37,29,21,13,5,28,20,12,4 };
	char tempStr2[IP1_table_size];
	T tempStr3 = "\0";

	for (int i = 0; i < IP1_table_size; i++) {
		tempStr2[i] = tempStr1[IP1_table[i] - 1];
	}

	for (int i = 0; i < IP1_table_size; i++) {
		tempStr3 += tempStr2[i];
	}
	return tempStr3;
}

/* :::::::::::::::::::::::: --------------------- ::::::::::::::::::::::::*/

/* This Function is for Half Circular Shift for key values. It takes string and number to shift values */
template <typename T>
T halfCircularShift(T half_key, int index) {
	int size = stringLength(half_key) - index;
	char* temp = new char[index];
	char* temp2 = new char[size];

	T tempStr = "\0";

	for (int i = 0; i < index; i++)
		temp[i] = half_key[i];

	for (int i = index - 1, j = 0; j < size; i++, j++)
		temp2[j] = half_key[i + 1];

	for (int i = 0, j = 0; i < stringLength(half_key); i++) {
		if (i < size)
			tempStr += temp2[i];
		else {
			tempStr += temp[j];
			j++;
		}
	}

	return tempStr;
}

/* :::::::::::::::::::::::: --------------------- ::::::::::::::::::::::::*/

/* This Function is for Second Permutation */
template <typename T>
T roundPermutation(T key) { //56 to 48 bit conversion
	const int PC2_table_size = 48;
	int PC2_table[PC2_table_size] = { 14,17,11,24,1,5,3,28,15,6,21,10,23,19,12,4,26,8,16,7,27,20,13,2,41,52,31,37,47,55,30,40,51,45,33,48,44,49,39,56,34,53,46,42,50,36,29,32 };
	char* tempStr1 = new char[PC2_table_size];
	T tempStr2 = "\0";

	for (int i = 0; i < PC2_table_size; i++)
		tempStr1[i] = key[PC2_table[i] - 1];

	for (int i = 0; i < PC2_table_size; i++)
		tempStr2 += tempStr1[i];

	return tempStr2;
}

/* :::::::::::::::::::::::: --------------------- ::::::::::::::::::::::::*/

/* This Function is for Initial permutation of text */
template <typename T>
T initTextPermutation(T text) {
	text = convertIntoHexadecimal(text);
	T tempStr = "\0";
	const int IP_table_size = 64;
	int IP_table[IP_table_size] = { 58,50,42,34,26,18,10,2,60,52,44,36,28,20,12,4,62,54,46,38,30,22,14,6,64,56,48,40,32,24,16,8,57,49,41,33,25,17,9,1,59,51,43,35,27,19,11,3,61,53,45,37,29,21,13,5,63,55,47,39,31,23,15,7 };
	char* tempStr1 = new char[IP_table_size];

	for (int i = 0; i < IP_table_size; i++)
		tempStr1[i] = text[IP_table[i] - 1];

	for (int i = 0; i < IP_table_size; i++)
		tempStr += tempStr1[i];

	return tempStr;
}

/* :::::::::::::::::::::::: --------------------- ::::::::::::::::::::::::*/

/* This Function is for the expansion of given text */
template <typename T>
T expandHalfText(T rightHalfText) {
	T tempStr = "\0";
	const int expansionTableSize = 48;
	int ExpansionTable[expansionTableSize] = { 32,1,2,3,4,5,4,5,6,7,8,9,8,9,10,11,12,13,12,13,14,15,16,17,16,17,18,19,20,21,20,21,22,23,24,25,24,25,26,27,28,29,28,29,30,31,32,1 };
	char* tempStr2 = new char[expansionTableSize];

	for (int i = 0; i < expansionTableSize; i++)
		tempStr2[i] = rightHalfText[ExpansionTable[i] - 1];

	for (int i = 0; i < expansionTableSize; i++)
		tempStr += tempStr2[i];

	return tempStr;
}

/* :::::::::::::::::::::::: --------------------- ::::::::::::::::::::::::*/

/* This Function will XOR the expanded value with Left half text */
template <typename T>
T XOR(T text, T key) {
	const int size = stringLength(text);
	T tempStr = "\0";
	char* tempStr2 = new char[size];

	for (int i = 0; i < size; i++) {
		if (text[i] == key[i])
			tempStr2[i] = '0';
		else
			tempStr2[i] = '1';
	}

	for (int i = 0; i < size; i++)
		tempStr += tempStr2[i];

	return tempStr;
}

/* :::::::::::::::::::::::: --------------------- ::::::::::::::::::::::::*/

/* This Function find string with the help of 8 boxes */
template <typename T>
T calcSBox(T text) {
	T str = "";
	T temp;
	const int div1 = 8;
	const int div2 = 6;
	T Subtext[div1][div2];
	T textparts[8];
	int rowNumber;
	int colNumber;


	for (int i = 0, j = 0; i < div1; i++) {
		for (int k = 0; k < div2; k++) {
			Subtext[i][k] = text[j];
			j++;
		}
	}


	for (int i = 0, j = 0; i < div1; i++) {
		for (int k = 0; k < div2; k++)
			cout << Subtext[i][k] << "\t";
	}
	const int rowSize = 4;
	const int colsSize = 16;

	int S_BOX_1[rowSize][colsSize] = { {14,4,13,1,2,15,11,8,3,10,6,12,5,9,0,7}, {0,15,7,4,14,2,13,1,10,6,12,11,9,5,3,8}, {4,1,14,8,13,6,2,11,15,12,9,7,3,10,5,0}, {15,12,8,2,4,9,1,7,5,11,3,14,10,0,6,13} };

	int S_BOX_2[rowSize][colsSize] = { {15,1,8,14,6,11,3,4,9,7,2,13,12,0,5,10}, {3,13,4,7,15,2,8,14,12,0,1,10,6,9,11,5}, {0,14,7,11,10,4,13,1,5,8,12,6,9,3,2,15},{13,8,10,1,3,15,4,2,11,6,7,12,0,5,14,9} };

	int S_BOX_3[rowSize][colsSize] = { {10,0,9,14,6,3,15,5,1,13,12,7,11,4,2,8}, {13,7,0,9,3,4,6,10,2,8,5,14,12,11,15,1}, {13,6,4,9,8,15,3,0,11,1,2,12,5,10,14,7}, {1,10,13,0,6,9,8,7,4,15,14,3,11,5,2,12} };

	int S_BOX_4[rowSize][colsSize] = { {7,13,14,3,0,6,9,10,1,2,8,5,11,12,4,15}, {13,8,11,5,6,15,0,3,4,7,2,12,1,10,14,9}, {10,6,9,0,12,11,7,13,15,1,3,14,5,2,8,4}, {3,15,0,6,10,1,13,8,9,4,5,11,12,7,2,14} };


	int S_BOX_5[rowSize][colsSize] = { {2,12,4,1,7,10,11,6,8,5,3,15,13,0,14,9}, {14,11,2,12,4,7,13,1,5,0,15,10,3,9,8,6}, {4,2,1,11,10,13,7,8,15,9,12,5,6,3,0,14}, {11,8,12,7,1,14,2,13,6,15,0,9,10,4,5,3} };

	int S_BOX_6[rowSize][colsSize] = { {12,1,10,15,9,2,6,8,0,13,3,4,14,7,5,11}, {10,15,4,2,7,12,9,5,6,1,13,14,0,11,3,8}, {9,14,15,5,2,8,12,3,7,0,4,10,1,13,11,6}, {4,3,2,12,9,5,15,10,11,14,1,7,6,0,8,13} };

	int S_BOX_7[rowSize][colsSize] = { {4,11,2,14,15,0,8,13,3,12,9,7,5,10,6,1}, {13,0,11,7,4,9,1,10,14,3,5,12,2,15,8,6}, {1,4,11,13,12,3,7,14,10,15,6,8,0,5,9,2}, {6,11,13,8,1,4,10,7,9,5,0,15,14,2,3,12} };

	int S_BOX_8[rowSize][colsSize] = { {13,2,8,4,6,15,11,1,10,9,3,14,5,0,12,7}, {1,15,13,8,10,3,7,4,12,5,6,11,0,14,9,2}, {7,11,4,1,9,12,14,2,0,6,10,13,15,3,5,8}, {2,1,14,7,4,10,8,13,15,12,9,0,3,5,6,11} };

	for (int i = 0; i < 8; i++) {
		rowNumber = toDecimal(Subtext[i][0] + Subtext[i][5]);
		colNumber = toDecimal(Subtext[i][1] + Subtext[i][2] + Subtext[i][3] + Subtext[i][4]);

		if (i == 0) {
			temp = toBinary<T>(S_BOX_1[rowNumber][colNumber]);
			textparts[0] = toBinary2(temp);
		}

		else if (i == 1) {
			temp = toBinary<T>(S_BOX_2[rowNumber][colNumber]);
			textparts[1] = toBinary2(temp);
		}

		else if (i == 2) {
			temp = toBinary<T>(S_BOX_3[rowNumber][colNumber]);
			textparts[2] = toBinary2(temp);
		}

		else if (i == 3) {
			temp = toBinary<T>(S_BOX_4[rowNumber][colNumber]);
			textparts[3] = toBinary2(temp);
		}

		else if (i == 4) {
			temp = toBinary<T>(S_BOX_5[rowNumber][colNumber]);
			textparts[4] = toBinary2(temp);
		}

		else if (i == 5) {
			temp = toBinary<T>(S_BOX_6[rowNumber][colNumber]);
			textparts[5] = toBinary2(temp);
		}

		else if (i == 6) {
			temp = toBinary<T>(S_BOX_7[rowNumber][colNumber]);
			textparts[6] = toBinary2(temp);
		}

		else if (i == 7) {
			temp = toBinary<T>(S_BOX_8[rowNumber][colNumber]);
			textparts[7] = toBinary2(temp);
		}

	}

	for (int i = 0; i < 8; i++) {
		str += textparts[i];
	}

	return str;
}

/* :::::::::::::::::::::::: --------------------- ::::::::::::::::::::::::*/

/* This Function finds Inverse Permutation of the given string */
string InversePermutation(string key) {
	cout << key << endl;
	string str = "";
	string str2 = "";
	const int IP_table_size = 64;
	int IP_table[IP_table_size] = { 40,8,48,16,56,24,64,32,39,7,47,15,55,23,63,31,38,6,46,14,54,22,62,30,37,5,45,13,53,21,61,29,36,4,44,12,52,20,60,28,35,3,43,11,51, 19, 59, 27,34,2,42,10,50,18,58,26,33 , 1 ,41,9,49,17,57, 25 };

	for (int i = 0; i < IP_table_size; i++) {
		str[i] = key[IP_table[i] - 1];
	}

	for (int i = 0; i < IP_table_size; i++)
		str2 += str[i];

	return str2;
}

/* :::::::::::::::::::::::: --------------------- ::::::::::::::::::::::::*/