#ifndef ENGINE_H
#define ENGINE_H

#include <stdio.h>
#include <math.h>


typedef struct s_vector2 
{
    long       x;
    long       y;
}              t_vector2;

typedef struct s_transform
{
    t_vector2    position;
    t_vector2    rotation;
}              t_transform;

typedef struct s_raycast
{
    t_vector2    origin;
    t_vector2    direction;
}              t_raycast;

typedef struct s_physics
{
    t_raycast    raycast;
    t_transform transform;
}              t_physics;

typedef struct s_map
{
    int          width;
    int          height;
    int          **map;
}              t_map;

t_map *map_create(int width, int height);
void map_destroy(t_map *map);
void map_set(t_map *map, int x, int y, int value);
int map_get(t_map *map, int x, int y);
void map_print(t_map *map);

t_vector2 vector2_create(long x, long y);
t_vector2 vector2_add(t_vector2 a, t_vector2 b);
t_vector2 vector2_sub(t_vector2 a, t_vector2 b);
t_vector2 vector2_mul(t_vector2 a, long scalar);
t_vector2 vector2_div(t_vector2 a, long scalar);
long vector2_dot(t_vector2 a, t_vector2 b);
long vector2_cross(t_vector2 a, t_vector2 b);
long vector2_length(t_vector2 a);
t_vector2 vector2_normalize(t_vector2 a);

t_raycast raycast_create(t_vector2 origin, t_vector2 direction);
t_vector2 raycast_cast(t_raycast raycast, t_map *map);

t_transform transform_create(t_vector2 position, t_vector2 rotation);
t_vector2 transform_forward(t_transform transform);
t_vector2 transform_right(t_transform transform);
t_vector2 transform_up(t_transform transform);

t_physics physics_create(t_vector2 position, t_vector2 rotation);
void physics_move(t_physics *physics, t_vector2 direction);
void physics_rotate(t_physics *physics, t_vector2 rotation);

#endif