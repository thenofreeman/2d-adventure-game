#include <SFML/Graphics>

#include <vector>

class SceneNode : public sf::Transformable, public sf::Drawable, private sf::NonCopyable
{
    public:
        typedef std::unique_ptr<SceneNode> NodePtr;

        SceneNode();

        void attachChild(NodePtr child);
        NodePtr detatchChild(const SceneNode& node);

    private:
        std::vector<NodePtr> children;
        SceneNode* parent;

        virtual void draw(sf::RenderTraget& target, sf::RenderStates states) const;
        virtual void drawCurrent(sf::RenderTarget& target, sf::RenderStates states) const;

};
