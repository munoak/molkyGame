// TODO: Include your header file of the class describing a series of four colors
#include "colorcontainer.hh"
#include <iostream>
#include <vector>
#include <random>
#include <string>


using namespace std;

// Maximum number of guesses
// (Not used in the template code)
//const unsigned int GUESS_MAX = 10; // Not in use, yet



// Length of the suffix part when printing a row.
// The suffix consists of three vertical lines ('|') and two digits, where one
// tells the amount of totally correct colors and the other tells the amount
// of correct colors in incorrect positions.
const unsigned int SUFFIX_LENGTH_IN_PRINT = 5;

// Text printed at the beginning of the program
const string INFO_TEXT = "Colors in use: \
B = Blue, R = Red, Y = Yellow, G = Green, O = Orange, V = Violet";

// TODO: Do you need more constants?

// Reads the input way, either random or listing way,
// and fills the color series in the user-desired way.
// Repeats the question until the user enters either R or L.
void get_input(ColorContainer sec_series)
{
    cout << "Enter an input way (R = random, L = list): ";
    string input_str = "";
    cin >> input_str;
    if(input_str == "R" or input_str == "r")
    {
        cout << "Enter a seed value: ";
        int seed = 0;
        cin >> seed;
        sec_series.fill_series(seed); // Fill color series randomly based on the seed value

    }
    else if(input_str == "L" or input_str == "l")
    {
        bool accepted = false;
        while(not accepted)
        {
            sec_series.fill_list();
            if(not sec_series.check_colors())
            {
                cout << "Unknown color"<< endl;
            }
            else
            {
                if(not sec_series.check_length())
                {
                    cout << "Wrong size"<< endl;

                }
                else accepted = true;  // Update the boolean variable called accepted
            }

        }
    }
    else
    {
        cout << "Bad input" << endl;
        // Below the function itself is called recursively, which makes the
        // above code executed until an acceptable input_str is given,
        // but instead you can enclose the above code inside a loop structure.
        get_input(sec_series);
    }
}

// Prints a line consisting of the given character c.
// The length of the line is given in the parameter line_length.
void print_line_with_char(char c, unsigned int line_length)
{
    for(unsigned int i = 0; i < line_length; ++i)
    {
        cout << c;
    }
    cout << endl;
}

// Prints all color series.
// (Not called in the template code.)
void print_all(/* a vector including color series */)
{
    print_line_with_char('=', 2 * (SIZE + SUFFIX_LENGTH_IN_PRINT) + 1);
    //for(/* go through the vector */)
    {
        // TODO: print each vector element (color series)
    }
    print_line_with_char('=', 2 * (SIZE + SUFFIX_LENGTH_IN_PRINT) + 1);
}

// Implements the actual game loop, where user-given guesses are read
// and compared to the secret row.
// On each round, all rows given so far are printed.
int main()
{
    cout << INFO_TEXT << endl;
    print_line_with_char('*', INFO_TEXT.size());

    // TODO: Declare an object for a color series (the secret one)
    ColorContainer sec_series;
    get_input(sec_series);

    // TODO: Play the game, i.e. repeatedly read a user given number series
    // and compare it with the secret one
//    ColorContainer guess_series;
//    get_input(guess_series);

    return 0;
}

