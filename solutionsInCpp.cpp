#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <cstdint>
#include <numeric>

typedef unsigned long long ull;

/*
Given an array of integers, find the one that appears an odd number of times.
There will always be only one integer that appears an odd number of times.

Use a map.
*/
int findOdd(const std::vector<int>& numbers){
    // Get the counts of each number
    std::vector<std::pair<int, int>> numCounts;
    for(uint i = 0; i < numbers.size(); i++){
        bool found = false;
        for(uint j = 0; j < numCounts.size() && !found; j++){
            if(numCounts[j].first == numbers[i]){
                found = true;
                numCounts[j].second += 1;
            }
        }
        if(!found){
            numCounts.push_back({numbers[i], 1});
        }
    }
    
    // Find the odd one
    for(uint i = 0; i < numCounts.size() - 1; i++){
        if(numCounts[i].second % 2 == 1){
            return numCounts[i].first;
        }
    }

    return numCounts[numCounts.size() - 1].first;
}

void test_findOdd(){
    int res = findOdd({20,1,-1,2,-2,3,3,5,5,1,2,4,20,4,-1,-2,5});
    int exp = 5;
    std::cout << "Test 1: " << (res == exp) << std::endl;

    res = findOdd({1,1,2,-2,5,2,4,4,-1,-2,5});
    exp = -1;
    std::cout << "Test 2: " << (res == exp) << std::endl;

    res = findOdd({20,1,1,2,2,3,3,5,5,4,20,4,5});
    exp = 5;
    std::cout << "Test 3: " << (res == exp) << std::endl;

    res = findOdd({10});
    exp = 10;
    std::cout << "Test 4: " << (res == exp) << std::endl;

    res = findOdd({1,1,1,1,1,1,10,1,1,1,1});
    exp = 10;
    std::cout << "Test 5: " << (res == exp) << std::endl;
}

/*
The rgb function is incomplete. Complete it so that passing in RGB decimal values will result in a hexadecimal representation being returned. Valid decimal values for RGB are 0 - 255. Any values that fall out of that range must be rounded to the closest valid value.

Note: Your answer should always be 6 characters long, the shorthand with 3 will not work here.
*/

std::string rgb_to_hex(int r, int g, int b){
    std::string result = "000000";
    std::string hexKey = "0123456789ABCDEF";
    
    // Normalize to 0 to 255 with things outside the range going to 0 or 255 respectively
    r = r < 0 ? 0 : r;
    r = r > 255 ? 255 : r;
    b = b < 0 ? 0 : b;
    b = b > 255 ? 255 : b;
    g = g < 0 ? 0 : g;
    g = g > 255 ? 255 : g;

    // Convert to hex
    result[0] = hexKey[(r / 16) % 16];
    result[1] = hexKey[r % 16];
    result[2] = hexKey[(g / 16) % 16];
    result[3] = hexKey[g % 16];
    result[4] = hexKey[(b / 16) % 16];
    result[5] = hexKey[b % 16];
    return result;
}

void test_rgb_to_hex(){
    std::string res = rgb_to_hex(0, 0, 0);
    std::string exp = "000000";
    std::cout << "Test 1: " << (res == exp) << std::endl;
    if(exp != res){
        std::cout << "Result: " << res << " Expected: " << exp << std::endl;
    }

    res = rgb_to_hex(1, 2, 3);
    exp = "010203";
    std::cout << "Test 2: " << (res == exp) << std::endl;
    if(exp != res){
        std::cout << "Result: " << res << " Expected: " << exp << std::endl;
    }

    res = rgb_to_hex(255, 255, 255);
    exp = "FFFFFF";
    std::cout << "Test 3: " << (res == exp) << std::endl;
    if(exp != res){
        std::cout << "Result: " << res << " Expected: " << exp << std::endl;
    }

    res = rgb_to_hex(254,253,252);
    exp = "FEFDFC";
    std::cout << "Test 4: " << (res == exp) << std::endl;
    if(exp != res){
        std::cout << "Result: " << res << " Expected: " << exp << std::endl;
    }

    res = rgb_to_hex(-20,275,125);
    exp = "00FF7D";
    std::cout << "Test 5: " << (res == exp) << std::endl;
    if(exp != res){
        std::cout << "Result: " << res << " Expected: " << exp << std::endl;
    }
}


/*
Take the following IPv4 address: 128.32.10.1

This address has 4 octets where each octet is a single byte (or 8 bits).

    1st octet 128 has the binary representation: 10000000
    2nd octet 32 has the binary representation: 00100000
    3rd octet 10 has the binary representation: 00001010
    4th octet 1 has the binary representation: 00000001

So 128.32.10.1 == 10000000.00100000.00001010.00000001

Because the above IP address has 32 bits, we can represent it as the unsigned 32 bit number: 2149583361

Complete the function that takes an unsigned 32 bit number and returns a string representation of its IPv4 address.
*/

std::string uint32_to_ip(uint32_t ip){
    std::string result = "";
    int curr = ip % 256;
    result = "." + std::to_string(curr);
    ip = ip / 256;

    curr = ip % 256;
    result = "." + std::to_string(curr) + result;
    ip = ip / 256;

    curr = ip % 256;
    result = "." + std::to_string(curr) + result;
    ip = ip / 256;

    curr = ip % 256;
    result = std::to_string(curr) + result;
    return result;
}

void test_uint32_to_ip(){
    std::string exp = "128.114.17.104";
    std::string res = uint32_to_ip(2154959208);
    std::cout << "Test 1: " << (exp == res) << std::endl;
    if(exp != res){
        std::cout << "Result: " << res << " Expected: " << exp << std::endl;
    }

    exp = "0.0.0.0";
    res = uint32_to_ip(0);
    std::cout << "Test 2: " << (exp == res) << std::endl;
    if(exp != res){
        std::cout << "Result: " << res << " Expected: " << exp << std::endl;
    }

    exp = "128.32.10.1";
    res = uint32_to_ip(2149583361);
    std::cout << "Test 3: " << (exp == res) << std::endl;
    if(exp != res){
        std::cout << "Result: " << res << " Expected: " << exp << std::endl;
    }
}


/*
Find the common denominator for the provided fractions in the list. The entries in the list are pairs of longs
where the first number is the numerator and the second number is the denominator. Report the result as a single string
of the form: [(n,d)...(n,d)] where each pair of numbers is the converted to the new denominator.

For example: {(1, 2), (1, 3), (1, 4)} have a common denominator of 12 and after conversion:
"(6,12)(4,12)(3,12)"
is the resulting string.
*/
std::string convertFrac_v1(std::vector<std::vector<unsigned long long>> &lst){
    // Find LCM for common denominator
    unsigned long long lcm = 1;
    unsigned long long curr;
    std::map<unsigned long long, unsigned long long> currFactors;
    std::map<unsigned long long, unsigned long long> sharedFactors;

    // Create list of set of all prime factors
    // Example: 2 - 2; 3 - 3; 4 - 2,2 -> so total list of prime factors is 2,2,3 - and lcm is 12
    for(uint i = 0; i < lst.size(); i++){
        // Create list of prime factors for the current item in the list
        currFactors.clear();
        curr = lst[i][1];
        while(curr != 1){
            bool notPrime = false;
            unsigned long long factor = 2;
            while(factor*factor <= curr && !notPrime){
                if(curr % factor == 0){
                    notPrime = true;
                }
            }
            
            if(notPrime){
                currFactors[factor] += 1;
                curr = curr / factor;
            } else {
                currFactors[curr] += 1;
                curr = 1;
            }
        }

        // Merge into the current list of shared factors
        for(auto itr = currFactors.begin(); itr != currFactors.end(); itr++){
            if(sharedFactors[itr->first] < itr->second){
                sharedFactors[itr->first] = itr->second;
            }
        }
    }
    
    // Calculate lcm by multiplying the minimum list of shared factors
    for(auto itr = sharedFactors.begin(); itr != sharedFactors.end(); itr++){
        for(uint i = 0; i < itr->second; i++){
            lcm *= itr->first;
        }
    }

    // Multiply all by lcm and build string
    std::string result = "(";
    std::string suffix = "," + std::to_string(lcm) + ")(";
    for(uint i = 0; i < lst.size() - 1; i++){
        curr = lst[i][0] * (lcm / lst[i][1]);
        result = result + std::to_string(curr) + suffix;
    }
    // Last entry
    curr = lst[lst.size() - 1][0] * (lcm / lst[lst.size() - 1][1]);
    result = result + std::to_string(curr) + "," + std::to_string(lcm) + ")";
    return result;
}


std::string convertFrac(std::vector<std::vector<unsigned long long>> &lst){
    unsigned long long currLCM = std::lcm(lst[0][1], lst[1][1]);
    for(uint i = 2; i < lst.size(); i++){
        currLCM = std::lcm(currLCM, lst[i][1]);
    }

    // Multiply all by lcm and build string
    unsigned long long currNum;
    std::string result = "(";
    std::string suffix = "," + std::to_string(currLCM) + ")(";
    for(uint i = 0; i < lst.size() - 1; i++){
        currNum = lst[i][0] * (currLCM / lst[i][1]);
        result = result + std::to_string(currNum) + suffix;
    }
    // Last entry
    currNum = lst[lst.size() - 1][0] * (currLCM / lst[lst.size() - 1][1]);
    result = result + std::to_string(currNum) + "," + std::to_string(currLCM) + ")";
    return result;
}

void test_convertFrac(){
    std::vector<std::vector<unsigned long long>> r1 = { {1, 2}, {1, 3}, {1, 4} };
    std::string exp = "(6,12)(4,12)(3,12)";
    std::string res = convertFrac(r1);
    std::cout << "Test 1: " << (exp == res) << std::endl;
    if(exp != res){
        std::cout << "Result: " << res << " Expected: " << exp << std::endl;
    }
}

/*
Count the number of characters with duplicates in each string, considering only lower case characters.
Report the result as the string they are found in (= if the same in both), then a colon, then an
enumeration of the duplicates, terminated by a /. Example:

s1 = "my&friend&Paul has heavy hats! &"
s2 = "my friend John has many many friends &"
mix(s1, s2) --> "2:nnnnn/1:aaaa/1:hhh/2:mmm/2:yyy/2:dd/2:ff/2:ii/2:rr/=:ee/=:ss"
*/
std::string mix(const std::string &s1, const std::string &s2){
    // TODO
    return "";
}

void test_mix(){
    std::string s1 = "my&friend&Paul has heavy hats! &";
    std::string s2 = "my friend John has many many friends &";
    std::string exp = "2:nnnnn/1:aaaa/1:hhh/2:mmm/2:yyy/2:dd/2:ff/2:ii/2:rr/=:ee/=:ss";
    std::string res = mix(s1, s2);
    std::cout << "Test 1: " << (exp == res) << std::endl;
}

/*
Write a function that returns the sum of two numbers. The input numbers are strings and the function must return a string.

Note: expect the numbers to be bigger than longs and such
*/

std::string add(const std::string& a, const std::string& b) {
    // Initialize based on which one is smaller
    const std::string* smaller = a.size() < b.size() ? &a : &b;
    const std::string* bigger = a.size() < b.size() ? &b : &a;
    std::string result = std::string(*bigger);

    // Add digits in a and b while both have valid digits
    int temp = 0;
    for(uint i = 0; i < smaller->size(); i++){
        temp += (a[a.size() - i - 1] - '0') + (b[b.size() - i - 1] - '0');
        if(temp >= 10){
            temp = temp - 10;
            result[result.size() - i - 1] = temp + '0';
            temp = 1;
        } else {
            result[result.size() - i - 1] = temp + '0';
            temp = 0;
        }
    }

    // Add digits if appropriate
    int i = bigger->size() - smaller->size() - 1;
    while(temp == 1 && i >= 0){
        if(result[i] == '9'){
            result[i] = '0';
        } else {
            result[i] = result[i] + 1;
            temp = 0;
        }
        i--;
    }

    // Append final 1 if needed
    if(temp == 1){
        result = "1" + result;
    }

    return result;
}

void test_add(){
    std::string res = add("123", "321");
    std::string exp = "444";
    std::cout << "Test 1: " << (exp == res) << std::endl;
    if(exp != res){
        std::cout << "Result: " << res << " Expected: " << exp << std::endl;
    }

    res = add("11", "99");
    exp = "110";
    std::cout << "Test 2: " << (exp == res) << std::endl;
    if(exp != res){
        std::cout << "Result: " << res << " Expected: " << exp << std::endl;
    }

    res = add("9999", "1");
    exp = "10000";
    std::cout << "Test 3: " << (exp == res) << std::endl;
    if(exp != res){
        std::cout << "Result: " << res << " Expected: " << exp << std::endl;
    }
}

int main(){
    test_convertFrac();
    return 0;
}