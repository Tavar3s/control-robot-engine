#include <stdio.h>
#include <math.h>
#include "../include/cre_zoom.h"

// Initialize camera with default FOV
void camera_init(Camera *cam) {
    cam->fov = 60.0f;
    cam->min_fov = 40.0f;
    cam->max_fov = 120.0f;
}

// Zoom in: decrease FOV
void camera_zoom_in(Camera *cam, float step) {
    cam->fov -= step;
    if (cam->fov < cam->min_fov) cam->fov = cam->min_fov;
}

// Zoom out: increase FOV
void camera_zoom_out(Camera *cam, float step) {
    cam->fov += step;
    if (cam->fov > cam->max_fov) cam->fov = cam->max_fov;
}

// Example usage
/*int main() {
    Camera cam;
    camera_init(&cam);

    printf("Initial FOV: %.2f\n", cam.fov);

    camera_zoom_in(&cam, 10.0f);
    printf("Zoomed In FOV: %.2f\n", cam.fov);

    camera_zoom_out(&cam, 20.0f);
    printf("Zoomed Out FOV: %.2f\n", cam.fov);

    return 0;
}*/
