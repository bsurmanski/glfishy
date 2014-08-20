/* 
 * File:   Background.h
 * Author: brandon
 *
 * Created on January 18, 2011, 11:07 AM
 */

#ifndef BACKGROUND_H
#define	BACKGROUND_H
#include "Model.h"
#include "vmath.h"

class Background {
public:
    Background();
    Background(const Background& orig);
    virtual ~Background();
    void Draw();
private:
    Model *model;
    Vector3f position;

};

#endif	/* BACKGROUND_H */

