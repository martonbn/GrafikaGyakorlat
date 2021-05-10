#include "scene.h"

#include <GL/glut.h>

#include <obj/load.h>
#include <obj/draw.h>

void init_scene(Scene* scene)
{
    load_model(&(scene->cube), "cube.obj");
    //load_model(&(scene->hedgie), "Hedgie.obj");
    scene->texture_id = load_texture("cube.png"); 

    glBindTexture(GL_TEXTURE_2D, scene->texture_id);

    scene->material.ambient.red = 0.4;
    scene->material.ambient.green = 0.4;
    scene->material.ambient.blue = 0.4;

    scene->material.diffuse.red = 0.9;
    scene->material.diffuse.green = 0.9;
    scene->material.diffuse.blue = 0.9;

    scene->material.specular.red = 0.8;
    scene->material.specular.green = 1.5;
    scene->material.specular.blue = 1.8;

    scene->material.shininess = 0.0;
}

void set_lighting()
{
    float ambient_light[] = { 0.8f, 0.8f, 0.8f, 0.7f };
    float diffuse_light[] = { 1.0f, 1.0f, 1.0, 1.0f };
    float specular_light[] = { 0.9f, 0.9f, 0.9f, 1.0f };
    float position[] = { 0.0f, 15.0f, 10.0f, 1.0f };

    glLightfv(GL_LIGHT0, GL_AMBIENT, ambient_light);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, diffuse_light);
    glLightfv(GL_LIGHT0, GL_SPECULAR, specular_light);
    glLightfv(GL_LIGHT0, GL_POSITION, position);
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

void draw_scene(const Scene* scene)
{
    set_material(&(scene->material));
    set_lighting();
    draw_origin();
    draw_model(&(scene->cube));

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
