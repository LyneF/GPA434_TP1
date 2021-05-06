#pragma once
#ifndef _EZAPP_TIMER_H_
#define _EZAPP_TIMER_H_


// Inclusion des bibliothèques
#include <cstdint>
#include <memory>


// Déclaration du namespace ezapp
namespace ezapp {

    //! \brief Classe utilitaire donnant accès à des métriques du temps écoulé.
    //! 
    //! Attention, toutes les métriques sont évaluées à chaque appel.
    class Timer
    {
    public:
        int64_t sinceLastTic() const;           //!< Retourne le temps écoulé depuis le dernier tic (en microseconde).
        int64_t sinceStartup() const;           //!< Retourne le temps écoulé depuis le démarage de l'application (en microseconde).
        float secondSinceLastTic() const;       //!< Retourne le temps écoulé depuis le dernier tic (en seconde).
        float secondSinceStartup() const;       //!< Retourne le temps écoulé depuis le démarage de l'application (en seconde).

        float fpsEstimation() const;            //!< Retourne une estimation du tic par seconde (frame per second).

    private:
        Timer(size_t framesUsedForFPS = 1000);
        Timer(Timer const &) = delete;
        Timer(Timer &&) = delete;
        Timer& operator=(Timer const &) = delete;
        Timer& operator=(Timer &&) = delete;
        ~Timer();

        friend class Application;

        struct Impl;
        std::unique_ptr<Impl> mImpl;

        void tic();
    };

}

#endif // _EZAPP_TIMER_H_