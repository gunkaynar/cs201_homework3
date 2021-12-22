//Gün Kaynar
//22101351

#include "Flower.h"

Flower::Flower(){
    this->size = 0;
    this->head = NULL;
    this->flowerName = "unknown flower";
}

Flower::Flower(string flowerName){
    this->size = 0;
    this->head = NULL;
    this->flowerName = flowerName;

}
Flower::Flower(const Flower& aFlower){
    this->flowerName = aFlower.flowerName;
    this->size = aFlower.size;
   if (aFlower.head == NULL)
      this->head = NULL;
   else {
      this->head = new FeatureNode;
      head->feature = aFlower.head->feature;
       FeatureNode *newPtr = this->head;

      for (FeatureNode *origPtr = aFlower.head->next;
                     origPtr != NULL;
                     origPtr = origPtr->next){
         newPtr->next = new FeatureNode;
         newPtr = newPtr->next;
         newPtr->feature = origPtr->feature;
      }
      newPtr->next = NULL;
   }
}

Flower::~Flower(){
    FeatureNode* current = this->head;
    FeatureNode* next = NULL;
    while (current != NULL){
        next = current->next;
        delete current;
        current = next;
    }
 

    this->head= NULL;

}

bool Flower::isEmpty() const{
    return size == 0;
}

int Flower::getLength() const{
    return size;
}

bool Flower::add(string feature){
    FeatureNode* new_node = new FeatureNode;
    FeatureNode *last = this->head;
    new_node->feature = feature;
    new_node->next = NULL;
    if (this->head == NULL){
        this->head = new_node;
        size++;
        delete last;
        return true;

    }
    if(last->feature==feature){
        delete new_node;
        return false;
    }
    while (last->next != NULL){
        if (last->feature == feature){
            delete new_node;
            return false;
        }
        last = last->next;
    }
    last->next = new_node;
    size++;
    return true;
}

bool Flower::remove(string feature){
    
    FeatureNode* temp = this->head;
    FeatureNode* prev = NULL;
    
   if (temp != NULL && temp->feature == feature){
       this->head = temp->next;
       delete temp;
       size--;
       return true;
   }

   else{
   while (temp != NULL && temp->feature != feature){
       prev = temp;
       temp = temp->next;
   }
       if (temp == NULL){
           delete temp;
           return false;
       }
   prev->next = temp->next;
   delete temp;
   }
    size--;
    return true;
}


string Flower::printFlower() const{
    string to_print = "";
    FeatureNode* temp = this->head;

    while (temp != NULL){
        to_print += temp->feature + ", ";
        temp = temp->next;

    }
    delete temp;
    if (to_print == ""){
        return "No feature\n";
    }
    else{
        return to_print;

    }
}

string Flower::getName() const{
    return flowerName;
}

bool Flower::findFeature(string feature)const{
    
    FeatureNode* temp = this->head;
    FeatureNode* prev = NULL;
    
   if (temp ==NULL){
       return false;
   }

   else{
   while (temp != NULL){
       if(temp->feature == feature){
           return true;
       }
       prev = temp;
       temp = temp->next;
   }
   delete temp;
   }
    return false;
}
