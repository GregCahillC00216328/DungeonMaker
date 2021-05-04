#ifndef FACTORY
#define FACTORY
#include "MapObj.h"

class Factory
{
public:
	virtual MapObj* initEntitySq(Entity& t_ent, Vector2 t_pos, Vector2 t_size, std::string t_str, bool t_isAnim, SDL_Renderer& t_renderer) = 0;
	
};
#endif	//!FACTORY

#ifndef OBJFACTORY
#define OBJFACTORY
class ObjFactory : public Factory
{
private:
	MapObj* m_testVar;
public:
	MapObj* initEntitySq(Entity& t_ent, Vector2 t_pos, Vector2 t_size, std::string t_str, bool t_isAnim, SDL_Renderer& t_renderer);
};
#endif	//!OBJFACTORY