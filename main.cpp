#include <iostream>
#include <fstream>
#include <vector>
#include <windows.h>
#include <winuser.h>



using namespace std;

ifstream file;
//the file to be read
string fileName;
//name and directory of the file
vector<string> output;
//a vector of words taken from the read file

bool endsWith(string in){
    //check if the inputted file ends with a valid txt extention
    string out = in.substr(in.size() - 4);

    if(out == ".txt")// || out == ".pdf")  soon
        return true;
    else
        return false;

}

void flushOut(string in){
    //clear the currently displayed word by backspacing all the way and then printing spaces out,
    //then backspacing into the nuetral position to be ready to display the next word
    int temp = in.size();
    for(int i = 0; i<temp; i++)
        cout<<"\b";
    for(int i = 0; i<temp; i++)
        cout<<" ";
    for(int i = 0; i<temp; i++)
        cout<<"\b";
    return;

}

void getTXT(){
    //simple function that grabs each word and puts them into a vector, in order

    string temp = "";
    while(file >> temp){
        output.push_back(temp);

    }
    file.close();
    return;

}



int main()
{

    bool isValid = true;
    do{


    isValid = true;
    cout << "Input txt file location: ";

    getline(cin, fileName);

    if(fileName.size()<=4)
        isValid = false;
        //if size is too small, do error

    isValid = endsWith(fileName);
    //check if file name is valid

    if(isValid == false)
        cout<<"ERROR: file not supported\n";

    }while(isValid == false);

    cout<<"File accepted\nParsing the file...\n";
    file.open(fileName, ios::in);
    //open the file
    cout<<"Opened file...\n";
    getTXT();
    //get the words of the file
    cout<<"\n\nReady! Hold down your shift key to print.\n\n\n\t\t\t";

    for(int i = 0; i< output.size(); ){

        if(GetKeyState(VK_SHIFT) & 0x8000)
            //if the shift key is held down, cycle through the words
        {
        cout << output.at(i);
        //print word located at i

        int extra = 0;
        char last = output.at(i).c_str()[output.at(i).size()-1];
        if(last == '.' || last == ','||last == '?'||last == '!' || last == ';' || last == ':')
            extra = 100;
            //if the word ends with a punctuation mark, give a bit extra stopping time for the reader

        Sleep(100 +  output.at(i).size()*10 + extra);
        //wait an extra longer time for longer words as well as punctuated words
        flushOut(output.at(i));
        //clear out the display

        i++;
        //add 1 to the wordlist
        }
        cout << output.at(i);
        flushOut(output.at(i));
        //if shift is not held, then just constantly show the current word
        //(probably a better way to do this)

    }






    return 0;
}
