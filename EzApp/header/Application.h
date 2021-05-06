#pragma once
#ifndef _EZAPP_APPLICATION_H_
#define _EZAPP_APPLICATION_H_


// Inclusion des bibliothèques
#include <memory>
#include <string>
#include <functional>


//! \brief Le namespace ezapp réuni les classes utilitaires de la librairie EzApp.
namespace ezapp {

    class Screen;
    class Timer;
    class Keyboard;
        
    //! \brief La classe Application correspond à l'application elle même et est au coeur de la librairie EzApp.
    //!
    //! \detail Il suffit de créer une instance de cette classe et d'appeler la fonction run pour démarrer l'application graphique.
    //!
    //! Il existe quelques paramètres disponibles pour configurer l'application. La sous classe Parameters permet de les manipuler. La seule façon de modifier les paramètres est en passant un objet Parameters à même le constructeur.
    //! 
    //! Même si sa présence n'est pas essentielle, il est attendu que le fichier de la police de caractères Arial.ttf soit disponible au démarrage du logiciel à même son dossier de travail.
    //! 
    //! La fonction run requiert deux fonctions lui pemettant de faire :
    //!  1. les calculs à chaque pas (considérant les entrées au clavier et le temps écoulé)
    //!  2. l'affichage pour chaque pas (l'affichage à l'écran)
    //! 
    //! Il existe plusieurs surcharges de la function run facilitant le 
    //! développement selon le contexte. Toutefois, il est important de 
    //! comprendre que l'application tourne en boucle et appel indéfiniment 
    //! les deux fonctions tant que la fonction updateModel retourne vrai. 
    //! L'application termine immédiatement lorsqu'elle retourne faux.
    //! 
    //! Ainsi, le corps du programme se résume à :
    //! \verbatim
    /*

                    Application::run
                    +--------------------------------------+
                    |                                      |
                    |                                      |
                    |                                      |
                    |                +-------------+       |
                    |                |             |       |
         +---------->       +--------> updateModel |       |
                    |       |        |             |       |
                    |       |        +------+------+       |
                    |       |               |              |
                    |       |               |              |
                    |       |               v              |
                    |       |              _-_             |
                    |       |           _-'   '-_          |
                    |       |          <         ---------------->
                    |       |           '-_   _-'  faux    |
                    |       |              '-'             |
                    |       |               | vrai         |
                    |       |               |              |
                    |       |               |              |
                    |       |        +------v------+       |
                    |       |        |             |       |
                    |       |        | udpateView  |       |
                    |       |        |             |       |
                    |       |        +------+------+       |
                    |       |               |              |
                    |       +---------------+              |
                    |                                      |
                    |                                      |
                    |                                      |
                    +--------------------------------------+

    */
    //! \endverbatim
    //! 
    class Application
    {
    public:
        // Définition des types publiques
        class Parameters;
        using UpdateModelFunction = bool(Keyboard const &, Timer const &);
        using UpdateViewFunction = void(Screen &);

        // Constructeurs et destructeur
        //! \brief Constructeur par défaut. Utilise les paramètres par défaut de la sous classe Parameters.
        Application();
        //! \brief Constructeur pouvant spécifier les paramètres de l'application.
        //!     \param[in]  parameters Les paramètres de l'application.
        Application(Parameters const & parameters); //!< Constructeur avec des paramètres spécifiques.
        //! \brief Destructeur.
        ~Application(); 

        //! \brief Retourne les parametres de l'application.
        Parameters const & parameters() const;

        // Trois surcharges disponibles
        //! \brief Démarre l'application graphique (surcharge no 1). 
        //! 
        //! \detail La fonction run nécessite en paramètre deux fonctions qui sont exécutées en boucle.
        //!     \param[in]  updateModel Une fonction qui reçoit en paramètre le clavier et le temps permettant de modifier l'état du logiciel.
        //!     \param[in]  updateView  Une fonction qui reçoit en paramètre l'écran et qui permet de dessiner l'état courant du logiciel.
        void run(std::function<UpdateModelFunction> updateModel, std::function<UpdateViewFunction> updateView);
        
        //! \brief Démarre l'application graphique (surcharge no 2).
        //! 
        //! \detail La fonction run nécessite en paramètre deux fonctions qui sont exécutées en boucle.
        //!     \param[in]  model       L'objet duquel la fonction updateModel sera appelée.
        //!     \param[in]  updateModel Une fonction qui reçoit en paramètre le clavier et le temps permettant de modifier l'état du logiciel.
        //!     \param[in]  view        L'objet duquel la fonction updateView sera appelée.
        //!     \param[in]  updateView  Une fonction qui reçoit en paramètre l'écran et qui permet de dessiner l'état courant du logiciel.
        template <typename Model, typename View>
        void run(Model & model, bool(Model::*updateModel)(Keyboard const &, Timer const &), View & view, void(View::*updateView)(Screen &));

        //! \brief Démarre l'application graphique (surcharge no 3).
        //! 
        //! \detail La fonction run nécessite en paramètre deux fonctions qui sont exécutées en boucle.
        //!     \param[in]  modelView   L'objet duquel les fonctions updateModel et updateView seront appelées.
        //!     \param[in]  updateModel Une fonction qui reçoit en paramètre le clavier et le temps permettant de modifier l'état du logiciel.
        //!     \param[in]  updateView  Une fonction qui reçoit en paramètre l'écran et qui permet de dessiner l'état courant du logiciel.
        template <typename ModelView>
        void run(ModelView & modelView, bool(ModelView::* updateModel)(Keyboard const&, Timer const&), void(ModelView::* updateView)(Screen&));

    private:
        class Impl;
        std::unique_ptr<Impl> mImpl;
        void * w();

        friend class Screen;
    };


    //! \brief Sous classe représentant les paramètres d'une application EzApp.
    class Application::Parameters
    {
    public:
        //! \brief Constructeur de la classe Application::Parameters.
        Parameters(size_t width = 800, size_t height = 600, std::string const& title = "EzApp", std::string const& iconFileName = "", std::list<std::string> const& fontToPreload = {});

        bool isValid() const;                                               //!< Retourne vrai si les paramètres sont valides (principalement si la taille est suffisante)

        void setTitle(std::string const & title);                           //!< Détermine le titre de la fenêtre
        void setIconFileName(std::string const & iconFileName);             //!< Détermine le nom du fichier à charger représentant l'icône
        void setWindowSize(size_t width, size_t height);                    //!< Détermine la taille de la fenêtre
        void setFontToPreload(std::list<std::string> const & fontToPreload);//!< Détermine la liste des fichiers de police de caractères à charger
        
        std::string title() const;                                          //!< return le titre de la fenêtre
        std::string iconFileName() const;                                   //!< Retourne le nom du fichier représentant l'icône
        size_t width() const;                                               //!< Retourne la largeur de la fenêtre
        size_t height() const;                                              //!< Retourne la hauteur de la fenêtre
        std::list<std::string> const & fontToPreload() const;               //!< Retourne la liste des fichiers de police de caractères

        static size_t const minSize();                                      //!< Retourne la taille la plus petite permise de la fenêtre

    private:
        std::string mTitle;
        std::string mIconFileName;
        size_t mWidth;
        size_t mHeight;
        std::list<std::string> mFontToPreload;

        static size_t const sMinSize;
    };


    template <typename Model, typename View>
    inline void Application::run(Model & model, bool(Model::* updateModel)(Keyboard const &, Timer const &), View & view, void(View::* updateView)(Screen &)) {
        run(std::bind(updateModel, &model, std::placeholders::_1, std::placeholders::_2), std::bind(updateView, &view, std::placeholders::_1));
    }

    template <typename ModelView>
    inline void Application::run(ModelView& modelView, bool(ModelView::* updateModel)(Keyboard const&, Timer const&), void(ModelView::* updateView)(Screen&)) {
        run(modelView, updateModel, modelView, updateView);
    }
}


#endif // _EZAPP_APPLICATION_H_