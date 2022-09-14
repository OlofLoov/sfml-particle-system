#pragma once

struct ParticleEmitterSettings
{
    bool continously = false;
    bool mouseAttracts = false;
    int mouseAttractStrength = 120;
    bool emitAtMouse = false;
    int emitCount = 250;
    bool emitVariationOverTime = false;
    int emitVariationStepSize = 20;
    int emitVariationMaxCount = 400;
    bool varySpeed = false;
    float speedVariation = 1.0;
    float lifeVariation = 1.0;
    bool varyLifeDuration = false;
    int angleOffset = 0;
    bool angleOffsetOverTime = false;
    int angleOffsetIncrement = 1;

    int countOverTime[6] = {500, 500, 500, 0, 0};
    float colorBegin[4] = {0.f, 0.3f, 0.05f, 1.0f};
    float colorEnd[4] = {0.7f, 0.25f, 0.f, 1.0f};
    float lifeTime = 6.0f;
    float velocity[2] = {0.4f, 0.4f};

    int angle[2] = {0, 360};
    int emitPos[2] = {500, 500};
};