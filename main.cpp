/*
** COT5405 Group Programming Assignment
** Group 1
** Ulku Meteriz, Necip Yildiran, Alexander Roustai
*/

#include <iostream>
#include <cmath>
#include <chrono>

using namespace std;

// Globals for evaluation.
const unsigned int digitPerUINT = 8;
const unsigned int maxValueForCell = 10e8-1;
const unsigned int minValueForCell = 10e7;
const unsigned int repetition = 1000;    


void printBigNumber(unsigned int number[], unsigned int size)
{
    for(int n = size-1; n >= 0; n--)
    {
        cout << number[n];
    }
    cout << endl;
}

void subtraction(unsigned int k, unsigned int min, unsigned int max)
{
    // Define arrays.
    unsigned int firstValue[k];
    unsigned int secondValue[k];
    unsigned int finalValue[k];
    
    // Set the seed value of the random number generator.
    srand(time(NULL));
    
    // Initialize the flags false.
    bool isNegative = false;

    // Populate arrays with random numbers.
    unsigned int range = max - min + 1;
    for(int i = 0; i < k; i++)
    {
        firstValue[i] = min + (rand() % range);
        secondValue[i] = min + (rand() % range);
    }

    // Print values.
    
    /*
    cout << "Value One:\t";
    printBigNumber(firstValue, k);
    
    cout << "Value Two:\t";
    printBigNumber(secondValue, k);
    */
    
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
                firstValue[indexTwo + 1] -= 1;
                // ... Add the current one the corresponding value.
                firstValue[indexTwo] += 10*min;
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
                secondValue[indexThree + 1] -= 1;
                secondValue[indexThree] += 10*min;
            }
            finalValue[indexThree] = secondValue[indexThree] - firstValue[indexThree];
       }
    }


    //Print final answer
    
    /*cout << "Final Answer:\t";
    if (isNegative)
        cout << "-";
    else
        cout << " ";
        
    printBigNumber(finalValue,k);*/
    
}


// Measures the time for the execution.
unsigned long evaluation(unsigned int n)
{
    // Start the timer.
    auto start_time = std::chrono::high_resolution_clock::now(); 
    
    if(n == 4)
    {
        for(int i = 0; i < repetition; i++)
            subtraction(1,1e3,9999);
    }
    else
    {
        for(int i = 0; i < repetition; i++)
            subtraction(n/digitPerUINT,minValueForCell,maxValueForCell);
    }
    
    // Stop the timer.
	auto current_time = std::chrono::high_resolution_clock::now();
    
    // Compute the execution time.
    unsigned long usec = std::chrono::duration_cast<std::chrono::microseconds>(current_time - start_time).count();
    
    return usec;
    
}

int main(int argc , char *argv[])
{      

    unsigned long usec = 0;
    for (int n = 4; n <= 512 ; n*=2 )
    {
        cout << "n is " << n << endl;
        // TODO: cache must be flushed each time.
        usec = evaluation(n);
        cout << "Execution time: " << usec << " us" << endl;
    }
    
    return 0;
}




