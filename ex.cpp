// g++ -pedantic -Wall -Wextra -std=c++17 ex.cpp

#include <iostream>
#include <string>
#include <vector>
#include <cmath>

//the number of permutations of a string of length n is n!



// ask user for letters until a non letter is entered and return the letters
std::vector<char> get_letters()
{
    std::vector<char> letters;
    char letter;
    //while the user enters letters, add them to the vector
    while (std::cin >> letter)
    {   //check if the letter is a letter
        if (std::isalpha(letter))
        {   // if so, add the letter to the vector
            letters.push_back(letter);
        }
        else
        {
            break;
        }
    }
    return letters;
}

//recursively print out all possible combinations of the letters in the vector by reference
void print_permutations(std::vector<char> & letters, std::vector<char> & permutation)
{
    //base case
    if (letters.size() == 0)
    {   //print out the permutation
        for (char letter : permutation)
        { 
            std::cout << letter << " ";
        }
        std::cout << std::endl;
    }
    else
    {
        //recursive case - for each letter in the vector
        for (int i = 0; i < letters.size(); i++)
        {
            //create a new permutation by adding the ith letter to the permutation
            std::vector<char> new_permutation = permutation;
            new_permutation.push_back(letters[i]);
            //create a new vector of letters by removing the ith letter
            std::vector<char> new_letters = letters;
            new_letters.erase(new_letters.begin() + i);
            //recursively call print_permutations with the new letters and permutation
            print_permutations(new_letters, new_permutation);
        }
    }
}



int main(){
    std::cout << "Enter letters: ";
    std::vector<char> letters = get_letters();
    //uncomment the following to print out the letters in the console

    // std::cout << "You entered: ";
    // for (char letter : letters)
    // {
    //     std::cout << letter << " ";
    // }
    // std::cout << std::endl;

    //pass the letters to the print_permutations function
    std::vector<char> permutation;
    print_permutations(letters, permutation);

    return 0;
}


//expected output
// The string with length of 2 will have 2 permutations
// The string with length of 3 will have 6 permutations
// The string with length of 4 will have 24 permutations
// the amount of permuations is equal to n! where n is the length of the string

// Output 
// Enter letters: a b 1
// a b
// b a
// Enter letters: a b c 1
// a b c
// a c b
// b a c
// b c a
// c a b
// c b a
// Enter letters: a b c d 1
// a b c d
// a b d c
// a c b d
// a c d b
// a d b c
// a d c b
// b a c d
// b a d c
// b c a d
// b c d a
// b d a c
// b d c a
// c a b d
// c a d b
// c b a d
// c b d a
// c d a b
// c d b a
// d a b c
// d a c b
// d b a c
// d b c a
// d c a b
// d c b a










