#include <iostream>
#include <vector>

#include"C:/Users/Work/Downloads/Timing.h"


using namespace std;



int binarySearch(std::vector<int> sortedNums, int searchValue)
{
    bool found = false;
    int first = 0;
    int last = sortedNums.size() - 1;
    int middle;
    

    int comparisonCount = 0;
    while (first <= last and !found)
    {
        middle = (first + last) / 2; //use ceil() or floor() for odd lengths … be cautious
        if (sortedNums[middle] == searchValue)
        {
            found = true;
        }
        else if (sortedNums[middle] > searchValue)
        {
            comparisonCount++; 
            last = middle - 1;//shift last one to the "left" of middle
        }
        else
        {
            comparisonCount++;
            first = middle + 1;
        }

    }//end while 

    cout << "Total comparisons for binary sea." << comparisonCount << endl; 

    if (found)
    {
        return middle;
    }
    else
    {
        return -1;//element is not in array
    }
} //end func. def.

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


int main()
{
    srand(time(0)); 

    vector<int> MANYevenNums; 

    for (int i = 0; i < 10'000'000; i = i + 2)
    {
        MANYevenNums.push_back(i);  //0 2 4 6 ...100'000
    }
    //RAND_MAX // problematic in this case

    for (int i = 0; i < 5; i++)
    {

        int randomIndex = (rand() % MANYevenNums.size()) * 100; 

        int targetValue = MANYevenNums.at(randomIndex);

        cout << "COMPARING sequential and binary search speeds (times) ..." << endl; 
        cout << "The target value is " << targetValue << endl; 

    
        Timer* timeForBinarySearch = new Timer; 
        binarySearch(MANYevenNums, targetValue);
        delete timeForBinarySearch;

        Timer* timeForSeqSearch = new Timer; 
        sequential_search(MANYevenNums, targetValue);
        delete timeForSeqSearch;

        cout << "Binary search index returned: " << binarySearch(MANYevenNums, targetValue) << endl; //COUT takes ~ 1ms
        cout << "Sequential search: " << sequential_search(MANYevenNums, targetValue) << endl; 

        cout << "\n\n";
        system("pause");
    //vector<int> evenNums = { 2, 4, 6, 8, 10, 12, 14, 16 };
    }
    //int targetValue = 14; 

    //cout << "The target value " << targetValue << " was? found at index: " <<
    //    binarySearch(evenNums, targetValue); 


    return 0;
}