//Gün Kaynar
//22101351


#include "FlowerList.h"

FlowerList::FlowerList(){
    this->size = 0;
    this->head = NULL;

}

FlowerList::FlowerList(const FlowerList& aList){
    this->size = aList.size;
   if (aList.head == NULL)
      this->head = NULL;
   else {
      this->head = new FlowerNode;
      head->f = aList.head->f;
       FlowerNode *newPtr = this->head;

      for (FlowerNode *origPtr = aList.head->next;
                     origPtr != NULL;
                     origPtr = origPtr->next){
         newPtr->next = new FlowerNode;
         newPtr = newPtr->next;
         newPtr->f = origPtr->f;
      }
      newPtr->next = NULL;
   }
}

FlowerList::~FlowerList(){
    FlowerNode* current = this->head;
    FlowerNode* next = NULL;
    while (current != NULL){
        next = current->next;
        delete current;
        current = next;
    }
 

    this->head= NULL;
}
bool FlowerList::isEmpty() const{
    return size == 0;
}

int FlowerList::getLength() const{
    return size;
}

bool FlowerList::retrieve(string flowerName, Flower& flower) const{
    
    FlowerNode* temp = this->head;
    while (temp != NULL){
        if(temp->f.getName() == flowerName){
            delete temp;
            return true;
        }
        temp = temp->next;
    }
    delete temp;
    return false;
}

bool FlowerList::add(string flowerName){
    FlowerNode* new_node = new FlowerNode;
    FlowerNode *last = this->head;
    new_node->f = flowerName;
    new_node->next = NULL;
    if (this->head == NULL){
        this->head = new_node;
        size++;
        delete last;
        return true;

    }
    if (last->f.flowerName == flowerName){
        delete new_node;
        return false;
    }
    while (last->next != NULL){
        if (last->f.flowerName == flowerName){
            delete new_node;
            return false;
        }
        last = last->next;
    }
    last->next = new_node;
    size++;
    return true;
}



bool FlowerList::remove(string flowerName){
    FlowerNode* temp = this->head;
    FlowerNode* prev = NULL;
    
   if (temp != NULL && temp->f.getName() == flowerName){
       this->head = temp->next;
       delete temp;
       size--;
       return true;
   }

   else{
   while (temp != NULL && temp->f.getName() != flowerName){
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
string FlowerList::printFlowers() const{
    string to_print ="";
    FlowerNode* temp = this->head;

    while (temp != NULL){
        to_print += temp->f.getName() + ": ";
        to_print += temp->f.printFlower();
        temp = temp->next;

    }
    delete temp;
    return to_print;
}
string FlowerList::printFlowers(string flowerName) const{
    string to_print = "";
    FlowerNode* temp = this->head;

    while (temp != NULL){
        if (temp->f.getName() == flowerName){
            to_print += flowerName + ": ";
            to_print += temp->f.printFlower();
            break;
        }
        temp = temp->next;
    }
//delete temp
    return to_print;
}
bool FlowerList::add_feature(string flowerName,string feature){
    FlowerNode* temp = this->head;
    while (temp != NULL){
        if (temp->f.getName() == flowerName){
            if(temp->f.add(feature)){
                cout << feature << " is added into " << flowerName << endl;
                return true;
            }
            else{
                cout << feature << " already exists in " << flowerName << endl;
                return true;
            }
        }
        temp = temp->next;
    }
    delete temp;
    return false;
}

bool FlowerList::remove_feature(string flowerName,string feature){
    FlowerNode* temp = this->head;
    while (temp != NULL){
        if (temp->f.getName() == flowerName){
            if(temp->f.remove(feature)){
                cout << feature << " is removed from " << flowerName << endl;
                return true;
            }
            else{
                cout << feature << " doesn't exist in  " << flowerName << endl;
                return true;
            }
        }
        temp = temp->next;
    }
    delete temp;
    return false;
}

string FlowerList::find(string feature)const{
    FlowerNode* temp = this->head;
    string v = "";
    while (temp != NULL){
        if (temp->f.findFeature(feature)){
            v+= (temp->f.getName()) + ", ";
        }
        temp = temp->next;

    }

    delete temp;
    return v;
}
