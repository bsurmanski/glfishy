/* 
 * File:   Fish.cpp
 * Author: brandon
 * 
 * Created on January 17, 2011, 4:19 PM
 */

#include "Fish.h"
#include <GL/gl.h>
#include <cmath>

Fish::Fish() {
    robot = false;
    model = new Model("fish.raw", "grass.png");
    scale = Vector3f(0.26, 0.26, 0.26);
    position = Vector3f(2,2,2);
    bound = model->getBounds();
    bound->sync(&position, &scale);
    for (int i = 0; i < 3; i++)
        bubbles.push_back(new Bubble());
}

Fish::Fish(bool robot) {
    this->robot = robot;
    model = new Model("fish.raw", "yellow.png");
    scale = Vector3f(0.25, 0.25, 0.25);
    bound = model->getBounds();
    bound->sync(&position, &scale);
    for (int i = 0; i < 3; i++)
        bubbles.push_back(new Bubble());
    destination = Vector3f(-2, 0, 0);
}

Fish::Fish(const Fish& orig) {
}

Fish::~Fish() {
}

void Fish::grow(float value) {
    scale *= value;
    for (int i = 0; i < bubbles.size(); i++)
        bubbles[i]->grow(value);
}

void Fish::Update(int t) {
    if (robot) {
        automate(t);
    } else {

    }
    velocity += acceleration / 10;
    velocity *= 0.96; // slow
    position += velocity / 60; // TODO: devide by framerate, so constant
    if (velocity.x > 0 && rotation.z != 0) {
        rotation.z += 15;
    } else
        if (velocity.x < 0 && rotation.z != 180) {
        rotation.z += 15;
    }

    if (rotation.x >= 360) rotation.x -= 360;
    if (rotation.x != 0) rotation.x += 5;
    if (rotation.z >= 360) rotation.z -= 360;
    for (int i = 0; i < bubbles.size(); i++) {
        if (bubbles[i]->getPosition().y > (random() % 10) + 10) {
            bubbles[i]->moveTo(position + Vector3f(0.25 * scale.x, 0.25 * scale.y, 0));
        }
        bubbles[i]->Update(t);
    }
}

void Fish::automate(int t) {
    acceleration *= 2;
    velocity *= 0.99;
    Vector3f vec = position - destination;
    if (vec.lengthSq() < 1) {
        destination = Vector3f((random() % 8) - 4, (random() % 8) - 4, 0);
    }
    if (vec.x < 0) {
        MoveRight();
    } else {
        MoveLeft();
    }

    if (vec.y < 0) {
        MoveUp();
    } else {
        MoveDown();
    }
}

void Fish::Draw() {
    glPushMatrix();
    glTranslatef(position.x, position.y, position.z);
    glRotatef(-90, 1, 0, 0);
    glRotatef(rotation.x, 1, 0, 0);
    glRotatef(rotation.y, 0, 1, 0);
    glRotatef(rotation.z, 0, 0, 1);
    glScalef(scale.x, scale.y, scale.z);
    Fish::model->Draw();
    glPopMatrix();
    for (int i = 0; i < bubbles.size(); i++)
        bubbles[i]->Draw();
}


