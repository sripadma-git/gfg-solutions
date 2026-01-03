Node* mergeTwoLists(Node* a, Node* b) {
    // base cases
    if (!a) return b;
    if (!b) return a;

    Node* result;

    if (a->data < b->data) {
        result = a;
        result->bottom = mergeTwoLists(a->bottom, b);
    } else {
        result = b;
        result->bottom = mergeTwoLists(a, b->bottom);
    }

    result->next = NULL; // next must be NULL in flattened list
    return result;
}

class Solution {
public:
    Node *flatten(Node *root) {
        // base case
        if (!root || !root->next)
            return root;

        // recursively flatten the right list
        root->next = flatten(root->next);

        // merge current list with the right list
        root = mergeTwoLists(root, root->next);

        return root;
    }
};
