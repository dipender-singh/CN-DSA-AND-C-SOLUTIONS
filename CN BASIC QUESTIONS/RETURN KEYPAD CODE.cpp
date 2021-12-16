/*Return Keypad Code
Send Feedback
Given an integer n, using phone keypad find out all the possible strings that can be made using digits of input n.
Return empty string for numbers 0 and 1.
Note : 1. The order of strings are not important.
2. Input and output has already been managed for you. You just have to populate the output array and return the count of elements populated in the output array.
Input Format :
Integer n
Output Format :
All possible strings in different lines
Constraints :
1 <= n <= 10^6
Sample Input:
23
Sample Output:
ad
ae
af
bd
be
bf
cd
ce
cf
*/
#include <string>
using namespace std;
string getPossibleCharsForKeypad(int num){
    if(num==2){
        return "abc";
    }
    if(num==3){
        return "def";
    }
    if(num==4){
        return "ghi";
    }
    if(num==5){
        return "jkl";
    }
    if(num==6){
        return "mno";
    }
    if(num==7){
        return "pqrs";
    }
    if(num==8){
        return "tuv";
    }
    if(num==9){
        return "wxyz";
    }
    else{
        return "";
    }
}

int keypad(int num,string output[]){
    if(num==0){
        output[0]="";
        return 1;
    }
    int smalloutputsize=keypad((num/10),output);
    string firstDigitPossibleChars=getPossibleCharsForKeypad(num%10);
    
    for(int i=0;i<firstDigitPossibleChars.length();i++){
        for(int j=0;j<smalloutputsize;j++){
            output[(i+1)*smalloutputsize+j]=output[j];
        }
    }
    int k=0;
    for(int i=0;i<firstDigitPossibleChars.length();i++){
        for(int j=0;j<smalloutputsize;j++){
            output[k]=output[k]+firstDigitPossibleChars[i];
            k++;
        }
    }
    return k;
}
