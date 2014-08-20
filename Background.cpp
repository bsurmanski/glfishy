/* 
 * File:   Background.cpp
 * Author: brandon
 * 
 * Created on January 18, 2011, 11:07 AM
 */

#include "Background.h"

Background::Background() {
    model = new Model ("fishbackground.raw", "dirt.png");
}

Background::Background(const Background& orig) {
}

Background::~Background() {
}

void Background::Draw() {
    glPushMatrix();
    glTranslatef(position.x, position.y, position.z);
    glRotatef(0, 1, 0, 0);
    model->Draw();
    glPopMatrix();
}

