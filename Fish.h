/* 
 * File:   Fish.h
 * Author: brandon
 *
 * Created on January 17, 2011, 4:19 PM
 */

#ifndef FISH_H
#define	FISH_H
#include "PhysObj.h"
#include "Bubble.h"
#include "BoundingBox.h"
#include <vector>

class Fish : public PhysObj {
public:
    Fish();
    Fish(bool robot);
    Fish(const Fish& orig);
    virtual ~Fish();
    void Draw();
    void Update(int t);
    void automate(int t);
    void grow(float value);
    //void roll();
/*
    void MoveUp();
    void MoveDown();
    void MoveLeft();
    void MoveRight();
    void stopMoveX();
    void stopMoveY();
    */
private:

    Vector3f destination; // used for autofish
    bool robot; // autofish

    std::vector<Bubble*> bubbles;

};

#endif	/* FISH_H */

