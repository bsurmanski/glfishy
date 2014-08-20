/**
 File:  Model.cpp
 */
#include "Model.h"
#include <fstream>
#include <iostream>
#include <queue>

//Model::Model(){}

Model::Model(std::string modelFileName) {
    loadRawModel(modelFileName);
}

Model::Model(std::string modelFileName, std::string textureFileName) {
    bound = new BoundingBox();
    texture = loadTexture(textureFileName);
    loadRawModel(modelFileName);
}

Model::~Model() {
}

BoundingBox* Model::getBounds() {
    return bound;
}

void Model::loadRawModel(std::string fileName) {
    fileName = "Resources/" + fileName;
    std::ifstream modelFile(fileName.c_str());
    char* tt = new char (10);
    while (modelFile.good()) {
        triFace *temp = new triFace;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                modelFile >> tt;
                temp->vertex[i][j] = atof(tt);

                //get bounding box around model
                if (temp->vertex[i][j] > bound->max[j]) {
                    bound->max[j] = temp->vertex[i][j];
                }
                if (temp->vertex[i][j] < bound->min[j]) {
                    bound->min[j] = temp->vertex[i][j];
                }
            }
        }
        faces.push_back(temp);
        modelFile.ignore();
    }
    modelFile.close();
}

void Model::swapTexture(std::string fileName) {
    texture = loadTexture(fileName);
}

void Model::Draw() {
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, texture);
    glBegin(GL_TRIANGLES);
    for (int i = 0; i < faces.size(); i++) {
        glTexCoord2d(0, 0);
        glVertex3f(faces[i]->vertex[0].x, faces[i]->vertex[0].y, faces[i]->vertex[0].z);
        glTexCoord2d(1, 0);
        glVertex3f(faces[i]->vertex[1].x, faces[i]->vertex[1].y, faces[i]->vertex[1].z);
        glTexCoord2d(1, 1);
        glVertex3f(faces[i]->vertex[2].x, faces[i]->vertex[2].y, faces[i]->vertex[2].z);
    }
    glEnd();
    glDisable(GL_TEXTURE_2D);
}

GLuint Model::loadTexture(std::string fileName) {
    glPixelStorei(GL_UNPACK_ALIGNMENT, 1);

    GLuint tex;
    glGenTextures(1, &tex);
    glBindTexture(GL_TEXTURE_2D, tex);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);

    int w, h;
    GLubyte *pixels = (GLubyte *) load_png(fileName, &w, &h);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, w, h, 0, GL_RGBA, GL_UNSIGNED_BYTE, pixels);
    free(pixels);

    return tex;
}

char* Model::load_png(std::string fileName, int *width, int *height) {
    fileName = "Resources/" + fileName;
    FILE *png_file = fopen(fileName.c_str(), "rb");
    //assert(png_file.open);

    uint8_t header[PNG_SIG_BYTES];

    fread(header, 1, PNG_SIG_BYTES, png_file);
    assert(!png_sig_cmp(header, 0, PNG_SIG_BYTES));

    png_structp png_ptr = png_create_read_struct(PNG_LIBPNG_VER_STRING, NULL, NULL, NULL);
    assert(png_ptr);

    png_infop info_ptr = png_create_info_struct(png_ptr);
    assert(info_ptr);

    png_infop end_info = png_create_info_struct(png_ptr);
    assert(end_info);

    assert(!setjmp(png_jmpbuf(png_ptr)));
    png_init_io(png_ptr, png_file);
    png_set_sig_bytes(png_ptr, PNG_SIG_BYTES);
    png_read_info(png_ptr, info_ptr);

    *width = png_get_image_width(png_ptr, info_ptr);
    *height = png_get_image_height(png_ptr, info_ptr);

    png_uint_32 bit_depth, color_type;
    bit_depth = png_get_bit_depth(png_ptr, info_ptr);
    color_type = png_get_color_type(png_ptr, info_ptr);

    //  if (color_type == PNG_COLOR_TYPE_GRAY && bit_depth < 8)
    //    png_set_gray_1_2_4_to_8(png_ptr);

    if (bit_depth == 16)
        png_set_strip_16(png_ptr);

    if (color_type == PNG_COLOR_TYPE_PALETTE)
        png_set_palette_to_rgb(png_ptr);
    else if (color_type == PNG_COLOR_TYPE_GRAY ||
            color_type == PNG_COLOR_TYPE_GRAY_ALPHA) {
        png_set_gray_to_rgb(png_ptr);
    }

    if (png_get_valid(png_ptr, info_ptr, PNG_INFO_tRNS))
        png_set_tRNS_to_alpha(png_ptr);
    else
        png_set_filler(png_ptr, 0xff, PNG_FILLER_AFTER);

    png_read_update_info(png_ptr, info_ptr);

    png_uint_32 rowbytes = png_get_rowbytes(png_ptr, info_ptr);
    png_uint_32 numbytes = rowbytes * (*height);
    png_byte* pixels = (png_byte*) malloc(numbytes);
    png_byte** row_ptrs = (png_byte**) malloc((*height) * sizeof (png_byte*));

    int i;
    for (i = 0; i < (*height); i++)
        row_ptrs[i] = pixels + ((*height) - 1 - i) * rowbytes;


    png_read_image(png_ptr, row_ptrs);

    free(row_ptrs);
    png_destroy_read_struct(&png_ptr, &info_ptr, &end_info);
    fclose(png_file);

    return (char *) pixels;
}