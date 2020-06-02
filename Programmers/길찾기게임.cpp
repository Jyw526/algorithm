#include <string>
#include <vector>
#include <algorithm>
using namespace std;

struct Node {
    int idx, x, y;
    struct Node* p;
    struct Node* left, *right;
};
vector<int> pre;
vector<int> post;
void preorder(Node *root) {
    if (root) {
        pre.push_back(root->idx);
        preorder(root->left);
        preorder(root->right);
    }
}
void postorder(Node* root) {
    if (root) {
        postorder(root->left);
        postorder(root->right);
        post.push_back(root->idx);
    }
}
bool cmp(vector<int> v1, vector<int> v2) {
    if (v1[1] == v2[1])
        return v1[0] < v2[0];
    else
        return v1[1] > v2[1];
;}

vector<vector<int>> solution(vector<vector<int>> nodeinfo) {
   vector<vector<int>> answer;
    
    for (int i = 0; i < nodeinfo.size(); i++) {
        nodeinfo[i].push_back(i + 1);
    }
    sort(nodeinfo.begin(), nodeinfo.end(), cmp);
    Node root = { nodeinfo[0][2], nodeinfo[0][0], nodeinfo[0][1], NULL ,NULL };
    Node* parent;
    for (int i = 1; i < nodeinfo.size(); i++) {
        parent = &root;
        while (1) {
            if (nodeinfo[i][0] < parent->x) {
                if (parent->left == NULL) {
                    parent->left = new Node{ nodeinfo[i][2], nodeinfo[i][0], nodeinfo[i][1], NULL, NULL };
                    break;
                }
                else {
                    parent = parent->left;
                }
            }
            else {
                if (parent->right == NULL) {
                    parent->right = new Node{ nodeinfo[i][2], nodeinfo[i][0], nodeinfo[i][1], NULL, NULL };
                    break;
                }
                else {
                    parent = parent->right;
                }
            }
        }
    }
    preorder(&root);
    postorder(&root);
    answer.push_back(pre);
    answer.push_back(post);
    return answer;
}