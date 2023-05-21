#pragma once

#include <SFML/Graphics.hpp>

#include <vector>

class SceneNode : public sf::Transformable, public sf::Drawable, private sf::NonCopyable
{
    public:
        typedef std::unique_ptr<SceneNode> NodePtr;

        SceneNode();

        void update(const sf::Time& deltaTime);

        void attachChild(NodePtr child);
        NodePtr detatchChild(const SceneNode& node);

        sf::Transform getWorldTransform() const;
        sf::Vector2f getWorldPosition() const;

    private:
        std::vector<NodePtr> children;
        SceneNode* parent;

        virtual void updateCurrent(const sf::Time& deltaTime);
        void updateChildren(const sf::Time& deltaTime);

        virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
        virtual void drawCurrent(sf::RenderTarget& target, sf::RenderStates states) const;

};
