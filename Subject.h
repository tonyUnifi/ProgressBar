//
// Created by Antonio Costache on 17/01/26.
//

#ifndef PROGRESSBAR_SUBJECT_H
#define PROGRESSBAR_SUBJECT_H
#include "Observer.h"
#include <list>

class Subject {
public:
    virtual void subscribe(Observer* observer) = 0;
    virtual void unsubscribe(Observer* observer) = 0;
    virtual void notify() = 0;
protected:
    std::list<Observer*> observers;
};


#endif //PROGRESSBAR_SUBJECT_H