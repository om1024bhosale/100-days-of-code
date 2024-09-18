/*
Approach
Convert Integers to Strings: Since comparing individual digits of integers won't work directly for concatenation, first convert the integer array into an array of strings. This allows us to concatenate and compare the results of a + b and b + a.

Custom Sorting: Use a custom comparator to sort the string array. The comparator should compare two strings a and b by checking the results of a + b vs b + a. If a + b is larger, then a should come before b in the sorted array.

Edge Case: After sorting, if the largest number is "0" (i.e., if the first element in the sorted array is "0"), return "0", since this means all numbers were zeros.

Construct the Result: Use a StringBuilder to concatenate all the strings in the sorted array into the final result.

*/

class Solution {
public:
    string largestNumber(vector<int>& nums) {
        // Convert integers to strings
        vector<string> arr;
        for (int num : nums) {
            arr.push_back(to_string(num));
        }

        // Custom comparator for sorting
        sort(arr.begin(), arr.end(), [](const string &a, const string &b) {
            return (b + a) < (a + b);
        });

        // Handle the case where the largest number is "0"
        if (arr[0] == "0") {
            return "0";
        }

        // Build the largest number from the sorted array
        string largest;
        for (const string &num : arr) {
            largest += num;
        }

        return largest;
    }
};
