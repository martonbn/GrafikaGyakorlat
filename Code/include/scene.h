#ifndef SCENE_H
#define SCENE_H

#include "camera.h"
#include "texture.h"

#include <obj/model.h>


typedef struct Object
{
    Model model;
    vec3 position;
    vec3 scale;
    vec3 speed;
    vec3 rotation;
    vec3 prev_position;
} Object;


typedef struct Scene
{
    float light;
    Model cube;
    Object hedgie;
    Material material;
    GLuint texture_id;
} Scene;



/**
 * Initialize the scene by loading models.
 */
void init_scene(Scene* scene);


void init_models(Scene *scene);



/**
 * Set the lighting of the scene.
 */
void set_lighting(Scene *scene);

/**
 * Set the current material.
 */
void set_material(const Material* material);

/**
 * Draw the scene objects.
 */
void draw_scene(const Scene* scene);

/**
 * Draw the origin of the world coordinate system.
 */
void draw_origin();

#endif /* SCENE_H */
