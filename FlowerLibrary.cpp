//Gün Kaynar
//22101351

#include "FlowerLibrary.h"

FlowerLibrary::FlowerLibrary(){
    FlowerList flowers;
}
FlowerLibrary::~FlowerLibrary(){

}
void FlowerLibrary::addFlower(string name){
    transform(name.begin(), name.end(), name.begin(), ::tolower);
    if(flowers.add(name)){
        cout << name << " has been added into the library." << endl;

    }
    else{
        cout << name << " cannot be added into the library because it already exists." << endl;
    }
}
void FlowerLibrary::removeFlower(string name){
    transform(name.begin(), name.end(), name.begin(), ::tolower);
    if(flowers.remove(name)){
        cout << name << " has been removed from the library." << endl;
    }
    else{
        cout << name << " cannot be removed because it's not in the library." << endl;

    }
    
}
void FlowerLibrary::listFlowers() const{
    if (flowers.printFlowers() == ""){
        cout << "Library is empty." << endl;
    }
    else{
        cout <<flowers.printFlowers()<<endl;

    }
}
void FlowerLibrary::listFeatures(string name) const{
    transform(name.begin(), name.end(), name.begin(), ::tolower);

    if (flowers.printFlowers(name) == ""){
        cout << name << " isn't found in library" << endl;
    }
    else{
        string s = flowers.printFlowers(name);
        s.resize(s.size()-2);
        cout << s   << endl;
    }
}
void FlowerLibrary::addFeature(string name,string feature){
    transform(feature.begin(), feature.end(), feature.begin(), ::tolower);

    transform(name.begin(), name.end(), name.begin(), ::tolower);

    if (flowers.add_feature(name, feature)==false){
        cout << name << " isn't found in library " << endl;
    }
}

void FlowerLibrary::removeFeature(string name, string feature){
    transform(feature.begin(), feature.end(), feature.begin(), ::tolower);

    transform(name.begin(), name.end(), name.begin(), ::tolower);
    if (flowers.remove_feature(name, feature)==false){
        cout << name << " isn't found in library " << endl;
    }
}

void FlowerLibrary::findFlowers(string feature) const{
    transform(feature.begin(), feature.end(), feature.begin(), ::tolower);

    string a = flowers.find(feature);
    cout << feature << " flowers: ";
    if(!a.empty()){
        a.resize(a.size()-2);

        cout << a;
    }
    else{
        cout << "there is no such flower";
    }
    cout << endl;
}
