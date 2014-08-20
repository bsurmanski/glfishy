
#include "PhysObj.h"

PhysObj::PhysObj() {
    //bound = new BoundingBox();
};

PhysObj::PhysObj(const PhysObj& orig) {
};

void PhysObj::Update(int t) {
}

void PhysObj::Draw() {
    glPushMatrix();
    glTranslatef(position.x, position.y, position.z);
    glRotatef(rotation.x, 1, 0, 0);
    glRotatef(rotation.y, 0, 1, 0);
    glRotatef(rotation.z, 0, 0, 1);
    glScalef(scale.x, scale.y, scale.z);
    model->Draw();
    glPopMatrix();
}

bool PhysObj::largerThan(PhysObj* other) {
    return (scale.x > other->scale.x);
}

void PhysObj::grow(float value) {
    scale *= value;
}

Vector3f PhysObj::getVelocity() {
    return velocity;
}

Vector3f PhysObj::getScale() {
    return scale;
}

Vector3f PhysObj::getPosition() {
    return position;
}

void PhysObj::roll() {
    rotation.x += 5;
}

void PhysObj::MoveUp() {
    acceleration.y = 1;
}

void PhysObj::MoveDown() {
    acceleration.y = -1;
}

void PhysObj::MoveLeft() {
    acceleration.x = -1;
}

void PhysObj::MoveRight() {
    acceleration.x = 1;
}

void PhysObj::stopMoveX() {
    acceleration.x = 0;
}

void PhysObj::stopMoveY() {
    acceleration.y = 0;
}
