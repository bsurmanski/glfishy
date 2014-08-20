/* 
 * File:   gameEntity.h
 * Author: brandon
 *
 * Created on January 2, 2011, 2:52 PM
 */

#ifndef GAMEENTITY_H
#define	GAMEENTITY_H
#include <GL/gl.h>

class gameEntity {
public:
    Vector3f position;
    Vector3f rotation;
    virtual void Update();
    virtual void Draw();
protected:
    virtual gameEntity();
    GLuint* sprite;

};

#endif	/* GAMEENTITY_H */

