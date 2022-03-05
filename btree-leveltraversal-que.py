# from https://favtutor.com/blogs/level-order-traversal-python
# To import queue datastructure
import collections
 
# Code to implement a binary tree
class TreeNode: 
     def __init__(self, val):
         self.val = val
         self.left = None
         self.right = None
 
# Function for level Order Traversal
def levelOrderTraversal(root):
    ans = []
 
    # Return Null if the tree is empty
    if root is None:
        return ans
    
    # Initialize queue 
    queue = collections.deque()
    queue.append(root)
 
    # Iterate over the queue until it's empty
    while queue:
        # Check the length of queue
        currSize = len(queue)
        currList = []
 
        while currSize > 0:
            # Dequeue element
            currNode = queue.popleft()
            currList.append(currNode.val)
            currSize -= 1
 
            # Check for left child
            if currNode.left is not None:
                queue.append(currNode.left)
            # Check for right child
            if currNode.right is not None:
                queue.append(currNode.right)
        
        # Append the currList to answer after each iteration
        ans.append(currList)
 
    # Return answer list
    return ans
 
root = TreeNode(1)
root.left = TreeNode(2)
root.right = TreeNode(3)
root.left.left = TreeNode(4)
root.left.right = TreeNode(5)
 
# Check if the algorithm work
print(levelOrderTraversal(root))
