#include <iostream>
#include<stdio.h>
#include<fstream>
#include<conio.h>
#include<strings.h>
struct dictionary
{
    char worda[50];
    char meaninga[50];
}s1;
int main()
{char word[50],meaning[50],choice;
    while(true)
    {
        std::cout<<"Pls Enter the Word\n";
        std::cin.getline(word,50);
        std::cout<<"Pls Enter the Meaning\n";
        std::cin.getline(meaning,50);
        std::ifstream fin;
        std::ofstream fout;
        fin.open("Dictionary.txt",std::ios::in|std::ios::out|std::ios::app|std::ios::binary);
        fout.open("Dictionary.txt",std::ios::in|std::ios::out|std::ios::app|std::ios::binary);
        fin.read((char*)&s1,sizeof(s1));
        if ((strcasecmp(s1.worda,word)==0)) {
            std::cout<<"WORD ALREADY EXISTS\n";
            std::cout<<"And the meaning of that word is \n";
            std::cout<<s1.meaninga<<"\n";
        }
        else if(strcasecmp(s1.meaninga,word)==0)
        {
            std::cout<<"WORD ALREADY EXISTS\n";
            std::cout<<"And the meaning of that word is \n";
            std::cout<<s1.worda<<"\n";
        }
        else {
            fout.write((char*)&word,sizeof(word));
            fout.write((char*)&meaning,sizeof(meaning));
            fout<<"\n";
        }
        std::cout<<"DO YOU WANT TO ENTER MORE WORDS\n";
        std::cin>>choice;
        if((choice=='y')||(choice=='Y'))
            continue;
        else
            break;
    }
    return 0;
}

