/*
** COT5405 Group Programming Assignment
** Group 1
** Ulku Meteriz, Necip Yildiran, Alexander Roustai
*/

#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    // Define arrays.
    unsigned int k = 3;
    unsigned int firstValue[k];
    unsigned int secondValue[k];
    unsigned int finalValue[k];
    
    // Set the seed value of the random number generator.
    srand(time(NULL));
    
    // Initialize the flags false.
    bool isNegative = false;

    // Populate arrays with random numbers.
    const unsigned int min = 1e8;
    const unsigned int range = 999999999 - 1e8;
    for(int i = 0; i < k; i++)
    {
        // Since unsigned integer can hold up to 10 digit, restrict it to 9 digit to be safe.
        firstValue[i] = min + (rand() % range);
        secondValue[i] = min + (rand() % range);
    }

    // Print values.
    cout << "Value One:\t";
    for(int n = k-1; n >= 0; n--)
    {
        cout << firstValue[n];
    }
    cout << endl;
    
    cout << "Value Two:\t";
    for(int m = k-1; m >= 0; m--)
    {
        cout << secondValue[m];
    }
    cout << "\n";

    // Determine whether the result will be positive or negative.
    
    int index = k-1;
    
    while (index >= 0)
    {
    
        if(firstValue[index] > secondValue[index])
        {
            isNegative = false;
            break;
        }
        else if(firstValue[index] < secondValue[index])
        {
            isNegative = true;
            break;
        }
        
        index--;
    }

    
    // If first value is bigger than second value, subtract the second from the first as usual.
    if(!isNegative)
    {
        for(int indexTwo = 0; indexTwo < k; indexTwo++)
        {
            // If there is a need to get a carry from the next division...
            if(firstValue[indexTwo] < secondValue[indexTwo])
            {
                // Decrement the next one by one,
                firstValue[indexTwo + 1] = firstValue[indexTwo + 1] -1;
                // ... Add the current one the corresponding value.
                firstValue[indexTwo] = firstValue[indexTwo] + 1e8;
            }
            // Put the result in corresponding position in the final array.
            finalValue[indexTwo] = firstValue[indexTwo] - secondValue[indexTwo];
        }
    }
    // If second value is bigger than first value,ie negative flag is set,
    // ... subtract the first value from the second one.
    else
    {
       for(int indexThree = 0; indexThree < k; indexThree++)
       {
        
            if(firstValue[indexThree] > secondValue[indexThree])
            {
                secondValue[indexThree + 1] = secondValue[indexThree + 1] -1;
                secondValue[indexThree] = secondValue[indexThree] + 1e8;
            }
            finalValue[indexThree] = secondValue[indexThree] - firstValue[indexThree];
       }
    }


    //print final answer
    cout << "Final Answer:\t";
    if (isNegative)
        cout << "-";
    else
        cout << " ";
        
    for(int indexFour = k-1; indexFour >= 0; indexFour--)
        cout << finalValue[indexFour];
    
    cout << "\n";

    return 0;
}

