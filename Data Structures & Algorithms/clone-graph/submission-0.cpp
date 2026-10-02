/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    unordered_map<Node*, Node*> mp;
    Node* cloneGraph(Node* node) {
        if(!node)
        return mp[node] = NULL;

        Node* copy = new Node();
        mp[node] = copy;
        copy->val = node->val;
        for(Node* n: node->neighbors){
            if(mp[n]){
                copy->neighbors.push_back(mp[n]);
            }
            else
            copy->neighbors.push_back(cloneGraph(n));
        }

        return copy;
    }
};
