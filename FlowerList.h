//Gün Kaynar
//22101351

#ifndef FlowerList_h
#define FlowerList_h
#include <string>
#include <iostream>

using namespace std;

#include "Flower.h"
class FlowerList{
    public:
        FlowerList();
        FlowerList(const FlowerList& aList);
        ~FlowerList();
        bool isEmpty() const;
        int getLength() const;
        bool retrieve(string flowerName, Flower& flower) const;
        bool add(string flowerName);
        bool remove(string flowerName);
        string printFlowers() const;
        string printFlowers(string flowerName) const;
        bool add_feature(string flowerName,string feature);
        bool remove_feature(string flowerName,string feature);
        string find(string feature) const;
    private:
        struct FlowerNode{
            Flower f;
            FlowerNode* next;
        };
        int size;
        FlowerNode* head;
    friend class FlowerLibrary;
};
#endif /* FlowerList_h */
