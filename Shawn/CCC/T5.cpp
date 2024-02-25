#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

// Function to find the greatest common divisor
int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}

// Main solution function
int maxConnectedParts(const vector<int>& topRow, const vector<int>& bottomRow) {
    int N = topRow.size();
    int totalSum = accumulate(topRow.begin(), topRow.end(), 0) + accumulate(bottomRow.begin(), bottomRow.end(), 0);
    int maxParts = 1; // At least the whole chocolate bar is one part

    for (int parts = 2; parts <= N; ++parts) {
        if ((totalSum % parts) == 0) {
            int partSum = totalSum / parts;
            int currentSum = 0;
            bool canPartition = true;

            // Iterate over each square to check if we can form 'parts' with equal sum
            for (int i = 0; i < N && canPartition; ++i) {
                currentSum += topRow[i] + bottomRow[i];
                if (currentSum > partSum) {
                    canPartition = false; // Cannot partition if any part exceeds the required sum
                    break;
                } else if (currentSum == partSum) {
                    currentSum = 0; // Reset for the next part
                }
            }

            if (canPartition && currentSum == 0) { // Check if we successfully partitioned the whole bar
                maxParts = max(maxParts, parts);
            }
        }
    }

    return maxParts;
}

int main() {
    int N;
    cin >> N;

    vector<int> topRow(N), bottomRow(N);
    for (int i = 0; i < N; ++i) cin >> topRow[i];
    for (int i = 0; i < N; ++i) cin >> bottomRow[i];

    cout << maxConnectedParts(topRow, bottomRow) << endl;

    return 0;
}