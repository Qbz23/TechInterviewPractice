// 1.1 Is Unique - pg90

// determine if string has all unique characters
// How to solve if no extra data?

#include "../../Shared/Testing/TestRunner.h"
#include "../CrackingTheCodingInterview.h"
#include <string>
#include <iostream>

 DEF_TESTDATA(IsUniqueData, std::string, bool) 

// O(n)
static bool IsUnique(std::string& s)
{
    const unsigned int kNumAscii = 256;
    bool charFound[kNumAscii] = { false };  
    for(auto it = s.begin(); it != s.end(); ++it)
    {
        if(charFound[*it])
        {
            return false;
        }
        else
        {
            charFound[*it] = true;
        }
    }
    
    return true;
}

// O(n^2)
static bool IsUniqueNoAdditionalData(std::string& s)
{
    for(size_t i = 0; i < s.length(); ++i)
    {
        for(size_t j = i + 1; j < s.length(); ++j)
        {
            if(s[i] == s[j])
            {
                return false;
            }
        }
    }
    
    return true;
}


int Cci::Run_1_1()
{
    const unsigned int kNumTestCases = 5;
    IsUniqueData testCases[kNumTestCases] = {
        {"aabb",        false}, 
        {"abcd",        true},
        {"12ab!5d",     true},
        {"",            true},
        {"abc123!@#a",  false}};
    
    int failedCases = 0;
    // Basic
    failedCases += TestRunner::RunTestCases<std::string, bool, kNumTestCases>(testCases, &IsUnique);
    // No additional data
    failedCases += TestRunner::RunTestCases<std::string, bool, kNumTestCases>(testCases, &IsUniqueNoAdditionalData);

    return failedCases;
}

