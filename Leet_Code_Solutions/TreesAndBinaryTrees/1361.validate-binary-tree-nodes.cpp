class unionFind
{
public:
    int components;
    int n;
    vector<int> parent;

    unionFind(int n)
    {
        this->n = n;
        parent = vector(n, 0);
        components = n;

        for (int i = 0; i < n; i++)
        {
            parent[i] = i;
        }
    }

    // joining of two subsets.
    // Return true if the union is successful.
    // or else return false.

    // If parent of child is not child, which means we would have assigned the
    // child to some parent already and now we are assigning it to some other parent.
    // parent(child) != child.

    // To check a cycle : parent(parent) == parent(child), then
    bool join(int parent, int child)
    {
        int parentParent = find(parent);
        int childParent = find(child);

        if (childParent != child || parentParent == childParent)
        {
            return false;
        }

        components--; // Number of components decrease.

        this->parent[childParent] = parentParent;
        return true;
    }

    int find(int node)
    {
        if (parent[node] != node)
        {
            parent[node] = find(parent[node]);
        }

        return parent[node];
    }
};

class Solution
{
public:
    bool validateBinaryTreeNodes(int n, vector<int> &leftChild, vector<int> &rightChild)
    {
        // Using DFS.
        // How to validate a binary tree.
        // 1) Root has no parent(One root is present)-> We check the leftChild and
        // rightChild array. The node not present in left and right array is the Root.
        // 2) There should be no cycle -> We create a seen map. If we encounter the same
        // node again we return false.
        // 3) A node has only one parent -> This can also be handled by the seen map.
        // Because we would see the same node twice by either parent.
        // 4) Tree must be connected -> If the seen length is equal to n. Then it
        // indicates the tree is connected.
        // Other Scenario's -> If there are multiple roots, then this is implictly
        // handled by the fourth point. If multiple root are present then the seen
        // length will always be less than n. So checking for a single root is enough.

        // int root = findRoot(leftChild, rightChild, n);
        // if(root == -1){
        //     return false;
        // }

        // unordered_set<int> seen; // To verify whether the node is already visited or not.
        // stack<int> stack;
        // stack.push(root);
        // seen.insert(root);

        // while(!stack.empty()){
        //     int node = stack.top();
        //     stack.pop();

        //     int children[] = {leftChild[node], rightChild[node]};
        //     for(int child : children){
        //         if(child != -1){
        //             // There is a cycle or a node has two parents.
        //             if(seen.find(child) != seen.end()){
        //                 return false;
        //             }

        //             seen.insert(child);
        //             stack.push(child);
        //         }
        //     }
        // }

        // // If the tree is connected then for the current root,
        // // seen.length == n.

        // return (seen.size() == n);

        // 2) Using BFS, instead of stack we use a queue.
        // We push the upcoming states of the next level in the queue.

        // 3) Using Union find.
        unionFind uf(n);

        // We don't have to think about the root.
        // As there is only one root at the top for union Find data Structure.

        for (int node = 0; node < n; node++)
        {
            int children[] = {leftChild[node], rightChild[node]};
            for (auto child : children)
            {
                if (child == -1)
                {
                    continue;
                }

                // While joining we check two simultaneous things at the same time.
                // 1) If there exists a cycle.
                // 2) If the current node is containing more that one parent.
                if (!uf.join(node, child))
                {
                    return false;
                }
            }
        }

        return (uf.components == 1);
    }

    int findRoot(vector<int> &leftChild, vector<int> &rightChild, int n)
    {
        unordered_set<int> children;
        children.insert(leftChild.begin(), leftChild.end());
        children.insert(rightChild.begin(), rightChild.end());

        for (int i = 0; i < n; i++)
        {
            // Checking for probable root node.
            if (children.find(i) == children.end())
            {
                return i;
            }
        }
        // No root node found.
        return -1;
    }
};