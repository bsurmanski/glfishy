/* 
 * File:   Bubble.h
 * Author: brandon
 *
 * Created on January 18, 2011, 4:27 PM
 */

#ifndef BUBBLE_H
#define	BUBBLE_H
#include "PhysObj.h"

class Bubble : PhysObj{
public:
    Bubble();
    Bubble(Vector3f pos);
    Bubble(const Bubble& orig);
    virtual ~Bubble();

    Vector3f getPosition();
    void moveTo(Vector3f point);
    void setVelocity (Vector3f v);
    void grow (float value);

    void Update(int t);
    void Draw();
private:
};

#endif	/* BUBBLE_H */

