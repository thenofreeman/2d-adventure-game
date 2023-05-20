#include "SceneNode.h"

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

void SceneNode::draw(sf::RenderTraget& target, sf::RenderStates states) const
{
    states.transform *= getTransform();

    drawCurrent(target, states);

    for (const NodePtr& child : children)
    {
        child->draw(target, states)
    }
}
