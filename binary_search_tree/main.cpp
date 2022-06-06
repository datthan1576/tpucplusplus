#include<iostream>
#include<string>
#include<fstream>
#include "BST.h"
#include<vector>
BST& getTree()
{
    std::string fileIn = R"(C:\Users\datth\Desktop\variant17.csv)";
    std::ifstream in(fileIn);
    if (!in.is_open())
    {
        std::cout << "Can not open file!" << std::endl;
    }
    std::string elem;
    BST* newTree = new BST;
    while (getline(in, elem, ','))
    {
        newTree->insert(std::stod(elem.c_str()));
    }
    in.close();
    return *newTree;
}

std::vector<double> getVector()
{
    std::string fileIn = R"(C:\Users\datth\Desktop\variant17.csv)";
    std::ifstream in(fileIn);
    if (!in.is_open())
    {
        std::cout << "Can not open file!" << std::endl;
    }
    std::string elem;
    std::vector<double> myvec;
    while (getline(in, elem, ','))
    {
        myvec.push_back(std::stod(elem.c_str()));
    }
    in.close();
    return myvec;
}

int main()
{
    std::vector<double> myvec = getVector();
    std::cout << "Vector :" << std::endl;
    for (const auto& i : myvec)
    {
        std::cout << i << "   ";
    }
    std::cout << std::endl;
    BST mytree = getTree();
    std::cout << "Binary Tree:" << std::endl;
    mytree.print();
    std::cout << std::endl;
    std::cout << "Height :" << mytree.height() << std::endl;
    std::cout << std::endl;
    mytree.display_tree();
}

