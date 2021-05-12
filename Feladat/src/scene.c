#include "scene.h"
#include <GL/glut.h>
#include <obj/load.h>
#include <obj/draw.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void init_scene(Scene* scene)
{
    init_models(scene);
    //set_position_hed(scene);
    load_model(&(scene->cube), "cube.obj");
    scene->texture_id = load_texture("cube.png"); 
    
    //glBindTexture(GL_TEXTURE_2D, scene->texture_id);

    scene->material.ambient.red = 0.8;
    scene->material.ambient.green = 0.8;
    scene->material.ambient.blue = 0.8;

    scene->material.diffuse.red = 0.9;
    scene->material.diffuse.green = 0.9;
    scene->material.diffuse.blue = 0.9;

    scene->material.specular.red = 0.9;
    scene->material.specular.green = 0.9;
    scene->material.specular.blue = 0.9;

    scene->material.shininess = 0.0;
    scene->light = -1.0f;
}

void set_lighting(Scene *scene)
{
    float ambient_light[4];
    float diffuse_light[4];
    float specular_light[4];
    float position[4];

    ambient_light[0] = scene->light;
    ambient_light[1] = scene->light;
    ambient_light[2] = scene->light;
    ambient_light[3] = 10.0f;

    diffuse_light[0] = scene->light;
    diffuse_light[1] = scene->light;
    diffuse_light[2] = scene->light;
    diffuse_light[3] = 10.0f;

    specular_light[0] = scene->light;
    specular_light[1] = scene->light;
    specular_light[2] = scene->light;
    specular_light[3] = 10.0f;

    position[0] = 0.0f;
    position[1] = 0.0f;
    position[2] = 10.0f;
    position[3] = 0.0f;

    glLightfv(GL_LIGHT0, GL_AMBIENT, ambient_light);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, diffuse_light);
    glLightfv(GL_LIGHT0, GL_SPECULAR, specular_light);
    glLightfv(GL_LIGHT0, GL_POSITION, position);


    /*
    float ambient_light[] = { 0.8f, 0.8f, 0.8f, 0.7f };
    float diffuse_light[] = { 1.0f, 1.0f, 1.0, 1.0f };
    float specular_light[] = { 0.9f, 0.9f, 0.9f, 1.0f };
    float position[] = { 0.0f, 15.0f, 10.0f, 1.0f };

    glLightfv(GL_LIGHT0, GL_AMBIENT, ambient_light);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, diffuse_light);
    glLightfv(GL_LIGHT0, GL_SPECULAR, specular_light);
    glLightfv(GL_LIGHT0, GL_POSITION, position);
    */
}

void set_material(const Material* material)
{
    float ambient_material_color[] = {
        material->ambient.red,
        material->ambient.green,
        material->ambient.blue
    };

    float diffuse_material_color[] = {
        material->diffuse.red,
        material->diffuse.green,
        material->diffuse.blue
    };

    float specular_material_color[] = {
        material->specular.red,
        material->specular.green,
        material->specular.blue
    };

    glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, ambient_material_color);
    glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, diffuse_material_color);
    glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, specular_material_color);

    glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, &(material->shininess));
}

float forwoard = 0.0f;

void draw_scene(const Scene* scene)
{
    set_material(&(scene->material));
    set_lighting(scene);
    draw_origin();
    glPushMatrix();
    glScalef(0.1f, 0.1f, 0.1f);
    forwoard += 0.01f;
    glRotatef(0.0f , 0.0f, 0.0f, 0.0f);
    //glTranslatef(scene->hedgie.position.x, scene->hedgie.position.y, scene->hedgie.position.z-forwoard);
    draw_model(&(scene->hedgie.model));
    glPopMatrix();

    draw_model(&(scene->cube));

}

/*
void set_position_hed(Scene *scene)
{
    scene->hedgie.position.x = -60;
    scene->hedgie.position.y = 7;
    scene->hedgie.position.z = 65;
}
*/



void init_models(Scene *scene)
{
    load_model(&(scene->hedgie.model), "Hedgie.obj");
}



void draw_origin()
{
    glRotatef(-90.0f, -90.0f, 0.0f, 0.0f);
    glScalef(0.98f, 0.98f, 0.98f);
    glTranslatef(0.9285f, -0.9285f, 0.0f);  
    glBegin(GL_LINES);
    

    glColor3f(1, 0, 0);
    glVertex3f(0, 0, 0);
    glVertex3f(1, 0, 0);

    glColor3f(0, 1, 0);
    glVertex3f(0, 0, 0);
    glVertex3f(0, 1, 0);

    glColor3f(0, 0, 1);
    glVertex3f(0, 0, 0);
    glVertex3f(0, 0, 1);

    glEnd();
}
