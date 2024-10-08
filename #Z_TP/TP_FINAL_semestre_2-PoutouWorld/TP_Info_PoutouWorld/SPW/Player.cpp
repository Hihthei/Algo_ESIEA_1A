﻿#include "Player.h"
#include "Camera.h"
#include "Scene.h"
#include "Collectable.h"
#include "Enemy.h"
#include "Graphics.h"

Player::Player(Scene &scene) :
    GameBody(scene, Layer::PLAYER), m_animator(),
    m_jump(false), m_facingRight(true), m_bounce(false), m_hDirection(0.0f), m_zDirection(0.0f),
    m_lifeCount(3), m_heartCount(3), m_fireflyCount(0), m_state(Player::State::IDLE),
    m_speed(5.0f), m_stateSwitchRunning(false), m_stateRunning(false), m_animSpeedValue(0.8f),
    m_timerDead(0.0f)

{
    m_name = "Player";

    SetToRespawn(true);

    AssetManager &assetsManager = scene.GetAssetManager();
    RE_Atlas *atlas = assetsManager.GetAtlas(AtlasID::PLAYER);
    RE_AtlasPart *part = nullptr;

    // Animation "Idle"
    part = atlas->GetPart("Idle");
    AssertNew(part);
    RE_TexAnim *idleAnim = new RE_TexAnim(
        m_animator, "Idle", part
    );
    idleAnim->SetCycleCount(0);

    // Animation "IdleInvincible"
    part = atlas->GetPart("IdleInvincible");
    AssertNew(part);
    RE_TexAnim* idleInvincibleAnim = new RE_TexAnim(
        m_animator, "IdleInvincible", part
    );
    idleInvincibleAnim->SetCycleCount(-1);
    idleInvincibleAnim->SetCycleTime(0.2f);

    // Animation "Dead"
    part = atlas->GetPart("Dying");
    AssertNew(part);
    RE_TexAnim* dyingAnim = new RE_TexAnim(
        m_animator, "Dying", part
    );
    idleAnim->SetCycleCount(0);

    // DID : ajouter l'animation "Falling"
    part = atlas->GetPart("Falling");
    AssertNew(part);
    RE_TexAnim* fallingAnim = new RE_TexAnim(
        m_animator, "Falling", part
    );
    fallingAnim->SetCycleCount(-1);
    fallingAnim->SetCycleTime(0.2f);

    // Animation "FallingInvincible"
    part = atlas->GetPart("FallingInvincible");
    AssertNew(part);
    RE_TexAnim* fallingInvincibleAnim = new RE_TexAnim(
        m_animator, "FallingInvincible", part
    );
    fallingInvincibleAnim->SetCycleCount(-1);
    fallingInvincibleAnim->SetCycleTime(0.2f);

    // DID : ajouter l'animation "Running"
    part = atlas->GetPart("RunningInvincible");
    AssertNew(part);
    RE_TexAnim* runningInvincibleAnim = new RE_TexAnim(
        m_animator, "RunningInvincible", part
    );
    runningInvincibleAnim->SetCycleCount(-1);
    runningInvincibleAnim->SetCycleTime(0.3f);

    // DID : ajouter l'animation "Running"
    part = atlas->GetPart("Running");
    AssertNew(part);
    RE_TexAnim* runningAnim = new RE_TexAnim(
        m_animator, "Running", part
    );
    runningAnim->SetCycleCount(-1);
    runningAnim->SetCycleTime(0.3f);

    
    // Animation "Drift"
    part = atlas->GetPart("Skidding");
    AssertNew(part);
    RE_TexAnim* driftAnim = new RE_TexAnim(
        m_animator, "Skidding", part
    );
    driftAnim->SetCycleCount(0);

    // Couleur des colliders en debug
    m_debugColor.r = 255;
    m_debugColor.g = 0;
    m_debugColor.b = 0;
}

Player::~Player()
{
}

void Player::Start()
{
    // Joue l'animation par défaut
    m_animator.PlayAnimation("Idle");

    // Crée le corps
    PE_World &world = m_scene.GetWorld();
    PE_BodyDef bodyDef;
    bodyDef.type = PE_BodyType::DYNAMIC;
    bodyDef.position = GetStartPosition() + PE_Vec2(0.5f, 0.0f);
    bodyDef.name = (char *)"Player";
    bodyDef.damping.SetZero();
    PE_Body *body = world.CreateBody(bodyDef);
    SetBody(body);

    // Création du collider
    PE_ColliderDef colliderDef;

    // DID : Donner une taille normale à la capsule
    PE_CapsuleShape capsule(PE_Vec2(0.09f, 0.20f), PE_Vec2(0.09f, 0.78f), 0.20f);
    colliderDef.friction = 2.5f;
    colliderDef.filter.categoryBits = CATEGORY_PLAYER;
    colliderDef.shape = &capsule;
    PE_Collider *collider = body->CreateCollider(colliderDef);
}

void Player::Update()
{
    ControlsInput &controls = m_scene.GetInputManager().GetControls();

    // Sauvegarde les contrôles du joueur pour modifier
    // sa physique au prochain FixedUpdate()
    
	// DID : Mettre à jour l'état du joueur en fonction des contrôles de jump

    m_hDirection = controls.hAxis;
    m_zDirection = controls.goDownDown;

    m_jump = controls.jumpPressed;
    m_jumpHold = controls.jumpDown;
}

void Player::Render()
{
    SDL_Renderer *renderer = m_scene.GetRenderer();
    Camera *camera = m_scene.GetActiveCamera();

    // Met à jour les animations du joueur
    m_animator.Update(m_scene.GetTime());

    float scale = camera->GetWorldToViewScale();
    SDL_RendererFlip flip = m_facingRight ? SDL_FLIP_NONE : SDL_FLIP_HORIZONTAL;
    SDL_FRect rect = { 0 };

    // DID : Trouver les bonnes diemnsions de l'affichage en fonction du sprite (dimensions en tuiles)
    rect.h = 1.2f * scale; 
    rect.w = 1.0f * scale; 
    camera->WorldToView(GetPosition(), rect.x, rect.y);

    // Dessine l'animateur du joueur
    // DID : Trouver le bon anchor
    // DID : position du sprite
    m_animator.RenderCopyExF(
        &rect, RE_Anchor::SOUTH , 0.0f, Vec2(0.5f, 0.5f), flip
    );
}

void Player::FixedUpdate()
{

    PE_Body* body = GetBody();
    PE_Vec2 position = body->GetPosition();

    // DID : Récuperer la vitesse du joueur
    PE_Vec2 velocity = body->GetLocalVelocity();

    // Réveille les corps autour du joueur
    WakeUpSurroundings();


    // test des états du joueur

    // Animation de mort si le joueur meurt

    //    //TODO -> faire en sorte que le jeu s'arrête sauf l'animation du joueur

    if (m_statePlayer == State_Player::DYING)
    {
        body->ApplyForce(PE_Vec2(5.0f, 17.0f));
        body->SetVelocity(PE_Vec2(5.0f, 17.0f));
        m_animator.PlayAnimation("Dying");
        m_statePlayer = State_Player::DEAD;
    }


    // Tue le joueur s'il tombe en dehors de la cate
    if (position.y < -2.0f)
    {
        if (m_lifeCount == 1)
        {
            m_scene.Quit();
            return;
        }

        Kill();
        return;
    }

    if (m_statePlayer == State_Player::DEAD || m_statePlayer == State_Player::DYING)
    {
        m_animator.PlayAnimation("Dying");
        return;
    }

    // Chrono si le joueur et invincible

    if (m_statePlayer == State_Player::INVINCIBLE)
    {
        m_invicibleState = true;

        m_statePlayer = State_Player::INVINCIBLE_DELAY;
    }
    else if (m_invincibleDelay <= 2.0f && m_statePlayer == State_Player::INVINCIBLE_DELAY)
        m_invincibleDelay += m_scene.GetFixedTimeStep();
    else
    {
        m_statePlayer = State_Player::ALIVE;
        m_invincibleDelay = 0.0f;
        m_invicibleState = false;
    }

    //--------------------------------------------------------------------------
    // Détection du sol

    bool m_onGround = false;
    bool m_onSloper = false;
    bool m_onSlopel = false;
    PE_Vec2 gndNormal = PE_Vec2::up;

    // Lance deux rayons vers le bas ayant pour origines
    // les coins gauche et droit du bas du collider du joueur
    // Ces deux rayons sont dessinés en jaune dans DrawGizmos()
    PE_Vec2 originL = position + PE_Vec2(-0.35f, 0.0f);
    PE_Vec2 originR = position + PE_Vec2(+0.35f, 0.0f);

    // Les rayons ne touchent que des colliders solides (non trigger)
    // ayant la catégorie FILTER_TERRAIN
    RayHit hitL = m_scene.RayCast(originL, PE_Vec2::down, 0.35f, CATEGORY_TERRAIN, true);
    RayHit hitR = m_scene.RayCast(originR, PE_Vec2::down, 0.35f, CATEGORY_TERRAIN, true);

    if (hitL.collider != NULL)
    {
        // Le rayon gauche à touché le sol
        m_onGround = true;
        gndNormal = hitL.normal;
    }
    if (hitR.collider != NULL)
    {
        // Le rayon droit à touché le sol
        m_onGround = true;
        gndNormal = hitR.normal;
    }

    //--------------------------------------------------------------------------
    // Etat du joueur

    // Détermine l'état du joueur et change l'animation si nécessaire

    // DID : Ajouter la gestion des animations Idle et Falling
    if (m_invicibleState)
    {
        if (m_onGround)
        {
            if (m_state != State::RUNNING && (m_hDirection > 0.0f || m_hDirection < 0.0f))
            {
                m_state = State::RUNNING;
                m_animator.PlayAnimation("RunningInvincible");
            }
            else if (m_state != State::IDLE && m_hDirection == 0.0f)
            {
                m_state = State::IDLE;
                m_animator.PlayAnimation("IdleInvincible");
            }
        }
        else
        {
            if (m_state != State::FALLING)
            {
                m_state = State::FALLING;
                m_animator.PlayAnimation("FallingInvincible");
            }
        }
    }
    else
    {
        if (m_onGround)
        {
            if (m_state != State::RUNNING && (m_hDirection > 0.0f || m_hDirection < 0.0f))
            {
                m_state = State::RUNNING;
                m_animator.PlayAnimation("Running");
            }
            else if (m_state != State::IDLE && m_hDirection == 0.0f)
            {
                m_state = State::IDLE;
                m_animator.PlayAnimation("Idle");
            }
        }
        else
        {
            if (m_state != State::FALLING)
            {
                m_state = State::FALLING;
                m_animator.PlayAnimation("Falling");
            }
        }
    }
    
    //--------------------------------------------------------------------------


    
    // DID
    // Orientation du joueur
    // Utilisez m_hDirection qui vaut :
    // *  0.0f si le joueur n'accélère pas ;
    // * +1.0f si le joueur accélère vers la droite ;
    // * -1.0f si le joueur accélère vers la gauche.

    // Utilisez m_zDirection qui vaut :
    // *  0.0f si le joueur ne descend pas ;
    // * -1.0f si le joueur descend

    /*
    if (m_zDirection > 0.0f)
    {
        // TODO
        
        j'aimerais touché la taille du collider mais je sais pas à quel point c'est gravissime
        donc j'attends de voir demain avec les profs
        
    }
    else */
        //collider de taille normal

    m_timerSpeed += m_scene.GetFixedTimeStep();

    if (m_hDirection == 0.0f)
    {
        m_speed = 3.0f;
        m_animSpeedValue = 0.5f;
    }
    else if (m_hDirection > 0.0f)
    {
        if (m_facingRight)
            m_stateSwitchRunning = false;

        m_facingRight = true;

        if (m_stateSwitchRunning)
        {
            m_speed = 3.0f;
            m_animSpeedValue = 0.5f;
            m_facingRight = true;
            m_stateSwitchRunning = false;
        }
        else if (m_timerSpeed > 0.7 && m_speed <= 10.0f && m_animSpeedValue <= 1.5f && m_onGround)
        {
            m_speed += 0.1f;
            m_timerSpeed = 0.0f;

            // On met à jour l'animation en fonction de la vitesse
            m_animSpeedValue += 0.01f;

            if (m_invicibleState)
            {
                RE_Animation* anim = m_animator.GetAnimation("RunningInvincible");
                anim->SetSpeed(m_animSpeedValue);
            }
            else
            {
                RE_Animation* anim = m_animator.GetAnimation("Running");
                anim->SetSpeed(m_animSpeedValue);
            }
        }
    }
    else if (m_hDirection < 0.0f)
    {
        if (m_facingRight)
        {
            m_facingRight = false;
            m_stateSwitchRunning = true;
        }

        if (m_stateSwitchRunning)
        {
            m_speed = 3.0f;
            m_animSpeedValue = 0.5f;
            m_facingRight = false;
            m_stateSwitchRunning = false;
        }
        else if (m_timerSpeed > 0.7 && m_speed <= 10.0f && m_animSpeedValue <= 2.8f && m_onGround)
        {
            m_speed += 0.1f;
            m_timerSpeed = 0.0f;

            // On met à jour l'animation en fonction de la vitesse
            m_animSpeedValue += 0.01f;

            if (m_invicibleState)
            {
                RE_Animation* anim = m_animator.GetAnimation("RunningInvincible");
                anim->SetSpeed(m_animSpeedValue);
            }
            else
            {
                RE_Animation* anim = m_animator.GetAnimation("Running");
                anim->SetSpeed(m_animSpeedValue);
            }
        }
    }
    

    //--------------------------------------------------------------------------
    // Modification de la vitesse et application des forces

    // Application des forces
    // Définit la force d'accélération horizontale du joueur
    PE_Vec2 direction = PE_Vec2::right;

    // DID : Donner une valeur cohérente au vecteur force
    PE_Vec2 force = (m_speed * m_hDirection) * direction;
    body->ApplyForce(force);


    // DID : Limiter la vitesse horizontale
    float maxHSpeed = 20.0f;
    velocity.x = PE_Clamp(velocity.x, -maxHSpeed, maxHSpeed);

    /*if (m_jumpHold)
    {
        m_jumpDelay -= m_scene.GetFixedTimeStep();

        if (m_onGround && (m_jumpDelay >= 0.0f))
        {
            printf("%.2f\n", m_jumpDelay);
            velocity.y = 11.0f;
            m_jump = false;
        }

    }
    else
        m_jumpDelay = 0.2; */

    if (m_jumpHold)
    {
        m_jumpDelay = 0.2f;
        if (m_onGround && (m_jumpDelay -= m_scene.GetFixedTimeStep()) >= 0.0f)
        {
            velocity.y = 11.0f;
            m_jump = false;
        }

    }

    body->SetGravityScale(1.0f);

    if (m_jumpHold)
        body->SetGravityScale(0.4f);



    // DID : Rebond sur les ennemis
    if (m_bounce)
    {
        m_bounce = false;
        velocity.y = 15.0f;
    }

    // Remarques :
    // Le facteur de gravité peut être modifié avec l'instruction
    // -> body->SetGravityScale(0.5f);
    // pour faire des sauts de hauteurs différentes.
    // La physique peut être différente si le joueur touche ou non le sol.

    // Définit la nouvelle vitesse du corps
    // DID : Appliquer la nouvelle velocity au player
    body->SetVelocity(velocity);
}

void Player::OnRespawn()
{
    PE_Body *body = GetBody();
    AssertNew(body);

    body->SetPosition(GetStartPosition() + PE_Vec2(0.5f, 0.0f));
    body->SetVelocity(PE_Vec2::zero);

//    m_heartCount = 2;
    m_state = State::IDLE;
    m_hDirection = 0.0f;
    m_fireflyCount = 0;

    m_facingRight = true;
    m_bounce = false;
    m_jump = false;

    m_animator.StopAnimations();
    m_animator.PlayAnimation("Idle");

    SetToRespawn(true);
}

void Player::DrawGizmos()
{
    SDL_Renderer *renderer = m_scene.GetRenderer();
    Graphics graphics(renderer, *m_scene.GetActiveCamera());
    PE_Vec2 position = GetPosition();
    PE_Vec2 velocity = GetVelocity();

    // Dessine en blanc le vecteur vitesse du joueur
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    graphics.DrawVector(0.5f * velocity, position);

    // Dessine en jaune les rayons pour la détection du sol
    SDL_SetRenderDrawColor(renderer, 255, 255, 0, 255);
    PE_Vec2 originL = position + PE_Vec2(-0.5f, 0.0f);
    PE_Vec2 originR = position + PE_Vec2(+0.5f, 0.0f);
    graphics.DrawVector(0.25f * PE_Vec2::down, originL);
    graphics.DrawVector(0.25f * PE_Vec2::down, originR);
}

void Player::OnCollisionEnter(GameCollision &collision)
{
    const PE_Manifold &manifold = collision.manifold;
    PE_Collider *otherCollider = collision.otherCollider;


    // Collision avec un ennemi

    if (otherCollider->CheckCategory(CATEGORY_ENEMY))
    {
        if (m_invicibleState)
            return;
            
        Enemy *enemy = dynamic_cast<Enemy *>(collision.gameBody);
        if (enemy == nullptr)
        {
            assert(false);
            return;
        }

        // Calcule l'angle entre la normale de contact et le vecteur "UP"
        // L'angle vaut :
        // * 0 si le joueur est parfaitement au dessus de l'ennemi,
        // * 90 s'il est à gauche ou à droite
        // * 180 s'il est en dessous
        float angle = PE_AngleDeg(manifold.normal, PE_Vec2::up);
        if (angle < PLAYER_DAMAGE_ANGLE)
        {
            enemy->Damage(this);
            collision.ResolveUp();
        }
        else
        {
            collision.SetEnabled(false);
        }

        return;
    }

    // Collision avec un objet
    if (otherCollider->CheckCategory(CATEGORY_COLLECTABLE))
    {
        Collectable *collectable = dynamic_cast<Collectable *>(collision.gameBody);
        if (collectable == nullptr) return;

        // Collecte l'objet
        // C'est ensuite l'objet qui affecte un bonus au joueur,
        // en appellant AddFirefly() par exemple.
        collectable->Collect(this);
        return;
    }
}

void Player::OnCollisionStay(GameCollision &collision)
{
    const PE_Manifold &manifold = collision.manifold;
    PE_Collider *otherCollider = collision.otherCollider;

    // D�sactiver les collisions lorsque le joueur est en train de mourir
    if (m_statePlayer == State_Player::DEAD)
    {
        collision.SetEnabled(false);
        return;
    }


    if (otherCollider->CheckCategory(CATEGORY_COLLECTABLE))
    {
        // Désactive la collision avec un objet
        // Evite d'arrêter le joueur quand il prend un coeur
        collision.SetEnabled(false);
        return;
    }
    else if (otherCollider->CheckCategory(CATEGORY_TERRAIN))
    {
        float angleUp = PE_AngleDeg(manifold.normal, PE_Vec2::up);
        if (angleUp <= 30.0f)
        {
            // Résoud la collision en déplaçant le joueur vers le haut
            // Evite de "glisser" sur les pentes si le joueur ne bouge pas
            collision.ResolveUp();
        }
    }
    else if (otherCollider->CheckCategory(CATEGORY_ENEMY))
    {
        if(m_invicibleState == true)
            collision.SetEnabled(false);
    }
}

void Player::AddFirefly(int count)
{
    m_fireflyCount += count;
    if (m_fireflyCount >= 30)
    {
        AddLife(1);
        m_fireflyCount = 0;
    }
}

void Player::AddLife(int count)
{
    m_lifeCount += count;
}

void Player::AddHeart(int count)
{
    if (m_heartCount == 4 && count == 1)
    {
        AddLife(1);
        m_heartCount = 3;
    }
    else
        m_heartCount += count;
}

void Player::Damage(int count)
{
    // Méthode appelée par un ennemi qui touche le joueur
    AddHeart(count);

    if (m_heartCount == 0)
    {
        m_statePlayer = State_Player::DEAD;
    }
    else if (m_heartCount >= 1 &&  m_statePlayer != State_Player::DYING && m_statePlayer != State_Player::DEAD )
    {
        m_statePlayer = State_Player::INVINCIBLE;
        m_invicibleState = true;
        Bounce();
    }
        //TODO -> retourner au menu
}

void Player::Kill()
{
    m_statePlayer = State_Player::ALIVE;
    AddLife(-1);
    m_heartCount = 3;
    m_scene.Respawn();
}

class WakeUpCallback : public PE_QueryCallback
{
public:
    WakeUpCallback() {};
    virtual bool ReportCollider(PE_Collider *collider)
    {
        collider->GetBody()->SetAwake(true);
        return true;
    }
};

void Player::WakeUpSurroundings()
{
    PE_World &world = m_scene.GetWorld();
    PE_Vec2 position = GetBody()->GetPosition();
    PE_AABB aabb(
        position.x - 20.0f, position.y - 10.0f,
        position.x + 20.0f, position.y + 10.0f
    );
    WakeUpCallback callback;
    world.QueryAABB(callback, aabb);
}