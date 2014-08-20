/* 
 * File:   PhysObj.h
 * Author: brandon
 *
 * Created on January 27, 2011, 9:05 AM
 */

#ifndef PHYSOBJ_H
#define	PHYSOBJ_H
#include "vmath.h"
#include "Model.h"
#include "BoundingBox.h"

class PhysObj {
public:

    virtual ~PhysObj() {
    }

    bool hitTest(PhysObj* other) {
        return (bound->collides(other->bound));
    }

    bool largerThan (PhysObj* other);

    virtual void grow(float value);

    Vector3f getVelocity();
    Vector3f getScale();
    Vector3f getPosition();

    void roll();
    void MoveUp();
    void MoveDown();
    void MoveLeft();
    void MoveRight();
    void stopMoveX();
    void stopMoveY();

    virtual void Update(int t);
    virtual void Draw();
protected:
    Model* model;
    Vector3f position;
    Vector3f velocity;
    Vector3f acceleration;
    Vector3f rotation;
    Vector3f scale;
    BoundingBox* bound;

    PhysObj();
    PhysObj(const PhysObj& orig);
};

#endif	/* PHYSOBJ_H */

