#include <iostream>
#include <limits>
#include <cstddef>

using namespace std;

void shortOF()
{
    short i = 1;
    short sum = 0;
    //While sum is greater than or equal to 0, keep looping until Sum turns negative
    //(Due to OverFlow)
    while(sum >= 0)
    {
        sum = sum + i;
        //if statement testing for negatives before incrementing our index.
        if(sum < 0)
        {
            cout << "Reached OverFlow Error at Short n: " << i << endl;
            cout << "sum: " << sum << endl << endl;
        }
        i++;
    }
}

void longOF()
{
    long i = 1;
    long sum = 0;
    while(sum >= 0)
    {
        sum = sum + i;
        if(sum < 0)
        {
            cout << "Reached OverFlow Error at Long n: " << i << endl;
            cout << "sum: " << sum << endl;
            cout << "-----------------------------------------------------------------------------------------" << endl;
        }
        i++;
    }
}

void factOF()
{
    cout << "Computing Factorials with floats, this will take a minute." << endl << endl;
    //5x4x3x2x1
    long i = 1;
    float sum = 0;
    while(sum >= 0)
    {
        //countDown is used to help keep track of all the values under i as we loop
        //through the equation without needing to change the i variable.
        int countDown = i;
        if(countDown >= i)
        {
            sum = sum + (i * countDown);
            countDown--;
            if(sum < 0)
            {
                cout << "Reached OverFlow Error at float factorial n: " << i << endl;
                cout << "product: " << sum << endl << endl;
            }
            else if(countDown < i)
            {
                i++;
            }
        }
    }
    //--------------------------------------------------------------------------------------
    /**cout << "Computing Factorials with doubles, this may take a while." << endl << endl;
    //5x4x3x2x1
    long i = 1;
    double sum = 0;
    while(sum >= 0)
    {
        int countDown = i;
        while(countDown > 0)
        {
            sum = sum + (i * countDown);
            cout << "sum= " << sum << " || i= " << i << " || countDown= " << countDown << endl;
            countDown--;
            if(sum < 0)
            {
                cout << "Reached OverFlow Error at double factorial n: " << i << endl;
                cout << "product: " << sum << endl << endl;
                break;
            }
        }
        i++;
    }*/
}

void doubleFractOF()
{
    //if n is 3, add 1/3 + 1/3 + 1/3 and then subtract 1. Continue till overflow
    cout << "Now starting fractOF() with sum as a double... " << endl;
    float i = 1;
    double sum = 0;
    while(sum >= 0)
    {
        int countDown = i;
        while (countDown > 0)
        {
            sum = sum + (1 / i);
            countDown--;
            //cout << "sum= " << sum << " || i= " << i << " || countDown= " << countDown << endl;
        }
        sum = sum - 1;
        if(sum < 0)
        {
            cout << "Reached OverFlow Error at n: " << i << endl;
            cout << "product: " << sum << endl << endl;
            cout << "The expected result would be to have zero reported each time we looped" << endl;
            cout << "through the operation. But because of the precision provided by doubles," << endl;
            cout << "there is a small decimal amount left over after each loop through the" << endl;
            cout << "operation that adds up. (Fractions like 1/3 that are 0.3 repeating)" << endl;
            cout << "-----------------------------------------------------------------------------------------" << endl;
        }
        else
        {
            //cout << "sum= " << sum << " || i= " << i << " || countDown= " << countDown << endl;
            i++;
        }
    }
}

void floatFractOF()
{
    cout << "Now starting fractOF() with sum as a float... " << endl;
    double i = 1;
    float sum = 0;
    while(sum >= 0)
    {
        int countDown = i;
        while (countDown > 0)
        {
            sum = sum + (1 / i);
            countDown--;
            //cout << "sum= " << sum << " || i= " << i << " || countDown= " << countDown << endl;
        }
        // Once we looped through all the values for countDown in respect to i, we subtract 1 from the sum
        //and then loop through again for the next increment of i.
        sum = sum - 1;
        if(sum < 0)
        {
            cout << "Reached OverFlow Error at n: " << i << endl;
            cout << "product: " << sum << endl << endl;
            cout << "For the same reason as doubles, the precision provided by the floats" << endl;
            cout << "leave small decimal amounts that add up through the operation loops." << endl;
            cout << "The reason floats hit their overflow sooner is because their decimal" << endl;
            cout << "place is limited to only six places compared to the doubles' 14." << endl;
            cout << "-----------------------------------------------------------------------------------------" << endl;
        }
        else
        {
            //cout << "sum= " << sum << " || i= " << i << " || countDown= " << countDown << endl;
            i++;
        }
    }
}

void puzzle()
{
    for (float i = 3.4; i < 4.4; i += 0.2)
	{
		cout << "i(floats) = " << i << endl;
	}
	cout << "The error occurs at 'i(floats) = 4.4' as 4.4 is the end parameter for the" << endl;
	cout << "function to end. The reason for this is that floats are only a SINGLE" << endl;
	cout << "point precision data-type and so after repeated operations on a 'mixed-" << endl;
	cout << "number', the precision is slowly lost on the value being summed up." << endl << endl;
	for (double i = 3.4; i < 4.4; i += 0.2)
	{
		cout << "i(doubles) = " << i << endl;
	}
	cout << "Doubles are aptly named for it's DOUBLE precision producing greater" << endl;
	cout << "precision that floats, allowing for more operations on 'mixed-numbers'" << endl;
	cout << "without losing as much accuracy for the summed up values." << endl;
}


int main()
{
    cout << "Frankie Galtieri" << endl << endl;
    shortOF();
    longOF();
    factOF();
    cout << "Cannot reach overflow within reasonable a timeframe, the max value allowed for a double" << endl;
    cout << "in this equation is: " << std::defaultfloat << std::numeric_limits<double>::max() << endl << endl;
    cout << "-----------------------------------------------------------------------------------------" << endl;
    doubleFractOF();
    floatFractOF();
    puzzle();
    return 0;
}
