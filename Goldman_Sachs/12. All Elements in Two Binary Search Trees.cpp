class Solution {
public:
    
    void inorder(TreeNode* root,vector<int> &v)
    {
        if(!root)
            return;
        
        inorder(root->left,v);
        v.push_back(root->val);
        inorder(root->right,v);
    }
    
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        
        vector<int> t1;
        vector<int> t2;
        
        inorder(root1,t1);
        inorder(root2,t2);
        
        vector<int> ans;
        int i=0,j=0;
        
        while(i<t1.size() && j<t2.size())
        {
            if(t1[i]<t2[j])
            {
                ans.push_back(t1[i++]);
            }
            else
            {
                ans.push_back(t2[j++]);
            }
        }
        
        while(j<t2.size())
        {
            ans.push_back(t2[j++]);
        }
        
        while(i<t1.size())
        {
            ans.push_back(t1[i++]);
        }
        return ans;
    }
};