#include "Factory.h"

MapObj* ObjFactory::initEntitySq(Entity& t_ent, Vector2 t_pos, Vector2 t_size, std::string t_str, bool t_isAnim, SDL_Renderer& t_renderer)
{
	t_ent.addComponent<PositionComponent>();
	t_ent.addComponent<BodyComponent>();
	t_ent.addComponent<SpriteComponent>();
	t_ent.addComponent<AudioComponent>();
	t_ent.getComponent<PositionComponent>().setPosition(t_pos);
	t_ent.getComponent<BodyComponent>().setSize(t_size);
	t_ent.getComponent< SpriteComponent>().setPathAndScreen(t_str, &t_renderer, t_isAnim);
	t_ent.getComponent< SpriteComponent>().setPosAndSize(t_ent.getComponent<PositionComponent>().getPosition().X(), t_ent.getComponent<PositionComponent>().getPosition().Y(),
	t_ent.getComponent<BodyComponent>().getSize().X(), t_ent.getComponent<BodyComponent>().getSize().Y());
}

