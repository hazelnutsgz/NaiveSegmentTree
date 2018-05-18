import math

class Node:

    def __init__(self, left, right, value):
        self.value = value
        self.left = left
        self.right = right
        self.lazy = False

class MinSegmentTree:

    def __init__(self, array, func):
        self.lens = len(array)
        self.nodes_list = [Node(-1,-1,-1) for _ in range((self.lens)*3)]
        self.func = func
        self._init(0, 0, self.lens-1, array)
        
    
    def _init(self, index, left, right, array):

        value = None
        if left == right:
            value = array[left]
            if left == self.lens-1:
                self.max_index = index
        else:
            mid = int((left + right) / 2)
            left_value = self._init(2*index+1, left, mid, array)
            right_value = self._init(2*index+2, mid+1, right, array)
            value = self.func((left_value, right_value))
        
        self.nodes_list[index].left = left
        self.nodes_list[index].right = right
        self.nodes_list[index].value = value    
        return value
    
    def query(self, left, right):
        return self._query(0, left, right)

    def _query(self, index, left, right):
        if index < 0 or left < 0 or right >= self.lens or left > right:
            return False
        node = self.nodes_list[index]
        if node.left == node.right:
            return node.value

        candidates = []
        left_node = None
        right_node = None
        if 2*index+1 <= self.max_index:
            left_node = self.nodes_list[2*index+1]
        if 2*index+2 <= self.max_index:
            right_node = self.nodes_list[2*index+2]

        if left_node and left <= left_node.right:
            candidates.append(self._query(2*index+1, left, right))
        if right_node and right >= right_node.left:
            candidates.append(self._query(2*index+2, left, right))
        
        return self.func(candidates)

    def update_batch(self, left, right, func):
        self._update_batch(0, left, right, func)

    def _update_batch(self, index, left, right, func):
        node = self.nodes_list[index]
        

    def update_one(self, position, value):
        self._update_one(0, position, value)

    def _update_one(self, index, position, value):
        node = self.nodes_list[index]
        ##Single Case
        if node.left == node.right:
            node.value = value
            return

        # if value < node.value:
        #     node.value = value
        left_node, right_node = None, None
        if 2*index+1 <= self.max_index:
            left_node = self.nodes_list[2*index+1]
            if left_node.left <= position and position <= left_node.right:
                self._update(2*index+1, position, value)

        if 2*index+2 <= self.max_index:
            right_node = self.nodes_list[2*index+1]
            if right_node.left <= position and position <= right_node.right:
                self._update(2*index+2, position, value)

        if not left_node:
            left_value = 0
        else:
            left_value = left_node.value
        if not right_node:
            right_value = 0
        else:
            right_value = right_node.value

        node.value = self.func((left_value, right_value)) 

if __name__ == '__main__':
    s = [2, 10, 3, 6]
    LLL = MinSegmentTree(s, sum)
    import pdb; pdb.set_trace()