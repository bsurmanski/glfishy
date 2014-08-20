/* 
 * File:   BoundingBox.cpp
 * Author: brandon
 * 
 * Created on January 27, 2011, 9:35 AM
 */

#include "BoundingBox.h"

BoundingBox::BoundingBox(Vector3f *position, Vector3f *scale) {
    this->position = position;
    this->scale = scale;
    max = Vector3f(0, 0, 0);
    min = Vector3f(0, 0, 0);
}

BoundingBox::BoundingBox() {
    max = Vector3f(0, 0, 0);
    min = Vector3f(0, 0, 0);
}

BoundingBox::BoundingBox(const BoundingBox& orig) {
}

BoundingBox::~BoundingBox() {
}

void BoundingBox::sync(Vector3f *position, Vector3f *scale) {
    this->position = position;
    this->scale = scale;
}

bool BoundingBox::collides(BoundingBox *other) {
    if ((position->x + (min.x * scale->x) < other->position->x + (other->max.x * other->scale->x)
            && position->y + (min.y * scale->y) < other->position->y + (other->max.y * other->scale->y))
            && (position->x + (max.x * scale->x) > other->position->x + (other->min.x * other->scale->x)
            && position->y + (max.y * scale->y) > other->position->y + (other->min.y * other->scale->y))) {
        return true;
    }
    return false;
}

