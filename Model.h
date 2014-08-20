/* 
 * File:   modelLoad.h
 * Author: brandon
 *
 * Created on January 10, 2011, 9:11 AM
 */

#ifndef MODELLOAD_H
#define	MODELLOAD_H
#include <string>
#include <png.h>
#include <cstdlib>
#include <GL/gl.h>
#include <vector>
#include "vmath.h"
#include "BoundingBox.h"


#define PNG_SIG_BYTES 8
#define HEADER_LENGTH 8

typedef struct face {
    Vector3f vertex[3];
} triFace;

//typedef Vector2f UVTextureVertex;

typedef face* mesh;

class Model {
public:
    Model();
    Model(std::string modelFileName);
    Model(std::string modelFileName, std::string textureFileName);
    ~Model();
    void loadRawModel(std::string fileName);
    void swapTexture (std::string fileName);
    void Draw();

    BoundingBox* getBounds ();

private:
    BoundingBox* bound;
    std::vector<triFace*> faces;
    // UVTextureVertex* textureVerticies;
    GLuint texture;
    char *load_png(std::string name, int *width, int *height);
    GLuint loadTexture(std::string filename);
};

#endif	/* MODELLOAD_H */

