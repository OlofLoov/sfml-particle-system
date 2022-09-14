#include "ParticleSystemMenuView.hpp"

ParticleSystemMenuView::ParticleSystemMenuView(ParticleEmitterSettings &emitterSettings, sf::RenderWindow &window, ParticleEmitter &particleEmitter) : _emitterSettings(emitterSettings), _window(window), _particleEmitter(particleEmitter)
{
    m_widgetHelper.onChanged = [&]() {
        _particleEmitter.updateSettings(_emitterSettings);
    };
}

void ParticleSystemMenuView::update(float deltaTime)
{
    ImGui::SFML::Update(_window, m_deltaClock.restart());
}

void ParticleSystemMenuView::render()
{
    ImGui::Begin("Particle Emittering Settings");
    
    if (ImGui::TreeNode("Color Settings"))
    {
        m_widgetHelper.colorEdit4("Start Color", _emitterSettings.colorBegin);
        m_widgetHelper.colorEdit4("End Color", _emitterSettings.colorEnd);
        ImGui::TreePop();
        ImGui::Separator();
    }

    if (ImGui::TreeNode("Emit Settings"))
    {
        m_widgetHelper.checkbox("Continously", &_emitterSettings.continously);
        m_widgetHelper.checkbox("Emit at mouse pos", &_emitterSettings.emitAtMouse);
        m_widgetHelper.dragInt("Emit Count", &_emitterSettings.emitCount, 1, 1000);

        m_widgetHelper.checkbox("Variation", &_emitterSettings.emitVariationOverTime);
        m_widgetHelper.dragInt("step size", &_emitterSettings.emitVariationStepSize, 1, 50);
        m_widgetHelper.dragInt("max count", &_emitterSettings.emitVariationMaxCount, 1, 500);

        // spawn pos size capped by width
        m_widgetHelper.dragInt2("Emit Position {x,y}", _emitterSettings.emitPos, 1, _window.getSize().x);

        ImGui::TreePop();
        ImGui::Separator();
    }

    if (ImGui::TreeNode("Direction Options"))
    {
        m_widgetHelper.dragInt2("{min, max}", _emitterSettings.angle, 0, 360);
        m_widgetHelper.dragInt("Offset", &_emitterSettings.angleOffset, 0, 180);
        m_widgetHelper.checkbox("Change over time", &_emitterSettings.angleOffsetOverTime);
        m_widgetHelper.dragInt("Increment", &_emitterSettings.angleOffsetIncrement, 0, 10);

        ImGui::TreePop();
        ImGui::Separator();
    }

    if (ImGui::TreeNode("Life Time Options"))
    {
        m_widgetHelper.dragFloat("Life Time", &_emitterSettings.lifeTime, 0.1f, 10.f);
        m_widgetHelper.checkbox("Vary", &_emitterSettings.varyLifeDuration);
        m_widgetHelper.dragFloat("Variation", &_emitterSettings.lifeVariation, 0.1f, 2.f);
        ImGui::TreePop();
        ImGui::Separator();
    }

    if (ImGui::TreeNode("Velocity Options"))
    {
        m_widgetHelper.dragFloat2("Velocity", _emitterSettings.velocity, -10.f, 10.f);
        m_widgetHelper.checkbox("Vary velocity", &_emitterSettings.varySpeed);
        m_widgetHelper.dragFloat("Variation", &_emitterSettings.speedVariation, 0.1f, 3.f);
        m_widgetHelper.checkbox("Mouse attracts particles", &_emitterSettings.mouseAttracts);
        m_widgetHelper.dragInt("strength", &_emitterSettings.mouseAttractStrength, 1, 200);
        ImGui::TreePop();
        ImGui::Separator();
    }

    if (ImGui::Button("Emit"))
    {
        _particleEmitter.emit(_emitterSettings);
    }

    ImGui::SameLine();
    
    if (ImGui::Button("Stop Emitter"))
    {
        _particleEmitter.clear();
    }

    ImGui::End();
    ImGui::SFML::Render(_window);
}
