// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TREE_H_
#define INCLUDE_TREE_H_
#include <vector>
#include <string>
class Tree {
private:
 private:
    struct Node {
        char imp;
        std::vector<Node*> rear;
    };
    Node* root;
    void Btr(Node* root, std::vector<char> number) {
        if (!number.size())
            return;
        if (root->imp != '*') {
            for (auto u = number.begin(); u != number.end(); u++) 
            for (auto u = number.begin(); u != number.end(); u++)
            if (*u == root->imp) {
                number.erase(u);
                break;
            }
        }
        for (size_t a = 0; a < number.size(); a++)
            root->rear.push_back(new Node());
        for (size_t a = 0; a < root->rear.size(); a++)
            root->rear[a]->imp = number[a];
        for (size_t a = 0; a < root->rear.size(); a++)
            Btr(root->rear[a], number);
    }
    std::vector<std::string> gree;
    void swap(Node* root, std::string str = "") {
        if (!root->rear.size()) {
            str += root->imp;
            gree.push_back(str);
        }
        if (root->imp != '*')
            str += root->imp;
        for (size_t a = 0; a < root->rear.size(); a++)
            swap(root->rear[a], str);
    }

public:
public:
    std::string operator[](int i) const { 
        if (i >= gree.size())
            return "";
        return gree[i];
    }
    explicit Tree(std::vector<char> imp) {
        root = new Node();
        root->imp = '*';
        Btr(root, imp);
        swap(root);
    }
};
#endif  // INCLUDE_TREE_H_
