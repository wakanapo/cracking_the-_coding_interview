/* 
 * 3_6.cpp
 * 
 * Author:   Wakana Nogami <wakana.tn16@gmail.com>
 * URL:      http://wknp16.tumblr.com               
 * License:  2-Clause BSD License                    
 * Created:  2017-03-11                              
 *
 *
 * Copyright (c) 2017, Wakana Nogami
 * All rights reserved.
 * 
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 * 
 * 1. Redistributions of source code must retain the above copyright notice,
 *    this list of conditions and the following disclaimer.
 * 
 * 2. Redistributions in binary form must reproduce the above copyright notice,
 *    this list of conditions and the following disclaimer in the documentation
 *    and/or other materials provided with the distribution.
 * 
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 */


#include "3_6.h"


Animal::Animal(AnimalKind k, std::string n) {
  kind = k;
  name = n;
  juniorAny = nullptr;
  juniorSame = nullptr;
  seniorAny = nullptr;
  seniorSame = nullptr;
}

AnimalKind Animal::getKind() {
  return kind;
}

std::string Animal::getName() {
  return name;
}


AnimalShelter::AnimalShelter() {
  newestAny = nullptr;
  newestDog = nullptr;
  newestCat = nullptr;
  oldestAny = nullptr;
  oldestDog = nullptr;
  oldestCat = nullptr; 
}

void AnimalShelter::removeFromAny_(Animal* a) {
  if (a == oldestAny) {
    if (a == newestAny) {
      oldestAny = nullptr;
      newestAny = nullptr;
    } else {
      oldestAny = a->juniorAny;
      a->juniorAny->seniorAny = nullptr;
    }
  } else if (a == newestAny){
    newestAny = newestAny->seniorAny;
    a->seniorAny->juniorAny = nullptr;
  } else {
    a->juniorAny->seniorAny = a->seniorAny;
    a->seniorAny->juniorAny = a->juniorAny;
  }
}

void AnimalShelter::enqueue(Animal* new_animal) {
  if (newestAny == nullptr)
    oldestAny = new_animal;
  else {
    new_animal->seniorAny = newestAny;
    newestAny->juniorAny = new_animal;
  }
  newestAny = new_animal;
  if (new_animal->getKind() == Dog) {
    if (newestDog == nullptr)
      oldestDog = new_animal;
    else {
      new_animal->seniorSame = newestDog;
      newestDog->juniorSame = new_animal;
    }
    newestDog = new_animal;
  } else {
    if (newestCat == nullptr)
      oldestCat = new_animal;
    else {
      new_animal->seniorSame = newestCat;
      newestCat->juniorSame = new_animal;
    }
    newestCat = new_animal;
  }
}

Animal* AnimalShelter::dequeueAny() {
  if (oldestAny == nullptr)
    return nullptr;
  if (oldestAny->getKind() == Dog) {
    return dequeueDog();
  } else {
    return dequeueCat();
  }
}

Animal* AnimalShelter::dequeueDog() {
  if (oldestDog == nullptr)
    return nullptr;
  Animal* tmp = oldestDog;
  if (tmp == newestDog) {
    newestDog = nullptr;
    oldestDog = nullptr;
  } else {
    oldestDog = tmp->juniorSame;
    oldestDog->seniorSame = nullptr;
  }
  removeFromAny_(tmp);
  return tmp;
}

Animal* AnimalShelter::dequeueCat() {
  if (oldestCat == nullptr)
    return nullptr;
  Animal* tmp = oldestCat;
  if (tmp == newestCat) {
    newestCat = nullptr;
    oldestCat = nullptr;
  } else {
    oldestCat = tmp->juniorSame;
    oldestCat->seniorSame = nullptr;
  }
  removeFromAny_(tmp);
  return tmp;
}
