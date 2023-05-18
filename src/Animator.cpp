#include "Animator.h"

#include "AssetManager.h"

Animator::Animator(sf::Sprite& sprite)
    : sprite{sprite}, currentTime{}, currentAnimation{nullptr}
{ }

Animator::Animation& Animator::createAnimation(const std::string& name,
                                               const std::string& textureName,
                                               const sf::Time& duration,
                                               const bool& isLoop)
{
    animations.push_back(Animator::Animation(name, textureName, duration, isLoop));

    if (currentAnimation == nullptr)
        switchAnimation(&animations.back());

    return animations.back();
}

void Animator::switchAnimation(Animator::Animation* animation)
{
    if (animation != nullptr)
    {
        sprite.setTexture(AssetManager::getTexture(animation->textureName));
    }

    currentAnimation = animation;
    currentTime = sf::Time::Zero; // Reset the time
}

bool Animator::switchAnimation(const std::string& name)
{
    auto animation = findAnimation(name);

    if (animation != nullptr)
    {
        switchAnimation(animation);

        return true;
    }

    return false;
}

Animator::Animation* Animator::findAnimation(const std::string& name)
{
    for (auto it = animations.begin(); it != animations.end(); ++it)
    {
        if (it->name == name)
        {
            return &*it;
        }
    }

    return nullptr;
}

std::string Animator::getCurrentAnimationName() const
{
    if (currentAnimation != nullptr)
        return currentAnimation->name;

    return "";
}

void Animator::update(const sf::Time& deltaTime)
{
    if (currentAnimation == nullptr)
        return;

    currentTime += deltaTime;

    float scaledTime = (currentTime.asSeconds() / currentAnimation->duration.asSeconds());
    int numFrames = currentAnimation->frames.size();
    int currentFrame = static_cast<int>(scaledTime * numFrames);

    if (currentAnimation->isLooping)
        currentFrame %= numFrames; // TODO fails if no frames have been added...
    else if (currentFrame >= numFrames)
        currentFrame = numFrames-1;

    sprite.setTextureRect(currentAnimation->frames[currentFrame]);
}
