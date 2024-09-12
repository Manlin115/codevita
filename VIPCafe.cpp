#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N;
    cin >> N;
    
    vector<int> priorities(N);
    for (int i = 0; i < N; ++i) {
        cin >> priorities[i];
    }
    
    int K;
    cin >> K;
    --K; 
    
    vector<int> original_priorities = priorities;
    int serve_count = 0;
    
    while (true) {
        // Find the index of the order with the highest priority
        int max_priority = *max_element(priorities.begin(), priorities.end());
        int index_to_serve = -1;
        
        for (int i = 0; i < N; ++i) {
            if (priorities[i] == max_priority) {
                index_to_serve = i;
                break;
            }
        }
        
        // Serve this order
        serve_count++;
        
        if (index_to_serve == K) {
            cout << serve_count << endl;
            return 0;
        }
        
        // Increment priority of orders before the served order
        for (int i = 0; i < index_to_serve; ++i) {
            priorities[i]++;
        }
        
        // Mark the served order as served
        priorities[index_to_serve] = -1;
    }
    
    return 0;
}
