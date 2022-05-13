#include <iostream>
#include <vector>

#define TL 0    // top left
#define TR 1    // top right
#define BR 2    // bottom right
#define BL 3    // bottom left

struct Point{
    int x;
    int y;

    Point() : x(-1), y(-1) {}

    Point(int a, int b) : x(a), y(b) {}
};

class QuadTree{
    // if point == NULL, node is regional.
    // if point == (-1, -1), node is empty.
    Point *point;

    Point *top_left, *bottom_right;   // represents the space.
    std::vector<QuadTree *> children;
    
public:
    QuadTree(){
        // to declare empty node
        point = new Point();
    }

    QuadTree(int x, int y){
        // to declare point node
        point = new Point(x, y);
    }

    QuadTree(int x1, int y1, int x2, int y2){
        if(x2 < x1 || y2 < y1)
            return;
        point = nullptr;
        top_left = new Point(x1, y1);
        bottom_right = new Point(x2, y2);
        children.assign(4, nullptr);
        for(int i = TL; i <= BL; ++i)
            children[i] = new QuadTree();
    }

    void insert(int x, int y){
        if(x < top_left->x || x > bottom_right->x
            || y < top_left->y || y > bottom_right->y)
            return;
        int midx = (top_left->x + bottom_right->x) >> 1,
            midy = (top_left->y + bottom_right->y) >> 1;
        int pos = -1;
        if(x <= midx){
            if(y <= midy)
                pos = TL;
            else
                pos = BL;
        }
        else{
            if(y <= midy)
                pos = TR;
            else
                pos = BR;
        }

        if(children[pos]->point == nullptr){
           // if region node
            children[pos]->insert(x, y);
            return;
        }
        else if(children[pos]->point->x == -1){
            // if empty node
            delete children[pos];
            children[pos] = new QuadTree(x, y);
            return;
        }
        else{
            int x_ = children[pos]->point->x,
                y_ = children[pos]->point->y;
            delete children[pos];
            children[pos] = nullptr;
            if(pos == TL){
                children[pos] = new QuadTree(top_left->x, top_left->y,
                                        midx, midy);
            }
            else if(pos == TR){
                children[pos] = new QuadTree(midx + 1, top_left->y,
                                        bottom_right->x, midy);
            }
            else if(pos == BR){
                children[pos] = new QuadTree(midx + 1, midy + 1,
                                        bottom_right->x, bottom_right->y);
            }
            else{
                children[pos] = new QuadTree(top_left->x, midy + 1,
                                        midx, bottom_right->y);
            }
            children[pos]->insert(x_, y_);
            children[pos]->insert(x, y);
        }
    }
    
    bool find(int x, int y){
        if(x < top_left->x || x > bottom_right->x
            || y < top_left->y || y > bottom_right->y)
            return 0;
        int midx = (top_left->x + bottom_right->x) >> 1,
            midy = (top_left->y + bottom_right->y) >> 1;
        int pos = -1;
        if(x <= midx){
            if(y <= midy)
                pos = TL;
            else
                pos = BL;
        }
        else{
            if(y <= midy)
                pos = TR;
            else
                pos = BR;
        }
        if(children[pos]->point == nullptr){
           // if region node
            return children[pos]->find(x, y);
        }
        else if(children[pos]->point->x == -1){
            // if empty node
            return 0;
        }
        else{
            if(x == children[pos]->point->x && y == children[pos]->point->y)
                return 1;
        }
        return 0;
    }
};

int main() {
    
    QuadTree tree(1, 1, 4, 4);
    std::cout << "Insert (3, 3)\n";
    tree.insert(3, 3);
    std::cout << "Insert (4, 4)\n";
    tree.insert(4, 4);
    std::cout << "Insert (1, 4)\n";
    tree.insert(1, 4);

    std::cout << "Find (3, 3):\n";
    std::cout << (tree.find(3, 3) ? "True\n" : "False\n");
    std::cout << "Find (3, 4):\n";
    std::cout << (tree.find(3, 4) ? "True\n" : "False\n");
    return 0;
}