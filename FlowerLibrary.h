//Gün Kaynar
//22101351

#ifndef FlowerLibrary_h
#define FlowerLibrary_h
#include <string>
#include <iostream>
#include <algorithm>

using namespace std;

#include "FlowerList.h"
#include "Flower.h"
class FlowerLibrary{
    public:
        FlowerLibrary();
        ~FlowerLibrary();
        void addFlower(string name);
        void removeFlower(string name);
        void listFlowers() const;
        void listFeatures(string name) const;
        void addFeature(string name,string feature);
        void removeFeature(string name, string feature);
        void findFlowers(string feature) const;
    private:
    
        FlowerList flowers;
        
};

#endif /* FlowerLibrary_h */
