#include "segment_tree.h"

SegmentTree::SegmentTree(vector<int> nums) {
    size = nums.size();
    if (size == 0) return;
    tree.resize(size * 4);
    buildTree(nums, 0, 0, size - 1);
}

void SegmentTree::buildTree(vector<int>& nums, int treeIndex, int left, int right) {

    if (left == right) { tree[treeIndex] = nums[left]; return;}
    int mid = (right - left) / 2 + left;
    buildTree(nums, treeIndex * 2 + 1, left, mid);
    buildTree(nums, treeIndex * 2 + 2, mid + 1, right);
    tree[treeIndex] = \
        tree[treeIndex * 2 + 1] + tree[treeIndex * 2 + 2];
    
    return;
}

void SegmentTree::update(int i, int val) {
    updateST(i, val, 0, size - 1, 0);
}

void SegmentTree::updateST(int index, int val, int left, int right, int treeIndex) {
    if (left == right) {tree[treeIndex] = val; return;}
    
    int mid = left + (right - left) / 2;
    if (index > mid) 
        updateST(index, val, mid + 1, 
                    right, treeIndex * 2 + 2);
    else 
        updateST(index, val, left,
                    mid, treeIndex * 2 + 1);
    
    tree[treeIndex] = \
            tree[treeIndex * 2 + 1] + tree[treeIndex * 2 + 2];
    
    return;
}

int SegmentTree::sumRange(int i, int j) {

    int ret = sumRangeST(i, j, 0, 0, size - 1);
    return ret;

}

int SegmentTree::sumRangeST(int targetLeft, int targetRight, int treeIndex, int currentLeft, int currentRight) {

    if (targetLeft == currentLeft 
            && targetRight == currentRight)
        return tree[treeIndex];
    
    int mid = currentLeft + (currentRight - currentLeft) / 2;
    
    int left = 0;
    int right = 0;
    
    if (targetLeft <= mid) 
        left = sumRangeST(targetLeft, 
            min(targetRight, mid), treeIndex * 2 + 1, currentLeft, mid);

    if (targetRight >= mid + 1) 
        right = sumRangeST(max(mid + 1, targetLeft), 
            targetRight, treeIndex * 2 + 2, mid + 1, currentRight);

    return left + right;
}
