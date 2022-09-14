#pragma once
#include "ParticleEmitter.hpp"
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/System/Clock.hpp>
#include <SFML/Window/Event.hpp>
#include <imgui-SFML.h>
#include <imgui.h>
#include <iostream>

class WidgetHelper
{
public:
    ~WidgetHelper() {
        std::cout << "Destroying widget helper" << std::endl;
    }

    void checkbox(std::string text, bool *checked)
    {
        if (ImGui::Checkbox(text.c_str(), checked))
            onChanged();
    }

    void dragInt(std::string text, int *value, int min, int max)
    {
        if (ImGui::DragInt(text.c_str(), value, 1, min, max))
            onChanged();
    }

    void dragInt2(std::string text, int *value, int min, int max)
    {
        if (ImGui::DragInt2(text.c_str(), value, 1, min, max))
            onChanged();
    }

    void dragFloat(std::string text, float *value, float min, float max)
    {
        if (ImGui::DragFloat(text.c_str(), value, 1.0f, min, max))
            onChanged();
    }

    void dragFloat2(std::string text, float *values, float min, float max)
    {
        if (ImGui::DragFloat2(text.c_str(), values, 0.1f, min, max))
            onChanged();
    }

    void colorEdit4(std::string text, float *col)
    {
        if (ImGui::ColorEdit4(text.c_str(), col))
            onChanged();
    }

    std::function<void()> onChanged;
};