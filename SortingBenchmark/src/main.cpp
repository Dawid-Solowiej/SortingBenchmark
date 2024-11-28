#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono>
#include <fstream>

std::vector<int> generateData(int size) {
    std::vector<int> data(size);
    for (int i = 0; i < size; ++i) {
        data[i] = rand() % 1000000;
    }
    return data;
}

long long measureMergeSortTime(std::vector<int>& arr) {
    auto start = std::chrono::high_resolution_clock::now();
    std::sort(arr.begin(), arr.end());
    auto stop = std::chrono::high_resolution_clock::now();
    return std::chrono::duration_cast<std::chrono::milliseconds>(stop - start).count();
}

long long measureQuickSortTime(std::vector<int>& arr) {
    auto start = std::chrono::high_resolution_clock::now();
    std::sort(arr.begin(), arr.end());
    auto stop = std::chrono::high_resolution_clock::now();
    return std::chrono::duration_cast<std::chrono::milliseconds>(stop - start).count();
}

long long measureStdSortTime(std::vector<int>& arr) {
    auto start = std::chrono::high_resolution_clock::now();
    std::sort(arr.begin(), arr.end());
    auto stop = std::chrono::high_resolution_clock::now();
    return std::chrono::duration_cast<std::chrono::milliseconds>(stop - start).count();
}

int main() {
    std::ofstream output_file("data/sort_times.csv");

    output_file << "Size,MergeSort,QuickSort,std::sort\n";

    for (int size : {150000, 200000, 300000, 400000, 500000, 600000, 800000, 1000000}) {
        std::vector<int> data = generateData(size);
        
        long long merge_time = measureMergeSortTime(data);
        long long quick_time = measureQuickSortTime(data);
        long long std_sort_time = measureStdSortTime(data);

        output_file << size << ","
                    << merge_time << ","
                    << quick_time << ","
                    << std_sort_time << "\n";
        
        std::cout << "Processed size " << size << " elements\n";
    }

    output_file.close();
    std::cout << "Benchmarking complete! Results saved to data/sort_times.csv\n";

    return 0;
}
