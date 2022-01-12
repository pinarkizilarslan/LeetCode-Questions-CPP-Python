# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def isEvenOddTree(self, root: TreeNode) -> bool:        
        queue = []        
        odd = lambda x: (x % 2 == 1)
        even = lambda x: (x % 2 == 0)        
        levelCount = 0        
        
        if (root):
            queue = [(root)]  
        while (queue):            
            newQueue = []
            temp = None            
            level = False 
            if (even(levelCount)):
                 level = True            
            for idx, node in enumerate(queue):
                if (level and not odd(node.val)):
                    return False                
                if (not level and not even(node.val)):
                    return False
                if (idx == 0):
                    temp= float('inf')
                    if even(levelCount):
                        temp = float('-inf') 
                else:                    
                    if (even(levelCount) and temp >= node.val):
                        return False
                    elif (odd(levelCount) and temp <= node.val):
                        return False                
                temp = node.val
                if (node.left):
                    newQueue.append(node.left)
                if (node.right):
                    newQueue.append(node.right)
            queue = newQueue
            levelCount += 1            
        return True