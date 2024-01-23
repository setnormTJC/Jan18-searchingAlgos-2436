#include <iostream>
#include <vector>

#include"C:/Users/Work/Downloads/Timing.h"

using namespace std;

//class Linkedlist
//{
//
//};



template<typename T> //templates enable "generic programming" (not as strict wrt data type)
void print(vector<T> someList)
{
    for (auto& element : someList) //"range-based" for loop 
    {
        cout << element << " ";
    }
    cout << "\n";

    //for (int i = 0; i < someList.size(); i++)
    //{
    //    cout << someList.at(i) << " ";
    //    //cout << someList[i] << " ";
    //}

    cout << "\n";
}

template<typename T>
int sequential_search(vector<T> someList, T targetValue)
{
    for (int i = 0; i < someList.size(); i++)
    {
        if (someList[i] == targetValue)
        {
            return i; 
        }
    }

    return -9999; //not possible for an array (conventionally) 
}


vector<int> generateNRandomInts(int N)
{
    vector<int> randomNums; 
    for (int i = 0; i < N; i++)
    {
        randomNums.push_back(rand() % N);
    }

    return randomNums; 
}


void timeSequentialSearchForN(int N)
{
    auto vecN = generateNRandomInts(N);
    int randValue = rand() % (N + 1);
    Timer* tN = new Timer;
    sequential_search(vecN, randValue);//ignoring returned index value
    delete tN;
}

int main()
{
    srand(time(0)); 


    timeSequentialSearchForN(10); 
    timeSequentialSearchForN(100);
    timeSequentialSearchForN(500);
    timeSequentialSearchForN(1000);
    timeSequentialSearchForN(3000);
    timeSequentialSearchForN(5000);
    timeSequentialSearchForN(10'000);

   // const int N = 10'000; 
   // vector<int> numsList = generateNRandomInts(N); //vector is a DYNAMIC array 

   //// numsList.push_back(8536);
   // 
   // cout << "Contents of list: " << endl; 
   // //print(numsList);

   // cout << "Enter some number - we'lll check if in the list: " << endl; 
   // int targetNumber = rand() % N; 
   // 

   // Timer* timeToSearch = new Timer; 
   // cout << "The number " << targetNumber << "is? in the list at index number: "
   //     << sequential_search(numsList, targetNumber) << endl;
   // delete timeToSearch; 


    //std::find


    return 0;
}