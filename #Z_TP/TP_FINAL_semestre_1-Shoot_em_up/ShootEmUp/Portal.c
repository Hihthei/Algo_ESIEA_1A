#include "Portal.h"
#include "Enemy.h"
#include "Common.h"
#include "Scene.h"
#include "Player.h"

Portal* Portal_New(Scene* scene, int type, void* linked, Vec2 position)
{
    Portal* self = (Portal*)calloc(1, sizeof(Portal));
    AssertNew(self);

    self->scene = scene;
    self->position = position;
    self->linked_portal = linked;

    Assets* assets = Scene_GetAssets(self->scene);

    switch (type)
    {
    case RED_PORTAL:
        self->texture = assets->portal[1];
        self->radius = 0.4f;
        break;

    default:
    BLUE_PORTAL:
        self->texture = assets->portal[0];
        self->radius = 0.4f;
        break;
    }
    return self;
}


void Portal_Update(Portal *self) //TODO
{
    if (self->scene->waveIdx != 1)
    {
        self->state = CLOSE_PORTAL;
    }
}    


void Portal_Teleport(Player *self, Portal *source)
{
    Vec2 radius = { 0.2, 0.2 };
    self->position = new_position(source, radius);
}

void Portal_Delete(Portal* self)
{
    if (!self) return;

    self->update(NULL);
    self->update(NULL);

    free(self);
}
