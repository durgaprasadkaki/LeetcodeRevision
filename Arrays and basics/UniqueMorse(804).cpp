/*
804. Unique Morse Code Words
Solved
Easy
Topics
premium lock icon
Companies
International Morse Code defines a standard encoding where each letter is mapped to a series of dots and dashes, 
as follows:

'a' maps to ".-",
'b' maps to "-...",
'c' maps to "-.-.", and so on.
For convenience, the full table for the 26 letters of the English alphabet is given below:

[".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.",
"...","-","..-","...-",".--","-..-","-.--","--.."]
Given an array of strings words where each word can be written as a concatenation of the Morse code of each letter.

For example, "cab" can be written as "-.-..--...", which is the concatenation of "-.-.", ".-", and "-...". 
We will call such a concatenation the transformation of a word.
Return the number of different transformations among all words we have.*/
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        vector<string> morse = {
            ".-","-...","-.-.","-..",".","..-.","--.","....","..",
            ".---","-.-",".-..","--","-.","---",".--.","--.-",".-.",
            "...","-","..-","...-",".--","-..-","-.--","--.."
        };
        
        unordered_set<string> uniqueWords;
        
        for (string word : words) {
            string transformation = "";
            
            for (char c : word) {
                transformation += morse[c - 'a'];
            }
            
            uniqueWords.insert(transformation);
        }
        
        return uniqueWords.size();
    }
};