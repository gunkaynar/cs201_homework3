//Gün Kaynar
//22101351

#ifndef Flower_h
#define Flower_h
#include <string>
#include <iostream>
#include <cstdlib>
using namespace std;
class Flower{
    public:
        Flower();
        Flower(string flowerName);
        Flower(const Flower& aFlower);
        ~Flower();
        bool isEmpty() const;
        int getLength() const;
        bool add(string feature);
        bool remove(string feature);
        string printFlower() const;
        string getName() const;
        bool findFeature(string feature)const;
    private:
        struct FeatureNode{
            string feature;
            FeatureNode* next;
        };
        int size;
        string flowerName;
        FeatureNode *head;
    friend class FlowerList;
    friend class FlowerLibrary;

};
#endif /* Flower_h */
