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

void tree_init(TREE *tree)
{
    tree->root = NULL;
}

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

// 아래 search_key 에서 parentKey를 저장하기 위해, 전역변수로 만들었다.
NODE *parentKey;

// --- Similar to Preorder Traversal !
bool search_key(const int key, NODE *node, int level)
{

    // 예외상황: 처음 search를 실행할 경우
    if (level == 1)
    {
        printf("//--- Search for the key(%d) in the tree...\n", key);
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
            parentKey = node;
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
            parentKey = node;
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

NODE *find_insert_loc(const int key, NODE *node)
{
    /*
        숫자를 삽입할 위치를 찾으면 된다. 삽입이 가능하다는 것은 그 숫자를 찾지 못했다는 의미이다. 즉, search_key를 통해 그 값이 false를 리턴했을 경우를 의미한다. false를 리턴할 당시, search_key에서 argument값으로 들어간 node는 지금 당장 삽입할 노드의 부모가 된다. 따라서 그 argument 값을 저장해놓고 find_insert_loc 에서 리턴해주면 된다.
    */
    return parentKey;
}

void insert_key(const int key, TREE *tree)
{

    // 만약 insert를 하려는데 tree->root 값이 NULL 이라면? search를 들어갈 이유가 없다.
    // 예외상황: 루트노드가 없을 경우
    if (tree->root == NULL)
    {
        tree->root = getNewNode(key);
        printf("//--- Search for the key(%d) in the tree...\n", key);
        notFoundKey(key, 0);
        return;
    }

    // 이미 여기에서 search를 수행했다. 따라서 아래에서 한번 더 수행할 필요가 없다.
    if (search_key(key, tree->root, 1))
    {
        printf("(Insert Failed): The key(%d) already exists..\n", key);
        return;
    }

    // loc는 현재 부모가 될 노드이다.
    NODE *loc = find_insert_loc(key, tree->root);

    // 부모노드와 자식노드간 값을 비교한다.

    char direction[10];

    if (loc->key > key)
    {
        strcpy(direction, "LEFT");
        set_left_child(loc, getNewNode(key));
    }
    else
    {
        strcpy(direction, "RIGHT");
        set_right_child(loc, getNewNode(key));
    }

    printf("-- The key(%d) is inserted as the [%s] child of node(%d)\n", key, direction, loc->key);
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
    printf("L(%d): The key(%d) does not exist in the tree!\n", level, key);
}

int main()
{
    // --- Constructing the (Ordered) Binary Search Tree in the slide.
    TREE Tree;

    tree_init(&Tree);

    insert_key(100, &Tree);
    insert_key(75, &Tree);
    insert_key(150, &Tree);
    insert_key(50, &Tree);
    insert_key(90, &Tree);
    insert_key(120, &Tree);
    insert_key(490, &Tree);
    insert_key(160, &Tree);
    print_tree(&Tree); // print tree structure
    // you should get the same results with the previous version
    search_key(120, Tree.root, 1);
    search_key(400, Tree.root, 1);
    // check the insertion result.
    insert_key(80, &Tree);
    print_tree(&Tree);
    return 0;
}