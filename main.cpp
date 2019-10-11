//
//  main.cpp
//  HW5.0
//
//  Created by Hasan Qureshi on 9/23/19.
//  Copyright © 2019 Hasan Qureshi. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <vector>
#include <unistd.h>
#include <string>
#include <cstring>
#include <sys/types.h>
#include <sys/wait.h>
#include <fstream>


using namespace std;

struct freq{
    char letter='\0';
    int frequency = 0;
};

struct huffman{
    string que,huff;
};


string mapH(string huff1,char toBeMapped);
string reduction(string huff1, string outMap);
string getInput();

int main(int argc,char *argv[]){
    //cout<<argv[1]<<endl;
    //string str= "NOW IS THE WINTER OF OUR DISCONTENT"
    cout<<"Begin execution"<<endl;
    string str="";
    
    //getline(cin,str);
    str=getInput();

        
    char Cstr[str.length()+1];
    strcpy(Cstr,str.c_str());
    cout<<endl;
    
    freq freq1[str.length()+1];
    //freq swapHolder;
    huffman encode[str.length()+1];
    
    for(int i=0; i<str.length();i++){
       // cout<<Cstr[i];
    }
    cout<<endl;
        
    for(int i=0;i<str.length();i++){
        for(int j=0;sizeof(freq1);j++){
            if(freq1[j].letter=='\0'){
                freq1[j].letter=Cstr[i];
                freq1[j].frequency++;
               // cout<<"found ";
                //cout<<Cstr[i]<<endl;
                break;
            }
            else if(Cstr[i]==freq1[j].letter){
                freq1[j].frequency++;
                break;
            }
        }
    }//DICTIONARY
 
    int zz=0;
    for(int z=0;z<str.length();z++){
        if(freq1[z].letter=='\0'){
            break;
        }
        //cout<<z+1<<" - "<<freq1[z].letter<<" - "<<freq1[z].frequency<<endl;
        zz=z+1;
    }
  
   for(int i=0;i< zz-1;i++)
   {
       for(int j=0; j < str.size(); j++)
       {
           if(freq1[j].frequency < freq1[j+1].frequency)
           {
               freq swapHolder = {freq1[j].letter,freq1[j].frequency};
               freq1[j] ={freq1[j+1].letter,freq1[j+1].frequency};
               freq1[j+1]={swapHolder.letter,swapHolder.frequency};
           }
       }
   }
    for(int z=0;z < freq1[z].letter; z++){
       cout<<freq1[z].letter<<" frequency is "<<freq1[z].frequency<<endl;
   }
    
    encode[0].que={str};
    encode[0].huff={mapH(encode[0].que, freq1[0].letter)};
    //cout<<"child process 2 is doing task 2"<<getpid()<<endl;
    cout<<endl;
    wait(0);
    //cout<<encode[0].huff<<endl;//created a new huff from key letter
    
    for(int t=1;t<zz;t++){
        encode[t].que={reduction(encode[t-1].que,encode[t-1].huff)};
        //cout<<encode[t-1].que<<endl;
        encode[t].huff={mapH(encode[t].que, freq1[t].letter)};
        //cout<<"TRACE 3 "<<t<<" "<<encode[t].huff<<" "<<freq1[t].letter<<endl;
       // cout<<t<<" "<<encode[t].huff<<" "<<freq1[t].letter<<endl;
    }
    //cout<<"child process 3 is doing task 3"<<getpid()<<endl;
    cout<<endl;
    sleep(0);
    pid_t pid;
    cout<<"Original message: "<<encode[0].que<<endl;
    for(int i=1;i<zz;i++){
        pid = fork();
        if(pid == 0){
            cout<<"Symbol "<< freq1[i].letter<<" code: "<<encode[i].huff<<endl;
            cout<<"Remiaining code: "<<encode[i+1].que<<endl;
            exit(0);
        }
            //cout<<"Remiaining code: "<<encode[i].que<<endl;
            //cout<<"Symbol "<< freq1[i].letter<<" code "<<encode[i].huff<<endl;
        }  //cout<<freq1[i].letter<<endl;
        wait(0);
     
     cout<<endl;

    
return 0;
}

string getInput(){
    
    string Input="";
    string str;
    string InputTemp="";
    while (getline(cin,InputTemp)){
        Input+=InputTemp;
        Input+= '\r';
        if(InputTemp.length()==0)
            break;
    };
    str=Input;
    return str;
}

string mapH(string huff1,char toBeMapped){
        string outMap="";
        char wStr[huff1.length()];
        strcpy(wStr,huff1.c_str());
        for(int i=0;i<huff1.length();i++){
            //cout<<huff1.substr(i,1)<<endl;// indexes through the ith element of the string
          //  cout<<wStr[i]<<endl;
            if(wStr[i]==toBeMapped){
                outMap+="1";
            }
            else{
                outMap+="0";
            }
        }
        return outMap;
}

string reduction(string que, string mapH){
   // for debugging cout<<"TRACE 1 "<<que<<" "<<mapH<<endl;
    string redMap="";
        char rStr[que.length()];
        strcpy(rStr,que.c_str());//compair
        char mStr[mapH.length()];
        strcpy(mStr,mapH.c_str());//compair
        for(int i=0;i<que.length();i++){
            //cout<<huff1.substr(i,1)<<endl;// indexes through the ith element of the string
            //cout<<wStr[i]<<endl;
            //mStr copy
           // for debugging cout<<"TRACE 2 "<<i << " "<<rStr[i]<<" "<<mStr[i]<<endl;
            if(mStr[i]=='0'){
                redMap+=(rStr[i]);
               // cout<<rStr[i];
            }
                //redMap.erase(0,rStr[i]);
        }
        return redMap;
}

