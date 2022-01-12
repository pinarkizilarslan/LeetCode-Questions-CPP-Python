/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution
{
public:
    void get_data(bool &result, TreeNode* node, vector<int> &array, int level){
        if(node==NULL){
            return;
        }
        if(level%2==0 && (node->val)%2==0){
            result=false;
            return;
        }
        if(level%2!=0 && (node->val)%2!=0){
            result=false;
            return;
        }
        if(level==array.size()){
            array.push_back(node->val);
        }
        else if(level%2==0){
            if(array[level]>=node->val){
                result=false;
                return;
            }
            array[level]=node->val;
        }
        else if (level %2 !=0){
            if(array[level]<=node->val){
                result=false;
                return;
            }
            array[level]=node->val;
        }
        get_data(result, node->left, array, level+1);
        get_data(result, node->right, array, level+1);        
    }
    bool isEvenOddTree(TreeNode* root) {
        vector<int> array;
        bool result=true;
        get_data(result, root, array, 0);
        return result;    
    }
};