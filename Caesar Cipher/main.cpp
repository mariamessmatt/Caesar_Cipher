
// FCAI-CU  Structured Programming  2022
//Program Name : Caesar Cipher
// Program Description : this program encrypts and dycrypts Caesar Cipher with a key that the user chooses according to caeser cipher
// Author : Mariam Esmat Ahamed   Group: A
// ver2 of Date : 24th March 2022
// section : s9,10

#include <algorithm>
#include <iostream>
#include <string>
using namespace std;

//makes sure tha the chosen opertion is an intger number
void check_operation(string& number)
{
    //takes the chosen opertaion as a string
    string chosen_opperation;
    //loops through that string
    for (int i = 0; i < number.length(); i++)
    {
        //if i is a digit it is appeanded
        if (isdigit(number[i]))
        {
            chosen_opperation.push_back(number[i]);
        }
    }
    //lenght of the string is not the same anymore it means that it icnulded a letter
    if (chosen_opperation.length() != number.length())
    {
        //ask the user to enter a new chioce
        cout << "Invalid input, please try again: ";
        cin >> number;
        cin.ignore();
        //re-apply the same function
        check_operation(number);
    }
}

//modifies the entered key
int shift()
{
    int key;
    cout << "Please, enter an interger key: " << endl;
    cin >> key;
    while (cin.fail())
    {
        cout << "Wrong key , Please try again:  ";
        cin.ignore();
        cin.clear();
        cin.sync();
        cin >> key;

    }

    // gets the mod of the entered key to handle numbers greater than 26 and numbers less than 0
    key = (key % 26 + 26) % 26;

    return key;
}

int main()
{

    cout << "\nHello user, this program can encrypt and decrypt a text according to Caesar Cipher  " << endl;
    // to keep the code running as long as the user did not choose to exit
    bool exit = false;
    while (exit == false)
    {
        cout << "\nPlease decide if you want to encrypt OR decrypt a text " << endl;
        cout << "1. Encryption " << "\n" << "2. Decryption" << "\n" << "3. Exit" << " " << endl;
        cout << "The chosen operation: ";
        string chosen_opperation;
        cin >> chosen_opperation;
        cin.ignore();
        cout << "\n";
        check_operation(chosen_opperation);
        int choice = stoi(chosen_opperation);


        if (choice == 1 || choice == 2 || choice == 3)
        {
            //encryption
            if (choice == 1)
            {
                int encrypt_key;
                encrypt_key = shift();
                cin.ignore();

                cout << "Enter the text you want to encrypt: " << endl;
                string plain_text;
                getline(cin, plain_text);
                transform(plain_text.begin(), plain_text.end(), plain_text.begin(), ::tolower);

                //loops through each letter of the string
                for (int i = 0; i < plain_text.length(); i++)
                {
                    //check if the enterd symbol is  a letter
                    if (isalpha(plain_text[i]))
                    {

                        //if after addition the letter gets out of the lower case range
                        if ((plain_text[i]) + encrypt_key > 122)
                        {
                            //moving back to the range of lower case letters
                            (plain_text[i]) = (plain_text[i]) + encrypt_key - 26 ;

                        }
                        else
                        {
                            plain_text[i] += encrypt_key;
                        }
                    }
                    // if the input was anything that's not a letter it is printed as it is
                    else
                        cout << plain_text[i];
                }

                cout << "Encrypted Message: " << plain_text ;
                cout << "\n";
            }

            //decryption
            if (choice == 2)
            {
                int dcrypt_key;
                dcrypt_key = shift();
                cin.ignore();

                cout << "Enter the text you want to decrypt: " << endl;
                string encrypted_text;
                getline(cin, encrypted_text);
                transform(encrypted_text.begin(), encrypted_text.end(), encrypted_text.begin(), ::tolower);

                //loops through each letter of the string
                for (int i = 0; i < encrypted_text.length(); i++)
                {
                    //check if the enterd symbol is  a letter
                    if (isalpha(encrypted_text[i]))
                    {
                        //if after subtraction the letter get out of the lower case range
                        if ((encrypted_text[i]) - dcrypt_key < 97 )
                        {
                            //moving back to the range of lower case letters
                            (encrypted_text[i]) = (encrypted_text[i] - dcrypt_key) + 26 ;

                        }
                        else
                        {
                            (encrypted_text[i]) = (encrypted_text[i]) - dcrypt_key;
                        }
                    }
                    // if the input was anything that's not a letter it is printed as it is
                    else
                        cout << encrypted_text[i];
                }
                //prints out the messamge after applying the changes
                cout << "Decrypted Message: " << encrypted_text ;
                cout << "\n";
            }
            //stops the loop on entering 3
            if (choice == 3)
            {
                cout << "Thank you for using my program :)\n";
                exit = true;
                break;
            }
        }
        //gets the user back to choose the operation if he enters a wrong input
        else
        {
            cout << "Sorry, your input is invalid. Please try again ! " << endl;
            main();
            cout << "\n";
        }
    }
    return 0;
}









