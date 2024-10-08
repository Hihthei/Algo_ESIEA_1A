#include "LevelParser.h"
#include "StaticMap.h"
#include "Brick.h"
#include "LevelScene.h"
#include "Checkpoint.h"
#include "Nut.h"
#include "LevelEnd.h"
#include "Bonus.h"
#include "Camera.h"

// TODO : Ajouter le fichier "Firefly.h"

LevelParser::LevelParser(const std::string &path)
{
    FILE *levelFile = fopen(path.c_str(), "rb");
    AssertNew(levelFile);

    bool isValidChar[128] = { 0 };
    isValidChar['\n'] = true;
    for (int i = '!'; i < '~'; i++)
    {
        isValidChar[i] = true;
    }

    fseek(levelFile, 0, SEEK_END);
    long fileSize = ftell(levelFile);
    rewind(levelFile);

    char *buffer = new char[fileSize];
    fread(buffer, 1, fileSize, levelFile);
    fclose(levelFile);
    levelFile = NULL;

    int height = 0;
    int width = 0;
    int i;
    for (i = 0; i < fileSize; i++)
    {
        char c = buffer[i];
        if (isValidChar[(int)c])
        {
            if (c == '\n')
            {
                height = 1;
                break;
            }
            else
            {
                width++;
            }
        }
        else
        {
            printf("INFO - Invalid char (%c)\n", c);
        }
    }
    if (height == 0)
    {
        printf("ERROR - Incorrect level file\n");
        assert(false);
        abort();
    }
    int w = 0;
    for (i = i + 1; i < fileSize; ++i)
    {
        char c = buffer[i];
        if (isValidChar[(int)c])
        {
            if (c == '\n')
            {
                if (w == 0)
                {
                    break;
                }
                height++;

                if (w != width)
                {
                    printf("ERROR - Incorrect level file\n");
                    assert(false);
                    abort();
                }
                w = 0;
            }
            else
            {
                w++;
            }
        }
        else
        {
            printf("INFO - Invalid char (%c)\n", c);
        }
    }

    // Initialisation du parser
    m_width = width;
    m_height = height;

    m_matrix = new char *[m_width];
    for (int x = 0; x < width; ++x)
    {
        m_matrix[x] = new char[height];
    }

    // Remplissage de la matrice du niveau
    int x = 0;
    int y = height - 1;
    for (i = 0; i < fileSize; ++i)
    {
        char c = buffer[i];
        if (isValidChar[(int)c])
        {
            if (c == '\n')
            {
                x = 0;
                y--;
                if (y < 0)
                {
                    break;
                }
            }
            else
            {
                m_matrix[x][y] = c;
                x++;
            }
        }
    }

    delete[] buffer;
}

LevelParser::~LevelParser()
{
    if (m_matrix)
    {
        for (int i = 0; i < m_width; ++i)
        {
            delete[] m_matrix[i];
        }
        delete[] m_matrix;
    }
}

void LevelParser::InitScene(LevelScene &scene) const
{
    // Cr�e la TileMap
    StaticMap *map = new StaticMap(scene, m_width, m_height);

    for (int x = 0; x < m_width; ++x)
    {
        for (int y = 0; y < m_height; ++y)
        {
            PE_Vec2 position((float)x, (float)y);
            switch (m_matrix[x][y])
            {
            case '#':
                map->SetTile(x, y, Tile::Type::GROUND);
                break;
            case 'W':
                map->SetTile(x, y, Tile::Type::WOOD);
                break;
            case '=':
                map->SetTile(x, y, Tile::Type::ONE_WAY);
                break;
            case 'A':
                map->SetTile(x, y, Tile::Type::SPIKE);
                break;
            case '\\':
                map->SetTile(x, y, Tile::Type::STEEP_SLOPE_L);
                break;
            case '/':
                map->SetTile(x, y, Tile::Type::STEEP_SLOPE_R);
                break;
            case 'L':
                map->SetTile(x, y, Tile::Type::GENTLE_SLOPE_L1);
                break;
            case 'l':
                map->SetTile(x, y, Tile::Type::GENTLE_SLOPE_L2);
                break;
            case 'r':
                map->SetTile(x, y, Tile::Type::GENTLE_SLOPE_R1);
                break;
            case 'R':
                map->SetTile(x, y, Tile::Type::GENTLE_SLOPE_R2);
                break;
            case 'S':
            {
                Player *player = scene.GetPlayer();
                player->SetStartPosition(position);
                break;
            }
            case 'F':
            {
                LevelEnd *levelEnd = new LevelEnd(scene);
                levelEnd->SetStartPosition(position);
                break;
            }
            case 'e':
            {
                Nut *nut = new Nut(scene);
                nut->SetStartPosition(position);
                break;
            }
            case 'o':
            {
                // TODO : Cr�er une luciolle
                break;
            }
            default:
                break;
            }
        }
    }
    map->InitTiles();

    PE_AABB bounds(0.0f, 0.0f, (float)m_width, 24.0f * 9.0f / 16.0f);
    Camera *camera = scene.GetActiveCamera();
    camera->SetWorldBounds(bounds);
}
