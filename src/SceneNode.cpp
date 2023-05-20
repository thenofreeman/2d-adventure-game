#include "SceneNode.h"

#include <cassert>

SceneNode::SceneNode()
{ }

void SceneNode::attachChild(NodePtr child)
{
    child->parent = this;
    children.push_back(std::move(child));
}

SceneNode::NodePtr SceneNode::detatchChild(const SceneNode& node)
{
    auto found = std::find_if(children.begin(), children.end(), [&](NodePtr& p) -> bool {
        return p.get() == &node;
    });

    assert(found != children.end());

    NodePtr result = std::move(*found);
    result->parent = nullptr;
    children.erase(found);

    return result;
}

void SceneNode::update(const sf::Time& deltaTime)
{
    updateCurrent(deltaTime);
    updateChildren(deltaTime);
}

void SceneNode::updateCurrent(const sf::Time& deltaTime)
{

}

void SceneNode::updateChildren(const sf::Time& deltaTime)
{
    for (NodePtr& child : children)
    {
        child->update(deltaTime);
    }
}

void SceneNode::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    states.transform *= getTransform();

    drawCurrent(target, states);

    for (const NodePtr& child : children)
    {
        child->draw(target, states);
    }
}

void SceneNode::drawCurrent(sf::RenderTarget& target, sf::RenderStates states) const
{

}

sf::Transform SceneNode::getWorldTransform() const
{
    sf::Transform transform = sf::Transform::Identity;

    for (const SceneNode* node = this; node != nullptr; node = node->parent)
    {
        transform = node->getTransform() * transform;
    }

    return transform;
}

sf::Vector2f SceneNode::getWorldPosition() const
{
    return getWorldTransform() * sf::Vector2f();
}
