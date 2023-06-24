
#include <iostream>
#include <cstring>
 
using namespace std;
int main(){
    int i, j;
    char str[100];
    
    cout << "Please enter a string: \t";
    cin >> str;
    
    cout << "Please choose 1 of the following: \n";
    cout << "1) I want to encrypt the string. \n";
    cout << "2) I want to decrypt the string. \n";
    cin >> j;
    
    //case statements 1)for encryption and 2) decryption
    switch(j){
        case 1:
            for(i=0; i < strlen(str); i++){
                str[i] = str[i] + 2; 
            }
                //encryption is 3 that's added to ASCII
                //adding 2 to each character's ASCII value, the characters in the string 
                //are shifted two positions to the right in the ASCII table. 
                //This process is known as a simple substitution cipher.
                 cout << "The resulting encrypted string is: " << str << endl;
                 break;
                 
        case 2:
            for(i=0; i < strlen(str); i++){
                str[i] = str[i] - 2;
            }
                //now shifts back by 2 to the original position in the ASCII table
                cout << "The resulting decrypts string is: " << str << endl;
                break;
                
                default:
                //default case
                cout << "Invalid Input! \n";
            }
            return 0;
        }
