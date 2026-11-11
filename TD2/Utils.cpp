#include "Utils.h"
#include "Vector2.h"
#include "Vector2Int.h"
#include "MapConfigs.h"
namespace Utils
{
	Vector2 TileToGlobal(Vector2Int tilePos)
	{
		float x = tilePos.x * MapConfig::TileWidth + MapConfig::TileWidth / 2;
		float y = tilePos.y * MapConfig::TileHeight + MapConfig::TileHeight / 2;
		return Vector2(x, y);
	}
	Vector2Int GlobalToLocal(Vector2 globalPos)
	{
		int x = static_cast<int>(globalPos.x);
		int y = static_cast<int>(MapConfig::kWindowHeight - globalPos.y);
		return Vector2Int(x, y);
	}
	Vector2Int GlobalToTile(Vector2 globalPos)
	{
		int x = static_cast<int>(globalPos.x / MapConfig::TileWidth);
		int y = static_cast<int>(globalPos.y / MapConfig::TileHeight);
		return Vector2Int(x, y);
	}
	Vector2Int TileToLocal(Vector2Int tilePos)
	{
		return GlobalToLocal(TileToGlobal(tilePos));
	}
}