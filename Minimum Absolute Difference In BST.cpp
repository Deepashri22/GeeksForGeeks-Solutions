//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Node
{
  int data;
  struct Node *left;
  struct Node *right;
};
// Utility function to create a new Tree Node
Node *newNode(int val)
{
  Node *temp = new Node;
  temp->data = val;
  temp->left = NULL;
  temp->right = NULL;

  return temp;
}
// Function to Build Tree
Node *buildTree(string str)
{
  // Corner Case
  if (str.length() == 0 || str[0] == 'N')
    return NULL;

  // Creating vector of strings from input
  // string after spliting by space
  vector<string> ip;

  istringstream iss(str);
  for (string str; iss >> str;)
    ip.push_back(str);

  // Create the root of the tree
  Node *root = newNode(stoi(ip[0]));

  // Push the root to the queue
  queue<Node *> queue;
  queue.push(root);

  // Starting from the second element
  int i = 1;
  while (!queue.empty() && i < ip.size())
  {

    // Get and remove the front of the queue
    Node *currNode = queue.front();
    queue.pop();

    // Get the current node's value from the string
    string currVal = ip[i];

    // If the left child is not null
    if (currVal != "N")
    {

      // Create the left child for the current node
      currNode->left = newNode(stoi(currVal));

      // Push it to the queue
      queue.push(currNode->left);
    }

    // For the right child
    i++;
    if (i >= ip.size())
      break;
    currVal = ip[i];

    // If the right child is not null
    if (currVal != "N")
    {

      // Create the right child for the current node
      currNode->right = newNode(stoi(currVal));

      // Push it to the queue
      queue.push(currNode->right);
    }
    i++;
  }

  return root;
}


// } Driver Code Ends
/*The Node structure is defined as
struct Node {
    int data;
    Node *left;
    Node *right;

};
*/

class Solution
{
    public:
    void left_max(Node *root,int &m){
        if(root==NULL){
            return;
        }
        m=max(m,root->data);
        left_max(root->left,m);
        left_max(root->right,m);
    }
    void right_min(Node *root,int &m){
        if(root==NULL){
            return ;
        }
        m=min(m,root->data);
        right_min(root->left,m);
        right_min(root->right,m);
    }
    void inord(Node *root,int &m){
        if(root==NULL){
            return ;
        }
        int lmax=0,rmin=0;
        if(root->left!=NULL){
            int leftmax1=INT_MIN;
            left_max(root->left,leftmax1);
            //cout<<leftmax1<<" ";
            lmax=abs(root->data-leftmax1);
            m=min(m,lmax);
        }
        if(root->right!=NULL){
            int rightmax1=INT_MAX;
            right_min(root->right,rightmax1);
            //cout<<rightmax1<<" ";
            rmin=abs(root->data-rightmax1);
            m=min(m,rmin);
        }
        inord(root->left,m);
        inord(root->right,m);
    }
    int absolute_diff(Node *root)
    {
        //Your code here
        int m=INT_MAX;
        inord(root,m);
        return m;
    }
};


//{ Driver Code Starts.

int main()
{

  int t;
  scanf("%d ", &t);
  while (t--)
  {
    string s;
    getline(cin, s);
    Node *root = buildTree(s);
    // getline(cin, s);
    if (root == NULL)
      continue;
    if (root->left == NULL and root->right == NULL)
      continue;
      Solution ob;
    cout << ob.absolute_diff(root) << '\n';
    // cout << s << '\n';
  }
  return 1;
}
// } Driver Code Ends
