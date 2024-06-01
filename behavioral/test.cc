// #include <iostream>
// #include <vector>
// #include <string>

// using namespace std;

// int main(){
//     string s = "abaa";
//     vector<int> dp(s.size(), 0);

// // traverse from the end of the string
// for(int i = s.size() - 2; i>=0; i--){
//     cout << s[i] << endl;
//     // check if this character should be changed : 
//     if((s[i + 1] - s[i] == 1) || (s[i] == s[i + 1])){
//         // change only its next element has not already marked to change
//         // logic : abdde 
//         //           i  <- this d need not change because changing next d can alredy
//         //                 solve the problem
//         if(dp[i + 1] != 1) dp[i] = 1;
//     }
// }

//     int count = 0;
//     cout << "dp matrix is " << endl;
//     for(int& e : dp){
//         cout << e << endl;
//         if(e) count++;
//     }

//     cout << "count is " << count << endl;

// return 0;
// }

#include <iostream>
#include <vector>
#include <algorithm> // For swap

void recoverArray(std::vector<int>& arr) {
    int n = arr.size();
    int first = -1, second = -1;

    // Traverse the array to find the first and second elements that are out of order
    for (int i = 0; i < n - 1; ++i) {
        if (arr[i] > arr[i + 1]) {
            if (first == -1) {
                first = i;
            }
            second = i + 1;
        }
    }

    // Swap the two elements to recover the sorted array
    if (first != -1 && second != -1) {
        std::swap(arr[first], arr[second]);
    }
}

int main() {
    std::vector<int> arr = {1, 3, 2, 4};
    recoverArray(arr);

    // Output the recovered array
    for (int num : arr) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}
