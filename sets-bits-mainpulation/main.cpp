#include <iostream>
#include <windows.h>
#include<bits/stdc++.h>
#define int unsigned int
#define RESET   "\033[0m"
#define RED     "\033[31m"      /* Red */
#define GREEN   "\033[32m"      /* Green */
#define YELLOW  "\033[33m"      /* Yellow */
#define BLUE    "\033[34m"      /* Blue */
#define MAGENTA "\033[35m"      /* Magenta */
#define CYAN    "\033[36m"      /* Cyan */


using namespace std;
//part-1
int getBit(int number,int position){
    return (1 &(number >> (position)));
}
int setBit(int number, int position){
    return ((number & ~(1 << position)) | (1 << position));
}
int clearBit(int number, int position){
    return (number & ~(1 << position));
}
int updateBit(int number, int position, bool value){
   if(value == 1){
    setBit(number,position);
   }
   else {
     clearBit( number, position);
   }
}
//part-2
string* print(string arr[],int Size,int solution){//printing the solution from the binary value
    string arrreturn[Size];
    int j=0;
    for(int i=0;i<Size;i++){
        if(getBit(solution,Size-1-i)==1){
            arrreturn[j]= arr[i];
            cout << arrreturn[j] <<" ";
            j++;
        }
    }
    return arrreturn;
}
string* Union_of_two_sets(string universal[],int Size ,int arrss[],int firstsubset,int secondsubset){
    int solution = arrss[firstsubset]|arrss[secondsubset];
    return print(universal, Size, solution);

}

string* Intersection_of_two_sets(string universal[],int Size ,int arrss[],int firstsubset,int secondsubset){
    int solution = arrss[firstsubset]&arrss[secondsubset];
    return print(universal, Size, solution);

}

string* complement_of_sets(string universal[],int Size ,int arrss[],int subset){
    int solution = ~arrss[subset];
    return print(universal, Size, solution);

}

//part-3
int bits_manipulation(int arr[], int Size){
    int result = 0;
    for(int i =0 ;i < Size; i++)
        result = (result ^ arr[i]);
    return result;
}

int32_t main() {


    system("cls");
    cout << CYAN <<"press (1) for part1" RESET ;
    cout <<" or ";
    cout <<BLUE<<"(2) for part2"RESET;
    cout <<" or ";
    cout << YELLOW <<"(3) for part3"RESET;
    cout <<" or ";
    cout << RED <<"(0) for Exit: "RESET;

    string part_number;
    cin>>part_number;//choosing the part required

    while(part_number!="0"){

    if(part_number=="1"){

    cout<<"choose{";
    cout <<GREEN"get"RESET;
    cout <<", ";
    cout <<YELLOW"set"RESET;
    cout <<", ";
    cout <<BLUE"clear"RESET;
    cout <<", ";
    cout <<MAGENTA"update"RESET;
    cout <<", ";
    cout <<RED"exit"RESET;
    cout <<"} : ";

    string statement;
    cin >> statement;
    while(statement!="exit"){
    cout<<"Enter number and position"<<endl;
    int number,position;
    cin >> number;
    cin >> position;
    if(statement=="set"){
    cout << "OUTPUT:"<<setBit(number,position);}
    else if(statement=="clear"){
    cout << "OUTPUT:"<<clearBit(number,position);}
    else if(statement=="get"){
    cout << "OUTPUT:"<<getBit(number,position);}
    else if(statement=="update"){
        cout<<"enter the update value"<<endl;
        bool value;
        cin>> value;
        cout << "OUTPUT:"<<updateBit(number,position,value);}
    cout<<"\nchoose{";
    cout <<GREEN"get"RESET;
    cout <<", ";
    cout <<YELLOW"set"RESET;
    cout <<", ";
    cout <<BLUE"clear"RESET;
    cout <<", ";
    cout <<MAGENTA"update"RESET;
    cout <<", ";
    cout <<RED"exit"RESET;
    cout <<"} : ";
    cin >> statement;
    }

    }


    else if(part_number=="2"){

        string Universal_elements;
        string universal[1000];
        int Size=0;
        cout << "Enter the Universal set elements: " <<endl;

        cin >>Universal_elements;
            while(cin.get()!= '\n'){
                universal[Size]=Universal_elements;
                Size++;
                cin >> Universal_elements;
            }
        universal[Size] = Universal_elements;
        Size++;
        int bits=pow(2,Size)-1;
        cout << "Enter number of subsets: " <<endl;
        int numberofsets;
        cin>>numberofsets;
        int ArrSets[numberofsets];
        int number_of_sets = numberofsets;
        int sets_number=0;
        ArrSets[sets_number]=bits; //the first set in ArrSets is universal sorted as binary
        sets_number++;
        cout << "Enter the subset elements";
        cout<<RED" (if the subset is null enter NULL): "RESET;
        for (int j = 0; j < numberofsets; j++) { //reading the subsets and getting binary equivalent
           ArrSets[sets_number]=0;
           while(1){
                string set_input;
                cin>>set_input;
                if(set_input!="NULL"){
                    for (int k = 0; k<Size; k++) {//setting the bits while reading the subsets
                        if(set_input==universal[k]){
                            ArrSets[sets_number]=setBit(ArrSets[sets_number],Size-1-k);
                        break;
                        }
                    }
                }
                else if(set_input=="NULL"){
                    ArrSets[sets_number]=0<<Size;
                }
            if(cin.get()== '\n'){
                break;
            }
        }
        sets_number++;
        number_of_sets--;
        if(number_of_sets!=0){
        cout << "Enter the next subset elements";
        cout<<RED" (if the subset is null enter NULL): "RESET;}
        }
        cout << GREEN"Enter 1 for Union"RESET;
        cout <<" or ";
        cout << YELLOW"2 for Intersection"RESET;
        cout <<" or ";
        cout << BLUE"3 for Complement"RESET;
        cout <<" or ";
        cout << RED"0 for Exit"RESET;
        cout <<" : ";
        string chose;
        cin >> chose;
        while(chose!="0"){
        if(chose == "1"){
            int firstsubset,secondsubset;
            cout << "Enter number of 2 subsets to get " ;
            cout <<GREEN"Union"RESET;
            cout << " : ";
            cin >> firstsubset;
            cin >> secondsubset;
            cout << "THE OUTPUT: ";
            Union_of_two_sets(universal,Size, ArrSets, firstsubset, secondsubset);
        }

        if(chose == "2"){
            int firstsubset,secondsubset;
            cout << "Enter number of 2 subsets to get " ;
            cout <<YELLOW"Intersection"RESET;
            cout << " : ";
            cin >> firstsubset;
            cin >> secondsubset;
            cout << "THE OUTPUT: ";
            Intersection_of_two_sets(universal,Size, ArrSets, firstsubset, secondsubset);
        }

        if(chose == "3"){
            int subset;
            cout << "Enter number of the subset to get " ;
            cout << BLUE"The Complement"RESET;
            cout << " : ";
            cin >> subset;
            cout << "THE OUTPUT: ";
            complement_of_sets(universal, Size , ArrSets, subset);
        }
        cout << GREEN"\nEnter 1 for Union"RESET;
        cout <<" or ";
        cout << YELLOW"2 for Intersection"RESET;
        cout <<" or ";
        cout << BLUE"3 for Complement"RESET;
        cout <<" or ";
        cout << RED"0 for Exit"RESET;
        cout <<" : ";
        cin >> chose;
        }
}

    else if(part_number=="3"){
        cout << YELLOW<<"1 for Enter the elements of array "RESET;
        cout << RED<<"0 for exit: "RESET ;
        int input;
        cin >> input;
        while(input!=0){
        cout << "Enter the elements of array:" <<endl;
        int arr[1000];
        int elements,i=0;
        cin >>elements;
        while(cin.get()!= '\n'){
            arr[i]=elements;
            i++;
            cin >> elements;
        }
        arr[i]=elements;
        i++;
        cout << "the single number is: " << bits_manipulation(arr, i) << endl;
        cout << YELLOW<<"1 for Enter the elements of array "RESET;
        cout << RED<<"0 for exit: "RESET ;
        cin >> input;
    }

    }
    cout << CYAN <<"\npress (1) for part1" RESET ;
    cout <<" or ";
    cout <<BLUE<<"(2) for part2"RESET;
    cout <<" or ";
    cout << YELLOW <<"(3) for part3"RESET;
    cout <<" or ";
    cout << RED <<"(0) for Exit: "RESET;
    cin >> part_number;
    }

}

