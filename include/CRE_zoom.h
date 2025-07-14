#ifndef CRE_ZOOM_H
#define CRE_ZOOM_H

typedef struct Camera {
    float fov;
    float min_fov;
    float max_fov;
} Camera;

void camera_init(Camera *cam);
void camera_zoom_in(Camera *cam, float step);
void camera_zoom_out(Camera *cam, float step);

#endif