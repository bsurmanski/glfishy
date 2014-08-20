/* 
 * File:   Bubble.cpp
 * Author: brandon
 * 
 * Created on January 18, 2011, 4:27 PM
 */
#include "Bubble.h"
#include <GL/gl.h>
#include <cmath>

Bubble::Bubble() {
    scale = Vector3f(0.03125, 0.03125, 0.03125); // one scale = one quarter of fishy initial
    model = new Model("bubble.raw", "water.png");
    velocity = Vector3f(0, 1.5, 0); // CHANGE SO IT HAS FISH V
}

Bubble::Bubble(Vector3f scale) {
    this->scale = scale * 0.25;
    model = new Model("bubble.raw", "water.png");
    velocity = Vector3f(0, 1 + 2 * rand(), 0); // CHANGE SO IT HAS FISH V
}

Bubble::Bubble(const Bubble& orig) {
}

Bubble::~Bubble() {
}

Vector3f Bubble::getPosition() {
    return position;
}

void Bubble::moveTo(Vector3f point) {
    position = point;
}

void Bubble::setVelocity (Vector3f v){
    velocity = v;
}

void Bubble::grow(float value) {
    scale *= sqrt(value);
}

void Bubble::Update(int t) {
    velocity.y+= 0.25;
    velocity.y*=0.9;
    velocity *= 0.95;
    position += velocity / 60;
}

void Bubble::Draw() {
    glPushMatrix();
    glTranslatef(position.x, position.y, position.z);
    glScalef(scale.x, scale.y, scale.z);
    model->Draw();
    glPopMatrix();
}
