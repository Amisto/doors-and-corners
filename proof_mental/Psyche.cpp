#include "Psyche.h"

const double Psyche::PSYCHE_MAX = 1000.0;
const double Psyche::MOOD_MAX = 100.0;
const double Psyche::EXCITEMENT_MAX = 1.0;

Psyche::Psyche() : Psyche(0.0, 0.0, 0.0)
{

}

Psyche::Psyche(double psyche, double mood, double excitement) : psyche(psyche), mood(mood), excitement(excitement)
{
    psycheModifier = 0.0;
    moodModifier = 0.9999;
    excitementModifier = 0.999;
}

Psyche::~Psyche()
{

}


void Psyche::action(double attitude)
{
    double d_psyche = attitude * mood * excitement;
    if (attitude < 0 && mood < 0)
        d_psyche *= -1;
    psyche += d_psyche;

    mood += ( attitude + psyche / PSYCHE_MAX) * excitement;
}


double Psyche::getPsyche()
{
    return psyche;
}

double Psyche::getMood()
{
    return mood;
}

double Psyche::getExcitement()
{
    return excitement;
}

void Psyche::setExcitement(double _excitement)
{
    excitement = _excitement;
}

double Psyche::getPsycheModifier()
{
    return psycheModifier;
}

void Psyche::setPsycheModifier(double _psycheModifier)
{
    psycheModifier = _psycheModifier;
}


double Psyche::getMoodModifier()
{
    return moodModifier;
}

void Psyche::setMoodModifier(double _moodModifier)
{
    moodModifier = _moodModifier;
}

double Psyche::getExcitementModifier()
{
    return excitementModifier;
}

void Psyche::setExcitementModifier(double _excitementModifier)
{
    excitementModifier = _excitementModifier;
}

bool Psyche::naturalDecay()
{
    if (psyche < - PSYCHE_MAX)
        return false;
    else if (psyche > PSYCHE_MAX)
        psyche = PSYCHE_MAX;
    if (mood < - MOOD_MAX)
        mood = - MOOD_MAX;
    else if (mood > MOOD_MAX)
        mood = MOOD_MAX;
    if (excitement < 0.0)
        excitement = 0.0;
    else if (excitement > EXCITEMENT_MAX)
        excitement = EXCITEMENT_MAX;

    psyche += psycheModifier;
    mood *= moodModifier;
    excitement *= excitementModifier;

    mood += excitement * psyche / PSYCHE_MAX;

    return true;
}

