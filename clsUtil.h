#pragma once
#include <iostream>
#include <string>
#include "clsDate.h"

using namespace std;

class clsUtil {

public:
    enum enCharType {
        SmallLetter = 1, CapitalLetter = 2,
        Digit = 3, MixChars = 4, SpecialCharacter = 5
    };

    static void sRand() {
        //Seeds the random number generator in C++, called only once
        srand((unsigned)time(NULL));
    }

    static int randomNumber(int from, int to) {
        //Function to generate a random number
        int randNum = rand() % (to - from + 1) + from;
        return randNum;
    }

    static char getRandomCharacter(enCharType charType) {

        //updated this method to accept mixchars
        if (charType == MixChars) {
            //Capital/Samll/Digits only
            charType = (enCharType)randomNumber(1, 3);
        }

        switch (charType) {

        case enCharType::SmallLetter: {
            return char(randomNumber(97, 122));
            break;
        }

        case enCharType::CapitalLetter: {
            return char(randomNumber(65, 90));
            break;
        }

        case enCharType::SpecialCharacter: {
            return char(randomNumber(33, 47));
            break;
        }

        case enCharType::Digit: {
            return char(randomNumber(48, 57));
            break;
        }

        default: {
            return char(randomNumber(65, 90));
            break;
        }
        }
    }

    static string generateWord(enCharType charType, short length) {

        string word;

        for (int i = 1; i <= length; i++) {
            word = word + getRandomCharacter(charType);
        }

        return word;
    }

    static string generateKey(enCharType charType = CapitalLetter) {

        string key = "";

        key = generateWord(charType, 4) + "-";
        key = key + generateWord(charType, 4) + "-";
        key = key + generateWord(charType, 4) + "-";
        key = key + generateWord(charType, 4);

        return key;
    }

    static void generateKeys(short numberOfKeys, enCharType charType) {

        for (int i = 1; i < numberOfKeys; i++) {
            cout << "Key [" << i << "] : ";
            cout << generateKey(charType) << endl;
        }
    }

    static void fillArrayWithRandomNumbers(int arr[100], int arrLength, int From, int To) {
        for (int i = 0; i < arrLength; i++)
            arr[i] = randomNumber(From, To);
    }

    static void fillArrayWithRandomWords(string arr[100], int arrLength, enCharType CharType, short Wordlength) {
        for (int i = 0; i < arrLength; i++)
            arr[i] = generateWord(CharType, Wordlength);

    }

    static void fillArrayWithRandomKeys(string arr[100], int arrLength, enCharType CharType) {
        for (int i = 0; i < arrLength; i++)
            arr[i] = generateKey(CharType);
    }

    static  void swap(int& A, int& B) {
        int temp;

        temp = A;
        A = B;
        B = temp;
    }

    static void swap(double& A, double& B) {
        double temp;

        temp = A;
        A = B;
        B = temp;
    }

    static void swap(bool& A, bool& B) {
        bool temp;

        temp = A;
        A = B;
        B = temp;
    }

    static void swap(char& A, char& B) {
        char temp;

        temp = A;
        A = B;
        B = temp;
    }

    static void swap(string& A, string& B) {
        string temp;

        temp = A;
        A = B;
        B = temp;
    }

    static void swap(clsDate& A, clsDate& B) {
        clsDate::swapDates(A, B);
    }

    static void shuffleArray(int arr[100], int arrLength) {

        for (int i = 0; i < arrLength; i++) {
            swap(arr[randomNumber(1, arrLength) - 1], arr[randomNumber(1, arrLength) - 1]);
        }
    }

    static void shuffleArray(string arr[100], int arrLength) {

        for (int i = 0; i < arrLength; i++) {
            swap(arr[randomNumber(1, arrLength) - 1], arr[randomNumber(1, arrLength) - 1]);
        }
    }

    static string  tabs(short NumberOfTabs) {
        string t = "";

        for (int i = 1; i < NumberOfTabs; i++) {
            t = t + "\t";
            cout << t;
        }
        return t;
    }

    static string encryptText(string text, short encryptionKey) {

        for (int i = 0; i <= text.length(); i++) {
            text[i] = char((int)text[i] + encryptionKey);
        }
        return text;
    }

    static string decryptText(string text, short encryptionKey) {

        for (int i = 0; i <= text.length(); i++) {
            text[i] = char((int)text[i] - encryptionKey);
        }
        return text;
    }

    static string numberToText(int number) {

        if (number == 0) {
            return "";
        }

        if (number >= 1 && number <= 19) {
            string arr[] = { "", "One","Two","Three","Four","Five","Six","Seven",
        "Eight","Nine","Ten","Eleven","Twelve","Thirteen","Fourteen",
          "Fifteen","Sixteen","Seventeen","Eighteen","Nineteen" };

            return  arr[number] + " ";
        }

        if (number >= 20 && number <= 99) {
            string arr[] = { "","","Twenty","Thirty","Forty","Fifty","Sixty","Seventy","Eighty","Ninety" };
            return  arr[number / 10] + " " + numberToText(number % 10);
        }

        if (number >= 100 && number <= 199) {
            return  "One Hundred " + numberToText(number % 100);
        }

        if (number >= 200 && number <= 999) {
            return   numberToText(number / 100) + "Hundreds " + numberToText(number % 100);
        }

        if (number >= 1000 && number <= 1999) {
            return  "One Thousand " + numberToText(number % 1000);
        }

        if (number >= 2000 && number <= 999999) {
            return   numberToText(number / 1000) + "Thousands " + numberToText(number % 1000);
        }

        if (number >= 1000000 && number <= 1999999) {
            return  "One Million " + numberToText(number % 1000000);
        }

        if (number >= 2000000 && number <= 999999999) {
            return   numberToText(number / 1000000) + "Millions " + numberToText(number % 1000000);
        }

        if (number >= 1000000000 && number <= 1999999999) {
            return  "One Billion " + numberToText(number % 1000000000);
        }
        else {
            return   numberToText(number / 1000000000) + "Billions " + numberToText(number % 1000000000);
        }
    }
};