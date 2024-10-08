#pragma once

#include "Settings.h"
#include "Math.h"
#include "patterns.h"
#include "Portal.h"

typedef struct Scene_s Scene;
typedef struct Enemy_s Enemy;

/// @brief Enum�ration repr�sentant les �tats possibles du joueur.
typedef enum PlayerState_e
{
    /// @brief Etat par d�faut du joueur.
    PLAYER_FLYING,

    /// @brief Etat du joueur quand il joue l'animation de destruction.
    PLAYER_DYING,

    /// @brief Etat du joueur quand il est mort et que son animation de
    /// destruction est termin�e.
    PLAYER_DEAD,
} PlayerState;

/// @brief Structure repr�sentant le joueur.
typedef struct Player_s
{
    /// @brief Sc�ne associ�e.
    Scene *scene;

    /// @brief Texture utilis�e pour le rendu.
    SDL_Texture *texture;

    /// @brief Position du joueur exprim�e dans le r�f�rentiel monde.
    Vec2 position;

    /// @brief Etat du joueur.
    /// Les valeurs possibles sont d�finies dans PlayerState.
    int state;

    /// @brief Rayon du joueur exprim� dans le r�f�rentiel monde.
    /// Il est utilis� dans le moteur physique pour tester les collisions.
    float radius;

	/// \brief Last time the user has raised an attack.
	float lastAttack;

	/// \brief Last time the user has raised a special attack.
	float lastSpecialAttack;

	/// \brief Remaining life
	int lifePoints;

	void_player_func_ptr update;
	void_player_func_ptr updatePos;
	func_ptr playerCollision;
	func_ptr playerDead;
	PatternData _data[2];

} Player;

/// @brief Cr�e un nouveau joueur.
/// @param scene la sc�ne.
/// @return Le joueur cr��.
Player *Player_New(Scene *scene);

/// @brief D�truit un joueur.
/// @param self le joueur.
void Player_Delete(Player *self);

/// @brief Met � jour le joueur.
/// @param self le joueur.
void Player_Update(Player *self);

/// @brief Dessine le joueur dans le moteur de rendu.
/// @param self le joueur.
void Player_Render(Player *self);

/// @brief Inflige des dommages au joueur.
/// @param self le joueur.
/// @param damage la quantit� de dommages (nombre de points de vie � perdre).
void Player_Damage(Player *self, int damage, struct Bullet_s *bullet);

/// \brief Player_Ship_Collision
/// \param self the player
/// \param source, the ship that collapsed with the player.
void Player_Ship_Collision(Player *self, Enemy *source);

/// \brief Player_Portal_Collision
/// \param self the player
/// \param source, the portal that collapsed with the player.
void Player_Portal_Collision(Player* self, Portal* source);