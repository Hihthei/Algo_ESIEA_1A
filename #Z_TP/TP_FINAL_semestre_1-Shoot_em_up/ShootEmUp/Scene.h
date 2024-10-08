#pragma once

#include "Settings.h"
#include "Common.h"

#include "Assets.h"
#include "Camera.h"
#include "Input.h"
#include "Bullet.h"
#include "Player.h"
#include "Enemy.h"
#include "uicomponents.h"
#include "mixer.h"
#include "Portal.h"

// Nombre maximal d'ennemis actifs dans un niveau.
#define ENEMY_CAPACITY 32

// Nombre maximal de projectiles actifs dans un niveau.
#define BULLET_CAPACITY 1024

// Maximum of UI Elements (Components) that the scene can hold.
#define UIC_CAPACITY 32

// Maximum number of waves.
#define WAVES_CAPACITY 10

// Maximum number of portal
#define PORTAL_CAPACITY 4

struct UiElement_t;
struct Scene_s;

typedef void (*void_scene_level_func_ptr)(struct Scene_s *);

/// @brief Structure repr�sentant la sc�ne principale du jeu (niveau).
typedef struct Scene_s
{
    /// @brief Moteur de rendu.
    SDL_Renderer *renderer;

    /// @brief Assets de la sc�ne (textures, musiques, sons...)
    Assets *assets;

    /// @brief Cam�ra par laquelle est vue la sc�ne.
    Camera *camera;

    /// @brief Entr�e utilisateur.
    Input *input;

	/// @brief Sound mixer of the scene.
	Mixer *mixer;

    /// @brief Joueur principal.
    Player *player;

    /// @brief Tableau contenant les ennemis courrants.
    Enemy *enemies[ENEMY_CAPACITY];

    /// @brief Nombre d'ennemis courrants.
    int enemyCount;

    /// @brief Tableau contenant les projectiles courrants.
    Bullet *bullets[BULLET_CAPACITY];

    /// @brief Nombre de projectiles courrants.
    int bulletCount;

    /// @brief Tableau contenant les portails actifs.
    Portal *portals[PORTAL_CAPACITY];

    /// @brief Nombre de portails actifs.
    int portalsCount;

	/// @brief Les ?l?ments visuels ind?pendants de la sc?ne.
	struct UiElement_t *elements[UIC_CAPACITY];

	/// @brief Nombres d'?l?ments visuels hors sc?ne.
	int uicCount;

    /// @brief Indice de la vague d'ennemis courrante.
    /// Utilis� pour impl�menter un niveau complet.
    int waveIdx;

	/// @brief Functions handling generation of the different levels.
	void_scene_level_func_ptr waves[WAVES_CAPACITY];

	bool ui_mode;
} Scene;

/// @brief Cr�e la sc�ne principale du jeu.
/// @param renderer moteur de rendu.
/// @return La sc�ne cr��e.
Scene *Scene_New(SDL_Renderer *renderer);

/// \brief Triggers loading of required resources.
/// \param self la sc?ne.
void Scene_Load(Scene *self);

/// @brief Unload data that is unecessary for a full UI mode (no player or enemies...).
void Scene_Unload(Scene *self);

/// @brief D�truit la sc�ne principale.
/// @param self la sc�ne.
void Scene_Delete(Scene *self);

/// @brief Met � jour la sc�ne.
/// Cette fonction est appel�e � chaque tour de la boucle de rendu.
/// @param self la sc�ne.
/// @return true s'il faut quitter la boucle de rendu, false sinon.
bool Scene_Update(Scene *self);

/// @brief Dessine la sc�ne dans le moteur de rendu.
/// @param self la sc�ne.
void Scene_Render(Scene *self);

/// @brief Ajoute un nouveau projectile � la sc�ne.
/// @param self la sc�ne.
/// @param bullet le projectile � ajouter (correctement initialis�).
void Scene_AppendBullet(Scene *self, Bullet *bullet);

/// @brief Ajoute un nouveau portail � la sc�ne.
/// @param self la sc�ne.
/// @param portal le portail � ajouter (correctement initialis�).
void Scene_AppendPortal(Scene *self, Portal *portal);

/// @brief Supprime un projectile de la sc�ne.
/// @param self la sc�ne.
/// @param index l'indice du projectile � supprimer dans le tableau self->bullets.
void Scene_RemoveBullet(Scene *self, int index);

/// @brief Ajoute un nouvel ennemi � la sc�ne.
/// @param self la sc�ne.
/// @param enemy l'ennemi � ajouter (correctement initialis�).
void Scene_AppendEnemy(Scene *self, Enemy *enemy);

/// @brief Supprime un ennemi de la sc�ne.
/// @param self la sc�ne.
/// @param index l'indice du l'ennemi � supprimer dans le tableau self->enemies.
void Scene_RemoveEnemy(Scene *self, int index);

/// @brief Add a UI component to the scene.
/// @param self the scene.
/// @param e the UI component/element.
void Scene_AddUiElement(Scene *self, struct UiElement_t *e);

/// @brief Remove a UI component tha you've set.
/// @brief self the scene.
/// @brief e the UI component/element to remove.
void Scene_RemoveUiElement(Scene *self, struct UiElement_t *e);

/// @brief Remove all UI elements of the scene.
/// @brief self the scene.
void Scene_RemoveAllUiElements(Scene *self);

/// @brief Change the current level (wave index).
/// @param self the scene.
/// @param index the level (wave index).
void Scene_SetWaveIndex(Scene *scene, int index);

/// @brief Renvoie le moteur de rendu de la sc�ne.
/// @param self la sc�ne.
/// @return Le moteur de rendu de la sc�ne.
INLINE SDL_Renderer *Scene_GetRenderer(Scene *self)
{
    return self->renderer;
}

/// @brief Renvoie les assets de la sc�ne.
/// @param self la sc�ne.
/// @return Les assets de la sc�ne.
INLINE Assets *Scene_GetAssets(Scene *self)
{
    return self->assets;
}

/// @brief Renvoie la cam�ra de la sc�ne.
/// @param self la sc�ne.
/// @return La cam�ra de la sc�ne.
INLINE Camera *Scene_GetCamera(Scene *self)
{
    return self->camera;
}

/// @brief Renvoie les entr�e utilisateur de la sc�ne.
/// @param self la sc�ne.
/// @return Les entr�e utilisateur de la sc�ne.
INLINE Input *Scene_GetInput(Scene *self)
{
    return self->input;
}
