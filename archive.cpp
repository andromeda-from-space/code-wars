// Archived Code Wars Solutions to help reduce compile time
#include <cstdint>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>

using Ingredients = std::unordered_map<std::string, int>;
//-----------------------------------------------------------------------------
// 5/6/2025

std::string DNAtoRNA(std::string dna){
    for(int i = 0; i < dna.size(); i++){
        if(dna[i] == 'T'){
            dna[i] = 'U';
        }
    }
    return dna;
}

void test_DNAtoRNA(){
    std::string dna0 = "";
    std::cout << "Test 0: Initial: " << dna0 << " Final: " << DNAtoRNA(dna0) << " Expected: " << std::endl;

    std::string dna1 = "GCAT";
    std::cout << "Test 1: Initial: " << dna1 << " Final: " << DNAtoRNA(dna1) << " Expected: GCAU" << std::endl;
}

/*
Implement a function that adds two numbers together and returns their sum in binary. The conversion can be done before, or after the addition.

The binary number returned should be a string.

Examples:(Input1, Input2 --> Output (explanation)))

1, 1 --> "10" (1 + 1 = 2 in decimal or 10 in binary)
5, 9 --> "1110" (5 + 9 = 14 in decimal or 1110 in binary)

#include <cstdint>
#include <string>
*/

std::string add_binary(uint64_t a, uint64_t b) {
    a = a + b;
    std::string output = "";
    if(a == 0){
        output = "0";
    } else {
        while(a > 0){
            if(a % 2 == 1){
                output = "1" + output;
            } else {
                output = "0" + output;
            }
            a /= 2;
        }
    }
    return output;
}

void test_add_binary(){
    uint64_t a = 0;
    uint64_t b = 0;
    std::cout << "Test 0: a: " << a << " b: " << b << "Output: " << add_binary(a, b) << " Expected: 0" << std::endl;
    
    a = 5;
    b = 9;
    std::cout << "Test 1: a: " << a << " b: " << b << "Output: " << add_binary(a, b) << " Expected: 1110" << std::endl;
}

/*
Your task is to make a function that can take any non-negative integer as an argument and return it with its digits in descending order. Essentially, rearrange the digits to create the highest possible number.
Examples:

Input: 42145 Output: 54421

Input: 145263 Output: 654321

Input: 123456789 Output: 987654321

#include <cinttypes>
#include <vector>
#include <algorithm>
*/
uint64_t descendingOrder(uint64_t a)
{
    if(a != 0){
        // Extract digits
        std::vector<uint64_t> digits;
        while(a > 0){
            digits.push_back(a % 10);
            a = a / 10;
        }
        
        // Sort
        std::sort(digits.begin(), digits.end(), std::greater<uint64_t>());
        
        // Reconstruct number
        uint i = 0;
        for(; i < digits.size() - 1; i++){
            a += digits[i];
            a *= 10;
        }
        a += digits[i];
    }
    return a;
}

void test_descendingOrder(){
    uint64_t a = 42145;
    std::cout << "Test 0: a: " << a << " Final: " << descendingOrder(a) << " Expected: 54421" << std::endl;
    a = 145263;
    std::cout << "Test 0: a: " << a << " Final: " << descendingOrder(a) << " Expected: 654321" << std::endl;
    a = 123456789;
    std::cout << "Test 0: a: " << a << " Final: " << descendingOrder(a) << " Expected: 987654321" << std::endl;
}

void stalinSort(std::vector<int>& arr){
    if(!arr.empty()){
        auto itr = arr.begin();
        while(itr < arr.end() - 1){
            if(*itr > *(itr + 1)){
                arr.erase(itr + 1);
            } else {
                itr++;
            }
        }
    }
}

void test_stalinSort(){
    std::vector<int> test0;
    test0 = {3, 1, 4, 1, 5, 9, 2};
    stalinSort(test0);
    std::cout << "Actual: [";
    for(auto itr = test0.begin(); itr < test0.end(); itr++){
        std::cout << *itr << ", ";
    }
    std::cout << "]" << std::endl;
    std::cout << "Expected: [3, 4, 5, 9]" << std::endl;
}

/*
Convert 1-3999 to roman numerals.

Symbol    Value
I          1
V          5
X          10
L          50
C          100
D          500
M          1,000
*/
std::string solution(int number){
    // Initialize output
    std::string output = "";

    // 1000 - 3999
    if(number >= 3000){
        output += "MMM";
        number -= 3000;
    } else if(number >= 2000){
        output += "MM";
        number -= 2000;
    } else if(number >= 1000){
        output += "M";
        number -= 1000;
    }

    // 100 - 900
    if(number > 900){
        output += "CM";
        number -= 900;
    } else if(number >= 800){
        output += "DCCC";
        number -= 800;
    } else if(number >= 700){
        output += "DCC";
        number -= 700;
    } else if(number >= 600){
        output += "DC";
        number -= 600;
    } else if(number >= 500){
        output += "D";
        number -= 500;
    } else if(number >= 400){
        output += "CD";
        number -= 400;
    } else if(number >= 300){
        output += "CCC";
        number -= 300;
    } else if(number >= 200){
        output += "CC";
        number -= 200;
    } else if(number >= 100){
        output += "C";
        number -= 100;
    }

    // 10-90
    if(number >= 90){
        output += "XC";
        number -= 90;
    } else if(number >= 80){
        output += "LXXX";
        number -= 80;
    } else if(number >= 70){
        output += "LXX";
        number -= 70;
    } else if(number >= 60){
        output += "LX";
        number -= 60;
    } else if(number >= 50){
        output += "L";
        number -= 50;
    } else if(number >= 40){
        output += "XL";
        number -= 40;
    } else if(number >= 30){
        output += "XXX";
        number -= 30;
    } else if(number >= 20){
        output += "XX";
        number -= 20;
    } else if(number >= 10){
        output += "X";
        number -= 10;
    }

    // 1-9
    if(number == 9){
        output += "IX";
    } else if(number == 8){
        output += "VIII";
    } else if(number == 7){
        output += "VII";
    } else if(number == 6){
        output += "VI";
    } else if(number == 5){
        output += "V";
    } else if(number == 4){
        output += "IV";
    } else if(number == 3){
        output += "III";
    } else if(number == 2){
        output += "II";
    } else if(number == 1){
        output += "I";
    }

    return output;
}

void test_solution(){
    int test = 182;
    std::cout << "Result: " << solution(test) << " Expected: CLXXXII" << std::endl;
    test = 1990;
    std::cout << "Result: " << solution(test) << " Expected: MCMXC" << std::endl;
    test = 1875;
    std::cout << "Result: " << solution(test) << " Expected: MDCCCLXXV" << std::endl;
}

// Returns the count of number of the copies of the recipe you can do with the ingredients in the pantry (available)
int cakes(const Ingredients& recipe, const Ingredients& available) {
    int output = -1;
    for(auto itrRecipe : recipe){
        bool found  = false;
        for(auto itrAvailable : available){
            if(itrRecipe.first == itrAvailable.first){
                found = true;
                int temp = itrAvailable.second / itrRecipe.second;
                if(output < 0 || temp < output){
                    output = temp;
                }
                break;
            }
        }
        if(!found || output <= 0){
            output = 0;
            break;
        }
    }
    return output;
}

void test_cakes(){
        Ingredients recipe0 = {{"flour",  500}, {"sugar",  200}, {"eggs", 1}};
        Ingredients available0 = {{"flour", 1200}, {"sugar", 1200}, {"eggs", 5}, {"milk", 200}};
        std::cout << "Result: " << cakes(recipe0, available0) << " Expected: 2" << std::endl;

        Ingredients recipe1 = {{"apples",  3}, {"flour",  300}, {"milk",  100}, {"sugar", 150}, {"oil", 100}};
        Ingredients available1 = {{"sugar", 500}, {"flour", 2000}, {"milk", 2000}};
        std::cout << "Result: " << cakes(recipe1, available1) << " Expected: 0" << std::endl;

        Ingredients recipe2 = {{"butter", 21}, {"eggs", 80}, {"flour", 44}};
        Ingredients available2 = {{"chocolate", 6766}, {"pears", 424}, {"crumbles", 2708}, {"butter", 5437}, {"cream", 3628}, {"sugar", 2543}, {"apples", 8622}, {"cocoa", 541}, {"oil", 2635}, {"flour", 4096}};
        std::cout << "Result: " << cakes(recipe2, available2) << " Expected: 0" << std::endl;
}

// Test if a number is a narcissitic number
bool narcissistic( int value ){
    // Invalid cases
    if(value < 0){
        return false;
    }

    // Base cases, 1 digit numbers of any base are all naricistic
    if(value < 10){
        return true;
    }

    // Digit break down
    std::vector<int> digits;
    int temp = value;
    while(temp > 0){
        digits.push_back(temp % 10);
        temp = temp / 10;
    }
    
    // Calculate value by definition
    int total = 0;
    for(uint i = 0; i < digits.size(); i++){
        temp = digits[i];
        for(uint j = 1; j < digits.size(); j++){
            temp = temp * digits[i];
        }
        total += temp;
    }

    // Check if the numbers are equivalent
    return total == value;
}

void test_narcissitic(){
    for(int i = 0; i < 1000000; i++){
        if(narcissistic(i)){
            std::cout << i << std::endl;
        }
    }
}

// Find the two numbers in the list that sum to the target number
std::pair<std::size_t, std::size_t> two_sum(const std::vector<int>& numbers, int target) {
    std::pair<std::size_t, std::size_t> output = {-1, -1};
    for(size_t i = 0; i < numbers.size(); i++){
        output.first = i;
        for(size_t j = i + 1; j < numbers.size(); j++){
            if(numbers[i] + numbers[j] == target){
                output.second = j;
                return output;
            }
        }
    }
    return output;
}

// Make the characters do the wave in a vector
std::vector<std::string> wave(std::string y){
    std::vector<std::string> output;   
    for(uint i = 0; i < y.size(); i++){
        if(y[i] != ' '){
            output.push_back(y);
            output[output.size() - 1][i] = output[output.size() - 1][i] - 32;
        }
    }
    return output;
}

void test_wave(){
    std::string test = " hello ";
    std::vector<std::string> result = wave(test);
    for(uint i = 0; i < result.size(); i++){
        std::cout << result[i] << " ";
    }
    std::cout << std::endl;
}

// Validate if the pattern of braces provided is valid (left and right braces open and close properly)
bool valid_braces(const std::string &braces){
    if(braces.size() % 2 != 0){
        // Can't be valid if not even amount of braces and parentheses (assuming nothing inbetween)
        return false;
    } else if(!(braces[0] == '(' || braces[0] == '[' || braces[0] == '{')) {
        // Make sure first brace is a left one
        return false;
    } else {
        // LIFO
        std::vector<char> braceStack;
        char currChar;
        braceStack.push_back(braces[0]);
        for(uint i = 1; i < braces.size(); i++){
            currChar = braces[i];
            if(currChar == '(' || currChar == '[' || currChar == '{'){
                braceStack.push_back(currChar);
            } else {
                if((currChar == ')' && braceStack[braceStack.size() - 1] == '(') ||
                    (currChar == ']' && braceStack[braceStack.size() - 1] == '[') ||
                    (currChar == '}' && braceStack[braceStack.size() - 1] == '{') ){
                        braceStack.pop_back();
                } else {
                    return false;
                }
            }
        }
    }

    return true;
}

void test_valid_braces(){
    std::cout << "true  : " << valid_braces("()") << std::endl;
    std::cout << "true  : " << valid_braces("()[]{}") << std::endl;
    std::cout << "false : " << valid_braces(")(") << std::endl;
    std::cout << "false : " << valid_braces("([)]") << std::endl;
    std::cout << "true  : " << valid_braces("[({})]") << std::endl;
    std::cout << "true  : " << valid_braces("[()()]") << std::endl;
    std::cout << "true  : " << valid_braces("[(())()]") << std::endl;
    std::cout << "true  : " << valid_braces("[()({[()]})]") << std::endl;
}

// Note - this is super easy with hashes
// Counts the number of characters with duplicates in the string, ignoring case, assume alphanumeric
// aabb - 2, 2 a's and 2 b's
// abb - 1, 2 b's
// ab - 0
std::size_t duplicateCount(const std::string& in){
    // Count
    std::size_t count = 0;

    // Run algorithm if string is longer than length 1
    if(in.size() > 1){
        // Tally the counts of each character
        std::vector<std::pair<char, int>> counts;
        counts.push_back({tolower(in[0]), 1});
        for(uint i = 1; i < in.size(); i++){
            char temp = tolower(in[i]);
            bool found = false;
            for(uint j = 0; j < counts.size() && !found; j++){
                if(counts[j].first == temp){
                    counts[j].second++;
                    found = true;
                }
            }
            if(!found){
                counts.push_back({temp, 1});
            }
        }

        // Count the duplicates
        for(uint i = 0; i < counts.size(); i++){
            if(counts[i].second >= 2){
                count++;
            }
        }
    }

    return count;
}

void test_duplicateCount(){
    std::string test = "asdfghjkl54";
    std::cout << "Expected 0, Result: " << duplicateCount(test) << std::endl;

    test = "abcdeaa";
    std::cout << "Expected 1, Result: " << duplicateCount(test) << std::endl;

    test = "hhhhhhHHhhHHHHhhhhhHhH";
    std::cout << "Expected 1, Result: " << duplicateCount(test) << std::endl;

    test = "asdfghjkl55";
    std::cout << "Expected 1, Result: " << duplicateCount(test) << std::endl;
}
//-----------------------------------------------------------------------------