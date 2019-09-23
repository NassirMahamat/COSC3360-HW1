//
//  main.cpp
//  CompXC2.0
//
//  Created by Hasan Qureshi on 9/15/19.
//  Copyright © 2019 Hasan Qureshi. All rights reserved.
//

#include <iostream>
#include <cstring>
#include <fstream>
#include <vector>
#include <unistd.h>

using namespace std;

struct Encrypt{
    char letter;
    string cMess;
};
vector<char> nString;//str in vector form
vector<char> nString2;//str temporary

struct Data{
    char letter;
    int frequency = 0;
};
vector<Data> vData;//sorted already

// parent process
void bubbleSort(vector<Data> &vData) // sort vector
{
    for(int i = 1; i < vData.size(); i++)
    {
        for(int j = 0; j < vData.size()-i; j++)
        {
            if(vData.at(j).frequency < vData.at(j+1).frequency)
            {
                Data temp = vData.at(j);
                vData.at(j) = vData.at(j+1);
                vData.at(j+1) = temp;
            }
        }
    }
    for(int i=0 ;i<26;i++){
        if(vData[i].frequency>0){
           // vData.push_back(vData[i]);//
        }
    }
}

int main(){
    
    string str;
    str="ZZZZZJFFJJKFSEJ";//nString
    //find a way to read from a standard input
    Data data[26];
    Encrypt ENCRYPTION[100];
    data[0].letter = 'A';
    data[1].letter = 'B';
    data[2].letter = 'C';
    data[3].letter = 'D';
    data[4].letter = 'E';
    data[5].letter = 'F';
    data[6].letter = 'G';
    data[7].letter = 'H';
    data[8].letter = 'I';
    data[9].letter = 'J';
    data[10].letter = 'K';
    data[11].letter = 'L';
    data[12].letter = 'M';
    data[13].letter = 'N';
    data[14].letter = 'O';
    data[15].letter = 'P';
    data[16].letter = 'Q';
    data[17].letter = 'R';
    data[18].letter = 'S';
    data[19].letter = 'T';
    data[20].letter = 'U';
    data[21].letter = 'V';
    data[22].letter = 'W';
    data[23].letter = 'X';
    data[24].letter = 'Y';
    data[25].letter = 'Z';

    for(int i = 0; i < str.size(); i++)
    {
        nString.push_back(str[i]);
        if (str[i] == 'A')
        {
            data[0].frequency++;
        }
        else if (str[i] == 'B')
        {
            data[1].frequency++;
        }
        else if (str[i] == 'C')
        {
            data[2].frequency++;
        }
        else if (str[i] == 'D')
        {
            data[3].frequency++;
        }
        else if (str[i] == 'E')
        {
            data[4].frequency++;
        }
        else if (str[i] == 'F')
        {
            data[5].frequency++;
        }
        else if (str[i] == 'G')
        {
            data[6].frequency++;
        }
        else if (str[i] == 'H')
        {
            data[7].frequency++;
        }
        else if (str[i] == 'I')
        {
            data[8].frequency++;
        }
        else if (str[i] == 'J')
        {
            data[9].frequency++;
        }
        else if (str[i] == 'K')
        {
            data[10].frequency++;
        }
        else if (str[i] == 'L')
        {
            data[11].frequency++;
        }
        else if (str[i] == 'M')
        {
            data[12].frequency++;
        }
        else if (str[i] == 'N')
        {
            data[13].frequency++;
        }
        else if (str[i] == 'O')
        {
            data[14].frequency++;
        }
        else if (str[i] == 'P')
        {
            data[15].frequency++;
        }
        else if (str[i] == 'Q')
        {
            data[16].frequency++;
        }
        else if (str[i] == 'R')
        {
            data[17].frequency++;
        }
        else if (str[i] == 'S')
        {
            data[18].frequency++;
        }
        else if (str[i] == 'T')
        {
            data[19].frequency++;
        }
        else if (str[i] == 'U')
        {
            data[20].frequency++;
        }
        else if (str[i] == 'V')
        {
            data[21].frequency++;
        }
        else if (str[i] == 'W')
        {
            data[22].frequency++;
        }
        else if (str[i] == 'X')
        {
            data[23].frequency++;
        }
        else if (str[i] == 'Y')
        {
            data[24].frequency++;
        }
        else if (str[i] == 'Z')
        {
            data[25].frequency++;
        }
    }
    
    for(int i=0;i<26;i++){
        if(data[i].frequency>0){
        cout<<"The frequency of "<<data[i].letter<<" is "<<data[i].frequency<<endl;
        vData.push_back(data[i]);
        }
    }
    cout<<endl;
    
    for(int i; i<vData.size();i++){
        cout<<vData[i].letter<<" "<<vData[i].frequency<<endl;
    }
    
    bubbleSort(vData);
    
    for(int i;i<vData.size();i++){
        cout<<"The frequency of "<<vData[i].letter<<" is "<<vData[i].frequency<<endl;
        }
    cout<<endl;
    
    for(int i; i <nString.size();i++){
            cout<<nString[i];
        }
        cout<<endl;
    
    for(int i = 0; i < vData.size(); i++)//step 4 comparison
    {
        ENCRYPTION[i].letter = vData[i].letter;
            for(int j = 0; j < nString.size(); i++)
            {
                if(nString[i] == vData[i].letter)
                {
                    ENCRYPTION[i].cMess +='1';
                }
                else
                {
                    ENCRYPTION[i].cMess +='0';
                }
                
            //child process.
                for(int k=0; k<nString.size(); k++){
                    if(nString[k]!=vData[k].letter){
                        nString2.push_back(nString[k]);//add to nString2
                }
                    nString.clear();//delete nString contents
                    
                for(int j=0;j<nString2.size();j++){
                        nString.push_back(nString2[j]);//push back into nString
                    }
                    nString2.clear();//clear nString2
                    cout<<nString[k]<<" ";
                }
            }
        
    }
  

    return 0;
    
}
