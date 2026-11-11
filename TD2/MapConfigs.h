#pragma once
#include "Vector2Int.h"
#include <Novice.h>
namespace MapConfig
{
    inline constexpr int kWindowWidth = 1280;
    inline constexpr int kWindowHeight = 720;
    inline constexpr char WallChar = '#';
    inline constexpr char FloorChar = '.';
    inline constexpr char PlayerChar = '@';
    inline constexpr char ScavengerChar = 'S';
    inline constexpr char ProtectorChar = 'P';
    inline constexpr char DestroyerChar = 'D';
    inline constexpr char VerticalChar = 'V';
    inline constexpr char HorizontalChar = 'H';
    inline constexpr char CrossChar = 'C';
    inline constexpr char TripleChar = 'T';
    inline constexpr char MirrorChar = '|';
    inline constexpr char AsteroidChar = 'A';
    inline constexpr int LevelsCount = 4;
    inline constexpr int MapRows = 23;
    inline constexpr int MapCols = 40;
    inline constexpr float TileWidth = 32.0f;
    inline constexpr float TileHeight = 32.0f;
    inline constexpr char  kShortSymbol = '0';
    inline constexpr char  kLongSymbol = '1';
    inline constexpr int kTaskSpeed = 10;
    inline constexpr int kImageWidth = 32;
    inline constexpr Vector2Int kTaskPosOnScreen = { 100,100 };
    inline constexpr Vector2Int kDialoguePosOnScreen = { 140,480 };
    inline constexpr int kTaskTimer = 300;
    inline constexpr Vector2Int kTimerPosOnScreen = { 140,50 };
    inline constexpr Vector2Int kManualPosOnScreen = { 936,100 };
    inline constexpr float kTaskTimerWidth = 1000;
    inline constexpr int kFirstStageTaskCount = 3;
    inline constexpr int kSecondStageTaskCount = 3;
    inline constexpr int kThirdStageTaskCount = 3;
}