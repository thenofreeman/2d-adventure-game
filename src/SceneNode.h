#include <SFML/Graphics>

#include <vector>

class SceneNode : public sf::Transformable, public sf::Drawable, private sf::NonCopyable
{
    public:
        typedef std::unique_ptr<SceneNode> NodePtr;

        SceneNode();

        void update(const sf::Time& dt);

        void attachChild(NodePtr child);
        NodePtr detatchChild(const SceneNode& node);

        sf::Transform getWorldTransform() const;
        sf::Vector2f getWorldPosition() const;

    private:
        std::vector<NodePtr> children;
        SceneNode* parent;

        virtual void updateCurrent(const sf::Time& dt);
        void updateChildren(const sf::Time& dt);

        virtual void draw(sf::RenderTraget& target, sf::RenderStates states) const;
        virtual void drawCurrent(sf::RenderTarget& target, sf::RenderStates states) const;

};
