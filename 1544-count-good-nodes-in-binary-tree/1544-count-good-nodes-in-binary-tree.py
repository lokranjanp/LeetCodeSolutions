# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    


    def goodNodes(self, root: TreeNode) -> int:
        def helper(root, count, maxval):
            if root.val >= maxval:
                count += 1

            if root.left:
                count = helper(root.left, count, max(root.val, maxval))

            if root.right:
                count = helper(root.right, count, max(root.val, maxval))

            return count

        return helper(root, 0, root.val)
            