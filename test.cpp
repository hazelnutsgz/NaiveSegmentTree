#include "segment_tree.h"
#include <iostream>
#include <vector>
using namespace std;


int main(int argc, char const *argv[]){
	vector<int> nums;
	for (int i = 1; i <= 9; i++)
		nums.push_back(i);

	SegmentTree segTree(nums);
	// cout << segTree.sumRange(1,4);
	return 0;
} 