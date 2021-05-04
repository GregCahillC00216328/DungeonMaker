#ifndef MAPOBJ
#define MAPOBJ
#include <iostream>
#include "Entity.h"
#include "Vector2.h"
#include "AudioComponent.h"
#include "BodyComponent.h"
#include "SpriteComponent.h"
#include "PositionComponent.h"
#include "EntityManager.h"

class MapObj
{
public:
	MapObj() {}
	virtual ~MapObj() {}
	virtual void addEntityFromFactory(Entity& t_ent) = 0;
};
#endif // !MAPOBJ

#ifndef MAPSQ
#define MAPSQ
class MapSq : public MapObj
{

public:
	void addEntityFromFactory(Entity& t_ent) { std::cout << "Entity square" << std::endl; }
};
#endif	//!MAPSQ


