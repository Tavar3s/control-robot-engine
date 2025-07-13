#include "../include/cre_zoom.h"
#include <stdio.h>

int main() {
    Camera cam;
    camera_init(&cam);

    printf("Initial FOV: %.2f\n", cam.fov);

    camera_zoom_in(&cam, 10.0f);
    printf("Zoomed In FOV: %.2f\n", cam.fov);

    camera_zoom_out(&cam, 20.0f);
    printf("Zoomed Out FOV: %.2f\n", cam.fov);

    return 0;
}