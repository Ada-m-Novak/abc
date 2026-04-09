#include <string>
#include <iostream>
struct Node
{
    int value;
    Node *left;
    Node *right;

    Node(int key) : value(key), left(nullptr), right(nullptr) {}
};

class BST
{
private:
    Node *root;
    void destroy(Node *node)
    {
        if (node == nullptr)
        {
            return;
        }
        destroy(node->left);
        destroy(node->right);
    }
    Node *insert(Node *node, int key)
    {
        if (node == nullptr)
        {
            return new Node(key);
        }
        if (key < node->value)
        {
            node->left = insert(node->left, key);
        }
        else if (key > node->value)
        {
            node->right = insert(node->right, key);
        }
    }
    bool find(Node *node, int key)
    {
        if (node == nullptr)
        {
            return 0;
        }
        if (key < node->value)
        {
            return find(node->left, key);
        }
        else if (key > node->value)
        {
            return find(node->right, key);
        }
        else if (key == node->value)
        {
            return true;
        }
    }
    void inorderpass(Node*node){
        if (node==nullptr)
        {
            return;
        }
        inorderpass(node->left);
        std::cout<<node->value<<" ";
        inorderpass(node->right);
    }
    void serialize(Node *node, std::string &res)
    {
        if (node==nullptr)
        {
            return;
        }
        res+=std::to_string(node->value);
        res+="(";
        serialize(node->left,res);
        res+=")";
        res+="(";
        serialize(node->right,res);
        res+=")";
    }

public:
    BST()
    {
        root = nullptr;
    }
    ~BST()
    {
        destroy(root);
    }

    void insert(int key)
    {
        root = insert(root, key);
    }

};
