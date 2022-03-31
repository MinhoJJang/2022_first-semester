#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <stdbool.h>

typedef struct NODE
{
    int key;
    struct NODE *parent;
    struct NODE *left;
    struct NODE *right;
} NODE;

NODE *getNewNode(int val)
{
    NODE *newNode = (NODE *)malloc(sizeof(NODE));
    newNode->key = val;
    newNode->parent = NULL;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
};

typedef struct TREE
{
    NODE *root;
} TREE;

void set_left_child(NODE *parent, NODE *child)
{
    child->parent = parent;
    parent->left = child;
}
void set_right_child(NODE *parent, NODE *child)
{
    child->parent = parent;
    parent->right = child;
}
void Preorder_Traversal(NODE *node)
{
    if (node != NULL)
    {
        printf("[%d] \n", node->key);
        Preorder_Traversal(node->left);
        Preorder_Traversal(node->right);
    }
}
void print_tree(TREE *tree)
{
    printf("--Print tree in preorder: \n");
    Preorder_Traversal(tree->root);
    printf("\n");
}
// --- Similar to Preorder Traversal !
bool search_key(const int key, NODE *node, int level)
{
    /*
        Tree의 root부터 시작하여, root 키 값과 변수로 들어온 key 값을 비교한다. 이때, 변수로 들어온 key 값이 같을 경우는 바로 함수를 끝낸다. 만약 클 경우는 root->right, 작을 경우는 root->left로 해주고 level 을 1증가시켜준다.

        만약, root->left 혹은 root->right가 존재하지 않는다면, false를 리턴하면 된다.
    */
    if (level == 1)
    {
        printf("\n//--- Search for the key(%d) in the tree...\n", key);
    }

    if (key == node->key)
    {
        foundKey(key, level);
        return true;
    }
    else if (key > node->key)
    {
        searchingLog(key, node, level);
        if (node->right == NULL)
        {
            notFoundKey(key, level);
            return false;
        }
        else
        {
            level++;
            search_key(key, node->right, level);
        }
    }
    else if (key < node->key)
    {
        searchingLog(key, node, level);
        if (node->left == NULL)
        {
            notFoundKey(key, level);
            return false;
        }
        else
        {
            level++;
            search_key(key, node->left, level);
        }
    }
}

void searchingLog(const int key, NODE *node, int level)
{
    int parentKey = node->key;
    if (key < parentKey)
    {
        printf("L(%d): The key(%d) < node(%d) --> left node\n", level, key, parentKey);
    }
    else if (key > parentKey)
    {
        printf("L(%d): The key(%d) > node(%d) --> right node\n", level, key, parentKey);
    }
}

void foundKey(int key, int level)
{
    printf("L(%d): The key(%d) is found in the tree!\n", level, key);
}

void notFoundKey(int key, int level)
{
    printf("L(%d): The key(%d) does not exist in the tree!\n\n", level, key);
}

int main()
{
    // --- Constructing the (Ordered) Binary Search Tree in the slide.
    TREE Tree;
    Tree.root = getNewNode(100);
    set_left_child(Tree.root, getNewNode(75));
    set_right_child(Tree.root, getNewNode(150));
    set_left_child(Tree.root->left, getNewNode(50));
    set_right_child(Tree.root->left, getNewNode(90));
    set_left_child(Tree.root->right, getNewNode(120));
    set_right_child(Tree.root->right, getNewNode(490));
    set_left_child(Tree.root->right->right, getNewNode(160));
    print_tree(&Tree); // print tree structure
    search_key(120, Tree.root, 1);
    search_key(400, Tree.root, 1);
    return 0;
}
