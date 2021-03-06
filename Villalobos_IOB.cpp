//Name:Thalia Villalobos 
//22 Oct 2015
//Write a program that will utilize a text input file (scores.txt) and compute the listed specifications. The text input file "scores.txt" is provided. Write a program to compute numeric grades for a course. The course records are a file that will serve as the input file. The input file format is specified "scores.txt". 

#include<iostream> //cin, cout
#include<fstream>  //fin, fout
#include<string>   //string
#include<cstdlib>  //exit()
#include<iomanip>  //(ios::fixed)
using namespace std;

int main()
{
    ifstream fin; 
    ofstream fout;
    
    char file_name [12];
    double max= 0;
    string firstName, lastName, highestFirstName, hightestLastName;
    double s1,s2,s3,s4,s5,s6, average, userAverage;
    
    cout << "Enter file_name:" << endl;
    cin >> file_name;
   
   //Open files
    fin.open(file_name);
    fout.open("results.txt");
    
   //Check if there is an error when both file fail to open
    if (fin.fail())
        {
           cout << "Error opening input file" << endl;
           exit(1);
        }  
    if (fout.fail())
        {
           cout << "Error opening input file" << endl;
           exit(1);
        }      
   
   //Loop
    while(fin >> firstName >> lastName >> s1 >> s2 >> s3 >> s4 >> s5 >> s6)
    {
        fout.setf(ios::fixed);
        fout.setf(ios::showpoint);
        fout.precision(1);
        fout.setf(ios::left);
        
        average = (s1+s2+s3+s4+s5) / 5;
        
        if (average >= max)
        {
            highestFirstName = firstName;
            hightestLastName = lastName;
            max = average;
        }
        else 
        {
            max = max;
        }
       
       //Output to results.txt
        fout << setw(12) << firstName << setw(12) << lastName << setw(6)
             << s1 << setw(6) << s2 << setw(6) << s3 << setw(6) 
             << s4 << setw(6) << s5;
             
        fout.precision(2);
             
        fout << setw(8) << average << setw(8) <<endl;     
    } //endl of loop
    
        fout << "\nHighest score: " << setw(8) << highestFirstName << setw(10)
             << hightestLastName << endl; 
    
    fin.close();
    fout.close();
    return 0;
}
