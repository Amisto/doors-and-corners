#ifndef PSYCHE_H
#define PSYCHE_H

class Psyche
{
public:
    void action(double attitude);
    bool naturalDecay();

    Psyche();
    Psyche(double psyche, double mood, double excitement);
    ~Psyche();

    double getPsyche();
    double getMood();
    double getExcitement();

    void setExcitement(double _excitement);
    
    double getPsycheModifier();
    void setPsycheModifier(double _psycheModifier);
    double getMoodModifier();
    void setMoodModifier(double _moodModifier);
    double getExcitementModifier();
    void setExcitementModifier(double _excitementModifier);

private:
    double psyche; // -PSYCHE_MAX PSYCHE_MAX
    double mood; // -MOOD_MAX MOOD_MAX
    double excitement; // 0.0 EXCITEMENT_MAX

    static const double PSYCHE_MAX;
    static const double MOOD_MAX;
    static const double EXCITEMENT_MAX;

    double psycheModifier;
    double moodModifier;
    double excitementModifier;
};

#endif