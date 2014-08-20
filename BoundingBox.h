/* 
 * File:   BoundingBox.h
 * Author: brandon
 *
 * Created on January 27, 2011, 9:35 AM
 */

#ifndef BOUNDINGBOX_H
#define	BOUNDINGBOX_H
#include "vmath.h"

class BoundingBox {
public:
    BoundingBox(Vector3f* position, Vector3f* scale);
    BoundingBox();
    BoundingBox(const BoundingBox& orig);
    virtual ~BoundingBox();

    bool collides (BoundingBox* other);
    void sync (Vector3f* position, Vector3f* scale);

    Vector3f *position;
    Vector3f *scale;
    Vector3f max, min;
    private:
};

#endif	/* BOUNDINGBOX_H */

