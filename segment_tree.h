#ifndef SEGMENT_TREE_H
#define SEGMENT_TREE_H

class SegmentTree {
private:
    vector<int> tree;
    int size;
public:
    SegmentTree(vector<int> nums);
    
    void buildTree(vector<int>& nums, int treeIndex, int left, int right);
    
    void update(int i, int val);
    
    void updateST(int index, int val, int left, int right, int treeIndex);
    
    int sumRange(int i, int j);
    
    int sumRangeST(int targetLeft, int targetRight, int treeIndex, int currentLeft, int currentRight);
};
#endif // SEGMENT_TREE_H
