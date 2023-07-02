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

class Solution
{
public:
    Node *cloneGraph(Node *node)
    {
        if (node == NULL)
        {
            return NULL;
        }
        // If there exists one node with zero neighbours.
        if ((node->neighbors).size() == 0)
        {
            Node *clone = new Node(node->val);

            return clone;
        }

        // map stores the reference of (reference of the original node) to the (reference of the cloned node).
        map<Node *, Node *> mp;

        return dfs(node, mp);
    }

    Node *dfs(Node *node, map<Node *, Node *> &mp)
    {
        Node *clone = new Node(node->val);
        mp[node] = clone;
        vector<Node *> neighbour;
        for (int i = 0; i < node->neighbors.size(); i++)
        {
            Node *curr = node->neighbors[i];
            if (mp.find(curr) == mp.end())
            {
                neighbour.push_back(dfs(curr, mp));
            }
            else
            {
                neighbour.push_back(mp[curr]);
            }
        }

        clone->neighbors = neighbour;
        return clone;
    }
};