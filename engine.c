#include "engine.h"

t_map *map_create(int width, int height)
{
    t_map *map = malloc(sizeof(t_map));
    map->width = width;
    map->height = height;
    map->map = malloc(sizeof(int *) * height);
    for (int i = 0; i < height; i++)
    {
        map->map[i] = malloc(sizeof(int) * width);
        for (int j = 0; j < width; j++)
            map->map[i][j] = 0;
    }
    return map;
}

void map_destroy(t_map *map)
{
    for (int i = 0; i < map->height; i++)
        free(map->map[i]);
    free(map->map);
    free(map);
}

void map_set(t_map *map, int x, int y, int value)
{
    map->map[y][x] = value;
}

int map_get(t_map *map, int x, int y)
{
    return map->map[y][x];
}

void map_print(t_map *map)
{
    for (int i = 0; i < map->height; i++)
    {
        for (int j = 0; j < map->width; j++)
            printf("%d ", map->map[i][j]);
        printf("\n");
    }
}

t_vector2 vector2_create(long x, long y)
{
    t_vector2 vector;
    vector.x = x;
    vector.y = y;
    return vector;
}

t_vector2 vector2_add(t_vector2 a, t_vector2 b)
{
    return vector2_create(a.x + b.x, a.y + b.y);
}

t_vector2 vector2_sub(t_vector2 a, t_vector2 b)
{
    return vector2_create(a.x - b.x, a.y - b.y);
}

t_vector2 vector2_mul(t_vector2 a, long scalar)
{
    return vector2_create(a.x * scalar, a.y * scalar);
}

t_vector2 vector2_div(t_vector2 a, long scalar)
{
    return vector2_create(a.x / scalar, a.y / scalar);
}

long vector2_dot(t_vector2 a, t_vector2 b)
{
    return a.x * b.x + a.y * b.y;
}

long vector2_cross(t_vector2 a, t_vector2 b)
{
    return a.x * b.y - a.y * b.x;
}

long vector2_length(t_vector2 a)
{
    return sqrt(a.x * a.x + a.y * a.y);
}

t_vector2 vector2_normalize(t_vector2 a)
{
    return vector2_div(a, vector2_length(a));
}

t_raycast raycast_create(t_vector2 origin, t_vector2 direction)
{
    t_raycast raycast;
    raycast.origin = origin;
    raycast.direction = direction;
    return raycast;
}

t_vector2 raycast_cast(t_raycast raycast, t_map *map)
{
    t_vector2 step = vector2_create(raycast.direction.x < 0 ? -1 : 1, raycast.direction.y < 0 ? -1 : 1);
    t_vector2 delta = vector2_create(fabs(1 / raycast.direction.x), fabs(1 / raycast.direction.y));
    t_vector2 side_dist = vector2_create(raycast.direction.x < 0 ? (raycast.origin.x - map->width) * delta.x : (map->width - raycast.origin.x) * delta.x,
                                         raycast.direction.y < 0 ? (raycast.origin.y - map->height) * delta.y : (map->height - raycast.origin.y) * delta.y);
    t_vector2 map_pos = vector2_create((long)raycast.origin.x, (long)raycast.origin.y);
    t_vector2 step_pos = vector2_create(0, 0);
    while (map_get(map, map_pos.x, map_pos.y) == 0)
    {
        if (side_dist.x < side_dist.y)
        {
            side_dist.x += delta.x;
            map_pos.x += step.x;
            step_pos.x = 0;
        }
        else
        {
            side_dist.y += delta.y;
            map_pos.y += step.y;
            step_pos.y = 1;
        }
    }
    return map_pos;
}

t_transform transform_create(t_vector2 position, t_vector2 rotation)
{
    t_transform transform;
    transform.position = position;
    transform.rotation = rotation;
    return transform;
}

t_vector2 transform_forward(t_transform transform)
{
    return vector2_create(cos(transform.rotation.x) * cos(transform.rotation.y), sin(transform.rotation.x) * cos(transform.rotation.y));
}

t_vector2 transform_right(t_transform transform)
{
    return vector2_create(-sin(transform.rotation.x), cos(transform.rotation.x));
}

t_vector2 transform_up(t_transform transform)
{
    return vector2_create(sin(transform.rotation.y), cos(transform.rotation.y));
}

t_physics physics_create(t_vector2 position, t_vector2 rotation)
{
    t_physics physics;
    physics.raycast = raycast_create(position, rotation);
    physics.transform = transform_create(position, rotation);
    return physics;
}

void physics_move(t_physics *physics, t_vector2 direction)
{
    physics->raycast.origin = vector2_add(physics->raycast.origin, direction);
    physics->transform.position = physics->raycast.origin;
}

void physics_rotate(t_physics *physics, t_vector2 rotation)
{
    physics->transform.rotation = vector2_add(physics->transform.rotation, rotation);
    physics->raycast.direction = vector2_create(cos(physics->transform.rotation.x) * cos(physics->transform.rotation.y), sin(physics->transform.rotation.x) * cos(physics->transform.rotation.y));
}

void physics_update(t_physics *physics, t_map *map)
{
    t_vector2 forward = transform_forward(physics->transform);
    t_vector2 right = transform_right(physics->transform);
    t_vector2 up = transform_up(physics->transform);
    if (GetKeyState('W') & 0x8000)
        physics_move(physics, forward);
    if (GetKeyState('S') & 0x8000)
        physics_move(physics, vector2_mul(forward, -1));
    if (GetKeyState('D') & 0x8000)
        physics_move(physics, right);
    if (GetKeyState('A') & 0x8000)
        physics_move(physics, vector2_mul(right, -1));
    physics->raycast = raycast_create(physics->transform.position, physics->transform.rotation);
    t_vector2 hit = raycast_cast(physics->raycast, map);
    if (hit.x != physics->transform.position.x || hit.y != physics->transform.position.y)
        physics->transform.position = hit;
}
