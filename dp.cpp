#include <iostream>
#include <map>

int main() {
    std::map<int, int> frequencyMap;
    
    // Sample array
    int arr[] = {1, 2, 3, 4, 1, 2, 3, 1, 4, 5};
    int size = sizeof(arr) / sizeof(arr[0]);

    for (int i = 0; i < frequencyMap.size(); ++i) {
        frequencyMap[arr[i]]++;
    }

    // Display the frequency of each element
    std::cout << "Element Frequency" << std::endl;
    for (const auto& entry : frequencyMap) {
        std::cout << entry.first << "\t" << entry.second << std::endl;
    }

    return 0;
}
