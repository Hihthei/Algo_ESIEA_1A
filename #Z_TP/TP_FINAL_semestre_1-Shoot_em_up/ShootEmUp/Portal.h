#pragma once

#include "Scene.h"
#include "patterns.h"
#include "Settings.h"

typedef struct Scene_s Scene;

typedef enum PortalType_e
{
    /// @brief Portail rouge
    RED_PORTAL,

    /// @brief Portail bleu
    BLUE_PORTAL,

    /// @brief Portail ouvert
    OPEN_PORTAL,

    /// @brief Portail fermé
    CLOSE_PORTAL,

} PortalType;

//création d'un objet protail

typedef struct Portal_s
{
    /// @brief Scène associée.
    Scene* scene;

    /// @brief Texture utilisée pour le rendu.
    SDL_Texture* texture;

    /// @brief Position de l'ennemi exprimée dans le référentiel monde.
    Vec2 position;

    /// \Initial position
    Vec2 position_initial;

    /// @brief Donne l'état du portail, ouvert ou fermé
    int state;

    /// @brief Largeur de la texture du portail
    /// exprimée dans le référentiel monde.
    float worldW;

    /// @brief Hauteur de la texture du portail
    /// exprimée dans le référentiel monde.
    float worldH;

    /// @brief Rayon du portal exprimé dans le référentiel monde.
    /// Il est utilisé dans le moteur physique pour tester les collisions.
    float radius;

    /// \brief Utilisé pour savoir si il faut mettre à jour le portail
    bool firstUpdate;

    /// @brief Pointeur vers le portail associé
    struct Portal_s* linked_portal;

    void_bullet_func_ptr update;

}Portal;

/// @brief Créer un portail et l'ajoute à la scène via la méthode Scene_AppendBullet();
/// @param scene la scène.
/// @param type le type du projectile.
/// @param lindek le portail auquel il est lié
/// @param position la position de départ du portail exprimée dans le référentiel monde.
/// @return Le projectile créé.
Portal* Portal_New(Scene* scene, int type, void* linked, Vec2 position);

/// @brief Update du portail
void Portal_Update(Portal* self);

/// @brief Téléporte le joueur à la position du portail suivant
/// @param player le joueur
/// @param source le portail source
void Portal_Teleport(Player* player, Portal* source);

void Portal_Delete(Portal *self);