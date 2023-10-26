#include <iostream>
#include <vector>
using namespace std;
int findFloor(const vector<int>& nums, int target) {
    int low = 0, high = nums.size() - 1;
    int floor = -1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (nums[mid] == target)
            return nums[mid];
        else if (nums[mid] < target) {
            floor = nums[mid];
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return floor;
}
int findCeiling(const vector<int>& nums, int target) {
    int low = 0, high = nums.size() - 1;
    int ceiling = -1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (nums[mid] == target)
            return nums[mid];
        else if (nums[mid] > target) {
            ceiling = nums[mid];
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return ceiling;
}
int findPeak(const vector<int>& nums) {
    int low = 0, high = nums.size() - 1;
    while (low < high) {
        int mid = low + (high - low) / 2;
        if (nums[mid] > nums[mid + 1])
            return nums[mid];
        if (nums[mid] < nums[mid + 1])
            low = mid + 1;
    }
    return nums[low];
}
int findMinimum(const vector<int>& nums) {
    int low = 0, high = nums.size() - 1;
    while (low < high) {
        int mid = low + (high - low) / 2;
        if (nums[mid] > nums[high])
            low = mid + 1;
        else if (nums[mid] < nums[high])
            high = mid;
    }
    return nums[low];
}
int main() {
    vector<int> nums = {4, 5, 6, 7, 0, 1, 2};
    int target = 3;
    int floor = findFloor(nums, target);
    int ceiling = findCeiling(nums, target);
    int peak = findPeak(nums);
    int minimum = findMinimum(nums);
    cout << "Floor of " << target << " is: " << floor << endl;
    cout << "Ceiling of " << target << " is: " << ceiling << endl;
    cout << "Peak element in the rotated array is: " << peak << endl;
    cout << "Minimum element in the rotated array is: " << minimum << endl;
    return 0;
}
