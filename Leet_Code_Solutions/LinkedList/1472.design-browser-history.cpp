// struct Node{
//     Node* next;
//     Node* prev;
//     string value;

//     Node(string link){
//         value = link;
//         next = NULL;
//         prev = NULL;
//     }
// };

// class BrowserHistory {

// private:
//     Node* root;
//     Node* curr; // pointing to current page we are in.

// public:
//     BrowserHistory(string homepage) {
//         root = new Node(homepage);
//         // we start at root.
//         curr = root;
//     }

//     void visit(string url) {
//         Node* node = curr;
//         // All forward pages needs to be cleared.
//         if(node->next){
//             Node* temp1 = node->next;
//             while(temp1){
//                 Node* temp2 = temp1;
//                 temp1 = temp1->next;
//                 delete (temp2);

//             }
//         }
//         node->next = new Node(url);
//         // to store the prev for the next url.
//         Node* temp = node;
//         node = node->next;
//         node->prev = temp;
//         curr = node;
//     }

//     string back(int steps) {
//         while(steps-- && curr->prev != NULL){
//             curr = curr->prev;
//         }
//         return curr->value;
//     }

//     string forward(int steps) {
//         while(steps-- && curr->next != NULL){
//             curr = curr->next;
//         }
//         return curr->value;
//     }
// };

// Also be done using two stacks.
// class BrowserHistory {
// private:
//     stack<string> history;
//     stack<string> future;
//     string current; // will hold the current string.
// public:
//     BrowserHistory(string homepage) {
//         history.push(homepage);
//         current = homepage;
//     }

//     void visit(string url) {
//         history.push(url);
//         while(!future.empty()){
//             future.pop();
//         }
//         current = url;
//     }

//     string back(int steps) {
//        // We have to go back which means some urls needs to popped but need not to
//         // be deleted. Therefore,
//         while(history.size() != 1 && steps--){
//             future.push(history.top());
//             history.pop();
//         }
//         current = history.top();
//         return current;
//     }

//     string forward(int steps) {
//         while(!future.empty() && steps--){
//             history.push(future.top());
//             future.pop();
//         }
//         current = history.top();
//         return current;
//     }
// };

// Using dynamic array
class BrowserHistory
{
private:
    vector<string> visitedUrls;
    int currUrl;
    int lastUrl;

public:
    BrowserHistory(string homepage)
    {
        visitedUrls.push_back(homepage);
        currUrl = 0;
        lastUrl = 0;
    }

    void visit(string url)
    {
        currUrl += 1;
        if (visitedUrls.size() > currUrl)
        {
            visitedUrls[currUrl] = url;
        }
        else
        {
            visitedUrls.push_back(url);
        }

        // Now we know that after visting url, this is our new last Url, as
        // given in the questions.
        lastUrl = currUrl;
    }

    string back(int steps)
    {
        // Move currUrl back by 'steps' amount of steps.
        currUrl = max(0, currUrl - steps);
        return visitedUrls[currUrl];
    }

    string forward(int steps)
    {
        // Move currUrl ahead.
        currUrl = min(lastUrl, currUrl + steps);
        return visitedUrls[currUrl];
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */