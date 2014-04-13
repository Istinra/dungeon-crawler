#include "RenderableComponent.h"


RenderableComponent::RenderableComponent(Entity &parent, Sprite *sprite) : AbstractComponent(parent), sprite(sprite)
{
}


RenderableComponent::~RenderableComponent()
{
}
